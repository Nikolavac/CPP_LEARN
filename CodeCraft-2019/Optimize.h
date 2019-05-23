#ifndef OPT_H
#define OPT_H

#include "loadInfo.h"
#include "Dijkstra.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <random>
#include <chrono>
#include <queue>
using namespace std;

vector<vector<int>> Opt(int Group_Size, double weightRate, double presetLaneWeight, double notPresetlaneWeight, double priorWeight, int groupNum_ReconstructPlan, int Time_Gap, vector<vector<int>>& roadBuf, 
	vector<vector<int>>& carBuf, unordered_map<int, set<vector<int>>>& adjTable, vector<int>& crossBuf, vector<vector<int>> presetAnsBuff){
	
	//1. 首先处理预置车辆
	//carid, time, roadId1...
	//----1.1按照预置车辆的实际出发时间片从小到大、id从小到大排序
	//----1.2记录预置车辆实际出发时间片的所有的预置车辆数目
	//----1.3记录预置车辆的路径字典
	unordered_map<int, int> presetCarTimeNumDict;
	sort(presetAnsBuff.begin(), presetAnsBuff.end(), [](const vector<int> &a, const vector<int> &b) { 
		if(a[1] == b[1])
			return a[0] < b[0];
		else
			return a[1] < b[1]; 
	});
	
	
	int preTime = presetAnsBuff[0][1];
	int cnt = 1;
	for( int i = 1; i < presetAnsBuff.size(); i++ ){
		if(presetAnsBuff[i][1] == preTime && i != presetAnsBuff.size()-1) cnt++;
		else{
			if(i == presetAnsBuff.size()-1) ++cnt;
			presetCarTimeNumDict[preTime] = cnt;
			cnt = 1;
		}
		preTime = presetAnsBuff[i][1];
	}
	unordered_map<int, vector<int>> presetCarPathDict;
	for( int i = 0; i < presetAnsBuff.size(); i++ ){
		vector<int> path;
		for( int j = 2; j < presetAnsBuff[i].size(); j++ )
			path.push_back(presetAnsBuff[i][j]);
		presetCarPathDict[presetAnsBuff[i][0]] = path;
	}
	
	
	//2. 筛选出预置车辆然后随机打乱并按照 planTime 从小到达排序
	//   非预置车辆，按照 presetAnsBuff 的 id 排序
	//id, from, to, speed, planTime, priority, preset
	vector<vector<int>> presetCarBuf;
	vector<vector<int>> notPresetCarBuf;
	unordered_map<int, int> asFromPointNumDict;
	unordered_map<int, int> asToPointNumDict;
	
	//非预置车辆按照优先级、计划出发时间、id排序
	//id, from, to, speed, planTime, priority, preset
	struct cmp{
		bool operator()(const vector<int> &a, const vector<int> &b){
			if(a[5] == b[5]){
				if(a[4] == b[4])
					return a[3] > b[3]; 
				else
					return a[4] > b[4]; 
			}
			else
				return a[5] < b[5]; 
		}
	};
	//非预置车辆的节点优先队列MAP
	unordered_map<int, priority_queue<vector<int>, vector<vector<int>>, cmp>> notPresetNodeMap;
	//非预置车辆的节点队列
	queue<int> nodeQueue;
	for( int i = 0; i < carBuf.size(); i++ ){
		if(!carBuf[i][6])
			notPresetCarBuf.push_back(carBuf[i]);
		else
			presetCarBuf.push_back(carBuf[i]);
		
		//处理始发点
		if(!asFromPointNumDict.count(carBuf[i][1])){
			asFromPointNumDict[carBuf[i][1]] = 1;
			//非预置车辆
			if(!carBuf[i][6]){
				//非预置车辆起始点队列
				//非预置车辆起始点的优先队列
				priority_queue<vector<int>, vector<vector<int>>, cmp> curNodePQ;
				curNodePQ.push(carBuf[i]);
				notPresetNodeMap[carBuf[i][1]] = curNodePQ;
				//nodeQueue.push(carBuf[i][1]);
			}
		}
		else{
			asFromPointNumDict[carBuf[i][1]] += 1;
			//非预置车辆
			if(!carBuf[i][6]){
				notPresetNodeMap[carBuf[i][1]].push(carBuf[i]);
			}
		}
			
		//处理终点
		if(!asToPointNumDict.count(carBuf[i][2]))
			asToPointNumDict[carBuf[i][2]] = 1;
		else
			asToPointNumDict[carBuf[i][2]] += 1;
	}
	for(auto it = notPresetNodeMap.begin(); it != notPresetNodeMap.end(); ++it ){
		nodeQueue.push(it->first);
	}	
	
	/*
	int total = 0;
	int nodeCnt = notPresetNodeMap.size();
	for(auto it = notPresetNodeMap.begin(); it != notPresetNodeMap.end(); ++it ){
		priority_queue<vector<int>, vector<vector<int>>, cmp> pQ = notPresetNodeMap[it->first];
		nodeQueue.push(it->first);
		cout << "node " << it->first << " with size " << pQ.size() << " priorityQueue is:"<< endl;
		int cur_total = pQ.size();
		total += cur_total;
		int cnt = 0;
		cout << "id, from, to, speed, planTime, priority, preset " << endl;
		while(!pQ.empty()){
			vector<int> node = pQ.top();
			pQ.pop();
			
			if(cnt < 10 || cnt > cur_total - 10){
				for( int j = 0; j < node.size(); j++ )
					cout << node[j] << ' ';
				cout << endl;
			}
			else if(cnt == 10)
				cout << "... .... ... ... ... ..." << endl;
			cnt++;
		}
		cout << "--------------" << endl;
	}
	cout << "nodeCnt is " << nodeCnt << " total node is " << total << endl; 
	
	cout << "nodeQueue size is " << nodeQueue.size() << endl;
	while(!nodeQueue.empty()){
		int node = nodeQueue.front();
		nodeQueue.pop();
		cout << node << endl;
	}
	
	vector<vector<int>> minPathList;
	return minPathList;
	
	
	
	cout << "-----------------" << endl;
	cout << "-----------------" << endl;
	cout << "-----------------" << endl;*/
	
	
	//预置车辆，按照 presetAnsBuff（预置车辆的实际出发时间片从小到大、id从小到大排序） 的 id 排序
	unordered_map<int, vector<int>> presetCarDict;
	for( int i = 0; i < presetCarBuf.size(); i++ )
		presetCarDict[presetCarBuf[i][0]] = presetCarBuf[i];
	presetCarBuf.clear();
	for( int i = 0; i < presetAnsBuff.size(); i++ )
		presetCarBuf.push_back(presetCarDict[presetAnsBuff[i][0]]);


	//3.处理非预置车辆相关信息和规划信息
	//----非预置车辆相关信息
	vector<int> retCarIds;
	int presetCarNum = presetCarBuf.size();
	//----规划信息
	vector<vector<int>> minPathList;
	vector<int> timeList;
	int currentTime = 1;
	int maxLane = 0;
	int maxLen = 0;
	int maxSpeed = 0;
	//id, length, speed, channel, from, to, isDuplex
	for( int i = 0; i < roadBuf.size(); i++ ){
		int laneNum =  roadBuf[i][3];
		int curLen = roadBuf[i][1];
		int speed = roadBuf[i][2];
		maxLane = max(maxLane, laneNum);
		maxLen = max(maxLen, curLen);
		maxSpeed = max(maxSpeed, speed);
	}
	cout << "maxLane " << maxLane << " maxLen " << maxLen << " maxSpeed "  << maxSpeed << endl;
	
	//----建图和路径规划字典
	Graph curGraph = Graph();
	map<pair<int, int>, int> plannedTimesDict;
	
	
	int curPresetCarIdx = 0;
	int groupIdx = 0;
	int curGroupSize = Group_Size;
	int nextGroupSize = Group_Size;
	
	while(!nodeQueue.empty()){
		//当前组实际出发时间片
		int curGroupTime = currentTime;
		if(curGroupTime > 600 && curGroupTime < 1000)
			Group_Size = 40;
		//发车方案1
		int curGroupSize = nextGroupSize;
		if(nextGroupSize > Group_Size) nextGroupSize = Group_Size;
		//非预置车辆在当前组的起始与结束位置
		int curGroup_NotPresetCarStart = 0;
		int curGroup_NotPresetCarEnd = 0;
		vector<vector<int>> curGroup_NotPresetCarBuff;
		//预置车辆在当前组的起始与结束位置
		int curGroup_PresetCarStart = curPresetCarIdx;
		int curGroup_PresetCarEnd = curPresetCarIdx;
		//1.根据当前时间片的预置车辆数目凑组
		//----如果超过组数则非预置车辆在当前时间片不走,预置车辆走完，但是下个组数需要减去多余的数目
		//----如果不超过组数则非预置车辆补齐至groupSize
		if(curGroupSize > 0){
			if(presetCarTimeNumDict.count(curGroupTime)){
				if(presetCarTimeNumDict[curGroupTime] >= curGroupSize){
					curGroup_PresetCarEnd = curGroup_PresetCarStart + presetCarTimeNumDict[curGroupTime];	
					nextGroupSize = Group_Size - (presetCarTimeNumDict[curGroupTime] - curGroupSize);				
				}
				else{
					curGroup_NotPresetCarEnd = curGroup_NotPresetCarStart + curGroupSize - presetCarTimeNumDict[curGroupTime];
					curGroup_PresetCarEnd = curGroup_PresetCarStart + presetCarTimeNumDict[curGroupTime];
					nextGroupSize = Group_Size;
				}
			}
			else{
				curGroup_NotPresetCarEnd = curGroup_NotPresetCarStart + curGroupSize;
				nextGroupSize = Group_Size;
			}
		}
		else{
			nextGroupSize += Group_Size;
		}
		if(curGroup_PresetCarEnd > presetCarNum) curGroup_PresetCarEnd = presetCarNum;
		
		
		//预置车辆组内以速度(高到低)
		if(curGroup_PresetCarEnd > curGroup_PresetCarStart){
			sort(presetCarBuf.begin()+curGroup_PresetCarStart, presetCarBuf.begin()+curGroup_PresetCarEnd, [](const vector<int> &a, const vector<int> &b) { 
				return a[3] > b[3];
			});
			//加id
			for( int j = curGroup_PresetCarStart; j < curGroup_PresetCarEnd; j++ )
				retCarIds.push_back(presetCarBuf[j][0]);
		}
		
		if(curGroup_NotPresetCarEnd > curGroup_NotPresetCarStart){
			int curNum = 0;
			while(!nodeQueue.empty() && curNum < curGroup_NotPresetCarEnd - curGroup_NotPresetCarStart){
				int curNode = nodeQueue.front();
				nodeQueue.pop();
				vector<int> nodeHead = notPresetNodeMap[curNode].top();
				//id, from, to, speed, planTime, priority, preset
				if(nodeHead[4] <= curGroupTime){
					notPresetNodeMap[curNode].pop();
					curGroup_NotPresetCarBuff.push_back(nodeHead);
					retCarIds.push_back(nodeHead[0]);
					curNum++;
					if(!notPresetNodeMap[curNode].empty())
						nodeQueue.push(curNode);
				}
				else nodeQueue.push(curNode);				
			}	
		}
		
		/*
		cout << curGroupTime << " " << curGroupSize << endl;
		cout << curGroup_PresetCarStart << " " << curGroup_PresetCarEnd << endl;
		cout << nodeQueue.size() << endl;
		cout << curGroup_NotPresetCarStart << " " << curGroup_NotPresetCarEnd << " " << curGroup_NotPresetCarBuff.size() << endl;
		cout << "---------------" << endl;*/
		 
	
		//重建图
		//将道路规划次数初始化为0
		if(groupIdx % groupNum_ReconstructPlan == 0){
			for( int k = 0; k < crossBuf.size(); k++ ){
				int crossId = crossBuf[k];
				set<vector<int>> curCrossSet = adjTable[crossId];
				for(auto set_iter = curCrossSet.begin(); set_iter != curCrossSet.end(); ++set_iter){
					plannedTimesDict[make_pair(crossId, (*set_iter)[0])] = 0;
				}
			}
			//to, length, id, channel, speed
			curGraph = Graph();
			for( int k = 0; k < crossBuf.size(); k++ ){
				int crossId = crossBuf[k];
				set<vector<int>> curCrossSet = adjTable[crossId];
				for(auto set_iter = curCrossSet.begin(); set_iter != curCrossSet.end(); ++set_iter){
					Edge curEdge = Edge(crossId, (*set_iter)[0], (*set_iter)[4]/((*set_iter)[1]*1.0/maxLen)/((*set_iter)[1]*1.0/maxLen)/(*set_iter)[3]*pow(weightRate, 1), (*set_iter)[2], (*set_iter)[3], (*set_iter)[4], (*set_iter)[1]);
					curGraph.addEdge(curEdge);
				}
			}
		}
		/*
		curGraph.printGraphEdgeInfo();
		string graphFilename = "Graph" + to_string(curGroupTime) + ".txt";
		curGraph.writeGraphEdgeInfo(graphFilename);
		cout << endl << endl;
		cout << groupIdx << endl;
		cout << "-------------------" << endl;
		cout << "-------------------" << endl;
		cout << "-------------------" << endl;
		cout << "-------------------" << endl;*/
	
		//处理当前组的车辆的动态路径
		//---先处理预置车辆、再处理非预置车辆
		
		if(curGroup_PresetCarEnd > curGroup_PresetCarStart){
			for( int j = curGroup_PresetCarStart; j < curGroup_PresetCarEnd; j++ ){
				timeList.push_back(curGroupTime);
				
				//id, from, to, speed, planTime, priority, preset
				int carIdx = presetCarBuf[j][0];
				int fromPoint = presetCarBuf[j][1];
				int toPoint = presetCarBuf[j][2];
				int priority = presetCarBuf[j][5];
				vector<int> curPresetCarPathNodes;
				curPresetCarPathNodes.push_back(fromPoint);
				vector<int> curPresetCarPath = presetCarPathDict[carIdx];
				int len = curPresetCarPath.size();
				int nextPoint = fromPoint;
				int pathIdx = 0;
				while(nextPoint != toPoint){
					set<Edge> nextPointAdjTable = curGraph.adjacents[nextPoint];
					for(auto set_iter = nextPointAdjTable.begin(); set_iter != nextPointAdjTable.end(); ++set_iter){
						if((*set_iter).pathName == curPresetCarPath[pathIdx]){
							nextPoint = (*set_iter).destine;
							curPresetCarPathNodes.push_back(nextPoint);
							pathIdx++;
							break;
						}
					}
				}
				minPathList.push_back(curPresetCarPath);
				//更新路径
				int pathNodeNum = curPresetCarPathNodes.size();
				for( int l = 0; l < pathNodeNum - 1; l++ ){
					int from = curPresetCarPathNodes[l];
					int to = curPresetCarPathNodes[l+1];
					int pathName;
					double weight;
					int lane = 0;
					int speed;
					int length;
					set<Edge> curFromSet = curGraph.adjacents[from];
					//int flag = 0;
					for(auto set_iter = curFromSet.begin(); set_iter != curFromSet.end(); ++set_iter){
						if((*set_iter).destine == to){
							weight = (*set_iter).weight;
							lane = (*set_iter).laneNum;
							speed = (*set_iter).speed;
							pathName = (*set_iter).pathName;
							length = (*set_iter).length;
							//flag = 1;
							break;
						}
					}
					
					int capacity = ceil(length * 1.0 / speed * lane);
					//if(not priority){
					//	curGraph.adjustEdgeValue(Edge(from, to, weight, pathName, lane, speed), Edge(from, to, weight*pow(weightRate, priorWeight), pathName, lane, speed));
					//}
					//if((plannedTimesDict[make_pair(from, to)] + 1) % lane == 0 ){
						//if(priority)
						//curGraph.adjustEdgeValue(Edge(from, to, weight, pathName, lane, speed), Edge(from, to, weight*pow(weightRate, presetLaneWeight/pow(speed*1.0/maxSpeed, 1.0/3)), pathName, lane, speed));
						//else
							//curGraph.adjustEdgeValue(Edge(from, to, weight, pathName, lane, speed), Edge(from, to, weight*pow(weightRate, presetLaneWeight*0.9/pow(speed*1.0/maxSpeed, 1.0/3)), pathName, lane, speed));
					//}
					//*pow(weightRate, (!priority)*priorWeight)
					if(plannedTimesDict[make_pair(from, to)] > capacity)
						curGraph.adjustEdgeValue(Edge(from, to, weight, pathName, lane, speed, length), Edge(from, to, weight*pow(weightRate, presetLaneWeight*1.0/lane/pow(speed*1.0/maxSpeed, 1.0/3)), pathName, lane, speed, length));
					else
						curGraph.adjustEdgeValue(Edge(from, to, weight, pathName, lane, speed, length), Edge(from, to, weight*pow(weightRate, presetLaneWeight*1.0/capacity/pow(speed*1.0/maxSpeed, 1.0/3)), pathName, lane, speed, length));
					plannedTimesDict[make_pair(from, to)] += 1;
				}
			}
		}
		
		if(curGroup_NotPresetCarEnd > curGroup_NotPresetCarStart){
			for( int j = 0; j < curGroup_NotPresetCarBuff.size(); j++ ){
				timeList.push_back(curGroupTime);
				//curGraph.printGraphEdgeInfo();
				int carIdx = curGroup_NotPresetCarBuff[j][0];
				int fromPoint = curGroup_NotPresetCarBuff[j][1];
				int toPoint = curGroup_NotPresetCarBuff[j][2];
				int priority = curGroup_NotPresetCarBuff[j][5];
				
				ShortestPath path = ShortestPath(curGraph, fromPoint);
				vector<vector<int>> pathRet = path.path_to(toPoint);
				//添加路径
				minPathList.push_back(pathRet[1]);
				int pathNodeNum = pathRet[0].size();//当前路径规划后对已规划道路字典进行调整
				for( int l = 0; l < pathNodeNum - 1; l++ ){
					int from = pathRet[0][l];
					int to = pathRet[0][l+1];
					int pathName;
					double weight;
					int lane = 0;
					int speed;
					int length;
					set<Edge> curFromSet = curGraph.adjacents[from];
					for(auto set_iter = curFromSet.begin(); set_iter != curFromSet.end(); ++set_iter){
						if((*set_iter).destine == to){
							weight = (*set_iter).weight;
							lane = (*set_iter).laneNum;
							speed = (*set_iter).speed;
							pathName = (*set_iter).pathName;
							length = (*set_iter).length;
							break;
						}
					}
					int capacity = ceil(length * 1.0 / speed * lane);
					/*
					if((plannedTimesDict[make_pair(from, to)] + 1) % lane == 0){
						curGraph.adjustEdgeValue(Edge(from, to, weight, pathName, lane, speed), Edge(from, to, weight*pow(weightRate, notPresetlaneWeight/pow(speed*1.0/maxSpeed, 1.0/3)), pathName, lane, speed));
					}*/
					if(plannedTimesDict[make_pair(from, to)] > capacity)
						curGraph.adjustEdgeValue(Edge(from, to, weight, pathName, lane, speed, length), Edge(from, to, weight*pow(weightRate, presetLaneWeight*1.0/lane/pow(speed*1.0/maxSpeed, 1.0/3)), pathName, lane, speed, length));
					else
						curGraph.adjustEdgeValue(Edge(from, to, weight, pathName, lane, speed, length), Edge(from, to, weight*pow(weightRate, presetLaneWeight*1.0/capacity/pow(speed*1.0/maxSpeed, 1.0/3)), pathName, lane, speed, length));
					plannedTimesDict[make_pair(from, to)] += 1;
				}
			}
		}
		currentTime += Time_Gap;
		++groupIdx;
		curPresetCarIdx = curGroup_PresetCarEnd;
		
	}
	//写文件做准备 前n-2行是路径 第n-1行是车子id，最后一行是出发时间
	cout << retCarIds.size() << ' ' << timeList.size();
	minPathList.push_back(retCarIds);
	minPathList.push_back(timeList);
	return minPathList;
}


void writeAnsFile(string ansFileStr, vector<vector<int>>& optAns){
	int len = optAns.size();
	vector<int> idList = optAns[len-2];
	vector<int> timeList = optAns[len-1];
	
	ofstream ansFileFid(ansFileStr);
	for( int i = 0; i < len - 2; i++ ){
		ansFileFid << '(' << idList[i] << ',' << timeList[i] << ',';
		int pathLen = optAns[i].size();
		for( int j = 0; j < pathLen; j++ ){
			if(j == pathLen - 1)
				ansFileFid << optAns[i][j];
			else
				ansFileFid << optAns[i][j] << ',';
		}
		ansFileFid << ')' << endl;
	}
	ansFileFid.close();
}

#endif

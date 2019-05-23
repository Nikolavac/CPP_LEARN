#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
//边类定义
class Edge{
public:
	int source;
	int destine;
	double weight;
	int pathName;
	int laneNum;
	int speed;
	int length;
	Edge(){
	};
	
	Edge(int src, int dst, double w, int pn, int l, int v, int len){
		source   = src;
		destine  = dst;
		weight   = w;
		pathName = pn;
		laneNum  = l;
		speed    = v;
		length   = len;
	}
	bool equalEdge(Edge& edge1){
		return (source == edge1.source && destine == edge1.destine);
	}
	void printEdgeInfo(){
		std::cout << source << ' ' << destine << ' ' << weight << ' ' << pathName << ' ' << laneNum << ' ' << speed << std::endl;
	}
	bool operator < (const Edge& edge) const{
		if(source != edge.source)
        	return source < edge.source;
        else
        	return destine < edge.destine;
    }
    bool operator == (const Edge& edge) const{
        return (source == edge.source && destine == edge.destine);
    }
};

//图类定义
class Graph{
public:
	std::set<int> vertices;
	std::set<Edge> edges;
	std::unordered_map<int, std::set<Edge>> adjacents;
	
	void addEdge(Edge& edge);
	std::set<Edge> getAdjacents(const int vertex);
	int vertexNumber(void);
	int edgeNumber(void);
	void adjustEdgeValue(const Edge& oldEdge, const Edge& newEdge);
	void printGraphEdgeInfo(void);
	void writeGraphEdgeInfo(std::string filename);
};

//最小堆实现的最小优先队列类定义
class MinPriorityQueue{
public:
	std::unordered_map<int, int> idxMap;
	std::vector<std::pair<int, double>> queue;
	MinPriorityQueue(void){
		queue.push_back(std::make_pair(0, 0.0));
		idxMap[0] = 0;
	}
	void idxMapSwap(int idx, int swapIdx){
		int tmp = idxMap[queue[idx].first];
		idxMap[queue[idx].first] = idxMap[queue[swapIdx].first];
		idxMap[queue[swapIdx].first] = tmp;
	}
	bool isEmpty(void){
		return queue.size() == 1;
	}
	int qsize(void){
		return queue.size() - 1;
	}
	std::pair<int, double> min(void){
		return queue[1];
	}
	void insert(int vertex, double newVal){
		queue.push_back(std::make_pair(vertex, newVal));
		idxMap[vertex] = qsize();
		swim(qsize());
	}
	
	std::pair<int, double> deleteMin(){
		int queueSize = qsize();
		swap(queue[1], queue[queueSize]);
		idxMapSwap(1, queueSize);
		std::pair<int, double> out = queue[queueSize];
		queue.pop_back();
		idxMap.erase(out.first);
		sink(1);
		return out;
	}
	
	void swim(int index){
		while(index > 1 && queue[int(index/2)].second > queue[index].second){
			swap(queue[int(index/2)], queue[index]);
			idxMapSwap(int(index/2), index);
			index = int(index / 2);
		}
	}
	
	void sink(int index){
		while(2*index <= qsize()){
			int nextLevel = 2 * index;
			if(nextLevel < qsize() && queue[nextLevel].second > queue[nextLevel+1].second)
				nextLevel += 1;
			if(queue[index].second <= queue[nextLevel].second)
				return ;
			swap(queue[index], queue[nextLevel]);
			idxMapSwap(index, nextLevel);
			index = nextLevel;
		}
	}
	
	
	bool contains(int vertex){
		/*int len = qsize();
		
		for(int index = 1; index <= len; index++){
			if(queue[index].first == vertex)
				return true;
		}
		return false;*/
		return idxMap.count(vertex);
	}
	
	void changeDist(int vertex, double newDist){
		/*
		int len = qsize();
		for(int index = 1; index <= len; index++){
			if(queue[index].first == vertex){
				queue[index].second = newDist;
				//需要上调
				swim(index);
				return ;
			}
		}*/
		int vertexIdx = idxMap[vertex];
		queue[vertexIdx].second = newDist;
		swim(vertexIdx);
	}
	
};

		
//寻找最小路径
class ShortestPath{
public:
	std::unordered_map<int, double> dist_to;
	std::unordered_map<int, Edge> edge_to;
	int startPoint;
	MinPriorityQueue dist_queue;
	
	ShortestPath(Graph& graph, int start);
	void relax(Edge& edge);
	std::vector<std::vector<int>> path_to(int vertex);
};

#endif 

#include "loadInfo.h"
//#include "Dijkstra.h"
Road::Road(std::string str){
	roadFileName = str;
	std::ifstream roadFileFid(roadFileName);
	if (!roadFileFid.is_open()) { 
        std::cout << "打开road文件错误" << std::endl; 
    } 
	std::string temp;
    while(getline(roadFileFid, temp)) { 
        if(temp[0] != '#'){
			//字符串处理
			int len = temp.size();
			int id, length, speed, channel, from, to, isDuplex;
			int start = 0, end = 0, subStrNum = 0;
			for( int i = 0; i < len; i++ ){
				if(temp[i] == '(' || temp[i] == ' ')
					++start, ++end;
				else if(temp[i] == ',' || temp[i] == ')'){
					switch(subStrNum){
						case 0:{
							id = stoi(temp.substr(start, end-start));
							break;
						}
						case 1:{
							length = stoi(temp.substr(start, end-start));
							break;
						}
						case 2:{
							speed = stoi(temp.substr(start, end-start));
							break;
						}
						case 3:{
							channel = stoi(temp.substr(start, end-start));
							break;
						}
						case 4:{
							from = stoi(temp.substr(start, end-start));
							break;
						}
						case 5:{
							to = stoi(temp.substr(start, end-start));
							break;
						}
						case 6:{
							isDuplex = stoi(temp.substr(start, end-start));
							break;
						}
						default:
							std::cout << "subStrNum error" << std::endl;
							break;
					}
					++subStrNum;
					start = ++end;
				}
				else ++end;
			}
			std::vector<int> v;
			v.push_back(id);v.push_back(length);v.push_back(speed);
			v.push_back(channel);v.push_back(from);v.push_back(to);v.push_back(isDuplex);

			roadBuf.push_back(v);
		}
    }
	roadNum = roadBuf.size();	
}

void Road::BuildAdjTable(void){
	int len = roadBuf.size();
	//id, length, speed, channel, from, to, isDuplex
	for( int i = 0; i < len; i++ ){
		//from->to info: to, length, id, channel, speed
		if(!adjTable.count(roadBuf[i][4])){
			std::set<std::vector<int>> initSet;
			std::vector<int> v;
			v.push_back(roadBuf[i][5]);
			v.push_back(roadBuf[i][1]);
			v.push_back(roadBuf[i][0]);
			v.push_back(roadBuf[i][3]);
			v.push_back(roadBuf[i][2]);
			initSet.insert(v);
			adjTable[roadBuf[i][4]] = initSet;
		}
		else{
			std::vector<int> v;
			v.push_back(roadBuf[i][5]);
			v.push_back(roadBuf[i][1]);
			v.push_back(roadBuf[i][0]);
			v.push_back(roadBuf[i][3]);
			v.push_back(roadBuf[i][2]);
			adjTable[roadBuf[i][4]].insert(v);
		}
			
			
		//if isDuplex
		if(roadBuf[i][6]){
			//to->from info: to, length, id, channel, speed
			if(!adjTable.count(roadBuf[i][5])){
				std::set<std::vector<int>> initSet;
				std::vector<int> v;
				v.push_back(roadBuf[i][4]);
				v.push_back(roadBuf[i][1]);
				v.push_back(roadBuf[i][0]);
				v.push_back(roadBuf[i][3]);
				v.push_back(roadBuf[i][2]);
				initSet.insert(v);
				adjTable[roadBuf[i][5]] = initSet;
			}
			else{
				std::vector<int> v;
				v.push_back(roadBuf[i][4]);
				v.push_back(roadBuf[i][1]);
				v.push_back(roadBuf[i][0]);
				v.push_back(roadBuf[i][3]);
				v.push_back(roadBuf[i][2]);
				adjTable[roadBuf[i][5]].insert(v);
			}
		}
	}
}



void Road::printRoadBuf(void){
	std::cout << "id, length, speed, channel, from, to, isDuplex" << std::endl;
	//打印前10行 后10行
	int printSize = 10;
	for( int i = 0; i < printSize; i++ ){
		int colSize = roadBuf[i].size();
		for( int j = 0; j < colSize; j++ ){
			std::cout << roadBuf[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "... ... ... ... ... ..." << std::endl;
	for( int i = roadNum-printSize; i < roadNum; i++ ){
		int colSize = roadBuf[i].size();
		for( int j = 0; j < colSize; j++ ){
			std::cout << roadBuf[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}


void Road::printAdjTable(void){
	int len = adjTable.size();
	std::cout << "adjacent table with size "<< len << std::endl;
	//打印前10行 后10行
	int printSize = 10;
	int cnt = 0;
	int adjEdgeNum = 0;
	for(auto iter = adjTable.begin(); iter != adjTable.end(); ++iter, ++cnt){
		adjEdgeNum += adjTable[iter->first].size();
		if(cnt < printSize || cnt > len-printSize){
			auto cur = iter->first;
			std::cout << "adjacent of " << cur << " as followed:" << std::endl;
			std::set<std::vector<int>> adjSet = adjTable[cur];
			for(auto set_iter = adjSet.begin(); set_iter != adjSet.end(); ++set_iter){
				std::vector<int> adj_x = (*set_iter);
				int adj_x_len = adj_x.size();
				std::cout << "----";
				for( int i = 0; i < adj_x_len; i++ )
					std::cout << adj_x[i] << ' ';
				std::cout << std::endl;
			}
		}
		else if(cnt == printSize){
			std::cout << "... ... ... ... ... ..." << std::endl;
		}
    }
    std::cout << "Total edge of adjacent table is " << adjEdgeNum << std::endl;
}


//车类实现
Car::Car(std::string str){
	carFileName = str;
	std::ifstream roadFileFid(carFileName);
	if (!roadFileFid.is_open()) { 
        std::cout << "打开car文件错误" << std::endl; 
    } 
	std::string temp;
    while(getline(roadFileFid, temp)) { 
        if(temp[0] != '#'){
			//字符串处理
			int len = temp.size();
			int id, from, to, speed, planTime, priority, preset;
			int start = 0, end = 0, subStrNum = 0;
			for( int i = 0; i < len; i++ ){
				if(temp[i] == '(' || temp[i] == ' ')
					++start, ++end;
				else if(temp[i] == ',' || temp[i] == ')'){
					switch(subStrNum){
						case 0:{
							id = stoi(temp.substr(start, end-start));
							break;
						}
						case 1:{
							from = stoi(temp.substr(start, end-start));
							break;
						}
						case 2:{
							to = stoi(temp.substr(start, end-start));
							break;
						}
						case 3:{
							speed = stoi(temp.substr(start, end-start));
							break;
						}
						case 4:{
							planTime = stoi(temp.substr(start, end-start));
							break;
						}
						case 5:{
							priority = stoi(temp.substr(start, end-start));
							break;
						}
						case 6:{
							preset = stoi(temp.substr(start, end-start));
							break;
						}
						default:
							std::cout << "subStrNum error" << std::endl;
							break;
					}
					++subStrNum;
					start = ++end;
				}
				else ++end;
			}
			std::vector<int> v;
			v.push_back(id);v.push_back(from);v.push_back(to);
			v.push_back(speed);v.push_back(planTime);v.push_back(priority);v.push_back(preset);
			carBuf.push_back(v);
		}
    } 
	carNum = carBuf.size();
}

void Car::printCarBuf(void){
	std::cout << "car total number is " << carNum << std::endl;
	std::cout << "id, from, to, speed, planTime, priority, preset" << std::endl;
	//打印前10行 后10行
	int printSize = 10;
	for( int i = 0; i < printSize; i++ ){
		int colSize = carBuf[i].size();
		for( int j = 0; j < colSize; j++ ){
			std::cout << carBuf[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "... ... ... ... ... ..." << std::endl;
	for( int i = carNum-printSize; i < carNum; i++ ){
		int colSize = carBuf[i].size();
		for( int j = 0; j < colSize; j++ ){
			std::cout << carBuf[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}


//交叉口类实现
Cross::Cross(std::string str){
	crossFileName = str;
	std::ifstream roadFileFid(crossFileName);
	if (!roadFileFid.is_open()) { 
        std::cout << "打开cross文件错误" << std::endl; 
    } 
	std::string temp;
    while(getline(roadFileFid, temp)) { 
        if(temp[0] != '#'){
			//字符串处理
			int len = temp.size();
			int crossId;
			int start = 0, end = 0, subStrNum = 0;
			for( int i = 0; i < len; i++ ){
				if(temp[i] == '(' || temp[i] == ' ')
					++start, ++end;
				else if(temp[i] == ',' || temp[i] == ')'){
					switch(subStrNum){
						case 0:{
							crossId = stoi(temp.substr(start, end-start));
							break;
						}
						case 1:case 2:case 3:case 4: break;
						default:
							std::cout << "subStrNum error" << std::endl;
							break;
					}
					++subStrNum;
					start = ++end;
				}
				else ++end;
			}
			crossBuf.push_back(crossId);
			
		}
    } 
	crossNum = crossBuf.size();
}

void Cross::printCrossBuf(void){
	std::cout << "cross total number is " << crossNum << std::endl;
	std::cout << "cross id" << std::endl;
	//打印前10行 后10行
	int printSize = 10;
	for( int i = 0; i < printSize; i++ ){
		std::cout << crossBuf[i] << ' ';
		std::cout << std::endl;
	}
	std::cout << "... ... ... ... ... ..." << std::endl;
	for( int i = crossNum-printSize; i < crossNum; i++ ){
		std::cout << crossBuf[i] << ' ';
		std::cout << std::endl;
	}
}

//预置车辆类实现
PresetAnswer::PresetAnswer(std::string str){
	presetAnswerFileName = str;
	std::ifstream presetAnswerFileFid(presetAnswerFileName);
	if (!presetAnswerFileFid.is_open()) { 
        std::cout << "打开presetAnswer文件错误" << std::endl; 
    } 
	std::string temp;
    while(getline(presetAnswerFileFid, temp)) { 
        if(temp[0] != '#'){
			//字符串处理
			int len = temp.size();
			int crossId;
			int start = 0, end = 0, subStrNum = 0;
			std::vector<int> curPresetCarAnsList;
			for( int i = 0; i < len; i++ ){
				if(temp[i] == '(' || temp[i] == ' ')
					++start, ++end;
				else if(temp[i] == ',' || temp[i] == ')'){
					if(subStrNum >= 0)
						curPresetCarAnsList.push_back(stoi(temp.substr(start, end-start)));
					++subStrNum;
					start = ++end;
				}
				else ++end;
			}
			presetAnswerBuff.push_back(curPresetCarAnsList);
		}
    } 
	presetAnswerNum = presetAnswerBuff.size();
}

void PresetAnswer::printPresetAnswerBuff(void){
	std::cout << "Preset car's number is " << presetAnswerNum << std::endl;
	std::cout << "carid, time, roadId1..." << std::endl;
	//打印前10行 后10行
	int printSize = 10;
	for(int i = 0; i < presetAnswerNum; ++i){
		if(i < printSize || i > presetAnswerNum-printSize){
			std::vector<int> curRouteList = presetAnswerBuff[i];
			for( int j = 0; j < curRouteList.size(); j++ ){
				std::cout << curRouteList[j] << ' ';
			}
			std::cout << std::endl;
		}
		else if(i == printSize){
			std::cout << "... ... ... ... ... ..." << std::endl;
		}
    }
}


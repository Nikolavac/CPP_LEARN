#ifndef LOAD_INFO_H
#define LOAD_INFO_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
class Road{
public:
	int roadNum;
	std::string roadFileName;
	std::vector<std::vector<int>> roadBuf;
	std::unordered_map<int, std::set<std::vector<int>>> adjTable;
	Road(std::string str);
	void BuildAdjTable(void);
	void printRoadBuf(void);
	void printAdjTable(void);
};

class Car{
public:
	int carNum;
	std::string carFileName;
	std::vector<std::vector<int>> carBuf;
	
	Car(std::string str);
	void printCarBuf(void);
};

class Cross{
public:
	int crossNum;
	std::string crossFileName;
	std::vector<int> crossBuf;
	
	Cross(std::string str);
	void printCrossBuf(void);
};


class PresetAnswer{
public:
	int presetAnswerNum;
	std::string presetAnswerFileName;
	std::vector<std::vector<int>> presetAnswerBuff;
	PresetAnswer(std::string str);
	void printPresetAnswerBuff(void);
};
#endif 

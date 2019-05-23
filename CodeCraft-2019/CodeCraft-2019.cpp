#include "iostream"
#include <vector>
#include "loadInfo.h"
#include "Dijkstra.h"
#include "Optimize.h"
int main(int argc, char *argv[])
{
    std::cout << "Begin" << std::endl;
	
	if(argc < 6){
		std::cout << "please input args: carPath, roadPath, crossPath, answerPath" << std::endl;
		exit(1);
	}
	
	std::string carPath(argv[1]);
	std::string roadPath(argv[2]);
	std::string crossPath(argv[3]);
	std::string presetAnswerPath(argv[4]);
	std::string answerPath(argv[5]);
	
	std::cout << "carPath is " << carPath << std::endl;
	std::cout << "roadPath is " << roadPath << std::endl;
	std::cout << "crossPath is " << crossPath << std::endl;
	std::cout << "presetAnswerPath is " << presetAnswerPath << std::endl;
	std::cout << "answerPath is " << answerPath << std::endl;
	
	Road road = Road(roadPath);
	//road.printRoadBuf();
	road.BuildAdjTable();
	//road.printAdjTable();
	Car car = Car(carPath);
	//car.printCarBuf();
	Cross cross = Cross(crossPath);
	//cross.printCrossBuf()
	PresetAnswer presetAns = PresetAnswer(presetAnswerPath);
	//presetAns.printPresetAnswerBuff();
	
	// TODO:process
	int Group_Size = 50;
	double weightRate = 1.5;
	double presetLaneWeight = 1.1;
	double notPresetlaneWeight = 1.1;
	double priorWeight = -1;
	//每groupNum_ReconstructPlan组重新建图更新权重
	int groupNum_ReconstructPlan = 10;
	int Time_Gap = 1;
	vector<vector<int>> optAns = Opt(Group_Size, weightRate, presetLaneWeight, notPresetlaneWeight, priorWeight, groupNum_ReconstructPlan, 
		Time_Gap, road.roadBuf, car.carBuf, road.adjTable, cross.crossBuf, presetAns.presetAnswerBuff);
	//std::cout << optAns.size() << std::endl;
	
	// TODO:write output file
	writeAnsFile(answerPath, optAns);
	
	return 0;
}
#include "Dijkstra.h"
#include <string>
#define DBL_MAX 1.7976931348623158e+300

//图类定义
void Graph::addEdge(Edge& edge){
	vertices.insert(edge.source);
	vertices.insert(edge.destine);
	edges.insert(edge);
	adjacents[edge.source].insert(edge);
	
	/* 
	if(adjacents.count(edge.source)){
		std::set<Edge> curEdgeSet = adjacents[edge.source];
		curEdgeSet.insert(edge);
		//adjacents[edge.source].insert(edge);
	}
	else{
		std::set<Edge> edgeInitSet;
		edgeInitSet.insert(edge);
		adjacents[edge.source] = edgeInitSet;
	}*/ 
}

std::set<Edge> Graph::getAdjacents(const int vertex){
	std::set<Edge> empty;
	//存在节点
	if(adjacents.count(vertex))
		return adjacents[vertex];
	else
		return empty;
}

int Graph::vertexNumber(void){
	return vertices.size();
}

int Graph::edgeNumber(void){
	return edges.size();
}


void Graph::adjustEdgeValue(const Edge& oldEdge, const Edge& newEdge){
	Edge newEdge_cpy = newEdge;
	//去除边
	edges.erase(oldEdge);
	//去除邻接
	adjacents[oldEdge.source].erase(oldEdge);
	//重新添加边
	addEdge(newEdge_cpy);
}


void Graph::printGraphEdgeInfo(void){
	int len = adjacents.size();
	std::cout << "adjacent table with node size "<< len  << ", with edge size "<< edgeNumber() << std::endl;
	//打印前10行 后10行
	int printSize = len;
	int cnt = 0;
	for(auto iter = adjacents.begin(); iter != adjacents.end(); ++iter, ++cnt){
		if(cnt < printSize || cnt >= len-printSize){
			int cur = iter->first;
			std::cout << "adjacent of " << cur << " as followed:" << std::endl;
			std::cout << "source   destine   weight   pathName   laneNum   speed" << std::endl;
			std::set<Edge> adjSet = adjacents[cur];
			for(auto set_iter = adjSet.begin(); set_iter != adjSet.end(); ++set_iter){
				Edge curEdge = (*set_iter);
				curEdge.printEdgeInfo();
			}
		}
		else if(cnt == printSize){
			std::cout << "... ... ... ... ... ..." << std::endl;
		}
	}	
}

void Graph::writeGraphEdgeInfo(std::string fileName){
	std::ofstream graphFileFid(fileName);
	if (!graphFileFid.is_open()) { 
        std::cout << "open " << fileName << "failed." << std::endl; 
    } 
	int len = adjacents.size();
	graphFileFid << "adjacent table with node size "<< len  << ", with edge size "<< edgeNumber() << std::endl;
	for(auto iter = adjacents.begin(); iter != adjacents.end(); ++iter){
		int cur = iter->first;
		graphFileFid << "source   destine   weight   pathName   laneNum   speed" << std::endl;
		std::set<Edge> adjSet = adjacents[cur];
		for(auto set_iter = adjSet.begin(); set_iter != adjSet.end(); ++set_iter){
			Edge curEdge = (*set_iter);
			graphFileFid << curEdge.source << ' ' << curEdge.destine << ' ' << curEdge.weight << ' ' << curEdge.pathName << ' ' << curEdge.laneNum << ' ' << curEdge.speed << std::endl;
		}
	}	
	graphFileFid.close();
}


ShortestPath::ShortestPath(Graph& graph, int start){
	for(auto set_iter = graph.vertices.begin(); set_iter != graph.vertices.end(); ++set_iter){
		dist_to[*set_iter] = DBL_MAX;
	}
	startPoint = start;
	dist_queue = MinPriorityQueue();
	//初始赋值
	dist_to[startPoint] = 0;
	dist_queue.insert(startPoint, dist_to[startPoint]);
	while(!dist_queue.isEmpty()){
		//for(auto set_iter = graph.vertices.begin(); set_iter != graph.vertices.end(); ++set_iter){
		//	std::cout << *set_iter << ':' << dist_to[*set_iter] << ' ';
		//}
		//std::cout << std::endl;
		
		std::pair<int, double> node = dist_queue.deleteMin();
		int vertex = node.first;
		std::set<Edge> nodeAdj = graph.getAdjacents(vertex);
		for(auto set_iter = nodeAdj.begin(); set_iter != nodeAdj.end(); ++set_iter){
			Edge curEdge = *set_iter;
			relax(curEdge);
		}
	}
}

void ShortestPath::relax(Edge& edge){
	int source = edge.source;
	int destine = edge.destine;
	if(dist_to[destine] > dist_to[source] + edge.weight){
		dist_to[destine] = dist_to[source] + edge.weight;
		edge_to[destine] = edge;
		if(dist_queue.contains(destine))
			dist_queue.changeDist(destine, dist_to[destine]);
		else
			dist_queue.insert(destine, dist_to[destine]);
	}
}


std::vector<std::vector<int>> ShortestPath::path_to(int vertex){
	std::vector<std::vector<int>> res;
	std::vector<int> pathNodes;
	pathNodes.push_back(vertex);
	std::vector<int> pathNames;
	int tempV = vertex;
	while(tempV != startPoint){
		pathNames.push_back(edge_to[tempV].pathName);
		tempV = edge_to[tempV].source;
		pathNodes.push_back(tempV);
	}
	std::reverse(pathNodes.begin(), pathNodes.end());
	std::reverse(pathNames.begin(), pathNames.end());
	res.push_back(pathNodes);
	res.push_back(pathNames);
	return res;
}

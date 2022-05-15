#pragma once
#include <string>
#ifndef Edge_H
using namespace std;
class Edge
{
public:
	string from;
	string to;
	int cost;
	int indexFrom = -1;
	int indexTo = -1;
	Edge(string from, string to, int cost1, int IndFrom, int IndTo)
	{
		this->from = from;
		this->to = to;
		this->cost = cost1;
		this->indexFrom = IndFrom;
		this->indexTo = IndTo;
	}

	Edge()
	{
		this->from = "";
		this->to = "";
		this->cost = 0;
		this->indexFrom = -1;
		this->indexTo = -1;
	}

};
#endif // !Edge_H


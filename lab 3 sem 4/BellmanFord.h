#pragma once
#ifndef BellmanFord_H
#include<iostream>
#include"List.h"
#include"Edge.h"
#include<string>
using namespace std;

int countCities(List<string>* list)
{
	if (list->getSize() != 0)
	{
		int size = list->getSize();
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if ((*list)[i] == (*list)[j])
				{
					list->remove(j);
					size--;
					j--;
				}
			}
		}
		return list->getSize();
	}
	else return -1;

}

void inizializeCity(List<Edge>* listEdg, List<string>* listStr)
{
	int sizeEdg = listEdg->getSize();
	int sizeStr = listStr->getSize();
	for (int i = 0; i < sizeEdg; i++)
	{
		for (int j = 0; j < sizeStr; j++)
		{
			if ((*listEdg)[i].from == (*listStr)[j])
				(*listEdg)[i].indexFrom = j;

			if ((*listEdg)[i].to == (*listStr)[j])
				(*listEdg)[i].indexTo= j;
		}

	}

}
int algorithm(List<Edge>* listEdg, List<string>* listStr, string from, string to)
{
	int countStr = countCities(listStr);
	int countEdg = listEdg->getSize();


	inizializeCity(listEdg, listStr);

	int* matrix = new int[countStr];
	int inf = INT_MAX - 10000;

	for (int i = 0; i < countStr; i++)
	{
		if ((*listStr)[i] == from) {
			matrix[i] = 0;
		}
		else
		{
			matrix[i] = inf;
		}
	}
	for (int i = 0; i < countStr - 1; i++)
	{
		for (int j = 0; j<countEdg;j++)
		{
			if(matrix[(*listEdg)[j].indexFrom]+(*listEdg)[j].cost< matrix[(*listEdg)[j].indexTo])
			{ 
				matrix[(*listEdg)[j].indexTo] = matrix[(*listEdg)[j].indexFrom] + (*listEdg)[j].cost;
			}
		}
	}
	for (int i = 0; i < countStr; i++)
	{
		if(from==to)
		{
			cout << endl << from << "->" << to << "=" << "dont path" << endl;
			return inf;
		}
		else
		{
			if ((*listStr)[i] == to)
			{
				cout << endl << from << "->" << to << "=" <<matrix[i] << endl;
				return matrix[i];
			}
		}
	}
	delete[] matrix;
}
#endif // !BellmanFord_H

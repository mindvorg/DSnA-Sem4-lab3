#pragma once
#ifndef Parsing_H
#include<iostream>
#include"List.h"
#include"Edge.h"
#include<fstream>

using namespace std;
void parse(List<Edge>* listEdg, List<string>* listStr)
{
	fstream file;
	file.open("priceList.txt", ios_base::in);
	if(file.bad())
	{
		cout << "some problems with input file";
	}
	else
	{
		string line;
		string subline;
		int position = 0;
		while (getline(file, line))
		{
			Edge edge1;
			Edge edge2;

				subline = line;
				position = line.find(';');
				subline.resize(position);
				listStr->pushBack(subline);
				edge1.from = subline;
				edge2.to = subline;
				line.erase(0, position + 1);
				
				subline = line;
				position = line.find(';');
				subline.resize(position);
				listStr->pushBack(subline);
				edge1.to = subline;
				edge2.from= subline;
				line.erase(0, position + 1);
			
			subline = line;
			position = line.find(';');
			subline.resize(position);
			if(subline!="N/A")
			{
				edge1.cost = stoi(subline);
				listEdg->pushBack(edge1);
			}	
			line.erase(0, position + 1);
			if (line != "N/A")
			{
				edge2.cost = stoi(line);
				listEdg->pushBack(edge2);
			}
		}


	}
	file.close();
}

#endif // !Parsing_H

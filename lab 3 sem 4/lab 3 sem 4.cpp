// lab 3 sem 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"List.h"
#include"Edge.h"
#include"Parsing.h"
#include"BellmanFord.h"
using namespace std;
int main()
{
    List<Edge> list1;
    List<string> list2;
    Parse(&list1,&list2);
    int path = -1;
    path = algorithm(&list1, &list2, "Saint-P", "Khabarovsk");
}

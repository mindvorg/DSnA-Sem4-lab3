#include "pch.h"
#include "CppUnitTest.h"
#include"..\lab 3 sem 4\BellmanFord.h"
#include"..\lab 3 sem 4\Parsing.h"
#include"..\lab 3 sem 4\Edge.h"
#include"..\lab 3 sem 4\List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testlab3BellmanFord
{
	TEST_CLASS(testlab3BellmanFord)
	{
	public:
		/*
		Saint-P;Moscow;10;20
Moscow;Khabarovsk;40;35
Saint-P;Khabarovsk;14;N/A
Vladivostok;Khabarovsk;13;8
Vladivostok;Saint-P;N/A;20
*/
		TEST_METHOD(TestAlgorithm1)
		{/*  ()- cost of trip 
		 *                (1)
		 *				2----3
		 *		    (3)/   /(5) 
		 *			  1---/
		 */
			List<Edge> listEdg;
			listEdg.pushBack(Edge{ "one","two",3,0,1 });
			listEdg.pushBack(Edge{ "two","three",1,1,2 });
			listEdg.pushBack(Edge{ "one","three",5,0,2 });
			List<string> listStr;
			listStr.pushBack("one");  listStr.pushBack("two"); listStr.pushBack("three");
			Assert::AreEqual(4, algorithm(&listEdg, &listStr, "one", "three"));
		}
		TEST_METHOD(TestAlgorithm2)
		{
			List<Edge> listEdg; List<string> listStr;
			/* Saint-P -> Moscow->Khabarovsk->Vladivostok
			* 0->1->2->3
			Saint-P;Moscow;10;20
Moscow;Khabarovsk;1;35//change from 40 to 1 and now it is faster from 0->2
Saint-P;Khabarovsk;14;N/A
Vladivostok;Khabarovsk;13;8
Vladivostok;Saint-P;N/A;20
			*/
			listStr.pushBack("Saint-P");listStr.pushBack("Moscow");  listStr.pushBack("Khabarovsk"); listStr.pushBack("Vladivostok");
			listEdg.pushBack(Edge{ "Saint-P", "Moscow", 10, 0, 1 });
			listEdg.pushBack(Edge{ "Moscow","Saint-P", 20, 1, 0 });
			listEdg.pushBack(Edge{ "Moscow","Khabarovsk", 1, 1, 2});
			listEdg.pushBack(Edge{ "Khabarovsk","Moscow", 35, 2, 1 });
			listEdg.pushBack(Edge{ "Saint-P","Khabarovsk", 14, 0, 2 });
			listEdg.pushBack(Edge{ "Vladivostok","Khabarovsk", 13, 3, 2 });
			listEdg.pushBack(Edge{ "Khabarovsk","Vladivostok", 8, 2, 3 });
			listEdg.pushBack(Edge{ "Saint-P","Vladivostok", 20, 0, 3 });


			Assert::AreEqual(11, algorithm(&listEdg, &listStr, "Saint-P", "Khabarovsk"));
			Assert::AreEqual(9, algorithm(&listEdg, &listStr,  "Moscow", "Vladivostok"));//Moscow->Khabarovsk->Vladivosotk no way straight Moscow->Vladivostok
			Assert::AreEqual(INT_MAX - 10000, algorithm(&listEdg, &listStr, "Moscow", "Moscow"));
		}
	};
}

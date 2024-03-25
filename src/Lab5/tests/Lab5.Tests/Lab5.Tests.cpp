#include "pch.h"
#include "CppUnitTest.h"
#include"..\..\src\GeneticAlgorithm.cpp"
#include"..\..\src\Graph.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5Tests
{
	TEST_CLASS(Lab5Tests)
	{
	public:
		
		TEST_METHOD(PositiveTest)
		{
			Graph graph(50, 2, 15);
			GeneticAlgorithm algo(graph, 100);
			Assert::IsTrue(algo.solve(10).size() > 0);
		}

		TEST_METHOD(NegativeTest)
		{
			Graph graph(50, 2, 15);
			GeneticAlgorithm algo(graph, 100);
			Assert::IsTrue(algo.solve(0).empty());
		}

		TEST_METHOD(BoundaryTest)
		{
			Graph graph(2, 1, 1);
			GeneticAlgorithm algo(graph, 3);
			Assert::IsTrue(algo.solve(2).size() == 1);
		}
	};
}

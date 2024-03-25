#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\src\Problem.cpp"
#include "..\..\src\Node.cpp"
#include "..\..\src\LDFS.cpp"
#include "..\..\src\RBFS.cpp"
#include "..\..\src\BoardCreator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab2Test
{
    TEST_CLASS(Lab2Test)
    {
    public:

        TEST_METHOD(PositiveCreate)
        {
            int sizeBoard = 8;
            Problem problem(sizeBoard);

            Node* startNode = BoardCreator<Node>::createStartBoard(sizeBoard, &problem);
            int sizeCreate = sqrt(startNode->getState().size());

            Assert::AreEqual(sizeCreate, sizeBoard);
        }

        TEST_METHOD(PositiveHeurictic)
        {
            vector<int> state = {
                0, 0, 0, 0, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 1, 0,
                0, 0, 0, 1, 0, 0, 0, 0,
                1, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 1, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 1,
                0, 0, 0, 0, 0, 1, 0, 0,
                0, 1, 0, 0, 0, 0, 0, 0 };
            Problem pr(8);

            int solve = pr.heuristics(state);

            Assert::AreEqual(0, solve);
        }

        TEST_METHOD(NegativeLDFS)
        {
            vector<int> valueState = {
               1, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 1, 0, 0, 0,
                1, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 1, 0, 0,
                0, 0, 1, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 1, 0,
                0, 1, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 1, 0, 0, 0, 0
            };
            int sizeBoard = 8;
            ProblemLDFS pr(sizeBoard);
            int limit = 2;

            LDFS algoritm;
            Node start(valueState, pr.FindQueen(valueState));
            Node* result = algoritm.DepthLimitedSearch(&pr, &start, limit);

            Assert::AreEqual(result->getIsSolution(), false);
        }

        TEST_METHOD(BoundaryRBFS)
        {
            vector<int> valueState = {
               1, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 1, 0,
                0, 0, 0, 0, 0, 1, 0, 0,
                0, 0, 1, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 1, 0,
                0, 1, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 1, 0, 0, 0, 0
            };
            int sizeBoard = 8;
            ProblemHeuristic pr(sizeBoard);

            RBFS algoritm;
            NodeHeuristic start(valueState, pr.FindQueen(valueState), pr.heuristics(valueState), nullptr, 0);
            algoritm.RecursiveBestFirstSearch(&start, &pr, 0);

            Assert::AreEqual(algoritm.getSolutionFound(), false);
        }
    };
}


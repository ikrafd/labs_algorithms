#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\src\miniMax.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab6Tests
{
	TEST_CLASS(Lab6Tests)
	{
	public:
		
		TEST_METHOD(PositiveTest)
		{
			miniMax work;
			work.setPlayer(1);
			work.updateBoard(-1, 1);
			work.updateBoard(-1, 6);
			work.updateBoard(-1, 11);
			work.updateBoard(-1, 16);

			Assert::IsTrue(work.checkWin());
		};

		TEST_METHOD(NegativeTest)
		{
			miniMax work;
			bool checkZero = true;
			work.setPlayer(1);
			work.updateBoard(-10, -1);
			for (int i = 0; i < 25; i++) {
				if (work.getValueBoard(i) != 0) {
					checkZero = false;
				}
			}

			Assert::IsTrue(checkZero);
		};

		TEST_METHOD(BoundaryTest)
		{
			miniMax work;
			work.setPlayer(1);
			for (int i = 1; i < 24; i++) {
				work.updateBoard(-1, i);
			}
			work.setPlayer(2);

			Assert::AreEqual(23, work.move().first);
		};

	};
}

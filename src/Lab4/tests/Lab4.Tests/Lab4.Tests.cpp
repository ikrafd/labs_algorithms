#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\..\Lab4\src\FourthLab\BeeColony.cpp"
#include "..\..\..\Lab4\src\FourthLab\Graph.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4Tests
{
	TEST_CLASS(Lab4Tests)
	{

	public:
		
		TEST_METHOD(PositiveTest)
		{
			Graph startGraph(10, 4);
			BeeColony colony(startGraph, 12, 2);
			colony.solve(30);
			Assert::AreEqual(colony.isProperlyColored(), true);
			
		}

		TEST_METHOD(NegativeTest)
		{
			Graph startGraph(40, 8);
			BeeColony colony(startGraph, 0, 0);
			colony.solve(2);
			Assert::AreEqual(colony.checkPainting(),false);

		}

		TEST_METHOD(BoundaryTest)
		{
			Graph startGraph(10, 4);
			BeeColony colony(startGraph, 1, 0);
			colony.solve(1);
			Assert::AreEqual(colony.isProperlyColored(), false);
		}
	};
}

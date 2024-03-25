#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\src\algorithm.cpp"
#include "..\..\src\createFile.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1Tests
{
	TEST_CLASS(Lab1Tests)
	{
	public:
		
		TEST_METHOD(TestPositive)
		{
            algorithm algo;
            vector<int> startVector = { 3, 6, 7, 4, 7, 9, 2, 5, 8, 3, 4, 9};
            vector<int> bVector = { 3, 6, 7, 2, 5, 8 };
            vector<int> cVector = {4, 7, 9, 3, 4, 9 };

            ofstream fileA("A.bin", ios::trunc);
            for (int num : startVector) {
                fileA<< num <<" ";
            }
            fileA.close();

            const int sizeOfGroup = 3;
            algo.writeInBC(sizeOfGroup);

            ifstream fileB("B.bin"), fileC("C.bin");
            int temp;

            vector<int> bValues, cValues;

            while (fileB >> temp) {
                bValues.push_back(temp);
            }

            while (fileC >> temp) {
                cValues.push_back(temp);
            }

            fileB.close();
            fileC.close();

            for (size_t i = 0; i < bVector.size(); ++i) {
                Assert::AreEqual(bVector[i], bValues[i]);
            }

            for (size_t i = 0; i < cVector.size(); ++i) {
                Assert::AreEqual(cVector[i], cValues[i]);
            }
           
		}

        TEST_METHOD(TestNegative)
        {
            algorithm algo;
            vector<int> startVector = { 3, 6, 4, 7, 2, 8, 9, 4 };
            int sizeOfGroup = -5;

            ofstream fileA("A.bin", ios::trunc);
            for (int num : startVector) {
                fileA << num << " ";
            }
            fileA.close();

            Assert::ExpectException<invalid_argument>([&]() {
                algo.writeInBC(sizeOfGroup);
                });

        }

        TEST_METHOD(TestBoundary)
        {
            algorithm algo;
            vector<int> startVector = { 3, 6, 7, 4, 7, 9, 2, 5, 8, 3, 4, 9 };
            int sizeOfGroup = static_cast<int>(startVector.size());  // Set sizeOfGroup to the length of startVector

            ofstream fileA("A.bin", ios::trunc);
            for (int num : startVector) {
                fileA << num << " ";
            }
            fileA.close();

            algo.writeInBC(sizeOfGroup);

            ifstream fileB("B.bin"), fileC("C.bin");
            int temp;

            vector<int> bValues, cValues;

            while (fileB >> temp) {
                bValues.push_back(temp);
            }

            while (fileC >> temp) {
                cValues.push_back(temp);
            }

            fileB.close();
            fileC.close();

            // Check if the output vectors match the startVector
            for (size_t i = 0; i < startVector.size(); ++i) {
                Assert::AreEqual(startVector[i], bValues[i]);
            }
            Assert::AreEqual(cValues.empty(), true);
        }
	};
}

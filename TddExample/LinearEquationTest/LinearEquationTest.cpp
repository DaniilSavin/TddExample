#include "pch.h"
#include "CppUnitTest.h"
#include"../Task2/LinearEquation.h";
#include"../Task2/LinearEquation.cpp";
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinearEquationTest
{
	TEST_CLASS(LinearEquationTest)
	{
	public:

		TEST_METHOD(CorrectIndex1)
		{
			vector<double>_a{ 1,2,3,4,6,7 };
			LinearEquation a(_a);
			Assert::AreEqual(2.0, a[1]);
		}
		TEST_METHOD(CorrectIndex2)
		{
			string s = "4, 5, 3.1, 9, 4, 8, 11, 12";
			LinearEquation a(s);
			Assert::AreEqual(3.1, a[2]);
		}

		TEST_METHOD(CorrectIndex3)
		{
			LinearEquation a(10);
			Assert::AreEqual(0.0, a[5]);
		}
		TEST_METHOD(CorrectMult1)
		{
			string s = "4, 5, 3.1, 9, 4, 8, 11, 12";
			LinearEquation a(s);
			a = a * 4.0;
			Assert::AreEqual(16.0, a[0]);
		}
		TEST_METHOD(CorrectMult2)
		{
			string s = "4, 5, 3.1, 9, 4, 8, 11, 12";
			LinearEquation a(s);
			a = a * 4.0;
			Assert::AreEqual(32.0, a[5]);
		}

		TEST_METHOD(CorrectSum)
		{
			string s1 = "4, 5, 3.1, 9, 4, 8, 11, 12";
			string s2 = "31, 32, 33, 34, 35.35, 36, 37, 38";
			LinearEquation a(s1);
			LinearEquation b(s2);
			LinearEquation res("35, 37, 34.1, 43, 39.35, 42, 47, 50");
			Assert::AreEqual(true, res == (a + b));
		}
		TEST_METHOD(CorrectSub)
		{
			string s1 = "4, 5, 3.1, 9, 4, 8, 11, 12";
			string s2 = "31, 32, 33, 34, 35.35, 36, 37, 38";
			LinearEquation a(s1);
			LinearEquation b(s2);
			LinearEquation res("-29, -27, -29.9, -25, -31.35, -24, -26, -26");
			Assert::AreEqual(true, res == (a - b));
		}

		TEST_METHOD(SameInit)
		{
			LinearEquation a(5);
			a.same_initialization(22.222);
			Assert::AreEqual(22.222, a[6]);
		}

		TEST_METHOD(CorrectUnaryMinus)
		{
			LinearEquation a("-29, -27, -29.9, -25, -31.35, -24, -26, -26");
			a = -a;
			Assert::AreEqual(3.0, a[1]);
		}

		TEST_METHOD(CheckContradictoryEquation)
		{
			LinearEquation a("-1, 0, 1, 1");
			bool check = (a) ? true : false;
			Assert::AreEqual(false, check);
		}


		TEST_METHOD(CheckSolvableEquation)
		{
			LinearEquation a("-1, 0, 1, 1");
			bool check = (a) ? true : false;
			Assert::AreEqual(true, check);
		}
		TEST_METHOD(CopyToList)
		{
			LinearEquation a(" - 1, 0, 1, 1");
			list<double> tmp = a;
			Assert::AreEqual(0.0, tmp.front());
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto func = []() {

				LinearEquation a("-1, 0, 1, 1");
				double tmp = a[-1];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto func = []() {

				LinearEquation a("-1, 0, 1, 1");
				double tmp = a[10];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
	};
}

#include "stdafx.h"
//#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathParserTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ExpresionWithoutBrackets)
		{
			std::string expr1("1+2=");
			std::string expr2("1/9=");
			std::string expr3("1-400=");
			std::string expr4("1*20=");
			std::string expr5("7^8=");
			std::string expr6("1-2*9=");
			std::string expr7("1+9*6-4/3=");
			std::string expr8("1+2-1/10*20+3^4*5+4+5+6+7*2=");

			double resExpr1 = 1 + 2;
			double resExpr2 = (double)1 / 9;
			double resExpr3 = 1 - 400;
			double resExpr4 = 1 * 20;
			double resExpr5 = pow(7, 8);
			double resExpr6 = 1 - 2 * 9;
			double resExpr7 = 1 + 9 * 6 - (double)4 / 3;
			double resExpr8 = 1 + 2 - (double)1 / 10 * 20 + pow(3,4) * 5 + 4 + 5 + 6 + 7 * 2;

			Expression testExpr1(expr1);
			Expression testExpr2(expr2);
			Expression testExpr3(expr3);
			Expression testExpr4(expr4);
			Expression testExpr5(expr5);
			Expression testExpr6(expr6);
			Expression testExpr7(expr7);
			Expression testExpr8(expr8);

			Assert::AreEqual(resExpr1, testExpr1.CalcExpr());
			Assert::AreEqual(resExpr2, testExpr2.CalcExpr());
			Assert::AreEqual(resExpr3, testExpr3.CalcExpr());
			Assert::AreEqual(resExpr4, testExpr4.CalcExpr());
			Assert::AreEqual(resExpr5, testExpr5.CalcExpr());
			Assert::AreEqual(resExpr6, testExpr6.CalcExpr());
			Assert::AreEqual(resExpr7, testExpr7.CalcExpr());
			Assert::AreEqual(resExpr8, testExpr8.CalcExpr());
		}


		TEST_METHOD(ExpresionWithBrackets)
		{
			std::string expr1("7*(2+3)=");
			std::string expr2("1/(9-2)=");
			std::string expr3("1-(400/(20+20)-40/5)=");
			std::string expr4("(1-5)*20=");
			std::string expr5("2^(8-5)=");
			std::string expr6("(2^8)-5=");
			std::string expr7("(1+9)*(6-4)/3=");
			std::string expr8("1+(2-1)/10*(20-17)^(4*5)+(4+7)*2=");

			double resExpr1 = 7 * (2 + 3);
			double resExpr2 = (double)1 / (9 - 2);
			double resExpr3 = 1 - ((double)400 / (20 + 20) - (double)40 / 5);
			double resExpr4 = (1 - 5) * 20;
			double resExpr5 = pow(2,(8 - 5));
			double resExpr6 = pow(2, 8) - 5;
			double resExpr7 = (1 + 9)*((double)6 - 4) / 3;
			double resExpr8 = 1 + ((double)2 - 1) / 10 * pow((20 - 17),(4 * 5)) + (4 + 7) * 2;

			Expression testExpr1(expr1);
			Expression testExpr2(expr2);
			Expression testExpr3(expr3);
			Expression testExpr4(expr4);
			Expression testExpr5(expr5);
			Expression testExpr6(expr6);
			Expression testExpr7(expr7);
			Expression testExpr8(expr8);

			Assert::AreEqual(resExpr1, testExpr1.CalcExpr());
			Assert::AreEqual(resExpr2, testExpr2.CalcExpr());
			Assert::AreEqual(resExpr3, testExpr3.CalcExpr());
			Assert::AreEqual(resExpr4, testExpr4.CalcExpr());
			Assert::AreEqual(resExpr5, testExpr5.CalcExpr());
			Assert::AreEqual(resExpr6, testExpr6.CalcExpr());
			Assert::AreEqual(resExpr7, testExpr7.CalcExpr());
			Assert::AreEqual(resExpr8, testExpr8.CalcExpr());
		}
	};
}
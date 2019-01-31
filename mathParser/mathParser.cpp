
#include "pch.h"
#include "Expression.h"


using namespace std;



int main()
{
	std::string expr1("1+2=");
			std::string expr2("1/9=");
			std::string expr3("1-400=");
			std::string expr4("1*20=");
			std::string expr5("7^8=");
			std::string expr6("1-2*9=");
			std::string expr7("1+9*6-4/3=");
			std::string expr8("1+2-1/10*(-20)+3^4*5+4+5+6+7*2=");
			double resExpr1 = 1 + 2;
			double resExpr2 = (double)1 / 9;
			double resExpr3 = 1 - 400;
			double resExpr4 = 1 * 20;
			double resExpr5 = pow(7, 8);
			double resExpr6 = 1 - 2 * 9;
			double resExpr7 = 1 + 9 * 6 - (double)4 / 3;
			double resExpr8 = 1 + 2 - (double)1 / 10 * (-20) + pow(3, 4) * 5 + 4 + 5 + 6 + 7 * 2;

			Expression testExpr1(expr1);
			Expression testExpr2(expr2);
			Expression testExpr3(expr3);
			Expression testExpr4(expr4);
			Expression testExpr5(expr5);
			Expression testExpr6(expr6);
			Expression testExpr7(expr7);
			Expression testExpr8(expr8);

			cout << testExpr1.CalcExpr() << " " << resExpr1 << endl;
			cout << testExpr2.CalcExpr() << " " << resExpr2 << endl;
			cout << testExpr3.CalcExpr() << " " << resExpr3 << endl;
			cout << testExpr4.CalcExpr() << " " << resExpr4 << endl;
			cout << testExpr5.CalcExpr() << " " << resExpr5 << endl;
			cout << testExpr6.CalcExpr() << " " << resExpr6 << endl;
			cout << testExpr7.CalcExpr() << " " << resExpr7 << endl;
			cout << testExpr8.CalcExpr() << " " << resExpr8 << endl;
	return 0;
}
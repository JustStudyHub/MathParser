
#include "pch.h"
#include "Expression.h"


using namespace std;



int main()
{
	Expression nExp1("1+(17-8)^2/5-9*3=");
	Expression nExp2("1+(17-8)^(2/5)^9*3=");
	Expression nExp3("(2*(7-(12*6+(23+3/7))))=");
	cout << "1+(17-8)^2/5-9*3=" << nExp1.CalcExpr() << endl;
	cout << "-------------------------" << endl;
	cout << "1+(17-8)^(2/5)^9*3=" << nExp2.CalcExpr() << endl;
	cout << "-------------------------" << endl;
	cout << "(2*(7-(12*6+(23+3/7))))=" << nExp3.CalcExpr() << endl;
	return 0;
}
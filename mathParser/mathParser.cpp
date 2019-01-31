
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Expression
{
public:
	Expression( string expression)
	{
		this->rest = expression;
		this->parse();
	}

	~Expression()
	{

	}

	double calcExpr()
	{
		int max_i = 0;
		size_t max = operVec.size();
		for (size_t j = 0; j < max; ++j)
		{
			for (size_t i = 0; i < operVec.size(); ++i)
			{
				if (operVec[max_i].operWeight < operVec[i].operWeight)
					max_i = i;
			}
			res = calcOper(operVec[max_i].oper, operVec[max_i].lVal->val, operVec[max_i].rVal->val);
			cout << res << "=" << operVec[max_i].lVal->val << operVec[max_i].oper << operVec[max_i].rVal->val << endl;
			operVec[max_i].operWeight = 0;
			if (max_i - 1 >= 0 )
			{
				operVec[max_i - 1].rVal->val = res;
			}
			if (max_i + 1 < operVec.size())
			{
				operVec[max_i + 1].lVal->val = res;
			}
			operVec.erase(operVec.begin() + max_i);
			max_i = 0;
		}				
		return res;
	}
private:	
	struct node
	{
		bool isVal;
		string name;
		char oper;
		int operWeight;
		double val;
		node* lVal;
		node* rVal;
		node(double val)
		{
			this->val = val;
			this->isVal = true;
			this->name = to_string(val);
			this->lVal = nullptr;
			this->rVal = nullptr;
		}
		node(char oper, int weightCoef)
		{
			this->oper = oper;
			switch (oper)
			{
			case '-': case '+':
				this->operWeight = 1 * weightCoef;
				break;
			case '/': case '*':
				this->operWeight = 2 * weightCoef;
				break;
			case '^':
				this->operWeight = 3 * weightCoef;
				break;
			default:
				break;
			}			
			this->isVal = false;
			this->name = oper;		
			this->lVal = nullptr;
			this->rVal = nullptr;
		}
	};
	vector <node> expr;
	vector <node> operVec;
	double res;
	string rest;
	void parse()
	{
		string temp = "";
		int bracketCoef = 1;
		for (size_t i = 0; i < rest.length(); ++i)
		{
			switch (rest[i])
			{
			case '(': 
				bracketCoef *= 4;
				break;
			case ')':
				bracketCoef /= 4;
				break;
			case '+': case '-':case '*': case '/':case '^': 
				if (temp.length() != 0)
				{
					expr.push_back(node(stod(temp)));
					temp = "";
				}			
				expr.push_back(node(rest[i], bracketCoef));
				break;
			case '=':
				if (temp.length() != 0)
				{
					expr.push_back(node(stod(temp)));
					temp = "";
				}
				break;
			case '1': case '2': case '3': case '4': case '5': case '6':
			case '7': case '8': case '9': case '0': case '.':
				temp += rest[i];
				break;
			default:
				break;
			}
		}
		for (size_t i = 1; i < expr.size() - 1; i++)
		{
			if (!expr[i].isVal)
			{
				expr[i].lVal = &expr[i - 1];
				expr[i].rVal = &expr[i + 1];
				operVec.push_back(expr[i]);
			}
		}
	}
	double calcOper(char oper, double a, double b)
	{
		switch (oper)
		{
		case '-':
			return a - b;
			break;

		case '+':
			return a + b;
			break;
		case '*':
			return a * b;
			break;
		case '/':
			return a / b;
			break;
		case '^':
			return pow(a, b);
			break;
		default:
			break;
		}
	}
	
};

int main()
{
	Expression nExp1("1+(17-8)^2/5-9*3=");
	Expression nExp2("1+(17-8)^(2/5)^9*3=");
	Expression nExp3("(2*(7-(12*6+(23+3/7))))=");
	cout << "1+(17-8)^2/5-9*3=" << nExp1.calcExpr() << endl;
	cout << "-------------------------" << endl;
	cout << "1+(17-8)^(2/5)^9*3=" << nExp2.calcExpr() << endl;
	cout << "-------------------------" << endl;
	cout << "(2*(7-(12*6+(23+3/7))))=" << nExp3.calcExpr() << endl;
	return 0;
}
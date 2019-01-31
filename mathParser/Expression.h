#pragma once
#include "pch.h"
class Expression
{
public:
	Expression(std::string expression);
	~Expression();
	double CalcExpr();
private:
	struct Node
	{
		bool m_isVal;
		std::string m_name;
		char m_oper;
		int m_operWeight;
		double m_val;
		Node* m_lVal;
		Node* m_rVal;
		Node(double val);
		Node(char oper, int weightCoef);
	};
	std::vector <Node> m_expr;
	std::vector <Node> m_operVec;
	double m_res;
	std::string m_rest;
	void Parse();
	double CalcOper(char oper, double a, double b);

};

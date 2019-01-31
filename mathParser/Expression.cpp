#include "pch.h"
#include "Expression.h"


Expression::Expression(std::string expression)
{
	this->m_rest = expression;
	this->Parse();
}

Expression::~Expression()
{

}

double Expression::CalcExpr()
{
	int max_i = 0;
	size_t max = m_operVec.size();
	for (size_t j = 0; j < max; ++j)
	{
		for (size_t i = 0; i < m_operVec.size(); ++i)
		{
			if (m_operVec[max_i].m_operWeight < m_operVec[i].m_operWeight)
				max_i = i;
		}
		m_res = CalcOper(m_operVec[max_i].m_oper, m_operVec[max_i].m_lVal->m_val, m_operVec[max_i].m_rVal->m_val);
		std::cout << m_res << "=" << m_operVec[max_i].m_lVal->m_val << m_operVec[max_i].m_oper << m_operVec[max_i].m_rVal->m_val << std::endl;
		m_operVec[max_i].m_operWeight = 0;
		if (max_i - 1 >= 0)
		{
			m_operVec[max_i - 1].m_rVal->m_val = m_res;
		}
		if (max_i + 1 < m_operVec.size())
		{
			m_operVec[max_i + 1].m_lVal->m_val = m_res;
		}
		m_operVec.erase(m_operVec.begin() + max_i);
		max_i = 0;
	}
	return m_res;
}

Expression::Node::Node(double val)
{
	this->m_val = val;
	this->m_isVal = true;
	this->m_name = std::to_string(val);
	this->m_lVal = nullptr;
	this->m_rVal = nullptr;
}
Expression::Node::Node(char oper, int weightCoef)
{
	this->m_oper = oper;
	switch (oper)
	{
	case '-': case '+':
		this->m_operWeight = 1 * weightCoef;
		break;
	case '/': case '*':
		this->m_operWeight = 2 * weightCoef;
		break;
	case '^':
		this->m_operWeight = 3 * weightCoef;
		break;
	default:
		break;
	}
	this->m_isVal = false;
	this->m_name = oper;
	this->m_lVal = nullptr;
	this->m_rVal = nullptr;
}

void Expression::Parse()
{
	std::string temp = "";
	int bracketCoef = 1;
	for (size_t i = 0; i < m_rest.length(); ++i)
	{
		switch (m_rest[i])
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
				m_expr.push_back(Node(std::stod(temp)));
				temp = "";
			}
			m_expr.push_back(Node(m_rest[i], bracketCoef));
			break;
		case '=':
			if (temp.length() != 0)
			{
				m_expr.push_back(Node(std::stod(temp)));
				temp = "";
			}
			break;
		case '1': case '2': case '3': case '4': case '5': case '6':
		case '7': case '8': case '9': case '0': case '.':
			temp += m_rest[i];
			break;
		default:
			break;
		}
	}
	for (size_t i = 1; i < m_expr.size() - 1; i++)
	{
		if (!m_expr[i].m_isVal)
		{
			m_expr[i].m_lVal = &m_expr[i - 1];
			m_expr[i].m_rVal = &m_expr[i + 1];
			m_operVec.push_back(m_expr[i]);
		}
	}
}
double Expression::CalcOper(char oper, double a, double b)
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
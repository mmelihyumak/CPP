#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &source){
	*this = source;
}

RPN& RPN::operator=(const RPN &source){
	if (this != &source){
		this->operands = source.operands;
	}
	return *this;
}

void RPN::push_operand(int operand){

	this->operands.push(operand);
}

int RPN::pop_operand(){
	int i = operands.top();
	operands.pop();
	return i;
}

void RPN::exec_operator(int x1, int x2, char operate){

	int res;

	if (operate == '+')
		res = x1 + x2;
	else if (operate == '-')
		res = x2 - x1;
	else if (operate == '*')
		res = x2 * x1;
	else if (operate == '/')
		res = x2 / x1;
	operands.push(res);
}

void RPN::print_res(){
	std::cout << operands.top() << std::endl;
}


#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN{
	private:
		std::stack<int> operands;

	public:
		RPN();
		~RPN();
		RPN(const RPN &source);
		RPN& operator=(const RPN &source);

		void push_operand(int operand);
		int pop_operand();
		void exec_operator(int x1, int x2, char operate);
		void print_res();
};

#endif
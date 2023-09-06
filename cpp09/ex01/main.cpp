#include "RPN.hpp"

int main(int argc, char **argv){

	std::string arg;
	RPN rpn;
	std::stringstream ss(argv[1]);
	int x1, x2;

	while (getline(ss, arg, ' ')){
		if (isdigit(arg[0]) == true)
			rpn.push_operand(std::stoi(arg));
		else if (arg[0] == '+' || arg[0] == '-' || arg[0] == '*' || arg[0] == '/'){
			x1 = rpn.pop_operand();
			x2 = rpn.pop_operand();
			rpn.exec_operator(x1, x2, arg[0]);
		}
		else{
			std::cout << "Error" << std::endl;
			exit(0);
		}
	}
	rpn.print_res();
	
	return 0;
}
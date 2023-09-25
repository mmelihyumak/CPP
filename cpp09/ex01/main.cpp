#include "RPN.hpp"

int main(int argc, char **argv){

	if (argc != 2 || argv[1][0] == 0){
		std::cout << "Invalid number of arguments" << std::endl;
		exit(0);
	}

	try
	{
		std::string arg;
		RPN rpn;
		std::stringstream ss(argv[1]);
		int x1, x2;

		while (getline(ss, arg, ' ')){
			if (arg == "")
				continue;
			if (arg.size() > 1){
				std::cout << "Error" << std::endl;
				exit(0);
			}
			if (isdigit(arg[0]) == true)
				rpn.push_operand(std::stoi(arg));
			else if (arg[0] == '+' || arg[0] == '-' || arg[0] == '*' || arg[0] == '/'){
				if (rpn.getOperands().size() == 1){
					std::cout << "Error" << std::endl;
					exit(0);
				}
				x1 = rpn.pop_operand();
				x2 = rpn.pop_operand();
				rpn.exec_operator(x1, x2, arg[0]);
			}
			else{
				
				std::cout << "Errorrrr" << std::endl;
				exit(0);
			}
		}
		rpn.print_res();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
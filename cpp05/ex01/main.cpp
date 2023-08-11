#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form form("Form", 100, 100);
        Bureaucrat melih("melih", 150);
        melih.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}
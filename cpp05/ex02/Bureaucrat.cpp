#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    std::cout << "Bureaucrat '=' operator called" << std::endl;
    this->grade = bureaucrat.getGrade();
    return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooHighException();
    this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooLowException();
    this->grade += 1;
}

void Bureaucrat::signForm(AForm &aForm)
{
    try
    {
        aForm.beSigned(*this);
        std::cout << this->name + " signed" << aForm.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn't sign" << aForm.getName() << "because" << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}


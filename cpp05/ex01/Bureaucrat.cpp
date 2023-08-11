#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name)
{
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    this->grade = bureaucrat.getGrade();
    return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
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
    if (this->grade > 150)
        throw Bureaucrat::GradeTooHighException();
    this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooLowException();
    this->grade += 1;
}

void Bureaucrat::signForm(Form& form){
    try{
        form.beSigned(*this);
        std::cout << this->name + " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << this->name + " couldn't sign " + form.getName() + " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}


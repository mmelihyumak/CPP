#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);
        std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &aForm);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too high!"; }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too low!"; }
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
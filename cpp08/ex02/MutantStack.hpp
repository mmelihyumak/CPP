#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &source);
        MutantStack& operator=(const MutantStack &source);
};

#endif
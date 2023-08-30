#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
    public:

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack<T> &source);
        MutantStack<T>& operator=(const MutantStack<T> &source);

        iterator begin(){
            return this->c.begin();
        }

        const_iterator begin() const{
            return this->c.begin();
        }

        iterator end(){
            return this->c.end();
        }

        const_iterator end() const{
            return this->c.end();
        }
        
};

template <typename T>
MutantStack<T>::MutantStack(){

}

template <typename T>
MutantStack<T>::~MutantStack(){

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &source){
    if (this != &source){
        std::stack<T>::operator=(source);
    }
    *this = source;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &source){
    if (this != &source){
        std::stack<T>::operator=(source);
    }
    return *this;
}

#endif
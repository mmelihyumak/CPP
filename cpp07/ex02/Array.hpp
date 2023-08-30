#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T> class Array{

    private:
        T *array;
        unsigned int size;

    public:
        Array();
        ~Array();
        Array(unsigned int size);
        Array(const Array& source);
        Array& operator=(const Array& source);
        T& operator[](int i);
        class OutOfBoundsException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};


template <typename T>
Array<T>::Array(){
    this->array = new T[0];
    this->size = 0;
}

template <typename T>
Array<T>::~Array(){
    delete [] this->array;
}

template <typename T>
Array<T>::Array(unsigned int size){
    this->array = new T[size];
    this->size = size;
}

template <typename T>
Array<T>::Array(const Array<T> &source){
    *this = source;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &source){
    this->size = source.size;
    this->array = new T[this->size];
    for (unsigned int i = 0; i < this->size; i++){
        this->array[i] = source.array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int i){
    if (i >= (int)this->size || i < 0)
        throw Array<T>::OutOfBoundsException();
    return array[i];
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw(){
    return "Index is out of bounds";
}

#endif
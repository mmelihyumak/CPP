#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array{

    private:
        T *arr;
        unsigned int n;

    public:
        Array(){
            this->arr = new T;
            n = 1;
        }

        Array(unsigned int n){
            this->arr = new T[n];
            this->n = n;
            for (int i = 0; i < n; i++)
                arr[i] = i + 1;
        }

        Array(const Array& source){
            *this = source;
        }

        Array& operator=(const Array& source)
        {
            this->n = source.n;
            this->arr = new T(this->n);
            for (int i = 0; i < n; i++)
                this->arr[i] = (source.getArr())[i];
            return *this;
        }

        class OutOfBoundsException : std::exception{
            public:
                virtual const char* what() const throw(){
                    return "Index is out of bounds";
                }
        };
        
        T& operator[](unsigned int i) const{
            if (i >= n)
                throw OutOfBoundsException();
            return arr[i];
        }

        T* getArr(void) const{
            return arr;
        }

};

#endif
#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void print(T &i)
{
    std::cout << i << std::endl;
}

template <typename T>
void iter(T *array, int length, void (*f)(T&)){
    for (int i = 0; i < length; i++){
        f(array[i]);
    }
}

#endif
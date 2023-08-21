#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b){
    T c = a;
    a = b;
    b = c;
}

template <typename T>
T min(T a, T b){
    if (a >= b)
        return b;
    else
        return a;
}

template <typename T>
T max(T a, T b){
    if (a > b)
        return a;
    else
        return b;
}

#endif
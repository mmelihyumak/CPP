#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>
# include <set>

template <typename T>
int easyfind(T a, int n){

	int i = 0;
	typename T::iterator it;
	typename T::iterator end = a.end();
	for (it = a.begin(); it != end; ++it){
		if (*it == n)
			return i;
		i++;
	}
	return -1;
}

#endif
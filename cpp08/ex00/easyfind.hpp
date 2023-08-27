#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>
# include <set>

template <typename T>
typename T::iterator easyfind(T &t, int n){
	typename T::iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw std::exception();
	return it;
}

#endif
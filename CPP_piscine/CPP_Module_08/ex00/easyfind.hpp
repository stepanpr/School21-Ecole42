
//
// CPP_Mod08_ex00/emabel/21school
//

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <algorithm>
# include <iterator>


class notFound : public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return ("value is not found :(");
	};
};

template<typename T>
int easyfind(T &container, int value)
{
	typename T::const_iterator it;
	it = find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw notFound();
	}
	return *it;
}


#endif




// http://espressocode.top/for_each-loop-c/
// https://www.cplusplus.com/reference/algorithm/for_each/
// https://ravesli.com/urok-197-kontejnery-stl/#toc-2
// https://ravesli.com/urok-198-iteratory-stl/
// https://ravesli.com/urok-199-algoritmy-stl/
// https://www.youtube.com/watch?v=1cKvMZOJeeE&list=PLQOaTSbfxUtDWAtIYme5MLZ1l0GTyUYkB
#pragma once

template <typename T>
typename T::iterator easyfind(T &tab, int nb)
{
	typename T::iterator temp = (std::find(tab.begin(), tab.end(), nb));
	if (temp == tab.end())
		throw(std::exception());
	std::cout << nb << " has been found! \n";
	return (temp);
}

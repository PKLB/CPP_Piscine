#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	// MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::stack<int> s(mstack);

	MutantStack<std::string> mstack;
	std::string toto;
	toto = "\033[1;30mtoto\033[0m";
	mstack.push(toto);
	toto = "\033[1;31mtutu\033[0m";
	mstack.push(toto);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	toto = "\033[1;32mtiti\033[0m";
	mstack.push(toto);
	toto = "\033[1;33mtoutou\033[0m";
	mstack.push(toto);
	toto = "\033[1;34mtaitai\033[0m";
	mstack.push(toto);
	toto = "\033[1;35mtiutiu\033[0m";
	mstack.push(toto);
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<std::string> s(mstack);
	return 0;
}
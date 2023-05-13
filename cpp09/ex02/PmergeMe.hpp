#pragma once
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <ctime>
#include <sys/time.h>

class PmergeMe {
	public:
		PmergeMe();
		void sort_list(std::list<int>& listo);
		void sort_vector(std::vector<int>& vectoro);
		int check_data(const std::string input);
		PmergeMe(const PmergeMe& src);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& src);
};
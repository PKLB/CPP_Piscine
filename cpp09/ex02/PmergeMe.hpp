#pragma once
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

class PmergeMe {
	public:
		PmergeMe();
		void sort_list(std::list<int>& listo);
		void sort_vector(std::vector<int>& vectoro);
		int check_data(const std::string input);
		std::vector<int> algo_sort_vector(std::vector<int>);
		std::vector<int> fusion_vector(std::vector<int> sorted_vector, std::vector<int> tmp_vector);
		std::list<int> algo_sort_list(std::list<int>);
		std::list<int> fusion_list(std::list<int> sorted_list, std::list<int> tmp_list);
		PmergeMe(const PmergeMe& src);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& src);
};
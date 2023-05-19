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
		std::vector<int> ford_johnson_vector(std::vector<int>);
		std::vector<int> fusion_vector(std::vector<int> left_part, std::vector<int> right_part);
		std::list<int> ford_johnson_list(std::list<int>);
		std::list<int> fusion_list(std::list<int> left_part, std::list<int> right_part);
		PmergeMe(const PmergeMe& src);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& src);
};
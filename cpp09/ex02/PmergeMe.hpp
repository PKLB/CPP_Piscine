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
	int check_data(std::string input);
	void do_algo(std::vector<int> arr);
    PmergeMe(const PmergeMe& src);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& src);
};

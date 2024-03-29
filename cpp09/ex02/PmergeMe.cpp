#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

/*********LIST**********/

std::list<int>::iterator find_middle(std::list<int>& listo) {
    std::list<int>::iterator it = listo.begin();
    std::size_t size = listo.size();
    std::size_t middle = size / 2;

    for (std::size_t i = 0; i < middle; ++i)
        ++it;
    return it;
}

void merge_list(std::list<int>& left, std::list<int>& right, std::list<int>& result) {
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt <= *rightIt) {
            result.push_back(*leftIt);
            ++leftIt;
        } else {
            result.push_back(*rightIt);
            ++rightIt;
        }
    }
    while (leftIt != left.end()) {
        result.push_back(*leftIt);
        ++leftIt;
    }
    while (rightIt != right.end()) {
        result.push_back(*rightIt);
        ++rightIt;
    }
}

void ford_johnson_list(std::list<int>& listo) {
    if (listo.size() <= 1) {
        return;
    }
    std::list<int> left;
    std::list<int> right;
    std::list<int> sorted;
    std::list<int>::iterator middle = find_middle(listo);
    left.assign(listo.begin(), middle);
    right.assign(middle, listo.end());
    ford_johnson_list(left);
    ford_johnson_list(right);
    merge_list(left, right, sorted);
    std::list<int> remaining(listo.begin(), middle);
    for (std::list<int>::iterator it = remaining.begin(); it != remaining.end(); ++it) {
        std::list<int>::iterator insertPos = std::lower_bound(sorted.begin(), sorted.end(), *it);
        sorted.insert(insertPos, *it);
    }
    listo = sorted;
}

void  PmergeMe::do_algo_list(std::list<int> listo) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    ford_johnson_list(listo);
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
	listo.unique();
    int sizo = listo.size();
	std::cout << "Time to process a range of " << sizo <<
		" elements with \033[1;32mstd::list\033[0m: ";
	std::cout << std::setprecision(6) << std::fixed << elapsed << "s" << std::endl;
}

/*********VECTOR**********/

void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result) {
    std::vector<int>::iterator leftIt = left.begin();
    std::vector<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt <= *rightIt) {
            result.push_back(*leftIt);
            ++leftIt;
        } else {
            result.push_back(*rightIt);
            ++rightIt;
        }
    }
    while (leftIt != left.end()) {
        result.push_back(*leftIt);
        ++leftIt;
    }
    while (rightIt != right.end()) {
        result.push_back(*rightIt);
        ++rightIt;
    }
}

void ford_johnson(std::vector<int>& vectoro) {
    if (vectoro.size() <= 1) {
        return;
    }
    std::vector<int> left;
    std::vector<int> right;
    std::vector<int> sorted;
    std::vector<int>::iterator middle = vectoro.begin() + (vectoro.size() / 2);
    left.assign(vectoro.begin(), middle);
    right.assign(middle, vectoro.end());
    ford_johnson(left);
    ford_johnson(right);
    merge(left, right, sorted);
    
    std::vector<int> remaining(vectoro.begin(), middle);
    for (std::vector<int>::iterator it = remaining.begin(); it != remaining.end(); ++it) {
        std::vector<int>::iterator insertPos = std::lower_bound(sorted.begin(), sorted.end(), *it);
        sorted.insert(insertPos, *it);
    }
    vectoro = sorted;
}


void  PmergeMe::do_algo(std::vector<int> vectoro) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    ford_johnson(vectoro);
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    std::cout << "\033[1;33mAfter: \033[0m";
	int tmp;
    int sizo = 0;
    for (std::vector<int>::iterator it = vectoro.begin(); it != vectoro.end(); ++it) {
        if (tmp != *it)
        {
			std::cout << *it << " ";
            sizo++;
        }
		tmp = *it;
    }
    std::cout << std::endl;
	std::cout << "Time to process a range of " << sizo <<
		" elements with \033[1;32mstd::vector\033[0m: ";
	std::cout << std::setprecision(6) << std::fixed << elapsed << "s" << std::endl;
}

int PmergeMe::check_data(std::string input) {
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	return 0;
}

PmergeMe::PmergeMe(const PmergeMe& src){
	*this = src;
}

PmergeMe::~PmergeMe(){
}

PmergeMe &PmergeMe::operator=(const PmergeMe& src){
	(void)src;
	return *this;
}

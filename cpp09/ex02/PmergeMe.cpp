#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

std::vector<int> PmergeMe::fusion_vector(std::vector<int> sorted_vector, std::vector<int> tmp_vector){
	std::vector<int>::iterator it1 = sorted_vector.begin();
	std::vector<int>::iterator it2 = tmp_vector.begin();
	std::vector<int> final_vector;

	while(it1 != sorted_vector.end() && it2 != tmp_vector.end())
	{
		if ((*it1) < (*it2)){
			final_vector.push_back((*it1));
			it1++;
		}
		else{
			final_vector.push_back((*it2));
			it2++;
		}
	}
	while (it1 != sorted_vector.end()) {
		final_vector.push_back((*it1));
		++it1;
	}
	while (it2 != tmp_vector.end()) {
		final_vector.push_back((*it2));
		++it2;
	}
	return final_vector;
}

std::list<int> PmergeMe::fusion_list(std::list<int> sorted_list, std::list<int> tmp_list){
	std::list<int>::iterator it1 = sorted_list.begin();
	std::list<int>::iterator it2 = tmp_list.begin();
	std::list<int> final_list;

	while(it1 != sorted_list.end() && it2 != tmp_list.end())
	{
		if ((*it1) < (*it2)){
			final_list.push_back((*it1));
			it1++;
		}
		else{
			final_list.push_back((*it2));
			it2++;
		}
	}
	while (it1 != sorted_list.end()) {
		final_list.push_back((*it1));
		++it1;
	}
	while (it2 != tmp_list.end()) {
		final_list.push_back((*it2));
		++it2;
	}

	return final_list;
}

std::vector<int> PmergeMe::algo_sort_vector(std::vector<int> tmp_vector){
	std::vector<int> sorted_vector;

	if (tmp_vector.size() <= 1)
		return tmp_vector;
	else{
		for (std::vector<int>::iterator tmp = tmp_vector.begin(); tmp != tmp_vector.end(); tmp++){
			std::vector<int> tmp_vector(1, *tmp);
			sorted_vector = fusion_vector(sorted_vector, tmp_vector);
		}
	}
	if (!std::is_sorted(sorted_vector.begin(), sorted_vector.end()))
		algo_sort_vector(sorted_vector);
	return (sorted_vector);
}

std::list<int> PmergeMe::algo_sort_list(std::list<int> tmp_list)
{
	std::list<int> sorted_list;

	if (tmp_list.size() <= 1)
		return tmp_list;
	else{
		for (std::list<int>::iterator tmp = tmp_list.begin(); tmp != tmp_list.end(); tmp++){
			std::list<int> tmp_list(1, *tmp);
			sorted_list = fusion_list(sorted_list, tmp_list);
	}
	}
	if (!std::is_sorted(sorted_list.begin(), sorted_list.end()))
		sorted_list.sort();
	sorted_list.unique();
	return (sorted_list);
}


void PmergeMe::sort_list(std::list<int>& listo){
	int length = listo.size();
	std::list<int>::iterator it;
 	struct timeval begin, end;
    gettimeofday(&begin, 0);
	listo = algo_sort_list(listo);
    gettimeofday(&end, 0);
	// std::cout << "\033[1;36mAfter: \033[0m";
	// for (it = listo.begin(); it != listo.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << "\n";

    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
	std::cout << "Time to process a range of " << length <<
		" elements with \033[1;32mstd::list\033[0m: ";
	std::cout << std::setprecision(6) << std::fixed << elapsed << "s" << std::endl;
	return;
}

void PmergeMe::sort_vector(std::vector<int>& vectoro){
	int length = vectoro.size();
	struct timeval begin, end;
    gettimeofday(&begin, 0);
	vectoro = algo_sort_vector(vectoro);
	gettimeofday(&end, 0);
	std::cout << "\033[1;33mAfter:  \033[0m";
	for (size_t i = 0; i < vectoro.size(); i++)
		std::cout << vectoro[i] << " ";
	std::cout << "\n";

	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
	std::cout << "Time to process a range of " << length <<
		" elements with \033[1;32mstd::vector\033[0m: ";
	std::cout << std::setprecision(6) << std::fixed << elapsed << "s" << std::endl;
	return;
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

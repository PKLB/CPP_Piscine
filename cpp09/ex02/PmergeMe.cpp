#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

std::vector<int> PmergeMe::ford_johnson_vector(std::vector<int> tmp_vector){
	std::vector<int> sorted_vector;
	std::vector<int> left_part;
	std::vector<int> right_part;

	if (tmp_vector.size() <= 1)
		return tmp_vector;
	else{
		for (struct {std::vector<int>::iterator it; size_t index;} s = {tmp_vector.begin(), 0}; s.it != tmp_vector.end(); s.it++, s.index++)
			(s.index <= tmp_vector.size() / 2 ? left_part : right_part).push_back((*s.it));
		sorted_vector = fusion_vector(left_part, right_part);
	}
	if (!std::is_sorted(sorted_vector.begin(), sorted_vector.end()))
		sort(sorted_vector.begin(), sorted_vector.end());
	std::unique(sorted_vector.begin(), sorted_vector.end());

	return (sorted_vector);
}

std::vector<int> PmergeMe::fusion_vector(std::vector<int> left_part, std::vector<int> right_part){
	std::vector<int> fusioned_vector;
	std::vector<int>::iterator left_it = left_part.begin();
	std::vector<int>::iterator right_it = right_part.begin();
	while (left_it != left_part.end() && right_it != right_part.end())
	{
		if ((*left_it) <= (*right_it))
			fusioned_vector.push_back((*left_it++));
		else
			fusioned_vector.push_back((*right_it++));
	}
	for (std::vector<int>::iterator it = left_it ;it != left_part.end(); it++)
		fusioned_vector.push_back((*it));
	for (std::vector<int>::iterator it = right_it;it != right_part.end(); it++)
		fusioned_vector.push_back((*it));

	return fusioned_vector;
}

std::list<int> PmergeMe::ford_johnson_list(std::list<int> tmp_list)
{
	std::list<int> sorted_list;
	std::list<int> left_part;
	std::list<int> right_part;

	if (tmp_list.size() <= 1)
		return tmp_list;
	else{
		for (struct {std::list<int>::iterator it; size_t index;} s = {tmp_list.begin(), 0}; s.it != tmp_list.end(); s.it++, s.index++)
			(s.index <= tmp_list.size() / 2 ? left_part : right_part).push_back((*s.it));
		sorted_list = fusion_list(left_part, right_part);
	}
	if (!std::is_sorted(sorted_list.begin(), sorted_list.end()))
		sorted_list.sort();
	sorted_list.unique();
	return (sorted_list);
}

std::list<int> PmergeMe::fusion_list(std::list<int> left_part, std::list<int> right_part)
{
	std::list<int> fusioned_list;
	std::list<int>::iterator left_it = left_part.begin();
	std::list<int>::iterator right_it = right_part.begin();
	while (left_it != left_part.end() && right_it != right_part.end())
	{
		if ((*left_it) <= (*right_it))
			fusioned_list.push_back((*left_it++));
		else
			fusioned_list.push_back((*right_it++));
	}
	for (std::list<int>::iterator it = left_it ;it != left_part.end(); it++)
		fusioned_list.push_back((*it));
	for (std::list<int>::iterator it = right_it;it != right_part.end(); it++)
		fusioned_list.push_back((*it));
	return fusioned_list;
}

void PmergeMe::sort_list(std::list<int>& listo){
	int length = listo.size();
	std::list<int>::iterator it;
 	struct timeval begin, end;
    gettimeofday(&begin, 0);
	listo = ford_johnson_list(listo);
    gettimeofday(&end, 0);
	std::cout << "\033[1;36mAfter: \033[0m";
	for (it = listo.begin(); it != listo.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

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
	vectoro = ford_johnson_vector(vectoro);
	gettimeofday(&end, 0);
	// std::cout << "[vector] After: ";
	// for (size_t i = 0; i < vectoro.size(); i++)
	// 	std::cout << vectoro[i] << " ";
	// std::cout << "\n";

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

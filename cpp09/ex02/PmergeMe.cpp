#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

void PmergeMe::sort_list(std::list<int>& listo){
	int length = listo.size();
	std::list<int>::iterator it;
 	struct timeval begin, end;
    gettimeofday(&begin, 0);

	// listo.sort();
	/* list.sort() some kind of merge sort() implemented in list, subject specifies this : "It is strongly advised to implement
	your algorithm for each container and thus to avoid using a generic function." So it's not forbidden, but this sort is a merge sort
	so it might not fit the requirements? */
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
	printf("%.6fs\n", elapsed);
	return;
}

void PmergeMe::sort_vector(std::vector<int>& vectoro){
	int length = vectoro.size();
	struct timeval begin, end;
    gettimeofday(&begin, 0);

	// std::sort (vectoro.begin(), vectoro.end());
	// insertionSort(vectoro);
	gettimeofday(&end, 0);
	std::cout << "[vector] After: ";
	for (size_t i = 0; i < vectoro.size(); i++)
		std::cout << vectoro[i] << " ";
	std::cout << "\n";

	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
	std::cout << "Time to process a range of " << length <<
		" elements with \033[1;32mstd::vector\033[0m: ";
	printf("%.6fs\n", elapsed);
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

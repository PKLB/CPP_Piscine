#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <ctime>
#include <sys/time.h>

/*
void merge_sort(){
	
	Declare an array Arr of length N
	If N=1, Arr is already sorted
	If N>1,
	Left = 0, right = N-1
	Find middle = (left + right)/2
	Call merge_sort(Arr,left,middle) =>sort first half recursively
	Call merge_sort(Arr,middle+1,right) => sort second half recursively
	Call merge(Arr, left, middle, right) to merge sorted arrays in above steps.
	
}
*/

/*
 void merge(){

}
*/

/* simple insertion sort below but subject is unclear to which algorithm is asked btw "merge-insert" and "merge-insertion" */
// void insertionSort(std::vector<int> &vectorito) 
// {
// 	int i, j, tmp;
// 	int n = vectorito.size();

// 	for (i = 1; i < n; i++)
// 	{
// 		j = i;
// 		tmp = vectorito[i];
// 		while (j > 0 && tmp<vectorito[j - 1])
// 		{
// 			vectorito[j] = vectorito[j - 1];
// 			j--;
// 		}
// 		vectorito[j] = tmp;
// 	}
// }

void sort_list(std::list<int> listo){
	int length = listo.size();
	std::list<int>::iterator it;
 	struct timeval begin, end;
    gettimeofday(&begin, 0);


	listo.sort();
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

void sort_vector(std::vector<int> vectoro){
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

int check_data(std::string input){
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

int main(int argc, char **argv){
	if (argc > 1)
	{
		std::string print_before;
		std::list<int> listo;
		std::vector<int> vectoro;

		for (int i = 1; i < argc; i++)
		{
			if (check_data(argv[i]) == 1)
				return 1;
			listo.push_back(atoi(argv[i]));
			vectoro.push_back(atoi(argv[i]));
			print_before += argv[i];
			if (i + 1 != argc)
				print_before += " ";
		}

		//Prints vector and list
		// std::list<int>::iterator it;
		// std::cout << "listo = ";
		// for (it = listo.begin(); it != listo.end(); ++it)
		// 	std::cout << *it << " ";
		// std::cout << "vectoro = ";
		// for (size_t i = 0; i < vectoro.size(); i++)
        // 	std::cout << vectoro[i] << " ";
		// std::cout << std::endl;;
		
		std::cout << "\033[1;33mBefore: \033[0m" << print_before << std::endl;
		sort_list(listo);
		sort_vector(vectoro);
	}
	else
		std::cout << "\033[1;31mError: no arguments given.\033[0m" << std::endl;
}

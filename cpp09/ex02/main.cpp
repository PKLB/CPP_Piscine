#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc > 1)
	{
		PmergeMe yoyo;
		std::string print_before;
		std::list<int> listo;
		std::vector<int> vectoro;

		for (int i = 1; i < argc; i++)
		{
			if (yoyo.check_data(argv[i]) == 1)
				return 1;
			listo.push_back(atoi(argv[i]));
			vectoro.push_back(atoi(argv[i]));
			print_before += argv[i];
			if (i + 1 != argc)
				print_before += " ";
		}
		std::cout << "\033[1;33mBefore: \033[0m" << print_before << std::endl;
		yoyo.sort_list(listo);
		yoyo.sort_vector(vectoro);
	}
	else
		std::cout << "\033[1;31mError: no arguments given.\033[0m" << std::endl;
}

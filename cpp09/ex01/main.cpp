#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

void calculate_data(std::string input_txt)
{
	std::stack<int> numbers;
	std::stringstream stream(input_txt);
	std::string tok;
	while (getline(stream, tok, ' ')) {
		if (isdigit(tok[0]))
			numbers.push(stod(tok));
		else if (numbers.size() >= 2)
		{
			int nb1 = numbers.top();
			numbers.pop();
			int nb2 = numbers.top();
			numbers.pop();
			int result = 0;
			if (tok == "+")
				result = nb2 + nb1;
			if (tok == "/")
				result = nb2 / nb1;
			if (tok == "*")
				result = nb2 * nb1;
			if (tok == "-")
				result = nb2 - nb1;
			numbers.push(result);
		}
	}
	while(!numbers.empty()) {
		std::cout << numbers.top() << " ";
		numbers.pop();
	}
}
int check_data(std::string input_txt)
{
	std::stringstream stream(input_txt);
	std::string tok;
	while (getline(stream, tok, ' ')) {
		if (tok.length() > 1)
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
		if (isdigit(tok[0]))
		{
			if (stod(tok) > 10 || stod(tok) < 0)
				std::cout << "Error" << std::endl;
		}
		else if (tok != "-" && tok != "+" && tok != "/" && tok != "*")
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	return 0;
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		std::string input_txt(argv[1]);
		if (check_data(input_txt) == 1)
			return 0;
		calculate_data(input_txt);
	}
	else
		std::cout << "\033[1;31mError: one argument only." << std::endl; 
}

/*
if chiffre -> add to stack
if operateur -> haut de la stack OP prochain chiffre

*/

// Le calcul ((1 + 2) × 4) + 3 peut se lire intuitivement :

// je mets 1, (1) ;
// j'ajoute 2, (2 +) ;
// je multiplie par 4, (4 ×) ;
// j'ajoute 3. (3 +).
// ce qui donne simplement 1 2 + 4 × 3 +

// 	Entrée			Opération			Pile
// Étape no 1	1	Pousser l’opérande	1
// Étape no 2	2	Pousser l’opérande	2
// 										1
// Étape no 3	+	Addition			3
// Étape no 4	4	Pousser l’opérande	4
// 										3
// Étape no 5	×	Multiplication		12
// Étape no 6	3	Pousser l’opérande	3
// 										12
// Étape no 7	+	Addition			15
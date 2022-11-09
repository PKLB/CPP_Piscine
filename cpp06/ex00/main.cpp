#include <iostream>
#include <string>
#include "MyData.hpp"

int main (int argc, char **argv)
{
	(void)argc;
	MyData toto;
	if (argc == 2){
		std::cout << toto;
		string src = argv[1];
	}
	return 0;
}

/*Écrivez un programme prenant en paramètre la représentation sous forme de chaîne
de caractères d’un littéral C++ sous sa forme la plus répandue. Le littéral doit faire
partie d’un des types scalaires suivants : char, int, float ou double. Hormis dans le cas de
paramètre de type char, seule la notation décimale sera utilisée.
Exemples de littéraux de type char : ’c’, ’a’, ...
Pour simplifier les choses, notez que les caractères non affichables ne seront pas passés à
votre programme. Si la conversion d’un char n’est affichable, mettez un message informatif.
Exemples de littéraux de type int : 0, -42, 42...
Exemples de littéraux de type float : 0.0f, -4.2f, 4.2f...
Vous devez gérer ces pseudo littéraux aussi (pour l’amour de la science) : -inff, +inff
et nanf.
Exemples de littéraux de type double : 0.0, -4.2, 4.2...
Vous devez gérer ces pseudo littéraux aussi (parce que c’est fun) : -inf, +inf et nan.
6
C++ - Module 06 C++ casts
Vous devez premièrement détecter le type du littéral passé en paramètre, le convertir
de sa représentation sous forme de chaîne de caractères vers son véritable type, et ensuite
le convertir explicitement vers les trois autres types de données.
Si une conversion n’a pas de sens ou overflow, affichez un message pour informer l’utilisateur que la conversion de type est impossible. Incluez tout fichier d’en-tête qui vous
sera nécessaire afin de gérer les limites numériques et les valeurs spéciales.*/
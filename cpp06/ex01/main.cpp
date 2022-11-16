#include <iostream>
#include <string>
#include "Data.hpp"

int main ()
{
	Data test;
	Data toto;
	uintptr_t nb;
	std::cout << &toto << std::endl;
	nb = toto.serialize(&test);
	std::cout << nb << std::endl;
	std::cout << toto.deserialize(nb) << std::endl;
	return 0;
}

/*Implémentez les fonctions suivantes :
uintptr_t serialize(Data* ptr);
Elle prend un pointeur et convertit celui-ci vers le type d’entier non-signé uintptr_t.
Data* deserialize(uintptr_t raw);
Elle prend un entier non-signé en paramètre et le convertit en pointeur sur Data.
Écrivez un programme pour tester vos fonctions et vous assurer que tout marche
comme attendu.
Vous devez créer une structure non-vide (cela signifie qu’elle comporte des variables
membres) Data.
Utilisez serialize() sur l’adresse de l’objet Data et passez la valeur de retour obtenue
à deserialize(). Ensuite, assurez-vous que le retour de deserialize() est identique
au pointeur d’origine.
N’oubliez pas de rendre les fichiers de votre structure Data.*/
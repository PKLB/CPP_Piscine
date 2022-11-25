#pragma once
#include <string>
#include <iostream>

template <typename T> 
class Array{
	public:
		Array();
		Array(const Array &src);
		Array(unsigned int n);
		Array &operator=(const Array& src);
		~Array();
		
		int size() const;
	private:
};


/*Créez une classe template Array (tableau) contenant des éléments de type T et qui
implémente le comportement suivant et les fonctions suivantes :
• Construction sans paramètres : crée un array vide.
• Construction avec un paramètre de type unsigned int n : crée un array de n
éléments initialisés par défaut.
Conseil : Essayez de compiler int * a = new int(); puis affichez *a.
• Construction par recopie et surcharge de l’opérateur d’affectation. Dans les deux
cas, après une copie, toute modification de l’array original ou de sa copie ne doit
pas impacter l’autre array.
• Vous DEVEZ utiliser l’opérateur new[] pour allouer de la mémoire. Toute allocation préventive 
(c’est-à-dire allouer de la mémoire en avance) est interdite. Votre
programme ne doit pas pouvoir accéder à une zone non allouée.
• Les éléments doivent être accessibles grâce à l’opérateur d’indice : [ ].
• En cas d’index invalide lors d’une tentative d’accès d’un élément en utilisant l’opérateur [ ], 
une std::exception est jetée.
• Une fonction membre size() qui retourne le nombre d’éléments dans l’array. Cette
fonction membre ne prend aucun paramètre et ne doit pas modifier l’instance courante*/
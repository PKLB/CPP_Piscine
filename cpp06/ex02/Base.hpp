#pragma once

class Base{
	public:
		virtual ~Base();
};

class A: public Base{
};

class B: public Base{
};

class C: public Base{
};
/*Implémentez une classe Base comportant seulement un destructeur public virtuel.

Créez trois classes vides A, B et C, héritant publiquement de Base.
Ces quatre classes n’ont pas à se conformer à la forme canonique de
Coplien.

Implémentez les fonctions suivantes :
Base * generate(void);
Elle crée aléatoirement une instance de A, B ou C et la retourne en tant que pointeur sur
Base. Utilisez ce que vous souhaitez pour l’implémentation du choix aléatoire.

void identify(Base* p);
Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C".

void identify(Base& p);
Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C". Utiliser un pointeur
dans cette fonction est interdit.

Le fichier d’en-tête typeinfo est interdit.
Écrivez un programme pour tester que tout fonctionne comme attendu.*/
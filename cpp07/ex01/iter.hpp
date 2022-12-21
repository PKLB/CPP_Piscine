#pragma once
#include <iostream>

template <typename T>
void iter(T *tab, int size, void (*func)(const T &)){
	for (int i = 0; i < size; i++)
		func(tab[i]);
}

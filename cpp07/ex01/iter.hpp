#pragma once
#include <iostream>

template <typename T, typename X>
void iter(T tab[], size_t size, X func){
	for (int i = 0; i < size; i++)
		func(tab[i]);
}
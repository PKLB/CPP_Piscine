#pragma once
#include <iostream>

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
 }

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
 }

template <typename T>
T swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
	return (a);
}
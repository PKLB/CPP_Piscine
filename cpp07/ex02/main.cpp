#include <iostream>
#include <time.h>
#include "Array.hpp"

int main(void)
{
    Array<int> numbersArray(10);

    try{
        numbersArray[-100] = 0;
    } catch(const std::exception& e){
        std::cerr << e.what();
    }
    try{
        numbersArray[100] = 0;
    } catch(const std::exception& e){
        std::cerr << e.what();
    }
	srand (time(NULL));
    for(int i = 0; i < 10; i++)
        numbersArray[i] = rand() % 100 + 1;
    for(int i = 0; i < 10; i++)
        std::cout << i << ": " << "\033[1;3"<< rand() % 10 << "m" << numbersArray[i] << "\033[0m" <<std::endl;

    Array<std::string>  stringArray(5);
    for(unsigned int i = 0; i < 5; i++)
        stringArray[i] = "\033[1;32mtesti\033[0m";
    for(unsigned int i = 0; i < 5; i++)
        std::cout << i << ": " << stringArray[i] << std::endl;
    try{
        stringArray[100] = "testo";
    } catch(const std::exception& n){
        std::cerr << n.what();
    }
    try{
        stringArray[-100] = "testu";
    } catch(const std::exception& no){
        std::cerr << no.what();
    }
    return 0;
}

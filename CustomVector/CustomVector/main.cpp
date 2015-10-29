#include <iostream>
#include "ArturVector.h"
#include "ArturVector.cpp" //we need to include this because otherwise linker is confused wich template class to link to this file

int main() {
	artur::arturVector<double> prices; // initially empty

	if (prices.empty())       // is prices empty?
		std::cout << "prices is empty" << std::endl;
	prices.push_back(23.56);
	prices.push_back(13.67);
	
	prices.back() = 20.25;
	prices.push_back(300.56);
	prices.push_back(45.67);
	ptices.pop_back();
	
	for (int i = 0; i < prices.size(); i++)
		std::cout << prices[i] << " ";
	std::cout << std::endl;

	return 0;
}

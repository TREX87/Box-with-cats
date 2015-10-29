#include <iostream>
#include "ArturVector.h"
#include "ArturVector.cpp" //we need to include this because otherwise linker is confused wich template class to link to this file

int main() {
	artur::arturVector<double> prices; // initially empty

	if (prices.empty())       // checks whether price is empty
		std::cout << "prices is empty" << std::endl;
	prices.push_back(23.56);
	prices.push_back(13.67);
	prices.push_back(100.55);

	prices.back() = 87.99;
	for (int i = 0; i < prices.size(); i++)
		std::cout << prices[i] << " ";
	std::cout << std::endl;

	prices.pop_back();
	for (int i = 0; i < prices.size(); i++)
		std::cout << prices[i] << " ";
	std::cout << std::endl;

	std::cout << prices.at(0) << std::endl;
	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include "Monster.h"
using namespace std;

int main()
{
	int number = 10, unit = 2;
	using monster::Monster;
	Monster* mickey;
	mickey = new Monster(10,34,12,25, "Bitch", 4);
	try {
		
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(30, 1);
			system("pause");
			mickey->humansFirst(30, 6);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
			system("pause");
			mickey->humansFirst(number, unit);
	}
	catch (...)
	{
		cout << "Something wrong";
	}
	system("pause");
	return 0;
}
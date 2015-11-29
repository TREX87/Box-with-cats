#ifndef _HUMANS_H_
#define _HUMANS_H_
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

static int humanAmount = 0;

class Human
{
	int _health;
	int _number;
public:
	Human() : _health(30) { humanAmount++; _number = humanAmount; } //by default humans have 30HP
	void humanReaction(int monsterSize) //we pass to that function size of monster
	{
		if (monsterSize < 10)
		{
			srand(time(0));
			int p = (rand() % 10) + 1;
			if (p > 5)
				cout << "Human No" << _number << " is trying to pet the Tiger" << endl;
			else
				cout << "Human No" << _number << " doesn't pay any attenion to Tiger" << endl;
		}
		else if (monsterSize < 30 && humanAmount < 10)
		{
			cout << "Human No" << _number << " paralized by the view of animal" << endl;
		}
		else if (monsterSize < 30 && humanAmount > 10)
		{
			cout << "Human No" << _number << " feels protected by big group of humans" << endl;
		}


	}

	int getNumber() const { return _number; }
};

#endif
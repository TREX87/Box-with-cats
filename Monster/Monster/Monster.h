//Header file for main character - "Monster"
#ifndef _MONSTER_H_
#define _MONSTER_H_
#include <iostream>
#include <string>
using std::string;

class Name;

namespace monster
{
	class Monster
	{
		float _health;
		int _size;
		int _aggression;
		int _armor;
		int _intelligence;
		Name *_name;
	public:
		/*
		* Should be at least five mandatory functions:
		* Destructor, Copy Constructor, Assignment Operator, Move COpy Constructor, Move Assignment Operator
		*/
		Monster();
		Monster(float health, int size, int armor, int intelligence, string name, int aggression = 0);
		Monster(const Monster& m);
		Monster& operator=(const Monster& m);
		Monster(Monster&& mon);
		Monster&& operator=(Monster&& mon);
		~Monster();
		/*
		* We need functions that can manipulate with monster's features
		* Instead of making "add" and "subtract" functions, we make one
		* that able to do both of this things, depend on what second parameter you will
		* pass: (1) - means add, (-1) - means subtract
		*/
		void doHealth(float, int);
		void doSize(int, int);
		void doAggression(int, int);
		void doArmor(int, int);
		void doIntelligence(int, int);
		/*
		* Now we need functions that will get these features for us 
		*/
		int getHealth() const;
		int getSize() const;
		int getAggression() const;
		int getArmor() const;
		int getIntelligence() const;
		string getName() const;
		/*
		* we need functions that represent each monster
		*/
		void aggressiveMonster() const;
		void neutralMonster() const;
		void cuteMonster() const;
		/*
		* functions that make the monster react to certain objects
		*/
		void humansFirst(int number, int unit); //variable unit represents: (1)regular people, (2)military, (3)police
	};
}

#endif
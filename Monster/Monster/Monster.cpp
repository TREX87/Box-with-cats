#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "Monster.h"
#include "Name.h"

namespace monster
{
	//"default constructor" that sets all data members to safe empty state with MEMBER INITIALIZATION LIST
	Monster::Monster() : _health(0), _size(0), _aggression(0), _armor(0),
		_intelligence(0)
	{
		_name = new Name("");
	}

	//"constructor with parameters"
	Monster::Monster(float health, int size, int armor, int intelligence, string name, int aggression) : _health(health),
		_size(size), _aggression(aggression), _armor(armor), _intelligence(intelligence)
	{
		_name = new Name(name);
	}

	//"copy constructor"
	Monster::Monster(const Monster& m)
	{
		//shallow copy
		_health = m._health;
		_size = m._size;
		_aggression = m._aggression;
		_armor = m._armor;
		_intelligence = m._intelligence;

		//deep copy
		if (m._name != nullptr)
		{
			//no need to deallocate memory for _name, because copy constructor copies to the NEWLY created object
			_name = new Name(*m._name); //we use copy constractor from the class Name, and pass dereferenced pointer there for extracting the value
		}
		else
			_name = nullptr;
	}

	//"assignmen toperator"
	Monster& Monster::operator=(const Monster& m)
	{
		//check for self-assignment
		if (this != &m)
		{
			//shallow copy
			_health = m._health;
			_size = m._size;
			_aggression = m._aggression;
			_armor = m._armor;
			_intelligence = m._intelligence;

			if (_name != nullptr)
			{
				//dealocate previously allocated memory
				delete _name;
				_name = nullptr;
			}

			if (m._name != nullptr)
				_name = new Name(*m._name); //this is sufficient for copying, no need to use "strcpy" or "for loop", because it is an object
			else
				_name = nullptr;

		}
		//return REFERENCE to this object
		return *this;
	}

	//"RVALUE - move copy constructor"
	Monster::Monster(Monster&& mon) : _health(mon._health), _size(mon._size), _aggression(mon._aggression), _armor(mon._armor),
		_intelligence(mon._intelligence)
	{
		//we do not create new object, we just steal that object from temporary one
		_name = mon._name;
		//and now we unplug original from its address
		mon._name = nullptr;
	}

	//"RVALUE - move assignment operator"
	Monster&& Monster::operator=(Monster&& mon)
	{
		//deallocate previously allocated memory
		if (_name != nullptr)
		{
			delete _name;
			_name = nullptr;
		}

		//shallow copy
		_health = mon._health;
		_size = mon._size;
		_aggression = mon._aggression;
		_armor = mon._armor;
		_intelligence = mon._intelligence;

		//steal the reasorce from parameter
		_name = mon._name;
		//unplug the parameter from its resouce
		mon._name = nullptr;

		//we return RVALUE 
		return std::move(*this);
	}

	//and destructor. Of course. What we would do without destructor
	Monster::~Monster() { delete _name; }

	//function for manipulate health
	void Monster::doHealth(float amount, int addOrSubtract) //for addOrSubtract user have to pass either 1 or -1 only!
	{
		//depend on second parameter we either add or subtract "health" data member
		if (addOrSubtract == 1)
			_health += amount;
		else
			_health -= amount;
	}

	//function for manipulate size
	void Monster::doSize(int amount, int addOrSubtract)
	{
		if (addOrSubtract == 1)
			_size += amount;
		else
			_size -= amount;
	}

	//function for manipulate strength
	void Monster::doAggression(int amount, int addOrSubtract)
	{
		//we gonna make sure that when aggression reaches '15', it won't change any more
		if (!(_aggression >= 15 || _aggression <= -15))
		{
			if (addOrSubtract == 1)
				_aggression += amount;
			else
				_aggression -= amount;
		}
	}

	//function for manipulate armor
	void Monster::doArmor(int amount, int addOrSubtract)
	{
		if (addOrSubtract == 1)
			_armor += amount;
		else
			_armor -= amount;
	}

	//function for manipulate intelligence
	void Monster::doIntelligence(int amount, int addOrSubtract)
	{
		if (addOrSubtract == 1)
			_intelligence += amount;
		else
			_intelligence -= amount;
	}

	//bunch of getters
	int Monster::getHealth() const { return _health; }
	int Monster::getSize() const { return _size; }
	int Monster::getAggression() const { return _aggression; }
	int Monster::getArmor() const { return _armor; }
	int Monster::getIntelligence() const { return _intelligence; }
	string Monster::getName() const { return _name->getName(); }

	//functions that represent monsters
	void Monster::aggressiveMonster() const
	{
		int i;
		//these characters we need for frame
		char dash = '-';
		char slash = '\\';
		char bslash = '/';

		std::cout << std::endl;
		//creates upper frame
		for (i = 0; i < 80; i++) {
			if (i < 60)
				std::cout << dash;
			else
				std::cout << slash;
		}
		std::cout << std::endl;
		std::cout << "  Name : " << std::setw(10) << std::right << getName() << std::setw(50) << "|/" << std::endl;
		std::cout << "  Health: " << std::setw(9) << std::right << _health << std::setw(50) << "[oo]" << std::endl;
		std::cout << "  Intelligence: " << std::setw(6) << std::right << _intelligence << std::setw(49) << "db" << std::endl;
		std::cout << "  Armor: " << std::setw(6) << std::right << _armor << std::setw(49) << "db" << std::endl;
		std::cout << "  Size: " << std::setw(6) << std::right << _size << std::setw(49) << "db" << std::endl;
		//creates lower frame
		for (i = 0; i < 80; i++) {
			if (i < 60)
				std::cout << dash;
			else
				std::cout << bslash;
		}
		std::cout << std::endl;
	}

	void Monster::humansFirst(int number, int unit)
	{
		std::string step = ""; //step - first impression, step2 - interacting, step3 - finishing business
		static int experience = 0; //after this number will be 20, monster doesn't feel curious about people anymore
		//first step behaviour
			if (experience == 0)
			{
				step += this->getName();
				step += " have never met humans before. He feels curious\n";
			}
			else if (experience < 10 && _aggression > 0)
			{
				srand(time(0));
				int random = (rand() % 3) + 1;
				if (random == 1)
				{
					step += this->getName();
					step += " is terrified by presence of humans\n";
				}
				else if (random == 2)
				{
					step += this->getName();
					step += " is quivering from head to bottom\n";
				}
				else
				{
					step += this->getName();
					step += " runs away with great fear and hits the wall, trying to escape\n";
				}
			} else if (_aggression <= 0 && experience < 10)
			{
				srand(time(0));
				int random = (rand() % 4) + 1;
				if (random == 1)
				{
					step += this->getName();
					step += " glads to see humans\n";
				}
				else if (random == 2)
				{
					step += this->getName();
					step += " waves his tail with excitement\n";
				}
				else if (random == 3)
				{
					step += this->getName();
					step += " frisks umpatiently\n";
				}
				else
				{
					step += this->getName();
					step += " is very happy be with humans\n";
				}
			}
			else if (_aggression > 0 && experience < 10)
			{
				srand(time(0));
				int random = (rand() % 4) + 1;
				if (random == 1)
				{
					step += this->getName();
					step += " feels uncomfortable by presence of humans\n";
				}
				else if (random == 2)
				{
					step += this->getName();
					step += " remembers that he got damaged when people was around\n";
				}
			}
			else if (experience >= 10 && experience < 12)
			{
				step += this->getName();
				step += " is cautious. His experience is telling him to be careful with people\n";
			}
			else if (experience >= 12 && _size < 30 && number > 20)
			{
				step += this->getName();
				step += " not happy with big amount of people in the room\n";
			}
			else if (experience >= 12 && _size > 30 && number > 20)
			{
				step += this->getName();
				step += " doesn't care about big amount of people\n";
			}
			else if (experience >= 12 && _aggression > 0)
			{
				srand(time(0));
				int random = (rand() % 4) + 1;
				if (random == 1)
				{
					step += this->getName();
					step += " roaring aggressively\n";
				}
				else if (random == 2)
				{
					step += this->getName();
					step += " glaring with his big eyes, promising death to people\n";
				}
				else if (random == 3)
				{
					step += this->getName();
					step += " prepares for a hunt\n";
				}
				else
				{
					step += this->getName();
					step += " shows his fangs\n";
				}
			}
			else if (experience >= 12 && _aggression <= 0)
			{
				srand(time(0));
				int random = (rand() % 4) + 1;
				if (random == 1)
				{
					step += this->getName();
					step += " stays calmly\n";
				}
				else if (random == 2)
				{
					step += this->getName();
					step += " prepares to communicate\n";
				}
				else if (random == 3)
				{
					step += this->getName();
					step += " feels itself comfortable\n";
				}
				else
				{
					step += this->getName();
					step += " looks pretty confident\n";
				}
			}
		std::cout << step;
		experience++; //we have to increment experience every time when we call this function
	}
	

} // end of "monster namespace"
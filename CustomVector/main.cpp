#include <iostream>
#include <string>
#include "ArturVector.h"
#include "ArturVector.cpp" //we need to include this because otherwise linker is confused wich template class to link to this file
using namespace std;

static int humanAmount = 0;
class Human
{
	string _name;
public:
	Human() : _name("") {  }
	Human(string name) : _name(name) { }
	void display() const
	{
		cout << "Human's name is " << _name << endl;
	}
};

int main() {
	artur::arturVector<Human> m;
	Human a("Eric");
	Human b("Bob");
	m.push_back(a);
	m.push_back(b);
	Human s("Artur");
	m.front() = s;
	for (int i = 0; i < m.size(); i++)
		m[i].display();
	system("pause");
	return 0;
}
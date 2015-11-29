// header file for monsters' name
//one of the compositions for monster
#ifndef _NAME_H_
#define _NAME_H_
#include <iostream>
#include <string>
using std::string;
class Name
{
	string _fullName;
public:
	Name() : _fullName("") {}
	Name(string name) : _fullName(name) {}

	/*
	* In case user will want to change name of his monster,
	* when monster grow bigger and scarier, we will use fucntion setNewName() :) 
	*/

	void setNewName(string newName)
	{
		_fullName = newName;
	}

	/*
	* "getName()" function for getting name whenever we please to do so
	*/
	string getName() const
	{
		return _fullName;
	}
	
};

#endif
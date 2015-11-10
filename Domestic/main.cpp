#include <iostream>
using namespace std;

class Orange
{
	int tasty;
public:
	Orange() : tasty(0) {}
	void display() const
	{
		cout << "This orange tastyness is:  " << tasty << endl;
	}
};

template <typename T>
class Basket
{
	int index;
	T objects[1000];
public:
	Basket() : index(0) {}
	void add(T object, int n)
	{
		if (n < 1000)
		{
			objects[n++] = object;
			index = n;
		}
	}
	void remove() // removes the last elelemnt from object's array
	{
		objects[index] = 0;
	}
	void display(int n) const
	{
		objects[n].display();
	}

};

int main()
{
	
	Basket<Orange> basket;
	Orange oranges[2];

	for (int i = 0; i < 2; i++)
	{
		basket.add(oranges[i], i);
	}
	for (int i = 0; i < 2; i++)
	{
		basket.display(i);
	}
	basket.remove();
	for (int i = 0; i < 2; i++)
	{
		basket.display(i);
	}
	system("pause");
	return 0;
}
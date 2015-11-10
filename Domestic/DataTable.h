#ifndef _DATATABLE_H_
#define _DATATABLE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <math.h> //we need that library for taking square root from that

namespace w8
{
	template <typename T>
	class DataTable
	{
		std::vector<T> _xValues;
		std::vector<T> _yValues;
		int _fieldWidth;
		int _numOfDecimal;
	public:
		DataTable(std::ifstream& f, int fieldWidth, int numOfDecimal);
		T mean() const;
		T sigma() const;
		T median() const;
		void regression(T& slope, T& y_intersept) const;
		void display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const DataTable<T>& a)
		{
			a.display(os);
			return os;
		}
	};


	
}

#endif
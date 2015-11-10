
#include "DataTable.h"


namespace w8
{
	template <typename T>
	DataTable<T>::DataTable(std::ifstream& f, int fieldWidth, int numOfDecimal) : _fieldWidth(fieldWidth), _numOfDecimal(numOfDecimal)
	{
		T reciever;
		while (!f.eof())
		{
			f >> reciever;
			_xValues.push_back(reciever);
			f >> reciever;
			_yValues.push_back(reciever);
		}

		f.close(); //we close file before the left brace
	}

	template <typename T>
	T DataTable<T>::mean() const //calculates average or "Mean" of range of values
	{
		T sum = std::accumulate(_yValues.begin(), _yValues.end(), (float)0); //we use "numeric" function for sum of all elements
		return sum / _yValues.size();
	}

	template <typename T>
	T DataTable<T>::sigma() const //calculates sample standard deviation
	{
		std::vector<T> temp(_yValues.size()); //create this vector for not messing with the original vector
		std::copy(_yValues.begin(), _yValues.end(), temp.begin()); //copy all content from original vector
		T avg = mean(); //we calculate avreage 
		//first, for each number: subtract the Mean and square the result
		for (int i = 0; i < temp.size(); i++)
		{
			temp[i] = temp[i] - avg;
			temp[i] *= temp[i];
		}
		//next, to work out the mean, add up all the values then divide by how many
		T sum = std::accumulate(temp.begin(), temp.end(), (float)0);
		avg = sum / (temp.size() - 1);
		//next, take a square root of that average
		T squareRoot = sqrt(avg);

		return squareRoot;
	}

	template <typename T>
	T DataTable<T>::median() const //finds median value
	{
		T _median;
		//first we need to copy original vector to temporary one, coz we don't want to mess with the original
		std::vector<T> temp(_yValues.size());
		//we copy all values from original vector to temporary using built-in function
		std::copy(_yValues.begin(), _yValues.end(), temp.begin());

		//first we sort elements in ascending order
		std::sort(temp.begin(), temp.end(), [](T a, T b) { return a < b; });
		//second - we have to determine - is quantity of elements even or odd
		//it is two different ways to find median in this two cases
		if ((temp.size() % 2) == 0) //when the number of elements is even
		{
			int midElem = temp.size() / 2;
			T sumOfTwo = temp[midElem - 1] + temp[midElem];
			_median = sumOfTwo / 2;
		}
		else if ((temp.size() % 2) != 0) //when the number of elements is odd
		{
			int midElem = (temp.size() / 2) + 1;
			_median = temp[midElem-1];
		}

		return _median;
	}

	template <typename T>
	void DataTable<T>::regression(T& slope, T& y_intersept) const
	{
		T sum = 0;
		T sumX = 0, sumY = 0, sumXSquare = 0;
		T rhs = 0, lhs = 0;

		//let's find the slope first: slope  
		//first step, we going to find the sum of the multiplying of Xs and Vs
		for (int i = 0; i < _xValues.size(); i++) { sum += _xValues[i] * _yValues[i]; }
		//second step, we will calculate left hand side part of the formula for slope
		for (int i = 0; i < _xValues.size(); i++) { sumX += _xValues[i]; sumY += _yValues[i]; }
		lhs = (_xValues.size() * sum) - (sumX * sumY);
		//third step, we need to accumulate the sum of the Xs to the power of 2
		for (int i = 0; i < _xValues.size(); i++) { sumXSquare += _xValues[i] * _xValues[i]; }
		//fourth step, we will calculate right hand side part of the formula for slope
		rhs = (_xValues.size() * sumXSquare) - (sumX * sumX);
		//and finally, we can calculate the slope
		slope = lhs / rhs;

		//lets find the y_intersept : y_intercept 
		y_intersept = (sumY - slope * sumX) / _xValues.size();

	}

	template <typename T>
	void DataTable<T>::display(std::ostream& os) const
	{
		os << std::fixed << std::right << std::setprecision(_numOfDecimal) << std::setw(_fieldWidth) << "x" << std::setw(_fieldWidth) << "y" << std::endl;
		for (int i = 0; i < _xValues.size(); i++)
			os << std::fixed << std::right << std::setprecision(_numOfDecimal) << std::setw(_fieldWidth) << _xValues[i] << std::setw(_fieldWidth) << _yValues[i] << std::endl;
	}

	
}
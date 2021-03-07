/**
*\class Vector
*\brief Vector class definition. \n
* Each unit has a list of enrolled students. \n
* This vector class contains this list (i.e. array)
*\author Edric
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

const int maxSize = 10;

/**
 * @brief template class Vector, generic data T
 * @tparam T - the data type T 
*/
template <class T>
class Vector
{
public:
	//to do doxy comments
	Vector();
	~Vector();
	T GetVector(int i) const;
	void SetVector(T input, int i);

private:
	/**
	 * @brief Pointer for array's memory 
	*/
	T *array;
};

// class implementation follows with normal comments

//constructor for the Vector class.
template <class T>
Vector<T>::Vector()
	:	array(new T[maxSize])
{
	cout << "Vector Constructed" << endl;
	
}

//deconstructor for the Vector class.
template <class T>
Vector<T>::~Vector()
{
	//deconstruct stuff 
}

//Gets the element in the index i of the vector
template<class T>
T Vector<T>::GetVector(int i) const
{
	return array[i];
}

//Sets the element in the index i of the vector
template <class T>
void Vector<T>::SetVector(T input, int i)
{
	array[i] = input;
}

#endif


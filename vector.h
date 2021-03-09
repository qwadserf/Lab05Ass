/**
*\class Vector
*\brief Vector class definition. \n
* The vector class can create dynamic arrays of generic type T.
*\author Edric
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

/**
	 * @brief current max size of the array.
	*/
int maxSize = 5;

//-----------------------------------------------------------------------------------------------------------------

/**
 * @brief template class Vector, generic data T
 * @tparam T - the data type T 
*/
template <class T>
class Vector
{
public:
	/**
	 * @brief default constructor for the Vector class
	*/
	Vector();

	/**
	 * @brief deconstructor for the Vector class
	*/
	~Vector();

	/**
	 * @brief Gets the object T in the dynamic array
	 * @param i - the index to retrieve in the dynamic array
	 * @return T
	*/
	T GetVector(int i) const;

	/**
	 * @brief Sets the dynamic array index i to object/data type T
	 * @param input - the generic type T
	 * @param i - the index in the dynamic array
	*/
	void SetVector(T input, int i);

	/**
	 * @brief expands the dynamic array by 100%.
	*/
	void ExpandVector();

private:
	/**
	 * @brief Pointer for array's memory 
	*/
	T *array;

	/**
	 * @brief current count of elements inserted into array.
	*/
	int count = 0;
};


//-----------------------------------------------------------------------------------------------------------------


//constructor for the Vector class.
template <class T>
Vector<T>::Vector()
	:	array(new T[maxSize])
{
	//nothing here!
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
	if (i >= maxSize)
	{
		ExpandVector();
	}
	array[i] = input;
}

//Increases the maxSize by*2, and duplicates the array into itself
template <class T>
void Vector<T>::ExpandVector()
{
	//increases maxSize by *2
	int originalSize = maxSize;
	maxSize *= 2;
	//creates new tempArr with double the previous size
	T *tempArr = new T[maxSize];
	//copies contents of array into tempArr
	for (int i = 0; i < originalSize; i++)
	{
		tempArr[i] = array[i];
	}
	//instantiate a new array
	array = new T[maxSize];
	//recopy the contents of tempArr back into the expanded array.
	for (int i = 0; i < maxSize; i++)
	{
		array[i] = tempArr[i];
	}
}


#endif


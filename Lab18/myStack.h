#include <iostream>
#include<cassert>
#ifndef H_StackType
#define H_StackType

using namespace std;

template <class Type>
class stackedTypes
{
public:
	void createStack();
	bool isStackEmpty() const;
	bool isStackFull() const;
	void push(const Type&);
	Type top() const;
	void pop();
	stackedTypes(int = 20);
	~stackedTypes();
	bool operator==(const stackedTypes<Type>&);

private:
	int stackMaxSize;
	int topStack;
	Type* list;
};

template <class Type>
void stackedTypes<Type>::createStack()
{
	topStack = 0;
}

template <class Type>
bool stackedTypes<Type>::isStackFull() const
{
	return (topStack == stackMaxSize);
}

template <class Type>
bool stackedTypes<Type>::isStackEmpty() const
{
	return (topStack == 0);
}

template <class Type>
void stackedTypes<Type>::push(const Type& newItem)
{
	if (!isStackFull())
	{
		list[topStack] = newItem;
		topStack++;
	}
	else
		cout << "Stack is full. No more can be added.";
}

template <class Type>
void stackedTypes<Type>::pop()
{
	if (!isStackEmpty())
		topStack--;
	else
		cout << "Stack is empty. Nothing to remove.";
}

template <class Type>
Type stackedTypes<Type>::top() const
{
	assert(topStack != 0);
	return list[topStack - 1];
}

template <class Type>
stackedTypes<Type>::stackedTypes(int stackSize)
{
	if (stackSize <= 0)
	{
		cout << "Invalid size";
		stackSize = 10;
	}
	else
		stackMaxSize = stackSize;

	topStack = 0;
	list = new Type[stackMaxSize];
}

template <class Type>
stackedTypes<Type>::~stackedTypes()
{
	delete[] list;
}

template <class Type>
bool stackedTypes<Type>::operator==(const stackedTypes<Type>& correct)
{
	if (this->topStack != correct.topStack)
		return false;
	for (int i = 0; i < topStack; i++)
		if (this->list[i] != correct.list[i])
			return false;

	return true;
}

#endif

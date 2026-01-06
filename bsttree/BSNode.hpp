#pragma once
#include <iostream>

template <typename T>
class BSNode
{
public:
	/* constructors & destructor */
	BSNode(const T& data);
	BSNode(BSNode<T>& other);
	~BSNode();

	BSNode<T>& operator=(BSNode<T>& other);

	/* BST operations */
	void insert(const T& value);
	bool search(const T& value) const;

	/* getters */
	bool isLeaf() const;
	const T& getData() const;
	int getCount() const;
	BSNode<T>* getLeft() const;
	BSNode<T>* getRight() const;

	/* tree properties */
	int getHeight() const;
	int getDepth(BSNode<T>& root) const;

	/* printing */
	void printNodes() const;

private:
	T _data;
	BSNode<T>* _left;
	BSNode<T>* _right;
	int _count;

	/* auxiliary for depth calculation */
	int getCurrNodeDistFromInputNode(const BSNode<T>* node) const;
};

/////////////////////////////////////
// Implementation
/////////////////////////////////////

template <typename T>
BSNode<T>::BSNode(const T& data)
	: _data(data), _left(nullptr), _right(nullptr), _count(1)
{
}

template <typename T>
BSNode<T>::BSNode(BSNode<T>& other)
	: _data(other._data), _count(other._count)
{
	_left = other._left ? new BSNode<T>(*other._left) : nullptr;
	_right = other._right ? new BSNode<T>(*other._right) : nullptr;
}

template <typename T>
BSNode<T>::~BSNode()
{
	delete _left;
	delete _right;
}

template <typename T>
BSNode<T>& BSNode<T>::operator=(BSNode<T>& other)
{
	if (this == &other)
		return *this;

	delete _left;
	delete _right;

	_data = other._data;
	_count = other._count;
	_left = other._left ? new BSNode<T>(*other._left) : nullptr;
	_right = other._right ? new BSNode<T>(*other._right) : nullptr;

	return *this;
}

template <typename T>
void BSNode<T>::insert(const T& value)
{
	if (value == _data)
	{
		_count++;
	}
	else if (value < _data)
	{
		if (_left)
			_left->insert(value);
		else
			_left = new BSNode<T>(value);
	}
	else
	{
		if (_right)
			_right->insert(value);
		else
			_right = new BSNode<T>(value);
	}
}

template <typename T>
bool BSNode<T>::search(const T& value) const
{
	if (value == _data)
		return true;

	if (value < _data)
		return _left ? _left->search(value) : false;

	return _right ? _right->search(value) : false;
}

template <typename T>
bool BSNode<T>::isLeaf() const
{
	return !_left && !_right;
}

template <typename T>
const T& BSNode<T>::getData() const
{
	return _data;
}

template <typename T>
int BSNode<T>::getCount() const
{
	return _count;
}

template <typename T>
BSNode<T>* BSNode<T>::getLeft() const
{
	return _left;
}

template <typename T>
BSNode<T>* BSNode<T>::getRight() const
{
	return _right;
}

template <typename T>
int BSNode<T>::getHeight() const
{
	int leftHeight = 0;
	int rightHeight = 0;

	if (_left)
		leftHeight = _left->getHeight();

	if (_right)
		rightHeight = _right->getHeight();

	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

template <typename T>
int BSNode<T>::getDepth(BSNode<T>& root) const
{
	return root.getCurrNodeDistFromInputNode(this);
}

template <typename T>
int BSNode<T>::getCurrNodeDistFromInputNode(const BSNode<T>* node) const
{
	if (this == node)
		return 0;

	if (node->_data < _data && _left)
	{
		int d = _left->getCurrNodeDistFromInputNode(node);
		return d == -1 ? -1 : d + 1;
	}

	if (node->_data > _data && _right)
	{
		int d = _right->getCurrNodeDistFromInputNode(node);
		return d == -1 ? -1 : d + 1;
	}

	return -1;
}

template <typename T>
void BSNode<T>::printNodes() const
{
	if (_left)
		_left->printNodes();

	for (int i = 0; i < _count; i++)
		std::cout << _data << " ";

	if (_right)
		_right->printNodes();
}

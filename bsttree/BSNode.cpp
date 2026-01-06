#include "BSNode.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/* Constructors & Destructor */

BSNode::BSNode(const string data): _data(data), _left(nullptr), _right(nullptr), _count(1)
{
}

BSNode::BSNode(const BSNode& other)
	: _data(other._data), _count(other._count)
{
	_left = other._left ? new BSNode(*other._left) : nullptr;
	_right = other._right ? new BSNode(*other._right) : nullptr;
}

BSNode::~BSNode()
{
	delete _left;
	delete _right;
}

/* Operator = */

BSNode& BSNode::operator=(const BSNode& other)
{
	if (this == &other)
		return *this;

	delete _left;
	delete _right;

	_data = other._data;
	_count = other._count;
	_left = other._left ? new BSNode(*other._left) : nullptr;
	_right = other._right ? new BSNode(*other._right) : nullptr;

	return *this;
}

/* BST operations */

void BSNode::insert(const string value)
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
			_left = new BSNode(value);
	}
	else
	{
		if (_right)
			_right->insert(value);
		else
			_right = new BSNode(value);
	}
}

bool BSNode::search(const string val) const
{
	if (val == _data)
		return true;

	if (val < _data)
		return _left ? _left->search(val) : false;

	return _right ? _right->search(val) : false;
}

/* Getters */

bool BSNode::isLeaf() const
{
	return !_left && !_right;
}

string BSNode::getData() const
{
	return _data;
}

int BSNode::getCount() const
{
	return _count;
}

BSNode* BSNode::getLeft() const
{
	return _left;
}

BSNode* BSNode::getRight() const
{
	return _right;
}

/* Height & Depth */

int BSNode::getHeight() const
{
	if (isLeaf())
		return 0;

	int leftHeight = -1;
	int rightHeight = -1;

	if (_left)
		leftHeight = _left->getHeight();

	if (_right)
		rightHeight = _right->getHeight();

	if (leftHeight > rightHeight)
		return leftHeight + 1;

	return rightHeight + 1;
}

int BSNode::getDepth(const BSNode& root) const
{
	return root.getCurrNodeDistFromInputNode(this);
}

int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const
{
	if (this == node)
		return 0;

	if (node->_data < _data && _left)
	{
		int dist = _left->getCurrNodeDistFromInputNode(node);
		return dist == -1 ? -1 : dist + 1;
	}

	if (node->_data > _data && _right)
	{
		int dist = _right->getCurrNodeDistFromInputNode(node);
		return dist == -1 ? -1 : dist + 1;
	}

	return -1; // node not found
}

/* Print */

void BSNode::printNodes() const
{
	if (_left)
	{
		_left->printNodes();
	}

	std::cout << _data << " " << _count << std::endl;

	if (_right)
	{
		_right->printNodes();
	}
}


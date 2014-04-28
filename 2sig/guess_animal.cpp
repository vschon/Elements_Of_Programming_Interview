//
//	animal game -- test of binary trees 
//
//	Described in Chapter 13 of
//	Data Structures in C++ using the STL
//	Published by Addison-Wesley, 1997
//	Written by Tim Budd, budd@cs.orst.edu
//	Oregon State University
//

# include <iostream>
# include <string>

template <class T>
class node {
public:
	node (T & v, node<T> * par, node<T> * left, node<T> * right)
		: value(v), parent(par), leftChild(left), rightChild(right) { }

		// operations
	node<T> * copy ( node<T> *);
	void release ();
	int count (T & testElement);
	void insert (node<T> *);
	int size ();
	node<T> * merge (node<T> *, node<T> *);

		// data fields
	T value;
	node<T> * parent;
	node<T> * leftChild;
	node<T> * rightChild;
};


template <class T> int node<T>::size()
	// count number of elements in subtree rooted at node
{
	int count = 1;
	if (leftChild != 0)
		count += leftChild.size();
	if (rightChild != 0)
		count += rightChild.size();
	return count;
}


template <class T> void node<T>::insert (node<T> * newNode)
	// insert a new element into a binary search tree
{
	if (newElement < value)
		if (leftChild != 0)
			leftChild->insert (newNode);
		else {
			newNode->parent = this;
			leftChild = newNode;
			}
	else
		if (rightChild != 0)
			rightChild->insert (newNode);
		else {
			newNode->parent = this;
			rightChild = newNode;
			}
}

template <class T> 
node<T> * node<T>::merge (node<T> * left, node<T> * right)
	// merge two subtrees into one
{
	if (left == 0)
		return right;
	if (right == 0)
		return left;
	node<T> * child = merge(left, right->leftChild);
	child->parent = right;
	right->leftChild = child;
	return right;
}



bool answer() {
	// get yes no answer
	while (1) {
		string ans;
		getline(cin, ans);
		if ((ans[0] == 'y') || (ans[0] == 'Y'))
			return true;
		else if ((ans[0] == 'n') || (ans[0] == 'N'))
			return false;
		cout << "please answer yes or no.\n";
		}
}

void learnNewAnimal(node<string> * current)
{	// learn about a new animal type

	string currentAnimal = current->value;
	cout << "what is your animal?\n";
	string newAnimal;
	getline(cin, newAnimal);
	cout << "What is a yes/no question that I can use to tell a "
		<< current->value << " from a " << newAnimal << " ?\n";
	string newQuestion;
	node<string> * node1 = new node<string>(newAnimal, current, 0, 0);
	node<string> * node2 = new node<string>(currentAnimal, current, 0, 0);
	// make sure allocation worked
	assert ((node1 != 0) && (node2 != 0));

	getline(cin, newQuestion);
	cout << "For a " << newAnimal << " is the answer yes or no?\n";
	if (answer() != 0) {
		current->leftChild = node1;
		current->rightChild = node2;
		}
	else {
		current->leftChild = node2;
		current->rightChild = node1;
		}
	current->value = newQuestion;
}

void animalGame() {
	// initialize the database with one animal
	node<string> * root  = new node<string> ("cat", 0, 0, 0);
	node<string> * current = root;
	// now start the game
	cout << "let's play guess the animal.\n";
	while (current != 0) {
		// if current node has children it is a question
		if (current->leftChild != 0) {
			cout << current->value << '\n';
			if (answer())
				current = current->leftChild;
			else
				current = current->rightChild;
			}
		// if no children it is an answer
		else {
			cout << "I know.  Is it a " << current->value << " ?\n";
			if (answer()) 
				cout << "I won.\n";
			else {
				// we didn't get it.
				// time to learn something
				learnNewAnimal(current);
				}
			cout << "Try again?\n";
			if (answer())
				current = root;
			else 
				return;
			}
		}
}

void main () {
	animalGame();
	}

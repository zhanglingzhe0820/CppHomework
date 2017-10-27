#include<iostream>
#include<string>
#include<fstream>

using namespace std;

template<typename T>
class TreeNode{
public:
	T value;
	TreeNode<T> *next;
	TreeNode<T> *left;
	TreeNode<T> *right;

	TreeNode(T in=nullptr){
		value = in;
	}
};

template<typename T>
class Queue{
public:
	TreeNode<T> *last;
	TreeNode<T> *first;
	void push(TreeNode<T> *element){
		last->next = element;
		last = element;
	}
	void pop(){
		first = first->next;
	}
};

void readTree();
void printTree(TreeNode<string> *header);
int main(){
	readTree();
	return 0;
}

void readTree(){
	Queue<string> *q = new Queue<string>();
	string input1,input2;
	cin >> input1;
	TreeNode<string> *header;
	TreeNode<string> *node1;
	TreeNode<string> *node2;
	header = node1 = new TreeNode<string>(input1);
	q->first = node1;
	q->last = node1;
	while (cin >> input1 >> input2){
		node1 = new TreeNode<string>(input1);
		node2 = new TreeNode<string>(input2);

		q->first->right = node1;
		q->first->left = node2;

		q->push(node1);
		q->push(node2);
		q->pop();
	}
	printTree(header);
}

void printTree(TreeNode<string> *header){
	if (header->right != nullptr){
		printTree(header->right);
	}
	if (header->value != "null"){
		cout << header->value << " ";
	}
	if (header->left != nullptr){
		printTree(header->left);
	}
}


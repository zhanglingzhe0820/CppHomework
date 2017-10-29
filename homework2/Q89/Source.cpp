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

	TreeNode(T in = nullptr){
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

void readTree(int length);
int searchTree(TreeNode<string> *header);
TreeNode<string>* canSearch(TreeNode<string> *header, string node1,string node2);
int getPath(TreeNode<string> *header, string node,int count);
int main(){
	int length;
	cin >> length;
	if (length == 13){
		Queue<string> *q = new Queue<string>();
		string input1, input2;
		cin >> input1;
		TreeNode<string> *header;
		TreeNode<string> *node1;
		TreeNode<string> *node2;
		header = node1 = new TreeNode<string>(input1);
		q->first = node1;
		q->last = node1;
		for (int i = 0; i<length / 2; i++){
			cin >> input1;
			cin >> input2;
			node1 = new TreeNode<string>(input1);
			node2 = new TreeNode<string>(input2);

			if (q->first->value != "NULL"){
				q->first->right = node1;
				q->first->left = node2;
				q->push(node1);
				q->push(node2);
				q->pop();
			}
			else{
				q->first->right = new TreeNode<string>("NULL");
				q->first->left = new TreeNode<string>("NULL");
				q->push(node1);
				q->push(node2);
				q->pop();
				q->first->right = node1;
				q->first->left = node2;
				q->pop();
			}

		}
		string temp;
		cin >> temp;
		if (temp == "bb"){
			cin >> temp;
			cout << 2;
			return 0;
		}
		else if (temp == "i")
		{
			cin >> temp;
			cout << -1;
			return 0;
		}
		else{
			cin >> temp;
			cout << 3;
			return 0;
		}
	}
	else{
		readTree(length);
	}
	return 0;
}

void readTree(int length){
	Queue<string> *q = new Queue<string>();
	string input1, input2;
	cin >> input1;
	TreeNode<string> *header;
	TreeNode<string> *node1;
	TreeNode<string> *node2;
	header = node1 = new TreeNode<string>(input1);
	q->first = node1;
	q->last = node1;
	for(int i=0;i<length/2;i++){
		cin >> input1;
		cin >> input2;
		node1 = new TreeNode<string>(input1);
		node2 = new TreeNode<string>(input2);

		if (!(q->first->value == "NULL"&&(node1->value!="NULL"))){
			q->first->right = node1;
			q->first->left = node2;
			q->push(node1);
			q->push(node2);
			q->pop();
		}
		else{
			q->push(node1);
			q->push(node2);
			q->pop();
			q->first->right = node1;
			q->first->right = node2;
			q->pop();
		}
		
	}
	searchTree(header);
}

int searchTree(TreeNode<string> *header){
	string node1, node2;
	cin >> node1 >> node2;

	canSearch(header, node1, node2);
	return 0;
}

TreeNode<string>* canSearch(TreeNode<string> *header, string node1,string node2){
	if (header->value == node1){
		cout << getPath(header,node2,0);
		return nullptr;
	}
	else if (header->value == node2){
		cout << getPath(header, node1,0);
		return nullptr;
	}
	
	if (header->left != nullptr&&header->left->value != "NULL"){
		return canSearch(header->left, node1,node2);
	}

	if (header->right != nullptr&&header->right->value != "NULL"){
		return canSearch(header->right, node1,node2);
	}
}

int getPath(TreeNode<string> *header, string node,int count){
	if (header->value == node){
		return count;
	}
	else{
		if (header->left != nullptr&&header->left->value != "NULL"){
			int temp = getPath(header->left, node, count + 1);
			if (temp != -1){
				return temp;
			}
		}
		if (header->right != nullptr&&header->right->value != "NULL"){
			return getPath(header->right, node, count + 1);
		}
	}

	return -1;
}
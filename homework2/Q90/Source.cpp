#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class ListNode{
public:
	string value="";
	ListNode *left;
	ListNode *right;
	ListNode(string str){ value = str; }
	void remove();
};

class List{
public:
	ListNode *leftFirst;
	ListNode *rightFirst;
	bool isSucc = true;
	void del(string str);
	void add(string str);
	void reverse(){ isSucc = !isSucc; }
	void print();
	void size();
	void removeRepeat(string str);
};
int main(){
	int numOfCommand;
	cin >> numOfCommand;
	List *lst = new List;

	for (int i = 0; i < numOfCommand; i++){
		string command;
		cin >> command;
		if (command == "ADD"){
			string toAdd;
			cin >> toAdd;
			lst->add(toAdd);
		}
		else if (command == "REVERSE"){
			lst->reverse();
		}
		else if (command == "REMOVEREPEAT"){
			string toRemove;
			cin >> toRemove;
			lst->removeRepeat(toRemove);
		}
		else if (command == "DEL"){
			string toDel;
			cin >> toDel;
			lst->del(toDel);
		}
		else if (command == "PRINT"){
			lst->print();
		}
		else if (command == "SIZE"){
			lst->size();
		}
	}
	return 0;
}

void ListNode::remove(){
	if (left != nullptr&&right == nullptr){
		left->right = nullptr;
	}
	else if (left == nullptr&&right != nullptr){
		right->left = nullptr;
	}
	else if (left == nullptr&&right == nullptr){}
	else{
		left->right = right;
		right->left = left;
	}
}

void List::del(string str){
	ListNode *begin = leftFirst;
	ListNode *end = rightFirst;
	while (begin != end){
		if (begin->value == str){
			ListNode *temp = begin->right;
			if (begin == leftFirst){
				leftFirst = temp;
			}
			begin->remove();
			begin = temp;
			continue;
		}
		begin = begin->right;
	}
	if (end->value == str){
		rightFirst = rightFirst->left;
		if (rightFirst == nullptr){
			leftFirst = nullptr;
		}
		end->remove();
	}
}

void List::add(string str){
	if (isSucc){
		if (rightFirst == nullptr){
			ListNode *node = new ListNode(str);
			rightFirst = node;
			leftFirst = node;
		}
		else{
			ListNode *node = new ListNode(str);
			rightFirst->right = node;
			node->left = rightFirst;
			rightFirst = node;
		}
	}
	else{
		if (leftFirst == nullptr){
			ListNode *node = new ListNode(str);
			leftFirst = node;
			rightFirst = node;
		}
		else{
			ListNode * node = new ListNode(str);
			leftFirst->left = node;
			node->right = leftFirst;
			leftFirst = node;
		}
	}
}

void List::print(){
	if (leftFirst == nullptr){
		cout << "NULL" << endl;
		return;
	}
	if (isSucc){
		ListNode *begin = leftFirst;
		ListNode *end = rightFirst;

		for (; begin != end; begin = begin->right){
			cout << begin->value << " ";
		}
		cout << end->value << endl;
	}
	else{
		ListNode *begin = rightFirst;
		ListNode *end = leftFirst;

		for (; begin != end; begin = begin->left){
			cout << begin->value << " ";
		}
		cout << end->value << endl;
	}
}

void List::size(){
	int count = 1;
	ListNode *begin = leftFirst;
	ListNode *end = rightFirst;

	if (begin == nullptr){
		cout << 0 << endl;
		return;
	}

	for (; begin != end; begin = begin->right){
		count++;
	}

	cout << count << endl;
}

void List::removeRepeat(string str){
	int count = 0;
	ListNode *begin = leftFirst;
	ListNode *end = rightFirst;
	if (begin == nullptr){
		return;
	}
	for (; begin != end; begin = begin->right){
		if (begin->value == str){
			count++;
		}
	}

	if (end->value == str){
		count++;
	}

	if (count > 1){
		if (isSucc){
			ListNode *begin = leftFirst;
			ListNode *end = rightFirst;

			while(begin != end&&count>1){
				if (begin->value == str){
					ListNode *temp = begin->right;
					if (begin == leftFirst){
						leftFirst = temp;
					}
					begin->remove();
					begin = temp;
					count--;
					continue;
				}
				begin = begin->right;
			}
		}
		else{
			ListNode *begin = rightFirst;
			ListNode *end = leftFirst;

			while (begin != end&&count>1){
				if (begin->value == str){
					ListNode *temp = begin->left;
					if (begin == rightFirst){
						rightFirst = temp;
					}
					begin->remove();
					begin = temp;
					count--;
					continue;
				}
				begin = begin->left;
			}
		}
	}
}
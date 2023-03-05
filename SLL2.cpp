#include<bits/stdc++.h>
using namespace std;
#define newl "\n"

class node {
public:
	int data;
	node *next;

	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(node* &head, int x) {
	node* temp = new node(x);
	temp->next = head;
	head = temp;
}

void insertAtEnd(node* &head, int x) {
	if (head == NULL) {
		head = new node(x);
		return;
	}

	node * newnode = new node(x);

	node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newnode;
}

void insertAtPos(node* &head, int pos, int x) {
	node * newnode = new node(x);

	node * temp = head;
	int curPos = 1;
	while (temp->next != NULL) {
		if (curPos == (pos - 1))
			break;
		curPos++;
		temp = temp->next;
	}

	newnode->next = temp->next;
	temp->next = newnode;
}

void deleteAtStart(node * &head) {

	if (head == NULL) {
		cout << "List is Empty\n";
		return;
	}
	node* temp = head;

	head = head->next;

	free(temp);
}

void deleteAtEnd(node * &head) {

	if (head == NULL) {
		cout << "List is Empty\n";
		return;
	}
	else if (head->next == NULL) {
		head = NULL;
		return;
	}

	node * temp = head;
	node * prev = NULL;

	while ( temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}

	prev->next = NULL;

	free(temp);

}

void deleteAtPos(node*&head, int pos) {
	node * temp = head;
	node * prev = NULL;
	int curPos = 1;

	while (temp->next != NULL) {
		curPos++;

		prev = temp;
		temp = temp->next;

		if (pos == curPos)
			break;
	}
	prev->next = temp->next;
	free(temp);

}

void printll(node * head) {

	map <node*, int> m;

	node * temp = head;

	while (temp != NULL) {
		m[temp]++;


		if (m[temp] > 1) {
			if (temp != head)
				cout << temp->data << "~>";
			break;
		}
		cout << temp->data << "~>";

		temp = temp->next;
	} cout <<  newl;
}

int length(node *&head) {
	node* temp = head;
	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

int recursiveLength(node*& head) {
	if (head == NULL) {
		return 0;
	}
	return 1 + recursiveLength(head->next);
}

void reverse(node *& head) {
	if (head == NULL || head->next == NULL) {
		return;
	}

	node* prev = NULL, *cur = head, *next = NULL;

	while (cur != NULL) {
		next = cur->next; //3

		cur->next = prev; // NULL<-1
		prev = cur; // prev=1
		cur = next; //cur=2
	}
	head = prev;
}

bool isEmpty(node * head) {
	if (head == NULL) return true; else return false;
}
int size(node *head) {
	node *temp = head; int sz = 0;

	map <node*, int> m;

	while (temp != NULL)
	{
		m[temp]++;


		if (m[temp] > 1) {
			break;
		}
		sz++;
		temp = temp->next;
	}
	return sz;
}

bool insertAfter(node * head, int target, int val) {
	if (head == NULL) {
		cout << "List is Empty\n";
		return false;
	}
	bool found = false;
	node * temp = head;
	while (temp != NULL) {
		if (temp->data == target) {
			found = true;
			break;
		}
		temp = temp->next;
	}

	if (found) {
		node * newnode = new node(val);
		if (temp->next != NULL)
		{
			newnode->next = temp->next;
			temp->next = newnode;
		}
		else {
			temp->next = newnode;

		}
		return true;
	}
	else {
		cout << "Search Element NOT in the List\n";
		return false;
	}

}



void rotate(node* &head, int k) {
	if (head == NULL) {
		cout << "List is Empty\n";
		return ;
	}
	else if (size(head) < k) {
		cout << "Limit Exceed Exception\n";
		return ;
	}

	for (int i = 0; i < k; i++) {
		node * temp = head, *prev = NULL;

		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}

		node * temphead = head->next;
		head->next = NULL;
		temp->next = head;
		head = temphead;

	}
}

void connect(node *& head, int p1, int p2) {
	node *n1, *n2, *temp;
	int pos = 0;
	temp = head;
	while (temp != NULL) {
		pos++;

		if (p1 == pos) {
			n1 = temp;

			if (p1 == max(p1, p2)) break;
		}
		if (p2 == pos) {
			n2 = temp;

			if (p2 == max(p1, p2)) break;
		}
		temp = temp->next;
	}
	// cout << n1->data << "+" << n2->data << newl;
	n1->next = n2;

}

//using Floyd's Cycle test aka Tortise and Hare
bool detectLoop(node *&head) {
	node *slowptr = head;
	node *fastptr = head;

	while (slowptr && fastptr && fastptr->next) {
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if (slowptr == fastptr) {
			return true;
		}
	}
	return false;
}

bool isCircular(node *& head) {
	node* temp = head;
	map <node*, int> m;

	while (temp != NULL) {

		m[temp]++;

		if (m[temp] > 1)
		{
			if (temp == head)
				return true;
			else
				return false;
		}
		temp = temp->next;
	}
}

testSLL() {
	node * head = NULL;

	int inputs; cin >> inputs;
	string command;
	while (inputs--) {
		cin >> command;

		if (command == "I") {
			cout << boolalpha << isEmpty(head) << endl;
		}
		else if (command == "S") {
			cout << size(head) << endl;
		}
		else if (command == "IA") {
			int target, val;
			cin >> target >> val;
			if (insertAfter(head, target, val))
				printll(head);

		}
		else if (command == "IL") {
			int val; cin >> val;
			insertAtEnd(head, val);
			printll(head);
		}
		else if (command == "IF") {
			int val; cin >> val;
			insertAtHead(head, val);
			printll(head);
		}
		else if (command == "DF") {
			deleteAtStart(head);
			printll(head);
		}
		else if (command == "DL") {
			deleteAtEnd(head);
			printll(head);
		}
		else if (command == "C?") {
			cout << boolalpha << isCircular(head) << endl;

		}
		else if (command == "L?") {
			cout << boolalpha << detectLoop(head) << endl;
		}
		else if (command == "RO") {
			int times; cin >> times;
			rotate(head, times);
			printll(head);
		}
		else if (command == "C") {
			int p1, p2; cin >> p1 >> p2;
			connect(head, p1, p2);
			printll(head);
		}
	}
}

int main() {

	testSLL();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define newl "\n"

class node {
public:
	int data;
	node * next;
	node * pre;
	node(int x) {
		next = NULL;
		pre = NULL;
		data = x;
	}
};

bool isEmpty(node *& head) {
	return (head == NULL);
}
void insertFirst(node * & head, int val) {
	node *newnode = new node(val);
	if (head == NULL) {
		head = newnode;
	}
	else {
		newnode->next = head;
		head->pre = newnode;
		head = newnode;
	}
}

void insertLast(node *& head, int val) {
	node *newnode = new node(val);
	if (head == NULL) {
		head = newnode;
	}

	else {
		node *temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->pre = temp;
	}
}

void deleteFirst(node*& head) {
	if (isEmpty(head)) {
		cout << "List is Empty" << newl;
	}
	else {
		node* temp = head;
		head = temp->next;
		if (head != NULL)
			head->pre = NULL;

		free (temp);
	}
}


void deleteLast(node*& head) {
	if (isEmpty(head)) {
		cout << "List is Empty" << newl;
	}
	else {
		node * temp = head, *prev = NULL;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		temp->pre = NULL;
		free(temp);

	}
}

void print(node *& head) {
	if (isEmpty(head))
		cout << "List is Empty" << newl;
	else {
		node *temp = head;

		while (temp != NULL) {
			cout << temp->data << "~>";
			temp = temp->next;
		}
		cout << newl;

	}
}

void deleteSecondLast(node*&head) {
	if (isEmpty(head) || (head->next == NULL))
		cout << "Insufficient Elements Exception" << newl;
	else {
		node * temp = head, *pre = NULL;

		while (temp->next->next != NULL) {
			pre = temp;
			temp = temp->next;
		}

		if (pre == NULL) {
			head = head->next;
			free(temp);
		}
		else {
			pre->next = temp->next;
			free(temp);
		}

	}
}
void printRev(node*& head) {
	if (isEmpty(head))
		cout << "List is Empty" << newl;
	else {
		node * last = NULL, *temp = head;

		while (temp != NULL ) {
			last = temp;
			temp = temp->next;
		}
		while (last != NULL)
		{
			cout << last->data << "~>";
			last = last->pre;
		}
		cout << newl;
	}
}

void findElement(node*& head, int x) {
	if (isEmpty(head))
		cout << "List is Empty" << newl;
	else {
		node* iter = head;
		int pos = 0;
		while (iter != NULL) {
			if (iter->data == x) {
				cout << "Element found at " << pos << newl;
				return ;
			}
			iter = iter->next;
			pos++;
		}

		if (iter == NULL)
			cout << "Element not found!" << newl;
		return;

	}
}


void replaceElement(node*& head, int x, int y) {
	if (isEmpty(head))
		cout << "List is Empty" << newl;
	else {
		node* iter = head;
		int pos = 0;
		while (iter != NULL) {
			if (iter->data == x) {
				iter->data = y;
				cout << "Element replaced at " << pos << newl;
				return ;
			}
			iter = iter->next;
			pos++;
		}

		if (iter == NULL)
			cout << "Element not found!" << newl;
		return;

	}
}

void insertAfter(node*& head, int x, int y) {
	if (isEmpty(head))
		cout << "List is Empty" << newl;
	else {
		node* iter = head;
		int pos = 0;
		while (iter != NULL) {
			if (iter->data == x) {
				node* next = iter->next;

				node* newnode = new node(y);

				iter->next = newnode;
				newnode->pre = iter;

				newnode->next = next;
				next->pre = newnode;

				return ;
			}
			iter = iter->next;
			pos++;
		}

		if (iter == NULL)
			cout << "Element not found!" << newl;
		return;

	}
}

void insertBefore(node*& head, int x, int y) {
	if (isEmpty(head))
		cout << "List is Empty" << newl;
	else {
		node* iter = head;
		int pos = 0;
		while (iter != NULL) {
			if (iter->data == x) {
				node* prev = iter->pre;

				node* newnode = new node(y);

				prev->next = newnode;
				newnode->pre = prev;

				newnode->next = iter;
				iter->pre = newnode;

				return ;
			}
			iter = iter->next;
			pos++;
		}

		if (iter == NULL)
			cout << "Element not found!" << newl;
		return;

	}
}

void insertSorted(node*& head, int val) {
	node *newnode = new node(val);

	if (isEmpty(head) || val <= head->data) {
		newnode->next = head;

		if (head != NULL) {
			head->pre = newnode;
		}
		head = newnode;
	}

	else {

		node *& temp = head;
		while (temp->next != NULL && temp->next->data < val) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		newnode->pre = temp ;

		if (temp->next != NULL) {
			temp->next->pre = newnode;
		}
		temp->next = newnode;
	}
}

int size(node*& head) {
	node* temp = head;
	int sz = 0;
	while (temp != NULL) {
		temp = temp->next, sz++;
	}

	return sz;
}

int main() {
	node * head = NULL;



	return 0;
}

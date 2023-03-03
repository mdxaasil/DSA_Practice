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
	node* temp = head;

	head = head->next;

	free(temp);
}

void deleteAtEnd(node * &head) {
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
	node * temp = head;

	while (temp != NULL) {
		cout << temp->data << "~>";
		temp = temp->next;
	} cout <<  newl;
}

int main() {



	node * head = NULL;


	insertAtEnd(head, 1);
	insertAtEnd(head, 2);
	insertAtEnd(head, 3);
	insertAtEnd(head, 4);

	// deleteAtStart(head);
	deleteAtPos(head, 3);

	printll(head);
	return 0;
}

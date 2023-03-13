#include<bits/stdc++.h>
using namespace std;

class node {
public:
	node * next = NULL;
	int data;
};

void insertAtHead(node* &head, int x) {
	node* temp = new node(); temp->data = x;
	temp->next = head;
	head = temp;
}
void insertAtEnd(node *& head, int val ) {
	node *newnode = new node();
	newnode->data = val;

	if (head == NULL)
	{
		head = newnode;
		return ;
	}
	else {
		node * temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}


}

void printList(node * head) {
	node * temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "";
		temp = temp->next;

	} cout << endl;
}

int carry = 0;

void add(node *h1, node * h2, node *& h3) {

	if (h1 == NULL || h2 == NULL) return;

	add(h1->next, h2->next, h3);

	int sum = h1->data + h2->data + carry;
	if (sum >= 10) carry = 1;
	else carry = 0;
	// cout << sum << endl;
	insertAtHead(h3, sum % 10);




}
int main() {

	node * h1 = NULL, * h2 = NULL;


	int n, val;
	string op1, op2;

	cin >> op1 >> op2;
	n = op1.length();
	for (int i = 0 ; i < n; i++) {

		val = op1[i] - '0';
		insertAtEnd(h1, val );
	}
	for (int i = 0 ; i < n; i++) {

		val = op2[i] - '0';
		insertAtEnd(h2, val );
	}
	// printList(h1);
	// printList(h2);

	node * h3 = NULL;

	add(h1, h2, h3);

	printList(h3);



	return 0;
}

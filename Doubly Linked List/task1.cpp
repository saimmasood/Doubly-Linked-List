#include<iostream>
using namespace std;


struct node {
	int data=0;

	node* prev=NULL;
	node* next=NULL;

};

node* head = NULL;


void insertAtBeg(int d) {

	node* newNode = new node();
	newNode->data = d;

	if (head == NULL) {
		
		newNode->next = head;
		head = newNode;
		newNode->prev = NULL;
		
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	newNode->prev = NULL;
	head = newNode;
}

void insertAtEnd(int d) {
	node* newNode = new node();
	newNode->data = d;

	if (head == NULL) {
		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;

		return;
	}

	node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = NULL;

}


void insertAtAnyPos(int d,int p) {

	node* newNode = new node;
	newNode->data = d;

	if (p == 1) {
		if (head == NULL) {
			head = newNode;
			return;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;

			return;
		}
	}

	node* temp = head;

	for (int i = 1;i < p - 1;i++) {

		temp = temp->next;
		if (temp== NULL) {
			cout << "Position not found:" << endl;
			return;
		}
	}

	//or

	//	for (int i = 1; i < p-1 && temp != NULL; i++) {
	//		temp = temp->next;
	//	}

	//// invalid position
	//if (temp == NULL) {
	//	cout << "Invalid position" << endl;
	//	return;
	//}

	if (temp->next == NULL) {
		newNode->next = NULL;
		newNode->prev = temp;
		temp->next = newNode;
		return;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	newNode->next->prev = newNode;
	temp->next = newNode;


}



void deleteFromBeg() {

	if (head == NULL) {
		cout << "Noting to delete , list empty!" << endl;
		return;
	}

	node* temp = head;

	if (head->next == NULL) {
		delete temp;
		head = NULL;
		return;
	}

	head = head->next;
	head->prev = NULL;

	delete temp;


}


void deleteFromEnd() {
	if (head == NULL) {
		cout << "List empty , " << endl;
		return;
	}

	node* temp = head;
	if (head->next == NULL) {
		head = head->next;
		delete temp;
		return;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->prev->next = NULL;
	delete temp;

}

void deleteAtPos(int p) {

	if (head == NULL) {
		cout << "Empty list " << endl;
		return;
	}

	node* temp = head;
	if (p == 1) {
		if (head ->next== NULL) {
			head = head->next;
			delete temp;
			return;
		}
		
		head = head->next;
		head->prev = NULL;
		delete temp;
		return;
	}

	for (int i = 1;i < p;i++) {
		temp = temp->next;
		if (temp == NULL) {
			cout << "Invalid position to delete:" << endl;
			return;
		}
	}

	//or

	//	for (int i = 1; i < p && temp != NULL; i++) {
	//		temp = temp->next;
	//	}

	//// invalid position
	//if (temp == NULL) {
	//	cout << "Invalid position" << endl;
	//	return;
	//}

	if (temp->next == NULL) {
		temp->prev->next = NULL;
		delete temp;
		return;
	}

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;

}



	void display(){
		node* temp = head;

		cout << "Doubly Linked List: ";

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}


	}





int main() {

	insertAtBeg(10);
	insertAtBeg(20);

	insertAtEnd(30);
	insertAtEnd(40);

	insertAtAnyPos(25, 3);

	deleteFromBeg();

	deleteFromEnd();

	deleteAtPos(2);

	display();

	system("pause");
	return 0;
}
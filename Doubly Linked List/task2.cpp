#include<iostream>
using namespace std;


struct node {
	int data = 0;
	node* next = NULL;
	node* prev = NULL;
};

node* head = NULL;

void insertStart(int d) {
	node* newNode = new node();
	newNode->data = d;

	if (head == NULL) {
		head = newNode;
		return;
	}
	if (head->next == NULL) {


		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void display() {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}


void swapNodes() {

	if (head == NULL || head->next == NULL) {
		cout << "Cant swap:" << endl;
		display();
		return;
	}

	node* temp1 = head;
	node* temp2 = head->next;



	while (temp1->next != NULL || temp2 != NULL) {

		node* temp5 = temp1->next->next;
		node* temp6 = temp2->next->next;



		node* temp3 = temp1;
		node* temp4 = temp2;



		if (temp3 == head) {

			temp4->next->prev = temp3;
			temp4->next = temp3;

			temp3->next = temp4->next;
			temp3->prev = temp4;



			temp4->prev = NULL;

			head = temp4;

			temp1 = temp5;
			temp2 = temp6;
			continue;
		}
		else {

			temp4->prev = temp3->prev;
			temp3->prev->next = temp4;

			temp3->next = temp4->next;
			temp3->prev = temp4;
			temp4->next = temp3;


			temp1 = temp5;
			temp2 = temp6;
			continue;

		}



	}

}



int main() {


	insertStart(5);
	insertStart(4);
	insertStart(3);
	insertStart(2);
	insertStart(1);

	display();

	cout << endl;


	swapNodes();

	display();
}
#include <iostream>
#include <string>
using namespace std;
class Address{
public:
	int i = 0;
	string name;
	string city;
	int ph;
	// default constructors
	Address(){
		name = "";
		city = "";
		ph = 0;
	}
	// constructor for initializing
	Address(string a, string b, int c){
		name = a;
		city = b;
		ph = c;
	}
	// copy constructor
	Address(const Address *adr){
		name = adr->name;
		city = adr->city;
		ph = adr->ph;
	}

	bool operator==(const Address adr)
	{
		return name.compare(adr.name) == 0 ? true : false;
	}
	// Display
	void display(){
		cout << "---------" << endl;
		cout << "Name: " << name << endl;
		cout << "City: " << city << endl;
		cout << "Ph: " << ph << endl;
	}
};
template <typename T>
struct Node{
	T data;
	Node *next;
	Node *back;
};
template <typename T>
class DoublyLinkedList{
private:
	// Defining metadta
	Node<T> *head, *tail;
	int size;
public:
	// constructor
	DoublyLinkedList(){
		head = NULL;
		tail = NULL;
	};
	// display the contents of the list
	void displayList();
	// Insert a node at the head
	void insertAtHead(T d);
	// which inserts a node at
	//the end of the list.
	void insertAtEnd(T d);
	// which deletes the node at the head of the list.

	void deleteAtHead();
	//which deletes the node
	//	at the end of the list.
	void deleteAtEnd();
	// function which searches a node
	//and deletes that.
	void deleteNode(T d);
};
// display the contents of the list
template <typename T>
void DoublyLinkedList<T>::displayList(){
	Node<T> *tmp = head;
	while (tmp){
		tmp->data.display();
		tmp = tmp->next;
	}
}
// Insert a node at the head
template <typename T>
void DoublyLinkedList<T>::insertAtHead(T d){
	Node<T>* newNode = new Node<T>;
	newNode->data = d;
	if (head == NULL){
		newNode->next = NULL;
		newNode->back = NULL;
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->back = NULL;
		newNode->next = head;
		head->back = newNode;
		head = newNode;
	}
}
//INSERT THE NODE AT THE END OF THE LIST 
template <typename T>
void DoublyLinkedList<T>::insertAtEnd(T d){
	Node<T>* newNode = new Node<T>;
	newNode->data = d;
	if (head == NULL){
		newNode->next = NULL;
		newNode->back = NULL;
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->back = tail;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}
//DELETE AT THE START OF THE LIST 
template <typename T>
void DoublyLinkedList<T>::deleteAtHead(){
	head = head->next;
	delete head->back;
	head->back = NULL;
}
//DELETE AT THE END OF THE LIST 
template <typename T>
void DoublyLinkedList<T>::deleteAtEnd(){
	tail = tail->back;
	delete tail->next;
	tail->next = NULL;

}
//DELETE SPECIFIED NODE
template <typename T>
void DoublyLinkedList<T>::deleteNode(T d)
{
	Node<T> *temp = head;
	Node<T> *previous = NULL;
	Node<T> *front = NULL;
	int flag = 0;
	while (temp)
	{
		if (temp->data == d)
		{
			previous = temp->back;
			front = temp->next;
			flag = 1;
			break;
		}
		temp = temp->next;
	}

	if (flag == 1)
	{
		if (temp == head)
			deleteAtHead();
	
		else if (temp == tail)
			deleteAtEnd();
		else
		{
			previous->next = front;
			delete temp;
			front->back = previous;
		}
	}

}


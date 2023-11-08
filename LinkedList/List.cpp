#include <iostream>

// circular double linked list
// last element has access to the head of the list
// the head of the list has access to the last element
class DoublyLinkedList {
private :
	//inner class "node" defines a number that has pointers to the next and previous elements of the list
	//this class is inner because it will only be used in this class.
	//it is not suitable for other classes
	class node {
	public:
		node(int value) : value(value) {

		}
		int value{};
		node* next = NULL;
		node* prev = NULL;
	};

	node* head = nullptr ;
public:
	void push_back(int number) {
		if (head == nullptr) {
			head = new node(number);
			return;
		}
		node* new_node = new node(number);
		node* last_element = (head->prev == nullptr ? head : head->prev);
		new_node->next = head;
		new_node->prev = last_element;
		last_element->next = new_node;
		head->prev = new_node;
	}	

	void push_front(int number) {
		if (head == nullptr) {
			head = new node(number);
			return;
		}
		node* new_node = new node(number);

		new_node->next = head;

		new_node->prev = ( head->prev == nullptr ? head : head->prev );
		head->prev = new_node;
		new_node->prev->next = new_node;

		head = new_node;
	}

	void find(int number) {
		node* current = head;
		while (current->next != head) {
			if (current->value != number && current->next != head) {
				current = current->next;
			}
			else {
				if (current->value == number) {
					std::cout << "Number " << number << " is found" << "\n";
					return;
				}
			}
		}
		std::cout << "Number " << number << " is not found" << "\n";
	}

	int find_length() {
		node* current = head;
		if (current == nullptr) {
			return 0;
		}
		else {
			int count = 1;
			while (current->next != head) {
				count++;
				current = current->next;
			}
			return count;
		}
	}

	void reverse() {
		if (head == nullptr) {
			return; // Empty list, nothing to reverse.
		}

		node* current = head;
		do {
			node* temp = current->next;
			current->next = current->prev;
			current->prev = temp;
			current = temp;
		} while (current != head);

		head = head->next; // Update the head to the new head after reversal.
	}

	void print() {
		node* current = head;
		while (current->next != head) {
			std::cout << current->value << ' ';
			current = current->next;
		}
		std::cout << current->value << ' ';
	}
};

int main() {
	DoublyLinkedList list;

	list.push_back(29);
	list.push_back(30);
	list.push_back(2);
	list.print();
	list.push_back(5);
	list.push_back(10);
	list.print();
	list.push_front(40);
	list.push_front(50);
	std::cout << "\n";
	list.print();
	std::cout << "\n\n";
	list.find(2);
	list.find(5);
	list.find(50);
	list.find(60);
	std::cout << "\n";
	std::cout << list.find_length();
	std::cout << "\n";
	list.reverse();
	list.find(29);
	list.print();
}
#include <iostream>

class list {
	// circular double linked list
	// last element have access to the head of the list
	// head of the list have access to the last element
private :
	// head is static so every object has access to it
	static inline list* head = nullptr ;
public:
	int value{};
	list* next = NULL;
	list* prev = NULL;
	
	void push_back(int number) {
		if (head == nullptr) {
			head = this;
			value = number;
			return;
		}
		list* new_node = new list();
		list* last_element = (prev == nullptr ? head : head->prev);
		new_node->value = number;
		new_node->next = head;
		new_node->prev = last_element;
		last_element->next = new_node;
		head->prev = new_node;
	}	

	void push_front(int number) {
		if (head == nullptr) {
			head = this;
			value = number;
			return;
		}
		list* new_node = new list();

		new_node->value = number;
		new_node->next = head;

		new_node->prev = ( head->prev == nullptr ? head : head->prev );
		head->prev = new_node;
		new_node->prev->next = new_node;

		head = new_node;

	}

	void find(int number) {
		list* current = head;
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
	// we can find the length of a list either by recursion or by loop
	int find_length(list* current = head) {
		if (current->next != head) {
			return find_length(current->next) + 1;
		}
		else return 1;
	}
	// 50 40 10
	// 10 40 50
	void reverse() {
		list* current = head;
		list* next = current->next;
		list* prev = current->prev;

		while (next != head) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = current->next;
	}

	void print() {
		list* current = head;
		while (current->next != head) {
			std::cout << current->value << ' ';
			current = current->next;
		}
		std::cout << current->value << ' ';
	}
};

int main() {
	list list;

	list.push_back(10);
	list.push_front(40);
	list.push_front(50);
	list.push_back(29);
	list.push_back(30);
	list.push_back(2);
	list.push_back(5);
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
	list.find(2);
	list.print();
	std::cout << " " << list.next << " " << list.prev << " ";
}
#include <iostream>
using namespace std;

template <class etype>
class stack {
private:
	class node {
	public:
		etype value;
		node* next;

		node( etype new_value = 0 ) : value( new_value ), next( NULL ) {}
	};

	int length;
	node* head;

public:
	stack(): length(0), head(NULL) {}

	bool empty() const { return (head == NULL); }
	int size() const { return length; }

	etype top();
	void push( const etype new_value );
	etype pop();
};

template <class etype>
etype stack<etype> :: top() {
	if( head == NULL )
		throw "exception null pointer";

	return head->value;
}

template <class etype>
void stack<etype> :: push( const etype new_value ) {
	node* new_node = new node( new_value );
	
	new_node -> next = head;
	head = new_node;
	++length;
} 

template <class etype>
etype stack<etype> :: pop() {
	if( head == NULL )
		throw "exception null pointer";

	etype old_value = head -> value;
	node* old_node = head;

	head = head -> next;
	delete( old_node );
	--length;

	return old_value;
}
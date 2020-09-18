#include <iostream>

using namespace std;

template <class etype>
class queue {
	class node {
	public:
		etype value;
		node* next;

		node( etype new_value = 0 ) : value( new_value ), next( NULL ) { }
	};

	int length;
	node* head;
	node* back;

public:
	queue(): length(0),head(NULL),back(NULL) {}

	bool empty() const { 
		return (head == NULL);
	}

	int size() const {
		return length;
	}

	etype front();
	void push( const etype new_value );
 	etype pop( );
};

template <class etype>
void queue< etype > :: push( const etype new_value ){
	node* new_node = new node( new_value );

	if( empty() )
		head = back = new_node;
	else {
		back->next = new_node;
		back = back->next;
	}
	++length;
}

template <class etype>
etype queue< etype > :: pop() {
	if ( empty() )
		throw "exeption null pointer";

	etype old_value = head->value;
	node* old_node = head;

	head = head->next;
	if ( head == NULL )
		back = NULL;

	delete old_node;
	--length;
	return old_value;
}

template <class etype>
etype queue< etype > :: front() {
	if ( empty() )
		throw "exeption null pointer";

	return head->value;
}
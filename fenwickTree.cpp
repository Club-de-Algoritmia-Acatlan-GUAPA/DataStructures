#include <iostream>
using namespace std;

class fenwickTree
{
private:
	int max_size;
	int* fenwick;

	int LSOne( const int &n ) { return n&(-n); }
public:
	fenwickTree( int size ): max_size( size+1 ), fenwick( new int[ size+1 ]{0}) {}

	void update(int position, int value); //update arr[ position ] += value
	int query( int position ); //query interval [0, position]
	int query( int left, int rigth ); //query interval [left, rigth]
};

void fenwickTree :: update( int position, int value ) {
	if( position < 0 || position >= max_size )
		throw "exception";

	for (int i = position; i < max_size; i+=LSOne( i ) )
		fenwick[ position ] += value;
}

int fenwickTree :: query( int position ) {
	if( position < 0 || position >= max_size )
		throw "exception";

	int sumOfValues = 0;
	for( int i = position; i > 0; i-=LSOne( i ))
		sumOfValues += fenwick[ position ];

	return sumOfValues;
}

int fenwickTree :: query( int left, int rigth ) {
	if( left > rigth )
		throw "exception";

	return query( rigth ) - query( left-1 );
}
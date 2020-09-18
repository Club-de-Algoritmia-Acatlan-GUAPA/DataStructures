#include <bits/stdc++.h>
#define l(p) (p<<1)
#define r(p) ((p<<1)+1)
#define mid(i,j) ((i+j)>>1)

using namespace std;

class SegmentTree
{
private:
	int length;
	vector<int> tree;
	vector<int> data;

	void build( int p, int i, int j ) {
		if( i == j ) {
			tree[ p ] = data[ i ];
			return;
		}

		build( l(p), i,   mid(i,j) );
		build( r(p), mid(i,j)+1, j );

		tree[ p ] = tree[ l(p) ] + tree[ r(p) ];
	}

	void update( int p, int i, int j, int a, int value ) {
		if( a < i || j < a ) return;

		if( i == a && j == a ) {
			tree[ p ] = data[ i ] = value;
			return;
		}

		update( l(p),   i, mid(i,j), a, value );
		update( r(p), mid(i,j)+1, j, a, value );

		tree[ p ] = tree[ l(p) ] + tree[ r(p) ];
	}

	int query( int p, int i, int j, int a, int b ){
		if( b < i || j < a ) return 0;
		if( a <= i && j <= b ) return tree[ p ];
	
		int left_node = query( l(p), i, mid(i,j), a, b );
		int right_node = query( r(p), mid(i,j)+1, j, a, b);
		
		return left_node + right_node;
	}

public:
	SegmentTree( vector<int> &new_data ) {
		length = new_data.size();
		tree.resize( 6*length );
		data = new_data;

		build( 1, 0, --length );
	}

	void update( int position, int value ) {
		update( 1, 0, length, position, value );
	}

	int query( int a, int b ){
		return query( 1, 0, length, a, b );
	}
};

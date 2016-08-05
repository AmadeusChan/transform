#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

const int inf = 0x7fffffff ;
const int maxn = 100 ; 

string origin , target , a[ maxn ] , b[ maxn ] ;
int cnt = 0 , ans = inf ; 

string trans( string state , int i , int j ) {
	string str = "" ; 
	for ( int k = 0 ; k < j ; ++ k ) str = str + state[ k ] ;
	str = str + b[ i ] ;
	for ( int k = j + a[ i ].size(  ) ; k < state.size(  ) ; ++ k ) str = str + state[ k ] ;
	return str ; 
}

void dfs( string state , int step ) {
	if ( step >= ans ) return ; 
	if ( state == target ) {
		ans = min( ans , step ) ;
		return ; 
	}
	for ( int i = 0 ; i < cnt ; ++ i ) {
		for ( int j = 0 ; j < state.size(  ) - a[ i ].size(  ) + 1 ; ++ j ) {
			bool flag = true ; 
			for ( int k = 0 ; k < a[ i ].size(  ) ; ++ k ) if ( a[ i ][ k ] != state[ j + k ] ) {
				flag = false ; break ; 
			}
			if ( flag ) dfs( trans( state , i , j ) , step + 1 ) ;
		}
	}
}

int main(  ) {
	freopen( "transform.in" , "r" , stdin ) ;
	freopen( "transform.out" , "w" , stdout ) ; 
	cin >> origin >> target ; 
	while ( ! ( cin >> a[ cnt ] ).eof(  ) ) {
		cin >> b[ cnt ++ ] ;
	}
	dfs( origin , 0 ) ;
	cout << ans << endl ;
	fclose( stdin ) , fclose( stdout ) ; 
	return 0 ; 
}

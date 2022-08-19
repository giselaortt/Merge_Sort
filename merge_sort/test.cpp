
#include <iostream>
#include<list>


using namespace std;


list<int> function( list<int> test ){

    test.clear();
    test.push_back( 5 );
    test.push_back( 5 );
    test.push_back( 5 );
    test.push_back( 5 );
return test;
}



int main(){

    list<int> test = {1,2,3,4,5};
    test = function( test );
    for( auto it = test.begin(); it != test.end(); it++ )
        cout << *it <<   " " ; 

return 0; 
}


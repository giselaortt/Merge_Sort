
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

typedef list<int>::iterator NODE;


list<int> merge_two_sorted_linked_lists( list<int> first, list<int> second ){
    list<int>::iterator it_first = first.begin(), it_second = second.begin();
    list<int> answer;
    while( it_first != first.begin() || it_second != second.end() ){
        if( ( it_second == second.end() ) || ( it_first != first.end() && *it_first < *it_second) ){
            answer.push_back( *it_first );
            it_first++;
        } else {
            answer.push_back( *it_second );
            it_second++;
        }
    }
    return answer;
}


list<int> merge_sort( list<int> numbers ){

    int n = numbers.size();
    if( n == 1 )
        return numbers;
    list<int> temp_list_1, temp_list_2;
    int i;
    list<int>::iterator it;
    for( i=0, it = numbers.begin(); it != numbers.end(); i++, it++ ){
        if( i<n/2 )
            temp_list_1.push_back( *it );
        else
            temp_list_2.push_back( *it );
    }
    temp_list_1 = merge_sort( temp_list_1 );
    temp_list_2 = merge_sort( temp_list_2 );
    numbers.clear();
    numbers = merge_two_sorted_linked_lists( temp_list_1, temp_list_2 );

    return numbers;
}


int main(){

    int size_of_array;
    int value;
    cin >> size_of_array;

    list<int> numbers;

    
    for( int i=0; i<size_of_array; i++ )
        cin >> value,
        numbers.push_back( value );

    merge_sort( numbers );

    for( auto it = numbers.begin(); it != numbers.end(); it++ )
        cout << *it << "  ";

    cout << endl;
    

return 0;
}



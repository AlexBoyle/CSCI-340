#include <vector>
#include <algorithm>
#include<iomanip>
#include<iostream>
#include <stdlib.h>

using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::right;
using std::sort;
using std::equal_range;
using std::pair;
using std::find;
using std::search;

const int DATA_SIZE = 200;
const int SEARCH_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;
const int NO_ITEMS = 12;
const int ITEM_W = 5;



/******************************
void genRndNums(vector<int>& , int)

param: 	vector<int>& : vector to be filled
	int : seed for rand numbers

Fills a vector with random numbers gotten from a seed
*******************************/
void genRndNums( vector<int>& v, int seed ) {
	srand(seed);
	 vector<int>::iterator i;
        for (i = v.begin(); i != v.end(); i++){
		*i =  rand() % 200 + 1;
	}
}

/*********************************
int linearSearch( const vector<int>&, int)

param:	const vector<int>&: vector being searched
	int: numebr being searched for

return : index of the int being searched for, else -1
an implementation of a linear search
*********************************/
int linearSearch( const vector<int>& inputVec, int x) {
	std::vector<int>::const_iterator it;
	it = find (inputVec.begin(), inputVec.end(), x);
	if(it == inputVec.end()){
		return -1;
	}
	return it - inputVec.begin();
}

/*********************************
int binarySearch( const vector<int>& ,int)

param:  const vector<int>&: vector being searched
        int: numebr being searched for

return : index of the int being searched for, else -1
an implementation of a binary search
*********************************/

int binarySearch( const vector<int>& inputVec, int x) {
	pair<vector<int>::const_iterator,vector<int>::const_iterator> bound;
        bound = equal_range (inputVec.begin(), inputVec.end(), x);
	if( bound.first ==  bound.second){
		return -1;
	}
	return bound.first - inputVec.begin();
}

/*************************************8
int search( const vector<int>&, const vector<int>& ,int (*p)( const vector<int>&, int))

param:	vector: vector being searched
	vector: vector of numbers to search for
	function: search function
return : numebr of successful searches

THis function checks the successfulness of a function when searching for elements in a vector
***************************************/
int search( const vector<int>& inputVec, const vector<int>& searchVec,
            int (*p)( const vector<int>&, int) ){
	int count = 0;
	vector<int>::const_iterator i;
        for (i = searchVec.begin(); i != searchVec.end(); i++){
		if(p(inputVec,*i) > -1)
			count ++;
	}
	return count;
}

/************************************88
void sortVector (vector<int>&)

param: vector: vector to be sorted

This function sorts vectors in assending order
****************************************/
void sortVector (vector<int>& inputVec) {
	sort (inputVec.begin(), inputVec.end());
}

/******************************************
void printStat (int , int ) {

params:	int: numebr of successful searches
	int: number ot total searches

this function displays the percentage of succsessful searches
***************************************/
void printStat (int totalSucCnt, int vec_size) {
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	cout << "Successful searches: " << setw(5) << right << ((double)totalSucCnt / (double)vec_size) * 100 << "%\n";
}

/***********************************************
void print_vec( const vector<int>& )

param:	vector: vector to be printed

THis function displays a vector
**********************************************/
void print_vec( const vector<int>& vec ){
	int num = 0;
        vector<int>::const_iterator i;
        for (i = vec.begin(); i != vec.end(); i++){
                if(num != 0 && num % NO_ITEMS == 0 )
                        cout << endl;
                cout << setw(ITEM_W) << right << *i ;
                num ++;
        }
	cout << endl;
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

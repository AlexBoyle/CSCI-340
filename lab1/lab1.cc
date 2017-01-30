#include<iostream>
#include<vector>
#include<set>
using std::cout;
using std::vector;
using std::set;
using std::endl;
/*******	******************************************************************************************************************
Purpose: This program initialises a vector of integers, add 10 natural numbers which are multiples of 10 eg: 10,20,....100.
         Print the vector. Now add 5 to each element of the vector. Copy these numbers to a new set and diplay the outout 
		 of vector in reverse order using reverse iterator and set in normal order with iterator.
Task   : Complete the code.
Output : 10 20 30 40 50 60 70 80 90 100
		105 95 85 75 65 55 45 35 25 15
		15 25 35 45 55 65 75 85 95 105
***************************************************************************************************************************/

int main(){
	vector<int> myvector;
	// add 10 natural numbers which are multiples of 10 eg: 10,20,....100
	for(int i = 1; i <=10; i ++){
		myvector.push_back(i * 10);
	}
	// display the vector
	vector<int>::iterator i;
	for (i = myvector.begin(); i != myvector.end(); i++)
		cout << *i << " ";
	cout << endl;

	//Add number 5 to all the elements
	for (i = myvector.begin(); i != myvector.end(); i++)
		*i += 5;

	// copy the vector to a set
	set<int> myset (myvector.begin(),myvector.end());

	//Display vector in reverse order using reverse_iterator
	vector<int>::reverse_iterator k;
	for(k = myvector.rbegin(); k != myvector.rend(); k++ ){
		cout << *k << " ";
	}
	cout<<'\n';

	//Display set in normal order
	set<int>::iterator s;
	for(s = myset.begin(); s != myset.end(); s++){
		cout << *s << " ";
	}
	cout<<'\n';
	return 0;
}

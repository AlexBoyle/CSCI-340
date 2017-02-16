#include<iostream>
#include <iomanip>
#include <stdlib.h>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::set;
using std::setw;
using std::string;

const int NO_ITEMS = 8;
const int ITEM_W = 6;

/****************************************
void sieve( set<int>&, const int, const int)

param:	set<int> - set the primes will be put in
	const int - lower bounds of primes
	const int - upper bounds of primes

Creates a list of primes
****************************************/
void sieve( set<int>& s, const int lower, const int upper) {
	s.clear();
	s.insert(2);
	for(int i = 3; i <= upper ; i += 2 ){
                s.insert(i);
        }
	set<int>::iterator it = s.begin();
	set<int>::iterator itt = s.begin();
	for (it = s.begin(); it != s.end(); it ++){
		for (itt = it; itt!= s.end(); itt ++){
			if((*itt%*it==0) && (*itt != *it)){
				s.erase(itt);
			}
		}
	}
	for(it = s.begin(); *it < lower;it ++){
		s.erase(it);
	}
}

/****************************************
void print_primes( const set <int>&, const int, const int)

param:	const set<int>& - set to be printed
	const int - lower bound of set
	const int - upper bound of set

Prints the set givin to it
****************************************/
void print_primes( const set <int>& s, const int lower, const int upper) {
	int i = 0;
	cout<< "There are " << s.size() << " prime numbers between " << lower << " and " << upper << ":";
	for(set<int>::const_iterator it = s.begin(); it != s.end(); it ++){
		if(i%NO_ITEMS == 0)
			cout<<'\n';
		cout << setw(ITEM_W)<<*it;
		i ++;
	}
	cout << '\n';
}

/****************************************
void run_game(set<int>&)

param:	set<int>& - set to use for prime list

Runs the prime game
****************************************/
void run_game(set<int>& s) {
	bool again = true;
	while (again){
		cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100)";
		int upper = 0;
        	int lower = 0;
		cin >> lower;
		cin >> upper;
		sieve(s, lower, upper);
		print_primes(s,lower,upper);
		cout << "Do you want to continue or not? Please answer yes or no and hit enter:";
		string in;
		cin >> in;
		if(in != "yes")
			again = false;
	}
}

int main() {
    set<int> s;
    run_game(s);
    return 0;
}


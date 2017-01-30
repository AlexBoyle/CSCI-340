/*
*Alex Boyle
*z1759628
*
*Assign1
*1/29/2016
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

const int DATA_RANGE = 100;
const int DATA_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;
const int NO_ITEMS = 10;
const int ITEM_W = 6;

using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::right;

bool linear_search(const vector<int>& vec, const int x, int& comparisons) {
	comparisons = 0;
	vector<int>::const_iterator i;
	//loop through vector to check if the target is in there
	//in an array of 66 the worst cases 66 comparisons
        for (i = vec.begin(); i != vec.end(); i++){
		comparisons ++;
		//check for item
		if(*i == x){
			return true;
		}
	}
	return false;
}

bool binary_search(const vector<int>& vec, const int x, int& comparisons) {
	comparisons = 0;
	//three inital binary search vars
	int start = 0,end = vec.size() - 1,middle = ((end + start)/2);
	//main loop: there are two comparisons per loop
	// with an array of 66 the worst case is 12 comparisons
	while (start <=  end){
		comparisons ++;
		if(x == vec[middle]){
			return true;
		}
		else if(x < vec[middle]){
			//remove the sectoion of vector that we dont need
			end = middle - 1;
		}
		else {
			//remove the sectoion of vector that we dont need
			start = middle + 1 ;
		}
		//set middle to the new middle between start and end
		middle = ((end + start)/2);
		comparisons ++;
	}
	return false;
}

void print_vec( const vector<int>& vec ){
	int num = 0;
	vector<int>::const_iterator i;
        for (i = vec.begin(); i != vec.end(); i++){
		if(num != 0 && num % NO_ITEMS == 0 )
			cout << endl;
                cout << setw(ITEM_W) << right << *i ;
		num ++;
	}
}

void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, bool (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison=0, sum=0, found = 0;
    bool res;
    for (i=0; i<(int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res )
           found++;
    }
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

int random_number() {
    return rand()%DATA_RANGE+1;
}

int main () {

    // -------- create unique random numbers ------------------//
    vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl; 
    print_vec(inputVec);
    cout << endl;

    // -------- create random numbers to be searched ---------//
    vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
    print_vec(searchVec);
    cout << endl;
    
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    cout << "------- numbers in data source are now sorted ---------" << endl << endl;
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}



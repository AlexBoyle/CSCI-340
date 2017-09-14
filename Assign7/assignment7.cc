#include <algorithm>
#include<vector>
#include<iomanip>
#include<iostream>

using namespace std;
const int HEAP_SIZE = 50;



/*********************************************************************************
*void heapify( vector < int >& v, int heap_size, int i, bool (*compar)(int, int) )
*
*Param:	vector - heap vector
*	int - size of heap
*	int - index
*	bool(*)(int,int) - compar function
*
*
**********************************************************************************/
void heapify( vector < int >& v, int heap_size, int i, bool (*compar)(int, int) ){
	int index;
	int l = (2*i);
	int r = (2*i) + 1;
	if(l <= heap_size && compar(v[l], v[i]))
		index = l;
	else
		index = i;
	if(r <= heap_size && compar(v[r], v[index]))
		index = r;
	if(index != i ){
		int temp = v[index];
		v[index] = v[i];
		v[i] = temp;
		heapify(v, heap_size, index, compar);
	}
}

/*********************************************************************************
*void build_heap ( vector < int >& v, int heap_size,bool (*compar)(int, int) )
*
*Param: vector - heap vector
*       int - size of heap
*       bool(*)(int,int) - compar function
*
*
**********************************************************************************/
void build_heap ( vector < int >& v, int heap_size,bool (*compar)(int, int) ){
        for(int i = heap_size/2; i > 0; i-- ){
                heapify(v, heap_size, i, compar);
        }
}
bool less_than ( int e1, int e2 ){return e1 < e2;}

bool greater_than ( int e1, int e2 ){return e1 > e2;}
/*********************************************************************************
*int extract_heap ( vector < int >& v, int& heap_size, bool(*compar)(int, int) )
*
*Param: vector - heap vector
*       int - size of heap
*       bool(*)(int,int) - compar function
*
*return first node
**********************************************************************************/
int extract_heap ( vector < int >& v, int& heap_size, bool(*compar)(int, int) ){
	int num = v[1];
	v[1] = v[heap_size];
	v[heap_size] = num;
	heap_size --;
	heapify(v, heap_size, 1, compar);
	return num;
}

/*********************************************************************************
*void print_vector ( vector < int >& v, int pos, int size )
*
*Param: vector - heap vector
*       int - start index
*       int - len of heap
**********************************************************************************/
void print_vector ( vector < int >& v, int pos, int size ){ 

	for( int i = pos; i <= size; i ++){
		cout<<setw(5)<<right<<v[i];
		if(i%8 == 0)
			cout<< '\n';
	}
	cout<<'\n';
}
/*********************************************************************************
*void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
*
*Param: vector - heap vector
*       int - size of heap
*       bool(*)(int,int) - compar function
*
**********************************************************************************/
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) ){
        while (heap_size > 1){
                extract_heap(v, heap_size, compar);
        }
	reverse(v.begin() + 1, v.end());
}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}

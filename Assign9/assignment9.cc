#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "assignment9.h"
using namespace std;
/********************************
*void graph::depth_first( int a)
*
*Param:	int - node number to start traversial at
*
*Traverses graph
********************************/
void graph::depth_first( int a){
	cout<<labels[a]<<" ";
	visit.push_back(a);
	int pos = 0;
	for(list<int>::iterator it = adj_list[a].begin(); it != adj_list[a].end(); it ++){
		if(*it == 1 && find(visit.begin(),visit.end(), pos) == visit.end()){
			pair += string("(") + labels[a] + string(", ") + labels[pos] + string(") ");
			depth_first(pos);
		}
		pos++;
	}
}
/******************************
*graph::graph( const char* filename )
*
*param:	char* - input file
*
*reads a file and creates a graph
********************************/
graph::graph( const char* filename ){
	pair = "";
	ifstream infile(filename, ios::in);
	string line;
	infile >> size;
	for(int i = 0; i < size; i ++){
		infile >> line;
		labels.push_back(line[0]);
	}
	for(int i = 0; i < size; i ++){
		infile >> line;
		adj_list.push_back(*(new list<int>()));
		for(int j = 0; j < size; j ++){
			int val;
			infile >> val;
			adj_list[i].push_back(val);
		}
	}
}
/***************************************
*graph::~graph()
*
*Called when the object is destroyed
******************************************/
graph::~graph(){}
/**************************************
*int graph::get_size() const
*
*returns the size of the gragh
***************************************/
int graph::get_size() const{return size;}
/***************************************
*void graph::traverse()
*
*prints the graph in a depth first format
***************************************/
void graph::traverse(){
	cout <<"------- travere of graph ------\n";
	for(int i = 0; i < size; i ++){
		if(find(visit.begin(), visit.end(), i) == visit.end())
			depth_first(i);
	}
	cout<<'\n'<< pair<<'\n';
	pair = "";
	cout<<"--------- end of traverse -------\n\n";
}
/*************************************
*void graph::print ( ) const
*
*prints the graph
************************************/
void graph::print ( ) const{
	cout <<"\nNumber of vertices in the graph: " <<size<<"\n\n";
	cout <<"-------- graph -------\n";
	for(int i = 0; i < size; i ++){
		cout<<labels[i]<< ": ";
		int lab = 0;
		for(list<int>::const_iterator it = adj_list[i].begin(); it !=adj_list[i].end(); it++){
			if(*it == 1){
				cout<<labels[lab]<<", ";
			}
			lab++;
		}
		cout<<'\n';
	}
	cout<<"------- end of graph ------\n\n";
}




#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }
    
    graph g(argv[1]);

    g.print();
    
    g.traverse();

    return 0;
}

#endif

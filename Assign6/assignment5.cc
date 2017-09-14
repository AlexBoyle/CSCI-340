
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

        binTree::binTree(){root = NULL;}
        void binTree::insert(int value){insert(root, value);}
        int binTree::height() const{return height(root);}
        unsigned binTree::size() const{return size(root);}
        void binTree::inorder(void(* f)(int)){inorder(root, f);}
        void binTree::preorder(void(* f)(int)){preorder(root, f);}
        void binTree::postorder(void(* f)(int)){postorder(root, f);}

	/*************************************************
	*void binTree::insert( Node*& node, int value)
	*
	*param: node - node to start on
	*	value - value to insert
	*
	*************************************************/
        void binTree::insert( Node*& node, int value){
		if(node == NULL)
			node = new Node(value);
		else
			if(height(node->l) <= height(node->r))
				insert(node->l, value);
			else
				insert(node->r, value);
	}
	/*************************************************
        *int binTree::height( Node* n) const{
        *
        *param: n - node to start checking height at
        *
	*return: heignt in int
        *************************************************/
        int binTree::height( Node* n) const{
		if (n == NULL)
			return -1;
		else
		{
			int lDepth = height(n->l);
			int rDepth = height(n->r);

			if (lDepth > rDepth)
				return(lDepth + 1);
			else
				return(rDepth + 1);

		}
	}
	/*************************************************
        * binTree::size( Node* n) const{
        *
        *param: n - node to check size of
        *
        *return: size in int
        *************************************************/
        unsigned binTree::size( Node* n) const{
		if(n != NULL){
			return size(n->l) + size(n->r) + 1;
		}
		return 0;
	}
	/*************************************************
        *void binTree::inorder( Node* n, void(* f)(int) ){
        *
        *param: n - node to start at
	*	f - function to visit node
        *
        *************************************************/
        void binTree::inorder( Node* n, void(* f)(int) ){
		if(n != NULL){
			inorder(n->l,f);
			f(n->v);
			inorder(n->r,f);
		}
	}
	/*************************************************
        *void binTree::preorder( Node* n, void(* f)(int) ){
        *
        *param: n - node to start at
        *       f - function to visit node
        *
        *************************************************/
        void binTree::preorder( Node* n, void(* f)(int) ){
		if(n != NULL){
                 	f(n->v);
			preorder(n->l,f);
                        preorder(n->r,f);
                }
	}
	/*************************************************
        *void binTree::postorder( Node* n, void(* f)(int) ){
        *
        *param: n - node to start at
        *       f - function to visit node
        *
        *************************************************/
        void binTree::postorder( Node* n, void(* f)(int) ){
		if(n != NULL){
                        postorder(n->l,f);
                        postorder(n->r,f);
			f(n->v);
                }
	}




void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

//#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif

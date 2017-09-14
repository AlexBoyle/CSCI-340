#include <iostream>
#include "assignment5.h"
#include "assignment6.h"

        /***********************************************
        *void BST::insert( int )
        *
        *param:	int - number being inserted
        *
        ***********************************************/
        void BST::insert( int n){insert(root, n);}

        /***********************************************
        * bool BST::search( int)
        *
        *param:	int - number  being searched for
        *
	*return: bool, true if found, false otherwise
        ***********************************************/
        bool BST::search( int n){return search(root, n);}

        /***********************************************
        * bool BST::remove( int)
        *
        *param: int - number being removed
        *
	*return: true if removed, false otherwise
        ***********************************************/
        bool BST::remove( int n){return remove(root, n);}

        /***********************************************
        * int BST::sumOfRange(int lower, const int upper)
        *
        *param:	int - lower bound
	*	int - upper bound
        *
	*return sum of the numbers between the bounds
        ***********************************************/
        int BST::sumOfRange(int lower, const int upper){return sumOfRange(root, lower, upper);}

	/***********************************************
	*void BST::insert( Node*&, int)
	*
	*param:	Node - node to start looking at
	*	int - number to insert into tree
	***********************************************/
        void BST::insert( Node*& n, int num){
		if(n == NULL)
			n = new Node(num);
		else {
			if(num < n->v)
				insert(n->l, num);
			else
				insert(n->r, num);
		}
	}

	/***********************************************
        * bool BST::search( Node*&, int)
        *
        *param:	Node - node to start search at
	*	int - number being searched for
        *
	*return true if found, false otherwise
        ***********************************************/
        bool BST::search( Node*& n, int num){
		if(n == NULL)
			return false;
		else if(n->v == num)
			return true;
		else if(n->l != NULL && n->v > num)
			return search(n->l, num);
		else if(n->r != NULL && n->v < num)
			return search(n->r, num);
		return false;
	}

	/***********************************************
        * bool BST::remove( Node*& , int)
        *
        *param:	Node - node to start looking at
	*	int - numbber to remove
        *
        ***********************************************/
        bool BST::remove( Node*& n, int num){
		if (n == NULL)
			return false;
		if(n->v > num)
			return remove(n->l, num);
		else if(n->v < num)
			return remove(n->r, num);
		else if(n->l != NULL && n->r != NULL){
			Node* temp = n->l;while(temp->r != NULL){temp = temp->r;}
			n->v = temp->v;
			remove(n->l, n->v);
		}else if(n->l == NULL && n->r == NULL){
			delete n;
			n = NULL;
		}else{
			Node* temp = n;
			n = n->r == NULL ? n->l : n->r;
			delete temp;
		}
		return true;
	}

        /***********************************************
        *int BST::sumOfRange(Node*& , const int, const int)
        *
        *param:	Node - node to start looking at
        *	int - lower bound
	*	int - upper bound
	*
	*return the sum of the numbers between upper and lower bound
        ***********************************************/
        int BST::sumOfRange(Node*& n, const int lower, const int upper){
		int value = 0;
		if(n->v > lower && n->v < upper)
			value = n->v;
		if(n->l != NULL)
			value += sumOfRange(n->l, lower, upper);
		if(n->r != NULL)
                        value += sumOfRange(n->r, lower, upper);
		return value;
	}


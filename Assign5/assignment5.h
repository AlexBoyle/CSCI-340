
#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
class BST;

class Node {
	Node (int va, Node* le = NULL, Node* ri = NULL){
                l = le;
                r = ri;
                v = va;
        }
	friend class binTree;
	private:
		Node* l;
		Node* r;
		int v;
	public:
};

class binTree {
    public:
        binTree();
        virtual void insert( int );
        int height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;

    private:
        void insert( Node*&, int );
        int height( Node* ) const;
        unsigned size( Node* ) const;
	void inorder( Node*, void(*)(int) );
	void preorder( Node*, void(*)(int) );
	void postorder( Node*, void(*)(int) );
};

#endif

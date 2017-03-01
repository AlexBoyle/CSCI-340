//Alex Boyle
//Z1759628
//Assignment 4
//2/27/2017

#include <iomanip>
#include <iostream>
#include <string>
#include "assignment4.h"

using std::setw;
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::endl;

/*
bool Stack::empty() const

return:	True if stack is empty, else false
*/
bool Stack::empty() const {
	return (q1.empty() && q2.empty());
}

/*
int Stack::size() const

return:	The number(int) of elements in the stack
*/
int Stack::size() const {
	return q1.size() + q2.size();
}

/*
int Stack::top();

return: The element on top of the stack
*/
int Stack::top() {
	if(!q1.empty())
		return q1.back();
	else
		return q2.back();
}

/*
void Stack::push(const int& val)

param:	const int& val - value being pushed into stack
*/
void Stack::push(const int& val) {
	q1.push(val);
}

/*
void Stack::pop()

This method removes the top element on the stack
*/
void Stack::pop() {
	while(q1.size() > 1){
		q2.push(q1.front());
		q1.pop();
	}
	q1 = q2;
	while(!q2.empty()){
		q2.pop();
	}
}

int main() {
    Stack s;
    string op;
    int val = 0;
 
   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            s.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            s.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << s.size() << setw(5) << s.top() << endl;
        cin >> op;
    }

    while ( !s.empty() )
        s.pop();
    cout << "End -- size of Stack is: " << s.size() << endl;

    return 0;
}

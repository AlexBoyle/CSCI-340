/*
Alex Boyle
Assignment 8
z1759628
*/

#include <fstream>
#include<iomanip>
#include<iostream>
#include "assignment8.h"
using namespace std;

// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}


/******************************
*:HT(int size = 11)
*
*param:	int - size of the hashtable
*
*constructor
*******************************/
HT::HT(int size = 11){
	table_size = size;
	item_count = 0;
	hTable = new vector<Entry>(size);
}
/******************************
*~HT()
*
*Destructor
********************************/
HT::~HT(){
	delete hTable;
}
/***********************************
*HT::insert(const Entry& thing)
*
*param: Entry - object being inserted
******************************************/
bool HT::insert(const Entry& thing){
	if(item_count < table_size){
		item_count++;
		int hash = hashing(thing.key);
		for(int i = 0; i < table_size; i ++){
			if(hTable->at((i + hash)%table_size).key == "---"){
				hTable->at((i + hash)%table_size) = thing;
				break;
			}
		}
	}
	return false;
}
/****************************
*search(const std::string& str)
*
*param: string - kay to search hashtable for
*****************************/
int HT::search(const std::string& str){
	int index = -1;
	int hash = hashing(str);
	for(int i = 0; i < table_size; i ++){
		if(hTable->at((i + hash)%table_size).key == str){
			index = (i + hash) % table_size;
			break;
		}
	}
	return index;
}
/********************************
*remove(const std::string& str)
*
*param: string - key to remove
*********************************/
bool HT::remove(const std::string& str){
	int index = search(str);
	if(index < 0)
		return false;
	else {
		Entry* e = new Entry();
		hTable->at(index) = *e;
		return true;
	}
}
/*****************************
*print()
*
*Print hashtable
*****************************/
void HT::print(){
	cout << "\n----Hash Table-----\n";
	for(vector<Entry>::iterator i = hTable->begin(); i != hTable->end(); i++){
		if(i->key != "---")
			cout << setw(2) << right << i - hTable->begin() << ": " << i->key << " " << i->description << '\n';
	}
	cout << "-------------------\n\n";
}
/*****************************
* get_entry(const std::string& str)
*
*param: string - line to be decoded to an entry
*
*return: Entry
********************************/
Entry* get_entry(const std::string& str){
	Entry* e = new Entry();
	e->key = str.substr(str.find(':') + 1,3);
	e->description = str.substr(str.find(':') + 5);
	return e;
}
/************************************
*get_key(const std::string& str)
*
*param: string - string to be decoded
*
*return: String
**************************************/
string get_key(const std::string& str){
	return str.substr(str.find(':') + 1);
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}

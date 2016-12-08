#pragma once
#include <String>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::ostream;

struct Link {  	string strName; Link* next; };  

class List
{
public:
  // Overloaded Constructor that names the List - Only constructor I want people to use   
List(string NameOfList);  // Don't be confused - North or South is the List Names  

~List(void);    
  
int Count(void);     // Gives the number of items in the list  
 
bool isIn(string strName);     // Tells me if an item is in the list   

string name(void);    // Gives the name of the list (will return North or South)
 
friend std::ostream &operator<<(ostream &stream, List &ob);   // Overloaded streaming operator   

// This is how you add a Link (Chicken, Farmer, Grain, or Fox) to the list   
// If you add something other than the listed, I'll return false and NOT add it to the List
bool Add(string ObjectName);      

// This is how you remove a Link from the List (Again Chicken, Farmer, Grain, or Fox Only)
bool Remove(string ObjectName);    

// Clear the List   
void Clear(void);  

// This is needed for the overloaded << operator 
   Link* getFirst(void); 


private:    
	List(void); // standard constructor here telling all to NOT use it - Name the List
string strName;    // Name of the list (North or South)
  Link *mpFirst;  
};  



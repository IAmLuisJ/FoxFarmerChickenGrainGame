#include "stdafx.h"
#include "List.h"
#include <String>
#include <iostream>

using std::string;
using std::endl;

List::List(void)
{
}

List::List(string bank)
{
	strName = bank;
}


List::~List(void)
{
	Clear();
}

string List::name(void)
{
	return strName;
}

Link* List::getFirst(void)
{
	return mpFirst;
}

int List::Count(void)
{
	int count = 0;
	Link* pLink = mpFirst;
	while (pLink != NULL)
	{
		count++;
		pLink = pLink->next;
			
	}
	return count;
}

bool List::isIn(string element)
{
	bool confirmed = false;
	Link* pLink = mpFirst;
	
	while (pLink != NULL)
	{
	
		if(pLink->strName == element)
		{ 
			confirmed = true;
			return true;
		}
		pLink = pLink->next;
	}
	if(pLink = NULL)
		{
			cout << "Item was not in the list";
			return false;
		}
	
	//if item is in the list return true, if not return false
	return confirmed;
}

// This is how you add a Link (Chicken, Farmer, Grain, or Fox) to the list   
// If you add something other than the listed, I'll return false and NOT add it to the List
bool List::Add(string element)
{
	bool bReturnValue = true;
	Link* pNewLink = 0;
	pNewLink = new Link;      // Get a new MyList object
	if( pNewLink == NULL )
		bReturnValue = false;
	pNewLink->strName = element; // Assign the data value
    pNewLink->next = mpFirst;  // it points to the next link
    mpFirst = pNewLink;         // now the first points to this item

	return bReturnValue;
}

bool List::Remove(string element)
{
//if item is in list return true;
	bool removedSuccess = false;
	
	Link* pLink = mpFirst; 
	Link* previousLink = mpFirst;
	if(pLink->strName == element)
	{
		mpFirst = pLink->next;
		delete pLink;
		return true;
	}

	while (pLink != NULL)
	{
		previousLink = pLink;
		pLink = pLink->next;
		if(pLink->strName == element)
		{ 
			previousLink->next = pLink->next;
			delete pLink;
			return true;
			pLink = NULL;
		}
		if(pLink->next == NULL)
		{
			cout << "Item was not in the list";
			return false;
		}
	}
	return removedSuccess;
}



ostream &operator<<(ostream &stream, List &ob)
{
	stream << ob.name().c_str() << endl;

	Link* pLink = ob.getFirst();
	while (pLink != NULL)
	{
            stream << pLink->strName.c_str() << endl;
			pLink = pLink->next;
	}
	return stream;
}

void List::Clear(void)
{
	Link* pLink = mpFirst;
	while (pLink != NULL)
	{
			mpFirst = pLink->next;
			delete pLink;
			pLink = mpFirst;
	}
}
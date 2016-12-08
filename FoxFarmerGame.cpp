// FoxFarmerGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

//Declaration
void testListObject(List &daList);
void PrintGameExplanation();
void initializeGame(List &north, List &south);
void ChangeDirection(List &north, List &south);
bool CheckWinLose(List &north, List &south);

int _tmain(int argc, _TCHAR* argv[])
{
	List North("North Bank:");
	List South("South Bank:");
	string item;
	bool restart = true;

	initializeGame(North, South);
	//testListObject(South);
	while (true)
	{
		while (restart){
		cout << "             Welcome to Fox, Chicken, and Grain" << endl;
		cout << endl;
		cout << " Program written by Luis Juarez" << endl;
		cout << endl;
	    bool viableMove = false;
		PrintGameExplanation();
		cout << North << endl;
		cout << South << endl;
		cout <<"The north bank has " << North.Count()<<" items" << endl;
		cout << "The south bank has " << South.Count()<<" items" << endl;
		cout << "Which item do you want to move?" << endl;
		cout << "Options: Chicken Fox Grain Nothing" << endl;
		cin >> item;
		if(item == "Nothing")
		{
			ChangeDirection(North, South);
		}

		else if(North.isIn("Farmer"))//checks farmer location and moves accordingly
		{
			viableMove = North.isIn(item);//if item exists returns true
			cout << endl;
			
			if(viableMove == true) // if item has been confirmed, remove from north and add to south
			{
			North.Remove(item);
			South.Add(item);
			ChangeDirection(North, South);
			system("cls");
			}
		}
		else if(South.isIn("Farmer")) //checks farmer location and moves accordingly
		{
			viableMove = South.isIn(item);
			cout << endl;
			if(viableMove == true)
			{
				South.Remove(item);
				North.Add(item);
				ChangeDirection(North, South);
				system("cls");
			}
		}
				restart = CheckWinLose(North, South);	//check for win/lose - returns bool
	} // loops game
		system("cls");
cout << "Game Over! Press any button to play again" << endl; //shows for both win/lose
system("pause");
restart = true;
	initializeGame(North, South);
		} // restarts game
	system("pause");
	system("cls");
	return 0;
}

void testListObject(List &testlist)
{
	testlist.Add("Grain");
	testlist.Add("Farmer");
	testlist.Add("Fox");
	testlist.Add("Chicken");
	cout << testlist;
	cout << "Number of items in the List:"<< testlist.Count() << endl;
	
	if(testlist.isIn("Fox"))
	{
		cout << "Fox is in the list" << endl;
	}
	cout << endl;
	cout << "Removing Grain and Farmer" << endl << endl;
	testlist.Remove("Fox");
	if(!testlist.isIn("Fox"))
	{
		cout << "Fox is NOT in the list" << endl;
	}
	testlist.Remove("Farmer");
	cout << testlist;
	cout << "Number of items in the List:"<< testlist.Count() << endl;
	testlist.Remove("fake");
}

void PrintGameExplanation()
{
	cout << "You have a boat and need to take a fox, a chicken and some grain across a river.";
	cout << "The boat will only hold you and one other thing." << endl;
	cout << "If you leave the chicken alone with the corn, the chicken will eat the corn." << endl;
	cout << "If you leave the fox alone with the chicken, the chicken's in big trouble." << endl;
	//cout << endl;
	cout << "Help the farmer by entering the name of what you want him to carry" << endl;
	cout << "on his next trip to the opposite bank. If you want the farmer to" << endl;
	cout << "cross the river without carrying anything, enter 'nothing' into the prompt" << endl;
	cout << endl;
}

void initializeGame(List &newNorth, List &newSouth) {
	newNorth.Clear();
	newSouth.Clear();
	newNorth.Add("Farmer");
	newNorth.Add("Fox");
	newNorth.Add("Chicken");
	newNorth.Add("Grain");
}

bool CheckWinLose(List &newNorth, List &newSouth)
{
	if(newNorth.isIn("Fox") && newNorth.isIn("Chicken") && newSouth.isIn("Farmer"))
	{
		return false;
	}
	if(newSouth.isIn("Fox") && newSouth.isIn("Chicken") && newNorth.isIn("Farmer"))
	{
		return false;
	}
	if(newNorth.isIn("Chicken") && newNorth.isIn("Grain") && newSouth.isIn("Farmer"))
	{return false;}
	if(newSouth.isIn("Chicken") && newSouth.isIn("Grain") && newNorth.isIn("Farmer"))
	{return false;}
	if (newSouth.Count() == 4)
	{return false;}
	
	return true;
}

void ChangeDirection(List &newNorth, List &newSouth)
{
	if (newNorth.isIn("Farmer"))
	{
		newNorth.Remove("Farmer");
		newSouth.Add("Farmer");
	}
	else if (newSouth.isIn("Farmer"))
	{
		newSouth.Remove("Farmer");
		newNorth.Add("Farmer");
	}
}


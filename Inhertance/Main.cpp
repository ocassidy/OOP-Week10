/*
* Main.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date: 20/11/2017
* Description: Code to demonstrate polymorphism - start code
*
* Copyright notice
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Publisher.h"
#include "Author.h"
#include "PhysicalBook.h"
#include "EBook.h"

using namespace std;

int main() {

	Author bjarne{ "Bjarne", "Stroustrup" };
	Book myBook{"Programming principles and practice using C++", bjarne, "Addison Wesley", "2343242", bookGenre::Reference, 59.99f};
	
	//cout << myBook.ToString();

	Author aaron{ "Aaron ", "Franklin" };
	PhysicalBook myPB{ "Franklin Barbecue (A Meatsmoking Manifesto)", aaron, "Ten Speed Press", "978-1607747208", bookGenre::Cuisine, 17.46f, 0.8f, 21.0f, 26.1f, 2.6f };

	EBook myEB{ "Franklin Barbecue (A Meatsmoking Manifesto)", aaron, "Ten Speed Press", "978-1607747208", bookGenre::Cuisine, 17.46f, "Kindle Edition", 63145.0f, "English", true, true  };

	myPB.SetTitle("hello sailor");

	//cout << myPB.ToString();
	//cout << myEB.ToString();

	Book *bookPtr{ nullptr };
	bookPtr = &myBook;
	cout << "Calling toString using base book pointer on a book object" << endl << endl;
	cout << bookPtr->ToString();

	PhysicalBook *pBookPtr{ nullptr };
	pBookPtr = &myPB;
	cout << "Calling toString using base book pointer on a Physical Book object" << endl << endl;
	cout << pBookPtr->ToString();

	bookPtr = &myPB;
	cout << "Calling toString using base book pointer on a derived physical book object" << endl << endl;
	cout << bookPtr->ToString();

	bookPtr = nullptr;
	pBookPtr = nullptr;

	return 0;
}
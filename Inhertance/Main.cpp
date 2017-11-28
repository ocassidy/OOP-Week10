#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Book.h"
#include "Publisher.h"
#include "Author.h"
#include "PhysicalBook.h"
#include "EBook.h"


void WriteFile();
void ReadFile();

int main() {

	WriteFile();
	ReadFile();

	return 0;
}

void WriteFile() {

	Author bjarne{ "Bjarne", "Stroustrup" };
	Book myBook{ "Programming principles and practice using C++", bjarne, "Addison Wesley", "2343242", bookGenre::Reference, 59.99f };

	//cout << myBook.ToString();

	Author aaron{ "Aaron ", "Franklin" };
	PhysicalBook myPB{ "Franklin Barbecue (A Meatsmoking Manifesto)", aaron, "Ten Speed Press", "978-1607747208", bookGenre::Cuisine, 17.46f, 0.8f, 21.0f, 26.1f, 2.6f };

	EBook myEB{ "Franklin Barbecue (A Meatsmoking Manifesto)", aaron, "Ten Speed Press", "978-1607747208", bookGenre::Cuisine, 17.46f, "Kindle Edition", 63145.0f, "English", true, true };

	myPB.SetTitle("hello sailor");

	//cout << myPB.ToString();
	//cout << myEB.ToString();

	/*Book *bookPtr{ nullptr };
	bookPtr = &myBook;
	std::cout << "Calling toString using base book pointer on a book object" << endl << endl;
	std::cout << bookPtr->ToString();

	PhysicalBook *pBookPtr{ nullptr };
	pBookPtr = &myPB;
	std::cout << "Calling toString using base book pointer on a Physical Book object" << endl << endl;
	std::cout << pBookPtr->ToString();

	bookPtr = &myPB;
	std::cout << "Calling toString using base book pointer on a derived physical book object" << endl << endl;
	std::cout << bookPtr->ToString();

	bookPtr = nullptr;
	pBookPtr = nullptr;*/

	std::ofstream outFile{};

	outFile.open("data.txt", std::ios::out | std::ios::app);

	if (!outFile) {
		std::cerr << "File could not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}

	outFile << myBook.ToString() << std::endl;
	outFile << myPB.ToString() << std::endl;
	outFile << myEB.ToString() << std::endl;

	outFile.close();

}

void ReadFile() {
	std::ifstream inFile("data.txt", std::ios::in);

	if (!inFile) {
		std::cerr << "File could not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string temp;
	std::cout << "Enter book contents" << std::endl;
	inFile >> temp;

	inFile.close();
}
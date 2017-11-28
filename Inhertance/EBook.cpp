#include "EBook.h"


EBook::EBook(){}


EBook::~EBook(){}

EBook::EBook(std::string title, Author author, std::string publisher, std::string isbn, bookGenre genre, float price, 
	std::string format, float filesize, std::string language, bool typeSetting, bool screenReaderSupport) : Book(title, author, publisher, isbn, genre,
		price), fileSize_{ filesize }, language_{ language }, enhancedTypeSetting_{ typeSetting }, screenReaderSupport_{ screenReaderSupport } {

}

std::string EBook::ToString() {
	std::ostringstream output;
	std::cout << "Details of the EBook are: " << std::endl;
	output << Book::ToString() << ", " << fileSize_ << ", " << language_ << ", " << enhancedTypeSetting_ << ", " << screenReaderSupport_ << std::endl << std::endl;

	return output.str();
}
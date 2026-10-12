#include <iostream>
#include <sstream>

#include "book.h"

// Default constructor
Book::Book() : title(""), author(""), isbn(""){}

// Parameterized constructor
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn){}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Setters
void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { this->isAvailable = available; }
void Book::setBorrowerId(const string& id) { this->borrowerId = id; }

// Methods
// Check out book
void Book::checkOut(const string& borrowerId){
    setAvailability(false);
    setBorrowerId(borrowerId);
}

// Return a book
void Book::returnBook(){
    setAvailability(true);
    setBorrowerId("");
}

// Display book information
string Book::toString() const{
    string result =  "Title: " + title + "\nAuthor: " + author + "\nIBSN: " + isbn + "\n Availability: ";
    if (isAvailable){
        result += "true";
    } else {
        result += "false\n Borrower: "+ borrowerId;
    }
    return result;
}

// Format for file storage
string Book::toFileFormat() const{
    string result =  title + "|" + author + "|" + isbn + "|";
    if (isAvailable){
        result += isAvailable;
    } else {
        result += isAvailable + "|" + borrowerId;
    }
    return result;
}

// Parse from file format
void Book::fromFileFormat(const string& line){
    stringstream ss(line);
    string isAvailableStr;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, isAvailableStr, '|');
    getline(ss, borrowerId);

    isAvailable = (isAvailableStr == "1");
}
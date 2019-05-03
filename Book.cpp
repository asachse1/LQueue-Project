#include "Book.h"

Book::Book(){

  m_title = "NULL";
  m_author = "NULL";
  m_rank = 0;
  m_price = 0;
}

Book::Book(string title, string author, int rank, double price){

  m_title = title;
  m_author = author;
  m_rank = rank;
  m_price = price;
}

string Book::getTitle() const{

  return m_title;
  
}

string Book::getAuthor() const{
  return m_author;
}

int Book::getRank() const{
  return m_rank;
}

double Book::getPrice() const{
  return m_price;
}

void Book::setTitle (string title){
  m_title = title;
}

void Book::setAuthor(string author){
  m_author = author;
}

void Book:: setRank(int rank){
  m_rank = rank;
}

void Book::setPrice(double price){
  m_price = price;
}

ostream& operator<< (ostream& output, Book& myBook){
  //Set Precision for moneyx
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  output << setw(40) << myBook.getTitle() << setw(25) <<  myBook.getAuthor() << setw(10) << "($"
	 << myBook.getPrice() << ')';
  return output;
}

bool operator< (Book const& lhs, Book const & rhs){
  return lhs.getPrice() < rhs.getPrice();
}


#include "EReader.h"



EReader::EReader(){

  m_bookCatalog.at(0) = NULL;
}

EReader::EReader(string filename){

  LoadCatalog(filename);
  
}

EReader::~EReader(){
  
  for (int i = 0; i < int(m_bookCatalog.size()); i++){
    delete m_bookCatalog[i];
  }
}

void EReader::LoadCatalog(string filename){
  ifstream inputStream;
  string title;
  string author;
  int rank;
  double price;

  inputStream.open(filename);

  if(inputStream.is_open()){
    //while stuff to read in
    while(getline(inputStream,title,',')){
      getline(inputStream,author,',');
      inputStream >> rank;
      //Ignoring comma
      if (inputStream.peek() == ','){
	inputStream.ignore();
      }
      inputStream >> price;
      //create new book
      Book *newBook = new Book(title, author, rank, price);

      m_bookCatalog.push_back(newBook);

      if (inputStream.peek() == '\n'){
	inputStream.ignore();
      }
    }
  }
}


void EReader::MainMenu(){
  int userInput = 0;
  while (userInput != 5){
    do{
      cout << "What would you like to do?" << endl
	   << "1. Display All Books" << endl
	   << "2. Add Book to Readlist" << endl
	   << "3. Display Readlist" << endl
	   << "4. Sort Readlist by Price" << endl
	   << "5. Quit" << endl;
      cin >> userInput; 
    } while(userInput < 1 and userInput > 5);
    switch(userInput){
    case DISPLAY_BOOKS:
      DisplayBooks();
      break;
    case ADD_BOOK:
      AddBook();
      break;
    case DISPLAY_READLIST:
      DisplayReadlist();
      break;
    case SORT:
      SortReadlist();
      break;
    default:
      break;
    }
  }   
}

void EReader::DisplayBooks(){

  for (int i = 0; i < int(m_bookCatalog.size()); i++){
    cout << i+1 << '.' << *m_bookCatalog[i] << endl;
  }
}

void EReader::AddBook(){
  int userInput = 0;
  do{
    //Displaying
    DisplayBooks();
    cout << "Enter the number of the book you would like to add:" << endl;
    cin >> userInput;
  }while (userInput < 1 or userInput > int(m_bookCatalog.size()));
  //Inserting
  m_readList.Push(*m_bookCatalog[userInput-1], true);
}

void EReader::DisplayReadlist(){
  if (m_readList.GetSize() != 0)
    cout << m_readList << endl;
  
}

void EReader::SortReadlist(){
  bool wasSorted = false;
  int counter = 0;
  while (counter < m_readList.GetSize()-1){

    if (m_readList[counter] < m_readList[counter+1]){
      m_readList.Swap(counter+1);
      counter = -1;
    }
    counter++;
    
  }
  
}

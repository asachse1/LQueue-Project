#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template <class T>
class Node {
public:
  Node( const T& data ); //Node Constructor
  T& GetData(); //Node Data Getter
  void SetData( const T& data ); //Node Data Setter
  Node<T>* GetNext(); //Node m_next getter
  void SetNext( Node<T>* next ); //Node m_next setter
private:
  T m_data; //Holds templated data
  Node<T>* m_next; //Pointer to next node
};

template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = nullptr;
}

template <class T>
T& Node<T>::GetData() {
   return m_data;
}

template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue<T>& operator= (const Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: If the bool = false, adds to front else adds a new node to the
  //                 end of the lqueue.
  void Push(const T&, bool);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front 
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  int GetSize();
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  void Clear();
  // Name: TestHeadTail() (Optional test function)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns the value of the head and the tail (used for main below)
  void TestHeadTail();
  // Name: operator<< (Overloaded << operator)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns an ostream with the data from each node on different line
  template <class U>
  friend ostream& operator<<(ostream& output, const Lqueue<U>&);
  //Name: Overloaded [] operator
  //Precondition: Existing Lqueue
  //Postcondition: Returns object from Lqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from Lqueue
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};
//*****************************************************************
//Implement Lqueue here
// Name: Lqueue() (Linked List Queue) - Default Constructor
// Desc: Used to build a new linked queue (as a linked list)
// Preconditions: None
// Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
template <class T>
Lqueue<T>::Lqueue(){

  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
  
}
// Name: ~Lqueue() - Destructor
// Desc: Used to destruct a Lqueue
// Preconditions: There is an existing lqueue with at least one node
// Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
//                 to have no memory leaks!
template <class T>
Lqueue<T>::~Lqueue(){

  Clear();
  
}
// Name: Lqueue (Copy Constructor)
// Preconditions: Creates a copy of existing LQueue
//                Requires a Lqueue
// Postconditions: Copy of existing Lqueue
template <class T>
Lqueue<T>::Lqueue(const Lqueue& oldObj){
  Node<T> *tempObj = oldObj.m_head;
  Node<T> *prevObj;
  Node<T> *newObj;
  //Making head/tail
  newObj = new Node<T>(tempObj -> GetData());
  m_head = newObj;
  m_tail = newObj;
  
  //Iterate
  prevObj = newObj;
  tempObj = tempObj -> GetNext();

  while (tempObj != nullptr){
    newObj = new Node<T>(tempObj -> GetData());
    
    //links last new object to new one and moves tail
    prevObj -> SetNext(newObj);
    m_tail = newObj;
    
    //moves prev up before next iteration
    prevObj = newObj;
    tempObj = tempObj -> GetNext();
  }
  tempObj = nullptr;
  prevObj = nullptr;
  newObj = nullptr;
  
    
}
// Name: operator= (Overloaded Assignment Operator)
// Preconditions: Copies an Lqueue into an existing Lqueue
//                Requires a Lqueue
// Postconditions: Copy of existing Lqueue
template <class T>
Lqueue<T>& Lqueue<T>::operator= (const Lqueue& oldObj){
  Node<T> *tempObj = oldObj.m_head;
  Node<T> *prevObj;
  Node<T> *newObj;
  //Clear it all
  Clear();
  //Making head/tail
  newObj = new Node<T>(tempObj -> GetData());
  m_head = newObj;
  m_tail = newObj;

  //Iterate
  prevObj = newObj;
  tempObj = tempObj -> GetNext();

  while (tempObj != nullptr){
    newObj = new Node<T>(tempObj -> GetData());

    //links last new object to new one and moves tail
    prevObj -> SetNext(newObj);
    m_tail = newObj;

    //moves prev up before next iteration
    prevObj = newObj;
    tempObj = tempObj -> GetNext();
  }
  tempObj = nullptr;
  prevObj = nullptr;
  newObj = nullptr;


  return *this;
}
// Name: Push
// Preconditions: Takes in data. Creates new node.
//                Requires a Lqueue
// Postconditions: If the bool = false, adds to front else adds a new node to the
//                 end of the lqueue.
template <class T>
void Lqueue<T>::Push(const T& newData, bool addEnd){
  Node<T> *newObj, *tempObj;
  
  newObj = new Node<T>(newData);
  m_size++;
  //If empty list
  if (m_head == nullptr){
    m_head = newObj;
    m_tail = newObj;
  }
  //Add to Start
  else if (addEnd == false){    
    tempObj = m_head;
    m_head = newObj;
    m_head -> SetNext(tempObj);    
  }
  //Add to End
  else if(addEnd == true){
    tempObj = m_tail;
    tempObj -> SetNext(newObj);
    m_tail = newObj;
    newObj -> SetNext(nullptr);
  }
  
  
  
}
// Name: Pop
// Preconditions: Lqueue with at least one node.
// Postconditions: Removes first node in the lqueue, returns data from first node.
template <class T>
T Lqueue<T>::Pop(){
  Node<T> *tempObj, *targetObj;
  T data;
  targetObj = m_head;
  tempObj = m_head;
  //if next isn't end
  if (m_head -> GetNext() != nullptr){
    tempObj = m_head -> GetNext();
  }
  m_head  = tempObj;
  if (targetObj != nullptr){
    //Extracting Data
    data = targetObj -> GetData();
    //Cleanup
    delete targetObj;
    targetObj = nullptr;
    tempObj = nullptr;
    m_size--;
  }
  return data;
}

// Name: Display
// Preconditions: Outputs the lqueue.
// Postconditions: Displays the data in each node of lqueue
template <class T>
void Lqueue<T>::Display(){
  Node<T> *tempObj = m_head;
  int ctr = 1;
  //while next isnt the end
  while (tempObj -> GetNext() != nullptr){
    cout << ctr << "." << setw(20) << tempObj -> GetData() << endl;
    ctr++;
    tempObj = tempObj -> GetNext();
  }
  
  cout << ctr << "." << setw(20) << tempObj -> GetData() << endl;
  
}
// Name: Front
// Preconditions: Requires a populated lqueue
// Postconditions: Returns whatever data is in front
template <class T>
T Lqueue<T>::Front(){
  T data;

  data = m_head -> GetData();
  return data;
  
}
// Name: IsEmpty
// Preconditions: Requires a lqueue
// Postconditions: Returns if the lqueue is empty.
template <class T>
bool Lqueue<T>::IsEmpty(){

  if (m_head == nullptr and m_tail == nullptr){
    return true;
  }
  return false;
  
}
// Name: GetSize
// Preconditions: Requires a lqueue
// Postconditions: Returns m_size
template <class T>
int Lqueue<T>::GetSize(){

  return m_size;
  
}
// Name: Swap(int)
// Preconditions: Requires a lqueue
// Postconditions: Swaps the nodes at the index with the node prior to it.
template <class T>
void Lqueue<T>::Swap(int index){
  int ctr = 0;
  Node<T> *tempObj = m_head;
  Node<T> *prevObj = m_head;
  Node<T> *firstObj = m_head;
  while (ctr != index){
    tempObj = tempObj -> GetNext();
    //don't iterate prev first time
    if (ctr != 0)
      prevObj = prevObj -> GetNext();
    //don't iterate first the first or second time
    if (ctr != 0 and ctr != 1)
      firstObj = firstObj -> GetNext();
    ctr++;
  }
  //List empty
  if (m_head == nullptr){
    cout << "Cannot swap, list is empty" << endl;
  }
  //Swap beginning
  else if (ctr == 0){
    cout << "Cannot swap the first index" << endl;
  }
  //swap tail with head
  else if (prevObj == m_head and tempObj == m_tail){
    tempObj -> SetNext(m_head);
    prevObj -> SetNext(nullptr);
    m_head = tempObj;
    m_tail = prevObj;
  }
  //swapping head with next
  else if (prevObj == m_head and tempObj != m_tail){
    prevObj -> SetNext(tempObj -> GetNext());
    tempObj -> SetNext(prevObj);
    m_head = tempObj;
  }
  //swapping tail with previous one
  else if (prevObj != m_head and tempObj == m_tail){
    prevObj -> SetNext(nullptr);
    tempObj -> SetNext(prevObj);
    firstObj -> SetNext(tempObj);
    m_tail = prevObj;
  }
  //middle swapping
  else{
    firstObj -> SetNext(tempObj);
    prevObj -> SetNext(tempObj -> GetNext());
    tempObj -> SetNext(prevObj);
  }
  
  
  
}
// Name: Clear
// Preconditions: Requires a lqueue
// Postconditions: Removes all nodes in a lqueue
template <class T>
void Lqueue<T>::Clear(){
  Node<T> *tempObj = m_head;
  Node<T> *prevObj = m_head;
  //while not the end and not empty
  while(m_head != m_tail and (m_head != nullptr and m_tail != nullptr)){
    prevObj = tempObj;
    //if next isnt the end
    if (tempObj -> GetNext() != nullptr){
      tempObj = tempObj -> GetNext();
    }
    m_head = tempObj;
    delete prevObj;
  }
  //if empty
  if (m_head == nullptr){
    cout << "Queue Already Empty" << endl;
  }
  //delete the end
  else{
    delete m_tail;
  }
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}
// Name: TestHeadTail() (Optional test function)
// Preconditions: Requires a lqueue
// Postconditions: Returns the value of the head and the tail (used for main below)
template <class T>
void Lqueue<T>::TestHeadTail(){
  
  cout << "Head: " << m_head -> GetData() << "Tail: " << m_tail -> GetData() << endl;

  
  
}
// Name: operator<< (Overloaded << operator)
// Preconditions: Requires a lqueue
// Postconditions: Returns an ostream with the data from each node on different line
template <class U>
ostream& operator<<(ostream& output, const Lqueue<U> &myQueue){
  Node<U> *currObj = myQueue.m_head;
  int nodeNumber = 0;
  bool endOfQueue = false;
  while (endOfQueue == false){
    
    nodeNumber++;
    
    output << nodeNumber << "." << setw(20) << currObj -> GetData() << endl;
    
    if (currObj == myQueue.m_tail)
      endOfQueue = true;
    else
      currObj = currObj -> GetNext();
  }
  return output;
}
//Name: Overloaded [] operator
//Precondition: Existing Lqueue
//Postcondition: Returns object from Lqueue using []
template <class T>
T& Lqueue<T>::operator[] (int x){
  Node<T> *currObj;
  int ctr = 0;
  currObj = m_head;
  while (ctr != x){
    ctr++;
    currObj = currObj -> GetNext();
  }
  return currObj -> GetData();
}

//******************************************************************
// To test just Lqueue follow these instructions:
//   1.  mv Lqueue.h Lqueue.cpp
//   2.  Uncomment out int main below
//   3.  make Lqueue
//   4.  ./Lqueue (try valgrind too!)
/*

int main () {
  //Test 1 - Default Constructor and Push
  cout << "Test 1 - Default Constructor and Push Running" << endl;
  //Test Default Constructor
  Lqueue <int> newLQ1;
  //Push 4 nodes into Lqueue
  newLQ1.Push(10, 1);
  newLQ1.Push(11, 1);
  newLQ1.Push(12, 1);
  newLQ1.Push(13, 1);
  cout << endl;
  
  //Test 2 - Copy Constructor and Assignment Operator
  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;

  //Test Copy constructor
  Lqueue <int> newLQ2(newLQ1);
  //Test Overloaded Assignment Operator
  Lqueue <int> newLQ3;
  newLQ3 = newLQ1;
  cout << endl;

  //Test 3 - Test Display and Overloaded <<
  cout << "Test 3 - Display and Overloaded << Running" << endl;
  cout << "newLQ1" << endl;
  newLQ1.Display();
  cout << "newLQ2" << endl;
  newLQ2.Display();
  cout << "newLQ3" << endl;
  newLQ3.Display();
  cout << "newLQ1" << endl;
  cout << newLQ1;
  
  cout << "newLQ2" << endl;
  cout << newLQ2;
  cout << "newLQ3" << endl;
  cout << newLQ3;
  cout << endl;
    
  //Test 4 - Test Front and Pop
  cout << "Test 4 - Front and Pop Running" << endl;
  //Test Front()
  cout << "Testing Front - Output 10" << endl;
  cout << newLQ1.Front() << endl;
  //Test Pop with Display of Pop
  cout << "Popping one node and displaying it" << endl;
  cout << newLQ1.Pop() << endl;
  //Test Pop with Display of Pop
  cout << "Popping one node and displaying it" << endl;
  cout << newLQ1.Pop() << endl;
  cout << endl;
  
  //Test 5 - Test GetSize and Clear
  cout << "Test 5 - GetSize and Clear Running" << endl;
  //Test GetSize()
  cout << "Outputting the size" << endl;
  cout << newLQ1.GetSize() << endl;
  //Test Clear()
  cout << "Clearing all nodes" << endl;
  //newLQ1.Clear();
  cout << endl;

  newLQ2.Display();
  //Test 6 - Test Swap
  cout << "Test 6 - Swap Running" << endl;
  newLQ2.Swap(2);
  cout << "Swap 2 - Should display 10->12->11->13->END" << endl;
  newLQ2.Display();
  //Testing to make sure head and tail point at the correct node
  newLQ2.TestHeadTail();
  cout << "Should display head 10 and tail 13" << endl;
  cout << endl;

  
  return 0;
}



*/

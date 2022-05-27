#include <iostream>
using namespace std;

// Create Queue Room 
struct sembakoLine{
  // Queue Data Containing  
  string name;
  int age;

  // Pointer Next
  sembakoLine *next;
};

int maximalLineLength = 7;
sembakoLine *head, *tail, *cur, *del, *newNode;

// Count Queue Data
int countQueueData()
{
  if( head == NULL ){
    return 0;
  }else{
    int total = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      total++;
    }
    return total;
  }
}

// Boolean if Queue Data is Full
bool isFullQueueData()
{
  if( countQueueData() == maximalLineLength ){
    return true;
  }else{
    return false;
  }
}

// Boolean if Queue Data is Empty
bool isEmptyQueueData()
{
  if( countQueueData() == 0 ){
    return true;
  }else{
    return false;
  }
}

// Enqueue Data
void enqueueSembakoData( string name, int age ){

  if( isFullQueueData() ){
    cout << "Full Queue!!!" << endl;
  }else{
    
    if( isEmptyQueueData() ){
      head = new sembakoLine();
      head->name = name;
      head->age = age;
      head->next = NULL;
      tail = head;
    }else{
      newNode = new sembakoLine();
      newNode->name = name;
      newNode->age = age;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

// Dequeue Data
void dequeueSembakoData()
{
  if( isEmptyQueueData() ){
    cout << "Queue Data is Empty!!" << endl;
  }else{
    del = head;
    head = head->next;
    del->next = NULL;
    delete del;
  }
}

// Clear Queue Data
void clearQueueData()
{
  if( isEmptyQueueData() ){
    cout << "Queue Data is Empty!!" << endl;
  }else{
    cur = head;
    while( cur != NULL ){
      del = cur;
      cur = cur->next;
      del->next = NULL;
      delete del;
    }
    head = NULL;
    tail = NULL;
  }
}



// Display Queue Data
void displayQueueData()
{
  cout << "---------Queue Line----------" << "\n" << endl;
  if( isEmptyQueueData() ){
    cout << "Queue Data is Empty!!" << endl;
  }else{
    cout << "Total Queue Data : " << countQueueData() << endl;
    cur = head;
    int num = 1;
    while( num <= maximalLineLength ){
      
      if( cur != NULL ){
        cout << num << ". " << cur->name << " - " << cur->age << " years old." << endl;
        cur = cur->next;
      }else{
        cout << num << ". " << "(empty)" << endl;
      }

      num++;
    }

  }
  cout << "\n" << endl;
  
  

}


int main()
{

  enqueueSembakoData("Jack", 18);
  displayQueueData();

  enqueueSembakoData("Udin", 24);
  enqueueSembakoData("Sarah", 38);
  enqueueSembakoData("Budi", 27);
  enqueueSembakoData("Randi", 23);
  enqueueSembakoData("Matt", 19);
  displayQueueData();

  enqueueSembakoData("Nunu", 26);// Data queue mencapai batas nya
  displayQueueData();
  
  dequeueSembakoData();// Menghapus 1 data queue
  displayQueueData();

  dequeueSembakoData();// Menghapus 1 data queue
  displayQueueData();

  clearQueueData();// Menghapus semua data queue
  displayQueueData();

  

}
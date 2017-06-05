
#include <iostream> // Only for displaying copy constructor
#include<string>
#include <new>         // for bad_alloc
#include <fstream>     // for file I/O
#include <cstddef>     // for NULL
#include "ListException.h"
typedef int ListItemType;

using namespace std;

class List
{
    private:
      /** A node on the list. */
      struct ListNode
      {
         /** A data item on the list. */
         ListItemType item;
         /** Pointer to next node. */
         ListNode    *next;
      }; // end ListNode

      /** Number of items in list. */
      int       size;
      /** Pointer to linked list of items. */
      ListNode *head;

    public:

         // Constructors and destructor:

      /** Default constructor. */
      List();

      /** Copy constructor.
       * @param aList The list to copy. */
      List(const List& aList);

      /** Destructor. */
      ~List();


      // Operations

      bool isEmpty() const;
      int getLength() const;
      void insert(const ListItemType& newItem);
      void remove();
	  void print() ;
      void save( string fileName );
      void load( string fileName )
        throw( ListException );



};

List::List(): size( 0 ), head( NULL )
{
}//end default constructor

List::~List()
{
   while (!isEmpty())
      remove();
}  // end destructor

List::List(const List& aList)
   : size(aList.size)
{
   cout << "Copy Constructor" << endl;
   if ( aList.head == NULL )
   {
      head = NULL;  // original list is empty
   }
   else
   {
      // copy first node
      head = new ListNode;
      head->item = aList.head->item;

      // copy rest of list
      ListNode *newPtr = head;  // new list pointer
      // newPtr points to last node in new list
      // origPtr points to nodes in original list
      for (ListNode *origPtr = aList.head->next;
	       origPtr != NULL;
           origPtr = origPtr->next)
      {
         newPtr->next = new ListNode;
         newPtr = newPtr->next;
	     newPtr->item = origPtr->item;
      }  // end for

      newPtr->next = NULL;
   }  // end if
}  // end copy constructor


bool List::isEmpty() const
{
   return size == 0;
}  // end isEmpty

int List::getLength() const
{
   return size;
}  // end getLength


void List::insert(const ListItemType& newItem)
{
    int newLength = getLength() + 1;
    ListNode *newPtr = new ListNode;
    newPtr->item = newItem;
    size = newLength;
    newPtr->next = head;
    head = newPtr;
}
void List::remove()
{
    ListNode *cur;
     // delete the first node from the list
     cur = head;  // save pointer to node
     head = head->next;
     cur->next = NULL;
     delete cur;
     cur = NULL;

     size = getLength()-1;

}
//prints all items in the list.
void List::print()
{
    ListNode *cur;
    cur = head;

    while (cur != NULL){
        cout<<cur->item<<endl;
        cur = cur->next;
    }

}
void List::save( string fileName )
{
   ofstream outFile( fileName.c_str() );

   // traverse the list to the end, writing each item
   for (ListNode *cur = head; cur != NULL; cur = cur->next)
   {
      outFile << cur->item << endl;
   }
   outFile.close();
}
void List::load( string fileName ) throw( ListException )
{
   ifstream inFile( fileName.c_str() );
   ListItemType nextItem;
   ListNode *tail;

   while (!isEmpty())
   {
      remove();
   }
   size = 0;

   if ( inFile >> nextItem ) // Is file empty?
   {  // File not empty:
      try
      {
         head = new ListNode;
         // Add the first integer to the list.
         head->item = nextItem;
         head->next = NULL;
         tail = head;
         size = size + 1;

         // Add remaining integers to linked list.
         while ( inFile >> nextItem )
         {
            tail->next = new ListNode;
            tail = tail->next;
            tail->item = nextItem;
            tail->next = NULL;
            size = size + 1;
         }  // end while
      }  // end try
      catch (bad_alloc e)
      {
          throw ListException(
         "ListException: restore cannot allocate memory.");
      }  // end catch
   }  // end if

   inFile.close();
}






#include <iostream> // Only for displaying copy constructor
#include<string>
#include <new>         // for bad_alloc
#include <fstream>     // for file I/O
#include <cstddef>     // for NULL
#include "ListException.h"
#include <time.h>

typedef int ListItemType;
//typedef struct ListNode* nodePtr;

using namespace std;

class List
{
       public:

      /** A node on the list. */
      struct ListNode
      {
         /** A data item on the list. */
         ListItemType item;
         /** Pointer to next node. */
         ListNode* next;
      }; // end ListNode

      /** Number of items in list. */
      int       size;
      /** Pointer to linked list of items. */
      ListNode* head;



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
	  void printList(ListNode* head) ;
      void mergeSort(ListNode* *source);
      void partitionTheList(ListNode* curHead, ListNode* *left, ListNode* *right);
      friend struct ListNode* mergeTheLists(ListNode* a, ListNode* b);
       //void  mergeTheLists(ListNode* *mergedList,  ListNode* a, ListNode* b);

    void insertionSort();//ListNode* temp);
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
    if(isEmpty())
        {
            cout<<"List is empty";
        }
    else
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
}
//prints all items in the list.
void List::printList(ListNode* head1)
{
    if(isEmpty())
        {
            cout<<"List is empty";
        }
    else
    {
    ListNode* cur;
    cur = head1;

    while (cur != NULL){
        cout<<cur->item<<endl;
        cur = cur->next;
      }
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

void List:: insertionSort(){

    if(isEmpty())
        {
            cout<<"List is empty";
        }
    else
    {
    ListNode* temp = head;
    ListNode* curr = head;
    temp=temp->next;
    while (temp != NULL){
                curr= head;
                while (curr != temp){
                    if (curr->item > temp->item)
                    {
                        //cout << "swap : " ;
                            int tempVariable = temp->item;
                            temp->item=curr->item;
                            curr->item=tempVariable;
                    }
                    else
                    {
                    curr=curr->next;
                    }

              }
            temp=temp->next;
         }
    }
}
 struct ListNode* mergeTheLists( ListNode* a, ListNode* b)
{
     //ListNode* temp;
     //temp = *mergedList;
   ListNode* mergedList = NULL;

  /* Base cases */
  if (a == NULL)
     return b;
  else if (b==NULL)
     return a;

  /* select either a or b,  */
  if (a->item <= b->item)
  {
     mergedList = a;
     mergedList= mergedList->next;
  }
  else
  {
     mergedList = b;
     mergedList= mergedList->next;// = mergeLists(a, b->next);
  }
  return (mergedList);
}
void List:: partitionTheList(ListNode* curHead, ListNode* *left, ListNode* *right)
{
    ListNode* fast;
    ListNode* slow;

    if ( curHead ==NULL || curHead->next ==NULL)
        {
            *left=curHead;
            *right= NULL;
        }
    else
    {
        slow = curHead;
        fast = curHead->next;
        while(fast != NULL)
            {
                fast=fast->next;
                if (fast != NULL)
                    {
                        slow= slow->next;
                        fast = fast->next;

                    }
            }
            *left = curHead;//a
            *right = slow->next;//b
            slow->next = NULL;cout<<"left side ";
             printList(*left);cout<<"right side "; // my print does not take any argument. fix this to print left or right
             printList(*right);
    }

}
void List:: mergeSort(ListNode* *source)
{
    if(isEmpty())
        {
            cout<<"List is empty";
        }
    else
    {
     ListNode* head = *source;

     ListNode* a=NULL; // "a" is a ptr to the first half of the array
     ListNode* b=NULL;  //
    if (head==NULL || head->next==NULL)
        {
            return;
        }
    partitionTheList(head,&a,&b);
    mergeSort(&a);
    mergeSort(&b);

   *source= mergeTheLists(a,b);

   }
}




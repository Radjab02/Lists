#ifndef LIST_H
#define LIST_H
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
      void partition(ListNode head,ListNode *left, ListNode *right);
      void mergeSort(ListNode *source);
     // ListNode mergeLists(ListNode a, ListNode b);


};

#endif // LIST_H

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <cstdlib>
#include <ctime>
#include "timer.h"

using namespace std;

typedef struct Node* ListNode;

    struct Node{

    int data;
    ListNode next;
    };
    bool isEmpty(ListNode);
    void remove(ListNode *headRef);

    void mergeSort(ListNode *source);
    void partition(ListNode curHead, ListNode *left, ListNode *right);
    ListNode mergeLists(ListNode a, ListNode b);

    void insertionSort(ListNode temp);
    void insertNode(ListNode* head,int);
    void printList(ListNode head);

    // random number generator
    int randomNumberGenerator (int siz);

int main(){

  ListNode head = NULL;//empty list
  int numb; int x;
  char choice;
  bool done = false;
  string filename;

  do
  {

    cout << endl << endl << endl;
    cout << "          1. Insert  items in the list" << endl;
    cout << "          2. Display the list" << endl;
    cout << "          3. Insertion sort" << endl;
    cout << "          4. Bubble sort" << endl;
    cout << "          5. Selection sort" << endl;
    cout << "          6. Merge sort" << endl;
    cout << "          7. Save Records to File" << endl;
    cout << "          8. Load Records from File" << endl;
    cout << "          9. Clear List" << endl;
    cout << "          Q. Quit" << endl;

    cout << endl;
    cout << "        => ";
    cin >> choice;
    choice = toupper(choice);

    switch( choice )
    {
      case '1' : cout << "enter size of the list => ";
                 cin >> numb;
                 //if (isnum(numb)){  to limit input to numbers
                 for(int i=0; i < numb;i++){
                  x=randomNumberGenerator(2000);
                  insertNode(&head,x);
                 }
                // }
                 break;

      case '2' :  if (isEmpty(head)){
                  cout<<"List is empty";
                  }
                  else{
                  cout << "Data for ALL Records" << endl;
                  cout << "----------------------------" << endl;

                  printList(head);
                  cout << endl;
                  cout << "----------------------------" << endl;
                  }
                  break;

      case '3' :  if (isEmpty(head)){cout<<"List is empty";}

                  else{
                        TICK();                  // <-- Note the use of TICK() here
                  insertionSort(head);
                  TOCK();                  // <-- and the use of TOCK() here
                   cout << endl;
                    // See how DURATION() is used below.
                   cout << "insertion sort  took "
                    << DURATION() << " seconds" << endl;
                    cout << endl;

//                  cout << "        => ";
//                  cout<<"List sorted"<<endl;
//                  printList(head);
                  }
                  break;

      case '4' :  cout <<"implement Bubble sort here ";
                  break;

      case '5' :  cout <<"implement Selection sort here ";
                  break;

      case '6' :  if (isEmpty(head))
                  {
                      cout<<"List is empty";
                  }
                  else
                    {
                        TICK();                  // <-- Note the use of TICK() here
                  insertionSort(head);
                  TOCK();                  // <-- and the use of TOCK() here
                   cout << endl;
                    // See how DURATION() is used below.
                   cout << "merge sort  took "
                    << DURATION() << " seconds" << endl;
                    cout << endl;
                    }

                    break;

      case '7' :  cout << "Save records to? File name = ";
                  cin >> filename;
                  //save( filename );
                  break;

      case '8' :  cout << "Load records from? File name = ";
                  cin >> filename;
                  //load(filename);
                  break;
      case '9' :  if(isEmpty(head)){cout<<"List is empty";}
                  else
                    {
                        while (!isEmpty(head)){remove(&head);}
                        cout<<"List Cleared!!";
                    }

                    break;

      case 'Q' : done = true;
                 break;

      default :
         cout << "Invalid choice" << endl;
    }
  } while ( !done );
  cout << "Good Bye !!" << endl;

   return 0;
}

int randomNumberGenerator (int siz)
    {
    return (rand()%siz)+1;
    }
 void insertNode(ListNode* head,int x){
Node* temp =new Node();
temp->data=x;//
temp->next=*head;
*head=temp;

}

void printList(ListNode head){
    //cout<<" list is : ";
    while(head != NULL){
        cout<<"\t "<<head->data;
        head=head->next;
    }
    endl(cout);
}

void insertionSort(ListNode temp){
    ListNode head = temp;
    ListNode curr = head;
    temp=temp->next;
    while (temp != NULL){
                curr= head;
                while (curr != temp){
                    if (curr->data > temp->data)
                    {
                        //cout << "swap : " ;
                            int tempVariable = temp->data;
                            temp->data=curr->data;
                            curr->data=tempVariable;
                    }
                    else
                    {
                    curr=curr->next;
                    }

              }
            temp=temp->next;
         }

}
ListNode mergeLists(ListNode a, ListNode b)
{

  ListNode mergedList = NULL;

  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);

  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     mergedList = a;
     mergedList->next = mergeLists(a->next, b);
  }
  else
  {
     mergedList = b;
     mergedList->next = mergeLists(a, b->next);
  }
  return(mergedList);
}
void partition(ListNode curHead, ListNode *left, ListNode *right)
{
    ListNode fast;
    ListNode slow;

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
void mergeSort(ListNode *source)
{

     ListNode head = *source;

     ListNode a=NULL; // "a" is a ptr to the first half of the array
     ListNode b=NULL;  //
    if (head==NULL || head->next==NULL)
        {
            return;
        }
    partition(head,&a,&b);
    mergeSort(&a);
    mergeSort(&b);

    *source = mergeLists(a,b);


}

bool isEmpty(ListNode head)
{
    return head == NULL;

}
void remove(ListNode *headRef)
{
    ListNode cur;
    ListNode head;
     // delete the first node from the list
     cur = *headRef;  // save pointer to node
     head = *headRef;
     head = head->next;
     cur->next = NULL;
     delete cur;
     cur = NULL;
     *headRef=head;

}

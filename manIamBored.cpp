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
    // this function are only for size 20
    void insertionSort1(ListNode temp);
  //    void mergeSort20(ListNode *source);
//    void partition20(ListNode curHead, ListNode *left, ListNode *right);
//    ListNode mergeLists20(ListNode a, ListNode b);

     //for size 200 and 200
    void insertionSort(ListNode temp);

    void insertNode(ListNode* head,int);
    void printList(ListNode head);

    void compareInsertionSort(ListNode head20,ListNode head200,ListNode head2000){
      cout << "insertion sort comparison "<<endl;
           TICK();
           insertionSort(head20);
           TOCK();
           cout << endl;

           cout << "the list of size 20 took "
                << DURATION() << " seconds" << endl;
           cout << endl;

   // for 200
           TICK();
           //insertionSort(head200);
           TOCK();
           cout << endl;
           cout << "the list of size 200 took "
                << DURATION() << " seconds" << endl;
           cout << endl;
    // time taken for 2000
           TICK();                  //
           //insertionSort(head2000);
           TOCK();                  //
           cout << endl;

           cout << "the list of size 2000 took "
                << DURATION() << " seconds" << endl;
           cout << endl;


    }

    void compareMergeSort(ListNode *head20,ListNode *head200,ListNode *head2000){
    //create three different lists with size 20, 200, 2000
           ListNode temp;
       cout << "merge sort comparison "<<endl<<endl;
           temp = *head20;
           TICK();
           mergeSort(&temp);
           TOCK();
           *head20= temp;
           cout << endl;

           cout << "the list of size 20 took "
                << DURATION() << " seconds" << endl;
           cout << endl;

          // for 200
           temp = *head200;
           TICK();                           //
           mergeSort(&temp);
           TOCK();
           *head200= temp;
           cout << endl;

           cout << "the list of size 200 took "
                << DURATION() << " seconds" << endl;
           cout << endl;

          // time taken for 2000
           temp = *head2000;
           TICK();                  //
           mergeSort(&temp);                    // mergeSort(&head2000);
           TOCK();                  //
           *head2000= temp;
           cout << endl;

           cout << "the list of size 2000 took "
                << DURATION() << " seconds" << endl;
           cout << endl;


    }


    // random number generator
    int randomNumberGenerator (int siz);
    void Display(int x, int y){

    cout << "Swapped " << setw(2) << x << " with " << setw(2) << y << " --->";
    }

    void generateTheList(ListNode *headPtr, int size){
        int x;
        ListNode temp = *headPtr;
    for(int i=0; i < size;i++){
                  x=randomNumberGenerator(2000);
                  insertNode(&temp,x);
                 }
     *headPtr=temp;
    }

int main(){

  //ListNode head = NULL;//empty list
    srand(time(0));// to give different random num each time the program is run
    ListNode headPtrFor20=NULL;
    ListNode headPtrFor200 =NULL;
    ListNode headPtrFor2000 = NULL;
    //generate the list for 20
   generateTheList(&headPtrFor20,20);
   //generate the list for 200
   generateTheList(&headPtrFor200,200);
  // generate the list for 2000
   generateTheList(&headPtrFor2000,2000);


  int numb; int x;
  char choice;
  bool done = false;
  string filename;

  do
  {

    cout << endl << endl << endl;

    cout << "          1. Display the lists" << endl;
    cout << "          2. Comparison of Insertion sort" << endl;
    cout << "          3. Comparison of Bubble sort" << endl;
    cout << "          4. Comparison of Selection sort" << endl;
    cout << "          5. Comparison of Merge sort" << endl;
    cout << "          6. Save Records to File" << endl;
    cout << "          7. Load Records from File" << endl;
    //cout << "          8. Clear List" << endl;
    cout << "          Q. Quit" << endl;

    cout << endl;
    cout << "        => ";
    cin >> choice;
    choice = toupper(choice);

    switch( choice )
    {
      case '1' :
                 if(isEmpty(headPtrFor20)){cout<<"Lists are empty"; cout<<"close and open the program";}
                 else {
                 cout<<" list of size 20 "<<endl;
                 printList(headPtrFor20);
                 cout<<" End of list of size 20 "<<endl;
                 cout<<endl;
                 cout<<"=============================="<<endl;

                 cout<<" list of size 200 "<<endl;
                 printList(headPtrFor200);
                 cout<<" End of list of size 200 "<<endl;
                 cout<<endl;
                 cout<<"=============================="<<endl;

                 cout<<" list of size 2000 "<<endl;
                 printList(headPtrFor2000);
                 cout<<" End of list of size 2000 "<<endl;
                 cout<<endl;
                 cout<<"=============================="<<endl;
                 }
                 break;

      case '2' :   printList(headPtrFor20);
                  compareInsertionSort(headPtrFor20,headPtrFor200,headPtrFor2000);
                  insertionSort1(headPtrFor20);
                  printList(headPtrFor20);
                  break;

      case '3' :
                  break;

      case '4' :  cout <<"implement Bubble sort here ";
                  break;

      case '5' :  //printList(headPtrFor20);
                  compareMergeSort(&headPtrFor20,&headPtrFor200,&headPtrFor2000);
                  break;

      case '6' :  cout << "Save records to? File name = ";
                  cin >> filename;
                  //save( filename );
                  break;

      case '7' :  cout << "Load records from? File name = ";
                  cin >> filename;
                  //load(filename);
 /*                 break;
      case '8' : //clear list of size 20
                if(isEmpty(headPtrFor20)){cout<<"List is empty";}
                  else
                    {
                        while (!isEmpty(headPtrFor20)){remove(&headPtrFor20);}
                        cout<<"List of size 20 is Cleared!!\n";
                    }
                    //clear list of size 200
                    if(isEmpty(headPtrFor200)){cout<<"List is empty";}
                  else
                    {
                        while (!isEmpty(headPtrFor200)){remove(&headPtrFor200);}
                        cout<<"List of size 200 is Cleared!! \n";
                    }
                    //clear list of size 2000
                    if(isEmpty(headPtrFor2000)){cout<<"List is empty";}
                  else
                    {
                        while (!isEmpty(headPtrFor2000)){remove(&headPtrFor2000);}
                        cout<<"List of size 2000 is Cleared!!\n";
                    }



                    break;
*/
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
                //curr= head;
                while (curr != temp){
                    if (curr->data > temp->data)
                    {

                            int tempVariable = temp->data;
                            temp->data=curr->data;
                            curr->data=tempVariable;
                            Display(temp->data,curr->data); //comment here
                            printList(head); //comment here
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
            slow->next = NULL;
            // cout<<"left side ---->"; //comment here
            // printList(*left);
           //  cout<<"right side---->"; //comment here
            // printList(*right);
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

    //cout << "Merging two halves ---> ";

    //printList(a); cout<<"                               ";
    //printList(b);

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
void insertionSort1(ListNode temp1){
    ListNode head1 = temp1;
    ListNode curr1 = head1;
    temp1=temp1->next;
    while (temp1 != NULL){
                curr1= head1;
                while (curr1 != temp1){
                    if (curr1->data > temp1->data)
                    {

                            int tempVariable1 = temp1->data;
                            temp1->data=curr1->data;
                            curr1->data=tempVariable1;
                            Display(temp1->data,curr1->data); //comment here
                            printList(head1); //comment here
                    }
                    else
                    {
                    curr1=curr1->next;
                    }

              }
            temp1=temp1->next;
         }

}

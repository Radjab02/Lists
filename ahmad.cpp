#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "timer.h"
using namespace std;

//create node to make to linked-list array
typedef struct Node* ListNode;
    struct Node{
    int data;
    ListNode next;
    };
//this function make new linked-list
//when list is already sorted , reset the list
void createList(ListNode *head,int size1,bool reset){
if(reset){
if(*head!=NULL){
//delete the old list
while(*head!=NULL){
     Node* temp =new Node();
    temp=*head;
    *head=temp->next;
    temp->next=NULL;
    delete temp;
    }
*head=NULL;
}
//creates a new list
    for(int i=0;i<size1;i++){
    Node* temp =new Node();
    temp->data= (rand()%(size1*7))+1;//  generates random numbers
    temp->next=*head;
    *head=temp;
    }
 }
}
//to display the linked-list
void show(ListNode temp){
    int counter=0;
  cout<<" list is : \n";
    while(temp != NULL){
        cout<<"  "<<temp->data;
        temp=temp->next;
        counter++;
        if(counter==10){cout<<endl;counter=0;}
    }
    endl(cout);
    endl(cout);
}

//structure that contains all Sorting functions.
struct linked_list {
ListNode head ;
int size2 ;
bool sorted;
//constructor
linked_list(int size1)
{      size2=size1 ;
       sorted=false;
       head = NULL ;

    createList(&head,size1,true);
}
// selection Algorithm that returns the time.
double selection_Sort_Algorithm(){
ListNode start ;
ListNode smallest ;
   ListNode temp ;
    temp=head;
    int temp1;
TICK();//start timer.
while(temp!=NULL){
start=temp;
smallest=temp;
//find the smallest number in range of start to null
while(start != NULL){
    if(start->data < smallest->data)
      smallest=start;
    start=start->next;
}
//swap temp with smallest and display only if the size 20
if(size2==20){cout << "Swapped " << temp->data  << " with " << smallest->data << " --->";show(head);}
 temp1=temp->data;
 temp->data=smallest->data;
 smallest->data=temp1;
 temp=temp->next;
}TOCK();//stop timer
sorted=true;
return DURATION();
}
// Bubble Algorithm that returns the time.
double bubble_Sort_Algorithm(){
ListNode second ;
ListNode first ;
    ListNode temp ;
    temp=head;
    first=head;
    second=head->next;
    int temp1,counter,counter2=0;
TICK(); //start timer.
   while(temp->next != NULL){
        counter=0;//count if there is swap in the current phase
        counter2++;//keep count of the number of phase
        if(size2==20)cout<<"\nPhase "<<counter2<<endl<<endl;
        //go though the list and swap elements which are next to each other
        while(first->next != NULL){
       if(first->data > second->data){
            temp1=first->data;
            first->data=second->data;
            second->data=temp1;
            counter++;
            //if size is 20 display
          if(size2==20){cout<< "Swapped "<<first->data<<" with " <<second->data<<" --->"; show(head);}
            }
        first=first->next;
        second=second->next;
        }
        //when the list is sorted break the loop
        if(counter==0)break;
            temp=temp->next;
            first=head;
            second=head->next;
    }
TOCK();// stop the time.
sorted=true;
return DURATION();
 }
// insertion Algorithm that returns the time.
double insertion_Sort_Algorithm(){
    ListNode temp = head;
    ListNode curr = head;
    temp=temp->next;
    TICK();// start the time.
//loop to check all items in the array
    while (temp != NULL){
    curr= head;
//insert the item in the right place
    while (curr != temp){
    if (curr->data > temp->data){
            int tempVariable = temp->data;
            temp->data=curr->data;
            curr->data=tempVariable;
            //if size is 20 display
            if (size2==20){ cout << "Swapped " << temp->data  << " with " << curr->data << " --->";show(head);}
              }
        curr=curr->next;
              }
    temp=temp->next;
     }
TOCK();// stop the time.
sorted=true;
return DURATION();
  }
//merge the two list into one
ListNode mergeLists(ListNode a, ListNode b)
{
  ListNode mergedList = NULL;
  //base case
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
  // pick either a or b then recall mergeLists
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
//partitions the list in to two lists
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
            *left = curHead;
            *right = slow->next;
            slow->next = NULL;
        if (size2==20){
        cout<< "left side"; show(*left);
        cout<< "right side";show(*right);
        }
    }
}
// merge sort Algorithm.
void mergeSort(ListNode *source)
{
     ListNode start = *source;
     ListNode a=NULL;
     ListNode b=NULL;
     //base case
    if (start==NULL || start->next==NULL)
        {
            return;
        }
    partition(start,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
    if(size2==20) {cout<<"merging the halves\nHalf 1";show(a);
    cout<<"Half 2";show(b);cout<<endl;
    }
    *source = mergeLists(a,b);
    if(size2==20){cout<<"After merging .The new";  show(*source);}
    sorted=true;
 }
};//end of LinkedList structure

//to save the list
void save(string name,ListNode head){
   Node* temp =new Node();
    temp=head;
ofstream save;
   save.open(name.c_str(),ios::out);
   if(save.is_open()){
while(temp!=NULL){
  save<<temp->data<<endl;
   temp=temp->next;
}
save.close();
   }
}
//to load the list of size 20
void load(string name,ListNode *head){
   Node* temp =new Node();
    temp=*head;
    ifstream load;
     load.open(name.c_str(),ios::in);
   if(load.is_open()){

while(temp!=NULL){
load>>temp->data;
   temp=temp->next;
}
cout<<"\n\tThe data has been loaded successfully\n";
 load.close();
 }else cout<<"can not load check the file if "<<name<<" excited\n\n";
}
//to display the menu and return the user choice
string menu(){
    string choice;
    cout<<endl
        <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
        <<"@@@@@                                                        @@@@@\n"
        <<"@@@@@                                                        @@@@@\n"
        <<"@@@@@          Please select :                               @@@@@\n"
        <<"@@@@@                                                        @@@@@\n"
        <<"@@@@@          1. Selection sort                             @@@@@\n"
        <<"@@@@@          2. Bubble sort                                @@@@@\n"
        <<"@@@@@          3. Insertion sort                             @@@@@\n"
        <<"@@@@@          4. Merge sort                                 @@@@@\n"
        <<"@@@@@          5. Comparison between sorting Algorithms      @@@@@\n"
        <<"@@@@@          6. Save Records to File                       @@@@@\n"
        <<"@@@@@          7. Load Records from File                     @@@@@\n"
        <<"@@@@@          8. view the linked-list arrays                @@@@@\n"
        <<"@@@@@          9. to reset the list                          @@@@@\n"
        <<"@@@@@                                                        @@@@@\n"
        <<"@@@@@          Q-quit                                        @@@@@\n"
        <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
        <<"@@@@                  => ";
        getline(cin,choice);
    cout << endl;
    return choice;
}
int main()
{
//setting default value
linked_list list_of_size_20(20);
linked_list list_of_size_200(200);
linked_list list_of_size_2000(2000);
  bool done = false;
  string choice;
  double timing[12];
  for(int i=0;i<12;i++)
    timing[i]=0;
  do{
 choice=menu();
if(choice=="1"){//

  createList(&list_of_size_20.head,20,list_of_size_20.sorted);
  timing[0]=list_of_size_20.selection_Sort_Algorithm();

  createList(&list_of_size_200.head,200,list_of_size_200.sorted);
  timing[1]= list_of_size_200.selection_Sort_Algorithm();

  createList(&list_of_size_2000.head,2000,list_of_size_2000.sorted);
  timing[2]=list_of_size_2000.selection_Sort_Algorithm();

  cout<<"\n\nThe time that selection Sort Algorithm took for \n size 20   is "<<timing[0]
     <<"\n size 200  is "<<timing[1]<<"\n size 2000 is "<<timing[2]<<"\n\n";
}
else if(choice=="2"){
  createList(&list_of_size_20.head,20,list_of_size_20.sorted);
  timing[3]=list_of_size_20.bubble_Sort_Algorithm();

  createList(&list_of_size_200.head,200,list_of_size_200.sorted);
  timing[4]=list_of_size_200.bubble_Sort_Algorithm();

  createList(&list_of_size_2000.head,2000,list_of_size_2000.sorted);
  timing[5]= list_of_size_2000.bubble_Sort_Algorithm();

  cout<<"\n\nThe time that selection Sort Algorithm took for \n size 20   is "<<timing[3]
     <<"\n size 200  is "<<timing[4]<<"\n size 2000 is "<<timing[5]<<"\n\n";
}
else if(choice=="3"){
  createList(&list_of_size_20.head,20,list_of_size_20.sorted);
  timing[6]=list_of_size_20.insertion_Sort_Algorithm();

  createList(&list_of_size_200.head,200,list_of_size_200.sorted);
  timing[7]=list_of_size_200.insertion_Sort_Algorithm();

  createList(&list_of_size_2000.head,2000,list_of_size_2000.sorted);
  timing[8]=list_of_size_2000.insertion_Sort_Algorithm();

  cout<<"\n\nThe time that selection Sort Algorithm took for \n size 20   is "<<timing[6]
     <<"\n size 200  is "<<timing[7]<<"\n size 2000 is "<<timing[8]<<"\n\n";
}
else if(choice=="4"){
  createList(&list_of_size_20.head,20,list_of_size_20.sorted);
  TICK();
  list_of_size_20.mergeSort(&list_of_size_20.head);
  TOCK();
  timing[9]=DURATION();

  createList(&list_of_size_200.head,200,list_of_size_200.sorted);
  TICK();
  list_of_size_200.mergeSort(&list_of_size_200.head);
  TOCK();
  timing[10]=DURATION();

  createList(&list_of_size_2000.head,2000,list_of_size_2000.sorted);
  TICK();
  list_of_size_2000.mergeSort(&list_of_size_2000.head);
  TOCK();
  timing[11]=DURATION();

  cout<<"\n\nThe time that selection Sort Algorithm took for \n size 20   is "<<timing[9]
     <<"\n size 200  is "<<timing[10]<<"\n size 2000 is "<<timing[11]<<"\n\n";
 }
else if(choice=="5"){
cout<<"-------------------------------------------------------------------------\n"
    <<"                 comparison of all sorting Algorithms\n"
    <<"-------------------------------------------------------------------------\n"
    <<"              |  size 20        |  size 200          |  size 2000        \n"
    <<"-------------------------------------------------------------------------\n"
    <<"selection sort| "<<timing[0]<<"       | "<<timing[1]<<"        | "<<timing[2]<<endl
    <<"-------------------------------------------------------------------------\n"
    <<"bubble sort   | "<<timing[3]<<"        | "<<timing[4]<<"        | "<<timing[5]<<endl
    <<"-------------------------------------------------------------------------\n"
    <<"insertion sort| "<<timing[6]<<"       | "<<timing[7]<<"        | "<<timing[8]<<endl
    <<"-------------------------------------------------------------------------\n"
    <<"merge sort    | "<<timing[9]<<"       | "<<timing[10]<<"        | "<<timing[11]<<endl
    <<"-------------------------------------------------------------------------\n";
}
else if(choice=="6"){
//for option 6 saving all the lists
save("list_of_size_20",list_of_size_20.head);
save("list_of_size_200",list_of_size_200.head);
save("list_of_size_2000",list_of_size_2000.head);
cout <<"The data has been saved successfully\n";
}
else if(choice=="7"){
//for option 7 loading all the lists
load("list_of_size_20",&list_of_size_20.head);
load("list_of_size_200",&list_of_size_200.head);
load("list_of_size_2000",&list_of_size_2000.head);
}
else if(choice=="8"){
//for option 8 display linked-list arrays
cout<< "size 2000 " ;show(list_of_size_2000.head);
cout<< "size 200 " ;show(list_of_size_200.head);
cout<< "size 20" ;show(list_of_size_20.head);
}
else if(choice=="9"){
//for option 9 resets linked-list arrays
createList(&list_of_size_20.head,20,true);list_of_size_20.sorted=false;
createList(&list_of_size_200.head,200,true);list_of_size_200.sorted=false;
createList(&list_of_size_2000.head,2000,true);list_of_size_2000.sorted=false;

  for(int i=0;i<12;i++)
    timing[i]=0;
  cout<<"the list have been reset \n";
}
else if(choice=="q"||choice=="Q")done =true;
else  {cout << "Invalid choice" << endl;}

} while ( !done );
  cout << "Good Bye !!" << endl;
    return 0;
}

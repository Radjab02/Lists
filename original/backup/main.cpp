#include <iostream>
#include <fstream>
#include <iomanip>
#include "List.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int randomNumberGenerator (int siz)
{
 return (rand()%siz)+1;
}

int main()
{
 char choice;
  bool done = false;
  //WRITE CODE HERE
  // declare the object of linked list here

   List aList;


  do
  {

    cout << endl << endl << endl;
    cout << "          1. Insert  items in the list" << endl;
    cout << "          2. Display the list" << endl;
    cout << "          3. Bubble sort" << endl;
    cout << "          4. Insertion sort" << endl;
    cout << "          5. Merge sort" << endl;
    cout << "          5. Selection sort" << endl;
    cout << "          6. Save Records to File" << endl;
    cout << "          7. Load Records from File" << endl;
    cout << "          Q. Quit" << endl;

    cout << endl;
    cout << "        => ";
    cin >> choice;
    choice = toupper(choice);


    string filename;
    int siz;


    switch( choice )
    {
      case '1' : cout << "enter size of the list => ";
                 cin >> siz;
                 for(int i=0; i < siz;i++)
                 aList.insert(randomNumberGenerator(100));

                 break;

      case '2' :  cout << "Data for ALL Records" << endl;
                  cout << "----------------------------" << endl;

                  aList.print();
                  cout << endl;
                  cout << "----------------------------" << endl;

                  break;

      case '3' :  cout<<"not implemented yet";

                  break;

      case '4' :  cout<<"not implemented yet";

                  break;

      case '5' :  cout<<"not implemented yet";
                  break;
      case '6' :  cout << "Save records to? File name = ";
                  cin >> filename;
                  aList.save( filename );
                break;

      case '7' : cout << "Load records from? File name = ";
                 cin >> filename;
                 aList.load(filename);
                 break;

      case 'Q' :
                 done = true;
                 break;

      default :
         cout << "Invalid choice" << endl;
    }
  } while ( !done );
  cout << "Good Bye !!" << endl;

    return 0;
}

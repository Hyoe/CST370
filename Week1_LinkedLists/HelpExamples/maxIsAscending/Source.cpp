#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
   // Test the class constructor
   LinkedList intList;
   cout << "Constructing intList\n";

   // Test insert()
   intList.insert(100, 0);
   intList.display(cout);
   cout << endl;

   intList.insert(200, 0);
   intList.display(cout);
   cout << endl;

   intList.insert(300, 1);
   intList.display(cout);
   cout << endl;

   intList.insert(400, 1);
   intList.display(cout);
   cout << endl;

   intList.insert(500, 3);
   intList.display(cout);
   cout << endl;

   cout << "Sum: " << intList.sumList() << endl;
   cout << "Max item: " << intList.maxItem() << endl;
   cout << "Is ascending order: " << intList.isAscendingOrder() << endl;

   // Test destructor
   {
      LinkedList anotherList;
      for (int i = 0; i < 10; i++)
      {
         anotherList.insert(100 * i, i);
      }
      cout << "\nThis is another list\n";
      anotherList.display(cout);
      cout << endl;

      cout << "Sum: " << anotherList.sumList() << endl;
      cout << "Max item: " << anotherList.maxItem() << endl;
      cout << "Is ascending order: " << anotherList.isAscendingOrder() << endl;

   }

   // Test erase
   intList.erase(1);
   intList.erase(1);
   cout << "\n\nTwo items are erased from the first list\n";
   intList.display(cout);
   cout << endl;

}



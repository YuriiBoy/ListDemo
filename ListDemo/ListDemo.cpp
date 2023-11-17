#include "Header.h"
#include "MyList.h"

int main()
{
	//1
	MyList<int> myList;
	myList.display();

	// 2
	myList.pushBack(100);
	myList.pushBack(200);
	myList.pushBack(300);
	myList.display();

	myList.pushFirst(111);
	myList.pushFirst(222);
	myList.pushFirst(333);	
	myList.display();

	//myList.pushIter(444, 2);
	//myList.display();

	// Fin
	std::cout << "\n Finish";
}

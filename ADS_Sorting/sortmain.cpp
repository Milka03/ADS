#include <iostream>
#include "sortheader.h"
using namespace std;





int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr1a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr2a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr3[] = { 1, 3, 2, 4, 7, 5, 6, 8, 9 };
	int arr3a[] = { 1, 3, 2, 4, 7, 5, 6, 8, 9 };
	int arr4[] = { 3, 8, 5, 7, 1, 4, 9, 6, 2 };
	int arr4a[] = { 3, 8, 5, 7, 1, 4, 9, 6, 2 };

	int h1[] = { 4, 1 };
	int h2[] = { 5, 3, 1 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	int size4 = sizeof(arr4) / sizeof(arr4[0]);
	int sizeh1 = sizeof(h1) / sizeof(h1[0]);
	int sizeh2 = sizeof(h2) / sizeof(h2[0]);

	
	printArray(arr1, size1); 
	cout << "-------------------------------" << endl;
	//int count1 = bubbleSort(arr1, size1);
	int count1 = Shell(arr1, size1, h1, sizeh1);
	cout << "Sorted array: ";
	printArray(arr1, size1);
	cout << "Number of comparisons: " << count1 << endl << endl;

	printArray(arr1a, size1);
	cout << "-------------------------------" << endl;
	int count1a = Shell(arr1a, size1, h2, sizeh2);
	cout << "Sorted array: ";
	printArray(arr1a, size1);
	cout << "Number of comparisons: " << count1a << endl << endl;


	printArray(arr2, size2);
	cout << "-------------------------------" << endl;
	//int count2 = bubbleSort(arr2, size2);
	int count2 = Shell(arr2, size2, h1, sizeh1);
	cout << "Sorted array: ";
	printArray(arr2, size2);
	cout << "Number of comparisons: " << count2 << endl << endl;

	printArray(arr2a, size2);
	cout << "-------------------------------" << endl;
	int count2a = Shell(arr2a, size2, h2, sizeh2);
	cout << "Sorted array: ";
	printArray(arr2a, size2);
	cout << "Number of comparisons: " << count2a << endl << endl;


	printArray(arr3, size3);
	cout << "-------------------------------" << endl;
	//int count3 = bubbleSort(arr3, size3);
	int count3 = Shell(arr3, size3, h1, sizeh1);
	cout << "Sorted array: ";
	printArray(arr3, size3);
	cout << "Number of comparisons: " << count3 << endl << endl;

	printArray(arr3a, size3);
	cout << "-------------------------------" << endl;
	int count3a = Shell(arr3a, size3, h2, sizeh2);
	cout << "Sorted array: ";
	printArray(arr3a, size3);
	cout << "Number of comparisons: " << count3a << endl << endl;


	printArray(arr4, size4);
	cout << "-------------------------------" << endl;
	//int count3 = bubbleSort(arr3, size3);
	int count4 = Shell(arr4, size4, h1, sizeh1);
	cout << "Sorted array: ";
	printArray(arr4, size3);
	cout << "Number of comparisons: " << count4 << endl << endl;

	printArray(arr4a, size4);
	cout << "-------------------------------" << endl;
	int count4a = Shell(arr4a, size4, h2, sizeh2);
	cout << "Sorted array: ";
	printArray(arr4, size4);
	cout << "Number of comparisons: " << count4a << endl << endl;





	system("pause");
	return 0;
}
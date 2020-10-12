#include <iostream>
#include "sortheader.h"

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


int bubbleSort(int arr[], int size)
{
	int i;
	int counter = 0;
	bool swapped;
	for (i = 0; i < size - 1; i++) {
		swapped = false;
		// Last i elements are sorted 
		if (i % 2 == 0) {
			for (int j = i / 2; j < size - (i / 2) - 1; j++) {
				counter++;
				if (arr[j] > arr[j + 1]) {
					swap(&arr[j], &arr[j + 1]);
				}
			}
		}
		//First i elements are sorted
		else {
			for (int j = size - i / 2 - 2; j > i / 2; j--) {
				counter++;
				if (arr[j] < arr[j - 1]) {
					swap(&arr[j], &arr[j - 1]);
				}
			}
		}
	}
	return counter;
}



int Shell(int arr[], int arrsize, int h[], int hsize)
{
	int Comparisons = 0;
	int temp;
	//gap to i, i to j
	for (int count = 0; count < hsize; count++) 
	{
		int gap = h[count];
		for (int i = gap; i < arrsize; i++)
		{
			int temp = arr[i];
			int j = i;
			
			while((j - gap) >= 0 && ++Comparisons && arr[j - gap] > temp) {
				//Comparisons++;
				arr[j] = arr[j - gap];
				j = j - gap;
				arr[j] = temp;
			}
			
		}
		printArray(arr, arrsize);
	}
	return Comparisons;
}



void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
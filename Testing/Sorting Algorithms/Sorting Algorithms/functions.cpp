#include<stdio.h>
#include "SortingHeader.h"

void SelectionSort(int list[], int size)
{
	printf("\nSelectionSort\n\n");
	int indexMin, i, j;

	// loop through all numbers 
	for (i = 0; i < size - 1; i++) {

		// set current element as minimum 
		indexMin = i;

		// check the element to be minimum 
		for (j = i + 1; j<size; j++) {
			if (list[j] < list[indexMin]) {
				indexMin = j;
			}
		}

		if (indexMin != i)
		{
			// swap the numbers 
			swap(&list[indexMin], &list[i]);
		}
	}
}

void InsertionSort(int list[], int size)
{
	printf("\InsertionSort\n\n");
	int holePosition;
	int valueToInsert;

	for (int i = 1; i <= size; i++)
	{
		/* select value to be inserted */
		valueToInsert = list[i];
		holePosition = i;

		/*locate hole position for the element to be inserted */

		while (holePosition > 0 && list[holePosition - 1] > valueToInsert)
		{
			list[holePosition] = list[holePosition - 1];
			holePosition = holePosition - 1;
		}

			/* insert the number at hole position */
		list[holePosition] = valueToInsert;
	}
}

void BubbleSort(int list[], int size)
{
	printf("\BubbleSort\n\n");
	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;

		for (int j = 0; j < size - 1; j++)
		{
			/* compare the adjacent elements */
			if (list[j] > list[j + 1])
			{
				swap(&list[j], &list[j + 1]);
				swapped = true;
			}
		}

		/*if no number was swapped that means
		array is sorted now, break the loop.*/

		if (!swapped)
		{
			break;
		}
	}
}
/*
void Merging(int a[],int low, int mid, int high)
{
	int b[200];
	int l1, l2, i;

	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 < high; i++) {
		if (a[l1] <= a[l2])
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	}

	while (l1 <= mid)
		b[i++] = a[l1++];

	while (l2 < high)
		b[i++] = a[l2++];

	for (i = low; i <= high; i++)
		a[i] = b[i];
}

void MergingSort(int list[], int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		MergingSort(list, low, mid);
		MergingSort(list, mid + 1, high);
		Merging(list, low, mid, high);
	}
	else {
		return;
	}
}
*/





void swap(int* a, int* b) 
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
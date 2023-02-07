// C++ program for Merge Sort
#include "ordenacao.hpp"
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(Item *Vet, int const left, int const mid,
		int const right, int *comp, int *nCopys)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	Item *leftArray = new Item[subArrayOne];
	Item *rightArray = new Item[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++){
		leftArray[i].Chave = Vet[left + i].Chave;
		(*nCopys)++;
	}
	for (auto j = 0; j < subArrayTwo; j++){
		rightArray[j].Chave = Vet[mid + 1 + j].Chave;
		(*nCopys)++;
	}
	auto indexOfSubArrayOne
		= 0, // Initial index of first sub-array
		indexOfSubArrayTwo
		= 0; // Initial index of second sub-array
	int indexOfMergedArray
		= left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
			(*comp)++;
		if (leftArray[indexOfSubArrayOne].Chave
			<= rightArray[indexOfSubArrayTwo].Chave) {
			Vet[indexOfMergedArray].Chave
				= leftArray[indexOfSubArrayOne].Chave;
			indexOfSubArrayOne++;
		}
		else {
			Vet[indexOfMergedArray].Chave
				= rightArray[indexOfSubArrayTwo].Chave;
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		Vet[indexOfMergedArray].Chave
			= leftArray[indexOfSubArrayOne].Chave;
		(*nCopys)++;
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		Vet[indexOfMergedArray].Chave
			= rightArray[indexOfSubArrayTwo].Chave;
		(*nCopys)++;
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(Item *Vet, int const begin, int const end, int *comp, int *nCopys)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(Vet, begin, mid,comp, nCopys);
	mergeSort(Vet, mid + 1, end, comp, nCopys);
	merge(Vet, begin, mid, end, comp, nCopys);
}

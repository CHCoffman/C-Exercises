#include <iostream>
using namespace std;
  
// A helper function to facilitate swapping two int elements 
// You might want to use this function in the function partition().
/*void swap(int& a, int& b) 
{ 

} 
*/ 
// This function partitions sub-array A[p..r]. It takes last element in the sub-array, i.e., A[r], as pivot, 
// places the pivot element at its correct position in sorted array, 
// places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot, 
// and returns the index of the pivot element (i.e. it's correct position in sorted array)
// You might want to use this function in the function quickSort().
int partition (int A[], int p, int r) 
{ 
	int pivot = A[r];
	int pVal = p;
	int i, temp;

	for(i = p; i < r; i++)
	{
		if(A[i] <= pivot)
		{
			temp = A[i];
			A[i] = A[pVal];
			A[pVal] = temp;
			pVal++;
		}
	}
	temp = A[r];
	A[r] = A[pVal];
	A[pVal] = temp;

	return pVal;

} 
  
// using quickSort to sort sub-array A[p..r]  
// p is for left index and r is right index of the 
// sub-array of A[] to be sorted
void quickSort(int A[], int p, int r) 
{ 
 if(p < r)
 {
 	int pVal = partition(A, p, r);
 	quickSort(A, p, pVal - 1);
 	quickSort(A, pVal + 1, r);
 }
} 
  

int main() 
{ 
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;
	
	if(n <= 0) {
		cout << "Illegal input array length!" << endl;
		return 0;
	}
	
	int* A = new int [n];
	
	cout << "Please enter each element in the array" << endl; 
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i=0; i<n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
  
    cout << "Given array A[] is: "; 
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;
	
  
    quickSort(A, 0, n-1); 
  
    cout << "After quickSort, sorted array A[] is: "; 
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;
	
	
	delete [] A;
    return 0; 
} 
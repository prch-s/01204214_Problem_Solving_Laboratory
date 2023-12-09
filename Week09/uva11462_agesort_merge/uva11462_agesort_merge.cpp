#include <iostream>
//#include <algorithm>

//const int MAX_N = 2000000;

using namespace std;

void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
  
    // Create temp arrays
    int leftArray[n1], rightArray[n2];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1 ; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2 ; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int i = 0;
    int j = 0;
    int k = left;

    // Merge the temp arrays back into array[left..right]
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}
  

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end) {
        return;
    }
    // begin < end
    //int mid = begin + (end - begin) / 2;
    int mid = (begin + end) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
  
void printArray(int array[], int size)
{
    for (int i = 0; i < size ; i++) {
        if (i == size - 1){
            cout << array[i] << "\n";
        } else {
            cout << array[i] << " ";
        }
    }
}
  

int main(){
    int n;
    
    while (cin >> n && n != 0){
        int ages[n];
        for (int i = 0 ; i < n ; i++){
            cin >> ages[i];
        }

        //printArray(ages, n);

        //sort(ages, ages + n);

        // int size = sizeof(ages) / sizeof(ages[0]);
        // cout << size << "\n";
        // mergeSort(ages, 0, size - 1);
        mergeSort(ages, 0, n - 1);

        printArray(ages, n);
    }
    
}

/*
5
3 4 2 1 5
5
2 3 2 3 1
*/
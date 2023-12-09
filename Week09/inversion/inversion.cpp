#include <iostream>

using namespace std;

//const int MAX_N = 100010;

long long merge(int array[], int temp[], int left, int mid, int right) {

   long long count = 0;
   int i = left; 
   int j = mid; 
   int k = left; 

    while ((i <= mid - 1) && (j <= right)) {
        if (array[i] <= array[j]){ 
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
            count += (mid - i); 
        }
    }

    //first list has remaining item
    while (i <= mid - 1) {
        temp[k++] = array[i++];
    }

    //second list has remaining item
    while (j <= right) {
        temp[k++] = array[j++];
    }

    //store temp array to main array
    for (i = left ; i <= right ; i++) {
        array[i] = temp[i]; 
    }
    return count;
}

long long mergeSort(int array[], int temp[], int left, int right){
   long long count = 0;
   if (left < right) {
      int mid = (right + left) / 2;
      count += mergeSort(array, temp, left, mid); //left sub array
      count += mergeSort(array, temp, mid+1, right); //right sub array
      count += merge(array, temp, left, mid+1, right); //merge two sub arrays
   }
   return count;
}

int main() {
    int n;

    cin >> n;

    int array[n];
    int temp[n];
    
    for (int i = 0 ; i < n ; i++){
        cin >> array[i];
    }

    long long inversion = mergeSort(array, temp, 0, n - 1);

    cout << inversion << "\n";
}

/*
5 1 3 10 2 7

ref : https://www.tutorialspoint.com/c-cplusplus-program-to-count-inversions-in-an-array-using-merge-sort 
*/
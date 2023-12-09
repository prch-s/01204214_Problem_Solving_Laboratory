#include "probelib.h"
#include <cstdio>

// #include <iostream>
// using namespace std;

int n;

int main()
{
  int n = probe_init();

  int mid, left, right;

  left = 0;
  right = n-1;

  while(true){

      mid = (left + right) / 2;
      //cout << left << " " << mid << " " << right << "\n";

    //   if (left > mid || right > n){
    //       break;
    //   }

      //left side
      if (probe_check(left, mid)){
          if (left == mid){
              probe_answer(mid);
          }
          //update top
          right = mid;
      }
      //right side
      else {
          //update bottom
          left = mid + 1;
      }  
  }
}

/*
5 3
1000000 12367
*/
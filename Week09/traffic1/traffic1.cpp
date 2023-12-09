#include "traffic.h"
#include <vector>
#include <iostream>

using namespace std;

int abs(int a, int b){
  if (a - b > 0){
    return a - b;
  } else {
    return b - a;
  }
}

int main(){

  int n, k;

  traffic_init(&n, &k);

  int mid, left, right;
  
  //column
  for(int x = 1 ; x <= n ; x++){
    if (traffic_query(x, n, x, 1) > n-1){
      
      //binary search
      left = n;
      right = 1;

      while (true){
        mid = (left + right) / 2;
        if (traffic_query(x, mid - 1, x, mid) == 2){
          traffic_report(x, mid-1, x, mid, 0, 0, 0, 0);
        } else if(traffic_query(x, mid, x, mid+1) == 2){
          traffic_report(x, mid, x, mid+1, 0, 0, 0, 0);
        } else if(traffic_query(x, left, x, mid) > abs(left, mid)) {
          right = mid; //go left
        } else {
          left = mid + 1; //go right
        }
      }
      break;
    }
  }

  //row
  for(int y = 1 ; y <= n ; y++){
    if (traffic_query(1, y, n, y) > n-1){
      
      //binary search
      left = 1;
      right = n;

      while (true){
        mid = (left + right) / 2;
        if(traffic_query(mid-1, y, mid, y) == 2) {
          traffic_report(mid-1, y, mid, y, 0, 0, 0, 0);
        } else if(traffic_query(mid, y, mid+1, y) == 2) {
          traffic_report(mid, y, mid+1, y, 0, 0, 0, 0);
        } else if(traffic_query(left, y, mid, y) > abs(left, mid)) {
          right = mid; //go down
        } else {
          left = mid + 1; //go up
        }
      }
      break;
    }
  }
}

//ref:https://github.com/anawinwz/cpe31-probsolve/tree/master/week7/traffic

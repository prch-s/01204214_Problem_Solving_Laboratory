#include <iostream>

using namespace std;

const int MAX_M = 500000;
// const int INFINITY = 1e7;

int k;
int height[MAX_M];
int cnt[MAX_M];
int slice[MAX_M];

int main(){
    cin >> k;

    for(int i = 1 ; i <= k ; i++){
		cin >> height[i];
		
		if(height[i] > height[i-1]){
			for(int j = height[i-1] + 1 ; j <= height[i] ; j++){
				slice[j] = i;
			}
		}
		
		if(height[i] < height[i-1]){
			for(int j= height[i-1] ; j > height[i] ; j--){
				cnt[i-slice[j]]++;
			}
		}
		
		if(i == k){
			i++;
			height[i] = 0;
			if( height[i] > height[i-1] ){
				for(int j = height[i-1] + 1 ; j <= height[i] ; j++){
					slice[j] = i;
				}
			}
			
			if( height[i] < height[i-1] ){
				for(int j = height[i-1] ; j > height[i] ; j--){
					cnt[i-slice[j]]++;
				}
			}
			
		}
		
	}

    int result = 0;
    for(int i = 1 ; i <= MAX_M ; i++){
		if (cnt[i] != 0){
        	result++;
        }
	}
	cout << result << "\n";

    for(int i = 1 ; i <= MAX_M ; i++){
		if (cnt[i] != 0){
        	cout << i << " " << cnt[i] << "\n";
        }
	}

}
/*
9 1 2 4 2 0 3 3 1 2

8 1 2 2 1 0 1 1 1
*/

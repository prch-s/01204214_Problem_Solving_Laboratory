#include <iostream>

//using namespace std;

/*
int main() {
    int N,K,T;
    int position;
    int check;
    
    cin >> N;
    cin >> K;
    cin >> T;

    position = 1; //start
    int count = 1;
    
    while (true) {
        if (T == 1){ // 1 is thief
            break;
        }
        position += K;
        
        check = position%N;
        count += 1;
        //cout << check << ' ' << count << endl;
        if (check == 1){
            count -= 1;
            break;
        } else if (check == T){
            break;
        }
        
    }

    cout << count << endl;

    return 0;
}
*/

int main() {
    int N,K,T;
    int position;
    //int check;
    
    std::cin >> N >> K >> T;

    position = 1; //start
    int count = 1;
    
    while (true) {

        position += K;
        
        //check = position%N;
        if (position > N){
            position -= N;
        }

        count += 1;
        //cout << position << ' ' << count << endl;
        if (position == 1){
            count -= 1;
            break;
        } else if (position == T){
            break;
        }
    }

    std::cout << count << "\n";

    return 0;
}
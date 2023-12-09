#include <iostream>

using namespace std;

int main(){

    string robot1;
    cin >> robot1;

    char direction = 'N'; // N E S W
    //string robot2 = "";

    for (int i = 0 ; i < robot1.size() ; i++)
    {
        if (robot1[i] == 'N')
        {
            //cout << "\nrobot1[" << i << "] is " << robot1[i] << " Dir is " << direction << "\n";
            if (direction == robot1[i]) {cout << "F";} //{robot2 += "F";}
            else if (direction == 'W') {cout << "RF";}
            else if (direction == 'S') {cout << "RRF";}
            else if (direction == 'E') {cout << "RRRF";}
            direction = robot1[i];
        }
        else if (robot1[i] == 'E')
        {
            //cout << "\nrobot1[" << i << "] is " << robot1[i] << " Dir is " << direction << "\n";
            if (direction == robot1[i]) {cout << "F";}
            else if (direction == 'N') {cout << "RF";}
            else if (direction == 'W') {cout << "RRF";}
            else if (direction == 'S') {cout << "RRRF";}
            direction = robot1[i];
        }
        else if (robot1[i] == 'S')
        {
            //cout << "\nrobot1[" << i << "] is " << robot1[i] << " Dir is " << direction << "\n";
            if (direction == robot1[i]) {cout << "F";} 
            else if (direction == 'E') {cout << "RF";}
            else if (direction == 'N') {cout << "RRF";}
            else if (direction == 'W') {cout << "RRRF";}
            direction = robot1[i];
        }
        else if (robot1[i] == 'W')
        {
            //cout << "\nrobot1[" << i << "] is " << robot1[i] << " Dir is " << direction << "\n";
            if (direction == robot1[i]) {cout << "F";} 
            else if (direction == 'S') {cout << "RF";}
            else if (direction == 'E') {cout << "RRF";}
            else if (direction == 'N') {cout << "RRRF";}
            direction = robot1[i];
        }
        else if (robot1[i] == 'Z')
        {
            //cout << "\nrobot1[" << i << "] is " << robot1[i] << " Dir is " << direction << "\n";
            cout << "Z";
            direction = 'N';
        }
    }
}
/*
NNEESWZEE

NENENENE

*/
#include <iostream>
#include <string>

using namespace std;

string name;
string line;
int cnt = 0;

int main(){
    getline(cin,name);

    //cout << name.size() << "\n";

    getline(cin,line);

    int j = 0;
    for (int i = 0 ; i < line.size() ; i++){
        //cout << "line : " << line[i] << " j : " << j << " name : "<< name[j] << "\n";
        if (line[i] == name[j]){
            j++;
            cnt++;
        }
        if (j == name.size()) {
            j = j % name.size();
        }
    }

    cout << cnt/name.size() << "\n";
}

/*
pracha
thisisprachaheyproactivehappypramotechanochanell
*/
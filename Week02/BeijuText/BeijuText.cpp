#include <iostream>
#include <list>
#include <string>

using namespace std;

void showlist(list<char> text){
    list<char>::iterator itr;
    for (itr = text.begin() ; itr != text.end() ; ++itr) {
        cout << *itr;
    }
    cout << "\n";
}

int main(){

    list<char> text;
    string line;

    while (getline(cin,line))
    {   
        //cout << line << "\n";
        text.clear();
        list<char>::iterator itr = text.begin();
        
        for (int i = 0 ; i < line.size() ; i++)
        {
            //cout << line[i] << '\n';
            //Home Key
            if (line[i] == '[')
            {   
                //cout << "Home\n";
                itr = text.begin();
            }
            //End key
            if (line[i] == ']')
            {
                //cout << "Key\n";
                itr = text.end();
            }
            if (line[i] != '[' && line[i] != ']')
            {
                text.insert(itr,line[i]); // .insert(pos,alp)
            }
        }
        showlist(text);
    }
    return 0;
}

/*
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
*/
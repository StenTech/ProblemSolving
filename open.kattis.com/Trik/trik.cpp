#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string ops; // as operations
    cin >> ops;
    int pos = 1;
    for (auto it = ops.cbegin(); it != ops.cend(); it++){
        if(*it == 'A' && pos != 3) {
            if(pos == 2) pos = 1;
            else pos += 1;
        }
        else if(*it == 'B' && pos != 1){
            if(pos == 3)    pos = 2;
            else pos += 1;
        }
        else if(*it == 'C' && pos != 2){
            if(pos == 3)    pos = 1;
            else pos = 3;
        }
    }
    cout << pos << endl;
    return 0;
}
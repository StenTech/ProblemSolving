#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, y;

    while(cin >> x >> y){
        if(x == 0 && y == 0){
            break;
        }else{
            if(x+y == 13){
                cout << "Never speak again." << endl;
            }
            else
            {
                if (x > y)
                {
                    cout << "To the convention." << endl;
                }
                else if ( x < y)
                {
                    cout << "Left beehind." << endl;
                }
                else
                {
                    cout << "Undecided." << endl;
                }
                
                
            }
            
        }
    }
    return 0;
}
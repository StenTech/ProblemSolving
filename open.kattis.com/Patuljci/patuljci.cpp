#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int dwarves[9], del[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1}, sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> dwarves[i];
        sum += dwarves[i];
    }

    //cout << sum << endl;
    

    for (int i = 0; i < 8; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if(dwarves[i] + dwarves[j] == sum - 100) {
                del[i] = i;
                del[j] = j;
                break;
            }
        }
        
    }

    for (int i = 0; i < 9; i++)
    {
        if(del[i] == -1) {
            cout << dwarves[i] << endl;
        }
    }
    
    
    
    return 0;
}
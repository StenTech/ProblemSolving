#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, y;
    cin >> x;
    cin >> y;
    if (x > 0)
    {
        if(y < 0) cout << 4;
        else cout<< 1;
    }else
    {
        if(y < 0) cout << 3;
        else cout<< 2;
    }
    
    return 0;
}

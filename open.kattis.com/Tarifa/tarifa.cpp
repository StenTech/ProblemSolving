#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, n, m = 0;
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ms;
        cin >> ms;
        m+=ms;        
    }
    cout << (n+1)*x - m;
    return 0;
}
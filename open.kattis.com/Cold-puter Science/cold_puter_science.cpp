#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, nb = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long x;
        cin >> x;
        if(x < 0) nb++;
    }
    cout << nb;
    return 0;
}
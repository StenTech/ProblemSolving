#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    long n, p, q;
    cin >> n >> p >> q;
    long m = (long)(p+q)/n;
    if (m%2){
        cout << "opponent";
    }
    else {
        cout << "paul";
    }
    return 0;
}
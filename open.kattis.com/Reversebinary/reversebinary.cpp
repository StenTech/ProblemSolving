#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    unsigned int n;
    string reverse("");

    
    cin >> n;

    //logn = (int)ceil(log2(n));
    
    while (n != 0) {
    //for (int i = 0; i < logn + 1; i++) {
        reverse += to_string(n%2);
        n >>= 1;
    }
    
    cout << stoi(reverse, 0, 2) ;
    
    return 0;
}
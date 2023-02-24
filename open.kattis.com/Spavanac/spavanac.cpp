#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    short h, m;
    cin >> h;
    cin >> m;
    if(m >= 45){
        short m_ = m-45;
        if(h > 0) cout << h << " " << m_;
        else cout << 23 << " " << m_;
    }
    else {
        short m_ = m+15;
        if (h > 0) cout << h-1 << " " << m_;
        else cout << 23 << " " << m_;
    }
    return 0;
}
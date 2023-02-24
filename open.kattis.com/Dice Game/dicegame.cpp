#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int a1, b1, a2, b2;
    int a_1, b_1, a_2, b_2;

    cin >> a1 >> b1 >> a2 >> b2;
    cin >> a_1 >> b_1 >> a_2 >> b_2;

    if(a1+b1 + a2+b2  > a_1+b1 + a_2+b2)  {
        cout << "Gunnar";
    }else if (a1+b1 + a2+b2 < a_1+b1 + a_2+b2)  {
        cout <<  "Emma";
    }
    else {
        cout << "Tie";
    }
    return 0;
}
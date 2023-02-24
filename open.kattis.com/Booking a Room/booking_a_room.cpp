#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, r;
    int booked[101] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cin >> r >> n;
    if(n == 0){
        cout << 1;
    } else if (n < r) {
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            booked[x] = x;
        }
        int i = 1;
        while (booked[i] != 0 && i <=100)
        {
            ++i;
        }

        cout << i;
        
    } else {
        cout << "too late";
    }

    return 0;
}
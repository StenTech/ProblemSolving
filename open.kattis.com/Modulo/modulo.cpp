#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int nums[42] {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
        -1, -1, -1, -1, -1, -1
    }, tab[10], mm = 0;


    for (int i = 0; i < 10; i++)
    {
        int n, m;
        cin >> n;
        m = n % 42;
        if (nums[m] == -1) {
            nums[m] = m;
            mm++;
        }
        
    }

    cout << mm;
    
    return 0;
}
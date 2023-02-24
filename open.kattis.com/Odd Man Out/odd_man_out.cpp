#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


int main(int argc, char const *argv[]) {

    int n, t, x, odd;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        odd = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            odd ^= x;
        }
        cout << "Case #" << i + 1 << ": " << odd << endl;
    }

    return 0;
}
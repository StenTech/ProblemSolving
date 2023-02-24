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

    int t;

    cin >> t;
    // nombre impair en anglais c'est odd
    while (t--)
    {
        int n;
        cin >> n;
        int nb = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x % 2 == 1) {
                nb++;
            }
        }
        cout << nb << endl;
    }

    return 0;
}
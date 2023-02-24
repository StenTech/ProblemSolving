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

    string n, m;

    cin >> n >> m;

    for (int i = 2; i >= 0; i--) {
        if(n[i] > m[i]) {
            reverse(n.begin(), n.end());
            cout << n;
            return 0;
        } else if (n[i] < m[i]) {
            reverse(m.begin(), m.end());
            cout << m;
            return 0;
        }
    }

    return 0;
}
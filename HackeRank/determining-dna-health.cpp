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
    
    int n;
    cin >> n;
    vi genes(n);
    for (int i = 0; i < n; i++) {
        cin >> genes[i];
    }
    vi health(n);
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }
    int s;
    cin >> s;
    ll min = 0, max = 0;
    for (int a0 = 0; a0 < s; a0++) {
        int first;
        int last;
        string d;
        cin >> first >> last >> d;
        ll h = 0;
        for (int i = first; i <= last; i++) {
            int j = 0;
            for (; j < d.size(); j++) {
                if (j < genes[i].size() && d[j] != genes[i][j]) {
                    break;
                }
            }
            if (j == d.size()) {
                h += health[i];
            }
        }
        if (a0 == 0) {
            min = h;
            max = h;
        } else {
            if (h < min) {
                min = h;
            }
            if (h > max) {
                max = h;
            }
        }
    }
    cout << min << " " << max << endl;
    return 0;
}

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

    long n;

    cin >> n;

    vector<int> digits((int)log10(n) + 1);

    for (int i = digits.size() - 1; i >= 0; i--) {
        digits[i] = n % 10;
        n /= 10;
    }

    bool found = false;

    for (int i = digits.size() - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (digits[i] > digits[j]) {
                swap(digits[i], digits[j]);
                sort(digits.begin() + j + 1, digits.end());
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) cout << 0 << endl;
    else {
        for (int i = 0; i < digits.size(); i++) {
            cout << digits[i];
        }
        cout << endl;
    }
    
    return 0;
}
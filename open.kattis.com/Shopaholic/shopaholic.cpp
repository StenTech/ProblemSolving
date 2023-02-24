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

    long n, maxi = 0;
    cin >> n;
    vector<long> arr(n);
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin() + n, greater<long>());

    for (long i = 0; i < n; i++) {
        if (i % 3 == 2) {
            maxi += arr[i];
        }
    }
    cout << maxi << endl;
    return 0;
}
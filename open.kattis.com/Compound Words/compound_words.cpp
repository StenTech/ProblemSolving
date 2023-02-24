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

/*
    solution of the problem Compound Words from open.kattis.com
    https://open.kattis.com/problems/compoundwords
    
*/

int main(int argc, char const *argv[]) {

    string s;
    set<string> st;
    vector<string> v;
    while (cin >> s) {
        for (auto i : v) {
            st.insert(i + s);
            st.insert(s + i);
        }
        v.push_back(s);
    }
    for (auto i : st) {
        cout << i << endl;
    }

    return 0;
}
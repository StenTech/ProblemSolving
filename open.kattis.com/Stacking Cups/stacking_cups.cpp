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
    cin.ignore();
    vector<pair<string, int>> cups(n);

    for (int i = 0; i < n; i++) {
        string s, line;
        int r;
        getline(cin, line);
        stringstream ss(line);

        if (isdigit(line[0])) {
            ss >> r >> s;
            cups[i] = {s, r / 2};
        } else {
            ss >> s >> r;
            cups[i] = {s, r};
        }
    }

    sort(cups.begin(), cups.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second < b.second;
    });

    for (int i = 0; i < n; i++) {
        cout << cups[i].first << endl;
    }
    

    return 0;
}
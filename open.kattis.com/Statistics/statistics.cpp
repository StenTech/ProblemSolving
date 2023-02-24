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

    string line;

    int l = 0;
    while (getline(cin, line)) {
        l++;
        stringstream ss(line);
        int mini=1000001, maxi=-1000001, range = 0;
        int n;
        ss >> n;
        for (int i = 0; i < n; i++) {
            long x;
            ss >> x;
            mini = min((long)mini, x);
            maxi = max((long)maxi, x);
        }

        range = maxi - mini;

        cout << "Case " << l << ": " << mini << " " << maxi << " " << range << endl; 

    }



    return 0;
}
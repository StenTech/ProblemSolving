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

    while( cin >> n ) {
        cin.ignore();
        if (n == 0) break;
        map<string, vector<string>> m;
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            string name;
            ss >> name;
            string food;
            while (ss >> food) {
                m[food].push_back(name);
            }
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->first << " ";
            sort(it->second.begin(), it->second.end());
            for (int i = 0; i < it->second.size(); i++) {
                cout << it->second[i];
                if (i != it->second.size() - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
        

    }

    return 0;
}
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
    stringstream ss;
    string line, myword, otherword;
    map<string, string> mydico;
    while (getline(cin, line)) {
        if (line == "") {break;}
        ss << line << endl;
        ss >> myword >> otherword;
        mydico[otherword] = myword;
    }

    while (getline(cin, line)) {
        if (mydico.find(line) != mydico.end()) {
            cout << mydico[line] << endl;
        } else {
            cout << "eh" << endl;
        }
    }
    
    return 0;
}
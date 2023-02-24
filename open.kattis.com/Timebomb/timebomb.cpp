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
    solution of problem: https://open.kattis.com/problems/timebomb
*/

int main(int argc, char const *argv[]) {

    
    int n = 0, m = 4;
    string s[5], code;
    getline(cin, code);
    n = (code.size() + 1)/4;
    vector<string> codes(n); 
    //s[0] = code

    map<string, string> mm = {
        {"***,* *,* *,* *,***", "0"},
        {"  *,  *,  *,  *,  *", "1"},
        {"***,  *,***,*  ,***", "2"},
        {"***,  *,***,  *,***", "3"},
        {"* *,* *,***,  *,  *", "4"},
        {"***,*  ,***,  *,***", "5"},
        {"***,*  ,***,* *,***", "6"},
        {"***,  *,  *,  *,  *", "7"},
        {"***,* *,***,* *,***", "8"},
        {"***,* *,***,  *,***", "9"}
    };
    
    
    for (int i = 0; i < n; i++) {
        codes[i] = code.substr(i*4, 3);
    }

    while (m--)
    {

        getline(cin, code);
        
        for (int i = 0; i < n; i++)
        {
            codes[i] += "," + code.substr(i*4, 3);
        }
        
    }

    string ans = "";
    long psswd = 0;
    stringstream ss;
    
    for (int i = 0; i < n; i++)
    {
        if (mm.find(codes[i]) == mm.end())
        {
            cout << "BOOM!!" << endl;
            return 0;
        }
        ans += mm[codes[i]];
    }

    ss << ans;
    ss >> psswd;

    if (psswd % 6 == 0)
    {
        cout << "BEER!!" << endl;
    }
    else
    {
        cout << "BOOM!!" << endl;
    }


    return 0;
}

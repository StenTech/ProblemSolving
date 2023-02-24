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
    solution of problem: https://open.kattis.com/problems/apaxiaaans
*/


int main(int argc, char const *argv[]) {

    string name;
    cin >> name;
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] != name[i + 1])
        {
            cout << name[i];
        }
    }
    

    return 0;
}
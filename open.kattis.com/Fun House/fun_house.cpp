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

    int w, l;
    
    map<char, pii> directions = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}}
    };

    int j = 1; 
    while( cin >> w >> l) {
        
        if (w == 0 && l == 0) break;
        
        vector<string> house(l);
        string line;
        pii entrance;
        
        for (int i = 0; i < l; i++)
        {
            cin >> house[i];
            
            int pos = house[i].find('*');
            if (pos != string::npos) {
                entrance = {i, pos};
            }
        }
        

        
        
        char dir_l;

        if (entrance.second == 0) {
            dir_l = 'R';
        } else if (entrance.second == w - 1) {
            dir_l = 'L';
        } else if (entrance.first == 0) {
            dir_l = 'D';
        } else if (entrance.first == l - 1) {
            dir_l = 'U';
        }
        
        pii pos = entrance, dir = directions[dir_l];

        while (true) {
            
            pos.first += dir.first;
            pos.second += dir.second;

            if (pos.first == 0 || pos.first == l-1 || pos.second == 0 || pos.second == w-1) {
                //cout << pos.first << " " << pos.second << " " << dir_l << endl;
                break;
            }
            else

            if (house[pos.first][pos.second] == '/') {
               if (dir_l == 'R') {
                   dir_l = 'U';
               } else if (dir_l == 'L') {
                   dir_l = 'D';
               } else if (dir_l == 'U') {
                   dir_l = 'R';
               } else if (dir_l == 'D') {
                   dir_l = 'L';
               }
            }
            else if (house[pos.first][pos.second] == '\\') {
                if (dir_l == 'R') {
                   dir_l = 'D';
               } else if (dir_l == 'L') {
                   dir_l = 'U';
               } else if (dir_l == 'U') {
                   dir_l = 'L';
               } else if (dir_l == 'D') {
                   dir_l = 'R';
               }
            }

            dir = directions[dir_l];
        }

        house[pos.first][pos.second] = '&';

        cout << "HOUSE "  << j++ << endl;
        
        for (int k = 0; k < l; k++)
        {
            cout << house[k] << endl;
        }



        //cout << pos.first << " " << pos.second << endl;


       
        
    }

    return 0;
}
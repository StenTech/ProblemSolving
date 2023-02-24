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
typedef vector<bool> vb;
typedef vector<vb> vvb;


int main(int argc, char const *argv[]) {

    int r, c, n;

    cin >> r >> c;

    vvi grid(r, vi(c));
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    vpii directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vvi groupes(r, vi(c, 0));
    queue<pii> q;

    
    //char current_type = grid[r1][c1];
    int groupe_count = 2;

    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {

            if(groupes[j][k] != 0) {
                continue;
            }

            groupes[j][k] = groupe_count;
            q.push({j, k});

            while (!q.empty()) {

                auto current_pos = q.front();
                q.pop();
                
                for (auto dir : directions) {

                    int x = current_pos.first + dir.first;
                    int y = current_pos.second + dir.second;

                    if (x < 0 || x >= r || y < 0 || y >= c) {
                        continue;
                    }

                    if (groupes[x][y] == 0 && grid[current_pos.first][current_pos.second] == grid[x][y]) {
                        groupes[x][y] = groupes[current_pos.first][current_pos.second];                    
                        q.push({x, y});
                    }
                }
            
            }
            groupe_count++;
        
        }
    }

    

    
    cin >> n;

    for (int i = 0; i < n; i++) {
        
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        if (groupes[r1][c1] == groupes[r2][c2]) {
            if (grid[r1][c1] == 0) {
                cout << "binary" << endl;
            } else {
                cout << "decimal" << endl;
            }
        } else {
            cout << "neither" << endl;
        }    
    }
    
    return 0;

}
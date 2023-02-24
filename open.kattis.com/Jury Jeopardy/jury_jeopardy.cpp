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

/* rotation of center pair<int, int> C and angle theta of any point A */
void rotate(pair<int, int> C, double theta, pair<int, int> &A) {
    int x = A.first - C.first;
    int y = A.second - C.second;
    A.first = C.first + x * cos(theta) - y * sin(theta);
    A.second = C.second + x * sin(theta) + y * cos(theta);
}

int main(int argc, char const *argv[]) {


    map<char, pair<int, int>> orientations = {
        {'R', {1, 0}},
        {'L', {-1, 0}},
        {'U', {0, -1}},
        {'D', {0, +1}},
    };

    int n;
    cin >> n;
    cin.ignore();
    
    cout << n << endl;
    while (n--) {
        string s;
        getline(cin, s);

        pair<int, int> current_position = {0, 0};
        char orientation = 'R';

        vector<pair<int, int>> empty_squares;
        pair<int, int> min_max_x = current_position;
        pair<int, int> min_max_y = current_position;
        empty_squares.push_back(current_position);
        
        for (int j = 0; j < s.size(); j++) {
            
            pair<int, int> center = current_position;

            
            if (s[j] == 'L') {
                if (orientation == 'R') {
                    orientation = 'U';
                } else if (orientation == 'L') {
                    orientation = 'D';
                } else if (orientation == 'U') {
                    orientation = 'L';
                } else if (orientation == 'D') {
                    orientation = 'R';
                }
            } else if (s[j] == 'R') {
                if (orientation == 'R') {
                    orientation = 'D';
                } else if (orientation == 'L') {
                    orientation = 'U';
                } else if (orientation == 'U') {
                    orientation = 'R';
                } else if (orientation == 'D') {
                    orientation = 'L';
                }
            } else if (s[j] == 'F') {
                if (orientation == 'R') {
                    orientation = 'R';
                } else if (orientation == 'L') {
                    orientation = 'L';
                } else if (orientation == 'U') {
                    orientation = 'U';
                } else if (orientation == 'D') {
                    orientation = 'D';
                }
            } else if (s[j] == 'B') {
                if (orientation == 'R') {
                    orientation = 'L';
                } else if (orientation == 'L') {
                    orientation = 'R';
                } else if (orientation == 'U') {
                    orientation = 'D';
                } else if (orientation == 'D') {
                    orientation = 'U';
                }
            }
            
            current_position.first += orientations[orientation].first;
            current_position.second += orientations[orientation].second;
      
            min_max_x.first = min(min_max_x.first, current_position.first);
            min_max_x.second = max(min_max_x.second, current_position.first);
            min_max_y.first = min(min_max_y.first, current_position.second);
            min_max_y.second = max(min_max_y.second, current_position.second);
            
            empty_squares.push_back(current_position);
    
        }

        int h, w;
        h = min_max_y.second - min_max_y.first + 3;
        w = min_max_x.second - min_max_x.first + 2;
   
        cout << h << " " << w << endl;
    
        vector<vector<char>> grid(h, vector<char>(w, '#'));

        for (int i = 0; i < empty_squares.size(); i++) {
            grid[empty_squares[i].second - min_max_y.first+1][empty_squares[i].first - min_max_x.first] = '.';
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }        
    }   



    return 0;
}
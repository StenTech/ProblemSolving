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

vector<string> class_picture(int student, const vector<bitset<10>>& enemies, const vector<string>& students) {
    if (student == students.size() - 1) {
        return vector<string>(1, students[student]);
    }
    if (student < 0) {
        return students;
    }

    if(!enemies[student].test(student -1)) {
        return class_picture(student - 1, enemies, students);
    } else {
        for (int i = student - 1; i >= 0; i--)
        {
            if (enemies[student].test(i)) {
                vector<string> a = class_picture(i - 1, enemies, students);
                vector<string> b = class_picture(student - 1, enemies, students);
                if (a.size() > b.size()) {
                    a.push_back(students[student]);
                    return a;
                } else {
                    b.push_back(students[student]);
                    return b;
                }
            }
        }
    }

    auto best = class_picture(student - 1, enemies, students);




}


int main(int argc, char const *argv[]) {

    int n;
    while (cin >> n && n != 0)
    {
        
        vector<string> students = vector<string>(n);
        vector<bitset<10>> enemies = vector<bitset<10>>(n);
        

        for (int i = 0; i < n; i++)
        {
            cin >> students[i];
        }
        sort(students.begin(), students.end());

        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            string a, b;
            cin >> a >> b;

            int a_index = lower_bound(students.begin(), students.end(), a) - students.begin();
            int b_index = lower_bound(students.begin(), students.end(), b) - students.begin();

            enemies[a_index].set(b_index);
            enemies[b_index].set(a_index);
        }

        auto best = class_picture(n - 1, enemies, students);

        for (auto& s : best) {
            cout << s << " ";
        } cout << endl;
        
    }
    return 0;
}
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

ll LIMIT = 256;

class opNode {
    public:
        char op;
        vector<opNode> children = vector<opNode>();
        
        opNode() {
            op = 'r';
        }
        opNode(char op) {
            this->op = op;
        }

        void add_child(opNode child) {
            children.push_back(child);
        }

        void add_children(vector<opNode> children) {
            for (int i = 0; i < children.size(); i++) {
                this->children.push_back(children[i]);
            }
        }

        // print the tree in awesome ascii art format (kinda)
        void print_tree(int depth = 0) {
            for (int i = 0; i < depth; i++) {
                cout << "  ";
            }
            cout << op << endl;
            for (int i = 0; i < children.size(); i++) {
                children[i].print_tree(depth + 1);
            }
        }


        void construct_tree(opNode root, int depth = 4) {
            if (depth == 0) {
                return;
            }

            vector<opNode> children = vector<opNode>();
                children.push_back(opNode('+'));
                children.push_back(opNode('-'));
                children.push_back(opNode('*'));
                children.push_back(opNode('/'));

            root.add_children(children);

            for (int i = 0; i < children.size(); i++) {
                construct_tree(children[i], depth - 1);
            }
        }
};
/*
int evaluate_path(vector<opNode> path) {
    int result = path[0].value;
    for (int i = 1; i < path.size(); i++) {
        switch (path[i].op) {
            case '+':
                result += path[i].value;
                break;
            case '-':
                result -= path[i].value;
                break;
            case '*':
                result *= path[i].value;
                break;
            case '/':
                result /= path[i].value;
                break;
        }
    }
    return result;
}

void dfs(opNode root, int target, vector<opNode> path) {

    if (root.children.size() == 0) {
        if (evaluate_path(path) == target) {
            cout << "4 " << path[1].op << " 4 " << path[2].op << " 4 " << path[3].op << " 4 = " << target << endl;
            return;
        }
    }

    for (int i = 0; i < 4; i++) {
        path.push_back(root.children[i]);
        dfs(root.children[i], target, path);
        path.pop_back();
    }

    cout << "no solution" << endl;
}
*/


/*
    problem:    4 thought
    link:       https://open.kattis.com/problems/4thought
*/
int main(int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    opNode root = opNode();
    root.construct_tree(root);
    root.print_tree(0);

    /*
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        
        int target;
        cin >> target;

        if (target > LIMIT) {
            cout << "no solution" << endl;
            continue;
        }

        vector<opNode> path = vector<opNode>();
        dfs(root, target, path);
    }*/

    return 0;
}
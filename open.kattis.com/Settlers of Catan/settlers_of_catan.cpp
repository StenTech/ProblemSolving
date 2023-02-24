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
typedef set<pair<int, int>, function<bool(const pair<int, int> &, const pair<int, int> &)>> freq_set;

//int dx[] = {0, 1, 1, 0, -1, -1};
//int dy[] = {1, 1, 0, -1, -1, 0};
//vector<pair<int, int>> dirs = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}};

typedef struct tile
{
    int x, y;
    int ressource;

    // constructeur pardefaut de la structure tile
    tile() : x(0), y(0), ressource(0) {}
    // constructeur de la structure tile
    tile(int x, int y, int ressource) : x(x), y(y), ressource(ressource) {}

    bool operator==(const tile &t) const
    {
        return ressource == t.ressource;
    }
} tile;

typedef vector<tile> vt;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

// insertion d'une paire dans un set en consdérant que deux paires sont egales si leurs premieres valeurs sont egales
void insert(freq_set &freq, pii p, pii q)
{
    freq.erase(p);
    freq.insert(q);
}

vt get_neighbors(vt &tiles, tile &t)
{
    vt neighbors;
    for (int i = 0; i < 6; i++)
    {
        int x = t.x + dirs[i].first;
        int y = t.y + dirs[i].second;
        for (auto &tile : tiles)
        {
            if (tile.x == x && tile.y == y)
            {
                neighbors.push_back(tile);
            }
        }
    }
    return neighbors;
}




// selection l'iterateur de la valeur a inserer dans la sequence de tel sorte qu'elle n'est pas egale a ses voisins
freq_set::iterator select(vt &neighbors, freq_set &freq, int n)
{
    freq_set::iterator it = freq.begin();
    while (it != freq.end())
    {
        tile t(0, 0, (*it).first);
        if (find(neighbors.begin(), neighbors.end(), t) == neighbors.end())
        {
            return it;
        }
        it++;
    }
    
    return it;
}

// Fonction pour trouver les coordonnées de la tuile suivante sur le plateau de jeu
void getNextTile(int x, int y, int& nextX, int& nextY) {
  if (x % 2 == 0) {
    if (y < x) {
      nextX = x + 1;
      nextY = y;
    } else {
      nextX = x + 1;
      nextY = y - 1;
    }
  } else {
    if (y > -x) {
      nextX = x - 1;
      nextY = y;
    } else {
      nextX = x - 1;
      nextY = y + 1;
    }
  }
}

int main(int argc, char const *argv[])
{

    int c;
    cin >> c;
    
    while (c--)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        // un set freq avec un lambda qui compare les valeurs des paires si elles sont egales compare les clefs
        freq_set freq(compare);

        // initialisation du set freq
        for (int i = 1; i <= 5; i++)
        {
            freq.insert({i, 0});
        }

        // un vection d'entiers qui contient la sequence de nombres
        vt seq(n);

        // tile de depart
        tile t(0, 0, 0);

        // insertion de la tile de depart dans la sequence
        seq[0] = t;

        // mise a jour du set freq
        //insert(freq, {1, 0}, {1, 1});

        // calcul de la sequence
        int k = 0, l = 6, d=2;
        for(int i = 0; i < n; i++)
        {
            // recuperation des voisins de la tile courante
            vt neighbors = get_neighbors(seq, t);

            // affichage des voisins de la tile courante
            for (auto &tile : neighbors)
            {
                cout << tile.ressource <<" ";
            }
            cout << endl;

            // selection de la valeur de la ressource de la tile a inserer dans la sequence
            freq_set::iterator it = select(neighbors, freq, n);

            // determination des coordonnees de la tile a inserer dans la sequence
            // directions possibles pour la tile courante
            pii dir = dirs[(d+1)%6];
            
            // on parcourt les directions possibles pour la tile courante et on verifie si la tile a inserer n'est pas deja son voisin
            /*/
                int x = t.x + dir.first;
                int y = t.y + dir.second;
                bool is_neighbor = false;
                for (auto &tile : neighbors)
                {
                    if (tile.x == x && tile.y == y)
                    {
                        is_neighbor = true;
                        break;
                    }
                    
                }
                if (!is_neighbor)
                {
                    d = (d+1)%6;
                    t.x = x;
                    t.y = y;
                    break;
                }
             */

            int nextX, nextY;
            getNextTile(t.x, t.y, nextX, nextY);
            

            // determination de la ressource de la tile a inserer dans la sequence
            t.ressource = (*it).first;
            //printf("i=%d, ressource=%d, x=%d, y=%d\n", i, t.ressource, t.x, t.y);

            // determination des coordonnees de la tile a inserer dans la sequence
            t.x = nextX;
            t.y = nextY;

            // insertion de la tile dans la sequence
            seq[i] = t;

            // mise a jour du set freq
            insert(freq, {(*it).first, (*it).second}, {(*it).first, (*it).second + 1});
            
            /*if (i == l - 1)
            {
                k ++;
                l += 6;
            }*/
            
        }

        // affichage de la ressource du dernier element de la sequence
        cout << seq.back().ressource << endl;

        /*/ affichage de la sequence
        {
            cout << tile.ressource << " ";
        }*/
        cout << endl;
    }

    return 0;
}
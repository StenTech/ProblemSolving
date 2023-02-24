#include <bits/stdc++.h>

using namespace std;

double heron(double sommet1[3], double sommet2[3], double sommet3[3]){
    double a = sqrt(pow(sommet1[0] - sommet2[0], 2) + pow(sommet1[1] - sommet2[1], 2) + pow(sommet1[2] - sommet2[2], 2));
    double b = sqrt(pow(sommet1[0] - sommet3[0], 2) + pow(sommet1[1] - sommet3[1], 2) + pow(sommet1[2] - sommet3[2], 2));
    double c = sqrt(pow(sommet2[0] - sommet3[0], 2) + pow(sommet2[1] - sommet3[1], 2) + pow(sommet2[2] - sommet3[2], 2));
    double s = (a + b + c)/2;

    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double heron(double sommets[3][3]){
    
    double *sommet1 = sommets[0];
    double *sommet2 = sommets[1];
    double *sommet3 = sommets[2];
    
    return heron(sommet1, sommet2, sommet3);
}


double aire_polygona(double sommets[][3], int n_sommet) {
    
    double aire = 0;
    
    for (int i = 1; i < n_sommet-1; i++)
    {
        aire += heron(sommets[0], sommets[i], sommets[i+1]);
    }
    
    return aire;
}

void prod_vectoria(double u[3], double v[3], double w[3]) {
    
    w[0] = u[1]*v[2] - u[2]*v[1];
    w[1] = u[2]*v[0] - u[0]*v[2];
    w[2] = u[0]*v[1] - u[1]*v[0];

}

double hauteur(double base[][3], double sommet[3]){
    
    double u[3], v[3], w[3] = {0, 0, 0}, d, e;
    // Caclul de u
    u[0] = base[0][0] - base[1][0];
    u[1] = base[0][1] - base[1][1];
    u[2] = base[0][2] - base[1][2];

    // Caclul de v
    v[0] = base[0][0] - base[2][0];
    v[1] = base[0][1] - base[2][1];
    v[2] = base[0][2] - base[2][2];

    prod_vectoria(u, v, w);

    //cout << w[0] << " " << w[1] << " " << w[2] << endl << endl ;

    // base[3][2] par ce que les figures ont au moins quatre coté...
    d = -(w[0]*base[0][0] + w[1]*base[0][1] + w[2]*base[0][2]);
    e = sqrt(pow(w[0], 2) + pow(w[1], 2) + pow(w[2], 2));

    return fabs((sommet[0]*w[0] + sommet[1]*w[1] + sommet[2]*w[2] + d))/e;

}

double vol_pyramida(double base[][3], double sommet[3], int n_sommet) {
    double aire_base = aire_polygona(base, n_sommet);
    double h = hauteur(base, sommet);

    return (aire_base *h)/ 3;
}

int main(int argc, char const *argv[])
{
    int n;
    double aire = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        int V[30];
        //int sumV = 0;
        double polyhedra[30][25][3];
        //double barycenter[3] = {0, 0, 0};

        for (int j = 0; j < f; j++)
        {
            //int v;
            cin >> V[j];
            //sumV += V[j];

            for (int k = 0; k < V[j]; k++)
            {
                cin >> polyhedra[j][k][0] >> polyhedra[j][k][1] >> polyhedra[j][k][2];
                /*barycenter[0] += polyhedra[j][k][0];
                barycenter[1] += polyhedra[j][k][1];
                barycenter[2] += polyhedra[j][k][2];*/
                //cout << polyhedra[j][k][0] << " " << polyhedra[j][k][1] << " " << polyhedra[j][k][2] << " ";
            }
            //cout << endl;
            
        }

        /*barycenter[0] /= sumV;
        barycenter[1] /= sumV;
        barycenter[2] /= sumV;
        */

        //cout << sumV <<endl;
        //cout << "barycenter : " << barycenter[0] << " " << barycenter[1] << " " << barycenter[2] << endl; 
        double vvv[3] = {5, 5, 5};
        for (int j = 0; j < f; j++)
        {

            //double xaire = vol_pyramida(polyhedra[j], barycenter, V[j]);
            //double xaire = aire_polygona(polyhedra[j], V[j]);
            //double h = hauteur(polyhedra[j], barycenter);
            aire += vol_pyramida(polyhedra[j], polyhedra[0][0], V[j]);
            //cout << xaire << endl ;
            //cout << h << endl ;
        }

        //cout << vol_pyramida(polyhedra[1], polyhedra[3][1], 4) << endl;
        
    }

    //aire = ceil(aire*100.00)/100.00;
    printf("%.2f", aire);

    return 0;
}

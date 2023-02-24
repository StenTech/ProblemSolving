#include <vector>
#include "vectorfunctions.h"



void backwards(std::vector<int>& vec){
    
    int n = vec.size();
    int n2 = n/2;

    for (int i = 0; i < n2; i++)
    {
        int el = vec[i];
        vec[i] = vec[n-i-1];
        vec[n-i-1] = el;
    }
    
}

std::vector<int> everyOther(const std::vector<int>& vec){
    
    std::vector<int> ret;
    for (int i = 0; i < vec.size(); ++i)
        if (i % 2 == 0)
            ret.push_back(vec[i]);
    return ret;

}
    


int smallest(const std::vector<int>& vec){
    
    int min = vec[0];
    
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < min)
        {
            min = vec[i];
        }
        
    }

    return min;
    
}

int sum(const std::vector<int>& vec){
    
    int sum = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        sum+=vec[i];
    }
    
    return sum;
}

int veryOdd(const std::vector<int>& suchVector){
    
    int nbOdd = 0;
    
    for (int i = 0; i < suchVector.size(); i++)
    {
        if (suchVector[i] % 2 == 0 && i%2 == 0)
        {
            nbOdd++;
        }        
    }
    
    return nbOdd;
}

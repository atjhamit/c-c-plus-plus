#include "../lib/commonImport.hpp"

#define I INT32_MAX
#define N 7
#define E 9

std::vector<int> set(N+1,-1);
std::vector<int> included(E,0);
std::vector<std::pair<int,int>> result;
std::vector<std::vector<int>> edges = {
                                    {1,2,25},
                                    {1,6,5},
                                    {2,3,12},
                                    {2,7,10},
                                    {3,4,8},
                                    {4,5,16},
                                    {4,7,14},
                                    {5,6,20},
                                    {5,7,18},
};

int cfind(int x)
{
    while(set[x] > 0)
        x = set[x];

    return x;
}

void wunion(int u, int v)
{
    if((-1 * set[u]) > (-1 * set[v]))
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}

void display()
{
    for(const std::pair<int,int>& pr : result)
        LOG(pr.first << " - " << pr.second);
}

void kruskals()
{
    int u = 0, v = 0, min, i, toInclude; 
    while(result.size() < (N -1))
    {
        // find minimum edge
        min = I;
        for(i = 0; i < E; i++)
        {
            if(!included[i] && edges[i][2] < min)
            {
                min = edges[i][2];
                u = edges[i][0];
                v = edges[i][1];
                toInclude = i;
            }
        }

        // check for cycle, include otherwise
        if(cfind(u) != cfind(v))
        {
            wunion(cfind(u), cfind(v));
            result.push_back({u,v});
        }
        included[toInclude] = 1;
    }
}

int main()
{
    kruskals();
    display();
    return 0;
}

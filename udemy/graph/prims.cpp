#include "../lib/commonImport.hpp"

#define I INT32_MAX

#define N 8

std::vector<std::vector<int>> cost = { 	{I,I,I,I,I,I,I,I},
										{I,I,25,I,I,I,15,I},
										{I,25,I,12,I,I,I,10},
										{I,I,12,I,8,I,I,I},
										{I,I,I,8,I,16,I,14},
										{I,I,I,I,16,I,20,18},
										{I,5,I,I,I,20,I,I},
										{I,I,10,I,14,18,I,I}
										};

int main()
{
    std::vector<int> near(8,I);
    std::vector<std::pair<int,int>> edges;
    int i, j, row, col, min = I;

    // find minimum edge
    for(i = 1; i < N; i++)
    {
        for(j = i; j < N; j++)
        {
            if(cost[i][j] < min)
            {
                min = cost[i][j];
                row = i;
                col = j;
            }
        }
    }

    // init first edge
    edges.push_back({row,col});
    near[row] = 0;
    near[col] = 0;

    // init the near array
    for(i = 1; i < N; i++)
    {
        if(near[i])
        {
            if(cost[i][row] < cost[i][col])
                near[i] = row;
            else
                near[i] = col;
        }
    }

    // === repeating steps
    int nextEdge;
    for(i = 2; i < N-1; i++)
    {
        min = I;
        for(j = 1; j < N; j++)
        {
            if(near[j] && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                nextEdge = j;
            }
        }

        edges.push_back({nextEdge,near[nextEdge]});
        near[nextEdge] = 0;

        // update the near vector
        for(j = 1; j < N; j++)
        {
            if(near[j] && cost[j][nextEdge] < cost[j][near[j]])
                near[j] = nextEdge;
        }
    }
    // display
    for(auto pair : edges)
    {
        LOG(pair.first << " - " << pair.second);
    }
    
    return 0;
}

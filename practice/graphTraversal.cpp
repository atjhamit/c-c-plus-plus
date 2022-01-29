#include "common.hpp"

std::vector<int> bfs(std::vector<std::vector<int>>& arr, int num)
{
    int size = arr.size();
    std::vector<int> visited(size,0);
    std::vector<int> result;
    std::queue<int> q;

    result.push_back(num);
    visited[num] = 1;
    q.push(num);

    int i;
    while(!q.empty())
    {
        num = q.front(); q.pop();
        for(i = 0; i < size; i++)
        {
            if(!visited[i] && arr[num][i])
            {
                result.push_back(i);
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return result;
}

std::vector<int> dfs(std::vector<std::vector<int>>& arr, std::vector<int>& visited, std::vector<int>& result, int num)
{
    visited[num] = 1;
    result.push_back(num);

    for(int i = 0; i < arr.size(); i++)
    {
        if(!visited[i] && arr[i][num])
            dfs(arr,visited,result,i);
    }
    return result;
}

void display(std::vector<int> result)
{
    for(const int& i : result)
        LOG_T(i);
    LOG("");
}

int main()
{
    std::vector<std::vector<int>> arr = {{0,1,0,0,0,0},
                                        {1,0,0,1,0,0},
                                        {0,0,0,1,1,0},
                                        {0,1,1,0,0,1},
                                        {0,0,1,0,0,1},
                                        {0,0,0,1,1,0}}; 

    int size = arr.size();
    std::vector<int> resultbfs;
    resultbfs = bfs(arr, 2);
    display(resultbfs);

    std::vector<int> visited(size, 0);
    std::vector<int> resultdfs;
    resultdfs = dfs(arr, visited, resultdfs, 2);
    display(resultdfs);
    return 0;
}

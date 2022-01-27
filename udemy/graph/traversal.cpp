#include "../lib/commonImport.hpp"

int n;

void bfs(std::vector<std::vector<int>>& arr, int i)
{
	std::vector<int> visited(n,0);
	std::queue<int> q;
	
	visited[i] = 1;
	LOG_T(i);
	q.push(i);
	
	while(!q.empty())
	{
		i = q.front(); q.pop();
		
		for(int j = 1; j < n; j++)
		{
			if(arr[i][j] && !visited[j])
			{
				LOG_T(j);
				visited[j] = 1;
				q.push(j);
			}
		}
	}
}

std::vector<int> visited;

void performDfs(std::vector<std::vector<int>>& arr, int i)
{
	if(visited[i]) return;
	
	LOG_T(i);
	visited[i] = 1;
	
	for(int j = 1; j < n; j++)
	{
		if(arr[i][j] && !visited[j])
			performDfs(arr, j);
	}	
}

void dfs(std::vector<std::vector<int>>& arr, int i)
{
	std::vector<int> newvec(n,0);
	visited = newvec;
	performDfs(arr,i);
}

int main()
{
	std::vector<std::vector<int>> arr = {
											{0,0,0,0,0,0,0},
											{0,0,1,1,0,0,0},
											{0,1,0,0,1,0,0},
											{0,1,0,0,1,0,0},
											{0,0,1,1,0,1,1},
											{0,0,0,0,1,0,0},
											{0,0,0,0,1,0,0}
										};
	n = 7;

    LOG("bfs");
    bfs(arr,4);
    LOG("\ndfs");
    dfs(arr,4);
    LOG("");

	return 0;
}

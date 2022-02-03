#include "common.hpp"

#define I INT32_MAX

std::vector<std::vector<int>> prims(std::vector<std::vector<int>>& arr, int size)
{
    std::vector<std::vector<int>> result;
    std::vector<int> near(size, I);

    // find min cost edge
    int i, j, min = I, row, col;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                row = i;
                col = j;
            }
        }
    }

    // update result
    result.push_back({ row,col,arr[row][col] });
    // LOG("from : " << result[result.size() - 1][0] << "\tto : " << result[result.size() - 1][1] << "\tcost : " << result[result.size() - 1][2]);
    near[row] = -1;
    near[col] = -1;

    // update near array
    for (i = 0; i < size; i++)
    {
        if (near[i] != -1)
        {
            if (arr[i][row] < arr[i][col])
                near[i] = row;
            else
                near[i] = col;
        }
    }

    // -- repeating steps --
    for (i = 1; i < size-1; i++)
    {
        // find min amongst near
        min = I;
        for (j = 0; j < size; j++)
            if ((near[j] != -1) && arr[j][near[j]] < min)
            {
                min = arr[j][near[j]];
                row = j;
                col = near[j];
            }

        // updated result
        result.push_back({ row,col,arr[row][col] });
        // LOG("from : " << result[result.size() - 1][0] << "\tto : " << result[result.size() - 1][1] << "\tcost : " << result[result.size() - 1][2]);
        near[row] = -1;

        // update near array
        for (j = 0; j < size; j++)
        {
            if ((near[j] != -1) && arr[row][j] < arr[j][near[j]])
                near[j] = row;
        }
    }

    return result;
}

void display(std::vector<std::vector<int>>& result)
{
    for (const std::vector<int>& vec : result)
        LOG("from : " << vec[0] << "\tto : " << vec[1] << "\tcost : " << vec[2]);
}

int main()
{
    std::vector<std::vector<int>> arr = { {I,5,6,I,I,I},
                                        {5,I,I,7,I,I},
                                        {6,I,I,8,6,I},
                                        {I,7,8,I,3,2},
                                        {I,I,6,3,I,4},
                                        {I,I,I,2,4,I} };

    int size = arr.size();
    std::vector<std::vector<int>> result = prims(arr, size);
    display(result);

    return 0;
}

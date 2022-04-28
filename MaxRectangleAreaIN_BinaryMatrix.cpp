#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    stack<int> currentStack;
    int maxArea = 0;

    int topOfStack = 0;

    int areaWithTop = 0;
    int i = 0;
    while (i < n)
    {

        if (currentStack.empty() || heights[currentStack.top()] <= heights[i])
        {
            currentStack.push(i++);
        }
        else
        {
            topOfStack = heights[currentStack.top()];
            currentStack.pop();
            areaWithTop = topOfStack * i;

            if (!currentStack.empty())
                areaWithTop = topOfStack * (i - currentStack.top() - 1);

            maxArea = max(maxArea, areaWithTop);
        }
    }
    while (!currentStack.empty())
    {
        topOfStack = heights[currentStack.top()];
        currentStack.pop();
        areaWithTop = topOfStack * i;

        if (!currentStack.empty())
            areaWithTop = topOfStack * (i - currentStack.top() - 1);

        maxArea = max(maxArea, areaWithTop);
    }
    return maxArea;
}

int maxMatrixArea(vector<vector<int>> &matrix)
{
    int totalRows = matrix.size();
    int totalColumns = matrix[0].size();
    int maxArea = 0;

    
    vector<int> previousRow(totalColumns, 0), resultantRow(totalColumns, 0);

    for (int currentRow = 0; currentRow < totalRows; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < totalColumns; currentColumn++)
        {
            if (matrix[currentRow][currentColumn] != 0)
            {
                resultantRow[currentColumn] = previousRow[currentColumn] + matrix[currentRow][currentColumn];
            }
            else
            {
                resultantRow[currentColumn] = 0;
            }
        }

        int currentMaxArea = largestRectangle(resultantRow);

        
        maxArea = max(maxArea, currentMaxArea);

        previousRow = resultantRow;
    }
    return maxArea;
}

int main()
{

    int totalRows, TotalColumns;
    cin >> totalRows;
    cin >> TotalColumns;
    vector<vector<int>> matrix(totalRows, vector<int>(TotalColumns));
    for (int i = 0; i < totalRows; i++)
    {
        for (int j = 0; j < TotalColumns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << maxMatrixArea(matrix);
}
#include"grid.hpp"

/*
Input format:
4
2 1. 3 1. 2 1.
0. 2. 3. 5.

3
4 1. 2 1.
0. 4. 5.

8
1 0 0 1 2
1 0 3 2 2
1 3 3 1 2
2 2 3 1 1
2 2 2 0 1
1 1 2 0 0
2 1 1 0 1
2 0 1 1 1
*/

using namespace solution;

int main()
{
    size_t cornersX, cornersY, bordersAmount;
    vector<pair<uint32_t, reald>> paramsX, paramsY;
    vector<reald> intervalX, intervalY;
    vector<vector<uint32_t>> bordersParam;

    ReadData(cornersX, paramsX, intervalX,
     cornersY, paramsY, intervalY,
      bordersAmount, bordersParam);

    vector<reald> X, Y;

    SetXY(cornersX, paramsX, intervalX,
     cornersY, paramsY, intervalY,
      X, Y, bordersParam);   

    Grid myGrid(X, Y, bordersParam);

    
    return 0;
}
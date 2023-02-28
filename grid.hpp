#ifndef GRID_HPP
#define GRID_HPP
#include"libs.hpp"

namespace solution
{

    enum TypeOfNode
    {
        outSide,
        firstBorder,
        secondBorder,
        inSide
    };

    struct Node
    {
        size_t num = NAN;
        reald _x = NAN;
        reald _y = NAN;
        TypeOfNode t = outSide;
    };

    void ReadData(size_t &_cornersX, vector<pair<uint32_t, reald>> &_paramsX, vector<reald> &_intervalX,
        size_t &_cornersY, vector<pair<uint32_t, reald>> &_paramsY, vector<reald> &_intervalY,
        size_t &_bordersAmount, vector<vector<uint32_t>> &_bordersParam);

    void SetXY(size_t &_cornersX, vector<pair<uint32_t, reald>> &_paramsX, vector<reald> &_intervalX,
        size_t &_cornersY, vector<pair<uint32_t, reald>> &_paramsY, vector<reald> &_intervalY,
        vector<reald> &_X, vector<reald> &_Y, vector<vector<uint32_t>> &_bordersParam);
       
    class Grid
    {
    private:
        //size_t _nx, _ny;
        //reald _kx, _ky;
        //vector<reald> _rangeX, _rangeY, _spaceX, _spaceY;
        vector<Node> _grid;
    public:
        Grid();
        Grid(vector<reald> _X, vector<reald> _Y, vector<vector<uint32_t>> _bordersParam);
        ~Grid();
    };
}
#endif

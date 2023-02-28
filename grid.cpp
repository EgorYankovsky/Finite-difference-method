#include"grid.hpp"

namespace solution
{
    void ReadData(size_t &_cornersX, vector<pair<uint32_t, reald>> &_paramsX, vector<reald> &_intervalX,
        size_t &_cornersY, vector<pair<uint32_t, reald>> &_paramsY, vector<reald> &_intervalY,
        size_t &_bordersAmount, vector<vector<uint32_t>> &_bordersParam)
    {
        try
        {
            ifstream fin("grid.txt");
            
            fin >> _cornersX;
            _paramsX.resize(_cornersX - 1);
            for (size_t i(0); i < _cornersX - 1; i++)
            {
                fin >> _paramsX[i].first;
                fin >> _paramsX[i].second;
            }

            _intervalX.resize(_cornersX);
            for (size_t i(0); i < _cornersX; i++)
                fin >> _intervalX[i];

            fin >> _cornersY;
            _paramsY.resize(_cornersY - 1);
            for (size_t i(0); i < _cornersY - 1; i++)
            {
                fin >> _paramsY[i].first;
                fin >> _paramsY[i].second;
            }

            _intervalY.resize(_cornersY);
            for (size_t i(0); i < _cornersY; i++)
                fin >> _intervalY[i];

            fin >> _bordersAmount;
            _bordersParam.resize(_bordersAmount);
            for (vector<uint32_t> &_vect : _bordersParam)
                _vect.resize(5);

            for (size_t i(0); i < _bordersAmount; i++)
                for (size_t j(0); j < 5; j++)
                    fin >> _bordersParam[i][j];

            fin.close();

        }
        catch(const ios::failure &e)
        {
            std::cerr << e.what() << endl;
        }
        
    }


    void SetXY(size_t &_cornersX, vector<pair<uint32_t, reald>> &_paramsX, vector<reald> &_intervalX,
        size_t &_cornersY, vector<pair<uint32_t, reald>> &_paramsY, vector<reald> &_intervalY,
        vector<reald> &_X, vector<reald> &_Y, vector<vector<uint32_t>> &_bordersParam)
    {
        uint32_t amountXPoints(1), amountYPoints(1);

        for (size_t i(0); i < _cornersX - 1; i++)
            amountXPoints += _paramsX[i].first;

        for (size_t i(0); i < _cornersY - 1; i++)
            amountYPoints += _paramsY[i].first;

        _X.resize(amountXPoints);
        _Y.resize(amountYPoints);
        
        size_t iter(0);
        for (size_t i(0); i < _cornersX - 1; i++)
        {
            reald deltX = _intervalX[i + 1] - _intervalX[i];
            reald divided(0.);
            reald k(_paramsX[i].second);

            for (size_t j(0); j < _paramsX[i].first; j++)
                divided += pow(k, j);

            reald h0(deltX / divided);
            reald xCurr = _intervalX[i];
            _X[iter] = xCurr;
            while (xCurr < _intervalX[i + 1])
            {
                iter++;
                h0 *= k;
                xCurr += h0;
                _X[iter] = xCurr;
            }
        }

        iter = 0;
        for (size_t i(0); i < _cornersY - 1; i++)
        {
            reald deltY = _intervalY[i + 1] - _intervalY[i];
            reald divided(0.);
            reald k(_paramsY[i].second);

            for (size_t j(0); j < _paramsY[i].first; j++)
                divided += pow(k, j);

            reald h0(deltY / divided);
            reald yCurr = _intervalY[i];
            _Y[iter] = yCurr;
            while (yCurr < _intervalY[i + 1])
            {
                iter++;
                h0 *= k;
                yCurr += h0;
                _Y[iter] = yCurr;
            }
        }

        /*
        for (reald elem : _X)
            cout << elem << " ";
        cout << endl;
        for (reald elem : _Y)
            cout << elem << " ";
        */
        vector<Node> vect;
        vect.resize(_X.size() * _Y.size());
        //cout << vect.size();

        for (size_t i(0); i < _Y.size(); i++)
        {
            for (size_t j(0); j < _X.size(); j++)
            {
                vect[i * _Y.size() + j]._x = _X[j];
                vect[i * _Y.size() + j]._y = _Y[i]; 
                SetNodeStatus(vect[i * _Y.size() + j], _intervalX, _intervalY);
            }
        }

    }

    Grid::Grid()
    {
    }

    Grid::Grid(vector<reald> _X, vector<reald> _Y, vector<vector<uint32_t>> _bordersParam)
    {

    }

    Grid::~Grid()
    {
    }
}

#ifndef MYMATRIX_HPP
#define MYMATRIX_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <math.h>

class MyMatrix
{
private:
    std::vector<std::vector<int>> m_matrix;

    int calcDet(const std::vector<std::vector<int>>& matrix)
    {
        int det = 0;
        int sign = 1;
        if (matrix.size() == 1)
            return matrix[0][0];
        
        if(matrix.size() == 2)
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

        for (size_t col = 0; col < matrix.size(); ++col)
        {
            det += sign * matrix[0][col] * calcDet(createNewMatrix(matrix, col));
            sign = -1*sign;
        }

        return det;
    }

    std::vector<std::vector<int>> createNewMatrix(const std::vector<std::vector<int>>& matrix, int strikeOut)
    {
        int newSize = matrix.size()-1;
        std::vector<std::vector<int>> tempMatrix (newSize, std::vector<int>(newSize));

        int offCol = 0;
        for (size_t row = 0; row < newSize; ++row)
        {
            offCol = 0;
            for (size_t col = 0; col < newSize; ++col)
            {
                if (col == strikeOut)
                {
                    offCol = 1;
                }
                tempMatrix[row][col] = matrix[row+1][col+offCol];
            }
        }
        return tempMatrix;
    }

public:
    MyMatrix(int n) //Случайная матрица размерностью n
    {
        srand(time(0));
        for (size_t row = 0; row < n; ++row)
        {   
            m_matrix.push_back(std::vector<int>(n));
            for (size_t col = 0; col < n; ++col)
            {
                m_matrix[row][col] = (rand()%5-2);
            }
        }

    }

    void printMatrix() const
    {
        for (const auto& row : m_matrix)
        {
            for (const auto& col : row)
            {
                std::cout << std::setw(3) << col << " ";
            }
            std::cout << std::endl;
        }
    }

    int calcDet()
    {
        int det = 0;
        int sign = 1;
        if (m_matrix.size() == 1)
            return m_matrix[0][0];
        
        if(m_matrix.size() == 2)
            return m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0];

        for (size_t col = 0; col < m_matrix.size(); ++col)
        {
            det += sign * m_matrix[0][col] * calcDet(createNewMatrix(m_matrix, col));
            sign = -1*sign;
        }

        return det;
    }

};


#endif

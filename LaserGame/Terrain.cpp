#include "Terrain.h"
#include "Case.h"
#include <iostream>
/**
 * @brief Construct a new Terrain:: Terrain object
 *
 * @param rows
 * @param columns
 */
Terrain::Terrain(int rows, int columns) : d_rows{rows}, d_columns{columns}
{
    tab2D = new std::unique_ptr<Case> *[rows];
    for (int i = 0; i < rows; i++)
        tab2D[i] = new std::unique_ptr<Case>[columns];
}

/**
 * @brief Construct a new Terrain:: Terrain object
 *
 */
Terrain::Terrain() : d_rows{0}, d_columns{0}
{
}

/**
 * @brief Destroy the Terrain:: Terrain object
 *
 */
Terrain::~Terrain()
{
}

/**
 * @brief return d_rows
 *
 * @return int
 */
int Terrain::getRows() const { return d_rows; }

/**
 * @brief return d_columns
 *
 * @return int
 */
int Terrain::getColumn() const { return d_columns; }

/**
 * @brief modif d_rows
 *
 * @param rows
 * @return int
 */
int Terrain::setRows(int rows) { d_rows = rows; }

/**
 * @brief modif d_columns
 *
 * @param columns
 * @return int
 */
int Terrain::setColumn(int columns) { d_columns = columns; }

/**
 * @brief return pointer of Case
 *
 * @param row
 * @param column
 * @return std::unique_ptr<Case>
 */
std::unique_ptr<Case> Terrain::getCase(int row, int column) { return std::move(tab2D[row][column]); }

/**
 * @brief return char of pointer this case
 *
 * @param row
 * @param column
 * @return char
 */
char Terrain::getCharCase(int row, int column) const { return tab2D[row][column]->getChar(); }

/**
 * @brief modif case
 *
 * @param row
 * @param column
 * @param d
 */
void Terrain::setCase(int row, int column, std::unique_ptr<Case> d)
{
    tab2D[row][column] = std::move(d);
}

/**
 * @brief print terrain
 *
 */
void Terrain::affichageTexte() const
{
    for (int i = 0; i < d_rows; i++)
    {
        for (int a = 0; a < d_columns; a++)
        {
            if (tab2D[i][a] != nullptr)
                std::cout << tab2D[i][a]->getChar() << " ";
            else
                std::cout << "  ";
        }
        std::cout << i << std::endl;
    }
    for (int i = 0; i < d_columns; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief remove element in this case
 *
 * @param x
 * @param y
 */
void Terrain::removeCase(int x, int y)
{
    tab2D[x][y] = nullptr;
}



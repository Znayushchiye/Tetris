#include "../header/Grid.h"

#include <iostream>

Grid::Grid() : Tetromino()
{
  createGrid();
  printGrid();
}

void Grid::createGrid()
{
  grid = std::vector<vc>(20, std::vector<unsigned char>(11, 0)); // Create a 20x10 grid with all cells set to 0 (dead)
  for (int i = 0; i < 20; i++)
  {
    grid[i][0] = 9;  // Set the left wall to 9 (wall)
    grid[i][10] = 9; // Set the right wall to 9 (wall)
  }
  for (int i = 0; i < 11; i++)
  {
    grid[19][i] = 9; // Set the bottom wall to 9 (wall)
  }
}

void Grid::printGrid()
{
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      int cellValue = (int)grid[i][j];
      switch (cellValue)
      {
      case 0:
        std::cout << " ";
        break;
      case 1:
      case 2:
        std::cout << "X";
        break;
      case 9:
        if (i == 19)
          std::cout << "=";
        else
          std::cout << "|";
        break;
      }
    }
    std::cout << std::endl;
  }
}

int main()
{
  Grid g;
  return 0;
}
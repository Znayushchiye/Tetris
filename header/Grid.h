#pragma once

#include "Tetromino.h"
#include <vector>

class Grid : public Tetromino
{
private:
  void createGrid();
  using vc = std::vector<unsigned char>;

public:
  Grid();
  std::vector<vc> grid;
  void printGrid();
};
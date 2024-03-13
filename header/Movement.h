#pragma once

#include "Grid.h"

class Movement : public Grid
{
protected:
  Movement();
  void moveLeft();
  void moveRight();
  void moveDown();
  void rotateClockwise();
  void rotateCounterClockwise();
};
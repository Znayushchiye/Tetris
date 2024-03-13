#pragma once

#include <atomic>
#include "Movement.h"

class Game : public Movement
{
private:
  void gameLoop(Game &);
  void userInput(Game &);

public:
  std::atomic<bool> gameRunning; // Flag to check if the game is running or not
  Game();
  bool printInstructions();
  void movePiece(unsigned char &);
  bool isGameOver();
  void run();
};
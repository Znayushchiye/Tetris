#include "../header/Game.h"
#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>

using namespace std;

Game::Game() : Movement(), gameRunning(true)
{
  run();
}

void Game::userInput(Game &game)
{
  while (gameRunning)
  {
    unsigned char key = getch();
    if (key == 27) // 27 is the ASCII code for the 'Esc' key
    {
      endwin(); // End ncurses
      cout << "Are you sure you want to exit? (y/n)" << endl;
      char choice;
      cin >> choice;
      if (choice == 'y' || choice == 'Y')
        gameRunning = false;
      else
        system("clear");
    }
    else
    {
      game.movePiece(key);
      if (game.isGameOver()) // TODO: complete this function
      {
        endwin(); // End ncurses
        cout << "Game Over!" << endl;
        gameRunning = false;
      }
    }
  }
}

void Game::gameLoop(Game &game)
{
  while (gameRunning)
  {
    // Your game logic goes here
    // For demonstration, sleep for a short time
    this_thread::sleep_for(chrono::milliseconds(100));
  }
}

void Game::run()
{
  initscr(); // Initialize ncurses
  printw("Welcome to Tetris!!\n");
  printGrid();
  printInstructions(); // TODO: write this function
  refresh();           // Refresh the screen

  thread userInputThread(userInput, ref(*this));
  thread gameLoopThread(gameLoop, ref(*this));

  userInputThread.join();
  gameLoopThread.join();
}

void Game::movePiece(unsigned char &key)
{
  switch (key)
  {
  case KEY_LEFT:
    Movement::moveLeft();
    break;
  case KEY_RIGHT:
    Movement::moveRight();
    break;
  case KEY_DOWN:
    Movement::moveDown();
    break;
  case 'x':
  case 'X':
    Movement::rotateCounterClockwise();
    break;
  case 'c':
  case 'C':
    Movement::rotateCounterClockwise();
    break;
  }
}

int main()
{
  Game game;
  return 0;
}
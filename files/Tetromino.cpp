#include "../header/Tetromino.h"
#include <stdlib.h>
#include <time.h>

Tetromino::Tetromino()
{
    srand(time(0)); // Seed the RNG
    populateMap();
    currentPiece = randomPiece(); // Randomly select a piece for the game to start with
    nextPiece = randomPiece();    // Randomly select a piece as the next piece
}

void Tetromino::populateMap()
{
    // Populate PieceMap map from Pieces std::vector
    PieceMap['o'] = PieceO();
    PieceMap['i'] = PieceI();
    PieceMap['l'] = PieceL();
    PieceMap['j'] = PieceJ();
    PieceMap['s'] = PieceS();
    PieceMap['z'] = PieceZ();
}
Piece Tetromino::randomPiece()
{
    int random = rand() % 7;
    char type = PieceList[random]; // Randomly select a piece type
    int orientation = 0;
    bool canRotate = false; // 'O' piece cannot rotate

    if (random) // Check if the piece is not 'O' piece
    {
        orientation = rand() % 4; // Randomly select an orientation for non-zero pieces
        canRotate = true;         // Non-zero pieces can rotate
    }
    Piece newPiece(type, PieceMap[type][orientation], canRotate);
    return newPiece; // Return a piece with its type, orientation and rotation status
}

std::vector<std::vector<std::vector<unsigned char>>> Tetromino::PieceO()
{
    std::vector<PieceType> o =
        {{
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0},
        }};
    return o;
}

std::vector<std::vector<std::vector<unsigned char>>> Tetromino::PieceI()
{
    std::vector<PieceType> i =
        {{
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {1, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 1},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0},
         }};
    return i;
}

std::vector<std::vector<std::vector<unsigned char>>> Tetromino::PieceZ()
{
    std::vector<PieceType> z =
        {{
             {0, 0, 0, 0, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 1, 0, 0, 0},
             {0, 0, 0, 0, 0},
         }};
    return z;
}

std::vector<std::vector<std::vector<unsigned char>>> Tetromino::PieceS()
{
    std::vector<PieceType> s =
        {{
             {0, 0, 0, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 0, 1, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
         }};
    return s;
}
std::vector<std::vector<std::vector<unsigned char>>> Tetromino::PieceJ()
{
    std::vector<PieceType> j =
        {{
             {0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 1, 1},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {1, 1, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
         }};
    return j;
}
std::vector<std::vector<std::vector<unsigned char>>> Tetromino::PieceL()
{
    std::vector<PieceType> l =
        {{
             {0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 1},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {1, 1, 2, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         }};
    return l;
}
std::vector<std::vector<std::vector<unsigned char>>> Tetromino::PieceT()
{
    std::vector<PieceType> t =
        {{
             {0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
         },
         {
             {0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
         }};
    return t;
}
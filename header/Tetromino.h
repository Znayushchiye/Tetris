#pragma once

#include "Piece.h"
#include <unordered_map>

class Tetromino : public Piece
{
public:
  Tetromino();

protected:
  using vc = std::vector<unsigned char>;
  using PieceType = std::vector<vc>;

  Piece currentPiece;
  Piece nextPiece;
  Piece randomPiece();

private:
  std::unordered_map<char, std::vector<PieceType>> PieceMap;
  std::vector<char> PieceList = {'o', 'i', 'j', 'l', 's', 'z', 't'};
  std::vector<PieceType> PieceO();
  std::vector<PieceType> PieceI();
  std::vector<PieceType> PieceJ();
  std::vector<PieceType> PieceL();
  std::vector<PieceType> PieceS();
  std::vector<PieceType> PieceZ();
  std::vector<PieceType> PieceT();
  void populateMap();
};
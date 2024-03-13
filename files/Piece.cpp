#include "../header/Piece.h"

Piece::Piece()
{
  this->type = ' ';
  this->piece = {};
  this->canRotate = false;
}
Piece::Piece(const char &type, const PieceType &piece, const bool &canRotate)
{
  this->type = type;
  this->piece = piece;
  this->canRotate = canRotate;
}
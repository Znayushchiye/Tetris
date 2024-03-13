#include <vector>

class Piece
{
protected:
  using PieceType = std::vector<std::vector<unsigned char>>;

  char type;
  PieceType piece;
  bool canRotate;

public:
  Piece();
  Piece(const char &, const PieceType &, const bool &);
};
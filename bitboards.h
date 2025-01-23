#include <cstdint>
#include <iostream>

enum colors { WHITE, BLACK };

enum Pieces {
   WHITE_PAWN = 0,
   WHITE_KNIGHT,
   WHITE_BISHOP,
   WHITE_ROOK,
   WHITE_QUEEN,
   WHITE_KING,
   BLACK_PAWN,
   BLACK_KNIGHT,
   BLACK_BISHOP,
   BLACK_ROOK,
   BLACK_QUEEN,
   BLACK_KING
};

// clang-format off
enum Squares
{
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};
// clang-format on

/*
8   0 1 1 1 1 1 1 1
7   0 1 1 1 1 1 1 1
6   0 1 1 1 1 1 1 1
5   0 1 1 1 1 1 1 1
4   0 1 1 1 1 1 1 1
3   0 1 1 1 1 1 1 1
2   0 1 1 1 1 1 1 1
1   0 1 1 1 1 1 1 1

    a b c d e f g h
 */
const uint64_t not_a_file = 18374403900871474942ULL;
const uint64_t not_h_file = 9187201950435737471ULL;

inline int GET_BIT(uint64_t bitboard, int square) {
   // return 0 if 0 or 1 if 2^square
   return (bitboard >> square) & 1ULL;
}

inline void SET_BIT(uint64_t &bitboard, int square) {
   bitboard |= (1ULL << square);
}

inline void POP_BIT(uint64_t &bitboard, int square) {
   bitboard &= ~(1ULL << square);
}

void print_bitboard(uint64_t bitboard);

uint64_t init_pawn_moves(int square, int side);
uint64_t init_horse_moves(int square);

class Bitboard {

 public:
   Bitboard();

   uint64_t bitboards[12];
   uint64_t filled_squares;
   uint64_t empty_squares;

   uint64_t pawn_moves[2][64];
};
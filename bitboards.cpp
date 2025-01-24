#include "bitboards.h"

using namespace std;

Bitboard::Bitboard() {
   bitboards[WHITE_PAWN] = 0xFF00ULL;
   bitboards[WHITE_KNIGHT] = 0x42ULL;
   bitboards[WHITE_BISHOP] = 0x24ULL;
   bitboards[WHITE_ROOK] = 0x81ULL;
   bitboards[WHITE_QUEEN] = 0x10ULL;
   bitboards[WHITE_KING] = 0x8ULL;

   bitboards[BLACK_PAWN] = 0xFF000000000000ULL;
   bitboards[BLACK_KNIGHT] = 0x4200000000000000ULL;
   bitboards[BLACK_BISHOP] = 0x2400000000000000ULL;
   bitboards[BLACK_ROOK] = 0x8100000000000000ULL;
   bitboards[BLACK_QUEEN] = 0x1000000000000000ULL;
   bitboards[BLACK_KING] = 0x0800000000000000ULL;

   filled_squares = 0ULL;
   for (int i = 0; i < 12; i++) {
      filled_squares |= bitboards[i];
   }
   empty_squares = ~filled_squares;

   for (int i = 0; i < 64; i++) {
      pawn_moves[WHITE][i] = init_pawn_moves(i, WHITE);
      pawn_moves[BLACK][i] = init_pawn_moves(i, BLACK);
      knight_moves[i] = init_knight_moves(i);
   }
}

uint64_t init_pawn_moves(int square, int side) {

   uint64_t bitboard = 0ULL;
   uint64_t attack = 0ULL;

   SET_BIT(bitboard, square);

   // white
   if (!side) {
      attack |= (bitboard >> 7) & not_a_file;
      attack |= (bitboard >> 9) & not_h_file;
   }

   else {
      attack |= (bitboard << 7) & not_h_file;
      attack |= (bitboard << 9) & not_a_file;
   }

   // black

   return attack;
}

uint64_t init_knight_moves(int square) {
   uint64_t bitboard = 0ULL;
   uint64_t attack = 0ULL;
   SET_BIT(bitboard, square);

   // right-up
   attack |= (bitboard >> 6) & not_ab_file;
   // right-down
   attack |= (bitboard << 10) & not_ab_file;

   // down-right
   attack |= (bitboard << 17) & not_a_file;
   // down-left
   attack |= (bitboard << 15) & not_h_file;

   // left-up
   attack |= (bitboard >> 10) & not_gh_file;
   // left-down
   attack |= (bitboard << 6) & not_gh_file;

   // up-left
   attack |= (bitboard >> 17) & not_h_file;

   // up-right
   attack |= (bitboard >> 15) & not_a_file;

   SET_BIT(attack, square);

   return attack;
}
void print_bitboard(uint64_t bitboard) {

   for (int rank = 0; rank < 8; rank++) {

      for (int file = 0; file < 8; file++) {
         if (!file) {
            cout << (8 - rank) << "  ";
         }

         int square = rank * 8 + file;

         int bit = GET_BIT(bitboard, square);
         if (bit) {
            cout << " " << bit;
         } else {
            cout << " " << ".";
         }
      }
      cout << endl;
   }
   cout << endl << "    a b c d e f g h" << endl;

   cout << endl << "board:    " << bitboard << endl << endl;
}

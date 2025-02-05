#include "bitboards.h"

using namespace std;

Bitboard::Bitboard() {

   bitboards[WHITE_PAWN] = 0xFF000000000000ULL;
   bitboards[WHITE_KNIGHT] = 0x4200000000000000ULL;
   bitboards[WHITE_BISHOP] = 0x2400000000000000ULL;
   bitboards[WHITE_ROOK] = 0x8100000000000000ULL;
   bitboards[WHITE_QUEEN] = 0x1000000000000000ULL;
   bitboards[WHITE_KING] = 0x0800000000000000ULL;

   bitboards[BLACK_PAWN] = 0xFF00ULL;
   bitboards[BLACK_KNIGHT] = 0x42ULL;
   bitboards[BLACK_BISHOP] = 0x24ULL;
   bitboards[BLACK_ROOK] = 0x81ULL;
   bitboards[BLACK_QUEEN] = 0x10ULL;
   bitboards[BLACK_KING] = 0x8ULL;

   filled_squares = 0ULL;
   for (int i = 0; i < 12; i++) {
      filled_squares |= bitboards[i];
   }
   empty_squares = ~filled_squares;

   for (int i = 0; i < 64; i++) {
      pawn_attacks[WHITE][i] = init_pawn_attacks(i, WHITE);
      pawn_attacks[BLACK][i] = init_pawn_attacks(i, BLACK);
      knight_attacks[i] = init_knight_attacks(i);
      king_attacks[i] = init_king_attacks(i);
   }
}

uint64_t init_pawn_attacks(int square, int side) {

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

uint64_t init_knight_attacks(int square) {
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

   // SET_BIT(attack, square);

   return attack;
}
/*
NW N NE
W  K  E
SW S SE
*/
uint64_t init_king_attacks(int square) {
   uint64_t bitboard = 0ULL;
   uint64_t attacks = 0ULL;

   SET_BIT(bitboard, square);
   // SE
   attacks |= (bitboard << 9) & not_a_file;
   // E
   attacks |= (bitboard << 1) & not_a_file;
   // NE
   attacks |= (bitboard >> 7) & not_a_file;
   // SW
   attacks |= (bitboard << 7) & not_h_file;
   // W
   attacks |= (bitboard >> 1) & not_h_file;
   // NW
   attacks |= (bitboard >> 9) & not_h_file;
   // N
   attacks |= (bitboard >> 8);
   // S
   attacks |= (bitboard << 8);

   return attacks;
}

uint64_t init_bishop_attacks(int square) {
   uint64_t bitboard = 0ULL;
   uint64_t attacks = 0ULL;

   int r, f;

   int tr = square / 8;
   int tf = square % 8;

   for (r = tr + 1, f = tf + 1; r <= 6 && f <= 6; r++, f++) {
      attacks |= 1ULL << (r * 8 + f);
   }

   for (r = tr - 1, f = tf - 1; r >= 1 && f >= 1; r--, f--) {
      attacks |= 1ULL << (r * 8 + f);
   }

   for (r = tr - 1, f = tf + 1; r <= 6 && f <= 6; r--, f++) {
      attacks |= 1ULL << (r * 8 + f);
   }

   for (r = tr + 1, f = tf - 1; r >= 1 && f >= 1; r++, f--) {
      attacks |= 1ULL << (r * 8 + f);
   }

   return attacks;
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

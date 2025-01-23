#include "bitboards.h"
#include <cstdint>
#include <iostream>

using namespace std;

void test_print() {

   uint64_t board = 0ULL;
   for (int i = 0; i < 64; i++) {
      if (!((i + 1) % 8)) {
         SET_BIT(board, i);
      }
   }

   print_bitboard(~board);
}

void print_numbers() {
   for (int rank = 0; rank < 8; rank++) {

      for (int file = 0; file < 8; file++) {
         if (!file) {
            cout << (8 - rank) << "  ";
         }

         int square = rank * 8 + file;
         if (square < 10) {
            cout << "  " << square;
         } else {
            cout << " " << square;
         }
      }
      cout << endl;
   }
   cout << endl << "    a b c d e f g h" << endl;
}

int main() {
   Bitboard board;
   print_numbers();

   return 0;
}
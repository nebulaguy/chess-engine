#include "bitboards.h"
#include <cstdint>
#include <iostream>

using namespace std;

void test_print() {

   uint64_t board = 0ULL;
   for (int rank = 0; rank < 8; rank++) {
      for (int file = 0; file < 8; file++) {
         if (file != 6) {
            int square = rank * 8 + file;
            SET_BIT(board, square);
         }
      }
   }

   print_bitboard(board);
}

/*
8    0  1  2  3  4  5  6  7
7    8  9 10 11 12 13 14 15
6   16 17 18 19 20 21 22 23
5   24 25 26 27 28 29 30 31
4   32 33 34 35 36 37 38 39
3   40 41 42 43 44 45 46 47
2   48 49 50 51 52 53 54 55
1   56 57 58 59 60 61 62 63

    a  b  c  d  e  f  g  h

 */
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
   cout << endl << "    a  b  c  d  e  f  g  h" << endl;
}

int main() {
   // Bitboard board;
   print_bitboard(init_king_attacks(e2));
   // test_print();
   return 0;
}
#include <cstdint>
#include <iostream>

inline int GET_BIT(uint64_t bitboard, int index) {
  return (bitboard & (1ULL << index));
}

#define get_bit(bitboard, square_index) (bitboard & (1ULL << square_index))

void print_bitboard(uint64_t bitboard) {
  for (int rank = 0; rank < 8; rank++) {
    std::cout << (8 - rank) << "  ";
    for (int file = 0; file < 8; file++) {
      int square_index = rank * 8 + file;
      int bit = (get_bit(bitboard, square_index) ? 1 : 0);
      std::cout << " " << bit;
    }
    std::cout << std::endl;
  }
  std::cout << "\n    a b c d e f g h\n";
}

int main() {
  uint64_t board = 0ULL;
  // Set bit 52 => e2 in "a8=0" indexing
  board |= (1ULL << 52);
  print_bitboard(board);
}

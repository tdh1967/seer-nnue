#include <iostream>
#include <string>

#include <board.h>
#include <move.h>
#include <move_orderer.h>

int main(){
  std::cout << "fen: ";
  std::string fen; std::getline(std::cin, fen);
  const auto bd = chess::board::parse_fen(fen);
  chess::move_orderer picker(bd.generate_moves());
  std::cout << bd.generate_moves().data[0] << std::endl;
  picker.set_first(bd.generate_moves().data[0]);
  for(auto [idx, mv] : picker){
    std::cout << idx << ", " << mv << '\n';
  }
}

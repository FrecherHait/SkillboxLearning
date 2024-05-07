#include <iostream>
#include <cstring>

int main(){
  bool mas1[2][3] = { {false, false, false}, {false, false , false} };
  bool mas2[2][3] = { {false, false, false}, {false, false , false} };

  if (std::memcmp(mas1, mas2, sizeof(mas1)) == 0){
    std::cout << "Massive is valid" << std::endl;
  }
  else {
    std::cout << "Massive is invalid" << std::endl;
  }

  //std::cout << "Hello World!" << std::endl;
  return 0;
}
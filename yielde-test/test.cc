#include <ios>
#include <iostream>


int main() {
  int buf[4] = {};
  buf[0] = 0x12345678 & 0xff;
  buf[1] = 0x12345678 >> 8 & 0xff;
  std::cout << std::hex << buf[0] << std::endl;
  std::cout << std::hex << buf[1] << std::endl;
  return 0;
}
/**
 * Project III: Start here.
 */
#include "library.h"
#include "rnt_data_table.cpp"
#include <iostream>


int main() {
  // Sample program
  data mydata;
  int depth;
  int time;
  std::cout << "Enter a depth: ";
  std::cin >> depth;
  std::cout << "Enter a time: ";
  std::cin >> time;
  std::cout << mydata.get_Nrnt_grp(depth, time);
}

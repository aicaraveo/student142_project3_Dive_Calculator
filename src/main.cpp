/**
 * Project III: Start here.
 */
#include "library.h"
#include "rnt_data_table.cpp"
#include <iostream>

int main() {
  // Sample program
  data mydata;
  // std::vector<int> test_data = mydata.get_Nrnt(11);
  // for (int i=0; i < test_data.size(); i++){
  //   std::cout << test_data.at(i) << " ";
  // }
  std::cout << mydata.get_Nrnt_grp(20,470);
}

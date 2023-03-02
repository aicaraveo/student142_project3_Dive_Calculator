/**
 * Project III: Start testing here.
 */
#include "library.h"
#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include "rnt_data_table.cpp"

void testRNTGRP()
{
  int succeed = 0;
  std::vector<int> fails;
  data mydata;
  std::vector<int> test_grps_t = {57, 60, 61, 62, 62, 63, 63, 63, 63, 63, 63, 47, 36, 28, 21, 16, 12, 9, 6, 3, 5, 6, 4, 5};
  std::vector<int> test_grps_d = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
  std::vector<char> test_grpex = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'C', 'D', 'C', 'D'};
  for (unsigned int i = 0; i < 24; i++)
  {
    if ((mydata.get_Nrnt_grp(test_grps_d.at(i), test_grps_t.at(i))) == test_grpex.at(i))
    {

      succeed += 1;
    }
    else if ((mydata.get_Nrnt_grp(test_grps_d.at(i), test_grps_t.at(i))) != test_grpex.at(i))
    {
      fails.push_back(i);
    }
  }
  std::cout << std::endl;
  if (fails.size() > 0)
  {
    std::cout << "TEST 1 FAILED: " << std::endl;
    for (unsigned int i = 0; i < fails.size(); i++)
    {
      std::cout << "Failure at: " << fails.at(i) << std::endl;
    }
  }
  if (fails.size() == 0)
  {
    std::cout << "SUCCESS: PASSED TEST 1" << std::endl;
  }
  int succeed2 = 0;
  std::vector<int> fails2 = {1, 2, 3, 4};
  if (mydata.get_Nrnt_grp(170, 2) == 'C')
  {
    succeed2 += 1;
    fails2.at(0) = 0;
  }
  if (mydata.get_Nrnt_grp(10, 2) == 'A')
  {
    succeed2 += 1;
    fails2.at(1) = 0;
  }
  if (mydata.get_Nrnt_grp(15, 450) == 'I')
  {
    succeed2 += 1;
    fails2.at(2) = 0;
  }
  if (mydata.get_Nrnt_grp(33, 50) == 'E')
  {
    succeed2 += 1;
    fails2.at(3) = 0;
  }
  if (succeed2 == 4)
  {
    std::cout << "SUCCESS: PASSED TEST 2" << std::endl;
  }
  else
  {
    std::cout << "TEST 2 FAILED:" << std::endl;
    for (unsigned int i = 0; i < fails2.size(); i++)
    {
      if (fails2.at(i) != 0)
      {
        std::cout << "Failure at: " << fails2.at(i);
      }
    }
  }
}

int main()
{
  testRNTGRP();
}

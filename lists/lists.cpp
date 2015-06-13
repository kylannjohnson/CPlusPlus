#include <iostream>
#include <vector>
using namespace std;

struct lists {
    std::vector<int> evens;
    std::vector<int> odds;
};

bool isEven(int num) {
    return num % 2 == 0;
}

int main ()
{
  
  int ints[] = {1,21,53,84,50,66,7,38,9};
  std::vector<int> fifth (ints, ints + sizeof(ints) / sizeof(int) );
  
  struct lists yo;
  
  
  for(int i=0; i<fifth.size(); ++i) {
      if(isEven(fifth[i])) {
          yo.evens.push_back(fifth[i]);
      } else {
          yo.odds.push_back(fifth[i]);
      }
  }
  
  for(int i=0; i<yo.evens.size(); ++i) {
      cout << yo.evens.at(i) << " ";
  }
  
  cout << endl;
  
  for(int i=0; i<yo.odds.size(); ++i) {
      cout << yo.odds.at(i) << " ";
  }
  
  return 0;
}
#include <iostream>
#include <vector>

template <typename T>
void print(std::vector <T> const &a) {
   std::cout << "The vector elements are : \n";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << "\n";
}
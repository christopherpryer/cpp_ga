#pragma once

#include <iostream>
#include <vector>

void printIntVector(std::vector<int> const &a, std::string const &mstr) {
   std::cout << "The vector [" << mstr << "] elements are: ";
   for(int i=0; i < a.size(); i++)
      std::cout << a.at(i) << ' ';
   std::cout << endl;
}

void printLongVector(std::vector<long> const &a, std::string const &mstr) {
   std::cout << "The vector [" << mstr << "] elements are: ";
   for(int i=0; i < a.size(); i++)
      std::cout << a.at(i) << ' ';
   std::cout << endl;
}

void printFloatVector(std::vector<float> const &a, std::string const &mstr) {
   std::cout << "The vector [" << mstr << "] elements are: ";
   for(int i=0; i < a.size(); i++)
      std::cout << a.at(i) << ' ';
   std::cout << endl;
}
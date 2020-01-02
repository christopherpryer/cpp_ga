#include "environment.h"

int main() {
  Individual i(5);
  auto data = i.getData();

  std::cout << "unsorted: ";
  copy(begin(data), end(data),
    std::ostream_iterator<int>(std::cout, "\n"));
}
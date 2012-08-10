#include <iostream>
#include <string>
#include "sha2/sha2.h"
#include "store.h"

Store::Store(std::string path) {
  this->path = path;
  file_count = 0;
}

int Store::open() {
  std::cout << path << std::endl;
  return 0;
}

#include <iostream>
#include <string>
#include "sha2/sha2.h"
#include "store.h"

Store::Store(std::string path, int file_count) {
  this->path = path;
  this->file_count = file_count;
}

// Creates a new empty block
// returns: block id
int Store::open() {
  std::cout << path << std::endl;
  std::cout << file_count << std::endl;
  return 0;
}

// Writes data to block id
void Store::write(int id, unsigned char* data) {
}

// Finishes writing to the block id.
// returns: sha256 32 byte hash
char* Store::close(int id) {
  return new char[1];
}

// Open block sha_value for reading.
// returns: block id
int Store::open(std::string sha_value) {
  return 0;
}

// Reads len bytes starting at offset of block id into buffer.
void Store::read(int id, int offset, int len, char* buffer) {
}

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include "sha2/sha2.h"
#include "store.h"

Store::Store(std::string path, int file_count) {
  this->path = path;
  this->file_count = file_count;
}

// Creates a new empty block
// returns: block id
int Store::open() {
  std::ostringstream ss;
  ss << file_count;
  std::string full_path = path + ss.str();
  char temp[path.length() + 65];
  char hashed_result[65];
  memcpy(temp, path.c_str(), path.length());

  // Generates 64 byte hash
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, (unsigned char*)full_path.c_str(), full_path.length());
  SHA256_End64(&ctx, hashed_result);
  hashed_result[64] = '\0';

  // Concats the has to the write path
  strcat(temp, hashed_result);

  std::cout << hashed_result << std::endl;
  std::cout << temp << std::endl;

  std::fstream file(temp, std::ios::out | std::ios::app);
  file_count++;
  return file_count;
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

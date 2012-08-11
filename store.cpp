#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include "sha2/sha2.h"
#include "store.h"

using namespace std;

File::

File::File(Store& _store) : store(_store) {
    fname = store.path + string((int)this); // temporary filename for now
    SHA256_Init(&ctx);
    file = file(fname, std::ios::out | std::ios::app);
}

File::close {
   byte[64] hash;
   SHA256_End64(&ctx, hash);
   file.close();
   // rename fname to final hash (hex)
   // return hash (bytes)
}

File::write(byte *data, unint length) {
  file.write(data, length);
  SHA256_Update(&ctx, data, length);
}


Store::Store(string _path) : path(_path) {

}

// Creates a new empty block
// returns: block id
int Store::open() {

  // find an unused fd
  static uint _fd = 0;
  uint fd = -1;
  for (int i=0;i<MAX_OPEN_FILES;i++) {
    if (files[_fd] == NULL) {
      fd = _fd;
    }
    _fd = (_fd + 1) & (MAX_OPEN_FILES-1);
  }

  if (fd == -1) {
    // ERROR! MAX_OPEN_FILES are open already
    return -1;
  }

  files[fd] = new File();

  return fd;

  ss << file_count;
  std::string full_path = path + ss.str();
  char temp[path.length() + 65];
  char hashed_result[65];
  memcpy(temp, path.c_str(), path.length());H

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

  return fd;
}

// Writes data to block id
void Store::write(uint fd, unsigned char* data) {
  // wrap to file
}

// Finishes writing to the block id.
// returns: sha256 32 byte hash
byte* Store::close(uint fd) {
  File* file = files[fd];
  files[fd] = NULL;
  byte[32] ret = file->close();
  delete file;
  return ret;
}

// Open block sha_value for reading.
// returns: block id
uint Store::open(std::string hash) {
  return 0;
}

// Reads len bytes starting at offset of block id into buffer.
void Store::read(int id, int offset, int len, char* buffer) {
}

#include <string>

#ifndef _STORE_H
#define _STORE_H

#define MAX_OPEN_FILES (4096)

typedef unsigned char byte;
typedef unsigned int uint;

class Store;

class File {
  public:
    File(Store& store);
    File(Store& store, const std::string hash);
    void write(const byte *data, uint length);
    void read(uint offset, uint length, byte *data);
    byte* close();

  private:
    SHA256_CTX hash;
    fstream file;
    std::string fname;
    Store& store;
};

class Store {
  public:
    Store(std::string);
    // open a file for writing and return the fd
    uint open();

    // open a file hash for reading and return the fd
    uint open(const std::string hash);

    // write length bytes into open file fd
    void write(uint fd, const byte *data, uint length);

    // read length bytes from open file fd, beginning at offset
    void read(uint fd, uint offset, uint length, byte *data);

    // close file fd, return sha256 of the file's data
    byte* close(uint fd);

  private:
    std::string path;
    File* open_files[MAX_OPEN_FILES];
};

#endif

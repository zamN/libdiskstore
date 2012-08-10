#include <string>

#ifndef _STORE_H
#define _STORE_H
class Store {
  public:
    Store(std::string, int);
    int open();
    int open(std::string);
    void write(int, unsigned char*);
    char* close(int);
    void read(int, int, int, char*);
  private:
    std::string path;
    int file_count;
};
#endif

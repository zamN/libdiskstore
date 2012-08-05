#ifndef _STORE_H
#define _STORE_H

class Store {
  public:
    int open();
    int open(sha256);
    void write(int, void*);
    sha256 close(int);
    void read(int, int, int, char*);
};
#endif

#ifndef INDEX_H
#define INDEX_H
#include <string>
#include <cstdio>

class index
{
    public:
        index(std::string, int);
        void info_write();
        ~index();
    protected:
        int ref_length;
        std::string firstname;
        std::string format;
        std::FILE *fbuf;
};

#endif // INDEX_H

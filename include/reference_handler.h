#ifndef REFERENCE_HANDLER_H_INCLUDED
#define REFERENCE_HANDLER_H_INCLUDED

#include <string>
#include <cstdio>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

class reference_handler {
    public:
        char get_next();
        char get_current();
        char get_spec(int num);
        int get_pos();
        int get_size();
        reference_handler(const char *);
    protected:
        int pos, vector_size;
        string ref_file, header;
        FILE *ref_stream;
        vector<char> cont;
};

#endif // REFERENCE_HANDLER_H_INCLUDED

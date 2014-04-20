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
        string get_id();
        void upd_cur_contig();
        reference_handler(const char *);
    protected:
        int pos, vector_size;
        string ref_file;
        FILE *ref_stream;
        vector<char> cont;
        vector<int> id_pos;
        vector<string> id;
        int cur_contig;
};

#endif // REFERENCE_HANDLER_H_INCLUDED

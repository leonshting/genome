#ifndef PILEUP_W_H
#define PILEUP_W_H
#include <cstdio>
#include <vector>

class pileup_w
{
    public:
        pileup_w(const char *filename);
        ~pileup_w();
        void push(int pos, char ref, std::vector<char> &l, std::vector<char> &q);
    protected:
        std::FILE *f;
};

#endif // PILEUP_W_H

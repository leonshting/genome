#include "pileup_w.h"

pileup_w::pileup_w(const char * filename)
{
    f = std::fopen(filename, "w");
}

void pileup_w::push(std::string id, int pos, char ref, std::vector<char> &l, std::vector<char> &q)
{
    char *le = reinterpret_cast<char*>(l.data());
    char *qu = reinterpret_cast<char*>(q.data());
    if(le != NULL && qu != NULL)
    {
        std::fprintf(f, "%s %d %c %s %s\n",id.c_str(), pos+1, ref, le, qu);

    }
}

pileup_w::~pileup_w()
{
    std::fclose(f);
}

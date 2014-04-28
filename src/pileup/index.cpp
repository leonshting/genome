#include "index.h"

#define form "%d %s\n"

index::index(std::string name, int size)
{
    std::string tmp = name + ".index";
    firstname = name;
    ref_length = size;
    format = form;
    fbuf = std::fopen(tmp.data(),"w");
}

void index::info_write()
{
    std::fprintf(fbuf, format.data(), ref_length, firstname.data());
}

index::~index()
{
    std::fclose(fbuf);
}

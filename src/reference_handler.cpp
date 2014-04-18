#include <reference_handler.h>
#include <iostream>

reference_handler::reference_handler(const char * filename)
{
    pos = 0; //maybe not
    struct stat st;
    char tmp = 0;
    int i=0;
    stat(filename, &st);
    vector_size = st.st_size;
    cont = std::vector<char>(vector_size);
    ref_file = std::string(filename);
    ref_stream = std::fopen(filename, "r");
    while((tmp=std::fgetc(ref_stream)) != '\n')
    {
        header.push_back(tmp);
    }
    i=0;
    while((tmp=std::fgetc(ref_stream)) != EOF)
    {
        if(tmp != '\n')
        {
            cont[i++] = tmp;
        }
        else
        {
            tmp = std::fgetc(ref_stream);
            cont[i++] = tmp;
        }
    }
}

char reference_handler::get_next()
{
    pos++;
    return (pos<vector_size)?cont[pos]:'*';
}

char reference_handler::get_spec(int num)
{
    return cont[num];
}
char reference_handler::get_current()
{
    return cont[pos];
}

int reference_handler::get_pos()
{
    return pos;
}
int reference_handler::get_size()
{
    return vector_size;
}

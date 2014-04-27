#include <reference_handler.h>
#include <iostream>

reference_handler::reference_handler(const char * filename)
{
    pos = 0; //maybe not kickstart my heart
    cur_contig = 1;
    struct stat st;
    char tmp = 0;
    int i=0, flag = 0, j=0;
    stat(filename, &st);
    vector_size = st.st_size;
    cont = std::vector<char>(vector_size);
    ref_file = std::string(filename);
    ref_stream = std::fopen(filename, "r");
    std::fgetc(ref_stream);
    i = 0;
    do
    {
        string id_tmp;
        while((tmp=std::fgetc(ref_stream)) != '\n')
        {
            if (tmp != ' ' && !flag) id_tmp.push_back(tmp);
            else flag = 1;
        }
        id.push_back(id_tmp);
        j++;
        flag = 0;
        id_pos.push_back(i);
        while((tmp=std::fgetc(ref_stream)) != EOF && tmp != '>')
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
    while(tmp != EOF);
    vector_size = i;
}
void reference_handler::upd_cur_contig()
{
    if(id_pos[cur_contig-1]==pos) cur_contig++;
}
char reference_handler::get_next()
{
    return (pos<vector_size)?cont[pos++]:'*';
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
string reference_handler::get_id()
{
    upd_cur_contig();
    return id[cur_contig-1];
}

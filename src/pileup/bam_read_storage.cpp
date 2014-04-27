#include "bam_read_storage.h"

bam_read_storage::bam_read_storage(int size)
{
    abs_pos = 0;
    ref_size = size;
}

char bam_read_storage::get_new_ref(reference_handler *handler)
{
    abs_pos = handler->get_pos();
    from_ref = handler->get_next();
    return from_ref;
}

char bam_read_storage::get_cur_ref()
{
    return from_ref;
}

int bam_read_storage::get_pos()
{
    return abs_pos;
}

int bam_read_storage::push_new(BamTools::BamAlignment *al)
{
    bam_read tmp(al);
    if(tmp.get_a_pos() == abs_pos)
    {
        storage.push_back(tmp);
        return 1;
    }
    else return 0;
}

void bam_read_storage::pop_unneeded()
{
    while(!storage.empty() && storage[0].is_ended())
    {
        storage.pop_front();
    }
}

bool bam_read_storage::get_vectors(std::vector<char> *letters, std::vector<char> *qualities)
{
    if(storage.empty())
    {
        scanned = int(100.0 * abs_pos / ref_size);
        return false;
    }
    else
    {
        std::deque<bam_read>::iterator it = storage.begin(), end = storage.end();
        for(it=it; it !=end; it++)
        {
            char l,q;
            if((*it).get_next(&l,&q))
            {
                (*letters).push_back(l);
                (*qualities).push_back(q);
            }
        }
        (*letters).push_back(0);
        (*qualities).push_back(0);
        scanned = int(100.0 * abs_pos / ref_size);
    }
    return true;
}

bool bam_read_storage::is_empty()
{
    return storage.empty();
}

int bam_read_storage::get_progress()
{
    return scanned;
}

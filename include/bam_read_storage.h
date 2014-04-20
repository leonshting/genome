#ifndef BAM_READ_STORAGE_H
#define BAM_READ_STORAGE_H

#include <deque>
#include <bam_read.h>
#include <reference_handler.h>
#include <vector>


class bam_read_storage
{
    public:
        bam_read_storage(int );
        void pop_unneeded();
        int push_new(BamTools::BamAlignment *al);
        bool get_vectors(std::vector<char> *letters, std::vector<char> *qualities);
        char get_new_ref(reference_handler *handler);
        char get_cur_ref();
        int get_pos();
        int get_progress();
        bool is_empty();
    protected:
        int ref_size; //for progress count
        int abs_pos;
        char from_ref;
        int scanned;
        std::deque<bam_read> storage;
};

#endif // BAM_READ_STORAGE_H

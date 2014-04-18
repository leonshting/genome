#ifndef BAM_READ_H
#define BAM_READ_H

#include <vector>
#include <api/BamAlignment.h>

class bam_read
{
    public:
        bam_read(BamTools::BamAlignment *al);
        bool is_ended();
        int get_next(char *letter, char *quality);
        int get_a_pos();
        int get_cur_pos();
        int get_a_cur_pos();


    protected:
        int length, a_pos, cur_pos;
        std::vector<char> letters, qualities;
        bool ended, is_reverse, is_back_complement;
};

#endif // BAM_READ_H

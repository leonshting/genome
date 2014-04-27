#include <bam_read.h>
using namespace BamTools;

bam_read::bam_read(BamTools::BamAlignment *al)
{
    length = al->Length;
    a_pos = al->Position;
    cur_pos = 0;
    is_back_complement = al->IsSecondMate();
    is_reverse = al->IsReverseStrand();
    letters = std::vector<char>(al->AlignedBases.begin(),al->AlignedBases.end());
    qualities = std::vector<char>(al->Qualities.begin(),al->Qualities.end());
    ended = false;
}

bool bam_read::is_ended()
{
    return ended;
}

int bam_read::get_next(char *letter, char *quality)
{
    if(cur_pos < length)
    {
        *letter = letters[cur_pos];
        *quality = qualities[cur_pos++];
        if(cur_pos == length)
        {
            ended = true;
            return 1;
        }
        return 2;
    }
    else return 0;
}

int bam_read::get_a_cur_pos()
{
    return a_pos+cur_pos;
}

int bam_read::get_a_pos()
{
    return a_pos;
}

int bam_read::get_cur_pos()
{
    return cur_pos;
}

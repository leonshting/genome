#include <iostream>
#include <deque>

#include <api/BamReader.h>
#include <api/BamWriter.h>
#include <api/BamAlignment.h>
#include <api/SamHeader.h>
#include <api/BamAux.h>
#include <reference_handler.h>
#include <pileup_w.h>
#include <bam_read_storage.h>

using namespace std;
using namespace BamTools;

int main(int argc, char * argv[])
{
    if(argc<4)
    {
        cout << "Not enough arguments" << endl;
        return -2;
    }
    bool die_flag = true, fuckup=false;
    const char * inputBam = argv[1];
    const char * inputRef = argv[2];
    const char * out_pileup = argv[3];
    BamReader BReader;
    BamAlignment BAl;
    pileup_w puWriter(out_pileup);
    reference_handler ref(inputRef);
    bam_read_storage storage(ref.get_size());
    if (!BReader.Open(inputBam))
    {
        cerr << "Could not open input BAM file." << endl;
        return -1;
    }
    while(!storage.is_empty() || die_flag)
    {
        vector<char> let, qua;
        storage.get_new_ref(&ref);
        do
        {
            if(!fuckup) die_flag = BReader.GetNextAlignment(BAl);
            fuckup = false;
        }
        while(die_flag && storage.push_new(&BAl));
        fuckup = true;
        storage.get_vectors(&let, &qua);
        puWriter.push(storage.get_pos(),storage.get_cur_ref(),let,qua);
        cout << storage.get_progress() << "%";
        printf("\n\033[F\033[J");
        storage.pop_unneeded();
    }
    BReader.Close();
    return 0;
}

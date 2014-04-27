#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define MAX_BUF 1000
#define precision1 4 //number of min nucleotides
#define precision2 43 //medium quality


int main(int argc, char *argv[])
{
    int fd, pos, length;
    char id_buf[100];
    char ref;
    char let[MAX_BUF], qua[MAX_BUF];
    FILE *inp = fopen(argv[1], "r"), *atgc=fopen(argv[2], "w"), *mut = fopen(argv[3], "w");
    while(fscanf(inp, "%s %d %c %s %s", id_buf, &pos, &ref, let, qua) == 5)
    {
        length = strlen(let);
        if(length > precision1)
        {
            double q[4]= {0.0};
            int medium = 0,membered[4] = {0};
            char letters[4]= {'A','T','G','C'};
            int i=0;
            do
            {
                switch(let[i])
                {
                case 'A':
                    q[0]+= (double)((double)qua[i] - 33.0)/(-10.0);
                    membered[0] = 1;
                    break;
                case 'T':
                    q[1]+= (double)((double)qua[i] - 33.0)/(-10.0);
                    membered[1] = 1;
                    break;
                case 'G':
                    q[2]+= (double)((double)qua[i] - 33.0)/(-10.0);
                    membered[2] = 1;
                    break;
                case 'C':
                    q[3]+= (double)((double)qua[i] - 33.0)/(-10.0);
                    membered[3] = 1;
                    break;
                }
                medium+= qua[i];
            }
            while(i++<length);
            medium/= length;
            if(medium > precision2)
            {
                int min_num = 0;
                double min = q[0];
                for(i=1; i<length; i++)
                {
                    if(q[i] < min && membered[i])
                    {
                        min = q[i];
                        min_num = i;
                    }
                }
                if(letters[min_num] != ref)
                {
                    fprintf(mut, "%d: %c\n", pos, letters[min_num]);
                    fprintf(atgc, "%d: %c: %.1lf, %c: %.1lf, %c: %.1lf, %c: %.1lf\n",
                            pos,letters[0], q[0],letters[1], q[1],letters[2], q[2],letters[3], q[3]);
                }
            }
        }
    }
    fclose(mut);
    fclose(atgc);
    fclose(inp);
    return 0;
}

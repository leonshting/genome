#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    FILE *f=fopen(argv[1],"r");
    char c,codo[3],seq[1000000];
    int i=0,j=1,flag=0,length;
    while((c=fgetc(f))!='\n');
    while((c=fgetc(f))!=EOF)
    {
        if(c=='\n')
        {
            c = fgetc(f);
        }
        seq[i++]=c;
    }
    length = i;
    i=0;
    if(strcmp(argv[2],"straight")==0)
    {
        while(j<length+1)
        {
            c = seq[j-1];
            if(flag) codo[i++] = c;
            else
            {
                codo[0]=codo[1];
                codo[1]=codo[2];
                codo[2]=c;
                i=3;
            }
            if(i == 3 && strcmp(codo, "ATG") == 0 && flag == 0)
            {
                i=0;
                printf("start : %d\n",j);
                flag=1;
                getchar();
            }
            else if(i==3 && (strcmp(codo,"TAA")==0 ||strcmp(codo,"TGA")==0 ||strcmp(codo,"TAG")==0)&& flag == 1)
            {
                i=0;
                printf("stop : %d\n%s\n",j,codo);
                flag=0;
                getchar();
            }
            else if(i == 3)
            {
                i=0;
            }
            j++;
        }
    }
    else if(strcmp(argv[2],"reverse")==0)
    {
        j=length-1;
        while(j>=1)
        {
            c = seq[j-1];
            if(flag) codo[i++] = c;
            else
            {
                codo[0]=codo[1];
                codo[1]=codo[2];
                codo[2]=c;
                i=3;
            }
            if(i == 3 && strcmp(codo, "TAC") == 0 && flag == 0)
            {
                i=0;
                printf("reverse strand start : %d\n%s\n",j,codo);
                flag=1;
                getchar();
            }
            else if(i==3 && (strcmp(codo,"ATT")==0 ||strcmp(codo,"ACT")==0 ||strcmp(codo,"ATC")==0)&& flag == 1)
            {
                i=0;
                printf("reverse strand stop : %d\n%s\n",j,codo);
                flag=0;
                getchar();
            }
            else if(i == 3)
            {
                i=0;
            }
            j--;
        }
    }
    fclose(f);
    return 0;
}


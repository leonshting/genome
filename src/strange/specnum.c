#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    FILE *f=fopen(argv[1],"r");
    char c,seq[1000000];
    int i=0,j=1,flag=0,n1,n2;
    while((c=fgetc(f))!='\n');
    while((c=fgetc(f))!=EOF)
    {
        if(c=='\n')
        {
            c = fgetc(f);
        }
        seq[i++]=c;
    }
    while(1)
    {
        scanf("%d %d",&n1,&n2);
        int g;
        for(g=n1;g<=n2;g++)
        {
            putc(seq[g-1],stdout);
        }
        putc('\n',stdout);
    }
    return 0;
}

class codon
int coden,codem         // *n - normal , *m- mutation
int codons[6][21]=      // A=1, T=2, G=3, C=4
 {
     {222,221,122,321,241,441,141,341,212,412,411,112,111,312,311,232,233,431,331,211,123},
     {224,223,121,322,242,442,142,342,214,414,413,114,113,314,313,234,  0,432,332,213,  0},
     {  0,421,124,323,243,443,143,343,  0,  0,  0,  0,  0,  0,  0,  0,  0,433,333,231,  0},
     {  0,422,  0,324,244,444,144,344,  0,  0,  0,  0,  0,  0,  0,  0,  0,434,334,  0,  0},
     {  0,423,  0,  0,132,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,131,  0,  0,  0},
     {  0,424,  0,  0,134,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,133,  0,  0,  0}
 };

char  Aminok[21][4]=
{"Phe", "Leu","Ile","Val","Ser","Pro", "Thr", "Ala", "Tyr", "His","Gin","Asn", "Lys", "Asp","Glu","Cys","Trp","Arg","Gly", "Beg", "End"};

public:
    void extraction()
 void compare (int coden,int codem, int pos){
    int i=0;
    int j=0;
    int l=0;
    int k=0;
    while (j<=21)
    {while (i<=6)
        {if (codons[i][j]==coden)
            k=j;
         if (codons[i][j]==codem)
            l=j;
         i++;
         }
    i=0;
    j++;
    }
   if (k!=l)
   cout <<"In position "<<pos<< " no sinonimic  " << Aminok[k] << "->" << Aminok[l];
   if (k==l)
   cout <<"In position "<<pos<< " sinonimic  " << Aminok[k];
    }

 return 0;
}

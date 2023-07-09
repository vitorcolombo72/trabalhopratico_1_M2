#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
char * longestNiceSubstring(char * s){
    int j = strlen(s);
    bool verif= false;
    int a,b,c= 0,d = 0;
    char v1,v2,v3,v4;
    printf("%d",j);
    char guarda[200][200];
    for(int i = 0;i<j;i++){

        while((int)(s[i]) == (int)(s[i+1]+32) || (int)(s[i]) == (int)(s[i+1]-32) || (int)(s[i-1]) == (int)(s[i]+32) || (int)(s[i-1]) == (int)(s[i]-32) ){
            verif = true;
           guarda[d][c] = s[i];
           c++;
           i++;
        }
        if(verif == true){
            d++;
            verif = false;
           }
        c = 0;    
    }
    printf("%s",guarda[1]);
}

int main(int argc, char const *argv[])
{
    char s = longestNiceSubstring("abcdDdDdaeEefg");
    
 
    return 0;
}

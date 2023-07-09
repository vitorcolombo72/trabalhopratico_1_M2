#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char * longestNiceSubstring( char * s );

int main()
{
    char *s = "a";
    printf("%s",longestNiceSubstring(s));
 
    return 0;
}
/*
====================
longestNiceSubstring
 exercício 1763 leetcode
====================
*/
char * longestNiceSubstring( char * s ){
    int j = strlen(s);
    int a2 = 0, a = 0, c = 0;
    char **token = (char**)malloc(50 * sizeof(char*));
    char *guarda = (char*)malloc(1000 * sizeof(char));
    char *guarda2 = (char*)malloc(1500 * sizeof(char)); 
    int maximo = 0;
    int maxIndex = -1;
    // Separando todas subpalavras em na substring guarda
    for( int i = 0 ; i<j ; i++ ){
        while( (int)(s[i]) == (int)(s[i+1]+32) || (int)(s[i]) == (int)(s[i+1]-32) || (int)(s[i-1]) == (int)(s[i]+32) || (int)(s[i-1]) == (int)(s[i]-32) ){
           guarda[c] = s[i];
           c++;
           i++;
        } 
    }
    // Adicionando "/" entre cada subpalavra
    for( int i = 0 ; i<strlen(guarda) ; i++ ){
        if( toupper(guarda[i]) != toupper(guarda[i-1]) ){
            guarda2[i+a] = '/';
            a++;
        } 
        guarda2[i+a] = guarda[i];
    }
    // Separando a string em várias strings
    token[a2] = strtok(guarda2,"/");
    a2++;
    while( a2<50 ){
        token[a2] = strtok(NULL,"/");
        a2++;
    }
    a = 0; 
    // Encontrando a maior delas  
    for ( int i = 0 ; i < sizeof(token)/sizeof(token[0]) ; i++) {
        if ( token[i] != NULL ) {
            int tam = strlen(token[i]);
            if ( tam > maximo ) {
                maximo = tam;
                maxIndex = i;
            }
        }
    }
    // Retornando a maior
   if ( maxIndex != -1 ) {
        return token[maxIndex];
    } else {
        return "\0";
    }  
}
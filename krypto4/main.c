#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

int podstawa, modulo;
long int  wykladnik;


scanf("podstawa: %i", &podstawa);
scanf("wykladnik: %li ", &wykladnik);
//scanf("modulo: %i", &modulo);


long int temp = wykladnik;

printf("wykladnik: %li " , temp);


scanf("podstawa: %i", &podstawa);

printf(" podstawa: %i" , podstawa);

int wykladnik_bin[64];
memset(wykladnik_bin,0,64*sizeof(int));

int i=0;

while(temp>0){
    wykladnik_bin[64-i]=temp%2;
    temp=temp/2;
}

for(i=0;i<64;i++){
    printf("%i",wykladnik_bin[i]);
}


    return 0;
}

#include<stdio.h>
#include<time.h>
#include<math.h>
#include <stdlib.h>
#include<unistd.h>

// helper program to set values of address randomly
int main(){
    time_t t;
    srand((unsigned) time(&t));
    FILE *address = fopen("address.txt", "w");
    for(int i=0;i<100;i++){
        int x = rand()%65536;
        fprintf(address,"%d\n",x);
    }
    return 0;
}
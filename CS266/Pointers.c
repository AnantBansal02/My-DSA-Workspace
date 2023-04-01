#include<stdio.h>
int main(){
    int a = 24;
    int *aptr = &a;
    printf("%p\n",aptr);
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr = arr;
    for(int i=0;i<10;i++){
        printf("%d", *ptr);
        printf("->%p ", ptr);
        ptr++;

    }
    // printf("%p ",arr);
}
// &ptr gives address of pointer
// ptr gives address of variable
// *ptr gives value of the variable
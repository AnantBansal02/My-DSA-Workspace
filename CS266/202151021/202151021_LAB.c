#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<unistd.h>

int physical[65536];
int page_table[256];
int TLB[32][2];

int binary_search(int target, int l, int h){
    if(l>h){
        return -1;
    }
    int mid = l + (h-l)/2;
    if(TLB[mid][0] == target){
        return mid;
    }
    else if(TLB[mid][0]>target){
        return binary_search(target,l,mid-1);
    }
    return binary_search(target,mid+1,h);
}
int main(){
    FILE *addresses = fopen("address.txt", "r");
    FILE *output = fopen("output.txt", "w");

    // setting the initial frames in page_table
    for(int i=0;i<256;i++){
        page_table[i] = 256*(i);
    }

    // setting the TLB
    int idx = 0;
    for(int i=0;i<32;i++){
        TLB[i][0] = idx;
        TLB[i][1] = page_table[idx];
        idx += 8;
    }

    // setting physical Memory
    for(int i=0;i<65536;i++){
        physical[i] = i;
    }
    int count = 0;
    int logical_address;
    while (fscanf(addresses, "%d", &logical_address) != EOF){
        int page_number = logical_address >> 8;
        int offset = logical_address - 256*page_number;
        int frame;
        int x =  binary_search(page_number,0,31);
        if(x!=-1){
            // TLB Hit!!!
            frame = TLB[x][1] + offset;
            count += 1;
            fprintf(output, "The Virtual Address Page Number = %d and Offset =  %d available at Frame Number %d\n",
                page_number, offset, physical[frame]);
            continue;
        }
        else{
            // TLB didn't hit so searching in linear time!
            for(int i=0;i<256;i++){
                if(i == page_number){
                    frame = page_table[i] + offset;
                    break;
                }
            }
            fprintf(output, "The Virtual Address Page Number = %d and Offset =  %d available at Frame Number %d\n",
                page_number, offset, physical[frame]);
            continue;
        }
    }
    fprintf(output,"Page Fault Rate = %d/100\n", (100-count));
    fprintf(output,"TLB Hit Count = %d/100\n", count);
}
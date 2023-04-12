#include <stdio.h>
#include <stdlib.h>

#define PAGE_TABLE_SIZE 256
#define TLB_SIZE 32
#define FRAME_SIZE 256
#define PHYSICAL_MEMORY_SIZE 65536

typedef struct{
    unsigned char page_num;
    unsigned char frame_num;
    int last_used;
} tlb_entry;

typedef struct
{
    unsigned char frame_num;
    int last_used;
    int present;
} page_table_entry;

tlb_entry tlb[TLB_SIZE];
page_table_entry page_table[PAGE_TABLE_SIZE];
unsigned char physical_memory[PHYSICAL_MEMORY_SIZE];
int tlb_hit_count = 0;
int page_fault_count = 0;

void clear_tlb()
{
    for (int i = 0; i < TLB_SIZE; i++)
    {
        tlb[i].page_num = 0;
        tlb[i].frame_num = 0;
        tlb[i].last_used = 0;
    }
}

void clear_page_table()
{
    for (int i = 0; i < PAGE_TABLE_SIZE; i++)
    {
        page_table[i].frame_num = 0;
        page_table[i].last_used = 0;
        page_table[i].present = 0;
    }
}

int search_tlb(unsigned char page_num)
{
    for (int i = 0; i < TLB_SIZE; i++)
    {
        if (tlb[i].page_num == page_num)
        {
            tlb[i].last_used = 0;
            for (int j = 0; j < TLB_SIZE; j++)
            {
                if (tlb[j].last_used > tlb[i].last_used)
                {
                    tlb[j].last_used++;
                }
            }
            return tlb[i].frame_num;
        }
    }
    return -1;
}

void add_to_tlb(unsigned char page_num, unsigned char frame_num)
{
    int oldest_index = 0;
    for (int i = 0; i < TLB_SIZE; i++)
    {
        if (tlb[i].last_used > tlb[oldest_index].last_used)
        {
            oldest_index = i;
        }
    }
    tlb[oldest_index].page_num = page_num;
    tlb[oldest_index].frame_num = frame_num;
    tlb[oldest_index].last_used = 0;
    for (int i = 0; i < TLB_SIZE; i++)
    {
        if (i != oldest_index && tlb[i].last_used < 15)
        {
            tlb[i].last_used++;
        }
    }
}

int search_page_table(unsigned char page_num)
{
    if (page_table[page_num].present == 1)
    {
        page_table[page_num].last_used = 0;
        for (int i = 0; i < PAGE_TABLE_SIZE; i++)
        {
            if (page_table[i].last_used > page_table[page_num].last_used)
            {
                page_table[i].last_used++;
            }
        }
        return page_table[page_num].frame_num;
    }
    return -1;
}

void handle_page_fault(unsigned char page_num, unsigned char offset, FILE *backing_store)
{
    fseek(backing_store, page_num * FRAME_SIZE, SEEK_SET);
    fread(physical_memory + page_fault_count * FRAME_SIZE, sizeof(char), FRAME_SIZE, backing_store);
    page_table[page_num].frame_num = page_fault_count;
    page_table[page_num].last_used = 0;
    page_table[page_num].present = 1;
    page_fault_count++;
    add_to_tlb(page_num, page_fault_count);
}

int main()
{
    FILE *addresses = fopen("address.txt", "r");
    FILE *backing_store = fopen("BACKING_STORE.bin", "rb");
    FILE *output = fopen("output.txt", "w");
    clear_tlb();
    clear_page_table();

    int logical_address;
    unsigned char page_num, offset, physical_address;
    while (fscanf(addresses, "%d", &logical_address) != EOF)
    {
        page_num = (unsigned char)(logical_address >> 8);
        offset = (unsigned char)logical_address;

        int frame_num = search_tlb(page_num);
        if (frame_num != -1)
        {
            tlb_hit_count++;
        }
        else
        {
            frame_num = search_page_table(page_num);
            if (frame_num == -1)
            {
                handle_page_fault(page_num, offset, backing_store);
                frame_num = page_table[page_num].frame_num;
            }
            add_to_tlb(page_num, frame_num);
        }

        physical_address = frame_num * FRAME_SIZE + offset;
        fprintf(output,"Virtual address(at frame no.) \t Physical Address \t ");
        fprintf(output, "The virtual address %d is available at frame number %d.\n", logical_address, frame_num);
        fprintf(output, "The physical address is %d.\n", physical_address);
        fprintf(output, "The value of the byte is %d.\n", physical_memory[physical_address]);
    }

    double page_fault_rate = (double)page_fault_count / (double)PAGE_TABLE_SIZE;
    double tlb_hit_rate = (double)tlb_hit_count / (double)PAGE_TABLE_SIZE;
    fprintf(output, "Page-fault rate: %f\n", page_fault_rate);
    fprintf(output, "TLB hit rate: %f\n", tlb_hit_rate);

    fclose(addresses);
    fclose(backing_store);
    fclose(output);

    return 0;
}
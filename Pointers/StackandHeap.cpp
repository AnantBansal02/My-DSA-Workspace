/*
Stack has got limited memeory whereas Heap has variable memory
Local global variable
memory allocation deallocation automatic manual;
int main()
{
    int a = 10; <-- Stored in Stack

    int *p = new int();  <-- Stored in Heap

    *p = 10; <-- p is a pointer pointing to memory address in Heap
    values stored in Heap acts as a global variable

    delete(p); <-- Used to deallocate memory in Heap

    pointer itself was stored in Stack so now p is pointing to nothing
    Dangling Pointer!!!

    p = new int[4]; we dont need to declare p again!(reusing the pointer)
    pointer is pointing to array of size 4
    pointer stores the address of 0th index element of array

    delete[]p; <-- deallocate the memory in Heap 
    again dangling pointer

    p = NULL; <-- delete pointer from stack

}
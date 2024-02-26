#include <stdio.h>

int main()
{
    int x = 5;
    int y = 3;
    int a = 0x8000;
    int b = -1;
    int res;
    
    unsigned int uintb = (unsigned int) (b);
    printf("int to uint %u\n", ((unsigned int)(b))>>((sizeof(int)*8)-1 ));
    // printf("size of int %ld\n", sizeof(int));
}

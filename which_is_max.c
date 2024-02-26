#include <stdio.h>
#include <time.h>

#define shift_max_right( datatype, var ) ( ((unsigned datatype)(var))>>((sizeof(datatype)*8)-1 ) )

int set_max(int currentMax, int nextMax);
int set_max(int currentMax, int nextMax)
{
    int newMax; 
    newMax = currentMax + (nextMax-currentMax)*(shift_max_right( int, currentMax - nextMax ) );
    return newMax;
}

int test_set_max_lowerNextVal()
{
    int currentVal = 5;
    int nextVal = 4;
    int res = 0;

    res = set_max(currentVal, nextVal);
    
    if( res == currentVal )
        printf("PASS: %d\n", res );

}

int test_set_max_higherNextVal()
{
    int currentVal = 5;
    int nextVal = 7;
    int res = 0;

    res = set_max(currentVal, nextVal);
    
    if( res == nextVal )
        printf("PASS: %d\n", res );

}

void test_main()
{
    clock_t begin = clock();

    // uncomment the following if need to test big O(n) where n is max of int
    // int i = 0;
    // while(i++ < 0x7FFFFFFF); 

    test_set_max_lowerNextVal();
    test_set_max_higherNextVal();

    clock_t end = clock();
    double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;

    printf("time spent: %f\n", time_spent);
}

int main()
{
    test_main();
}


#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
    int I;           //Index Variable
    int Sum =0;         // Summation Variable
    for (I= 0; I < len; ++I)
	{
	    Sum = Sum + array[I];
	}
    return Sum;
}

int arrayCountNegative(int * array, int len)
{
    int I, Count = 0;        //Index Variable and Count Variable
    for (I=0; I < len; ++I)
        {
            if (array[I] < 0)
                {
                    ++Count;
                }
        }
    return Count;
}

int arrayIsIncreasing(int * array, int len)
{    
    return 0;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    return 0;
}

int arrayFindSmallest(int * array, int len)
{
    return 0;
}









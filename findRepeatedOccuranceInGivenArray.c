#include <stdio.h>
#include <stdlib.h>

#undef FEQUENCY_OF_OCCURANCES_DEBUG

#define swap(a,b) \
    do { \
        (a)^=(b); \
        (b)^=(a); \
        (a)^=(b); \
    } while (0);
    
void PrintFrequent(int arr[],int len)
{
    int pos = 0;    
    while(pos < len)
    {
        int expectedPos = arr[pos] - 1;
        if(arr[pos] > 0 && arr[expectedPos] > 0){
            swap(arr[pos], arr[expectedPos]);
            arr[expectedPos] = -1;
        }
        else if(arr[pos] > 0){
            arr[expectedPos] --;
            arr[pos ++] = 0;
        }
        else{
            pos ++;
        }       
    }
}

void DoTest(int* arr, int len)
{
    printf("The array is \n");
    for(int i = 0; i < len; ++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("The output is \n");
    
    PrintFrequent(arr, len);
    
    for(int i = 0; i < len; ++i){
        printf("(%d) ---- %d\n",i+1, abs(arr[i]));
    }
    printf("\n");
}

#ifdef FEQUENCY_OF_OCCURANCES_DEBUG
// Assume the len >= max(arr[i])
int main(int argc, char* argv[])
{
    int arr[] = {9,9,9,9,9,9,9,8,7,9,9};
    DoTest(arr, sizeof(arr)/ sizeof(arr[0]));

    int arr1[] = {1};
    DoTest(arr1, sizeof(arr1)/ sizeof(arr1[0]));

    int arr3[] = {4, 4, 4, 4};
    DoTest(arr3, sizeof(arr3)/ sizeof(arr3[0]));

    int arr2[] = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9, 1};
    DoTest(arr2, sizeof(arr2)/ sizeof(arr2[0]));

    int arr4[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    DoTest(arr4, sizeof(arr4)/ sizeof(arr4[0]));

    int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    DoTest(arr5, sizeof(arr5)/ sizeof(arr5[0]));

    int arr6[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    DoTest(arr6, sizeof(arr6)/ sizeof(arr6[0]));

    return 0;
}
/* We can also use the another method increment the values instead of decrement them. 
http://www.geeksforgeeks.org/count-frequencies-elements-array-o1-extra-space-time/
*/
#endif

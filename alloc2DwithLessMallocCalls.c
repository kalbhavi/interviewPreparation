#include <stdio.h>
#include <stdlib.h>

#undef ALLOC2D_DEBUG

/* This function assumes that the 2D array is of the integer members only. Any other type of the allocation
    requires additional argument as type */
int** malloc2d(int rows, int cols)
{
    int rowHeadersCount = 0, dataMembersCount = 0;
    int **rowBasePtr = NULL;
    int * tempBufPtr = NULL;
    int k = 0;
    
    rowHeadersCount = rows * sizeof(int *);
    dataMembersCount = rows * cols * sizeof(int);
    rowBasePtr = (int**)malloc(rowHeadersCount + dataMembersCount);
    
    if (rowBasePtr == NULL)
        return NULL;
    /* Represent the initial allocated buffer for maintaining the pointers for each row and the remaining
        allocated memory can be used for storing the data members */     
    tempBufPtr = (int * )(rowBasePtr + rows);

    for (k = 0; k < rows; ++k) {
        rowBasePtr[k] = tempBufPtr + (k * cols);
    }
    
    return rowBasePtr;
}

/* This function frees the memory as regual free. This is just for program completion */
int free2d(int** pt)
{
    free(pt);
    return 0;
}


#ifdef ALLOC2D_DEBUG
int main(int argc, char* argv[])
{
    int i, j;
    int **p = malloc2d(3,5);

    for( i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){
            p[i][j] = i + j;
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
    free2d(p);
    
    return 0;
}
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*define the below for debug the logic */
#undef SPIRAL_MATRIX_DEBUG

/* This function generates a spiral matrix of MxN square matrix */
int ** generateSprialMatrix(int numberOfRows, int numberOfCols) {
    int** spiralMatrix;
 //   int numberOfCols = numberOfRows;
    int rowStartIndex = 0, colStartIndex = 0, rowEndIndex, colEndIndex;
    int i = 0;
    int cnt=1;
    
    if (numberOfRows == 0 )
        return NULL;
    /* Allocate memory for holding the pointers */
    spiralMatrix = malloc(sizeof(int*) * numberOfRows);
        
    for (rowStartIndex = 0; (rowStartIndex < numberOfRows); rowStartIndex++)
        spiralMatrix[rowStartIndex] = (int *) calloc(numberOfCols, sizeof(int));
    
    for (rowStartIndex=0, colStartIndex=0; rowStartIndex<(numberOfRows + 1)/2 && colStartIndex<(numberOfCols + 1)/2; rowStartIndex++, colStartIndex++){
        //top row of the matrix
        for(int i=colStartIndex; i<(numberOfCols-colStartIndex); i++){
            spiralMatrix[rowStartIndex][i] = cnt++;
        }
        //right column of the matrix
        for(int i=rowStartIndex + 1; i<(numberOfRows-rowStartIndex); i++){
            spiralMatrix[i][numberOfCols-colStartIndex-1] = cnt++;
        }
        //bottom row of the matrix
        for(int i=numberOfCols-colStartIndex-2; numberOfRows-rowStartIndex-1>rowStartIndex && i>=colStartIndex; i--){
            spiralMatrix[numberOfRows-rowStartIndex-1][i] = cnt++;
        }
        //left column of the matrix
        for(int i=numberOfRows-rowStartIndex-2; numberOfCols-colStartIndex-1>colStartIndex && i>rowStartIndex; i--){
            spiralMatrix[i][colStartIndex] = cnt++;
        }
        
    }
    return spiralMatrix;
}


#ifdef SPIRAL_MATRIX_DEBUG
void printSpiralMatrix(int **spiralMatrix, int numberOfRows, int numberOfCols){
    int rowIndex = 0, colIndex = 0;
    for(rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {
        for(colIndex = 0; colIndex < numberOfCols; colIndex++)
            printf("%d   ", spiralMatrix[rowIndex][colIndex]);
        
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    int numberOfCols=3, numberOfRows=3;
    int rowStartIndex =0;
    int **spiraMatrixArray;
    
    if (argc>1){
        numberOfRows = numberOfCols = atoi(argv[1]);
    }
    if (argc>2){
        numberOfCols = atoi(argv[2]);
    }
    spiraMatrixArray = generateSprialMatrix(numberOfRows,numberOfCols);
    printSpiralMatrix(spiraMatrixArray,numberOfRows,numberOfCols);
    
    for (rowStartIndex = 0; (rowStartIndex < numberOfRows); rowStartIndex++)
        free(spiraMatrixArray[rowStartIndex]);
    
    free(spiraMatrixArray);
    
    return 0;
}
#endif
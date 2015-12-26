#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#undef  KMP_DEBUG

/* Function to create a longest prefix suffix array, which can be used in KMP search algorithm */
/* This function takes another parameter, LPS array, which was created to hold the computed values */
/* create lps[] that will hold the longest prefix suffix */

void computeLPSArray(char *patternArray, int patternLen, int *lpsArray)
{
    int runner, count;
    
    /* We will initialze the first element of the lps array and lpsIndex to zero */
    int lpsIndex = 0;  // length of the previous longest prefix suffix
    lpsArray[0] = 0; // lpsArray[0] is always 0
    
    runner = 1;
 
    // the loop calculates lpsArray[i] for i = 1 to patternLen-1
    while (runner < patternLen)
    {
       if (patternArray[runner] == patternArray[lpsIndex])
       {
         lpsArray[runner] = lpsIndex + 1;
         lpsIndex++;
         runner++;
       }
       else // (patternArray[runner] != patternArray[lpsIndex])
       {
         if (lpsIndex != 0)
         {
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
           lpsIndex = lpsArray[lpsIndex-1];
 
           // Also, note that we do not increment i here
         }
         else // if (lpsIndex == 0)
         {
           lpsArray[runner] = 0;
           runner++;
         }
       }
#ifdef KMP_DEBUG       
       printf("lpsIndex = %d runner = %d\n", lpsIndex, runner);
       for (count = 0; count < runner; count++)
        printf("%d  ", lpsArray[count]);
       printf("\n\n\n\n");
#endif
    }
}

int kmp_matcher(char *inputTextArray, int textLen, char *patternArray, int patternLen, int *lpsArray)
{
    int i = 0, j = 0;  // index for inputTextArray[] and patternArray[]
 
	while(i < textLen){
		if(inputTextArray[i] == patternArray[j])
        {           
			if(j == (patternLen - 1))
				return (i - j); // means, in (i-j)th position, there is a match occur
			else{
				i++;
				j++;
			}
		}
        else if( j > 0 ){
			j = lpsArray[j-1];
		}else{
			i++;
		}
	}
	return -1; // No match found
}

#ifdef KMP_DEBUG
int main() {
    int count = 0;
    
    char inputStringArray[] = "ABABDABACDABABDABACDABABCABAB";
    char patArray[] = "ABABCABAB";
    int pattLen = strlen(patArray);
    int textLen = strlen(inputStringArray);
    
    int matchPosition = 0;  // index for inputStringArray[]
    
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lpsArray = (int *)calloc(pattLen, sizeof(int));
    
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(patArray, pattLen, lpsArray);
    
    for (count = 0; count < pattLen; count++)
        printf("%d  ", lpsArray[count]);
    
    matchPosition = kmp_matcher(inputStringArray, textLen, patArray, pattLen, lpsArray);
    if (matchPosition != -1)
        printf("\nMatch found in the original input string at = %d\n", matchPosition);
    else
        printf("\nPattern Not Found The Original Input String\n");
    
    free(lpsArray); // to avoid memory leak
}
#endif
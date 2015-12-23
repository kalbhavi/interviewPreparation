/********************************************************************************** 
* 
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* 
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n) 
*   to hold additional elements from B. The number of elements initialized in A and B 
*   are m and n respectively.
*               
**********************************************************************************/

void mergeTwoSortedArrays(int A[], int numElemtsA, int B[], int numElemtsB) {
    int idx_a = numElemtsA - 1 ;
    int idx_b = numElemtsB - 1 ;
    int idx_common = numElemtsA + numElemtsB - 1;
    
    /* Move the elements from end of the big array by comparing values of 
       each array from the end (i.e from highest values to lower values) */ 
    while ((idx_a >= 0) && (idx_b >= 0))
    {
        if (A[idx_a] > B[idx_b]){
            A[idx_common--] = A[idx_a--];
        }else{
            A[idx_common--] = B[idx_b--];
        }    
    }
    /* Move the rest of the elements to big array if there are elements left in
       the second array (where number of elements are more in the second array and 
       number of elements are less in the big array) */
    while (idx_b >= 0){
        A[idx_common--] = B[ib--];
    }
}

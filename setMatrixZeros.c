/********************************************************************************** 
* 
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* 
* Follow up:
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
           
**********************************************************************************/
#define BOOL unsigned char
#define TRUE 1
#define FALSE 0

/* space: O(1) time: O(m*n)
 * use first column to set row flag
 * and first row to set column flag */
void setZeroes(int **matrix, int m, int n) {
    
    BOOL first_col_has_zero = FALSE;
    BOOL first_row_has_zero = FALSE;
    int i, j;
    
    /* scan first column to need to set all the elements of the column at the final step */
    for (i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            first_col_has_zero = TRUE;
            break;
        }
    }
    /* scan first row to need to set all the elements of the row at the final step */
    for (j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            first_row_has_zero = TRUE;
            break;
        }
    }
    /* scan the rest of the matrix, leaving the first row and first column */
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    /* set zeros except first column and first row */
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    /* set first column and first row to zero  if we found zeros in the initial scan*/
    if (first_col_has_zero) {
        for (i = 0; i < m; i++) 
            matrix[i][0] = 0;
    }
    if (first_row_has_zero) {
        for (j = 0; j < n; j++) 
            matrix[0][j] = 0;
    }
}
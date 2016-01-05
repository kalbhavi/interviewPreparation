#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef WATER_LEVEL_AT_JTH_GLASS_DEBUG

// Returns the amount of water in jth glass of ith row
float findWaterLevel(int ithRow, int jthGlass, float Xliter)
{
    // A row number i has maximum i columns. So input column number must
    // be less than i
    if (jthGlass > ithRow)
    {
        printf("Incorrect Input\n");
        exit(0);
    }
 
    // There will be i*(i+1)/2 glasses till ith row (including ith row)
    float glass[ithRow * (ithRow + 1) / 2];
    
#ifdef WATER_LEVEL_AT_JTH_GLASS_DEBUG    
    printf("Number of glasses need = %f\n",(float)(ithRow * (ithRow + 1)) / 2);
#endif 
    // Initialize all glasses as empty
    memset(glass, 0, sizeof(glass));
 
    // Put all water in first glass
    int index = 0;
    glass[index] = Xliter;
 
    // Now let the water flow to the downward glassses till the
    // amount of water X is not 0 and row number is less than or
    // equal to i (given row)
    for (int rowIndex = 1; rowIndex <= ithRow && Xliter !=0.0; ++rowIndex)
    {
        // Fill glasses in a given row. Number of columns in a row
        // is equal to row number
        for (int colIndex = 1; colIndex <= ithRow; ++colIndex, ++index)
        {
            // Get the water from current glass
            Xliter = glass[index];
 
            // Keep the amount less than or equal to
            // capacity in current glass
            glass[index] = (Xliter >= 1.0f) ? 1.0f : Xliter;
 
            // Get the remaining amount
            Xliter = (Xliter >= 1.0f) ? (Xliter - 1) : 0.0f;
 
            // Distribute the remaining amount to the down two glasses
            glass[index + ithRow] += Xliter / 2;
            glass[index + ithRow + 1] += Xliter / 2;
        }
    }
 
    // The index of jth glass in ith row will be i*(i-1)/2 + j - 1 (Array Index)
    return glass[ithRow * (ithRow - 1) /2 + jthGlass - 1];
}

#ifdef WATER_LEVEL_AT_JTH_GLASS_DEBUG
// Driver program to test above function
int main()
{
    int i = 2, j = 2;
    float X = 6.0; // Total amount of water
 
    printf("Amount of water in jth glass of ith row is: %f\n",
            findWaterLevel(i, j, X));
 
    return 0;
}
#endif
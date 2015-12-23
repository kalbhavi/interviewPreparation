/*Function to reverse any sequence starting with pointer
  begin and ending with pointer end  */
void reverseString(char *start, char *end)
{
  char temp;
  while (start < end)
  {
    temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

/*Function to reverse words - Time Complexity: O(n)*/
void reverseWordsInString( char *inputStr )
{
    char *word_begin = NULL;
    char *temp = inputStr; /* temp is for word boundry */
    
    if (inputStr == NULL)
        return;

    /*Identify each word by space as delimiter and reverse the characters in the word */
    while( *temp )
    {
        /*This condition is to make sure that the string start with
        valid character (not space) only*/
        if (( word_begin == NULL ) && (*temp != ' ') )
        {
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            reverseString(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    } /* End of while */

    /*Reverse one more time the entire reversed word string */
    reverseString(inputStr, temp-1);
}

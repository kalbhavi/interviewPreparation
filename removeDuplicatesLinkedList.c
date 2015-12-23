/*
 Write code to remove duplicates from an unsorted linked list. 
 */

/* METHOD 1 :Time Complexity: O(n^2)*/

/* Function to remove duplicates from a unsorted linked list */
void removeDuplicates(struct node *start)
{
  struct node *ptr1, *ptr2, *dup;
  ptr1 = start;
 
  /* Pick elements one by one */
  while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;
 
     /* Compare the picked element with rest of the elements */
     while(ptr2->next != NULL)
     {
       /* If duplicate then delete it */
       if(ptr1->data == ptr2->next->data)
       {
          /* sequence of steps is important here */
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          free(dup);
       }
       else /* This is tricky */
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}


/*
METHOD 2 (Use Sorting)
In general, Merge Sort is the best suited sorting algorithm for sorting linked lists efficiently.
1)	Sort the elements using Merge Sort. We will soon be writing a post about sorting a linked list. O(nLogn)
2)	Remove duplicates in linear time using the algorithm for removing duplicates in sorted Linked List. O(n)

Please note that this method doesn’t preserve the original order of elements.

Time Complexity: O(nLogn)



METHOD 3 (Use Hashing)
We traverse the link list from head to end. For every newly encountered element, we check whether it is in the hash table: if yes, we remove it; otherwise we put it in the hash table.

Thanks to bearwang for suggesting this method.

Time Complexity: O(n) on average (assuming that hash table access time is O(1) on average).
*/


/*
 Write code to remove duplicates from a sorted linked list. 
 */
 // Remove duplicates from a sorted list
void RemoveDuplicates(struct node* head) {
    //(figured these with a few drawings)
    ￼struct node* current = head;
    if (current == NULL) return;     // do nothing if the list is empty
    // Compare current node with next node
    while(current->next!=NULL) {
        if (current->data == current->next->data) {
            struct node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;// only advance if no deletion
        }
    }
}

/* Below function will removes the duplicate characters from a sorted array of characters */
/* Function to remove duplicates in a sorted array */
char *removeDupsSorted(char *str)
{
    int resultIndex = 1, inputIndex = 1;
 
    /* In place removal of duplicate characters*/
    while (*(str + inputIndex))
    {
        if (*(str + inputIndex) != *(str + inputIndex - 1))
        {
            *(str + resultIndex) = *(str + inputIndex);
            resultIndex++;
        }
        inputIndex++;
    }
 
    /* After above step string is stringiittg.
       Removing extra iittg after string*/
    *(str + resultIndex) = '\0';
 
    return str;
}

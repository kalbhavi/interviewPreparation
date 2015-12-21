#include <stdio.h>

// Find the beginning of the loop in a circular linked list
// The code doesn't work when the linked list is not a circular linked list
LinkedListNode* findLoopBeginning(LinkedListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	LinkedListNode* fastPtr = head;
	LinkedListNode* slowPtr = head;
	while (fastPtr != NULL && fastPtr->next != NULL)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;

		// Let fastPtr has twice length of slowPtr
		if (fastPtr == slowPtr)
			break;
	}
    
    /* There is no meeting point and therefore no loop */
    if (fastPtr == NULL || fastPtr->next == NULL)
        return NULL;
    
    /*  Move the slowPtr to head. Keep the fastPtr at the meeting point.
        Each are k steps from the start of the loop. If they move at the same pace,
        they must meet at the loop start */
	slowPtr = head;
	while (fastPtr != slowPtr)
	{
		fastPtr = fastPtr->next;
		slowPtr = slowPtr->next;
	}
    
    /* At this point both fastPtr and slowPtr are point to the start of the loop */
	return fastPtr;
}
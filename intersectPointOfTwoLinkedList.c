
/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
int _getIntesectionNode(int d, struct LinkedList* head1, struct LinkedList* head2);

/* Function to get the counts of node in a linked list */
/* Takes head pointer of the linked list and
   returns the count of nodes in the list */
int getCount(struct LinkedList* head)
{
  struct LinkedList* current = head;
  int count = 0;
 
  while (current != NULL)
  {
    count++;
    current = current->next;
  } 
  return count;
}
 
/* function to get the intersection point of two linked
   lists head1 and head2 */
int getIntesectionNode(struct LinkedList* head1, struct LinkedList* head2)
{
  int count1 = getCount(head1);
  int count2 = getCount(head2);
  int extraNodes;
 
  if(count1 > count2)
  {
    extraNodes = count1 - count2;
    return _getIntesectionNode(extraNodes, head1, head2);
  }
  else
  {
    extraNodes = count2 - count1;
    return _getIntesectionNode(extraNodes, head2, head1);
  }
}
 
/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has extraNodes more nodes than
   head2 */
int _getIntesectionNode(int extraNodes, struct LinkedList* head1, struct LinkedList* head2)
{
  int i;
  struct LinkedList* current1 = head1;
  struct LinkedList* current2 = head2;
 
  for(i = 0; i < extraNodes; i++)
  {
    if(current1 == NULL)
    {  
        return -1; 
    }
    current1 = current1->next;
  }
 
  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
      return current1->data;

    current1= current1->next;
    current2= current2->next;
  }
 
  return -1;
}
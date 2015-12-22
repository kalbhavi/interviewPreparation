
// Return the number of nodes in a list (while-loop version)
int Length(struct node* head) {
   int count = 0;
   struct node* current = head;
   while (current != NULL) {
      count++;
      current = current->next;
   }
   return(count);
}

void MoveNode(struct node** destRef, struct node** sourceRef) {
   struct node* newNode = *sourceRef;     // the front source node
   assert(newNode != NULL);
   *sourceRef = newNode->next;      // Advance the source pointer
   newNode->next = *destRef;  // Link the old dest off the new node
   *destRef = newNode;        // Move dest to point to the new node
}

// Uses the "count the nodes" strategy
void FrontBackSplit(struct node* source,
                  struct node** frontRef, struct node** backRef) {
   int len = Length(source);
   int i;
   struct node* current = source;
   if (len < 2) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        int hopCount = (len-1)/2;   //(figured these with a few drawings)
        for (i = 0; i<hopCount; i++) {
            current = current->next;
        }
        // Now cut at current
        *frontRef = source;
        *backRef = current->next;
        current->next = NULL;
    } 
}

// Uses the fast/slow pointer strategy
void FrontBackSplit2(struct node* source,struct node** frontRef, struct node** backRef) {
    struct node* fast;
    struct node* slow;
    
    if (source==NULL || source->next==NULL) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        slow = source;
        fast = source->next;
        // length < 2 cases
        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        // 'slow' is before the midpoint in the list, so split it in two
        // at that point.
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}


struct node* SortedMerge(struct node* a, struct node* b) {
    struct node dummy;   // a dummy first node to hang the result on
    struct node* tail = &dummy;      // Points to the last result node --
                                    // so tail->next is the place to add
                                    // new nodes to the result.
    dummy.next = NULL;
    while (1) {
        if (a == NULL) {  // if either list runs out, use the other list
            tail->next = b;
            break; 
        }
        else if (b == NULL) {
            tail->next = a;
            break;
        }
        if (a->data <= b->data) {
            MoveNode(&(tail->next), &a);
        } else {
            MoveNode(&(tail->next), &b);
        }
        tail = tail->next;
    }
    return(dummy.next);
}


struct node* SortedMerge2(struct node* a, struct node* b) {
    struct node* result = NULL;
    struct node** lastPtrRef = &result; // point to the last result pointer
    while (1) {
        if (a==NULL) {
            *lastPtrRef = b;
            break; 
        }
        else if (b==NULL) {
            *lastPtrRef = a;
            break;
        }
        if (a->data <= b->data) {
            MoveNode(lastPtrRef, &a);
        } else {
            MoveNode(lastPtrRef, &b);
        }
        
        lastPtrRef = &((*lastPtrRef)->next); // tricky: advance to point to
                                        // the next ".next" field
    }
    return(result);
}

struct node* SortedMerge3(struct node* a, struct node* b) {
    struct node* result = NULL;
    // Base cases
    if (a==NULL) return(b);
    else if (b==NULL) return(a);
    
    // Pick either a or b, and recur
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge3(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge3(a, b->next);
    }
    return(result);
}


void MergeSort(struct node** headRef) {
   struct node* head = *headRef;
   struct node* a;
   struct node* b;
   
   // Base case -- length 0 or 1
   if ((head == NULL) || (head->next == NULL)) {
    return;
   }
   
   FrontBackSplit(head, &a, &b);    // Split head into 'a' and 'b' sublists
                                    // We could just as well use AlternatingSplit()
   MergeSort(&a); // Recursively sort the sublists
   MergeSort(&b);
   
   *headRef  = SortedMerge(a, b);   // answer = merge the two sorted lists together
}
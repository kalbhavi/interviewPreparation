#include <stdio.h>
#include <stdlib.h>

#undef ALIGNED_MALLOC_DEBUG

/* 
    This function will allocate a memory required with the alignment. The alignment argument
    may be a byte aligned, short aligned, int aligned or long aligned etc. 1, 2, 4, 8, 16 byte aligned 
    We are allocating additional memory for storing aligned allocated memory. And also we are additionally
    allocating memory for additional padding on the alignment
*/
unsigned char alignedMalloc(void **memptr, size_t alignmentType, size_t allocationSize)
{
    /* We are allocating extra memory to hold the allocated memory pointer (which is not same as malloc pointer)
    and additional bytes required for the alignment */
    size_t totalMemLen = allocationSize + alignmentType + sizeof(void *);
    
    void *ptr = malloc(totalMemLen);
    if(ptr == NULL){
        return 0;
    }
#ifdef ALIGNED_MALLOC_DEBUG    
    printf("Allocated Memory Pointer Address From Malloc : 0x%lx\n",(unsigned long)ptr);
    printf("Alignment Type :%lu\n",(unsigned long)alignmentType);
    printf("Size of (void *) :%lu\n", sizeof(void *));
#endif     
    *memptr = (unsigned long *)  ( ( ((unsigned long)ptr) + alignmentType + sizeof(void *)) & ~(alignmentType - 1) );

#ifdef ALIGNED_MALLOC_DEBUG    
    printf("Allocated Memory Pointer After Alignment : 0x%lx\n",(unsigned long)*memptr);
    printf("(((unsigned int *)*memptr) -1 ): 0x%lx\n",(((unsigned long *)*memptr) - 1));
#endif    
    *( (unsigned long *) (((unsigned long *)*memptr) - 1) ) = (unsigned long)ptr;
    
    return 1;
}

int alignedFree(void *memptr)
{
    if(memptr == NULL){
        return 0;
    }
    else{
#ifdef ALIGNED_MALLOC_DEBUG        
        printf("Freeing memory address : 0x%lx\n",(void *)(*((unsigned long *)memptr - 1)));
#endif        
        free((void *)(*((unsigned long *)memptr - 1)));
        return 1;
    }
}

#ifdef ALIGNED_MALLOC_DEBUG
int main(int argc, char* argv[])
{
    for(int i = 1; i < 257; i *= 2){
        void *memptr = NULL;
        alignedMalloc(&memptr, i, 100);
        printf("aligned :%d -- 0x%lx -- next location 0x%lx\n",i, (unsigned long)memptr, (unsigned long)(memptr+i));
        alignedFree(memptr);
    }
 return 0;
}
#endif
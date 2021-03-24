#include <stdio.h> 
#include <stdlib.h>
int main() 
{ 
    int* data = (int *) malloc(100 * sizeof(int));
    data[100] = 0;
    free(data);
    printf("data: %d\n", (*data)); 
    return 0;
}
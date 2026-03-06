#include <stdio.h>
#include <stdlib.h>


int main (){
  int *array;
  int n;
  
  printf("¿Cuantos elementos tiene el conjunto?\n");
  scanf("%d", &n);
  array = (int *)calloc(n, sizeof(int));
  
  if (array!=NULL) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
      printf("%d ", (array + i));
    }
    printf("]\n");
    free(array);
  }
  return 0;
}

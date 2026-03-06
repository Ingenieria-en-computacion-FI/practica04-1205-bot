#include <stdio.h>
#include <stdlib.h>


int main (){
  int *array;
  int *array2;
  int n;
  printf("¿Cuantos elementos tiene el conjunto?\n");
  scanf("%d", &n);
  array = (int *)malloc(n * sizeof(int));
  
  if (array != NULL) {
    for(int i = 0; i < n; i++) {
      printf("Ingrese el elemento: ");
      scanf("%d", (array + i));
    }
    printf("[ ");
    for (int i = 0; i < n; i++) {
      printf("%d ", *(array + i));
    }
    printf("]\n");

    array2 = (int *)realloc(array, (2*n) * sizeof(int));
     if (array2 != NULL) {
        for(int i = n; i < (2*n); i++) {
          printf("Ingrese el elemento: ");
          scanf("%d", (array2 + i));
        }
        printf("[ ");
        for(int i = 0; i < (2*n); i++) {
          printf("%d ", *(array2 + i));
        }
        printf("]\n");
      }
    
    free(array2);
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int printArr(int *arr, int n)
{
     for(int i = 0; i < n; i ++)
     {
          if(i % 80 == 0)
               printf("\n");
          printf("%d ", arr[i]);
     }

}

void swap(int * arr, int j, int k)
{
     int tmp = arr[j];

     arr[j] = arr[k];
     arr[k] = tmp;
}

void bubble(int *arr, int n)
{
     int i, x, inOrder;

     for(i = 0; i < n; i ++)
     {
          inOrder = 1;
          for(x = 0; x < n; x ++)
          {
               if(arr[x] > arr[x+1])
               {
                    swap(arr, x, x+1);
                    inOrder = 0;
               }

          }
     }
}

void selection(int *arr, int n)
{
     // selection sort algorithm

     if(arr == NULL || n <= 0)
          return;

     int min = 100000000, minIndex;
     for(int i = 0; i < n; i ++)
          if(arr[i] < min)
          {
              minIndex = i;
              min = arr[i];
          }


    // printf("\nmin = %d\n", min);
     swap(arr, 0, minIndex);
    // printArr(arr, n);

    // recursive call
     selection(arr + 1, n - 1);
}
int main(void)
{
     srand(time(NULL));

     int size = 15;
     int * arr = malloc(sizeof(int) * size);
     int i;

     for(i = 0; i < 15; i++)
     {
          arr[i] = rand() % 100;
     }
     printArr(arr, size);
     selection(arr, size);
     printArr(arr, size);
     printf("\n");
     return 0;
}

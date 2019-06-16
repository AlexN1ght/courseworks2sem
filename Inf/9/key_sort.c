#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void siftDown(float *numbers, size_t *values, int root, int bottom)
{
  int maxChild;
  int done = 0;
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (numbers[root] < numbers[maxChild]) 
    {
      float temp = numbers[root];
      size_t tempV = values[root];
      numbers[root] = numbers[maxChild];
      values[root] = values[maxChild];
      numbers[maxChild] = temp;
      values[maxChild] = tempV;
      root = maxChild;
    }
    else
      done = 1; 
  }
}
void heapSort(float *numbers, size_t *values, int array_size) 
{
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, values, i, array_size - 1);
  for (int i = array_size - 1; i >= 1; i--)
  {
    float temp = numbers[0];
    size_t tempV = values[0];
    numbers[0] = numbers[i];
    values[0] = values[i];
    numbers[i] = temp;
    values[i] = tempV;
    siftDown(numbers, values, 0, i - 1);
  }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    float keys[N];
    size_t vals[N];

    
    for(int i = 0; i < N; i++) {
        puts("Ue");
        vals[i] = (size_t)malloc(sizeof(char) * 100);
        scanf("%f %s",&(keys[i]), (char*)vals[i]);
        puts("rr");
    }
    puts("Unsorted:");
    for(int i = 0; i < N; i++) {
        printf("%f %s\n",keys[i], (char*)vals[i]);
    }
    heapSort(keys, vals, N);
    puts("");
    puts("Sorted:");
    for(int i = 0; i < N; i++) {
        printf("%f %s\n",keys[i], (char*)vals[i]);
    }
    
    float key;
    while(scanf("%f", &key)) {
        puts("Enter:");
        int a = 0;
        int b = N - 1;
        while(abs(a - b) > 1) {
            if (key > keys[(a + b) / 2]) {
                a = (a + b) / 2;
            } else if (key < keys[(a + b) / 2]) {
                b = (a + b) / 2;
            } else {
                a = (a + b) / 2;
                b = a;
            }
        }
        if (a != b) {
            if (fabsf(key - keys[a]) < fabsf(key - keys[b])) {
                b = a;
            } else {
                a = b;
            }
        }
        printf("%f %s\n",keys[a], (char*)vals[a]);

    }
    
    return 0;
}

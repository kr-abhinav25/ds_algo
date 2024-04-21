#include <stdio.h>

void quick_sort(int a[], int low, int high){
  int *p = a;
  if (low < high) {
    int i = low + 1;
    int j = high;
    int pivot_val = a[low];

    while (i < j) {
      while (a[i] < pivot_val)
      {
        i++;
      }
    while (a[j] > pivot_val)
      {
        j--;
      }
      if (i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }

    int tmp1 = a[j];
    a[j] = a[low];
    a[low] = tmp1;

    quick_sort(a,low, j - 1);
    quick_sort(a, (j + 1), high);
}

}
 int main() {
  int a[] = {10, 1, 50, 24, 4, 11, 1, 18, 2, 37};
  int length = 10;
  quick_sort(a,0,9);
  for (int i = 0; i < length; i++)
  {
    printf("%d\n", a[i]);
  }
  
  return 0;

 }
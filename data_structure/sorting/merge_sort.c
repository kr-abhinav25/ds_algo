#include <stdio.h>

void merge(int a[],int low, int mid, int high ) {

}

void merge_sort(int a[],int low, int high){
  if (low < high) {
    int mid = low + (high -1)/2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}
 int main() {
  int a[] = {10, 1, 50, 24, 4, 11, 1, 18, 2, 37};
  int length = 10;
  merge_sort(a, 0, 9);
  for (int i = 0; i < length; i++)
  {
    printf("%d\n", a[i]);
  }
  
  return 0;

 }
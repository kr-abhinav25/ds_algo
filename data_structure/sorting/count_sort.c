#include <stdio.h>
#include <string.h>
void count_sort(int input[], int sorted[], int length){

  // get range of elements from 0...k in input array
  int k = 0;
  for (int i = 0; i < length; i++)
  {
    if(input[i] > k) {
      k = input[i];
    }
  }

  // initalise array to store frequency of each element at their corresponding index
  int temp_arr_length = k+1;
  int temp[temp_arr_length];
  memset(temp, 0, temp_arr_length * sizeof(int));

  for (int i = 0; i < length; i++)
  {
    temp[input[i]] = temp[input[i]] + 1;
  }

  // set the starting index for each element relative to its previous elements length
  for (int i = 1; i < temp_arr_length; i++)
  {
   temp[i] = temp[i] + temp[i-1];
  }

  // iterate through the array starting at end:
  // get each element from input array ad its index in temp array.
  // Reduce the index position by one and place it at the resulting
  // position in result array. We start from end of array to maintain
  // stability of the sort. We can start from beginning as well
  // but will lose the relative position of each element in input array.
  // This is coz for each element encountered, it will first be entered
  // at the end in sorted array as temp holds the last position where
  // the element should be added.
  for (int i = length -1; i >= 0; i--)
  {
    temp[input[i]] = temp[input[i]] - 1;
    sorted[temp[input[i]]] = input[i];
  }
}
 int main() {
  int input[] = {2, 1, 1, 0, 2, 5, 41, 2, 8, 7, 7, 9,2,0,1,9};
  // int input[] = {2, 1, 1, 0, 2, 5, 4, 0,2, 8, 7, 7, 9,2,0,1,9};

  int length = 16;
  int sorted[length];
  memset(sorted, 0, length * sizeof(int));

  count_sort(input, sorted, length);
  for (int i = 0; i < length; i++)

  {
    printf("%d\n", sorted[i]);
  }

  return 0;
 }
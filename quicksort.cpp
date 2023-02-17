#include <iostream>

void printArray(int left, int right, int arr[]) {
  for ( size_t i = left; i <= right; i++ ) {
    std::cout << arr[i] << "\t";
  }

  std::cout << std::endl;
}


void swap(int &first, int &second) {
  int tmp = first;
  first = second;
  second = tmp;
}

int findGreaterThanOrEqualToPivot(int arr[], int left, int pivot) {
  while ( arr[left] < arr[pivot] ) {
    left++;
  }

  return left;
}

int findLessThanPivot(int arr[], int right, int pivot, int min) {
  while ( arr[right] >= arr[pivot] && right >= min ) {
    right--;
  }

  return right;
}

bool boundsHaveCrossed(int left, int right) {
  return left > right;
}

int partition(int arr[], int left, int right, int pivot) {
  std:: cout << "partition: " << left << ", " << right << " with pivot @ " << pivot << " = " << arr[pivot] << std::endl;
  printArray(left, right, arr);

  while ( left < right ) {
    left = findGreaterThanOrEqualToPivot(arr, left, pivot);
    right = findLessThanPivot(arr, right, pivot, left);
    if ( left < right ) {
      std::cout << "order swap: " << left << ", " << right << std::endl;
      swap(arr[left], arr[right]);
      printArray(left, right, arr);
    }

  }

  return left;
}

void sort(int arr[], int left, int right) {
  std::cout << "sort: " << left << ", " << right << std::endl;
  printArray(left, right, arr);
  int mid = left + ((right - left) >> 1);

  std::cout << "choose pivot and swap it to end: " << mid << ", " << right << std::endl;
  swap(arr[mid], arr[right]);
  printArray(left, right, arr);

  int pivot = partition(arr, left, right, right);
  std::cout << "swap pivot to place: " << pivot << ", " << right << std::endl;
  swap(arr[pivot], arr[right]);
  printArray(left, right, arr);

  if ( pivot - left > 1 ) {
    std::cout << "sort left subarray" << std::endl;
    sort(arr, left, pivot - 1);
    printArray(left, right, arr);
  }

  if ( right - pivot > 1 ) {
    std::cout << "sort right subarray" << std::endl;
    sort(arr, pivot + 1, right);
  }

  printArray(left, right, arr);
}

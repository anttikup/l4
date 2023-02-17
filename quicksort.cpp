#include <iostream>

void printArray(int len, int arr[]) {
  for ( size_t i = 0; i < len; i++ ) {
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
  printArray(8, arr);

  while ( left < right ) {
    left = findGreaterThanOrEqualToPivot(arr, left, pivot);
    right = findLessThanPivot(arr, right, pivot, left);
    if ( left < right ) {
      std::cout << "order swap: " << left << ", " << right << std::endl;
      swap(arr[left], arr[right]);
      printArray(8, arr);
    }

  }

  return left;
}

void sort(int arr[], int left, int right) {
  std::cout << "sort: " << left << ", " << right << std::endl;
  printArray(8, arr);
  int mid = left + ((right - left) >> 1);

  std::cout << "choose pivot and swap it to end: " << mid << ", " << right << std::endl;
  swap(arr[mid], arr[right]);
  printArray(8, arr);

  int pivot = partition(arr, left, right, right);
  std::cout << "swap pivot to place: " << pivot << ", " << right << std::endl;
  swap(arr[pivot], arr[right]);
  printArray(8, arr);

  if ( pivot - left > 1 ) {
    std::cout << "sort left subarray" << std::endl;
    sort(arr, left, pivot - 1);
    printArray(8, arr);
  }

  if ( right - pivot > 1 ) {
    std::cout << "sort right subarray" << std::endl;
    sort(arr, pivot + 1, right);
  }

  printArray(8, arr);
}




bool isSorted(int len, int arr[]) {

  for ( int i = 1; i < len; i++ ) {
    if ( arr[i] < arr[i - 1] ) {
      return false;
    }
  }

  return true;
}


int main(int argc, char *argv[]) {


  int arr[] = { 98, 3, 32, 9, 2, 22, 8, 4 };
  int len = 8;

  printArray(len, arr);

  sort(arr, 0, 7);

  printArray(len, arr);

  std::cout << (isSorted(len, arr) ? "sorted" : "not sorted") << std::endl;

  return 0;
}

#include <cassert>
#include <cstdlib>

#include "quicksort.cpp"


bool isSorted(int len, int arr[]) {

  for ( int i = 1; i < len; i++ ) {
    if ( arr[i] < arr[i - 1] ) {
      return false;
    }
  }

  return true;
}

int randomInt(int min, int max) {
  int diff = max - min;
  return rand() % diff + min;
}

void test(int len, int arr[]) {
  sort(arr, 0, len-1);
  bool sorted = isSorted(len, arr);
  std::cout << (sorted ? "sorted" : "not sorted") << std::endl;

  assert(sorted);
}

int main(int argc, char *argv[]) {

  for ( int n = 0; n < 100; n++ ) {
    int len = randomInt(1, 11);
    std::cout << len << std::endl;
    int arr[len];
    for ( int i = 0; i < len; i++ ) {
      arr[i] = randomInt(-99, 99);
    }

    test(len, arr);
  }

  return 0;
}

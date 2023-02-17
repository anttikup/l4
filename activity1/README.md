# Activities

## Task 1

- Refer to the following link. Discuss how Merge-sort works:
  https://opendsa-server.cs.vt.edu/OpenDSA/AV/Sorting/mergesortAV.html
- Merge-sort Practice. Refer to the following link. Merge the two sub-arrays into the larger array.
  https://opendsa-server.cs.vt.edu/OpenDSA/Exercises/Sorting/MergesortMergePRO.html

## Task 2

- Refer to the following link. Discuss how Quick-sort works:
  https://opendsa-server.cs.vt.edu/OpenDSA/AV/Sorting/quicksortAV.html
- Quick-sort Practice. Refer to the following link. Partition the array using quicksort.
  https://opendsa-server.cs.vt.edu/OpenDSA/Exercises/Sorting/QuicksortPartitPRO.html

## Task 3

- The following snippet is from `./src/quicksort.cpp` lines 32-43. Discuss in groups how the code works:

```cpp
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //partition the array
        int pivot = partition(arr, low, high);

        //sort the sub arrays independently
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
```

- The following snippet is from `./src/quicksort.cpp` line 27. Discuss in groups how ìt works:

```cpp
swap(&arr[i + 1], &arr[high]);
```

## Task 4: Individual (at home)

1. Merge-sort has better worst case performance than quicksort. So why Quick-sort is considered better than Merge-sort? Refer to the following article

Quicksort sorts the array in-place. No extra space is needed. The elements are loaded in cache at the same time, so they can be retrieved faster. Bad worst case performance of quicksort can be improved on average by randomizing the selection of pivot.

   https://www.geeksforgeeks.org/quicksort-better-mergesort/
2. Refer to the following article. Analyze the complexity of the Merge-sort algorithm.
   https://www.softwaretestinghelp.com/merge-sort/

Merge sort first divides the array in to smaller and smaller subarrays. It's (log n), because the arrays lengths are halved on each step.

Finding middle element is O(1), if using an array.

Merging the arrays is O(n) (or 2n), because only the first elements of the subarrays need to be looked at since the subarrays are sorted.
Total complexity is O(log n · 1 · n) = O(n·log n).


3. Refer to the following article. Analyze the complexity of the Quick-sort algorithm.
   https://www.softwaretestinghelp.com/quick-sort/

Quicksort partitions the array to smaller subarrays which is O(log n).

Choosing the middle as pivot is O(1).

Finding smaller and larger value is in worst case O(n) because all elements are visited before the pointers cross.

In total O(n·log n).

If the first or last element is selected as pivot, then the complexity can be as bad as O(n²).

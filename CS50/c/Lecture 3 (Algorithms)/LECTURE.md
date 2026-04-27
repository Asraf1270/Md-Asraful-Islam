#linear search



---
## Binary Search
Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

### Pseudocode

```
function binarySearch(array, target, low, high)
    if low > high
        return -1  // not found
    mid = (low + high) / 2
    if array[mid] == target
        return mid
    else if array[mid] > target
        return binarySearch(array, target, low, mid - 1)
    else
        return binarySearch(array, target, mid + 1, high)
```

### Characteristics
- Time complexity: O(log n)
- Requires sorted array
- Efficient for large datasets

---

## Logarithmic Search

Logarithmic search refers to search algorithms that have O(log n) time complexity, such as binary search. These algorithms reduce the search space by half with each step.

For example, binary search is a logarithmic search algorithm.



# Sorting Algorithms Notes

Sorting is the process of arranging a collection of values in a specific order, usually ascending or descending. In algorithms, sorting is one of the most important building blocks because many other problems become easier once the data is sorted.

---

## 1. Selection Sort
Selection sort repeatedly chooses the smallest (or largest) element from the unsorted part of the array and moves it to the front.

### How it works
- Start with the first position in the array.
- Find the smallest element in the unsorted portion.
- Swap that smallest element with the current position.
- Move to the next position and repeat until the array is sorted.

### Example
Given: `5 3 8 4 2`
- First pass: find smallest from all elements -> `2`, swap with `5` → `2 3 8 4 5`
- Second pass: find smallest from remaining `3 8 4 5` -> `3`, already in place → `2 3 8 4 5`
- Continue until sorted: `2 3 4 5 8`

### Pseudocode
```
for i from 0 to n - 2
    minIndex = i
    for j from i + 1 to n - 1
        if numbers[j] < numbers[minIndex]
            minIndex = j
    swap numbers[i] and numbers[minIndex]
```

### Characteristics
- Time complexity: O(n^2)
- Space complexity: O(1)
- Stable: no (unless implemented carefully)
- Good when memory is very limited and n is small

---

## 2. Bubble Sort
Bubble sort repeatedly passes through the array and swaps adjacent out-of-order elements, pushing the largest element toward the end on each pass.

### How it works
- Compare adjacent elements.
- If they are in the wrong order, swap them.
- After one full pass, the largest element "bubbles" to the end.
- Repeat passes until no swaps are needed.

### Example
Given: `5 1 4 2 8`
- First pass: compare `5` and `1` → swap → `1 5 4 2 8`
- Continue swapping adjacent out-of-order pairs until end.
- After enough passes, the array becomes `1 2 4 5 8`

### Pseudocode
```
for pass from 0 to n - 2
    swapped = false
    for i from 0 to n - 2 - pass
        if numbers[i] > numbers[i + 1]
            swap numbers[i] and numbers[i + 1]
            swapped = true
    if not swapped
        break
```

### Characteristics
- Time complexity: O(n^2)
- Space complexity: O(1)
- Stable: yes
- Best case: O(n) when the list is already sorted
- Useful for teaching and simple cases, but not efficient for large arrays

---

## 3. Recursion in Sorting
Recursion is a technique where a function calls itself to solve smaller instances of the same problem. Many efficient sorting algorithms, such as merge sort and quick sort, are based on recursion.

### Recursion concept
- A recursive algorithm has:
  - A base case: the condition where the recursion stops.
  - A recursive case: the part where the function calls itself with smaller input.

### Recursive sorting idea
A simple recursive sorting approach can be described as:
- If the list has size 0 or 1, it is already sorted.
- Otherwise, split the list into smaller parts.
- Sort each part recursively.
- Combine the sorted parts.

### Recursion pseudocode
```
function recursiveSort(numbers, start, end)
    if start >= end
        return
    mid = (start + end) / 2
    recursiveSort(numbers, start, mid)
    recursiveSort(numbers, mid + 1, end)
    merge(numbers, start, mid, end)

function merge(numbers, start, mid, end)
    left = numbers[start .. mid]
    right = numbers[mid + 1 .. end]
    i = 0, j = 0, k = start
    while i < length(left) and j < length(right)
        if left[i] <= right[j]
            numbers[k] = left[i]
            i = i + 1
        else
            numbers[k] = right[j]
            j = j + 1
        k = k + 1
    while i < length(left)
        numbers[k] = left[i]
        i = i + 1
        k = k + 1
    while j < length(right)
        numbers[k] = right[j]
        j = j + 1
        k = k + 1
```

### Why recursion helps
- It simplifies complex problems by breaking them down.
- Many fast sorting algorithms use divide-and-conquer.
- Recursive sorting can lead to better time complexity than simple loops.

---

## Summary
- Selection sort selects the smallest element and places it at the start.
- Bubble sort swaps adjacent elements until the array is ordered.
- Recursion enables divide-and-conquer sorting strategies used by advanced algorithms.
- Merge sort efficiently sorts arrays using a divide-and-conquer approach.

These ideas are foundational for understanding both simple and advanced sorting techniques in C and algorithm design.

---

## 4. Merge Sort

Merge sort is a divide-and-conquer sorting algorithm that divides the array into two halves, recursively sorts each half, and then merges the sorted halves back together.

### How it works

- If the array has 0 or 1 elements, it is already sorted.

- Divide the array into two halves.

- Recursively sort each half.

- Merge the two sorted halves into a single sorted array.

### Pseudocode

```
function mergeSort(array)
    if length(array) <= 1
        return array
    mid = length(array) / 2
    left = mergeSort(array[0..mid-1])
    right = mergeSort(array[mid..end])
    return merge(left, right)

function merge(left, right)
    result = []
    while left and right are not empty
        if left[0] <= right[0]
            add left[0] to result
            remove left[0]
        else
            add right[0] to result
            remove right[0]
    add remaining elements from left or right to result
    return result
```

### Characteristics

- Time complexity: O(n log n)

- Space complexity: O(n)

- Stable: yes

- Efficient for large datasets

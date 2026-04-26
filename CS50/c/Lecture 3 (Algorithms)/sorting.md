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

### Simple recursive structure
```
function recursiveSort(numbers, start, end)
    if start >= end
        return
    mid = (start + end) / 2
    recursiveSort(numbers, start, mid)
    recursiveSort(numbers, mid + 1, end)
    merge sorted halves
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

These ideas are foundational for understanding both simple and advanced sorting techniques in C and algorithm design.

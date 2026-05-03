# Lecture 4 — Memory

## 1. Introduction

Lecture 4 focuses on how computers store and access information in memory. The main ideas are:
- Data in a computer is stored in memory as binary values (bits).
- Memory is organized as a sequence of bytes, each with its own address.
- Understanding memory is essential for working with pointers, arrays, and more advanced C programming.

### Key concepts
- Bit: the smallest unit of data, either 0 or 1.
- Byte: 8 bits grouped together.
- Address: a unique location in memory where a byte is stored.
- Value: the data stored at a memory address.

## 2. Pixel Art

Pixel art is an example of how memory and data representation can be visualized.

### How pixel art works
- An image is a grid of pixels.
- Each pixel has a color represented by values.
- In simple examples, colors can be stored using numbers.

### Example representation
- A 3x3 image can be represented as a nested array:
  - `[[0, 1, 0], [1, 1, 1], [0, 1, 0]]`
- Each number corresponds to a color or shade.
- In C, a pixel art image might be stored as a 2D array of integers.

### Memory connection
- Each pixel value is stored in memory as a number.
- The whole image is stored as a contiguous block of memory when using arrays.
- Accessing a pixel by row and column uses its memory location.

## 3. Hexadecimal

Hexadecimal is a base-16 number system used to represent binary data more compactly.

### Why hexadecimal?
- Binary values are long and hard to read.
- Hexadecimal uses 16 symbols: `0-9` and `A-F`.
- Each hex digit represents 4 binary bits.

### Examples
- Binary `0000` = hex `0`
- Binary `1111` = hex `F`
- Binary `1010` = hex `A`

### Common use cases
- Memory addresses are often shown in hexadecimal.
- Color values in graphics use hex notation like `#FF0000` for red.
- Hex makes it easier to read and write binary-based values.

### Converting between systems
- Binary to hex: group bits in 4s.
- Hex to decimal: multiply each digit by `16^position`.
- Decimal to hex: divide by 16 and use remainders.

## 4. Memory

Memory is the region where a computer stores data while programs run.

### Memory structure
- Memory is linear and byte-addressable.
- Each byte has a unique address.
- Programs access memory by using these addresses.

### Variables and memory
- When you declare a variable, the computer allocates memory for it.
- Example: `int x = 5;`
  - The value `5` is stored in a memory location reserved for `x`.
- Different data types use different amounts of memory.
  - `char` typically uses 1 byte.
  - `int` often uses 4 bytes.
  - `float` and `double` use 4 and 8 bytes respectively.

### Memory layout
- A program’s memory can include:
  - Code (instructions)
  - Data (static variables)
  - Stack (local variables and function calls)
  - Heap (dynamically allocated memory)

### Memory and arrays
- Arrays store multiple values in contiguous memory.
- Example: `int arr[3] = {1, 2, 3};`
  - `arr[0]`, `arr[1]`, and `arr[2]` are stored next to each other.
- The array name `arr` can be used to reference the starting address of the block.

## 5. Pointers

Pointers are variables that store memory addresses instead of direct values.

### Pointer basics
- A pointer stores the address of another variable.
- Syntax in C:
  - Declare: `int *p;`
  - Assign: `p = &x;`
  - Dereference: `*p` to access the value at the address.

### Example
```c
int x = 10;
int *p = &x;

printf("x = %d\n", x);      // prints 10
printf("p = %p\n", (void *) p); // prints address of x
printf("*p = %d\n", *p);    // prints 10
```

### Important pointer concepts
- `&` operator gives the address of a variable.
- `*` operator accesses the value stored at an address.
- A pointer must have a type: `int *`, `char *`, `float *`, etc.
- The pointer type tells the compiler how many bytes the pointed-to data uses.

### Pointers and memory
- Pointers allow direct access to memory locations.
- Changing `*p` changes the value stored at the address.
- Example:
```c
int x = 5;
int *p = &x;
*p = 20;
// x is now 20
```

### Pointers and arrays
- An array name acts like a pointer to its first element.
- Example: `arr[i]` is equivalent to `*(arr + i)`.
- This connection is useful for iterating through arrays and working with data in memory.

### Pointer pitfalls
- Uninitialized pointers may point to random memory.
- Dereferencing invalid pointers causes crashes.
- Always initialize pointers and use valid addresses.

## 6. String

Strings in C are arrays of characters terminated by a null byte (`\0`).

### String basics
- A string literal like `"HI!"` is stored as four characters: `H`, `I`, `!`, and `\0`.
- `char *s = "HI!";` points to the first character of the string.
- `printf("%s\n", s);` prints characters until it finds the null terminator.

### Memory and strings
- Each character occupies one byte in memory.
- The string is stored as a contiguous sequence of bytes.
- The `\0` terminator marks the end of the string.

### Example
```c
char *s = "HI!";
printf("%s\n", s);
```

## 7. Pointer arithmetic

Pointer arithmetic uses a pointer to move through memory based on the type size.

### How it works
- If `s` is a `char *`, then `s + 1` points to the next character.
- Pointer addition advances by the size of the pointed-to type.
- For `int *p`, `p + 1` moves to the next `int` in memory.

### Example
```c
char *s = "HI!";
printf("%c\n", *s);
printf("%c\n", *(s + 1));
printf("%c\n", *(s + 2));
printf("%c\n", *(s + 3));

printf("%s\n", s);
printf("%s\n", s + 1);
printf("%s\n", s + 2);
```

### Why it matters
- Pointer arithmetic is useful for iterating over arrays and strings.
- It shows how memory addresses change when you move through data.
- Understanding it helps with low-level data access and performance.

## 8. String Comparison

Comparing strings in C requires special care because strings are pointers, not simple values.

### Why `==` doesn't work
- `s == t` compares memory addresses, not the contents of the strings.
- Two strings with the same text but different addresses won't be equal with `==`.

### String comparison functions
- `strcmp(s, t)` compares two strings character by character.
- Returns 0 if strings are equal, negative if `s < t`, positive if `s > t`.

### Example
```c
char *s = "HI!";
char *t = "HI!";

if (s == t)          // FALSE - different addresses
    printf("Same\n");

if (strcmp(s, t) == 0) // TRUE - same content
    printf("Same\n");
```

## 9. Copying and malloc

Copying strings and dynamically allocating memory are fundamental memory operations.

### Why simple assignment doesn't copy
- `char *s = t;` makes both pointers reference the same memory.
- Changing one string affects the other.

### Using `strcpy` (unsafe)
- `strcpy(s, t)` copies a string from `t` to `s`.
- Assumes `s` has enough space, which can cause buffer overflow.

### Using `malloc` for dynamic memory
- `malloc(n)` allocates `n` bytes of memory on the heap.
- Returns a pointer to the allocated memory.
- Must include `<stdlib.h>`.

### Safe string copying with malloc
```c
#include <stdlib.h>
#include <string.h>

char *t = "HI!";
char *s = malloc(strlen(t) + 1); // +1 for null terminator
strcpy(s, t);

printf("%s\n", s);
free(s); // release memory when done
```

### Memory cleanup
- Always use `free()` to release memory allocated with `malloc`.
- Failing to free memory causes memory leaks.

## 10. Valgrind

Valgrind is a tool that detects memory-related errors in C programs.

### What valgrind does
- Tracks memory allocation and deallocation.
- Detects memory leaks (allocated but never freed).
- Identifies use-after-free errors.
- Reports invalid memory accesses.

### Using valgrind
```bash
valgrind ./program
```

### Common valgrind output
- Reports show where memory was allocated and not freed.
- Helpful for finding bugs in memory management.
- Essential when working with pointers and dynamic memory.

## 11. Garbage Values

Garbage values are unpredictable data in memory that haven't been initialized.

### What causes garbage values
- Declaring a variable without initializing it.
- Reading from unallocated memory.
- Using memory after it's been freed.

### Example
```c
int *p;        // p points to random memory
printf("%i\n", *p); // prints garbage value
```

### How to avoid garbage values
- Always initialize variables: `int x = 0;`
- Always initialize pointers before use: `int *p = malloc(sizeof(int));`
- Set memory to zero when allocating: `malloc()` doesn't initialize.
- Use tools like valgrind to detect uninitialized memory.

## 12. Swapping

Swapping values is a common operation that demonstrates the power of pointers.

### Why simple swapping doesn't work
- Without pointers, you can't swap values in a way that affects the caller.
- Local variables can't change the original values.

### Swapping with pointers
- Pass addresses to a swap function.
- Inside the function, use pointers to modify the original values.

### Example
```c
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int x = 1;
    int y = 2;

    swap(&x, &y);

    printf("x = %i, y = %i\n", x, y); // x = 2, y = 1
}
```

### Key concept
- Pointers allow functions to modify variables in the caller's scope.
- This is essential for many algorithms and data structures.

## 13. Overflow

Overflow happens when a value exceeds the storage capacity of its data type.

### Integer overflow
- An `int` can only store values within a certain range.
- Adding or multiplying values beyond that range can wrap around.
- This can produce incorrect, unpredictable results.

### Buffer overflow
- A buffer overflow occurs when more data is written into a memory area than it can hold.
- Common with strings and arrays in C.
- Can overwrite adjacent memory, causing bugs or security vulnerabilities.

### Example
```c
char buffer[4];
strcpy(buffer, "HELLO"); // Writes 6 bytes into 4-byte buffer
```

### Avoiding overflow
- Always allocate enough space for data and the null terminator.
- Use safer functions like `strncpy()` carefully.
- Check bounds before writing into arrays.

## 14. File I/O

File input/output lets programs read from and write to files.

### Opening files
- Use `fopen()` to open a file.
- Example: `FILE *file = fopen("data.txt", "r");`
- Modes: `"r"` for read, `"w"` for write, `"a"` for append.

### Reading and writing
- `fgets()` reads a line from a file.
- `fprintf()` writes formatted text to a file.
- `fclose()` closes the file when done.

### Example
```c
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("output.txt", "w");
    if (file == NULL)
        return 1;

    fprintf(file, "Hello, file!\n");
    fclose(file);

    return 0;
}
```

### Why it matters
- File I/O lets programs save data permanently.
- It is used for reading configuration, storing results, and more.
- Always close files to release system resources.

## 15. Summary

Lecture 4 covers advanced memory concepts:
- Memory stores data in bytes at addresses.
- Hexadecimal makes memory values readable.
- Pixel art shows data stored in memory visually.
- Pointers allow direct memory access.
- Strings are character arrays ended by `\0`.
- Pointer arithmetic navigates memory by type size.
- String comparison requires `strcmp`, not `==`.
- `malloc()` allocates heap memory; `free()` releases it.
- Valgrind detects memory errors.
- Garbage values come from uninitialized memory.
- Overflow can corrupt data or cause security issues.
- File I/O lets programs read and write persistent files.
- Pointers enable swapping and other advanced operations.

## 16. Additional notes

- Practice drawing memory diagrams for variables and pointers.
- Review how arrays, strings, and pointers are related.
- Remember that pointer types matter because they affect how many bytes are read or written.
- Always allocate enough memory and initialize pointers properly.
- Use valgrind regularly to catch memory leaks and errors.
- Test swap functions and other pointer-based operations carefully.
- Validate array sizes before using them to prevent overflow.
- Close files after using them to free resources and avoid leaks.

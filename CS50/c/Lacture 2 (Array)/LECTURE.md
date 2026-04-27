# CS50 Lecture 2: Arrays (2025)

## Table of Contents
1. [Introduction to Arrays](#introduction-to-arrays)
2. [Strings as Character Arrays](#strings-as-character-arrays)
3. [Command-Line Arguments](#command-line-arguments)
4. [Working with Integers Arrays](#working-with-integers-arrays)
5. [String Manipulation](#string-manipulation)
6. [Functions and Best Practices](#functions-and-best-practices)
7. [Key Concepts Summary](#key-concepts-summary)

---

## Introduction to Arrays

### What is an Array?
An array is a **contiguous collection of data elements of the same type** stored in memory. Arrays allow us to work with multiple values efficiently instead of creating separate variables for each value.

**Key Features:**
- Fixed size (in traditional C arrays)
- Zero-indexed (first element is at index 0)
- All elements must be of the same data type
- Elements are stored consecutively in memory

### Array Declaration Syntax
```c
datatype arrayName[arraySize];
```

**Example:**
```c
int scores[5];      // Array of 5 integers
char name[20];      // Array of 20 characters (string)
double prices[10];  // Array of 10 doubles
```

### Initializing Arrays
```c
int scores[3] = {72, 73, 33};    // Initialize with values
char word[5] = {'A', 'S', 'R', 'A', 'F'};  // Character array
char s[] = "HI!";                // String initialization
```

---

## Strings as Character Arrays

### Understanding Strings in C
In C, **strings are arrays of characters terminated by a null character (`\0`)**. The null character marks the end of the string.

### Character Arrays vs String Literals
From `hi.c`:
```c
char s[] = "HI! ";     // String literal - includes null terminator automatically
char word[5];
word[0] = 'A';
word[1] = 'S';
word[2] = 'R';
word[3] = 'A';
word[4] = 'F';
```

**Output:**
```
HI! 
ASRAF
A S R A
65 83 82 65 70
H I !  
72 73 33 32
```

### Key Observations:
1. **`%s` format specifier** - prints the entire string until it encounters `\0`
2. **`%c` format specifier** - prints a single character
3. **`%i` format specifier** - prints ASCII value of a character
4. Each character has an ASCII integer value (A=65, S=83, etc.)

### String Indexing
```c
printf("%c\n", s[0]);    // Prints: H
printf("%i\n", s[0]);    // Prints: 72 (ASCII value)
```

---

## Command-Line Arguments

### What are Command-Line Arguments?
**Command-line arguments** are values passed to a program when it's executed from the command line.

### Function Signature
```c
int main(int argc, char *argv[])
```

**Parameters:**
- **`argc`** (argument count) - The number of command-line arguments (including the program name)
- **`argv`** (argument vector) - An array of strings containing the arguments

### Example from `greet.c`:
```c
#include <stdio.h>
int main(int argc, char *argv[])
{
    // for (int i = 0; i < argc; i++)
    for(int i = 0; i < argc; i++)
    {
        printf("argv[%i]: %s\n", i, argv[i]);
    }
}
```

**Running the program:**
```bash
./greet Alice Bob
```

**Output:**
```
argv[0]: ./greet      // Program name
argv[1]: Alice        // First argument
argv[2]: Bob          // Second argument
```

### Validating Arguments from `status.c`:
```c
#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Missing command line argument\n");
        return 1;
    }
    printf("Hello, %s\n", argv[1]);
    return 0;
}
```

---

## Working with Integer Arrays

### Basic Integer Arrays
From `scores.c`:
```c
int scores[3];
scores[0] = 72;
scores[1] = 73;
scores[2] = 33;

// Calculate average
printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
```

**Important:** Use `3.0` instead of `3` for floating-point division!

### Dynamic Arrays (VLA - Variable Length Arrays)
From `score2.c`:
```c
int n;
printf("Number of scores: ");
scanf("%d", &n);

int scores[n];  // Array size determined at runtime
for(int i = 0; i < n; i++)
{
    printf("Score: ");
    scanf("%d", &scores[i]);
}

// Calculate average
int sum = 0;
for(int i = 0; i < n; i++)
{
    sum += scores[i];
}
printf("Average: %f\n", (float)sum / n);
```

**Key Points:**
- VLAs allow creating arrays with size determined at runtime
- Must use `scanf()` to read user input
- Use a loop to populate array elements
- Use `&` operator to get address of variable for `scanf()`

---

## String Manipulation

### Calculating String Length Manually
From `length.c`:
```c
char name[4];
printf("What is your name? \n");
scanf("%s", name);
printf("Hello, %s\n", name);

// Count characters manually
int n = 0;
while (name[n] != '\0')  // Loop until null terminator
{
    n++;
}
printf("Length of name: %i\n", n);
```

### Using the `strlen()` Function
From `length_string.c`:
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[4];
    printf("What is your name? \n");
    scanf("%s", name);
    printf("Hello, %s\n", name);

    // Get length using strlen()
    int n = strlen(name);
    printf("Length of name: %i\n", n);
}
```

**Advantages of `strlen()`:**
- More efficient
- Automatically finds the null terminator
- Part of the standard C library
- Requires `#include <string.h>`

### Iterating Through Strings
From `string.c`:
```c
#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[1];
    printf("What is your name? \n");
    scanf("%s", s);
    printf("Hello, %s\n", s);

    // Print each character of string   
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c\n", s[i]);
    }
    printf("\n");
}
```

**Note:** `for (int i = 0, n = strlen(s); i < n; i++)` - initializes two variables in the for loop

---

## String Conversion and Case Manipulation

### Manual Uppercase Conversion
From `uppercase.c`:
```c
#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[4];
    printf("What is your name? ");
    scanf("%s", s);
    printf("Before: %s\n", s);
    printf("After:  ");
    
    // Convert to uppercase manually
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // ASCII difference between 'a' and 'A' is 32
            s[i] = s[i] - ('a' - 'A');
            printf("%c", s[i]);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```

**How it works:**
- 'a' = 97, 'A' = 65
- Difference = 32
- So: lowercase - 32 = uppercase
- Or: lowercase - ('a' - 'A') = uppercase

### Using `toupper()` Function
From `uppercase_with_header_file.c`:
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[4];
    printf("What is your name? ");
    scanf("%s", s);
    printf("Before: %s\n", s);
    printf("After : ");
    
    // Convert to uppercase using toupper()
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
```

**Advantages:**
- Cleaner and more readable
- Handles edge cases automatically
- Part of standard library (`ctype.h`)
- Also available: `tolower()`, `isalpha()`, `isdigit()`, etc.

---

## Functions and Best Practices

### Creating Functions
From `make_function.c`:
```c
#include <stdio.h>

int get_int(char *prompt);  // Function declaration (prototype)

int main(void)
{
    int A = get_int("Enter an integer: ");
    int B = get_int("Enter another integer: ");
    printf("%d + %d = %d\n", A, B, A + B);
    printf("Wow!, Finally, I can make functions in C! :D\n");
}

// Function definition
int get_int(char *prompt)
{
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}
```

**Key Concepts:**
1. **Function Declaration** - tells compiler about function before use
2. **Function Definition** - actual implementation
3. **Parameters** - inputs to function (here: `char *prompt`)
4. **Return Type** - what the function returns (here: `int`)
5. **Function Call** - using the function in main

### Another Function Example from `buggy.c`:
```c
#include <stdio.h>

void print_column(int height);  // Declaration

int main(void)
{
    int h;
    printf("Height: ");
    scanf("%d", &h);
    print_column(h);  // Function call
}

void print_column(int height)  // Definition
{
    for (int i = 0; i < height; i++)
    {
        printf("###\n");
    }
}
```

**Key Difference:**
- `void` return type means the function doesn't return anything
- Still can take parameters

---

## Key Concepts Summary

### Arrays in C
| Concept | Details |
|---------|---------|
| **Declaration** | `int arr[size];` or `int arr[] = {...};` |
| **Indexing** | Zero-based (0, 1, 2, ...) |
| **Size** | Can be fixed or dynamic (VLA) |
| **Strings** | Character arrays ending with `\0` |
| **Bounds** | No automatic bounds checking (buffer overflow risk) |

### String Libraries
| Header | Functions |
|--------|-----------|
| `<string.h>` | `strlen()`, `strcpy()`, `strcmp()`, etc. |
| `<ctype.h>` | `toupper()`, `tolower()`, `isalpha()`, `isdigit()` |
| `<stdio.h>` | `scanf()`, `printf()` |

### Important Points
✓ Strings are null-terminated (`\0`)
✓ Use `%s` for strings, `%c` for characters, `%i` for integers
✓ Arrays are passed by reference to functions
✓ Always validate user input (especially with `argv`)
✓ Use library functions when available (`strlen()`, `toupper()`, etc.)
✓ Be careful with floating-point division (use `3.0` not `3`)
✓ Always use `&` operator with `scanf()` for non-array variables

### Common Errors to Avoid
❌ **Buffer Overflow** - writing beyond array bounds
❌ **Off-by-one errors** - forgetting arrays are 0-indexed
❌ **Integer division** - dividing two integers gives integer result
❌ **Missing null terminator** - always ensure strings end with `\0`
❌ **Unvalidated input** - always check argc/user input

---

## Practice Exercises

1. **String Reversal** - Write a program to reverse a string
2. **Character Counter** - Count vowels and consonants in a string
3. **Array Sorting** - Sort an array of integers
4. **Command-Line Calculator** - Use `argc` and `argv` to perform calculations
5. **String Comparison** - Compare two strings character by character

---

## Resources
- **CS50 Course**: Arrays and Strings in C
- **Header Files**: `<string.h>`, `<ctype.h>`, `<stdio.h>`
- **Key Functions**: `strlen()`, `toupper()`, `tolower()`, `scanf()`, `printf()`

---

**Last Updated**: CS50 2025 | Lecture 2: Arrays

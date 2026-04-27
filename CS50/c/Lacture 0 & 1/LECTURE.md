# CS50 Lectures 0 & 1: Scratch and Introduction to C (2025)

## Table of Contents
1. [Lecture 0: Scratch Fundamentals](#lecture-0-scratch-fundamentals)
2. [Lecture 1: Introduction to C](#lecture-1-introduction-to-c)
3. [Basic C Syntax](#basic-c-syntax)
4. [Conditional Statements](#conditional-statements)
5. [Loops and Repetition](#loops-and-repetition)
6. [Functions](#functions)
7. [Input and Output](#input-and-output)
8. [Data Types](#data-types)
9. [Key Concepts Summary](#key-concepts-summary)

---

## Lecture 0: Scratch Fundamentals

### What is Scratch?
**Scratch** is a visual programming language that teaches fundamental programming concepts using blocks. It serves as an introduction to:
- **Sequencing** - doing things one after another
- **Conditionals** - making decisions
- **Loops** - repeating actions
- **Variables** - storing values
- **Functions** - reusable code blocks

### Scratch Concepts
| Concept | Purpose | Example |
|---------|---------|---------|
| **Say block** | Output text | "Hello, World!" |
| **Ask block** | Get user input | Ask "What is your name?" |
| **If/Else blocks** | Make decisions | If answer = yes, then... |
| **Repeat loops** | Do something multiple times | Repeat 10 times |
| **Variables** | Store and use values | Set score to 0 |
| **Custom blocks** | Create reusable functions | Define print_row |

### Why Scratch Matters
- ✓ Teaches logic without syntax complexity
- ✓ Visual representation of control flow
- ✓ Easier to understand algorithms
- ✓ Foundation for moving to text-based languages like C

---

## Lecture 1: Introduction to C

### What is C?
**C** is a powerful, low-level programming language that:
- Compiles to machine code for fast execution
- Has minimal abstraction (you control memory)
- Is widely used in systems programming
- Serves as the foundation for many modern languages
- Has been used since 1972!

### Why Learn C?
1. **Close to hardware** - understand how computers actually work
2. **Efficient** - fast execution and minimal memory usage
3. **Foundational** - learn concepts applicable to all languages
4. **Industry standard** - used in operating systems, databases, embedded systems

### C Program Structure
```c
#include <stdio.h>   // Include library

int main(void)       // Main function - where program starts
{
    // Code goes here
    
    return 0;        // Return exit code
}
```

**Key Points:**
- Every C program must have a `main()` function
- `#include` brings in library functions
- `return 0;` indicates successful program termination
- Semicolons `;` end statements

---

## Basic C Syntax

### Hello World - Your First Program
From `hello.c`:
```c
#include <stdio.h>

int main(void) 
{
    char name[50];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    printf("Welcome to CS50!\n");
    printf("Do you ready to enjoy learning C?\nLet's get started!\n");
    return 0;
}
```

**Output:**
```
What is your name? Alice
Hello, Alice!
Welcome to CS50!
Do you ready to enjoy learning C?
Let's get started!
```

**Key Concepts:**
- `printf()` - output text to screen
- `scanf()` - read input from user
- `%s` - format specifier for strings
- `\n` - newline character

### Variables and Data Types
```c
int x;           // Integer variable
float price;     // Floating-point number
char letter;     // Single character
char name[50];   // Array of 50 characters (string)
```

### Printf Format Specifiers
| Format | Type | Example |
|--------|------|---------|
| `%s` | String | `"Hello"` |
| `%d` | Integer | `42` |
| `%f` | Float | `3.14` |
| `%c` | Character | `'A'` |
| `%i` | Integer | `100` |

### Escape Sequences
| Escape | Meaning |
|--------|---------|
| `\n` | Newline |
| `\t` | Tab |
| `\\` | Backslash |
| `\"` | Double quote |
| `\'` | Single quote |

---

## Conditional Statements

### If/Else Basics
From `condition.c` - Finding the Greatest Number:
```c
#include <stdio.h>

int main(void)
{
    int x, y, z;
    printf("Enter first integers: ");
    scanf("%d", &x);
    printf("Enter second integers: ");
    scanf("%d", &y);
    printf("Enter third integers: ");
    scanf("%d", &z);
    
    if(x > y && x > z)
    {
        printf("%d is the greatest among %d and %d\n", x, y, z);
    }
    else if(y > x && y > z)
    {
        printf("%d is the greatest among %d and %d\n", y, x, z);
    }
    else
    {
        printf("%d is the greatest among %d and %d\n", z, x, y);
    }
    return 0;
}
```

### Comparison Operators
| Operator | Meaning | Example |
|----------|---------|---------|
| `==` | Equal to | `x == 5` |
| `!=` | Not equal to | `x != 5` |
| `>` | Greater than | `x > 5` |
| `<` | Less than | `x < 5` |
| `>=` | Greater or equal | `x >= 5` |
| `<=` | Less or equal | `x <= 5` |

### Logical Operators
```c
&&  // AND - both conditions must be true
||  // OR - at least one condition must be true
!   // NOT - negates a condition
```

**Example:**
```c
if (age > 18 && age < 65)  // Both must be true
{
    printf("You can work!\n");
}

if (day == 6 || day == 7)  // At least one must be true
{
    printf("It's the weekend!\n");
}

if (!raining)  // True if NOT raining
{
    printf("Let's go outside!\n");
}
```

### If/Else-If/Else Structure
```c
if (condition1)
{
    // Do this if condition1 is true
}
else if (condition2)
{
    // Do this if condition2 is true
}
else if (condition3)
{
    // Do this if condition3 is true
}
else
{
    // Do this if none of the above are true
}
```

### Yes/No Input Validation
From `agree.c`:
```c
#include <stdio.h>

int main(void)
{
    char answer[10];
    printf("Do you agree? ");
    scanf("%s", answer);
    
    if(answer[0] == 'y' || answer[0] == 'Y')
    {
        printf("Agreed!\n");
    }
    else if(answer[0] == 'n' || answer[0] == 'N')
    {
        printf("Not agreed!\n");
    }
    else
    {
        printf("Invalid input! Please enter 'yes' or 'no'.\n");
    }
    return 0;
}
```

**Key Point:** `answer[0]` gets the first character of the input string

---

## Arithmetic and Calculator

### Basic Arithmetic Operators
| Operator | Operation | Example |
|----------|-----------|---------|
| `+` | Addition | `5 + 3 = 8` |
| `-` | Subtraction | `5 - 3 = 2` |
| `*` | Multiplication | `5 * 3 = 15` |
| `/` | Division | `5 / 2 = 2` (integer), `5.0 / 2 = 2.5` (float) |
| `%` | Modulo (remainder) | `5 % 2 = 1` |

### Calculator Program
From `calculator.c`:
```c
#include <stdio.h>

int main(void)
{
    int x, y;
    char op;

    printf("x: ");
    scanf("%d", &x);

    printf("y: ");
    scanf("%d", &y);

    printf("operator: ");
    scanf(" %c", &op);  // Note the space before %c

    if (op == '+')
    {
        printf("%d %c %d = %d\n", x, op, y, x + y);
    }
    else if (op == '-')
    {
        printf("%d %c %d = %d\n", x, op, y, x - y);
    }
    else if (op == '*')
    {
        printf("%d %c %d = %d\n", x, op, y, x * y);
    }
    else if (op == '/')
    {
        printf("%d %c %d = %f\n", x, op, y, (float)x / y);
    }
    else if (op == '%')
    {
        printf("%d %c %d = %d\n", x, op, y, x % y); 
    }
    else
    {
        printf("Invalid operator.\n");
    }
}
```

**Output Example:**
```
x: 10
y: 3
operator: /
10 / 3 = 3.333333
```

**Important Notes:**
- Use `scanf(" %c", &op)` - space before `%c` to skip whitespace
- Cast to `(float)` for floating-point division: `(float)x / y`
- `&` operator gets the memory address (required for `scanf`)

---

## Loops and Repetition

### For Loop
The most common loop structure:
```c
for(int i = 0; i < 3; i++)
{
    printf("Meow\n");
}
```

**For Loop Syntax:**
```c
for (initialization; condition; increment)
{
    // Code to repeat
}
```

**Parts:**
- **initialization** - `int i = 0` - set up counter
- **condition** - `i < 3` - when to keep looping
- **increment** - `i++` - what happens each iteration

### While Loop
```c
int i = 1;
while (i <= 3)
{
    printf("Meow\n");
    i++;
}
```

**While Loop:**
- Repeats while condition is true
- Good when you don't know how many iterations you need
- Must update counter manually

### Do-While Loop
```c
int i = 1;
do
{
    printf("Meow\n");
    i++;
} while (i <= 3);
```

**Key Difference:** Code runs at least once before checking condition

### Loop Comparison
```c
// For loop - best when you know iteration count
for(int i = 0; i < n; i++)
{
    printf("Meow\n");
}

// While loop - best for unknown iteration count
while (user_wants_more)
{
    printf("Meow\n");
}

// Do-While - runs at least once
do
{
    printf("Enter number: ");
    scanf("%d", &n);
} while (n < 1 || n > 10);
```

---

## Functions

### Creating and Using Functions
From `cat.c`:
```c
#include <stdio.h>

void meow(void)        // Function declaration and definition
{
    printf("Meow\n");
}

int main(void)
{
    for(int i = 0; i < 3; i++)
    {
        meow();        // Function call
    }
    return 0;
}
```

**Output:**
```
Meow
Meow
Meow
```

### Function Syntax
```c
returnType functionName(parameters)
{
    // Function body
    return value;  // If returnType is not void
}
```

### Function with Parameters
From `mario.c`:
```c
#include <stdio.h>

void print_row(int n)  // Parameter: n is an integer
{
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

int main(void)
{
    int n = 4;
    for(int row = 0; row < 4; row++)
    {
        print_row(n);  // Call with argument
    }
}
```

**Output:**
```
####
####
####
####
```

### Function Declaration vs Definition
```c
// Declaration (prototype) - tells compiler about function
void greet(char *name);

// Definition - actual implementation
void greet(char *name)
{
    printf("Hello, %s!\n", name);
}

// Can also combine declaration and definition
void greet(char *name)
{
    printf("Hello, %s!\n", name);
}
```

### Function with Return Value
```c
int add(int a, int b)  // Returns an int
{
    return a + b;      // Return the result
}

int main(void)
{
    int sum = add(5, 3);
    printf("Sum: %d\n", sum);  // Output: Sum: 8
}
```

### Function Types
| Type | Declaration | Purpose |
|------|-------------|---------|
| **void** | `void func(void)` | Doesn't return anything |
| **int** | `int func(void)` | Returns an integer |
| **float** | `float func(void)` | Returns a float |
| **char** | `char func(void)` | Returns a character |

---

## Input and Output

### Printf (Output)
```c
printf("Simple text\n");
printf("Name: %s, Age: %d\n", name, age);
printf("Price: $%.2f\n", price);  // 2 decimal places
```

### Scanf (Input)
```c
int age;
scanf("%d", &age);        // Read integer

char name[50];
scanf("%s", name);        // Read string

float salary;
scanf("%f", &salary);     // Read float

char grade;
scanf(" %c", &grade);     // Read character (note space before %c)
```

**Important:** Always use `&` with `scanf()` to provide memory address (except for strings and arrays)

### Multiple Inputs
```c
int x, y;
char op;
printf("Enter: ");
scanf("%d %d %c", &x, &y, &op);
```

### Input Format Specifiers
| Format | Type | Example |
|--------|------|---------|
| `%d` | Integer | `42` |
| `%f` | Float | `3.14` |
| `%s` | String | `"hello"` |
| `%c` | Character | `'A'` |
| `%i` | Integer | `100` |
| `%x` | Hex | `FF` |

---

## Data Types

### Basic Data Types in C
| Type | Size | Range | Format |
|------|------|-------|--------|
| `char` | 1 byte | -128 to 127 | `%c` |
| `int` | 4 bytes | -2B to 2B | `%d` |
| `float` | 4 bytes | ~1.2e-38 to 3.4e38 | `%f` |
| `double` | 8 bytes | ~2.2e-308 to 1.8e308 | `%lf` |
| `long` | 8 bytes | Very large range | `%ld` |
| `unsigned int` | 4 bytes | 0 to 4B | `%u` |

### Variable Declaration
```c
int age = 25;                    // Initialize at declaration
char initial;
initial = 'A';                   // Initialize later

float pi = 3.14159;
double x, y, z;                  // Declare multiple
```

### Type Casting
```c
int x = 5;
float result = (float)x / 2;     // 2.5 (not 2)

float price = 19.99;
int cents = (int)(price * 100);  // 1999
```

---

## Key Concepts Summary

### Comparing Scratch to C

| Concept | Scratch | C |
|---------|---------|---|
| Output | Say block | `printf()` |
| Input | Ask block | `scanf()` |
| Decision | If block | `if (condition)` |
| Repetition | Repeat block | `for`, `while`, `do-while` |
| Storage | Variable block | `int x;`, `char name[50];` |
| Reuse | My Blocks | Functions |

### Programming Fundamentals
✓ **Sequencing** - Statements execute in order  
✓ **Conditionals** - Make decisions with if/else  
✓ **Loops** - Repeat with for/while/do-while  
✓ **Variables** - Store data in memory  
✓ **Functions** - Organize and reuse code  
✓ **Input/Output** - Interact with user  

### Common Syntax Rules
- Semicolons `;` end statements
- Braces `{}` group blocks of code
- Include headers with `#include`
- Every program needs `main()` function
- Use `&` with `scanf()` (except strings/arrays)
- `return 0;` indicates success

### Debugging Tips
❌ **Syntax errors** - Missing semicolons, brackets, quotes
❌ **Logic errors** - Program runs but does wrong thing
❌ **Runtime errors** - Program crashes during execution
✓ Use `printf()` to check values during execution
✓ Break code into smaller functions
✓ Test with different inputs

---

## Common Mistakes

### Mistake 1: Forgetting & in scanf()
```c
// WRONG - compiler error
int x;
scanf("%d", x);

// CORRECT
int x;
scanf("%d", &x);
```

### Mistake 2: Integer Division
```c
// WRONG - gives 2 (integer division)
float result = 5 / 2;

// CORRECT - gives 2.5 (float division)
float result = 5.0 / 2;
// OR
float result = (float)5 / 2;
```

### Mistake 3: Character vs String Input
```c
// For single character
char letter;
scanf(" %c", &letter);  // Note the space

// For string
char name[50];
scanf("%s", name);  // No & needed
```

### Mistake 4: Off-by-One Errors
```c
// WRONG - prints 0 times
for(int i = 0; i < 0; i++)

// WRONG - prints 4 times (0, 1, 2, 3)
for(int i = 0; i <= 3; i++)  // 4 iterations

// CORRECT - prints 3 times (0, 1, 2)
for(int i = 0; i < 3; i++)
```

---

## Practice Exercises

### Easy
1. **Greeting Program** - Ask for name and age, print a personalized message
2. **Simple Math** - Create a calculator for two numbers
3. **Temperature Converter** - Convert Celsius to Fahrenheit

### Medium
4. **Pattern Printing** - Create a triangle, pyramid, or diamond pattern
5. **Number Guessing** - Create a game where user guesses random number
6. **Grade Calculator** - Calculate average from multiple scores

### Hard
7. **Fibonacci Sequence** - Print first N Fibonacci numbers
8. **Prime Number Checker** - Determine if number is prime
9. **Password Validator** - Check if password meets requirements

---

## Important Functions Reference

### stdio.h
```c
printf()      // Output formatted text
scanf()       // Input formatted data
getchar()     // Read single character
putchar()     // Print single character
```

### stdlib.h (Standard Library)
```c
malloc()      // Allocate memory
free()        // Free allocated memory
exit()        // Exit program
rand()        // Generate random number
```

### math.h (Math Library)
```c
pow()         // Power function
sqrt()        // Square root
abs()         // Absolute value
```

---

## How to Compile and Run

### Using GCC (GNU Compiler Collection)
```bash
# Compile
gcc hello.c -o hello

# Run
./hello

# Compile with debugging info
gcc -g hello.c -o hello

# Compile with warnings
gcc -Wall hello.c -o hello
```

### Using Make
```bash
make hello
./hello
```

---

## Key Takeaways

1. **C is powerful** - Low-level control with high performance
2. **Scratch → C** - Same concepts, different syntax
3. **Practice matters** - Write code, run it, break it, fix it
4. **Read errors carefully** - Compiler errors are helpful
5. **Functions are your friend** - Break code into manageable pieces
6. **Always validate input** - Never trust user input
7. **Think like a computer** - Sequential, logical thinking

---

## Resources
- **CS50 Course**: Introduction to Computer Science
- **C Documentation**: https://www.cprogramming.com/
- **Online Compiler**: https://repl.it/ (practice online)
- **Headers**: `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<math.h>`

---

**Last Updated**: CS50 2025 | Lectures 0 & 1: Scratch and Introduction to C

# CS50 Python — Complete Lecture Notes

## 1. Introduction to Python

Python is a high-level, interpreted programming language known for its simplicity and readability.

### Why Python?
- Easy to learn and read.
- Supports multiple programming paradigms (procedural, functional, object-oriented).
- Large ecosystem of libraries and frameworks.
- Used in web development, data science, automation, and more.

### Python basics
- Python is dynamically typed (no need to declare variable types).
- Code is executed line by line.
- Indentation matters (defines code blocks).

### Your first program
```python
print("Hello, World!")
```

## 2. Variables and Data Types

Variables store data values. Python automatically infers the data type.

### Common data types
- `int`: Integer numbers (e.g., `42`, `-10`)
- `float`: Decimal numbers (e.g., `3.14`, `-2.5`)
- `str`: Text strings (e.g., `"Hello"`, `'World'`)
- `bool`: Boolean values (`True`, `False`)

### Creating variables
```python
name = "Alice"
age = 25
height = 5.6
is_student = True
```

### Type checking
```python
type(name)      # <class 'str'>
type(age)       # <class 'int'>
type(height)    # <class 'float'>
type(is_student) # <class 'bool'>
```

### Type conversion
```python
int("42")       # Converts string to integer
str(42)         # Converts integer to string
float("3.14")   # Converts string to float
```

## 3. Operators

Operators perform operations on variables and values.

### Arithmetic operators
- `+`: Addition
- `-`: Subtraction
- `*`: Multiplication
- `/`: Division (returns float)
- `//`: Integer division (returns int)
- `%`: Modulo (remainder)
- `**`: Exponentiation

### Comparison operators
- `==`: Equal to
- `!=`: Not equal to
- `<`: Less than
- `>`: Greater than
- `<=`: Less than or equal to
- `>=`: Greater than or equal to

### Logical operators
- `and`: Logical AND
- `or`: Logical OR
- `not`: Logical NOT

### Example
```python
x = 10
y = 3

print(x + y)    # 13
print(x // y)   # 3
print(x % y)    # 1
print(x > y)    # True
print(x > 5 and y > 5)  # False
```

## 4. Control Flow: if/elif/else

Control flow statements execute code based on conditions.

### if statement
```python
age = 18

if age >= 18:
    print("You are an adult")
```

### if/else statement
```python
age = 16

if age >= 18:
    print("You are an adult")
else:
    print("You are a minor")
```

### if/elif/else statement
```python
score = 85

if score >= 90:
    print("Grade: A")
elif score >= 80:
    print("Grade: B")
elif score >= 70:
    print("Grade: C")
else:
    print("Grade: F")
```

## 5. Loops

Loops repeat code blocks multiple times.

### for loop
- Iterates a specific number of times or over a sequence.

```python
for i in range(5):
    print(i)  # prints 0, 1, 2, 3, 4

for name in ["Alice", "Bob", "Charlie"]:
    print(name)
```

### while loop
- Repeats while a condition is true.

```python
count = 0
while count < 5:
    print(count)
    count += 1
```

### break and continue
- `break`: Exits the loop immediately.
- `continue`: Skips the current iteration.

```python
for i in range(10):
    if i == 3:
        continue  # Skip 3
    if i == 7:
        break     # Exit at 7
    print(i)
```

## 6. Functions

Functions are reusable blocks of code that perform specific tasks.

### Defining functions
```python
def greet(name):
    print(f"Hello, {name}!")

greet("Alice")  # Output: Hello, Alice!
```

### Return values
```python
def add(a, b):
    return a + b

result = add(5, 3)
print(result)  # Output: 8
```

### Default parameters
```python
def greet(name, greeting="Hello"):
    print(f"{greeting}, {name}!")

greet("Alice")            # Hello, Alice!
greet("Bob", "Hi")        # Hi, Bob!
```

### Multiple return values
```python
def get_coordinates():
    return 10, 20

x, y = get_coordinates()
print(x, y)  # Output: 10 20
```

### Scope
- Variables defined inside a function are local to that function.
- Variables defined outside are global.

## 7. Lists

Lists are ordered, mutable collections of items.

### Creating lists
```python
numbers = [1, 2, 3, 4, 5]
mixed = [1, "hello", 3.14, True]
empty = []
```

### Accessing elements
```python
numbers = [10, 20, 30, 40, 50]

print(numbers[0])    # 10 (first element)
print(numbers[-1])   # 50 (last element)
print(numbers[1:4])  # [20, 30, 40] (slice)
```

### List operations
```python
numbers = [1, 2, 3]

numbers.append(4)      # Add to end: [1, 2, 3, 4]
numbers.insert(0, 0)   # Insert at position: [0, 1, 2, 3, 4]
numbers.remove(2)      # Remove value: [0, 1, 3, 4]
numbers.pop()          # Remove last: [0, 1, 3]
len(numbers)           # Length: 3
numbers.sort()         # Sort in place
```

### Iterating lists
```python
numbers = [1, 2, 3]

for num in numbers:
    print(num)
```

## 8. Dictionaries

Dictionaries store key-value pairs and are unordered (as of Python 3.7+, they maintain insertion order).

### Creating dictionaries
```python
person = {"name": "Alice", "age": 25, "city": "NYC"}
empty = {}
```

### Accessing values
```python
person = {"name": "Alice", "age": 25}

print(person["name"])  # Alice
print(person.get("age"))  # 25
print(person.get("email", "Not found"))  # Not found (default)
```

### Adding and modifying
```python
person = {"name": "Alice"}

person["age"] = 25  # Add new key-value
person["name"] = "Bob"  # Modify value
del person["age"]   # Delete key
```

### Dictionary methods
```python
person = {"name": "Alice", "age": 25}

person.keys()      # dict_keys(['name', 'age'])
person.values()    # dict_values(['Alice', 25])
person.items()     # dict_items([('name', 'Alice'), ('age', 25)])
```

### Iterating dictionaries
```python
person = {"name": "Alice", "age": 25}

for key, value in person.items():
    print(f"{key}: {value}")
```

## 9. Strings

Strings are sequences of characters.

### String basics
```python
s = "Hello, World!"

print(len(s))       # Length: 13
print(s[0])         # First char: H
print(s[-1])        # Last char: !
print(s[0:5])       # Slice: Hello
```

### String methods
```python
s = "hello world"

s.upper()           # HELLO WORLD
s.lower()           # hello world
s.title()           # Hello World
s.replace("world", "Python")  # hello Python
s.split()           # ['hello', 'world']
```

### String formatting
```python
name = "Alice"
age = 25

print(f"My name is {name} and I am {age} years old")
print("My name is {} and I am {} years old".format(name, age))
```

## 10. Tuples

Tuples are ordered, immutable collections.

### Creating tuples
```python
point = (10, 20)
single = (1,)       # Trailing comma for single element
empty = ()
```

### Accessing elements
```python
point = (10, 20, 30)

print(point[0])     # 10
print(point[1:3])   # (20, 30)
```

### Tuple unpacking
```python
x, y = (10, 20)
print(x, y)  # 10 20
```

### Why tuples?
- Immutable (safer for data that shouldn't change).
- Hashable (can be dictionary keys or set elements).
- Slightly more efficient than lists.

## 11. Sets

Sets are unordered collections of unique items.

### Creating sets
```python
numbers = {1, 2, 3, 4, 5}
empty = set()  # Note: {} creates dict, not set
```

### Set operations
```python
a = {1, 2, 3}
b = {3, 4, 5}

a.union(b)          # {1, 2, 3, 4, 5}
a.intersection(b)   # {3}
a.difference(b)     # {1, 2}
1 in a              # True
```

## 12. File I/O

Programs can read and write files to store data permanently.

### Reading files
```python
with open("data.txt", "r") as file:
    content = file.read()  # Read entire file
    print(content)

with open("data.txt", "r") as file:
    for line in file:
        print(line.strip())  # Read line by line
```

### Writing files
```python
with open("output.txt", "w") as file:
    file.write("Hello, file!\n")
    file.write("This is line 2\n")
```

### Appending to files
```python
with open("output.txt", "a") as file:
    file.write("Appended line\n")
```

### Why use `with`?
- Automatically closes the file, even if an error occurs.
- Cleaner and safer than manual file handling.

## 13. Exception Handling

Exception handling allows programs to handle errors gracefully.

### try/except
```python
try:
    x = int("abc")  # This will raise an error
except ValueError:
    print("Invalid input")
```

### try/except/else
```python
try:
    x = int("42")
except ValueError:
    print("Invalid input")
else:
    print(f"Number: {x}")
```

### try/except/finally
```python
try:
    file = open("data.txt", "r")
    content = file.read()
except FileNotFoundError:
    print("File not found")
finally:
    file.close()  # Always executed
```

### Multiple exceptions
```python
try:
    x = int(input("Enter a number: "))
except ValueError:
    print("Invalid number")
except KeyboardInterrupt:
    print("Program interrupted")
```

## 14. Functions (Advanced)

### *args and **kwargs
```python
def print_args(*args):
    for arg in args:
        print(arg)

print_args(1, 2, 3)  # prints 1, 2, 3

def print_kwargs(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")

print_kwargs(name="Alice", age=25)
```

### Lambda functions
```python
square = lambda x: x ** 2
print(square(5))  # 25

numbers = [1, 2, 3, 4, 5]
squared = list(map(lambda x: x ** 2, numbers))
print(squared)  # [1, 4, 9, 16, 25]
```

## 15. List Comprehension

Concise way to create lists.

### Basic list comprehension
```python
squares = [x ** 2 for x in range(5)]
print(squares)  # [0, 1, 4, 9, 16]
```

### With condition
```python
evens = [x for x in range(10) if x % 2 == 0]
print(evens)  # [0, 2, 4, 6, 8]
```

### Nested comprehension
```python
matrix = [[x for x in range(3)] for _ in range(3)]
# [[0, 1, 2], [0, 1, 2], [0, 1, 2]]
```

## 16. Object-Oriented Programming

Classes allow you to create custom objects with attributes and methods.

### Defining a class
```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):
        print(f"Hello, my name is {self.name}")

person = Person("Alice", 25)
person.greet()  # Hello, my name is Alice
```

### Attributes and methods
- Attributes: Data stored in an object (e.g., `self.name`).
- Methods: Functions defined in a class (e.g., `greet()`).

### Inheritance
```python
class Animal:
    def speak(self):
        print("Some sound")

class Dog(Animal):
    def speak(self):
        print("Woof!")

dog = Dog()
dog.speak()  # Woof!
```

## 17. Modules and Libraries

Modules are files containing Python code. Libraries are collections of modules.

### Importing modules
```python
import math
print(math.sqrt(16))  # 4.0

from math import pi, sqrt
print(pi)  # 3.14159...
print(sqrt(16))  # 4.0
```

### Common libraries
- `math`: Mathematical functions.
- `random`: Random number generation.
- `datetime`: Date and time handling.
- `os`: Operating system interactions.
- `sys`: System-specific parameters.
- `json`: JSON parsing.
- `requests`: HTTP requests.
- `numpy`: Numerical computing.
- `pandas`: Data analysis.

### Example usage
```python
import random

print(random.randint(1, 10))  # Random int between 1-10
print(random.choice([1, 2, 3]))  # Random choice from list

import datetime
now = datetime.datetime.now()
print(now)
```

## 18. Working with JSON

JSON is a common format for storing and exchanging data.

### Parsing JSON
```python
import json

data = '{"name": "Alice", "age": 25}'
obj = json.loads(data)  # Parse JSON string
print(obj["name"])  # Alice
```

### Creating JSON
```python
import json

obj = {"name": "Alice", "age": 25}
data = json.dumps(obj)  # Convert to JSON string
print(data)  # {"name": "Alice", "age": 25}
```

### File I/O with JSON
```python
import json

# Writing
with open("data.json", "w") as file:
    json.dump({"name": "Alice"}, file)

# Reading
with open("data.json", "r") as file:
    data = json.load(file)
    print(data)
```

## 19. Regular Expressions

Regular expressions are patterns for matching and manipulating strings.

### Basic patterns
```python
import re

text = "Hello 123 World"

re.findall(r"\d+", text)  # ['123']
re.search(r"World", text)  # Found
re.sub(r"\d", "X", text)   # Hello XXX World
```

### Common patterns
- `.`: Any character
- `\d`: Digit
- `\w`: Word character (letter, digit, underscore)
- `\s`: Whitespace
- `*`: Zero or more
- `+`: One or more
- `?`: Zero or one

## 20. Summary

Python is a versatile language with:
- Simple syntax and dynamic typing.
- Rich data structures (lists, dictionaries, sets, tuples).
- Powerful control flow and functions.
- Object-oriented programming support.
- Extensive standard library and third-party packages.
- Exception handling for robust error management.

## 21. Key Takeaways

- Python code is readable and concise.
- Use functions and classes to organize code.
- Leverage built-in and external libraries.
- Handle errors gracefully with try/except.
- Use list comprehensions for clean, efficient code.
- Understand the difference between mutable and immutable types.
- Practice with small programs to build proficiency.

## 22. Additional Resources

- Official Python documentation: https://docs.python.org/
- Python Standard Library overview.
- Popular libraries: NumPy, Pandas, Requests, Flask, Django.
- Practice platforms: LeetCode, HackerRank, Codewars.

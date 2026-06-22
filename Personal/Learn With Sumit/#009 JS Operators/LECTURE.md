# JavaScript Operators

## Overview

**Operators** in JavaScript are special symbols that perform operations on operands (values and variables). They are the building blocks of expressions, allowing you to manipulate data, compare values, perform calculations, and control program flow. From simple arithmetic to complex logical operations, operators are essential for writing functional JavaScript code.

### Why Operators are Important 🔧
- **Data Manipulation**: Perform calculations, string concatenation, and transformations
- **Decision Making**: Compare values and create conditional logic
- **Assignments**: Store and update values in variables
- **Type Checking**: Understand and convert data types
- **Bitwise Operations**: Work at the binary level for performance-critical code
- **Unary Operations**: Work with single operands for increment/decrement and negation

## Key Concepts

### Classification of Operators

#### By Number of Operands
- **Unary Operators**: Work with one operand (`typeof`, `!`, `++`, `--`)
- **Binary Operators**: Work with two operands (`+`, `-`, `*`, `&&`, `||`)
- **Ternary Operator**: Works with three operands (`condition ? expr1 : expr2`)

#### By Function
- **Arithmetic Operators**: Mathematical calculations
- **Assignment Operators**: Assign and update values
- **Comparison Operators**: Compare values and return boolean
- **Logical Operators**: Combine boolean conditions
- **String Operators**: Concatenate and manipulate strings
- **Type Operators**: Check and convert data types
- **Bitwise Operators**: Operate on binary representations

## Syntax

### Operator Precedence Table
Operators have different precedence levels (higher = evaluated first):

| Precedence | Operator Type | Operators |
|------------|---------------|-----------|
| 20 | Grouping | `( )` |
| 19 | Member Access | `.`, `[]`, `?.` |
| 18 | Function Call | `()` |
| 17 | New | `new` |
| 16 | Postfix | `++`, `--` |
| 15 | Logical NOT, Unary | `!`, `+`, `-`, `++`, `--`, `typeof`, `void` |
| 14 | Multiplicative | `*`, `/`, `%` |
| 13 | Additive | `+`, `-` |
| 12 | Shift | `<<`, `>>`, `>>>` |
| 11 | Relational | `<`, `>`, `<=`, `>=`, `instanceof` |
| 10 | Equality | `==`, `!=`, `===`, `!==` |
| 9 | Bitwise AND | `&` |
| 8 | Bitwise XOR | `^` |
| 7 | Bitwise OR | `\|` |
| 6 | Logical AND | `&&` |
| 5 | Logical OR | `\|\|`, `??` |
| 4 | Conditional (Ternary) | `? :` |
| 3 | Assignment | `=`, `+=`, `-=`, etc. |
| 2 | Yield | `yield` |
| 1 | Comma | `,` |

## Examples

### Example 1: Arithmetic Operators
```javascript
// Arithmetic operators
let x = 10;
let y = 3;

console.log("Addition:", x + y);        // 13
console.log("Subtraction:", x - y);     // 7
console.log("Multiplication:", x * y);  // 30
console.log("Division:", x / y);        // 3.333...
console.log("Modulus (Remainder):", x % y); // 1
console.log("Exponentiation:", x ** y); // 1000

// Increment and Decrement
let count = 5;
console.log("Post-increment:", count++); // 5 (returns then increments)
console.log("After post-increment:", count); // 6
console.log("Pre-increment:", ++count); // 7 (increments then returns)
console.log("Post-decrement:", count--); // 7
console.log("Pre-decrement:", --count); // 5

// Unary plus and minus
let num = "5";
console.log("String to Number:", +num); // 5
console.log("Negation:", -num); // -5

// NaN operations
console.log("Invalid math:", 10 / "hello"); // NaN
console.log("Is NaN?", isNaN(10 / "hello")); // true
```

**Output:**
```
Addition: 13
Subtraction: 7
Multiplication: 30
Division: 3.3333333333333335
Modulus (Remainder): 1
Exponentiation: 1000
Post-increment: 5
After post-increment: 6
Pre-increment: 7
Post-decrement: 7
Pre-decrement: 5
String to Number: 5
Negation: -5
Invalid math: NaN
Is NaN? true
```

### Example 2: Assignment Operators
```javascript
// Basic assignment
let value = 10;
console.log("Initial:", value); // 10

// Compound assignments
value += 5;  // value = value + 5
console.log("+= 5:", value); // 15

value -= 3;  // value = value - 3
console.log("-= 3:", value); // 12

value *= 2;  // value = value * 2
console.log("*= 2:", value); // 24

value /= 4;  // value = value / 4
console.log("/= 4:", value); // 6

value %= 5;  // value = value % 5
console.log("%= 5:", value); // 1

value **= 3; // value = value ** 3
console.log("**= 3:", value); // 1

// Logical assignments
let user = null;
user ||= "Guest"; // If user is null/undefined, assign "Guest"
console.log("user ||=:", user); // Guest

let settings = { theme: "dark" };
settings.theme &&= "light"; // If theme exists, assign "light"
console.log("settings:", settings); // { theme: "light" }

let count2 = 0;
count2 ??= 10; // If count2 is null/undefined, assign 10
console.log("count2 ??=:", count2); // 0 (not nullish)

// Destructuring assignment
const [a, b, ...rest] = [1, 2, 3, 4, 5];
console.log("Destructuring:", a, b, rest); // 1, 2, [3, 4, 5]

const { name, age } = { name: "Alice", age: 30, city: "NYC" };
console.log("Object destructuring:", name, age); // Alice, 30
```

**Output:**
```
Initial: 10
+= 5: 15
-= 3: 12
*= 2: 24
/= 4: 6
%= 5: 1
**= 3: 1
user ||=: Guest
settings: { theme: 'light' }
count2 ??=: 0
Destructuring: 1 2 [3, 4, 5]
Object destructuring: Alice 30
```

### Example 3: Comparison Operators
```javascript
// Strict vs. Loose equality
console.log("2 == '2':", 2 == '2');   // true (loose - type conversion)
console.log("2 === '2':", 2 === '2'); // false (strict - different types)
console.log("0 == false:", 0 == false); // true
console.log("0 === false:", 0 === false); // false
console.log("null == undefined:", null == undefined); // true
console.log("null === undefined:", null === undefined); // false

// Comparison with coercion
console.log("'10' > 5:", '10' > 5);   // true (string converted to number)
console.log("'abc' > 5:", 'abc' > 5); // false (NaN comparison)
console.log("'abc' < 'def':", 'abc' < 'def'); // true (lexicographic)

// Strict comparison examples
const obj1 = { name: "John" };
const obj2 = { name: "John" };
const obj3 = obj1;

console.log("obj1 == obj2:", obj1 == obj2);   // false (different references)
console.log("obj1 === obj2:", obj1 === obj2); // false
console.log("obj1 === obj3:", obj1 === obj3); // true (same reference)

// Relational operators
console.log("5 < 10:", 5 < 10);   // true
console.log("5 <= 5:", 5 <= 5);   // true
console.log("10 > 20:", 10 > 20); // false
console.log("10 >= 20:", 10 >= 20); // false

// Special cases with NaN
console.log("NaN == NaN:", NaN == NaN);   // false
console.log("NaN === NaN:", NaN === NaN); // false
console.log("Number.isNaN(NaN):", Number.isNaN(NaN)); // true

// Object.is (ES6) - SameValueZero equality
console.log("Object.is(NaN, NaN):", Object.is(NaN, NaN)); // true
console.log("Object.is(-0, +0):", Object.is(-0, +0)); // false
```

**Output:**
```
2 == '2': true
2 === '2': false
0 == false: true
0 === false: false
null == undefined: true
null === undefined: false
'10' > 5: true
'abc' > 5: false
'abc' < 'def': true
obj1 == obj2: false
obj1 === obj2: false
obj1 === obj3: true
5 < 10: true
5 <= 5: true
10 > 20: false
10 >= 20: false
NaN == NaN: false
NaN === NaN: false
Number.isNaN(NaN): true
Object.is(NaN, NaN): true
Object.is(-0, +0): false
```

### Example 4: Logical Operators
```javascript
// Logical AND (&&) - returns first falsy or last truthy
console.log("true && true:", true && true);   // true
console.log("true && false:", true && false); // false
console.log("false && true:", false && true); // false
console.log("false && false:", false && false); // false

// Short-circuit evaluation - AND
const user2 = { name: "Alice", isAdmin: true };
console.log("user2 && user2.name:", user2 && user2.name); // Alice
const nullUser = null;
console.log("nullUser && nullUser.name:", nullUser && nullUser.name); // null

// Logical OR (||) - returns first truthy or last falsy
console.log("true || true:", true || true);   // true
console.log("true || false:", true || false); // true
console.log("false || true:", false || true); // true
console.log("false || false:", false || false); // false

// Short-circuit evaluation - OR
const name1 = "";
const defaultName = "Guest";
console.log("name1 || defaultName:", name1 || defaultName); // Guest

// Nullish Coalescing (??) - only checks null/undefined
const val1 = null;
const val2 = undefined;
const val3 = 0;
const val4 = false;
const val5 = "";
console.log("null ?? 'default':", val1 ?? "default"); // default
console.log("undefined ?? 'default':", val2 ?? "default"); // default
console.log("0 ?? 'default':", val3 ?? "default"); // 0 (not nullish)
console.log("false ?? 'default':", val4 ?? "default"); // false
console.log("'' ?? 'default':", val5 ?? "default"); // ""

// Logical NOT (!)
console.log("!true:", !true);   // false
console.log("!false:", !false); // true
console.log("!0:", !0);         // true
console.log("!''", !'');       // true
console.log("!!'hello':", !!'hello'); // true (double NOT - convert to boolean)

// Complex logical expressions
const age2 = 25;
const hasLicense = true;
const canDrive = age2 >= 18 && hasLicense;
console.log("Can drive:", canDrive); // true

const isWeekend = true;
const isHoliday = false;
const canSleepIn = isWeekend || isHoliday;
console.log("Can sleep in:", canSleepIn); // true
```

**Output:**
```
true && true: true
true && false: false
false && true: false
false && false: false
user2 && user2.name: Alice
nullUser && nullUser.name: null
true || true: true
true || false: true
false || true: true
false || false: false
name1 || defaultName: Guest
null ?? 'default': default
undefined ?? 'default': default
0 ?? 'default': 0
false ?? 'default': false
'' ?? 'default': 
!true: false
!false: true
!0: true
!'' true
!!'hello': true
Can drive: true
Can sleep in: true
```

### Example 5: Ternary and Type Operators
```javascript
// Ternary operator (conditional operator)
const age3 = 20;
const status = age3 >= 18 ? "Adult" : "Minor";
console.log("Age status:", status); // Adult

// Nested ternary
const score = 85;
const grade = score >= 90 ? "A" :
              score >= 80 ? "B" :
              score >= 70 ? "C" :
              score >= 60 ? "D" : "F";
console.log("Grade:", grade); // B

// typeof operator
console.log("typeof 42:", typeof 42);           // "number"
console.log("typeof 'hello':", typeof "hello"); // "string"
console.log("typeof true:", typeof true);       // "boolean"
console.log("typeof undefined:", typeof undefined); // "undefined"
console.log("typeof null:", typeof null);       // "object" (historical bug)
console.log("typeof [1,2]:", typeof [1,2]);     // "object"
console.log("typeof {a:1}:", typeof {a:1});     // "object"
console.log("typeof function(){}:", typeof function(){}); // "function"
console.log("typeof Symbol():", typeof Symbol()); // "symbol"
console.log("typeof BigInt(1):", typeof BigInt(1)); // "bigint"

// instanceof operator
class Animal {}
class Dog extends Animal {}

const dog = new Dog();
console.log("dog instanceof Dog:", dog instanceof Dog); // true
console.log("dog instanceof Animal:", dog instanceof Animal); // true
console.log("dog instanceof Object:", dog instanceof Object); // true

// [] instanceof Array
console.log("[] instanceof Array:", [] instanceof Array); // true
console.log("[] instanceof Object:", [] instanceof Object); // true

// in operator
const car = { brand: "Toyota", year: 2020 };
console.log("'brand' in car:", "brand" in car); // true
console.log("'model' in car:", "model" in car); // false
console.log("'toString' in car:", "toString" in car); // true (inherited)
```

**Output:**
```
Age status: Adult
Grade: B
typeof 42: number
typeof 'hello': string
typeof true: boolean
typeof undefined: undefined
typeof null: object
typeof [1,2]: object
typeof {a:1}: object
typeof function(){}: function
typeof Symbol(): symbol
typeof BigInt(1): bigint
dog instanceof Dog: true
dog instanceof Animal: true
dog instanceof Object: true
[] instanceof Array: true
[] instanceof Object: true
'brand' in car: true
'model' in car: false
'toString' in car: true
```

### Example 6: Bitwise Operators
```javascript
// Bitwise AND (&)
console.log("5 & 3:", 5 & 3); // 1 (0101 & 0011 = 0001)
// 5 = 0101, 3 = 0011, result = 0001 = 1

// Bitwise OR (|)
console.log("5 | 3:", 5 | 3); // 7 (0101 | 0011 = 0111)

// Bitwise XOR (^)
console.log("5 ^ 3:", 5 ^ 3); // 6 (0101 ^ 0011 = 0110)

// Bitwise NOT (~)
console.log("~5:", ~5); // -6 (inverts bits, 2's complement)
// 5 = 0101, ~5 = 1010 (in binary) = -6 in decimal

// Left shift (<<)
console.log("5 << 1:", 5 << 1); // 10 (0101 << 1 = 1010 = 10)
console.log("5 << 2:", 5 << 2); // 20 (0101 << 2 = 10100 = 20)

// Right shift (>>)
console.log("10 >> 1:", 10 >> 1); // 5 (1010 >> 1 = 0101 = 5)
console.log("-10 >> 1:", -10 >> 1); // -5 (sign preserved)

// Unsigned right shift (>>>)
console.log("10 >>> 1:", 10 >>> 1); // 5
console.log("-10 >>> 1:", -10 >>> 1); // 2147483643 (no sign preservation)

// Practical use: checking even/odd with bitwise AND
const num2 = 7;
console.log(`${num2} is even:`, (num2 & 1) === 0); // false
const num3 = 8;
console.log(`${num3} is even:`, (num3 & 1) === 0); // true

// Practical use: flags
const FLAG_A = 1;  // 001
const FLAG_B = 2;  // 010
const FLAG_C = 4;  // 100

let flags = FLAG_A | FLAG_B; // 011 (has A and B)
console.log("Has flag A:", (flags & FLAG_A) !== 0); // true
console.log("Has flag C:", (flags & FLAG_C) !== 0); // false

// Add flag C
flags |= FLAG_C; // 111
console.log("Has flag C now:", (flags & FLAG_C) !== 0); // true

// Remove flag B
flags &= ~FLAG_B; // 101
console.log("Has flag B now:", (flags & FLAG_B) !== 0); // false
```

**Output:**
```
5 & 3: 1
5 | 3: 7
5 ^ 3: 6
~5: -6
5 << 1: 10
5 << 2: 20
10 >> 1: 5
-10 >> 1: -5
10 >>> 1: 5
-10 >>> 1: 2147483643
7 is even: false
8 is even: true
Has flag A: true
Has flag C: false
Has flag C now: true
Has flag B now: false
```

## Explanation of Examples

### Example 1: Arithmetic Operators
- **Basic Arithmetic**: `+`, `-`, `*`, `/` perform standard mathematical operations
- **Modulus (`%`)**: Returns the remainder after division (useful for checking even/odd)
- **Exponentiation (`**`)**: Raised to the power of (e.g., `2 ** 3 = 8`)
- **Increment/Decrement**: Post-increment returns value then increments; pre-increment increments then returns
- **Unary Plus/Minus**: Converts strings to numbers and negates values
- **NaN (Not-a-Number)**: Results from invalid mathematical operations

### Example 2: Assignment Operators
- **Basic Assignment (`=`)**: Assigns value to variable
- **Compound Assignment**: Shorthand for applying an operation and assignment
- **Logical Assignment**: `||=`, `&&=`, `??=` assign based on logical conditions
- **Destructuring**: Extracts values from arrays/objects into variables
- **`??=` (Nullish Coalescing Assignment)**: Only assigns if value is null/undefined

### Example 3: Comparison Operators
- **Loose Equality (`==`)**: Compares values after type conversion (use with caution)
- **Strict Equality (`===`)**: Compares both value and type (preferred)
- **Relational Operators**: Compare numeric and string values
- **Object Comparison**: Compares references, not content
- **`Object.is()`**: More strict equality (handles `NaN` and `-0` specially)
- **`Number.isNaN()`**: Reliably checks for `NaN`

### Example 4: Logical Operators
- **AND (`&&`)**: Returns first falsy or last truthy value
- **OR (`||`)**: Returns first truthy or last falsy value
- **Nullish Coalescing (`??`)**: Returns right operand only if left is `null` or `undefined`
- **NOT (`!`)**: Converts to boolean and negates
- **Short-Circuiting**: Evaluation stops as soon as result is determined
- **Truthy/Falsy Values**: Understanding what JavaScript considers truthy/falsy is crucial

### Example 5: Ternary and Type Operators
- **Ternary (`? :`)**: Conditional operator for inline if-else
- **`typeof`**: Returns the type of a value as a string
- **`instanceof`**: Checks if an object is an instance of a constructor
- **`in`**: Checks if a property exists in an object or its prototype chain

### Example 6: Bitwise Operators
- **Bitwise AND/OR/XOR**: Operate on binary representations
- **Bitwise NOT**: Inverts bits (2's complement)
- **Shift Operators**: Move bits left or right
- **Practical Uses**: Flag management, performance optimization, low-level operations
- **Unsigned Right Shift (`>>>`)**: Shifts with zero fill (no sign preservation)

## Important Notes

### Best Practices 📝
1. **Use `===` and `!==`**: Always use strict equality to avoid type coercion bugs
2. **Prefer `??` over `||`**: For default values, use nullish coalescing to avoid issues with falsy values like `0`, `false`, `""`
3. **Use Parentheses**: Make operator precedence explicit for readability
4. **Avoid `var`**: Use `const` and `let` (only `let` when reassignment is needed)
5. **Use Short-Circuiting**: Write elegant code with `&&` and `||` for conditional execution
6. **Leverage Destructuring**: Cleaner variable assignments from objects/arrays

### Things to Remember 💡
- `NaN` is not equal to anything, including itself (`NaN === NaN` is `false`)
- `null == undefined` is `true`, but `null === undefined` is `false`
- `+` operator does both addition and string concatenation
- Operator precedence determines order of evaluation
- `&&` and `||` return the actual value, not just `true`/`false`
- Bitwise operators convert operands to 32-bit signed integers
- `typeof null` returns `"object"` (historical bug in JavaScript)
- `++` and `--` can be prefix or postfix with different behaviors

### Operator Precedence Example
```javascript
let result = 2 + 3 * 4; // Multiplication happens first
console.log(result); // 14 (not 20)

// Make it explicit with parentheses
result = (2 + 3) * 4; // Addition first
console.log(result); // 20
```

## Common Mistakes

### Mistake 1: Using `==` Instead of `===`
```javascript
// ❌ Bad - unexpected type coercion
if (0 == false) { // true
    console.log("This executes!");
}

if (null == undefined) { // true
    console.log("This also executes!");
}

// ✅ Good - strict equality
if (0 === false) { // false
    console.log("This won't execute!");
}

if (null === undefined) { // false
    console.log("This won't execute!");
}
```

### Mistake 2: Confusing Assignment and Comparison
```javascript
// ❌ Bad - accidental assignment
let x = 5;
if (x = 10) { // assigns 10 to x, condition is true
    console.log("Oops! x is now", x); // x is 10
}

// ✅ Good - use === for comparison
if (x === 10) {
    console.log("x is 10");
}
```

### Mistake 3: Misunderstanding `||` and `??`
```javascript
// ❌ Bad - using || for default values with falsy valid values
const count = 0;
const defaultCount = count || 10; // 10 (not 0)
console.log(defaultCount); // 10

// ✅ Good - using ?? for nullish coalescing
const defaultCount2 = count ?? 10; // 0 (only null/undefined trigger default)
console.log(defaultCount2); // 0
```

### Mistake 4: Forgetting Operator Precedence
```javascript
// ❌ Bad - relying on implicit precedence
const result1 = 5 + 3 * 2; // 11 (3*2 = 6, then 5+6 = 11)
console.log(result1);

// ✅ Good - use parentheses for clarity
const result2 = (5 + 3) * 2; // 16
console.log(result2);
```

### Mistake 5: Using `++` in Complex Expressions
```javascript
// ❌ Bad - confusion with pre/post increment
let i = 1;
let j = i++ + ++i; // 1 + 3 = 4 (confusing!)
console.log(i, j); // 3, 4

// ✅ Good - keep it simple and separate
let a = 1;
let b = a++;
let c = ++a;
let sum = b + c; // 1 + 3 = 4
console.log(a, sum); // 3, 4
```

### Mistake 6: Comparing Objects
```javascript
// ❌ Bad - comparing objects by reference
const obj1 = { value: 10 };
const obj2 = { value: 10 };
if (obj1 === obj2) { // false
    console.log("Objects are equal");
}

// ✅ Good - compare properties
if (obj1.value === obj2.value) {
    console.log("Objects have same value");
}

// ✅ Or use JSON.stringify (for shallow comparison)
if (JSON.stringify(obj1) === JSON.stringify(obj2)) {
    console.log("Objects are equal");
}
```

## Interview Questions

1. **What's the difference between `==` and `===` in JavaScript?**  
   *Answer: `==` performs type coercion before comparison, while `===` compares both value and type without coercion. `===` is preferred to avoid unexpected results from implicit type conversion.*

2. **What is short-circuit evaluation in logical operators?**  
   *Answer: Short-circuiting means the second operand is evaluated only if necessary. For `&&`, if the first operand is falsy, the second is not evaluated. For `||`, if the first operand is truthy, the second is not evaluated.*

3. **What's the difference between `||` and `??` (nullish coalescing)?**  
   *Answer: `||` returns the right operand if the left is falsy (including `0`, `false`, `""`, `null`, `undefined`). `??` only returns the right operand if the left is `null` or `undefined`, making it safer for default values that could be falsy.*

4. **Explain the ternary operator and its use cases.**  
   *Answer: The ternary operator (`condition ? expr1 : expr2`) is a concise way to write if-else statements in expressions. It returns `expr1` if the condition is truthy, otherwise `expr2`. Use it for simple conditional assignments, not complex logic.*

5. **What are truthy and falsy values in JavaScript?**  
   *Answer: Falsy values evaluate to `false` in boolean context: `false`, `0`, `""` (empty string), `null`, `undefined`, `NaN`. All other values are truthy including `"0"`, `"false"`, empty objects, and empty arrays.*

6. **How does the `+` operator work with different types?**  
   *Answer: The `+` operator is overloaded. If either operand is a string, it performs string concatenation; otherwise, it performs numeric addition. For other combinations, it converts to strings or numbers based on JavaScript's coercion rules.*

7. **What is operator precedence and why is it important?**  
   *Answer: Operator precedence determines the order in which operators are evaluated. Understanding it is crucial for writing correct expressions. When in doubt, use parentheses to make the intended order explicit.*

8. **Explain the difference between `++i` and `i++`.**  
   *Answer: `++i` (pre-increment) increments `i` then returns the new value. `i++` (post-increment) returns the current value then increments `i`. Example: if `i=5`, `j=++i` gives `j=6, i=6`; `j=i++` gives `j=5, i=6`.*

9. **When would you use bitwise operators in JavaScript?**  
   *Answer: Bitwise operators are used for low-level operations like flag management, optimization for performance-critical code, cryptography, and working with binary data. They're rarely needed in everyday web development but are useful for certain domains.*

10. **What is the `in` operator used for?**  
    *Answer: The `in` operator checks if a property exists in an object or its prototype chain. It returns `true` if the property exists, `false` otherwise. It's useful for checking if an object has a specific key before accessing it.*

## Practice Exercises

### Easy Exercise ✨
**Task**: Write a function that determines if a number is even or odd using:
1. The modulus operator
2. The bitwise AND operator
3. Explain which is more readable

<details>
<summary>Solution</summary>

```javascript
// 1. Using modulus operator
function isEvenModulus(num) {
    return num % 2 === 0;
}

// 2. Using bitwise AND
function isEvenBitwise(num) {
    return (num & 1) === 0;
}

// Test
console.log("10 is even (modulus):", isEvenModulus(10)); // true
console.log("7 is even (modulus):", isEvenModulus(7)); // false
console.log("10 is even (bitwise):", isEvenBitwise(10)); // true
console.log("7 is even (bitwise):", isEvenBitwise(7)); // false

// Readability: modulus is more readable and should be preferred
```
</details>

### Medium Exercise 📘
**Task**: Create a "smart shopping cart" system that:
1. Starts with an empty cart (array of items)
2. Adds items with name, price, and quantity
3. Calculates total with different discount tiers using ternary operators
4. Uses logical operators to validate inputs
5. Uses nullish coalescing for default values

<details>
<summary>Solution</summary>

```javascript
class ShoppingCart {
    constructor() {
        this.items = [];
        this.discount = 0;
    }

    addItem(name, price, quantity = 1) {
        // Validate inputs with logical operators
        if (!name || !price || price <= 0) {
            console.log("❌ Invalid item data");
            return false;
        }

        // Use nullish coalescing for default quantity
        quantity = quantity ?? 1;
        
        // Check if item exists (shallow comparison)
        const existing = this.items.find(item => item.name === name);
        if (existing) {
            existing.quantity += quantity;
        } else {
            this.items.push({ name, price, quantity });
        }
        
        console.log(`✅ Added ${quantity}x ${name} ($${price} each)`);
        return true;
    }

    calculateTotal() {
        const subtotal = this.items.reduce((sum, item) => 
            sum + (item.price * item.quantity), 0
        );

        // Use ternary for discount tiers
        const discountRate = subtotal >= 100 ? 0.20 :
                             subtotal >= 50 ? 0.15 :
                             subtotal >= 30 ? 0.10 : 0;
        
        const discount = subtotal * discountRate;
        const total = subtotal - discount;

        // Use logical && for conditional display
        discount > 0 && console.log(`🎉 ${(discountRate * 100)}% discount applied!`);
        discount > 0 && console.log(`💰 You saved $${discount.toFixed(2)}`);

        return {
            subtotal: subtotal.toFixed(2),
            discount: discount.toFixed(2),
            total: total.toFixed(2)
        };
    }

    displayCart() {
        console.log("\n🛒 Shopping Cart:");
        this.items.forEach(item => {
            console.log(`  - ${item.quantity}x ${item.name} @ $${item.price} = $${(item.price * item.quantity).toFixed(2)}`);
        });
        const totals = this.calculateTotal();
        console.log(`\nSubtotal: $${totals.subtotal}`);
        console.log(`Discount: -$${totals.discount}`);
        console.log(`Total: $${totals.total}`);
        console.log("─".repeat(30));
    }
}

// Testing
const cart = new ShoppingCart();
cart.addItem("Laptop", 1000, 1);
cart.addItem("Mouse", 25, 2);
cart.addItem("Keyboard", 45, 1);
cart.addItem("", 50); // Invalid - should fail
cart.displayCart();
```
</details>

### Challenge Exercise 💪
**Task**: Build a "complex expression evaluator" that:
1. Takes user input as a string (e.g., "3 + 5 * 2")
2. Parses and evaluates mathematical expressions with:
   - Basic operations: +, -, *, /, %
   - Logical operations: &&, ||, !, comparison
   - Parentheses for grouping
3. Handles operator precedence correctly
4. Returns the result or an error message

<details>
<summary>Solution</summary>

```javascript
class ExpressionEvaluator {
    constructor() {
        // Precedence: higher = evaluated first
        this.precedence = {
            '!': 6,
            '*': 5, '/': 5, '%': 5,
            '+': 4, '-': 4,
            '>': 3, '<': 3, '>=': 3, '<=': 3,
            '==': 2, '!=': 2, '===': 2, '!==': 2,
            '&&': 1,
            '||': 1
        };
    }

    evaluate(expression) {
        try {
            // Remove whitespace
            const cleaned = expression.replace(/\s/g, '');
            
            // Handle parentheses recursively
            const result = this.evaluateExpression(cleaned);
            return { success: true, result };
        } catch (error) {
            return { 
                success: false, 
                error: error.message || "Invalid expression" 
            };
        }
    }

    evaluateExpression(expr) {
        // Find innermost parentheses
        while (expr.includes('(')) {
            const lastOpen = expr.lastIndexOf('(');
            const close = expr.indexOf(')', lastOpen);
            if (close === -1) throw new Error("Unmatched parentheses");
            
            const inner = expr.substring(lastOpen + 1, close);
            const value = this.evaluateSimple(inner);
            expr = expr.substring(0, lastOpen) + value + expr.substring(close + 1);
        }
        return this.evaluateSimple(expr);
    }

    evaluateSimple(expr) {
        // Find the operator with lowest precedence
        let minPrecedence = Infinity;
        let operatorIndex = -1;
        let selectedOp = '';

        const operators = Object.keys(this.precedence);
        
        // Handle unary NOT (!)
        if (expr.startsWith('!')) {
            const value = this.evaluateSimple(expr.substring(1));
            return this.applyOperator('!', value);
        }

        // Find operator with lowest precedence (evaluated last)
        for (let i = 0; i < expr.length; i++) {
            const char = expr[i];
            
            // Check for multi-character operators
            if (i + 1 < expr.length) {
                const twoChar = expr.substring(i, i + 2);
                if (operators.includes(twoChar) && this.precedence[twoChar] <= minPrecedence) {
                    minPrecedence = this.precedence[twoChar];
                    operatorIndex = i;
                    selectedOp = twoChar;
                    i++; // Skip second character
                    continue;
                }
            }
            
            if (operators.includes(char) && this.precedence[char] <= minPrecedence) {
                minPrecedence = this.precedence[char];
                operatorIndex = i;
                selectedOp = char;
            }
        }

        if (operatorIndex === -1) {
            // No operator found - parse as number or boolean
            return this.parseValue(expr);
        }

        const left = expr.substring(0, operatorIndex);
        const right = expr.substring(operatorIndex + selectedOp.length);
        
        const leftValue = this.evaluateSimple(left);
        const rightValue = this.evaluateSimple(right);
        
        return this.applyOperator(selectedOp, leftValue, rightValue);
    }

    parseValue(value) {
        if (value === 'true') return true;
        if (value === 'false') return false;
        if (value === 'null') return null;
        if (value === 'undefined') return undefined;
        if (/^\d+$/.test(value)) return parseInt(value, 10);
        if (/^\d+\.\d+$/.test(value)) return parseFloat(value);
        if (/^'.*'$/.test(value) || /^".*"$/.test(value)) {
            return value.slice(1, -1);
        }
        throw new Error(`Cannot parse value: ${value}`);
    }

    applyOperator(op, left, right) {
        switch(op) {
            case '!': return !left;
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/': 
                if (right === 0) throw new Error("Division by zero");
                return left / right;
            case '%': return left % right;
            case '>': return left > right;
            case '<': return left < right;
            case '>=': return left >= right;
            case '<=': return left <= right;
            case '==': return left == right;
            case '!=': return left != right;
            case '===': return left === right;
            case '!==': return left !== right;
            case '&&': return left && right;
            case '||': return left || right;
            default: throw new Error(`Unknown operator: ${op}`);
        }
    }
}

// Testing
const evaluator = new ExpressionEvaluator();

console.log("Simple arithmetic:");
console.log("3 + 5 * 2 =", evaluator.evaluate("3 + 5 * 2")); // 13
console.log("(3 + 5) * 2 =", evaluator.evaluate("(3 + 5) * 2")); // 16
console.log("10 / 3 =", evaluator.evaluate("10 / 3")); // 3.333...
console.log("10 % 3 =", evaluator.evaluate("10 % 3")); // 1

console.log("\nComparisons:");
console.log("5 > 3 =", evaluator.evaluate("5 > 3")); // true
console.log("5 === '5' =", evaluator.evaluate("5 === '5'")); // false
console.log("5 == '5' =", evaluator.evaluate("5 == '5'")); // true

console.log("\nLogic:");
console.log("true && false =", evaluator.evaluate("true && false")); // false
console.log("true || false =", evaluator.evaluate("true || false")); // true
console.log("!(5 > 3) =", evaluator.evaluate("!(5 > 3)")); // false

console.log("\nComplex expressions:");
console.log("(5 + 3) * 2 === 16 =", evaluator.evaluate("(5 + 3) * 2 === 16")); // true
console.log("10 > 5 && 20 < 30 =", evaluator.evaluate("10 > 5 && 20 < 30")); // true

console.log("\nError handling:");
console.log("10 / 0 =", evaluator.evaluate("10 / 0")); // Division by zero error
console.log("2 + =", evaluator.evaluate("2 +")); // Parse error
```
</details>

## Summary

### Key Takeaways 📌

#### Arithmetic & Assignment
- `+`, `-`, `*`, `/`, `%` for basic math
- `**` for exponentiation (ES7)
- `++`/`--` for increment/decrement (prefix vs postfix)
- Compound assignments (`+=`, `-=`, etc.) for concise updates
- Logical assignments (`||=`, `&&=`, `??=`) for conditional assignment

#### Comparisons & Equality
- Always prefer `===` and `!==` over `==` and `!=`
- Relational operators (`<`, `>`, `<=`, `>=`) compare numbers and strings
- `Object.is()` for `NaN` and `-0` comparison
- `instanceof` for checking object types

#### Logical Operators
- `&&` returns first falsy or last truthy
- `||` returns first truthy or last falsy
- `??` (nullish coalescing) only checks `null`/`undefined`
- `!` negates boolean values
- Short-circuiting enables elegant conditional code

#### Special Operators
- Ternary (`? :`) for inline conditional expressions
- `typeof` for type checking
- `in` for property existence checking
- `delete` for removing object properties
- `new` for creating object instances

#### Bitwise Operators
- Operate on binary representations (32-bit signed integers)
- Useful for flags, permissions, and performance-critical code
- `&`, `|`, `^`, `~`, `<<`, `>>`, `>>>`

### Remember This Rule of Thumb 🎯
> **"When in doubt about operator precedence, use parentheses!"**

### Quick Reference Card
```
✅ Use === and !== (always!)
✅ Use ?? for default values (not ||)
✅ Use && for conditional execution
✅ Use ternary for simple conditions
✅ Use parentheses for clarity

❌ Avoid == and !=
❌ Avoid var (use const/let)
❌ Avoid complex expressions with ++/--
❌ Avoid comparing objects by reference
```

**Mastering operators is fundamental to writing efficient and bug-free JavaScript code!** 🚀
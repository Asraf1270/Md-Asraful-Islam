# JavaScript Assignment

## Overview

**Assignment** in JavaScript is the process of storing values in variables using the assignment operator (`=`). While simple assignment (`=`) is the most common, JavaScript provides a rich set of assignment operators and patterns that make code more concise, expressive, and maintainable. Assignment is fundamental to programming as it allows you to store and manipulate data throughout your application.

### Why Assignment is Important 📦
- **Data Storage**: Store values for later use in your program
- **State Management**: Track and update application state
- **Code Concision**: Compound assignments reduce code repetition
- **Immutability Control**: Understand when and how to reassign values
- **Pattern Matching**: Destructuring simplifies extracting data from complex structures
- **Readability**: Proper assignment patterns make code self-documenting

## Key Concepts

### Types of Assignment

#### 1. Simple Assignment
- **`=`**: Basic assignment operator
- Assigns the value on the right to the variable on the left

#### 2. Compound Assignment
- **Arithmetic**: `+=`, `-=`, `*=`, `/=`, `%=`, `**=`
- **Bitwise**: `&=`, `|=`, `^=`, `<<=`, `>>=`, `>>>=`
- **Logical**: `&&=`, `||=`, `??=` (ES2021)

#### 3. Destructuring Assignment
- **Array Destructuring**: Extract values from arrays
- **Object Destructuring**: Extract properties from objects
- **Nested Destructuring**: Extract deeply nested values

#### 4. Other Assignment Patterns
- **Multiple Assignment**: Assign multiple variables in one statement
- **Chained Assignment**: Assign the same value to multiple variables
- **Swapping Variables**: Exchange values between variables
- **Default Values**: Provide fallback values in destructuring

### Assignment vs Mutation
- **Assignment**: Changing what a variable references
- **Mutation**: Changing the contents of what a variable references
- Understanding this distinction is crucial, especially with `const`

## Syntax

### Basic Syntax
```javascript
// Simple assignment
variableName = value;

// Compound assignment
variableName += value;  // variableName = variableName + value

// Destructuring
const { property } = object;
const [first, second] = array;

// Multiple assignment
let a, b, c;
a = b = c = 10;
```

## Examples

### Example 1: Simple and Compound Assignment
```javascript
// Simple assignment
let score = 100;
let message = "Hello";
let isValid = true;

console.log("Initial values:", score, message, isValid);
// Output: Initial values: 100 Hello true

// Compound arithmetic assignments
let total = 50;
console.log(`\nStarting total: ${total}`);

total += 20;  // total = total + 20
console.log("After += 20:", total); // 70

total -= 15;  // total = total - 15
console.log("After -= 15:", total); // 55

total *= 3;   // total = total * 3
console.log("After *= 3:", total); // 165

total /= 5;   // total = total / 5
console.log("After /= 5:", total); // 33

total %= 10;  // total = total % 10
console.log("After %= 10:", total); // 3

total **= 4;  // total = total ** 4
console.log("After **= 4:", total); // 81

// Compound string assignment
let greeting = "Hello";
greeting += " World";
console.log("\nString concatenation:", greeting); // Hello World

// Compound with different types
let number = 10;
number += "5";  // Converts to string
console.log("Number += '5':", number); // "105"
```

**Output:**
```
Initial values: 100 Hello true

Starting total: 50
After += 20: 70
After -= 15: 55
After *= 3: 165
After /= 5: 33
After %= 10: 3
After **= 4: 81

String concatenation: Hello World
Number += '5': 105
```

### Example 2: Logical Assignment Operators (ES2021)
```javascript
// Logical OR assignment (||=)
let name = "";
name ||= "Guest"; // If name is falsy, assign "Guest"
console.log("||= with empty string:", name); // Guest

let userName = "Alice";
userName ||= "Guest"; // userName is truthy, so no assignment
console.log("||= with existing name:", userName); // Alice

// Logical AND assignment (&&=)
let settings = { theme: "dark" };
settings.theme &&= "light"; // If theme exists, assign "light"
console.log("&&= with theme:", settings); // { theme: "light" }

let user = { };
user.name &&= "John"; // name doesn't exist, no assignment
console.log("&&= with missing property:", user); // {}

// Logical AND assignment with nullish values
let count = 0;
count &&= 10; // 0 is falsy, no assignment
console.log("&&= with 0:", count); // 0

// Nullish coalescing assignment (??=)
let value1 = null;
value1 ??= "default";
console.log("??= with null:", value1); // default

let value2 = undefined;
value2 ??= "default";
console.log("??= with undefined:", value2); // default

let value3 = 0;
value3 ??= "default"; // 0 is not nullish
console.log("??= with 0:", value3); // 0

let value4 = false;
value4 ??= "default"; // false is not nullish
console.log("??= with false:", value4); // false

// Practical example: Configuration defaults
const config = {
    timeout: null,
    retries: 0,
    debug: false
};

config.timeout ??= 5000; // Assigns 5000 (was null)
config.retries ??= 3;    // Keeps 0 (not nullish)
config.debug ??= true;   // Keeps false (not nullish)

console.log("\nConfig after ??=:", config);
// { timeout: 5000, retries: 0, debug: false }
```

**Output:**
```
||= with empty string: Guest
||= with existing name: Alice
&&= with theme: { theme: 'light' }
&&= with missing property: {}
&&= with 0: 0
??= with null: default
??= with undefined: default
??= with 0: 0
??= with false: false

Config after ??=: { timeout: 5000, retries: 0, debug: false }
```

### Example 3: Array Destructuring Assignment
```javascript
// Basic array destructuring
const colors = ["red", "green", "blue", "yellow", "purple"];

// Destructure first two elements
const [first, second] = colors;
console.log("First:", first); // red
console.log("Second:", second); // green

// Destructure with rest operator
const [primary, secondary, ...others] = colors;
console.log("\nPrimary:", primary); // red
console.log("Secondary:", secondary); // green
console.log("Others:", others); // ["blue", "yellow", "purple"]

// Skipping elements
const [one, , three] = colors;
console.log("\nOne:", one); // red
console.log("Three:", three); // blue

// Default values
const [a, b, c, d, e, f = "unknown"] = colors;
console.log("\nF (with default):", f); // unknown (color doesn't exist)

// Swapping variables
let x = 10;
let y = 20;
console.log("\nBefore swap: x=", x, "y=", y); // x=10 y=20

[x, y] = [y, x];
console.log("After swap: x=", x, "y=", y); // x=20 y=10

// Nested array destructuring
const matrix = [
    [1, 2],
    [3, 4]
];
const [[row1col1, row1col2], [row2col1, row2col2]] = matrix;
console.log("\nNested destructuring:");
console.log("Row 1:", row1col1, row1col2); // 1 2
console.log("Row 2:", row2col1, row2col2); // 3 4

// Destructuring in function parameters
function getSum([a, b]) {
    return a + b;
}
const pair = [5, 7];
console.log("\nSum of [5,7]:", getSum(pair)); // 12

// Parsing return values
function getCoordinates() {
    return [10, 20, 30];
}
const [lat, lon] = getCoordinates();
console.log("\nLatitude:", lat); // 10
console.log("Longitude:", lon); // 20
```

**Output:**
```
First: red
Second: green

Primary: red
Secondary: green
Others: [ 'blue', 'yellow', 'purple' ]

One: red
Three: blue

F (with default): unknown

Before swap: x= 10 y= 20
After swap: x= 20 y= 10

Nested destructuring:
Row 1: 1 2
Row 2: 3 4

Sum of [5,7]: 12

Latitude: 10
Longitude: 20
```

### Example 4: Object Destructuring Assignment
```javascript
// Basic object destructuring
const user = {
    id: 1,
    name: "John Doe",
    email: "john@example.com",
    age: 30,
    address: {
        street: "123 Main St",
        city: "New York",
        country: "USA"
    }
};

// Destructure specific properties
const { name, email } = user;
console.log("Name:", name); // John Doe
console.log("Email:", email); // john@example.com

// Destructure with different variable names
const { name: fullName, age: years } = user;
console.log("\nFull name:", fullName); // John Doe
console.log("Years:", years); // 30

// Default values
const { phone = "N/A", city = "Unknown" } = user;
console.log("\nPhone (default):", phone); // N/A

// Nested object destructuring
const { address: { street, city: userCity } } = user;
console.log("\nNested destructuring:");
console.log("Street:", street); // 123 Main St
console.log("City:", userCity); // New York

// Destructuring with rest operator
const { id, ...rest } = user;
console.log("\nID:", id); // 1
console.log("Rest:", rest); // { name: 'John Doe', email: 'john@example.com', age: 30, address: {...} }

// Destructuring in function parameters
function displayUser({ name, age, email }) {
    console.log(`\nUser: ${name} (${age})`);
    console.log(`Email: ${email}`);
}

displayUser(user);
// Output: User: John Doe (30)
//         Email: john@example.com

// Destructuring with computed property names
const key = "name";
const { [key]: userName } = user;
console.log("\nComputed property:", userName); // John Doe

// Destructuring existing variables
let firstName = "Alice";
let age2 = 25;
const person = { firstName: "Bob", age: 30 };

// If we use const/let, we create new variables
const { firstName: newName, age: newAge } = person;
console.log("\nNew variables:", newName, newAge); // Bob 30

// To reassign existing variables without new declarations
({ firstName, age: age2 } = person);
console.log("Reassigned existing variables:", firstName, age2); // Bob 30
```

**Output:**
```
Name: John Doe
Email: john@example.com

Full name: John Doe
Years: 30

Phone (default): N/A

Nested destructuring:
Street: 123 Main St
City: New York

ID: 1
Rest: { name: 'John Doe', email: 'john@example.com', age: 30, address: { street: '123 Main St', city: 'New York', country: 'USA' } }

User: John Doe (30)
Email: john@example.com

Computed property: John Doe

New variables: Bob 30
Reassigned existing variables: Bob 30
```

### Example 5: Multiple and Chained Assignment
```javascript
// Multiple assignment in one line
let a, b, c;
a = b = c = 10;
console.log("Chained assignment:", a, b, c); // 10 10 10

// Multiple variables with destructuring
const [firstColor, secondColor, thirdColor] = ["red", "green", "blue"];
console.log("Colors:", firstColor, secondColor, thirdColor); // red green blue

// Multiple assignment from object
const { price, quantity } = { price: 100, quantity: 5 };
console.log("Product:", price, quantity); // 100 5

// Multiple assignment with mixed sources
let p = 1, q = 2, r = 3;
[p, q] = [q, r]; // p=2, q=3, r remains 3
console.log("After swap-like assignment:", p, q, r); // 2 3 3

// Chained assignment with different types
let x1, y1, z1;
x1 = y1 = z1 = 5 + 3 * 2; // All get 11 (due to precedence)
console.log("Chained with expression:", x1, y1, z1); // 11 11 11

// Chained assignment with objects (same reference)
const obj1 = { value: 1 };
const obj2 = {};
const obj3 = {};
obj2.data = obj3.data = obj1;
obj3.data.value = 42;
console.log("\nChained object assignment:");
console.log("obj1:", obj1); // { value: 42 }
console.log("obj2.data:", obj2.data); // { value: 42 }
console.log("obj3.data:", obj3.data); // { value: 42 }

// Multiple assignment with function returns
function getValues() {
    return ["A", "B", "C"];
}
const [val1, val2, val3] = getValues();
console.log("\nFrom function:", val1, val2, val3); // A B C

// Multiple variable declaration with const and let mixed
const PI = 3.14159;
let radius = 5;
const area = PI * radius ** 2;
console.log(`\nCircle with radius ${radius}: area = ${area}`); // 78.53975
```

**Output:**
```
Chained assignment: 10 10 10
Colors: red green blue
Product: 100 5
After swap-like assignment: 2 3 3
Chained with expression: 11 11 11

Chained object assignment:
obj1: { value: 42 }
obj2.data: { value: 42 }
obj3.data: { value: 42 }

From function: A B C

Circle with radius 5: area = 78.53975
```

### Example 6: Advanced Assignment Patterns
```javascript
// Assigning to deeply nested properties
const state = {
    user: {
        profile: {
            settings: {
                theme: "light"
            }
        }
    }
};

// Safe assignment with optional chaining
state.user?.profile?.settings?.theme = "dark";
console.log("Updated nested property:", state);
// { user: { profile: { settings: { theme: 'dark' } } } }

// Using assignment with logical operators
let score = 85;
score = score > 90 ? "A" : score > 80 ? "B" : "C";
console.log("\nGrade:", score); // B

// Assignment with increment/decrement
let counter = 0;
const incrementCounter = () => ++counter; // Pre-increment
const getCounter = () => counter;

console.log("Counter:", getCounter()); // 0
console.log("Increment:", incrementCounter()); // 1
console.log("Counter:", getCounter()); // 1

// Assigning through methods
class BankAccount {
    constructor(initialBalance) {
        this._balance = initialBalance;
    }
    
    deposit(amount) {
        this._balance += amount;
        return this;
    }
    
    withdraw(amount) {
        if (this._balance >= amount) {
            this._balance -= amount;
        }
        return this;
    }
    
    get balance() {
        return this._balance;
    }
}

// Method chaining (fluent interface)
const account = new BankAccount(100);
account.deposit(50).withdraw(30).deposit(20);
console.log("\nAccount balance:", account.balance); // 140

// Assignment with spread operator (creates new object)
const defaults = { theme: "light", language: "en" };
const preferences = { theme: "dark", notifications: true };
const merged = { ...defaults, ...preferences };
console.log("\nMerged with spread:", merged);
// { theme: 'dark', language: 'en', notifications: true }

// Assignment with Object.assign
const copied = Object.assign({}, defaults, preferences);
console.log("Copied with Object.assign:", copied);
// { theme: 'dark', language: 'en', notifications: true }

// Assignment with array methods
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.map(n => n * 2);
console.log("\nDoubled array:", doubled); // [2, 4, 6, 8, 10]

// Destructuring with default values and renaming
const product = { name: "Laptop", price: 999 };
const { name: productName, price: productPrice, category = "Electronics" } = product;
console.log("\nProduct details:", productName, productPrice, category);
// Laptop 999 Electronics
```

**Output:**
```
Updated nested property: { user: { profile: { settings: { theme: 'dark' } } } }

Grade: B
Counter: 0
Increment: 1
Counter: 1

Account balance: 140

Merged with spread: { theme: 'dark', language: 'en', notifications: true }
Copied with Object.assign: { theme: 'dark', language: 'en', notifications: true }

Doubled array: [2, 4, 6, 8, 10]

Product details: Laptop 999 Electronics
```

## Explanation of Examples

### Example 1: Simple and Compound Assignment
- **Simple Assignment (`=`)**: Directly assigns a value to a variable
- **Compound Arithmetic**: Each operator is shorthand for a mathematical operation
- **String Concatenation with `+=`**: Appends strings efficiently
- **Type Coercion**: When mixing types, JavaScript converts types as needed
- **Order of Operations**: Compound assignments preserve normal operator precedence

### Example 2: Logical Assignment Operators
- **`||=` (OR Assignment)**: Assigns if left operand is falsy (except nullish)
- **`&&=` (AND Assignment)**: Assigns if left operand is truthy
- **`??=` (Nullish Coalescing Assignment)**: Assigns only if left is `null` or `undefined`
- **Safety**: `??=` is safer than `||=` for falsy values like `0` and `false`
- **Real-world Use**: Configuration defaults and state initialization

### Example 3: Array Destructuring
- **Pattern Matching**: Extract elements based on position
- **Rest Operator (`...`)**: Captures remaining elements
- **Skipping**: Use commas to skip elements
- **Default Values**: Provide fallbacks for missing elements
- **Swap**: Elegant variable swapping without temporary variables
- **Nested Arrays**: Destructure multi-dimensional arrays
- **Function Returns**: Easily parse multiple return values

### Example 4: Object Destructuring
- **Property Matching**: Extract by property name
- **Renaming**: Use `property: newName` syntax
- **Default Values**: Provide fallbacks for missing properties
- **Nested Objects**: Extract deeply nested properties
- **Rest Operator**: Collect remaining properties
- **Function Parameters**: Destructure objects directly in parameter lists
- **Computed Property Names**: Use dynamic keys in destructuring

### Example 5: Multiple and Chained Assignment
- **Chained Assignment**: All variables reference the same value
- **Primitive vs Reference**: For objects, all reference the same object
- **Multiple Variables**: Declare and assign multiple variables
- **Function Returns**: Destructure returned arrays/objects
- **Mixed Types**: Combine `const` and `let` in assignments

### Example 6: Advanced Assignment Patterns
- **Nested Property Assignment**: Update deeply nested objects
- **Ternary Assignment**: Conditional assignment in one line
- **Method Chaining**: Return `this` for fluent interfaces
- **Spread Operator**: Create new objects/arrays from existing ones
- **`Object.assign()`**: Alternative to spread for merging
- **Array Methods**: Assignment through transformations

## Important Notes

### Best Practices 📝
1. **Use `const` by Default**: Only use `let` when reassignment is needed
2. **Prefer `??=` over `||=`**: Safer for falsy values
3. **Destructuring for Clarity**: Use it to extract only what you need
4. **Avoid Chained Assignment with Objects**: Can create unintended shared references
5. **Initialize Variables**: Always initialize before use to avoid bugs
6. **Use Descriptive Names**: Make variable names self-documenting
7. **Method Chaining**: Return `this` for readable fluent interfaces

### Things to Remember 💡
- Assignment with `const` is permanent (cannot reassign)
- Objects and arrays assigned with `const` can still be mutated
- Compound assignments evaluate the right side once
- Destructuring creates new variables (doesn't mutate source)
- Chained assignment for primitives creates independent values
- Chained assignment for objects creates shared references
- `??=` only assigns for `null` and `undefined`, not all falsy values

### Assignment Safety Checklist ✅
```
□ Is the variable declared with appropriate keyword (const/let)?
□ Am I reassigning a const variable?
□ For objects, am I mutating or reassigning?
□ Am I using the correct compound operator?
□ Are my default values with ?? safe for falsy values?
□ Are my destructuring patterns correctly matching the data structure?
```

## Common Mistakes

### Mistake 1: Confusing Assignment and Comparison
```javascript
// ❌ Bad - using = instead of ===
if (x = 5) {  // Assigns 5 to x, always truthy
    console.log("This runs every time!");
}

// ✅ Good - use === for comparison
if (x === 5) {
    console.log("This runs only when x is 5");
}
```

### Mistake 2: Using `||=` with Falsy Valid Values
```javascript
// ❌ Bad - 0 is falsy, so default is incorrectly applied
let count = 0;
count ||= 10;
console.log(count); // 10 (but 0 was a valid value!)

// ✅ Good - use ??= for null/undefined only
let count2 = 0;
count2 ??= 10;
console.log(count2); // 0 (preserves valid 0)
```

### Mistake 3: Object Destructuring with Existing Variables
```javascript
// ❌ Bad - SyntaxError or unexpected behavior
let name = "Alice";
const user = { name: "Bob" };
// const { name } = user; // Error: name already declared

// ✅ Good - rename or use different variable
let name = "Alice";
const user = { name: "Bob" };
const { name: userName } = user;
console.log(name); // Alice (unchanged)
console.log(userName); // Bob

// Or use parentheses to reassign
({ name } = user); // Changes name to "Bob"
```

### Mistake 4: Chained Assignment with Objects
```javascript
// ❌ Bad - creates shared reference
let a = b = c = { value: 1 };
a.value = 42;
console.log(b.value); // 42 (same object!)

// ✅ Good - create independent copies
let a = { value: 1 };
let b = { ...a };
let c = { ...a };
a.value = 42;
console.log(b.value); // 1 (independent)
console.log(c.value); // 1 (independent)
```

### Mistake 5: Not Handling Destructuring Failures
```javascript
// ❌ Bad - undefined values causing errors
const user = { name: "John" };
// const { name, email } = user;
// console.log(email.toLowerCase()); // TypeError: Cannot read property 'toLowerCase' of undefined

// ✅ Good - provide defaults
const { name, email = "" } = user;
console.log(email.toLowerCase()); // "" (works fine)

// Or use optional chaining
const { name, email: userEmail } = user;
console.log(userEmail?.toLowerCase() || "no email");
```

### Mistake 6: Forgetting Parentheses for Destructuring
```javascript
// ❌ Bad - SyntaxError
let x, y;
// { x, y } = { x: 1, y: 2 }; // SyntaxError

// ✅ Good - wrap in parentheses
({ x, y } = { x: 1, y: 2 });
console.log(x, y); // 1 2
```

### Mistake 7: Using `const` When Reassignment is Needed
```javascript
// ❌ Bad - TypeError
const counter = 0;
counter++; // TypeError: Assignment to constant variable

// ✅ Good - use let
let counter = 0;
counter++;
console.log(counter); // 1
```

### Mistake 8: Not Understanding Array Destructuring Order
```javascript
// ❌ Bad - wrong order of extraction
const numbers = [1, 2, 3, 4];
const [first, second] = numbers; // Gets 1 and 2
console.log(second); // 2

// To get last element, use rest or length
const [a, b, c, d] = numbers;
const last = numbers[numbers.length - 1];
console.log(last); // 4
```

## Interview Questions

1. **What's the difference between `=` and `==` and `===` in JavaScript?**  
   *Answer: `=` is the assignment operator used to assign values to variables. `==` is the loose equality operator that compares values after type coercion. `===` is the strict equality operator that compares both value and type without coercion. Assignment (`=`) should never be used in conditional statements.*

2. **What are logical assignment operators and when would you use them?**  
   *Answer: Logical assignment operators (`||=`, `&&=`, `??=`) combine logical operations with assignment. Use `??=` for default values when the variable is `null` or `undefined` (safer than `||=` for falsy values like `0` or `false`). Use `||=` for fallback values when the current value is falsy. Use `&&=` for conditional assignment when the value is truthy.*

3. **Explain destructuring assignment with examples.**  
   *Answer: Destructuring allows extracting values from arrays or objects into variables. Array destructuring uses position `[a, b] = array`, object destructuring uses property names `{ name, age } = object`. It supports default values, renaming (`{ name: userName }`), nesting, and rest patterns. It's useful for simplifying code when working with complex data structures.*

4. **What is the difference between assignment and mutation?**  
   *Answer: Assignment changes what a variable references (e.g., `obj = {}`). Mutation changes the contents of what a variable references (e.g., `obj.value = 42`). With `const`, assignment is forbidden but mutation is allowed. This distinction is crucial for understanding immutability in JavaScript.*

5. **Can you swap two variables without a temporary variable in JavaScript?**  
   *Answer: Yes, using array destructuring: `[a, b] = [b, a]`. This creates a temporary array with swapped values and destructures it back, avoiding the need for an explicit temporary variable. This works for primitive values and references.*

6. **What is the rest operator in destructuring and how is it used?**  
   *Answer: The rest operator (`...`) in destructuring collects remaining elements/properties. For arrays: `[first, ...rest] = [1, 2, 3, 4]` gives `first=1, rest=[2,3,4]`. For objects: `{ id, ...details } = user` gives `id` separately and `details` as an object with remaining properties. It must be the last element in the pattern.*

7. **How does chained assignment work and what are its pitfalls?**  
   *Answer: Chained assignment (`a = b = c = 5`) assigns the same value to multiple variables. For primitives, each gets an independent copy. For objects/references, all variables reference the same object. Pitfall: modifying one object variable affects all others. This can cause unintended bugs if the shared reference is forgotten.*

8. **What are compound assignment operators and why are they useful?**  
   *Answer: Compound operators (`+=`, `-=`, `*=`, etc.) combine an arithmetic/bitwise operation with assignment. They're useful for conciseness and readability, reducing repetition. For example, `x += 5` is clearer than `x = x + 5`. They work with most operators and can improve code maintainability.*

9. **What is the nullish coalescing assignment operator (`??=`)?**  
   *Answer: `??=` was introduced in ES2021. It assigns the right operand only if the left operand is `null` or `undefined`. Unlike `||=`, it doesn't trigger for other falsy values like `0`, `false`, or `""`. This makes it safer for default values where `0` or `false` might be valid values.*

10. **How do you destructure nested objects and arrays together?**  
    *Answer: You can combine object and array destructuring. For example: `const { user: { address: [firstLine, secondLine] } } = data`. This extracts `firstLine` and `secondLine` from an array inside a nested object. You can also use default values: `const { user: { address: [street = "N/A"] = [] } } = data`.*

## Practice Exercises

### Easy Exercise ✨
**Task**: Given an array of numbers, use destructuring to:
1. Extract the first element
2. Extract the last element (using rest)
3. Swap the first and last elements
4. Create a new array with the middle elements

<details>
<summary>Solution</summary>

```javascript
function manipulateArray(arr) {
    // 1. Extract first and last
    const [first, ...rest] = arr;
    const last = rest.length > 0 ? rest.pop() : first;
    
    console.log("Original:", arr);
    console.log("First:", first);
    console.log("Last:", last);
    
    // 2. Get middle elements (everything except first and last)
    const middle = rest.slice(0, -1);
    console.log("Middle:", middle);
    
    // 3. Swap first and last (destructuring)
    let swapped = [last, ...middle, first];
    console.log("Swapped:", swapped);
    
    return { first, last, middle, swapped };
}

// Test
const numbers = [1, 2, 3, 4, 5];
const result = manipulateArray(numbers);
```
</details>

### Medium Exercise 📘
**Task**: Create a configuration system that:
1. Has default settings object
2. Accepts user-provided overrides
3. Uses logical assignment operators for defaults
4. Destructures settings for specific operations
5. Uses nested object destructuring

<details>
<summary>Solution</summary>

```javascript
class ConfigSystem {
    constructor() {
        this.defaults = {
            app: {
                name: "MyApp",
                version: "1.0.0",
                debug: false
            },
            database: {
                host: "localhost",
                port: 5432,
                ssl: false
            },
            features: {
                darkMode: false,
                notifications: true,
                analytics: false
            }
        };
        
        this.settings = { ...this.defaults };
    }
    
    loadConfig(overrides = {}) {
        // Use spread for shallow merge
        this.settings = {
            ...this.defaults,
            ...overrides
        };
        
        // Use logical assignment for nested overrides
        if (overrides.app) {
            this.settings.app = {
                ...this.defaults.app,
                ...overrides.app
            };
        }
        
        if (overrides.database) {
            this.settings.database = {
                ...this.defaults.database,
                ...overrides.database
            };
        }
        
        if (overrides.features) {
            this.settings.features = {
                ...this.defaults.features,
                ...overrides.features
            };
        }
        
        return this;
    }
    
    // Destructure specific properties
    getAppInfo() {
        const { app: { name, version, debug } } = this.settings;
        return { name, version, debug };
    }
    
    getDatabaseConfig() {
        const { database: { host, port, ssl } } = this.settings;
        return { host, port, ssl };
    }
    
    isFeatureEnabled(feature) {
        const { features } = this.settings;
        return features[feature] ?? false;
    }
    
    // Use logical assignment to update config
    updateConfig(updates) {
        // Only update if value is provided
        updates.app?.name &&= (this.settings.app.name = updates.app.name);
        updates.database?.host &&= (this.settings.database.host = updates.database.host);
        updates.features?.darkMode &&= (this.settings.features.darkMode = updates.features.darkMode);
        
        return this;
    }
    
    displayConfig() {
        console.log("\n📋 Current Configuration:");
        console.log("  App:", this.getAppInfo());
        console.log("  Database:", this.getDatabaseConfig());
        console.log("  Features:", this.settings.features);
    }
}

// Usage
const config = new ConfigSystem();

const overrides = {
    app: {
        name: "AwesomeApp",
        debug: true
    },
    database: {
        host: "prod-db.example.com",
        ssl: true
    },
    features: {
        darkMode: true,
        analytics: true
    }
};

config.loadConfig(overrides);
config.displayConfig();

console.log("\n🔍 Feature checks:");
console.log("Dark mode enabled:", config.isFeatureEnabled('darkMode'));
console.log("Notifications enabled:", config.isFeatureEnabled('notifications'));
console.log("Chat enabled:", config.isFeatureEnabled('chat'));

// Update specific config
config.updateConfig({
    app: { name: "UltimateApp" },
    features: { darkMode: false }
});

console.log("\n🔄 After updates:");
config.displayConfig();
```
</details>

### Challenge Exercise 💪
**Task**: Build a state management system that:
1. Maintains a immutable state object
2. Uses assignment patterns to create new states (like Redux)
3. Implements actions that transform the state
4. Uses destructuring and rest patterns extensively
5. Provides a history of state changes
6. Supports undo/redo functionality

<details>
<summary>Solution</summary>

```javascript
class StateManager {
    constructor(initialState = {}) {
        this.currentState = Object.freeze({ ...initialState });
        this.history = [this.currentState];
        this.currentIndex = 0;
        this.maxHistory = 20;
    }
    
    // Get current state (immutable)
    getState() {
        return this.currentState;
    }
    
    // Dispatch an action that creates a new state
    dispatch(action) {
        const newState = this.reducer(this.currentState, action);
        
        // Freeze to enforce immutability
        const frozenState = Object.freeze(newState);
        
        // Update state
        this.currentState = frozenState;
        
        // Update history (with undo/redo support)
        if (this.currentIndex < this.history.length - 1) {
            // If we're in the middle of history, truncate future
            this.history = this.history.slice(0, this.currentIndex + 1);
        }
        
        this.history.push(frozenState);
        if (this.history.length > this.maxHistory) {
            this.history.shift();
        }
        this.currentIndex = this.history.length - 1;
        
        return this.currentState;
    }
    
    // Reducer function - pure transformation
    reducer(state, action) {
        const { type, payload } = action;
        
        switch (type) {
            case 'UPDATE_USER': {
                const { user } = payload;
                // Using spread to create new user
                return {
                    ...state,
                    user: {
                        ...state.user,
                        ...user,
                        lastUpdated: new Date().toISOString()
                    }
                };
            }
            
            case 'ADD_TODO': {
                const { todo } = payload;
                // Add to todos array
                return {
                    ...state,
                    todos: [
                        ...state.todos,
                        {
                            id: Date.now(),
                            ...todo,
                            completed: false,
                            createdAt: new Date().toISOString()
                        }
                    ]
                };
            }
            
            case 'TOGGLE_TODO': {
                const { id } = payload;
                // Toggle todo completion using map
                return {
                    ...state,
                    todos: state.todos.map(todo =>
                        todo.id === id
                            ? { ...todo, completed: !todo.completed }
                            : todo
                    )
                };
            }
            
            case 'DELETE_TODO': {
                const { id } = payload;
                // Filter out todo
                return {
                    ...state,
                    todos: state.todos.filter(todo => todo.id !== id)
                };
            }
            
            case 'UPDATE_SETTINGS': {
                const { settings } = payload;
                return {
                    ...state,
                    settings: {
                        ...state.settings,
                        ...settings
                    }
                };
            }
            
            case 'CLEAR_TODOS': {
                // Destructure to exclude todos
                const { todos, ...rest } = state;
                return {
                    ...rest,
                    todos: []
                };
            }
            
            default:
                return state;
        }
    }
    
    // Undo functionality
    undo() {
        if (this.currentIndex > 0) {
            this.currentIndex--;
            this.currentState = this.history[this.currentIndex];
            return this.currentState;
        }
        console.log("❌ Cannot undo - at the beginning of history");
        return this.currentState;
    }
    
    // Redo functionality
    redo() {
        if (this.currentIndex < this.history.length - 1) {
            this.currentIndex++;
            this.currentState = this.history[this.currentIndex];
            return this.currentState;
        }
        console.log("❌ Cannot redo - at the end of history");
        return this.currentState;
    }
    
    // Get history info
    getHistoryInfo() {
        return {
            currentIndex: this.currentIndex,
            total: this.history.length,
            canUndo: this.currentIndex > 0,
            canRedo: this.currentIndex < this.history.length - 1,
            history: this.history
        };
    }
    
    // Display current state nicely
    displayState() {
        console.log("\n📊 Current State:");
        console.log("  User:", this.currentState.user);
        console.log("  Todos:", this.currentState.todos.length, "items");
        console.log("  Settings:", this.currentState.settings);
        console.log("  History:", this.getHistoryInfo());
    }
}

// Usage
const initialState = {
    user: {
        name: "Alice",
        email: "alice@example.com",
        preferences: {
            theme: "light",
            language: "en"
        }
    },
    todos: [
        { id: 1, text: "Learn JavaScript", completed: false },
        { id: 2, text: "Build a project", completed: true }
    ],
    settings: {
        darkMode: false,
        notifications: true
    }
};

const manager = new StateManager(initialState);

console.log("🚀 Starting State Management System");
manager.displayState();

// Dispatch some actions
manager.dispatch({
    type: 'UPDATE_USER',
    payload: {
        user: { 
            name: "Alice Smith",
            preferences: { theme: "dark" }
        }
    }
});

manager.dispatch({
    type: 'ADD_TODO',
    payload: {
        todo: { text: "Master destructuring" }
    }
});

manager.dispatch({
    type: 'ADD_TODO',
    payload: {
        todo: { text: "Learn about immutability" }
    }
});

manager.dispatch({
    type: 'TOGGLE_TODO',
    payload: { id: 1 }
});

console.log("\n📝 After actions:");
manager.displayState();

// Demonstrate undo/redo
console.log("\n⏪ Undoing...");
manager.undo();
console.log("After undo:");
console.log("Todos count:", manager.getState().todos.length);

console.log("\n⏪ Undoing again...");
manager.undo();
console.log("After second undo:");
console.log("Todos count:", manager.getState().todos.length);

console.log("\n⏩ Redoing...");
manager.redo();
console.log("After redo:");
console.log("Todos count:", manager.getState().todos.length);

// Clear todos
manager.dispatch({
    type: 'CLEAR_TODOS'
});

console.log("\n🧹 After clearing todos:");
manager.displayState();

// Try undo after clear
console.log("\n⏪ Undo clear...");
manager.undo();
console.log("Todos restored:", manager.getState().todos.length);
```

</details>

## Summary

### Key Takeaways 📌

#### Simple vs Compound Assignment
- `=` for basic assignment
- `+=`, `-=`, `*=`, etc. for arithmetic operations
- Logical assignments (`||=`, `&&=`, `??=`) for conditional assignment
- Choose the right operator for clarity and correctness

#### Destructuring Power
- **Arrays**: Extract by position, skip elements, use rest patterns
- **Objects**: Extract by property name, rename, use defaults
- **Nested**: Extract deep values with clear syntax
- **Function Parameters**: Simplify function signatures

#### Best Practices
- **Use `const` by default** - Prefer `const` over `let` when possible
- **Use `??=` for defaults** - Safer than `||=` for falsy values
- **Destructure responsibly** - Use destructuring for clarity, not obfuscation
- **Avoid shared references** - Be careful with object assignment
- **Test for existence** - Use optional chaining and defaults

#### Common Patterns
```
// Safe default assignment
value ??= "default";

// Swap variables
[a, b] = [b, a];

// Extract object properties
const { property, property: alias } = object;

// Function parameter destructuring
function fn({ param, param2 }) { }

// Create new objects immutably
const updated = { ...old, property: newValue };
```

### Quick Reference Card 🎯
```
Assignment:
  ✅ Use = for simple assignment
  ✅ Use +=, -=, *= for math operations
  ✅ Use ??= for null/undefined defaults
  ✅ Use ||= for falsy fallbacks (carefully)

Destructuring:
  ✅ [a, b] = array     - Position-based
  ✅ { x, y } = object  - Name-based
  ✅ { x: x1 } = obj    - Rename
  ✅ { x = 0 } = obj    - Default values
  ✅ [a, ...r] = arr    - Rest pattern
  ✅ { x, ...r } = obj  - Rest properties

Avoid:
  ❌ = in conditions (use ===)
  ❌ ||= for 0, false, "" (use ??=)
  ❌ Chained object assignment (creates shared refs)
  ❌ const when reassignment is needed
  ❌ Deeply nested destructuring (reduces readability)
```

**Mastering assignment patterns is essential for writing clean, maintainable, and bug-free JavaScript!** 🚀
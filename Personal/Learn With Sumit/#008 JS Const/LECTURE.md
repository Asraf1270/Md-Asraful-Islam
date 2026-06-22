# JavaScript `const` Declaration

## Overview

The `const` keyword in JavaScript is used to declare variables that cannot be reassigned. Think of it as creating a "constant" binding - once you assign a value to a `const` variable, you cannot change what that variable points to. It was introduced in ES6 (2015) alongside `let` to improve JavaScript's variable handling.

### Why `const` is Important 🔒
- **Immutability of Binding**: Prevents accidental reassignment of variables
- **Code Safety**: Makes your intentions clear - this value should not change
- **Better Performance**: JavaScript engines can optimize code with constants
- **Default Choice**: Modern best practice suggests using `const` by default, only using `let` when reassignment is needed
- **Block Scoping**: Like `let`, `const` is block-scoped, avoiding hoisting issues of `var`

## Key Concepts

### What `const` Actually Means
- **Reassignment is Forbidden**: You cannot reassign a `const` variable
- **Block Scope**: `const` is scoped to the nearest enclosing block (`{}`)
- **Must Be Initialized**: You must assign a value when declaring a `const`
- **Not Immutable Values**: For objects and arrays, the content *can* change; only the reference is constant
- **Temporal Dead Zone**: Like `let`, `const` variables are not accessible before declaration

### `const` vs `let` vs `var`

| Feature | `const` | `let` | `var` |
|---------|---------|-------|-------|
| Reassignment | ❌ No | ✅ Yes | ✅ Yes |
| Block Scoped | ✅ Yes | ✅ Yes | ❌ No (function scoped) |
| Hoisting | ⚠️ TDZ | ⚠️ TDZ | ✅ Hoisted (undefined) |
| Must Initialize | ✅ Yes | ❌ No | ❌ No |
| Global Object Property | ❌ No | ❌ No | ✅ Yes |

## Syntax

```javascript
// Basic syntax
const variableName = value;

// Examples
const PI = 3.14159;
const APP_NAME = "MyApp";
const user = { name: "Alice", age: 25 };
const colors = ["red", "green", "blue"];
```

## Examples

### Example 1: Primitive Values
```javascript
// Primitive values (number, string, boolean, null, undefined, symbol)
const birthYear = 1990;
const firstName = "Sarah";
const isActive = true;

console.log(birthYear); // Output: 1990
console.log(firstName); // Output: Sarah
console.log(isActive); // Output: true

// ❌ This will throw an error - cannot reassign
try {
    birthYear = 2000;
} catch (error) {
    console.log("Error:", error.message); 
    // Output: Error: Assignment to constant variable
}
```

**Output:**
```
1990
Sarah
true
Error: Assignment to constant variable
```

### Example 2: Objects and Arrays with `const`
```javascript
// Object with const
const person = {
    name: "Bob",
    city: "New York"
};

// ✅ Allowed - modifying object properties
person.name = "Robert";
person.age = 30;

console.log("Updated person:", person);
// Output: Updated person: { name: 'Robert', city: 'New York', age: 30 }

// Array with const
const numbers = [1, 2, 3];

// ✅ Allowed - modifying array content
numbers.push(4);
numbers[0] = 10;

console.log("Updated numbers:", numbers);
// Output: Updated numbers: [10, 2, 3, 4]

// ❌ This will throw an error - cannot reassign the array
try {
    numbers = [5, 6, 7];
} catch (error) {
    console.log("Error:", error.message);
    // Output: Error: Assignment to constant variable
}
```

**Output:**
```
Updated person: { name: 'Robert', city: 'New York', age: 30 }
Updated numbers: [10, 2, 3, 4]
Error: Assignment to constant variable
```

### Example 3: Block Scoping
```javascript
if (true) {
    const blockScoped = "I exist only in this block";
    console.log(blockScoped); // Output: I exist only in this block
}

// ❌ ReferenceError - blockScoped is not defined outside the block
try {
    console.log(blockScoped);
} catch (error) {
    console.log("Error:", error.message);
    // Output: Error: blockScoped is not defined
}

// Different block - different variable
{
    const blockScoped = "Different block";
    console.log(blockScoped); // Output: Different block
}
```

**Output:**
```
I exist only in this block
Error: blockScoped is not defined
Different block
```

### Example 4: Temporal Dead Zone (TDZ)
```javascript
// ❌ Cannot access before declaration
try {
    console.log(myConst); // ReferenceError
} catch (error) {
    console.log("Error:", error.message);
    // Output: Error: Cannot access 'myConst' before initialization
}

// Temporal Dead Zone ends here
const myConst = "Declared now";

// ✅ Can access after declaration
console.log(myConst); // Output: Declared now
```

**Output:**
```
Error: Cannot access 'myConst' before initialization
Declared now
```

## Explanation of Examples

### Example 1: Primitive Values
- `const` prevents reassignment of primitive values (numbers, strings, etc.)
- When we try `birthYear = 2000`, JavaScript throws a `TypeError`
- The error message clearly states "Assignment to constant variable"
- This protection helps prevent accidental value changes

### Example 2: Objects and Arrays
- **Important Distinction**: `const` only prevents reassignment of the variable itself
- For objects, you can still modify properties (`.name`, `.age`)
- For arrays, you can still modify elements (`numbers[0] = 10`) or use methods (`.push()`)
- The error occurs only when trying to reassign the entire object/array
- This is a common point of confusion for beginners

### Example 3: Block Scoping
- `const` is block-scoped, meaning it only exists within `{}` braces
- Each block has its own separate scope and variables
- Variables declared in different blocks don't conflict with each other
- Attempting to access a block-scoped variable outside its block causes `ReferenceError`

### Example 4: Temporal Dead Zone
- TDZ is the period from entering a scope until the variable is declared
- Accessing a `const` variable during TDZ causes `ReferenceError`
- This is different from `var` which is hoisted and initialized with `undefined`
- TDZ helps catch errors by preventing usage before declaration

## Important Notes

### Best Practices 📝
1. **Default to `const`**: Use `const` for all variables that won't be reassigned
2. **Uppercase for Constants**: Use `UPPER_CASE` for truly constant values (like configuration)
3. **Meaningful Names**: Use descriptive names like `MAX_USERS` instead of `max`
4. **Declare Closely**: Declare `const` variables as close to where they're used
5. **Avoid `var`**: Modern code should use `const` and `let` exclusively

### Things to Remember 💡
- `const` does NOT make values immutable, only the binding
- `const` cannot be declared without initialization
- `const` is block-scoped, not function-scoped
- `const` has a Temporal Dead Zone (TDZ)
- `const` is not available on `window` (global object) in browsers

## Common Mistakes

### Mistake 1: Confusing Reassignment with Mutation
```javascript
// ❌ Incorrect thinking
const user = { name: "Alice" };
user = { name: "Bob" }; // TypeError - reassignment

// ✅ Correct thinking - this is allowed
const user = { name: "Alice" };
user.name = "Bob"; // This IS allowed - property mutation
console.log(user.name); // Output: Bob
```

### Mistake 2: Forgetting to Initialize
```javascript
// ❌ SyntaxError - missing initializer
const PI; // Uncaught SyntaxError: Missing initializer in const declaration

// ✅ Always initialize
const PI = 3.14159;
```

### Mistake 3: Using `const` for Values That Change
```javascript
// ❌ Using const when reassignment is needed
const counter = 0;
counter++; // TypeError - assignment to constant variable

// ✅ Use let for values that change
let counter = 0;
counter++; // Works fine
```

### Mistake 4: Accessing Before Declaration
```javascript
// ❌ ReferenceError - TDZ
console.log(age); // Cannot access 'age' before initialization
const age = 25;

// ✅ Declare before use
const age = 25;
console.log(age); // Output: 25
```

### Mistake 5: Assuming `const` Makes Objects Immutable
```javascript
// ❌ Wrong assumption
const config = { theme: "dark" };
config.theme = "light"; // This IS allowed!
console.log(config.theme); // Output: light

// ✅ Use Object.freeze() for true immutability
const config = Object.freeze({ theme: "dark" });
config.theme = "light"; // In strict mode: TypeError
console.log(config.theme); // Output: dark (unchanged)
```

## Interview Questions

1. **What's the difference between `const` and `let`?**  
   *Answer: `const` cannot be reassigned, while `let` can be. Both are block-scoped and have TDZ. `const` must be initialized at declaration.*

2. **Can you modify an object declared with `const`? Why or why not?**  
   *Answer: Yes, you can modify properties because `const` only prevents reassignment of the variable, not mutation of the object's contents.*

3. **What is the Temporal Dead Zone (TDZ) and how does it affect `const`?**  
   *Answer: TDZ is the period between entering a scope and the declaration of a variable. Accessing a `const` during TDZ throws a ReferenceError, preventing usage before declaration.*

4. **When would you use `const` instead of `let`?**  
   *Answer: Use `const` for values that should never be reassigned (default choice). Use `let` only when reassignment is necessary, like loop counters or accumulators.*

5. **Is `const` more performant than `let`?**  
   *Answer: In theory, JavaScript engines can optimize `const` better since the binding is immutable. However, in practice, the performance difference is usually negligible for most applications.*

6. **What happens if you declare two `const` variables with the same name in different blocks?**  
   *Answer: It's allowed because they have separate block scopes. Each block has its own variable independent of other blocks.*

## Practice Exercises

### Easy Exercise ✨
**Task**: Fix the following code to work correctly:

```javascript
// Fix this code
const name = "John";
name = "Jane";
console.log(name);
```

<details>
<summary>Solution</summary>

```javascript
const name = "John";
console.log(name); // "John"
// To use "Jane", use a different variable or use let:
let name2 = "John";
name2 = "Jane";
console.log(name2); // "Jane"
```
</details>

### Medium Exercise 📘
**Task**: Create a `const` object representing a product with properties (name, price, quantity). Then:
1. Update the price and quantity
2. Add a new property (category)
3. Print the updated product
4. Try reassigning the entire object and handle the error

<details>
<summary>Solution</summary>

```javascript
// 1. Create product object
const product = {
    name: "Laptop",
    price: 999,
    quantity: 10
};

// 2. Update properties
product.price = 899;
product.quantity = 15;

// 3. Add new property
product.category = "Electronics";

console.log("Updated product:", product);
// Output: Updated product: { name: 'Laptop', price: 899, quantity: 15, category: 'Electronics' }

// 4. Attempt reassignment
try {
    product = { name: "Tablet", price: 499 };
} catch (error) {
    console.log("Cannot reassign:", error.message);
}
```
</details>

### Challenge Exercise 💪
**Task**: Create a banking system simulation using `const` and `let` appropriately:
1. Create a `const` object `account` with properties: owner, balance, transactions (array)
2. Write functions: `deposit(amount)` and `withdraw(amount)` that modify the account
3. Write a function `getTransactionHistory()` that returns all transactions
4. Ensure the account object reference can't be changed, but its internal state can
5. Use `Object.freeze()` to prevent modifications to transaction objects

<details>
<summary>Solution</summary>

```javascript
const account = {
    owner: "Alice Smith",
    balance: 1000,
    transactions: []
};

function deposit(amount) {
    if (amount <= 0) {
        console.log("Amount must be positive");
        return;
    }
    const transaction = Object.freeze({
        type: "deposit",
        amount: amount,
        date: new Date().toISOString(),
        newBalance: account.balance + amount
    });
    account.transactions.push(transaction);
    account.balance += amount;
    console.log(`💰 Deposited $${amount}. New balance: $${account.balance}`);
}

function withdraw(amount) {
    if (amount <= 0) {
        console.log("Amount must be positive");
        return;
    }
    if (amount > account.balance) {
        console.log("❌ Insufficient funds");
        return;
    }
    const transaction = Object.freeze({
        type: "withdraw",
        amount: amount,
        date: new Date().toISOString(),
        newBalance: account.balance - amount
    });
    account.transactions.push(transaction);
    account.balance -= amount;
    console.log(`💸 Withdrew $${amount}. New balance: $${account.balance}`);
}

function getTransactionHistory() {
    console.log(`\n📋 Transaction History for ${account.owner}:`);
    account.transactions.forEach((t, i) => {
        console.log(`${i + 1}. ${t.type.toUpperCase()} - $${t.amount} (${t.date})`);
    });
    console.log(`Current balance: $${account.balance}`);
}

// Test the system
deposit(500);
withdraw(200);
deposit(1000);
withdraw(5000); // Insufficient funds
getTransactionHistory();

// Try to reassign account (should fail)
try {
    account = { owner: "Bob", balance: 0 };
} catch (error) {
    console.log("\n❌ Cannot reassign account object");
}

// Try to modify a transaction (should fail in strict mode)
try {
    account.transactions[0].amount = 999;
} catch (error) {
    console.log("❌ Cannot modify frozen transaction object");
}
```
</details>

## Summary

### Key Takeaways 📌
- `const` creates block-scoped variables that cannot be reassigned
- Must be initialized at declaration time
- Has Temporal Dead Zone (TDZ) like `let`
- Does NOT make objects or arrays immutable, only the binding/reference
- Use `const` by default, only use `let` when reassignment is necessary
- Prefer `const` and `let` over `var` in modern JavaScript
- `Object.freeze()` can be used for true immutability of objects
- Understanding the distinction between reassignment and mutation is crucial

### When to Use Each
| Use Case | Recommended |
|----------|-------------|
| Values that never change | `const` |
| Loop counters | `let` |
| Accumulators | `let` |
| Configuration values | `const` |
| Function parameters | `const` (implicitly) |
| Any value by default | `const` |

Remember: **Const by default, let only when needed!** 🚀
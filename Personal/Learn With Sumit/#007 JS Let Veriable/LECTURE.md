# JavaScript `let`

## Introduction

The `let` keyword was introduced in **ES6 (ECMAScript 2015)** and is used to declare variables in JavaScript.

It provides better variable management than `var` because it supports **block scope** and prevents accidental redeclaration.

### Syntax

```javascript
let variableName;
let variableName = value;
```

### Example

```javascript
let name = "John";
console.log(name);
```

Output:

```text
John
```

---

# Why Use `let`?

Before ES6, JavaScript developers mainly used `var` to declare variables.

However, `var` has some issues:

* Function-scoped instead of block-scoped.
* Can be redeclared.
* Can cause unexpected behavior in loops and conditions.

`let` solves many of these problems.

Example:

```javascript
let age = 25;
age = 26;

console.log(age);
```

Output:

```text
26
```

---

# Block Scope

Variables declared with `let` are only accessible inside the block where they are declared.

A block is defined by curly braces `{}`.

Example:

```javascript
{
    let x = 10;
    console.log(x);
}
```

Output:

```text
10
```

Trying to access `x` outside the block:

```javascript
{
    let x = 10;
}

console.log(x);
```

Output:

```text
ReferenceError: x is not defined
```

---

# Difference Between `let` and `var`

## Using `var`

```javascript
{
    var x = 5;
}

console.log(x);
```

Output:

```text
5
```

Because `var` ignores block scope.

## Using `let`

```javascript
{
    let x = 5;
}

console.log(x);
```

Output:

```text
ReferenceError
```

Because `let` respects block scope.

---

# Redeclaring Variables

## `var` Allows Redeclaration

```javascript
var name = "John";
var name = "Mike";

console.log(name);
```

Output:

```text
Mike
```

## `let` Does Not Allow Redeclaration

```javascript
let name = "John";
let name = "Mike";
```

Output:

```text
SyntaxError: Identifier 'name' has already been declared
```

---

# Reassigning Variables

Variables declared with `let` can be reassigned.

Example:

```javascript
let score = 50;

score = 75;

console.log(score);
```

Output:

```text
75
```

---

# `let` in Different Blocks

You can use the same variable name in different blocks.

Example:

```javascript
let x = 10;

{
    let x = 20;
    console.log(x);
}

console.log(x);
```

Output:

```text
20
10
```

The two variables are different because they belong to different scopes.

---

# Global Scope

Variables declared outside any function or block become global.

Example:

```javascript
let user = "John";

function showUser() {
    console.log(user);
}

showUser();
```

Output:

```text
John
```

---

# `let` and Loops

`let` creates a new variable for each loop iteration.

Example:

```javascript
for (let i = 0; i < 3; i++) {
    console.log(i);
}
```

Output:

```text
0
1
2
```

Trying to access `i` outside:

```javascript
for (let i = 0; i < 3; i++) {
}

console.log(i);
```

Output:

```text
ReferenceError
```

---

# Hoisting

Like `var`, `let` is hoisted.

However, it cannot be used before declaration.

Example:

```javascript
console.log(x);

let x = 5;
```

Output:

```text
ReferenceError: Cannot access 'x' before initialization
```

This behavior is called the **Temporal Dead Zone (TDZ)**.

---

# Temporal Dead Zone (TDZ)

The TDZ is the period between entering a scope and declaring a `let` variable.

Example:

```javascript
{
    console.log(age);

    let age = 20;
}
```

Output:

```text
ReferenceError
```

The variable exists but cannot be accessed before initialization.

---

# `let` Inside Functions

Example:

```javascript
function greet() {
    let message = "Hello";
    console.log(message);
}

greet();
```

Output:

```text
Hello
```

Accessing it outside:

```javascript
function greet() {
    let message = "Hello";
}

console.log(message);
```

Output:

```text
ReferenceError
```

---

# Practical Example

```javascript
let balance = 1000;

if (balance > 500) {
    let discount = 100;
    console.log("Discount:", discount);
}

console.log(balance);
```

Output:

```text
Discount: 100
1000
```

---

# Common Mistakes

## 1. Redeclaring a `let` Variable

```javascript
let x = 10;
let x = 20;
```

❌ Error

---

## 2. Using Before Declaration

```javascript
console.log(x);

let x = 5;
```

❌ Error

---

## 3. Accessing Outside Scope

```javascript
{
    let x = 10;
}

console.log(x);
```

❌ Error

---

# Best Practices

✅ Use `let` when the value may change.

```javascript
let counter = 0;
counter++;
```

✅ Use meaningful variable names.

```javascript
let studentName = "John";
let totalMarks = 95;
```

✅ Keep variables in the smallest possible scope.

```javascript
if (true) {
    let result = "Success";
    console.log(result);
}
```

---

# `let` vs `const`

| Feature       | let | const |
| ------------- | --- | ----- |
| Block Scope   | Yes | Yes   |
| Redeclaration | No  | No    |
| Reassignment  | Yes | No    |
| Hoisted       | Yes | Yes   |

Example:

```javascript
let age = 20;
age = 21;
```

Valid.

```javascript
const age = 20;
age = 21;
```

Error.

---

# Summary

* `let` was introduced in ES6.
* Variables declared with `let` are block-scoped.
* `let` cannot be redeclared in the same scope.
* `let` can be reassigned.
* `let` is hoisted but remains in the Temporal Dead Zone until initialized.
* `let` is safer and more predictable than `var`.
* Use `let` whenever a variable's value needs to change.

## Quick Example

```javascript
let name = "John";

name = "Mike";

console.log(name);
```

Output:

```text
Mike
```

This demonstrates the main purpose of `let`: declaring variables that can be updated while maintaining block scope.

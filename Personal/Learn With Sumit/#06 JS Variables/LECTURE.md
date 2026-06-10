# JavaScript Variables

## Introduction

Variables are containers used to store data values.

Examples:

```javascript
let name = "John";
let age = 25;
```

---

# Why Variables?

Variables help store information that can be used later.

Example:

```javascript
let price = 100;
let quantity = 5;

let total = price * quantity;
```

---

# Declaring Variables

JavaScript provides three ways:

```javascript
var
let
const
```

---

# Using let

```javascript
let name = "John";
```

Example:

```javascript
let age = 20;

age = 21;
```

Output:

```text
21
```

Values can be changed.

---

# Using const

```javascript
const PI = 3.1416;
```

Example:

```javascript
const country = "Bangladesh";
```

Cannot be reassigned:

```javascript
const PI = 3.1416;

PI = 5;
```

Output:

```text
Error
```

---

# Using var

```javascript
var name = "John";
```

Older JavaScript code often uses `var`.

Modern JavaScript prefers:

```javascript
let
const
```

---

# Variable Naming Rules

## Allowed

```javascript
let name;
let age1;
let firstName;
let first_name;
let $price;
```

---

## Not Allowed

```javascript
let 1name;
let first-name;
let let;
```

---

# Case Sensitivity

JavaScript is case-sensitive.

```javascript
let name = "John";
let Name = "David";
```

These are different variables.

---

# Multiple Variables

```javascript
let x = 10;
let y = 20;
let z = 30;
```

or

```javascript
let x = 10, y = 20, z = 30;
```

---

# Assigning Values Later

```javascript
let name;

name = "John";
```

---

# Variable Types

## String

```javascript
let name = "John";
```

---

## Number

```javascript
let age = 25;
```

---

## Boolean

```javascript
let isStudent = true;
```

---

# Variable Example

```javascript
let firstName = "Rahim";
let lastName = "Ahmed";

let fullName = firstName + " " + lastName;

console.log(fullName);
```

Output:

```text
Rahim Ahmed
```

---

# Variable Scope Overview

## Block Scope (let)

```javascript
{
    let age = 20;
}
```

Accessible only inside the block.

---

## Function Scope (var)

```javascript
function test() {
    var age = 20;
}
```

Accessible inside the function.

---

# var vs let vs const

| Feature     | var  | let    | const       |
| ----------- | ---- | ------ | ----------- |
| Reassign    | Yes  | Yes    | No          |
| Redeclare   | Yes  | No     | No          |
| Block Scope | No   | Yes    | Yes         |
| Modern Use  | Rare | Common | Most Common |

---

# Best Practices

Use:

```javascript
const PI = 3.1416;
const country = "Bangladesh";

let age = 20;
let score = 100;
```

Avoid:

```javascript
var name = "John";
```

unless working with older codebases.

---

# Summary

* Variables store data values.
* JavaScript uses `var`, `let`, and `const`.
* Use `const` whenever possible.
* Use `let` when values change.
* Avoid `var` in modern JavaScript.
* Variable names should be meaningful and readable.

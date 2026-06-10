# JavaScript Comments

## Introduction

Comments are notes written inside code.

Comments are ignored by JavaScript and are not executed.

They help programmers:

* Explain code
* Improve readability
* Document programs
* Debug applications

---

# Single-Line Comments

Single-line comments start with:

```javascript
//
```

Example:

```javascript
// This is a comment

let age = 20;
```

---

## Using Comments for Explanation

```javascript
// Store user age
let age = 20;

// Display age
console.log(age);
```

---

## Using Comments to Disable Code

```javascript
// let age = 25;

let age = 20;
```

This is useful for testing.

---

# Multi-Line Comments

Multi-line comments start with:

```javascript
/*
```

and end with:

```javascript
*/
```

Example:

```javascript
/*
This is
a multi-line
comment
*/
```

---

## Documentation Example

```javascript
/*
Project Name: Student Management System
Author: John Doe
Date: 2025
*/

let student = "Rahim";
```

---

# Commenting Code Blocks

```javascript
/*
console.log("Line 1");
console.log("Line 2");
console.log("Line 3");
*/
```

---

# Best Practices

## Good Comment

```javascript
// Calculate total product price
let total = quantity * price;
```

---

## Bad Comment

```javascript
// Add x and y
let total = x + y;
```

The code already explains itself.

---

# When to Use Comments

Use comments for:

* Business logic
* Complex calculations
* Important decisions
* TODO notes

Example:

```javascript
// TODO: Add user authentication
```

---

# When Not to Use Comments

Avoid comments for obvious code.

Bad:

```javascript
// Create variable
let age = 20;
```

---

# Summary

## Single-Line Comment

```javascript
// Comment
```

## Multi-Line Comment

```javascript
/ *
Comment
* /
```

(Without spaces)

```javascript
/*
Comment
*/
```

Comments improve readability and maintainability.

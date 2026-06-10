# JavaScript Syntax and Statements

## Introduction

JavaScript syntax is the set of rules that define how JavaScript programs are written and interpreted by the browser.

A JavaScript program consists of:

* Values
* Variables
* Operators
* Expressions
* Keywords
* Statements

---

## JavaScript Syntax

## Values

JavaScript works with two types of values:

### Fixed Values (Literals)

Values written directly into code.

```javascript
10
3.14
"Hello"
true
```

Example:

```javascript
let age = 20;
let name = "John";
```

---

### Variable Values

Values stored in variables.

```javascript
let x = 10;
let y = x + 5;
```

---

## Operators

Operators are used to perform actions on values.

### Arithmetic Operators

```javascript
+
-
*
/
%
**
```

Example:

```javascript
let total = 10 + 5;
```

Output:

```text
15
```

---

## Expressions

An expression produces a value.

Examples:

```javascript
5 + 5
```

```javascript
x * 10
```

```javascript
"Hello" + " World"
```

---

## Keywords

Keywords are reserved words in JavaScript.

Examples:

```javascript
let
const
var
if
else
for
while
function
return
```

---

## Identifiers

Identifiers are names used for:

* Variables
* Functions
* Objects

Example:

```javascript
let firstName = "John";
```

Here:

```text
firstName
```

is an identifier.

---

## JavaScript Statements

Statements are instructions executed by JavaScript.

Example:

```javascript
let x = 5;
let y = 10;
let z = x + y;
```

Each line is a statement.

---

## Multiple Statements

```javascript
let name = "John";
let age = 25;

console.log(name);
console.log(age);
```

---

## Semicolons

Semicolons separate statements.

```javascript
let x = 10;
let y = 20;
```

Although JavaScript can insert semicolons automatically, using them is considered a good practice.

---

## Code Blocks

A block groups statements together using curly braces.

```javascript
{
    let x = 10;
    let y = 20;
}
```

Example:

```javascript
if (true) {
    console.log("Hello");
}
```

---

## Whitespace

JavaScript ignores extra spaces.

```javascript
let person = "John";
```

is the same as:

```javascript
let     person      =      "John";
```

---

## Line Length and Readability

Good:

```javascript
document.getElementById("demo").innerHTML =
"Hello JavaScript";
```

Bad:

```javascript
document.getElementById("demo").innerHTML = "Hello JavaScript";
```

for very long lines.

---

### Best Practices

✅ Use meaningful variable names

```javascript
let studentName = "Rahim";
```

✅ Use semicolons

```javascript
let age = 20;
```

✅ Use indentation

```javascript
if (age >= 18) {
    console.log("Adult");
}
```

---

### Summary

* Syntax defines how JavaScript code is written.
* Statements are instructions executed by JavaScript.
* Operators perform actions.
* Expressions produce values.
* Keywords have special meanings.
* Curly braces create code blocks.
* Semicolons improve readability.

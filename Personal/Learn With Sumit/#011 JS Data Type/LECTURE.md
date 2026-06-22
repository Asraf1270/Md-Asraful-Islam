# JavaScript Data Types

## Overview

**Data types** in JavaScript define the kind of values that can be stored and manipulated in a program. JavaScript is a **dynamically typed** language, meaning variables can hold different types of values over time, and the type is determined at runtime. Understanding data types is fundamental to writing correct and efficient JavaScript code.

### Why Data Types are Important 🎯
- **Memory Management**: Different types use different amounts of memory
- **Operations**: Certain operations only work with specific types
- **Type Safety**: Understanding types helps prevent bugs and errors
- **Coercion**: JavaScript automatically converts between types, which can be both helpful and dangerous
- **Data Validation**: Ensure data is in the correct format before processing
- **Performance**: Some types are more efficient for specific operations

## Key Concepts

### Classification of Data Types

#### 1. Primitive (Immutable) Types
- **Number**: All numbers (integers, floats, NaN, Infinity)
- **String**: Text data and character sequences
- **Boolean**: `true` or `false`
- **Undefined**: A variable that has been declared but not assigned
- **Null**: Intentionally empty value
- **Symbol** (ES6): Unique and immutable identifiers
- **BigInt** (ES2020): Integers beyond the Number limit

#### 2. Non-Primitive (Reference) Types
- **Object**: Collection of key-value pairs
- **Array**: Ordered list of values (special object)
- **Function**: Callable objects (special object)
- **Date**: Date and time objects
- **RegExp**: Regular expression objects
- **Map**: Key-value collection with any key type
- **Set**: Collection of unique values

### Key Distinctions

#### Primitive vs Reference
- **Primitive**: Stored directly in memory, immutable, compared by value
- **Reference**: Stored as a reference in memory, mutable, compared by reference

#### Dynamic Typing
- Variables can hold any type at any time
- Type is checked at runtime, not compile time
- `typeof` operator helps identify types

## Syntax

### Type Declaration and Checking
```javascript
// Variables don't have fixed types
let value = 42;       // Number
value = "Hello";      // Now String
value = true;         // Now Boolean

// Type checking
typeof 42;            // "number"
typeof "Hello";       // "string"
typeof true;          // "boolean"
typeof undefined;     // "undefined"
typeof null;          // "object" (bug!)
typeof {};           // "object"
typeof [];           // "object"
typeof function(){}; // "function"
typeof Symbol();     // "symbol"
typeof 42n;          // "bigint"
```

## Examples

### Example 1: Number Type
```javascript
// Integers
const integer = 42;
console.log("Integer:", integer, typeof integer);
// Output: Integer: 42 number

// Floating point numbers
const float = 3.14;
console.log("Float:", float, typeof float);
// Output: Float: 3.14 number

// Scientific notation
const scientific = 2.5e5; // 250,000
console.log("Scientific:", scientific);
// Output: Scientific: 250000

// Special numeric values
const infinity = Infinity;
const negativeInfinity = -Infinity;
const notANumber = NaN;
console.log("Infinity:", infinity, typeof infinity);
console.log("NaN:", notANumber, typeof notANumber);
// Output: Infinity: Infinity number
// Output: NaN: NaN number

// Number methods
const num = 123.456;
console.log("toFixed:", num.toFixed(2)); // "123.46"
console.log("toPrecision:", num.toPrecision(4)); // "123.5"
console.log("toString:", num.toString(2)); // Binary representation
console.log("isInteger:", Number.isInteger(42)); // true
console.log("isInteger:", Number.isInteger(3.14)); // false
console.log("isNaN:", Number.isNaN(NaN)); // true
console.log("isNaN:", Number.isNaN("hello")); // false

// Number parsing
console.log("parseInt:", parseInt("123px")); // 123
console.log("parseFloat:", parseFloat("3.14em")); // 3.14
console.log("Number:", Number("42")); // 42
console.log("Number:", Number("invalid")); // NaN

// Binary, octal, hexadecimal
console.log("Binary:", 0b1010); // 10
console.log("Octal:", 0o12); // 10
console.log("Hexadecimal:", 0xA); // 10

// Number limits
console.log("MAX_SAFE_INTEGER:", Number.MAX_SAFE_INTEGER); // 9007199254740991
console.log("MIN_SAFE_INTEGER:", Number.MIN_SAFE_INTEGER); // -9007199254740991
console.log("MAX_VALUE:", Number.MAX_VALUE);
console.log("MIN_VALUE:", Number.MIN_VALUE);
```

**Output:**
```
Integer: 42 number
Float: 3.14 number
Scientific: 250000
Infinity: Infinity number
NaN: NaN number
toFixed: 123.46
toPrecision: 123.5
toString: 1111011
isInteger: true
isInteger: false
isNaN: true
isNaN: false
parseInt: 123
parseFloat: 3.14
Number: 42
Number: NaN
Binary: 10
Octal: 10
Hexadecimal: 10
MAX_SAFE_INTEGER: 9007199254740991
MIN_SAFE_INTEGER: -9007199254740991
MAX_VALUE: 1.7976931348623157e+308
MIN_VALUE: 5e-324
```

### Example 2: String Type
```javascript
// String creation
const single = 'Hello';
const double = "World";
const template = `Template ${single}`;
console.log("Single:", single);
console.log("Double:", double);
console.log("Template:", template);
// Output: Single: Hello
// Output: Double: World
// Output: Template: Template Hello

// String properties
const text = "JavaScript";
console.log("Length:", text.length); // 10
console.log("Char at index 0:", text[0]); // J
console.log("Char at index 5:", text.charAt(5)); // c

// String methods
const str = "Hello World";
console.log("toUpperCase:", str.toUpperCase()); // HELLO WORLD
console.log("toLowerCase:", str.toLowerCase()); // hello world
console.log("substring:", str.substring(0, 5)); // Hello
console.log("slice:", str.slice(0, 5)); // Hello
console.log("slice negative:", str.slice(-5)); // World
console.log("split:", str.split(" ")); // ["Hello", "World"]
console.log("replace:", str.replace("World", "JavaScript")); // Hello JavaScript
console.log("includes:", str.includes("World")); // true
console.log("startsWith:", str.startsWith("Hello")); // true
console.log("endsWith:", str.endsWith("World")); // true
console.log("indexOf:", str.indexOf("o")); // 4
console.log("lastIndexOf:", str.lastIndexOf("o")); // 7

// Template literals
const name = "John";
const age = 30;
const message = `My name is ${name} and I am ${age} years old.`;
console.log("Template literal:", message);
// Output: Template literal: My name is John and I am 30 years old.

// Multiline strings
const multiline = `
This is
a multiline
string.
`;
console.log("Multiline:", multiline);
// Output: Multiline: 
// This is
// a multiline
// string.

// Escape sequences
console.log("New line:\nHello\nWorld");
console.log("Tab:\tHello\tWorld");
console.log("Backslash: \\");
console.log("Quote: \"Hello\"");
console.log("Unicode: \u00A9"); // ©

// String concatenation
const concat1 = "Hello" + " " + "World";
const concat2 = "Hello".concat(" ", "World");
console.log("Concatenation:", concat1, concat2);

// String padding
console.log("padStart:", "42".padStart(5, "0")); // "00042"
console.log("padEnd:", "42".padEnd(5, "0")); // "42000"

// Trim
const padded = "  Hello World  ";
console.log("trim:", padded.trim()); // "Hello World"
console.log("trimStart:", padded.trimStart()); // "Hello World  "
console.log("trimEnd:", padded.trimEnd()); // "  Hello World"
```

**Output:**
```
Single: Hello
Double: World
Template: Template Hello
Length: 10
Char at index 0: J
Char at index 5: c
toUpperCase: HELLO WORLD
toLowerCase: hello world
substring: Hello
slice: Hello
slice negative: World
split: [ 'Hello', 'World' ]
replace: Hello JavaScript
includes: true
startsWith: true
endsWith: true
indexOf: 4
lastIndexOf: 7
Template literal: My name is John and I am 30 years old.
Multiline: 
This is
a multiline
string.

New line:
Hello
World
Tab:	Hello	World
Backslash: \
Quote: "Hello"
Unicode: ©
Concatenation: Hello World Hello World
padStart: 00042
padEnd: 42000
trim: Hello World
trimStart: Hello World  
trimEnd:   Hello World
```

### Example 3: Boolean Type
```javascript
// Boolean values
const isTrue = true;
const isFalse = false;
console.log("True:", isTrue, typeof isTrue);
console.log("False:", isFalse, typeof isFalse);
// Output: True: true boolean
// Output: False: false boolean

// Boolean conversion
console.log("Boolean(0):", Boolean(0)); // false
console.log("Boolean(1):", Boolean(1)); // true
console.log("Boolean(''):", Boolean("")); // false
console.log("Boolean('hello'):", Boolean("hello")); // true
console.log("Boolean(null):", Boolean(null)); // false
console.log("Boolean(undefined):", Boolean(undefined)); // false
console.log("Boolean({}):", Boolean({})); // true
console.log("Boolean([]):", Boolean([])); // true

// Truthy and Falsy values
const falsyValues = [false, 0, -0, "", null, undefined, NaN];
const truthyValues = [true, 1, -1, "hello", [], {}, function(){}];

console.log("\nFalsy values:");
falsyValues.forEach(val => {
    console.log(`  ${String(val)}: ${Boolean(val)}`);
});

console.log("\nTruthy values:");
truthyValues.forEach(val => {
    console.log(`  ${String(val)}: ${Boolean(val)}`);
});

// Logical operations with booleans
console.log("\nLogical operations:");
console.log("true && true:", true && true); // true
console.log("true && false:", true && false); // false
console.log("true || false:", true || false); // true
console.log("!true:", !true); // false
console.log("!false:", !false); // true

// Short-circuit evaluation
console.log("\nShort-circuiting:");
const result1 = 5 && 10; // Returns 10
const result2 = 0 || 42; // Returns 42
console.log("5 && 10:", result1);
console.log("0 || 42:", result2);

// Comparisons that return boolean
console.log("\nComparisons:");
console.log("5 > 3:", 5 > 3); // true
console.log("5 === 5:", 5 === 5); // true
console.log("'hello' === 'world':", "hello" === "world"); // false
console.log("10 !== 20:", 10 !== 20); // true
```

**Output:**
```
True: true boolean
False: false boolean
Boolean(0): false
Boolean(1): true
Boolean(''): false
Boolean('hello'): true
Boolean(null): false
Boolean(undefined): false
Boolean({}): true
Boolean([]): true

Falsy values:
  false: false
  0: false
  -0: false
  : false
  null: false
  undefined: false
  NaN: false

Truthy values:
  true: true
  1: true
  -1: true
  hello: true
  : true
  [object Object]: true
  function (){}: true

Logical operations:
true && true: true
true && false: false
true || false: true
!true: false
!false: true

Short-circuiting:
5 && 10: 10
0 || 42: 42

Comparisons:
5 > 3: true
5 === 5: true
'hello' === 'world': false
10 !== 20: true
```

### Example 4: Undefined and Null
```javascript
// Undefined - variable declared but not assigned
let unassigned;
console.log("Undefined variable:", unassigned, typeof unassigned);
// Output: Undefined variable: undefined undefined

// Explicitly setting undefined
const explicitUndefined = undefined;
console.log("Explicit undefined:", explicitUndefined, typeof explicitUndefined);
// Output: Explicit undefined: undefined undefined

// Null - intentionally empty value
const nullValue = null;
console.log("Null value:", nullValue, typeof nullValue);
// Output: Null value: null object (typeof null returns "object" - bug)

// Differences between undefined and null
console.log("\nComparisons:");
console.log("undefined == null:", undefined == null); // true
console.log("undefined === null:", undefined === null); // false
console.log("undefined == undefined:", undefined == undefined); // true
console.log("null == null:", null == null); // true

// Common scenarios where undefined appears
console.log("\nUndefined scenarios:");
const obj = {};
console.log("Missing property:", obj.missing); // undefined

function noReturn() {}
console.log("Function without return:", noReturn()); // undefined

const [a, b, c] = [1, 2];
console.log("Missing array element:", c); // undefined

// Null in practice
function findUser(id) {
    // Returns null if user not found
    if (id === 999) {
        return null;
    }
    return { id, name: "User" };
}

const user1 = findUser(1);
const user2 = findUser(999);
console.log("\nNull in practice:");
console.log("User1:", user1); // { id: 1, name: 'User' }
console.log("User2:", user2); // null

// Checking for undefined and null
const value1 = null;
const value2 = undefined;
const value3 = "Hello";

console.log("\nChecking for nullish values:");
console.log("value1 == null:", value1 == null); // true
console.log("value2 == null:", value2 == null); // true
console.log("value3 == null:", value3 == null); // false

// Nullish coalescing operator
console.log("\nNullish coalescing:");
const defaultValue = value1 ?? "Default"; // Uses default
console.log("value1 ?? 'Default':", defaultValue);
const value4 = "Hello";
const result3 = value4 ?? "Default"; // Returns "Hello"
console.log("value4 ?? 'Default':", result3);
```

**Output:**
```
Undefined variable: undefined undefined
Explicit undefined: undefined undefined
Null value: null object

Comparisons:
undefined == null: true
undefined === null: false
undefined == undefined: true
null == null: true

Undefined scenarios:
Missing property: undefined
Function without return: undefined
Missing array element: undefined

Null in practice:
User1: { id: 1, name: 'User' }
User2: null

Checking for nullish values:
value1 == null: true
value2 == null: true
value3 == null: false

Nullish coalescing:
value1 ?? 'Default': Default
value4 ?? 'Default': Hello
```

### Example 5: Symbol Type (ES6)
```javascript
// Creating symbols
const sym1 = Symbol();
const sym2 = Symbol("description");
const sym3 = Symbol("description");

console.log("Symbol:", sym1, typeof sym1);
console.log("Symbol with description:", sym2);
console.log("Symbols are unique:", sym2 === sym3); // false

// Symbol properties
console.log("Symbol description:", sym2.description); // "description"

// Symbols as object keys
const sym = Symbol("id");
const obj2 = {
    [sym]: "12345",
    name: "John"
};

console.log("\nSymbol as object key:");
console.log("Object:", obj2);
console.log("Access via symbol:", obj2[sym]);
console.log("Access via string:", obj2["id"]); // undefined

// Symbols are not enumerable in for...in
for (const key in obj2) {
    console.log("Enumeration:", key); // Only "name"
}

// Getting symbol properties
console.log("Symbol properties:", Object.getOwnPropertySymbols(obj2)); // [Symbol(id)]
console.log("All keys:", Reflect.ownKeys(obj2)); // ["name", Symbol(id)]

// Well-known symbols
console.log("\nWell-known symbols:");
console.log("Symbol.iterator:", Symbol.iterator);
console.log("Symbol.toStringTag:", Symbol.toStringTag);
console.log("Symbol.hasInstance:", Symbol.hasInstance);

// Using Symbol.iterator for custom iteration
class MyCollection {
    constructor() {
        this.items = [1, 2, 3];
    }
    
    [Symbol.iterator]() {
        let index = 0;
        const items = this.items;
        return {
            next() {
                if (index < items.length) {
                    return { value: items[index++], done: false };
                }
                return { done: true };
            }
        };
    }
}

const collection = new MyCollection();
console.log("\nCustom iteration:");
for (const item of collection) {
    console.log("Item:", item);
}

// Global symbol registry
const globalSym1 = Symbol.for("app.id");
const globalSym2 = Symbol.for("app.id");
console.log("\nGlobal symbols:");
console.log("Same global symbol:", globalSym1 === globalSym2); // true
console.log("Symbol key:", Symbol.keyFor(globalSym1)); // "app.id"
```

**Output:**
```
Symbol: Symbol() symbol
Symbol with description: Symbol(description)
Symbols are unique: false
Symbol description: description

Symbol as object key:
Object: { name: 'John', [Symbol(id)]: '12345' }
Access via symbol: 12345
Access via string: undefined
Enumeration: name
Symbol properties: [ Symbol(id) ]
All keys: [ 'name', Symbol(id) ]

Well-known symbols:
Symbol.iterator: Symbol(Symbol.iterator)
Symbol.toStringTag: Symbol(Symbol.toStringTag)
Symbol.hasInstance: Symbol(Symbol.hasInstance)

Custom iteration:
Item: 1
Item: 2
Item: 3

Global symbols:
Same global symbol: true
Symbol key: app.id
```

### Example 6: BigInt Type (ES2020)
```javascript
// Creating BigInt
const bigInt1 = 12345678901234567890n; // n suffix
const bigInt2 = BigInt("12345678901234567890");
const bigInt3 = BigInt(1234567890);

console.log("BigInt1:", bigInt1, typeof bigInt1);
console.log("BigInt2:", bigInt2);
console.log("BigInt3:", bigInt3);

// BigInt operations
const a = 10n;
const b = 3n;

console.log("\nBigInt arithmetic:");
console.log("a + b:", a + b); // 13n
console.log("a - b:", a - b); // 7n
console.log("a * b:", a * b); // 30n
console.log("a / b:", a / b); // 3n (integer division)
console.log("a % b:", a % b); // 1n
console.log("a ** b:", a ** b); // 1000n

// Comparisons
console.log("\nBigInt comparisons:");
console.log("10n > 5n:", 10n > 5n); // true
console.log("10n === 10n:", 10n === 10n); // true
console.log("10n == 10:", 10n == 10); // true (loose equality)
console.log("10n === 10:", 10n === 10); // false (strict equality)

// Mixed operations (Number and BigInt)
console.log("\nMixed operations:");
try {
    console.log("10n + 5:", 10n + 5);
} catch (error) {
    console.log("Error:", error.message); // Cannot mix BigInt and Number
}

// Converting between BigInt and Number
const num1 = Number(10n);
const bigInt4 = BigInt(10);
console.log("Number from BigInt:", num1);
console.log("BigInt from Number:", bigInt4);

// Math operations with BigInt
console.log("\nMath with BigInt:");
console.log("BigInt.max:", a > b ? a : b);
console.log("BigInt.abs:", a - b > 0 ? a - b : b - a);

// Using BigInt for large numbers
const maxSafeInt = Number.MAX_SAFE_INTEGER;
console.log("MAX_SAFE_INTEGER:", maxSafeInt);
console.log("Exceed safe:", maxSafeInt + 1); // Precision loss!
console.log("BigInt safe:", BigInt(maxSafeInt) + 1n); // Precise

// BigInt in practical scenarios
const largeNumber = 123456789012345678901234567890n;
console.log("\nLarge number operations:");
console.log("Large + 1000n:", largeNumber + 1000n);
console.log("Large * 2n:", largeNumber * 2n);
console.log("Large % 1000n:", largeNumber % 1000n);
```

**Output:**
```
BigInt1: 12345678901234567890n bigint
BigInt2: 12345678901234567890n
BigInt3: 1234567890n

BigInt arithmetic:
a + b: 13n
a - b: 7n
a * b: 30n
a / b: 3n
a % b: 1n
a ** b: 1000n

BigInt comparisons:
10n > 5n: true
10n === 10n: true
10n == 10: true
10n === 10: false

Mixed operations:
Error: Cannot mix BigInt and other types, use explicit conversions

Number from BigInt: 10
BigInt from Number: 10n

Math with BigInt:
BigInt.max: 10n
BigInt.abs: 7n
MAX_SAFE_INTEGER: 9007199254740991
Exceed safe: 9007199254740992
BigInt safe: 9007199254740992n

Large number operations:
Large + 1000n: 123456789012345678901234568890n
Large * 2n: 246913578024691357802469135780n
Large % 1000n: 890n
```

### Example 7: Object Type
```javascript
// Creating objects
const obj1 = {}; // Object literal
const obj2 = new Object(); // Constructor
const obj3 = Object.create(null); // No prototype

console.log("Object literals:", obj1, typeof obj1);

// Object properties
const user = {
    name: "Alice",
    age: 30,
    "full name": "Alice Johnson",
    greet() {
        return `Hello, I'm ${this.name}`;
    }
};

console.log("\nObject properties:");
console.log("Name:", user.name);
console.log("Full name:", user["full name"]);
console.log("Age:", user.age);
console.log("Greet:", user.greet());

// Adding and modifying properties
user.email = "alice@example.com";
user.age = 31;
console.log("\nModified object:", user);

// Deleting properties
delete user["full name"];
console.log("After deletion:", user);

// Checking properties
console.log("\nProperty checks:");
console.log("'name' in user:", "name" in user); // true
console.log("'address' in user:", "address" in user); // false
console.log("user.hasOwnProperty('name'):", user.hasOwnProperty("name")); // true
console.log("user.hasOwnProperty('toString'):", user.hasOwnProperty("toString")); // false

// Object methods
console.log("\nObject methods:");
console.log("Object.keys:", Object.keys(user)); // ["name", "age", "email", "greet"]
console.log("Object.values:", Object.values(user)); // ["Alice", 31, "alice@example.com", function]
console.log("Object.entries:", Object.entries(user));

// Object copying
const original = { a: 1, b: { c: 2 } };
const shallowCopy = { ...original };
const deepCopy = JSON.parse(JSON.stringify(original));

console.log("\nObject copying:");
console.log("Original:", original);
console.log("Shallow copy:", shallowCopy);
console.log("Deep copy:", deepCopy);

// Modifying copies
shallowCopy.b.c = 42;
deepCopy.b.c = 100;
console.log("After modifications:");
console.log("Original:", original); // { a: 1, b: { c: 42 } }
console.log("Shallow copy:", shallowCopy); // { a: 1, b: { c: 42 } }
console.log("Deep copy:", deepCopy); // { a: 1, b: { c: 100 } }

// Object freezing
const frozen = Object.freeze({ value: 42 });
try {
    frozen.value = 100;
} catch (error) {
    console.log("Cannot modify frozen object");
}
console.log("Frozen object:", frozen.value); // 42

// Object sealing
const sealed = Object.seal({ value: 42 });
sealed.value = 100; // Allowed
try {
    sealed.newProp = "new";
} catch (error) {
    console.log("Cannot add properties to sealed object");
}
console.log("Sealed object:", sealed); // { value: 100 }

// Getters and Setters
const person = {
    _name: "John",
    get name() {
        return this._name;
    },
    set name(value) {
        if (value && value.length > 0) {
            this._name = value;
        } else {
            console.log("Invalid name");
        }
    }
};

console.log("\nGetters/Setters:");
console.log("Get name:", person.name);
person.name = "Jane";
console.log("Set name:", person.name);
person.name = ""; // Invalid name
```

**Output:**
```
Object literals: {} object

Object properties:
Name: Alice
Full name: Alice Johnson
Age: 30
Greet: Hello, I'm Alice

Modified object: { name: 'Alice', age: 31, 'full name': 'Alice Johnson', email: 'alice@example.com', greet: [Function: greet] }
After deletion: { name: 'Alice', age: 31, email: 'alice@example.com', greet: [Function: greet] }

Property checks:
'name' in user: true
'address' in user: false
user.hasOwnProperty('name'): true
user.hasOwnProperty('toString'): false

Object methods:
Object.keys: [ 'name', 'age', 'email', 'greet' ]
Object.values: [ 'Alice', 31, 'alice@example.com', [Function: greet] ]
Object.entries: [ [ 'name', 'Alice' ], [ 'age', 31 ], [ 'email', 'alice@example.com' ], [ 'greet', [Function: greet] ] ]

Object copying:
Original: { a: 1, b: { c: 2 } }
Shallow copy: { a: 1, b: { c: 2 } }
Deep copy: { a: 1, b: { c: 2 } }
After modifications:
Original: { a: 1, b: { c: 42 } }
Shallow copy: { a: 1, b: { c: 42 } }
Deep copy: { a: 1, b: { c: 100 } }
Cannot modify frozen object
Frozen object: 42
Sealed object: { value: 100 }

Getters/Setters:
Get name: John
Set name: Jane
Invalid name
```

### Example 8: Array Type
```javascript
// Creating arrays
const arr1 = [1, 2, 3]; // Array literal
const arr2 = new Array(1, 2, 3); // Constructor
const arr3 = new Array(5); // Creates array of length 5 (empty slots)
const arr4 = Array.from("hello"); // ['h', 'e', 'l', 'l', 'o']
const arr5 = Array.of(1, 2, 3); // [1, 2, 3]

console.log("Array types:");
console.log("arr1:", arr1, typeof arr1);
console.log("arr2:", arr2);
console.log("arr3:", arr3);
console.log("arr4:", arr4);
console.log("arr5:", arr5);

// Array properties
const fruits = ["apple", "banana", "orange"];
console.log("\nArray properties:");
console.log("Length:", fruits.length); // 3
console.log("First element:", fruits[0]); // apple
console.log("Last element:", fruits[fruits.length - 1]); // orange

// Array methods - Mutating
console.log("\nMutating methods:");
fruits.push("grape"); // Add to end
console.log("push('grape'):", fruits); // ["apple", "banana", "orange", "grape"]

fruits.pop(); // Remove from end
console.log("pop():", fruits); // ["apple", "banana", "orange"]

fruits.unshift("kiwi"); // Add to beginning
console.log("unshift('kiwi'):", fruits); // ["kiwi", "apple", "banana", "orange"]

fruits.shift(); // Remove from beginning
console.log("shift():", fruits); // ["apple", "banana", "orange"]

fruits.splice(1, 1, "mango"); // Replace at index 1
console.log("splice(1, 1, 'mango'):", fruits); // ["apple", "mango", "orange"]

fruits.splice(2, 0, "grape", "melon"); // Insert at index 2
console.log("splice(2, 0, 'grape', 'melon'):", fruits); // ["apple", "mango", "grape", "melon", "orange"]

// Array methods - Non-mutating
console.log("\nNon-mutating methods:");
const numbers = [3, 1, 4, 1, 5];
console.log("slice(1, 4):", numbers.slice(1, 4)); // [1, 4, 1]
console.log("concat([9, 2]):", numbers.concat([9, 2])); // [3, 1, 4, 1, 5, 9, 2]

// Iteration methods
console.log("\nIteration methods:");
const doubled = numbers.map(n => n * 2);
console.log("map(n => n * 2):", doubled); // [6, 2, 8, 2, 10]

const even = numbers.filter(n => n % 2 === 0);
console.log("filter(n => n % 2 === 0):", even); // [4]

const sum = numbers.reduce((acc, n) => acc + n, 0);
console.log("reduce((acc, n) => acc + n, 0):", sum); // 14

const found = numbers.find(n => n > 3);
console.log("find(n => n > 3):", found); // 4

const includes = numbers.includes(1);
console.log("includes(1):", includes); // true

// Sorting
console.log("\nSorting:");
const unsorted = [5, 2, 9, 1, 5, 6];
console.log("Unsorted:", unsorted);
console.log("Default sort:", [...unsorted].sort()); // [1, 2, 5, 5, 6, 9]
console.log("Numeric sort:", [...unsorted].sort((a, b) => a - b)); // [1, 2, 5, 5, 6, 9]
console.log("Descending sort:", [...unsorted].sort((a, b) => b - a)); // [9, 6, 5, 5, 2, 1]

// Spread operator with arrays
const arr10 = [1, 2, 3];
const arr11 = [4, 5, 6];
const combined = [...arr10, ...arr11];
console.log("\nSpread operator:", combined); // [1, 2, 3, 4, 5, 6]

// Destructuring arrays
const [first, second, ...rest] = combined;
console.log("Destructuring:", first, second, rest); // 1, 2, [3, 4, 5, 6]

// Array-like objects to arrays
function toArray() {
    return Array.from(arguments);
}
console.log("Array.from arguments:", toArray(1, 2, 3)); // [1, 2, 3]
console.log("Array.from NodeList:", Array.from(document.querySelectorAll('div'))); // []

// Sparse arrays
const sparse = [1, , , 4];
console.log("\nSparse array:", sparse);
console.log("Length:", sparse.length); // 4
console.log("Has index 1:", 1 in sparse); // false
```

**Output:**
```
Array types:
arr1: [ 1, 2, 3 ] object
arr2: [ 1, 2, 3 ]
arr3: [ <5 empty items> ]
arr4: [ 'h', 'e', 'l', 'l', 'o' ]
arr5: [ 1, 2, 3 ]

Array properties:
Length: 3
First element: apple
Last element: orange

Mutating methods:
push('grape'): [ 'apple', 'banana', 'orange', 'grape' ]
pop(): [ 'apple', 'banana', 'orange' ]
unshift('kiwi'): [ 'kiwi', 'apple', 'banana', 'orange' ]
shift(): [ 'apple', 'banana', 'orange' ]
splice(1, 1, 'mango'): [ 'apple', 'mango', 'orange' ]
splice(2, 0, 'grape', 'melon'): [ 'apple', 'mango', 'grape', 'melon', 'orange' ]

Non-mutating methods:
slice(1, 4): [ 1, 4, 1 ]
concat([9, 2]): [ 3, 1, 4, 1, 5, 9, 2 ]

Iteration methods:
map(n => n * 2): [ 6, 2, 8, 2, 10 ]
filter(n => n % 2 === 0): [ 4 ]
reduce((acc, n) => acc + n, 0): 14
find(n => n > 3): 4
includes(1): true

Sorting:
Unsorted: [ 5, 2, 9, 1, 5, 6 ]
Default sort: [ 1, 2, 5, 5, 6, 9 ]
Numeric sort: [ 1, 2, 5, 5, 6, 9 ]
Descending sort: [ 9, 6, 5, 5, 2, 1 ]

Spread operator: [ 1, 2, 3, 4, 5, 6 ]
Destructuring: 1 2 [ 3, 4, 5, 6 ]
Array.from arguments: [ 1, 2, 3 ]
Array.from NodeList: []

Sparse array: [ 1, <2 empty items>, 4 ]
Length: 4
Has index 1: false
```

## Explanation of Examples

### Example 1: Number Type
- **Number encompasses all numeric types**: integers, floating-point, special values
- **Methods like `toFixed()`** format numbers for display
- **`parseInt()` and `parseFloat()`** convert strings to numbers
- **Special values**: `NaN` (Not-a-Number), `Infinity`, `-Infinity`
- **Safe integer range**: numbers between `-(2^53 - 1)` and `2^53 - 1` are safe

### Example 2: String Type
- **Strings are immutable**: methods return new strings
- **Template literals** with backticks allow interpolation and multiline
- **String methods** provide powerful manipulation capabilities
- **Escape sequences** represent special characters
- **`padStart()`/`padEnd()`** useful for formatting

### Example 3: Boolean Type
- **Only two values**: `true` and `false`
- **Truthy/Falsy**: Many values evaluate to `true`/`false` in boolean contexts
- **Falsy values**: `false`, `0`, `""`, `null`, `undefined`, `NaN`
- **Short-circuit evaluation**: `&&` and `||` return one of the operands

### Example 4: Undefined and Null
- **Undefined**: Unintentional missing value, default for uninitialized variables
- **Null**: Intentional absence of a value
- **Difference**: Type check reveals `undefined` vs `null` (typeof null returns "object")
- **Equality**: `null == undefined` is `true`, but `===` is `false`
- **Nullish coalescing (`??`)**: Only responds to `null` and `undefined`

### Example 5: Symbol Type
- **Unique and immutable**: Every symbol is unique
- **Can have descriptions**: For debugging purposes
- **Object keys**: Symbols create non-enumerable properties
- **Well-known symbols**: Customize JavaScript behavior
- **Global registry**: Share symbols across different realms

### Example 6: BigInt Type
- **Handles arbitrarily large integers**: Beyond Number.MAX_SAFE_INTEGER
- **Cannot mix with Number**: Must convert explicitly
- **`n` suffix**: Literal notation for BigInt
- **Integer-only operations**: Division truncates toward zero
- **Precision**: Guaranteed accuracy for all integers

### Example 7: Object Type
- **Collection of key-value pairs**: Properties can be accessed via dot or bracket notation
- **Methods**: Functions as property values
- **Object operations**: Add, modify, delete properties
- **Copying**: Shallow vs deep copy
- **Protection**: `Object.freeze()` and `Object.seal()`
- **Getters/Setters**: Dynamic property access control

### Example 8: Array Type
- **Ordered list**: Elements accessed by index
- **Mutating vs non-mutating methods**: Some modify array, others return new array
- **Iteration methods**: `map()`, `filter()`, `reduce()`, etc.
- **Spread operator**: Concise array manipulation
- **Destructuring**: Extract elements into variables
- **Sparse arrays**: Arrays with empty slots

## Important Notes

### Best Practices 📝
1. **Use strict equality (`===`)** to avoid type coercion bugs
2. **Check for `null` and `undefined`** using `== null` or `??`
3. **Use `Number.isNaN()`** instead of global `isNaN()`
4. **Use `const` for values** that won't be reassigned
5. **Use descriptive variable names** that imply type
6. **Use `Array.isArray()`** to check if variable is an array
7. **Use template literals** for string concatenation
8. **Prefer `Object.is()`** for `NaN` comparisons

### Things to Remember 💡
- `typeof null` returns `"object"` (historical bug)
- Arrays are objects (type `"object"`)
- `NaN` is never equal to anything, including itself
- `undefined` is a type, `null` is an object (technically)
- Primitive types are immutable, reference types are mutable
- Strings are iterable (can use `for...of`)
- Objects are compared by reference, not value
- `Symbol()` creates unique values, `Symbol.for()` creates shared values

### Type Conversion Table

| From Type | To Boolean | To String | To Number |
|-----------|------------|-----------|-----------|
| `undefined` | `false` | `"undefined"` | `NaN` |
| `null` | `false` | `"null"` | `0` |
| `true` | `true` | `"true"` | `1` |
| `false` | `false` | `"false"` | `0` |
| `0` | `false` | `"0"` | `0` |
| `1` | `true` | `"1"` | `1` |
| `""` | `false` | `""` | `0` |
| `"0"` | `true` | `"0"` | `0` |
| `"42"` | `true` | `"42"` | `42` |
| `{}` | `true` | `"[object Object]"` | `NaN` |
| `[]` | `true` | `""` | `0` |
| `[1]` | `true` | `"1"` | `1` |

## Common Mistakes

### Mistake 1: Confusing `null` and `undefined`
```javascript
// ❌ Bad - treating them as the same
let user = null;
if (user === undefined) { // false
    console.log("User not found");
}

// ✅ Good - explicit check
let user = null;
if (user == null) { // true (checks both null and undefined)
    console.log("User not found");
}

// ✅ Better - use nullish coalescing
const name = user ?? "Guest";
```

### Mistake 2: Using `==` Instead of `===`
```javascript
// ❌ Bad - type coercion
console.log(0 == false); // true
console.log("" == false); // true
console.log(null == undefined); // true

// ✅ Good - strict equality
console.log(0 === false); // false
console.log("" === false); // false
console.log(null === undefined); // false
```

### Mistake 3: Not Handling `NaN`
```javascript
// ❌ Bad - NaN comparisons fail
const result = 0 / 0;
if (result === NaN) { // false (always)
    console.log("Got NaN");
}

// ✅ Good - use Number.isNaN()
if (Number.isNaN(result)) {
    console.log("Got NaN");
}

// ✅ Also works with Object.is()
if (Object.is(result, NaN)) {
    console.log("Got NaN");
}
```

### Mistake 4: Assuming Arrays are Primitive
```javascript
// ❌ Bad - comparing arrays
const arrA = [1, 2, 3];
const arrB = [1, 2, 3];
if (arrA === arrB) { // false (different references)
    console.log("Arrays are equal");
}

// ✅ Good - compare content
const arrC = [1, 2, 3];
const arrD = [1, 2, 3];
if (arrC.length === arrD.length && arrC.every((v, i) => v === arrD[i])) {
    console.log("Arrays are equal");
}

// ✅ Or use JSON.stringify
if (JSON.stringify(arrC) === JSON.stringify(arrD)) {
    console.log("Arrays are equal");
}
```

### Mistake 5: Modifying Objects Assigned with `const`
```javascript
// ❌ Bad - thinking const prevents mutation
const person = { name: "John" };
person.name = "Jane"; // This works! (const only prevents reassignment)
console.log(person.name); // "Jane"

// ✅ Good - freeze to prevent mutation
const person = Object.freeze({ name: "John" });
try {
    person.name = "Jane"; // Fails in strict mode
} catch (e) {
    console.log("Cannot mutate frozen object");
}
```

### Mistake 6: Type Coercion in Arithmetic
```javascript
// ❌ Bad - unexpected results
console.log("2" + 2); // "22" (string concatenation)
console.log("2" - 2); // 0 (numeric subtraction)
console.log("2" * 2); // 4 (numeric multiplication)

// ✅ Good - explicit conversion
console.log(Number("2") + 2); // 4
console.log("2" + String(2)); // "22"
```

### Mistake 7: Using `typeof` for Arrays
```javascript
// ❌ Bad - typeof doesn't distinguish arrays
const arr = [1, 2, 3];
console.log(typeof arr); // "object"

// ✅ Good - use Array.isArray()
console.log(Array.isArray(arr)); // true
```

### Mistake 8: Forgetting BigInt and Number Can't Mix
```javascript
// ❌ Bad - TypeError
const big = 10n;
const num = 5;
// console.log(big + num); // TypeError

// ✅ Good - explicit conversion
console.log(big + BigInt(num)); // 15n
console.log(Number(big) + num); // 15
```

## Interview Questions

1. **What are the primitive data types in JavaScript?**  
   *Answer: Primitive types are immutable data types: Number, String, Boolean, Undefined, Null, Symbol (ES6), and BigInt (ES2020). They are stored directly in memory and are compared by value.*

2. **What's the difference between `null` and `undefined`?**  
   *Answer: `undefined` means a variable has been declared but not assigned a value. `null` is an intentional assignment value representing "nothing" or "empty". `typeof null` returns "object" (bug), while `typeof undefined` returns "undefined".*

3. **Why is `typeof null` "object" in JavaScript?**  
   *Answer: This is a historical bug in JavaScript that dates back to its creation. In the original implementation, values were represented as 32-bit words, and null was represented as a null pointer (all bits zero), which was categorized as an object in the type tagging system.*

4. **What is the difference between primitive and reference types?**  
   *Answer: Primitive types are immutable and stored directly in memory (stack). Reference types (objects, arrays, functions) are mutable and stored in heap memory, with variables holding a reference to the actual data. Primitive types are compared by value, reference types by reference.*

5. **Explain truthy and falsy values in JavaScript.**  
   *Answer: Falsy values are values that evaluate to `false` in boolean contexts: `false`, `0`, `-0`, `0n`, `""`, `null`, `undefined`, `NaN`. Everything else is truthy, including empty arrays `[]`, empty objects `{}`, and strings like `"0"` or `"false"`.*

6. **What is type coercion and when does it happen?**  
   *Answer: Type coercion is automatic or implicit conversion of values from one type to another. It happens in operations like `==` (loose equality), arithmetic with strings, and when using non-boolean values in logical contexts. Use `===` to avoid unwanted coercion.*

7. **How do you check if a variable is an array?**  
   *Answer: Use `Array.isArray(variable)` which is the most reliable method. `variable instanceof Array` also works but can fail across different frames/windows. Avoid `typeof` as it returns "object" for arrays.*

8. **What are Symbols and why are they useful?**  
   *Answer: Symbols are unique and immutable primitive values introduced in ES6. They're useful for creating non-enumerable object properties, avoiding property name collisions, and implementing well-known protocols (like `Symbol.iterator` for iteration).*

9. **When would you use BigInt instead of Number?**  
   *Answer: Use BigInt when dealing with integers larger than `Number.MAX_SAFE_INTEGER` (9e15) where precision matters. BigInt provides exact integer arithmetic for arbitrarily large numbers, while Number operations can lose precision for very large integers.*

10. **What is the difference between `Object.is()` and `===`?**  
    *Answer: `Object.is()` is similar to `===` but handles edge cases differently. It treats `NaN` as equal to `NaN` (unlike `===`), and `-0` and `+0` as unequal (unlike `===`). Use `Object.is()` for more mathematically precise comparisons.*

## Practice Exercises

### Easy Exercise ✨
**Task**: Write a function that takes a value and returns a string description of its type, handling edge cases like `null`, `NaN`, and arrays correctly.

<details>
<summary>Solution</summary>

```javascript
function getType(value) {
    // Handle null separately (typeof bug)
    if (value === null) {
        return "null";
    }
    
    // Handle arrays
    if (Array.isArray(value)) {
        return "array";
    }
    
    // Handle NaN (typeof returns "number")
    if (typeof value === "number" && Number.isNaN(value)) {
        return "NaN";
    }
    
    // Handle all other types
    return typeof value;
}

// Test
console.log(getType(42)); // "number"
console.log(getType("hello")); // "string"
console.log(getType(true)); // "boolean"
console.log(getType(undefined)); // "undefined"
console.log(getType(null)); // "null"
console.log(getType({})); // "object"
console.log(getType([])); // "array"
console.log(getType(NaN)); // "NaN"
console.log(getType(Symbol())); // "symbol"
console.log(getType(10n)); // "bigint"
console.log(getType(() => {})); // "function"
```
</details>

### Medium Exercise 📘
**Task**: Create a deep equality checker that works for:
1. Primitive values
2. Arrays
3. Objects (including nested)
4. Handles special cases (NaN, null, undefined)

<details>
<summary>Solution</summary>

```javascript
function deepEqual(a, b) {
    // Check for strict equality first
    if (a === b) {
        // Handle NaN case (NaN !== NaN)
        return !Number.isNaN(a) && !Number.isNaN(b);
    }
    
    // Handle NaN specifically
    if (Number.isNaN(a) && Number.isNaN(b)) {
        return true;
    }
    
    // Check if either is null or not object
    if (a === null || b === null || typeof a !== "object" || typeof b !== "object") {
        return false;
    }
    
    // Handle arrays
    if (Array.isArray(a) && Array.isArray(b)) {
        if (a.length !== b.length) {
            return false;
        }
        for (let i = 0; i < a.length; i++) {
            if (!deepEqual(a[i], b[i])) {
                return false;
            }
        }
        return true;
    }
    
    // Handle one array, one not
    if (Array.isArray(a) !== Array.isArray(b)) {
        return false;
    }
    
    // Handle objects
    const keysA = Object.keys(a);
    const keysB = Object.keys(b);
    
    if (keysA.length !== keysB.length) {
        return false;
    }
    
    for (const key of keysA) {
        if (!keysB.includes(key)) {
            return false;
        }
        if (!deepEqual(a[key], b[key])) {
            return false;
        }
    }
    
    return true;
}

// Test
const test1 = deepEqual(42, 42); // true
const test2 = deepEqual(42, "42"); // false
const test3 = deepEqual(NaN, NaN); // true
const test4 = deepEqual([1, 2, 3], [1, 2, 3]); // true
const test5 = deepEqual([1, 2, 3], [1, 2, 3, 4]); // false
const test6 = deepEqual({ a: 1, b: { c: 2 } }, { a: 1, b: { c: 2 } }); // true
const test7 = deepEqual({ a: 1, b: { c: 2 } }, { a: 1, b: { c: 3 } }); // false
const test8 = deepEqual(null, null); // true
const test9 = deepEqual(undefined, undefined); // true
const test10 = deepEqual(null, undefined); // false

console.log({
    test1, test2, test3, test4, test5,
    test6, test7, test8, test9, test10
});
```
</details>

### Challenge Exercise 💪
**Task**: Build a type-safe data validation library that:
1. Validates primitive types (number, string, boolean, etc.)
2. Validates complex types (arrays, objects)
3. Supports nested validation schemas
4. Provides detailed error messages
5. Handles optional fields with defaults

<details>
<summary>Solution</summary>

```javascript
class Validator {
    constructor() {
        this.errors = [];
    }
    
    validate(value, schema) {
        this.errors = [];
        this._validate(value, schema, "value");
        return {
            valid: this.errors.length === 0,
            errors: this.errors
        };
    }
    
    _validate(value, schema, path) {
        // Handle schema as a type string
        if (typeof schema === "string") {
            return this._validatePrimitive(value, schema, path);
        }
        
        // Handle array schemas
        if (Array.isArray(schema) && schema.length === 1) {
            return this._validateArray(value, schema[0], path);
        }
        
        // Handle object schemas
        if (typeof schema === "object" && schema !== null) {
            return this._validateObject(value, schema, path);
        }
        
        this.errors.push(`Invalid schema: ${schema}`);
    }
    
    _validatePrimitive(value, type, path) {
        const typeMap = {
            number: "number",
            string: "string",
            boolean: "boolean",
            undefined: "undefined",
            object: "object",
            function: "function",
            symbol: "symbol",
            bigint: "bigint",
            nan: "nan",
            null: "null"
        };
        
        // Special handling for NaN
        if (type === "nan") {
            if (!Number.isNaN(value)) {
                this.errors.push(`${path} must be NaN, got ${value}`);
            }
            return;
        }
        
        // Special handling for null
        if (type === "null") {
            if (value !== null) {
                this.errors.push(`${path} must be null, got ${value}`);
            }
            return;
        }
        
        // Type checking
        if (typeof value !== typeMap[type]) {
            this.errors.push(`${path} must be ${type}, got ${typeof value}`);
        }
    }
    
    _validateArray(value, itemSchema, path) {
        if (!Array.isArray(value)) {
            this.errors.push(`${path} must be an array, got ${typeof value}`);
            return;
        }
        
        value.forEach((item, index) => {
            const itemPath = `${path}[${index}]`;
            this._validate(item, itemSchema, itemPath);
        });
    }
    
    _validateObject(value, schema, path) {
        if (typeof value !== "object" || value === null || Array.isArray(value)) {
            this.errors.push(`${path} must be an object, got ${typeof value}`);
            return;
        }
        
        // Validate required fields
        for (const [key, rules] of Object.entries(schema)) {
            const fieldPath = `${path}.${key}`;
            
            // Check if field is optional
            if (rules.optional && !(key in value)) {
                continue;
            }
            
            // Check if field exists
            if (!(key in value) && !rules.default) {
                this.errors.push(`${fieldPath} is required`);
                continue;
            }
            
            // Get value (with default if provided)
            const fieldValue = key in value ? value[key] : rules.default;
            
            // Validate based on schema
            if (rules.type) {
                this._validate(fieldValue, rules.type, fieldPath);
            }
            
            // Check custom validator
            if (rules.validate && typeof rules.validate === "function") {
                if (!rules.validate(fieldValue)) {
                    this.errors.push(`${fieldPath} failed custom validation`);
                }
            }
        }
        
        // Check for unexpected fields (optional)
        for (const key of Object.keys(value)) {
            if (!(key in schema)) {
                this.errors.push(`${path}.${key} is not allowed`);
            }
        }
    }
}

// Usage
const validator = new Validator();

// Schema definition
const userSchema = {
    id: {
        type: "number",
        validate: (v) => v > 0
    },
    name: {
        type: "string",
        validate: (v) => v.length > 2
    },
    age: {
        type: "number",
        optional: true,
        default: 18
    },
    email: {
        type: "string",
        validate: (v) => /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(v)
    },
    tags: {
        type: ["string"],
        optional: true
    },
    profile: {
        type: {
            bio: { type: "string", optional: true },
            location: { type: "string" }
        },
        optional: true
    }
};

// Test cases
const testCases = [
    {
        id: 1,
        name: "John Doe",
        email: "john@example.com",
        tags: ["developer", "javascript"],
        profile: {
            location: "New York"
        }
    },
    {
        id: -1, // Invalid
        name: "J", // Invalid
        email: "invalid-email", // Invalid
        profile: {
            location: "London"
        }
    },
    {
        id: 3,
        name: "Alice Smith",
        email: "alice@example.com",
        extra: "field" // Unexpected field
    }
];

testCases.forEach((data, index) => {
    console.log(`\n📋 Test Case ${index + 1}:`);
    const result = validator.validate(data, userSchema);
    if (result.valid) {
        console.log("✅ Data is valid");
    } else {
        console.log("❌ Data is invalid:");
        result.errors.forEach(error => {
            console.log(`  - ${error}`);
        });
    }
});

// Advanced validation with custom types
const advancedSchema = {
    config: {
        type: {
            timeout: {
                type: "number",
                validate: (v) => v > 0
            },
            retries: {
                type: "number",
                optional: true,
                default: 3
            },
            flags: {
                type: ["string"],
                optional: true,
                validate: (v) => v.every(f => f.startsWith("--"))
            }
        }
    }
};

const advancedData = {
    config: {
        timeout: 5000,
        flags: ["--verbose", "--debug"]
    }
};

console.log("\n🔍 Advanced Validation:");
const advancedResult = validator.validate(advancedData, advancedSchema);
if (advancedResult.valid) {
    console.log("✅ Advanced data is valid");
} else {
    console.log("❌ Advanced data is invalid:");
    advancedResult.errors.forEach(error => {
        console.log(`  - ${error}`);
    });
}
```
</details>

## Summary

### Key Takeaways 📌

#### Primitives (Immutable)
- **Number**: All numeric values (`42`, `3.14`, `NaN`, `Infinity`)
- **String**: Text data (`"Hello"`, `'World'`, `` `Template` ``)
- **Boolean**: Logical values (`true`, `false`)
- **Undefined**: Uninitialized value
- **Null**: Intentional absence
- **Symbol**: Unique identifiers (ES6)
- **BigInt**: Large integers (ES2020)

#### Reference Types (Mutable)
- **Object**: Key-value collections
- **Array**: Ordered lists (special object)
- **Function**: Callable objects (special object)
- **Date**, **RegExp**, **Map**, **Set**, etc.

#### Key Principles
```
✅ Use === for comparison (not ==)
✅ Check for null/undefined with ?? or == null
✅ Use Number.isNaN() not global isNaN()
✅ Use Array.isArray() not typeof for arrays
✅ Use Object.is() for NaN comparisons
✅ Be aware of type coercion
✅ Understand truthy/falsy values
✅ Use appropriate type for the task
```

### Quick Reference Card 🎯

| Type | typeof | Constructor | Example |
|------|--------|-------------|---------|
| Number | `"number"` | Number | `42`, `3.14` |
| String | `"string"` | String | `"Hello"` |
| Boolean | `"boolean"` | Boolean | `true` |
| Undefined | `"undefined"` | - | `undefined` |
| Null | `"object"` | - | `null` |
| Symbol | `"symbol"` | Symbol | `Symbol()` |
| BigInt | `"bigint"` | BigInt | `42n` |
| Object | `"object"` | Object | `{}`, `[]`, `function` |

### Common Type Checks
```javascript
// Number
typeof value === "number" && !Number.isNaN(value)

// String
typeof value === "string"

// Boolean
typeof value === "boolean"

// Array
Array.isArray(value)

// Null
value === null

// Undefined
typeof value === "undefined"

// NaN
Number.isNaN(value)

// Object (excluding null)
typeof value === "object" && value !== null && !Array.isArray(value)

// Function
typeof value === "function"

// Symbol
typeof value === "symbol"

// BigInt
typeof value === "bigint"
```

### Type Conversion Functions
```javascript
// To Number
Number(value)     // Explicit
parseInt(str)     // Parse integer
parseFloat(str)   // Parse float
+value           // Unary plus

// To String
String(value)     // Explicit
value.toString()  // Method
'' + value        // Concatenation

// To Boolean
Boolean(value)    // Explicit
!!value           // Double NOT
```

**Understanding JavaScript data types is fundamental to writing reliable, bug-free code!** 🚀
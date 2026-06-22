# JavaScript Functions

## Overview

**Functions** in JavaScript are reusable blocks of code that perform specific tasks. They are first-class objects, meaning they can be assigned to variables, passed as arguments, and returned from other functions. Functions are the building blocks of JavaScript applications, enabling code organization, reusability, and abstraction.

### Why Functions are Important 🎯
- **Code Reusability**: Write once, use multiple times
- **Modularity**: Break complex problems into smaller, manageable pieces
- **Abstraction**: Hide complex implementation details
- **Organization**: Structure code logically and maintainably
- **Encapsulation**: Create private scopes and avoid global namespace pollution
- **Event Handling**: Respond to user interactions and asynchronous events

## Key Concepts

### Types of Functions

#### 1. Function Declarations
- Hoisted to the top of their scope
- Named functions for debugging
- Can be called before declaration

#### 2. Function Expressions
- Not hoisted (can't be called before definition)
- Assigned to variables
- Anonymous or named

#### 3. Arrow Functions (ES6)
- Concise syntax with `=>`
- No `this` binding (lexical `this`)
- Cannot be used as constructors

#### 4. Anonymous Functions
- Functions without a name
- Used as callbacks or IIFEs

#### 5. Immediately Invoked Function Expressions (IIFE)
- Executed immediately after creation
- Creates a new scope

### Function Components

- **Name**: Identifier for the function (optional in expressions)
- **Parameters**: Input values (optional)
- **Body**: Code to execute
- **Return Value**: Output (default `undefined`)
- **Scope**: Lexical environment where variables are accessible

### Function Hoisting
- Function declarations are hoisted completely (both name and body)
- Function expressions are not hoisted (only variable declaration)

## Syntax

### Function Declaration
```javascript
function functionName(parameters) {
    // Function body
    return value; // Optional
}
```

### Function Expression
```javascript
const functionName = function(parameters) {
    // Function body
    return value;
};
```

### Arrow Function
```javascript
// Basic syntax
const functionName = (parameters) => {
    // Function body
    return value;
};

// Concise (single expression, implicit return)
const functionName = (parameters) => value;

// Single parameter (parentheses optional)
const square = x => x * x;
```

### IIFE
```javascript
(function() {
    // Function body
})();

// Arrow IIFE
(() => {
    // Function body
})();
```

## Examples

### Example 1: Function Declarations
```javascript
// Basic function declaration
function greet(name) {
    return `Hello, ${name}!`;
}

console.log(greet("Alice"));
// Output: Hello, Alice!

// Function with multiple parameters
function add(a, b) {
    return a + b;
}

console.log("Sum:", add(5, 3));
// Output: Sum: 8

// Function with default parameters (ES6)
function createUser(name = "Guest", age = 18) {
    return {
        name: name,
        age: age
    };
}

console.log("Default user:", createUser());
console.log("Custom user:", createUser("John", 25));
// Output: Default user: { name: 'Guest', age: 18 }
// Output: Custom user: { name: 'John', age: 25 }

// Function with rest parameters
function sumAll(...numbers) {
    return numbers.reduce((total, num) => total + num, 0);
}

console.log("Sum all:", sumAll(1, 2, 3, 4, 5));
// Output: Sum all: 15

// Function with destructuring
function displayUser({ name, age, city = "Unknown" }) {
    console.log(`Name: ${name}, Age: ${age}, City: ${city}`);
}

const user = { name: "Sarah", age: 28, city: "New York" };
displayUser(user);
// Output: Name: Sarah, Age: 28, City: New York

// Function returning a function (closure)
function multiplier(factor) {
    return function(number) {
        return number * factor;
    };
}

const double = multiplier(2);
const triple = multiplier(3);
console.log("Double:", double(10)); // 20
console.log("Triple:", triple(10)); // 30

// Function with optional arguments
function greetUser(firstName, lastName) {
    if (lastName) {
        return `Hello, ${firstName} ${lastName}!`;
    }
    return `Hello, ${firstName}!`;
}

console.log(greetUser("John")); // Hello, John!
console.log(greetUser("John", "Doe")); // Hello, John Doe!

// Hoisting example
console.log(hoistedFunction(5)); // Works
function hoistedFunction(x) {
    return x * 2;
}
```

**Output:**
```
Hello, Alice!
Sum: 8
Default user: { name: 'Guest', age: 18 }
Custom user: { name: 'John', age: 25 }
Sum all: 15
Name: Sarah, Age: 28, City: New York
Double: 20
Triple: 30
Hello, John!
Hello, John Doe!
10
```

### Example 2: Function Expressions
```javascript
// Basic function expression
const multiply = function(a, b) {
    return a * b;
};

console.log("Multiply:", multiply(4, 5));
// Output: Multiply: 20

// Named function expression (better stack traces)
const factorial = function fact(n) {
    return n <= 1 ? 1 : n * fact(n - 1);
};

console.log("Factorial 5:", factorial(5));
// Output: Factorial 5: 120

// Function expression as callback
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.map(function(num) {
    return num * 2;
});
console.log("Doubled:", doubled);
// Output: Doubled: [2, 4, 6, 8, 10]

// Function expression for event handlers
const button = document.createElement('button');
button.onclick = function() {
    console.log('Button clicked!');
};

// Function expression with closure
const counter = (function() {
    let count = 0;
    return function() {
        count++;
        return count;
    };
})();

console.log(counter()); // 1
console.log(counter()); // 2
console.log(counter()); // 3

// Function expression with dynamic behavior
const operations = {
    add: function(a, b) { return a + b; },
    subtract: function(a, b) { return a - b; },
    multiply: function(a, b) { return a * b; },
    divide: function(a, b) { return a / b; }
};

console.log("Add:", operations.add(10, 5)); // 15
console.log("Multiply:", operations.multiply(10, 5)); // 50

// Self-invoking function expression (IIFE)
(function() {
    const privateVar = "I'm private";
    console.log("IIFE executed, private:", privateVar);
})();
// Output: IIFE executed, private: I'm private

// Function expression with conditional definition
let operation;
if (true) {
    operation = function(a, b) {
        return a + b;
    };
} else {
    operation = function(a, b) {
        return a - b;
    };
}
console.log("Conditional operation:", operation(10, 5));
// Output: Conditional operation: 15
```

**Output:**
```
Multiply: 20
Factorial 5: 120
Doubled: [2, 4, 6, 8, 10]
1
2
3
Add: 15
Multiply: 50
IIFE executed, private: I'm private
Conditional operation: 15
```

### Example 3: Arrow Functions
```javascript
// Basic arrow function
const greet2 = (name) => {
    return `Hello, ${name}!`;
};
console.log(greet2("Bob"));
// Output: Hello, Bob!

// Single parameter (parentheses optional)
const square = x => x * x;
console.log("Square:", square(5));
// Output: Square: 25

// Multiple parameters
const add2 = (a, b) => a + b;
console.log("Add:", add2(3, 4));
// Output: Add: 7

// No parameters
const getRandom = () => Math.random();
console.log("Random:", getRandom());
// Output: Random: 0.123456789

// Returning object literal (wrap in parentheses)
const createPerson = (name, age) => ({ name, age });
console.log("Person:", createPerson("Alice", 30));
// Output: Person: { name: 'Alice', age: 30 }

// Arrow function with rest parameters
const multiplyAll = (...numbers) => numbers.reduce((product, n) => product * n, 1);
console.log("Multiply all:", multiplyAll(2, 3, 4));
// Output: Multiply all: 24

// Arrow function in array methods
const numbers2 = [1, 2, 3, 4, 5];
const evenNumbers = numbers2.filter(n => n % 2 === 0);
console.log("Even numbers:", evenNumbers); // [2, 4]
const doubled2 = numbers2.map(n => n * 2);
console.log("Doubled:", doubled2); // [2, 4, 6, 8, 10]

// Arrow function as callback
setTimeout(() => {
    console.log("Delayed execution");
}, 1000);

// Arrow function with destructuring
const users = [
    { name: "John", age: 25 },
    { name: "Jane", age: 30 }
];
const names = users.map(({ name }) => name);
console.log("Names:", names); // ['John', 'Jane']

// Arrow function with lexical 'this'
class Counter {
    constructor() {
        this.count = 0;
        // Arrow function preserves 'this' from parent scope
        this.increment = () => {
            this.count++;
            console.log("Count:", this.count);
        };
    }
}

const counter2 = new Counter();
counter2.increment(); // Count: 1
counter2.increment(); // Count: 2

// Arrow function in promise chain
const fetchData = () => {
    return Promise.resolve("Data received")
        .then(data => data.toUpperCase())
        .then(processed => console.log(processed));
};
fetchData();
// Output: DATA RECEIVED
```

**Output:**
```
Hello, Bob!
Square: 25
Add: 7
Random: 0.123456789
Person: { name: 'Alice', age: 30 }
Multiply all: 24
Even numbers: [ 2, 4 ]
Doubled: [ 2, 4, 6, 8, 10 ]
Names: [ 'John', 'Jane' ]
Count: 1
Count: 2
DATA RECEIVED
```

### Example 4: Closures
```javascript
// Basic closure
function outerFunction(outerValue) {
    return function innerFunction(innerValue) {
        return outerValue + innerValue;
    };
}

const addTen = outerFunction(10);
console.log(addTen(5)); // 15
console.log(addTen(20)); // 30

// Closure with private variables
function createCounter() {
    let count = 0;
    
    return {
        increment: function() {
            count++;
            return count;
        },
        decrement: function() {
            count--;
            return count;
        },
        getCount: function() {
            return count;
        },
        reset: function() {
            count = 0;
            return count;
        }
    };
}

const counter3 = createCounter();
console.log("Count:", counter3.getCount()); // 0
console.log("Increment:", counter3.increment()); // 1
console.log("Increment:", counter3.increment()); // 2
console.log("Decrement:", counter3.decrement()); // 1
console.log("Reset:", counter3.reset()); // 0

// Closure for memorization (caching)
function memoize(fn) {
    const cache = {};
    
    return function(...args) {
        const key = JSON.stringify(args);
        if (cache[key] !== undefined) {
            console.log("Cache hit for:", args);
            return cache[key];
        }
        
        console.log("Cache miss for:", args);
        const result = fn(...args);
        cache[key] = result;
        return result;
    };
}

function expensiveCalculation(x, y) {
    console.log("Performing expensive calculation...");
    return x * y + x + y;
}

const memoizedCalc = memoize(expensiveCalculation);
console.log("Result 1:", memoizedCalc(5, 10));
console.log("Result 2:", memoizedCalc(5, 10));
console.log("Result 3:", memoizedCalc(5, 10));

// Closure for event handlers with captured variables
function createButtonHandler(message) {
    return function() {
        console.log(`Button clicked: ${message}`);
    };
}

const button1Handler = createButtonHandler("Save");
const button2Handler = createButtonHandler("Delete");

// Function factory with closure
function multiplier2(factor) {
    return function(number) {
        return number * factor;
    };
}

const double2 = multiplier2(2);
const triple2 = multiplier2(3);
const quadruple = multiplier2(4);

console.log("Double 5:", double2(5)); // 10
console.log("Triple 5:", triple2(5)); // 15
console.log("Quadruple 5:", quadruple(5)); // 20

// Module pattern using closure
const UserModule = (function() {
    // Private variables
    let users = [];
    
    // Private functions
    function validateUser(user) {
        return user && user.name && user.age > 0;
    }
    
    // Public API
    return {
        addUser: function(user) {
            if (validateUser(user)) {
                users.push(user);
                return true;
            }
            return false;
        },
        getUsers: function() {
            return [...users]; // Return copy
        },
        getUserCount: function() {
            return users.length;
        },
        removeUser: function(name) {
            const index = users.findIndex(u => u.name === name);
            if (index !== -1) {
                users.splice(index, 1);
                return true;
            }
            return false;
        }
    };
})();

UserModule.addUser({ name: "John", age: 25 });
UserModule.addUser({ name: "Jane", age: 30 });
console.log("Users:", UserModule.getUsers());
console.log("User count:", UserModule.getUserCount());
console.log("Remove John:", UserModule.removeUser("John"));
console.log("Users after removal:", UserModule.getUsers());
```

**Output:**
```
15
30
Count: 0
Increment: 1
Increment: 2
Decrement: 1
Reset: 0
Cache miss for: [ 5, 10 ]
Performing expensive calculation...
Result 1: 65
Cache hit for: [ 5, 10 ]
Result 2: 65
Cache hit for: [ 5, 10 ]
Result 3: 65
Double 5: 10
Triple 5: 15
Quadruple 5: 20
Users: [ { name: 'John', age: 25 }, { name: 'Jane', age: 30 } ]
User count: 2
Remove John: true
Users after removal: [ { name: 'Jane', age: 30 } ]
```

### Example 5: Callback Functions
```javascript
// Basic callback
function processUserInput(name, callback) {
    console.log(`Processing user: ${name}`);
    callback(name);
}

processUserInput("Alice", function(user) {
    console.log(`Hello, ${user}!`);
});

// Callback with error handling
function fetchData(callback) {
    const success = Math.random() > 0.3;
    setTimeout(() => {
        if (success) {
            callback(null, { data: "Important data" });
        } else {
            callback("Error: Failed to fetch data", null);
        }
    }, 1000);
}

fetchData((error, result) => {
    if (error) {
        console.log("Error:", error);
    } else {
        console.log("Success:", result);
    }
});

// Array iteration callbacks
const numbers3 = [1, 2, 3, 4, 5];

// forEach
numbers3.forEach((num, index) => {
    console.log(`Index ${index}: ${num}`);
});

// sort with custom comparator
const unsorted = [5, 2, 8, 1, 9];
unsorted.sort((a, b) => a - b);
console.log("Sorted:", unsorted);

// Custom callback for filtering
function filterArray(arr, predicate) {
    const result = [];
    for (const item of arr) {
        if (predicate(item)) {
            result.push(item);
        }
    }
    return result;
}

const evens = filterArray(numbers3, n => n % 2 === 0);
console.log("Evens:", evens);

// Callback for DOM events (simulated)
class EventEmitter {
    constructor() {
        this.events = {};
    }
    
    on(event, callback) {
        if (!this.events[event]) {
            this.events[event] = [];
        }
        this.events[event].push(callback);
    }
    
    emit(event, data) {
        if (this.events[event]) {
            this.events[event].forEach(callback => callback(data));
        }
    }
}

const emitter = new EventEmitter();
emitter.on("userLogin", (user) => {
    console.log(`User logged in: ${user.name}`);
});
emitter.on("userLogin", (user) => {
    console.log(`Welcome back, ${user.name}!`);
});
emitter.emit("userLogin", { name: "John" });

// Async callback with setTimeout
function delayedGreeting(name, callback) {
    setTimeout(() => {
        callback(`Hello, ${name}! (delayed)`);
    }, 500);
}

delayedGreeting("Bob", (message) => {
    console.log(message);
});

// Callback hell (nested callbacks)
function step1(callback) {
    setTimeout(() => callback("Step 1 done"), 100);
}
function step2(callback) {
    setTimeout(() => callback("Step 2 done"), 100);
}
function step3(callback) {
    setTimeout(() => callback("Step 3 done"), 100);
}

// Classic callback hell
step1((result1) => {
    console.log(result1);
    step2((result2) => {
        console.log(result2);
        step3((result3) => {
            console.log(result3);
            console.log("All steps completed!");
        });
    });
});
```

**Output:**
```
Processing user: Alice
Hello, Alice!
Error: Error: Failed to fetch data
Index 0: 1
Index 1: 2
Index 2: 3
Index 3: 4
Index 4: 5
Sorted: [ 1, 2, 5, 8, 9 ]
Evens: [ 2, 4 ]
User logged in: John
Welcome back, John!
Hello, Bob! (delayed)
Step 1 done
Step 2 done
Step 3 done
All steps completed!
```

### Example 6: Generator Functions
```javascript
// Basic generator
function* countGenerator() {
    yield 1;
    yield 2;
    yield 3;
}

const counter4 = countGenerator();
console.log(counter4.next()); // { value: 1, done: false }
console.log(counter4.next()); // { value: 2, done: false }
console.log(counter4.next()); // { value: 3, done: false }
console.log(counter4.next()); // { value: undefined, done: true }

// Generator with infinite sequence
function* infiniteSequence() {
    let i = 0;
    while (true) {
        yield i++;
    }
}

const infinite = infiniteSequence();
console.log(infinite.next().value); // 0
console.log(infinite.next().value); // 1
console.log(infinite.next().value); // 2

// Generator for custom iteration
function* range(start, end, step = 1) {
    for (let i = start; i <= end; i += step) {
        yield i;
    }
}

for (const num of range(1, 10, 2)) {
    console.log(num); // 1, 3, 5, 7, 9
}

// Generator with data transformation
function* fibonacci() {
    let a = 0, b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

const fib = fibonacci();
const first10Fib = [];
for (let i = 0; i < 10; i++) {
    first10Fib.push(fib.next().value);
}
console.log("First 10 Fibonacci:", first10Fib);

// Generator with input
function* calculator() {
    const a = yield "Enter first number";
    const b = yield "Enter second number";
    const operation = yield "Enter operation (+, -, *, /)";
    
    if (operation === "+") return a + b;
    if (operation === "-") return a - b;
    if (operation === "*") return a * b;
    if (operation === "/") return a / b;
    return "Invalid operation";
}

const calc = calculator();
console.log(calc.next()); // { value: 'Enter first number', done: false }
console.log(calc.next(10)); // { value: 'Enter second number', done: false }
console.log(calc.next(5)); // { value: 'Enter operation (+, -, *, /)', done: false }
console.log(calc.next('+')); // { value: 15, done: true }

// Generator delegation
function* generateNumbers() {
    yield* [1, 2, 3];
    yield* range(4, 6);
    yield 7;
}

const numbers4 = [...generateNumbers()];
console.log("All numbers:", numbers4); // [1, 2, 3, 4, 5, 6, 7]

// Async generator (ES2018)
async function* asyncRange(start, end) {
    for (let i = start; i <= end; i++) {
        await new Promise(resolve => setTimeout(resolve, 100));
        yield i;
    }
}

async function runAsyncGenerator() {
    for await (const num of asyncRange(1, 5)) {
        console.log("Async number:", num);
    }
}
runAsyncGenerator();
```

**Output:**
```
{ value: 1, done: false }
{ value: 2, done: false }
{ value: 3, done: false }
{ value: undefined, done: true }
0
1
2
1
3
5
7
9
First 10 Fibonacci: [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ]
{ value: 'Enter first number', done: false }
{ value: 'Enter second number', done: false }
{ value: 'Enter operation (+, -, *, /)', done: false }
{ value: 15, done: true }
All numbers: [ 1, 2, 3, 4, 5, 6, 7 ]
Async number: 1
Async number: 2
Async number: 3
Async number: 4
Async number: 5
```

### Example 7: Higher-Order Functions
```javascript
// Function that returns a function
function createLogger(prefix) {
    return function(message) {
        console.log(`[${prefix}] ${message}`);
    };
}

const infoLogger = createLogger("INFO");
const errorLogger = createLogger("ERROR");

infoLogger("Application started");
errorLogger("Failed to connect to database");

// Function that takes a function as argument
function applyOperation(a, b, operation) {
    return operation(a, b);
}

const result1 = applyOperation(10, 5, (x, y) => x + y);
const result2 = applyOperation(10, 5, (x, y) => x * y);
console.log("Result 1:", result1); // 15
console.log("Result 2:", result2); // 50

// Function composition
function compose(...functions) {
    return function(input) {
        return functions.reduceRight((value, fn) => fn(value), input);
    };
}

const add5 = x => x + 5;
const multiplyBy2 = x => x * 2;
const subtract3 = x => x - 3;

const composed = compose(add5, multiplyBy2, subtract3);
console.log(composed(10)); // (10 - 3) * 2 + 5 = 19

// Currying
function curryAdd(a) {
    return function(b) {
        return function(c) {
            return a + b + c;
        };
    };
}

const add3Numbers = curryAdd(1)(2)(3);
console.log("Curry add:", add3Numbers); // 6

// Partial application
function partial(fn, ...args) {
    return function(...remainingArgs) {
        return fn(...args, ...remainingArgs);
    };
}

function greet3(greeting, name, punctuation) {
    return `${greeting}, ${name}${punctuation}`;
}

const sayHello = partial(greet3, "Hello");
const sayGoodbye = partial(greet3, "Goodbye");

console.log(sayHello("Alice", "!")); // Hello, Alice!
console.log(sayGoodbye("Bob", ".")); // Goodbye, Bob.

// Function with side effects
function createCounterWithEffects(initial) {
    let count = initial;
    const history = [];
    
    return {
        increment: function() {
            count++;
            history.push(`Incremented to ${count}`);
            return count;
        },
        decrement: function() {
            count--;
            history.push(`Decremented to ${count}`);
            return count;
        },
        getHistory: function() {
            return [...history];
        },
        getCount: function() {
            return count;
        }
    };
}

const counter5 = createCounterWithEffects(5);
counter5.increment();
counter5.increment();
counter5.decrement();
console.log("History:", counter5.getHistory());
console.log("Current count:", counter5.getCount());

// Memoization with higher-order function
function memoize2(fn) {
    const cache = new Map();
    
    return function(...args) {
        const key = JSON.stringify(args);
        if (cache.has(key)) {
            return cache.get(key);
        }
        
        const result = fn(...args);
        cache.set(key, result);
        return result;
    };
}

const factorial2 = memoize2(function(n) {
    console.log(`Computing factorial of ${n}`);
    return n <= 1 ? 1 : n * factorial2(n - 1);
});

console.log("Factorial 5:", factorial2(5));
console.log("Factorial 5 (cached):", factorial2(5));
console.log("Factorial 6:", factorial2(6));
```

**Output:**
```
[INFO] Application started
[ERROR] Failed to connect to database
Result 1: 15
Result 2: 50
19
Curry add: 6
Hello, Alice!
Goodbye, Bob.
History: [ 'Incremented to 6', 'Incremented to 7', 'Decremented to 6' ]
Current count: 6
Computing factorial of 5
Computing factorial of 4
Computing factorial of 3
Computing factorial of 2
Computing factorial of 1
Factorial 5: 120
Factorial 5 (cached): 120
Computing factorial of 6
Factorial 6: 720
```

## Explanation of Examples

### Example 1: Function Declarations
- **Basic declaration**: Named functions with `function` keyword
- **Default parameters**: Provide fallback values for omitted arguments
- **Rest parameters**: Collect all remaining arguments into an array
- **Destructuring**: Extract values from objects in parameters
- **Returning functions**: Functions can return other functions (closures)
- **Hoisting**: Function declarations are moved to the top of scope

### Example 2: Function Expressions
- **Assignment to variables**: Functions as first-class citizens
- **Named expressions**: Better debugging stack traces
- **Callbacks**: Functions as arguments to other functions
- **IIFE**: Immediately invoked function expressions
- **Conditional definition**: Define functions based on conditions

### Example 3: Arrow Functions
- **Concise syntax**: `=>` for simpler functions
- **Implicit return**: Single expression returns automatically
- **Lexical `this`**: Arrow functions don't bind their own `this`
- **No `arguments` object**: Use rest parameters instead
- **Cannot be constructors**: No `new` keyword with arrow functions

### Example 4: Closures
- **Access to outer scope**: Functions remember their lexical environment
- **Private variables**: Create private state using closures
- **Memoization**: Cache results for performance
- **Module pattern**: Encapsulate private data and expose public API
- **Function factories**: Create functions with specific behavior

### Example 5: Callback Functions
- **Asynchronous handling**: Pass functions to be called later
- **Error-first callbacks**: Standard pattern for Node.js
- **Array methods**: `forEach`, `map`, `filter` use callbacks
- **Event handling**: Callbacks respond to events
- **Callback hell**: Nested callbacks become unmanageable

### Example 6: Generator Functions
- **Yield keyword**: Pause and resume function execution
- **Iterable sequences**: Create custom iterables
- **Infinite sequences**: Generate unlimited values lazily
- **Two-way communication**: Send values back into generator
- **Async generators**: Yield promises (ES2018)

### Example 7: Higher-Order Functions
- **Function returning functions**: Create specialized functions
- **Function composition**: Combine multiple functions
- **Currying**: Transform multi-argument functions
- **Partial application**: Fix some arguments, return new function
- **Memoization**: Cache results of expensive computations

## Important Notes

### Best Practices 📝
1. **Use `const` for function expressions**: Prevents accidental reassignment
2. **Name functions for debugging**: Use named functions in stacks
3. **Prefer arrow functions for callbacks**: Cleaner syntax and lexical `this`
4. **Use default parameters**: Safer than checking `undefined`
5. **Use rest parameters**: Better than `arguments` object
6. **Avoid side effects**: Functions should be predictable
7. **Single responsibility**: Each function should do one thing
8. **Descriptive names**: Function names should clearly indicate purpose
9. **Document complex functions**: Use JSDoc comments
10. **Consider using generators for sequences**: Cleaner than manual state management

### Things to Remember 💡
- Functions are first-class objects in JavaScript
- Function declarations are hoisted, expressions are not
- Arrow functions have lexical `this` and no `arguments`
- Default parameters evaluated at call time
- Rest parameter must be last parameter
- Closures capture variables by reference, not value
- Generators use `function*` syntax and `yield`
- All functions return `undefined` by default
- Functions can have methods (call, apply, bind)
- Constructor functions use `new` keyword

### Function Comparison Table

| Feature | Declaration | Expression | Arrow | Generator |
|---------|-------------|------------|-------|-----------|
| Hoisting | ✅ Yes | ❌ No | ❌ No | ✅ Yes |
| `this` binding | Dynamic | Dynamic | Lexical | Dynamic |
| `arguments` | ✅ Yes | ✅ Yes | ❌ No | ❌ No |
| Constructor | ✅ Yes | ✅ Yes | ❌ No | ❌ No |
| `new` keyword | ✅ Yes | ✅ Yes | ❌ No | ❌ No |
| Named/Anonymous | Named | Both | Anonymous | Named |
| Syntax | `function fn(){}` | `const fn = function(){}` | `const fn = () => {}` | `function* fn(){}` |

## Common Mistakes

### Mistake 1: Not Returning a Value
```javascript
// ❌ Bad - implicit undefined return
function add(a, b) {
    a + b; // No return statement
}
console.log(add(5, 3)); // undefined

// ✅ Good - explicit return
function add(a, b) {
    return a + b;
}
console.log(add(5, 3)); // 8
```

### Mistake 2: Arrow Function with `this`
```javascript
// ❌ Bad - using arrow function as method
const obj = {
    name: "Object",
    getName: () => this.name // Lexical `this` (global/window)
};
console.log(obj.getName()); // undefined

// ✅ Good - use function expression
const obj2 = {
    name: "Object",
    getName: function() { return this.name; }
};
console.log(obj2.getName()); // "Object"

// ✅ Also works with method shorthand
const obj3 = {
    name: "Object",
    getName() { return this.name; }
};
console.log(obj3.getName()); // "Object"
```

### Mistake 3: Forgetting `new` with Constructors
```javascript
// ❌ Bad - using constructor without new
function Person(name) {
    this.name = name;
}
const person = Person("John"); // this = global/window
console.log(person); // undefined
console.log(window.name); // "John" (in browser)

// ✅ Good - use new
const person = new Person("John");
console.log(person.name); // "John"

// ✅ Better - use class
class Person {
    constructor(name) {
        this.name = name;
    }
}
const person = new Person("John");
console.log(person.name); // "John"
```

### Mistake 4: Callback Hell
```javascript
// ❌ Bad - nested callbacks
asyncOperation1((result1) => {
    asyncOperation2(result1, (result2) => {
        asyncOperation3(result2, (result3) => {
            asyncOperation4(result3, (result4) => {
                console.log("Final:", result4);
            });
        });
    });
});

// ✅ Good - use promises
asyncOperation1()
    .then(asyncOperation2)
    .then(asyncOperation3)
    .then(asyncOperation4)
    .then(result => console.log("Final:", result));

// ✅ Better - use async/await
async function process() {
    const result1 = await asyncOperation1();
    const result2 = await asyncOperation2(result1);
    const result3 = await asyncOperation3(result2);
    const result4 = await asyncOperation4(result3);
    console.log("Final:", result4);
}
```

### Mistake 5: Using `var` in Loops with Callbacks
```javascript
// ❌ Bad - captures the same variable
for (var i = 0; i < 3; i++) {
    setTimeout(function() {
        console.log(i); // 3, 3, 3
    }, 100);
}

// ✅ Good - use let (block scope)
for (let i = 0; i < 3; i++) {
    setTimeout(function() {
        console.log(i); // 0, 1, 2
    }, 100);
}

// ✅ Also works with closure
for (var i = 0; i < 3; i++) {
    (function(j) {
        setTimeout(function() {
            console.log(j); // 0, 1, 2
        }, 100);
    })(i);
}
```

### Mistake 6: Modifying `arguments` Object
```javascript
// ❌ Bad - arguments is array-like, not an array
function sum() {
    // Arguments is not a real array
    return arguments.reduce((acc, val) => acc + val, 0); // Error
}
console.log(sum(1, 2, 3));

// ✅ Good - convert to array
function sum() {
    const args = Array.from(arguments);
    return args.reduce((acc, val) => acc + val, 0);
}
console.log(sum(1, 2, 3)); // 6

// ✅ Better - use rest parameters
function sum(...numbers) {
    return numbers.reduce((acc, val) => acc + val, 0);
}
console.log(sum(1, 2, 3)); // 6
```

### Mistake 7: Returning Object Literal from Arrow Function
```javascript
// ❌ Bad - ambiguous curly braces
const createUser = (name) => { name: name, age: 30 }; // SyntaxError

// ✅ Good - wrap in parentheses
const createUser = (name) => ({ name: name, age: 30 });
console.log(createUser("John")); // { name: 'John', age: 30 }
```

## Interview Questions

1. **What's the difference between function declaration and function expression?**  
   *Answer: Function declarations are hoisted (can be called before definition), while function expressions are not. Function declarations are named, while expressions can be anonymous or named. Declarations are processed before code execution, expressions are processed during execution.*

2. **What is a closure and how does it work?**  
   *Answer: A closure is a function that remembers its lexical scope even when executed outside that scope. It works because inner functions maintain a reference to their outer environment, allowing access to variables even after the outer function has returned. Closures enable private variables, function factories, and module patterns.*

3. **How do arrow functions differ from regular functions?**  
   *Answer: Arrow functions have lexical `this` binding (inherit from parent scope), cannot be used as constructors with `new`, don't have `arguments` object, cannot use `super`, and have concise syntax with implicit return for single expressions. They're best suited for callbacks and scenarios where `this` should be preserved.*

4. **What is the difference between `call`, `apply`, and `bind`?**  
   *Answer: `call` and `apply` invoke a function immediately with a specified `this` value and arguments (`call` takes arguments separately, `apply` takes an array). `bind` returns a new function with a bound `this` value and optional arguments, which can be called later.*

5. **What is a higher-order function?**  
   *Answer: A higher-order function is a function that takes one or more functions as arguments, returns a function, or both. Examples include `map`, `filter`, `reduce`, and function composition functions. They enable functional programming patterns and code abstraction.*

6. **What are generator functions and when would you use them?**  
   *Answer: Generator functions (defined with `function*`) can be paused and resumed using `yield`. They return iterators with `next()`. Use them for lazy evaluation, infinite sequences, custom iteration, handling asynchronous flows, and creating state machines.*

7. **How does `this` binding work in different function types?**  
   *Answer: Regular functions have dynamic `this` binding based on how they're called (implicit, explicit with call/apply/bind, or global). Arrow functions have lexical `this` that's determined by the surrounding scope. Class methods use `this` referring to the class instance.*

8. **What is function currying and why is it useful?**  
   *Answer: Currying transforms a function that takes multiple arguments into a sequence of functions each taking a single argument. It's useful for partial application, function composition, and creating specialized functions from general ones.*

9. **Explain the module pattern using closures.**  
   *Answer: The module pattern uses closures to create private variables and expose a public API. An IIFE returns an object with methods that have access to private data through closure. This provides encapsulation, prevents global namespace pollution, and enables module-like organization.*

10. **What are default parameters and rest parameters?**  
    *Answer: Default parameters allow specifying default values for function parameters when omitted or `undefined`. Rest parameters (`...args`) collect all remaining arguments into an array. Both were introduced in ES6 and provide cleaner ways to handle optional arguments and variable-length argument lists.*

## Practice Exercises

### Easy Exercise ✨
**Task**: Write a function that:
1. Takes a string and returns the string reversed
2. Uses arrow function syntax
3. Handles edge cases (empty string, null, undefined)

<details>
<summary>Solution</summary>

```javascript
const reverseString = (str) => {
    // Handle edge cases
    if (str === null || str === undefined) {
        return "";
    }
    if (typeof str !== "string") {
        str = String(str);
    }
    return str.split("").reverse().join("");
};

// Test
console.log(reverseString("hello")); // "olleh"
console.log(reverseString("JavaScript")); // "tpircSavaJ"
console.log(reverseString("")); // ""
console.log(reverseString(null)); // ""
console.log(reverseString(12345)); // "54321"
```
</details>

### Medium Exercise 📘
**Task**: Create a function that:
1. Takes an array and a callback function
2. Processes each element through the callback
3. Returns a new array with results
4. Implements the functionality of `map` manually
5. Handles edge cases and uses closure

<details>
<summary>Solution</summary>

```javascript
function customMap(arr, callback) {
    // Validate inputs
    if (!Array.isArray(arr)) {
        throw new TypeError("First argument must be an array");
    }
    if (typeof callback !== "function") {
        throw new TypeError("Second argument must be a function");
    }
    
    // Create a new array for results
    const result = [];
    
    // Process each element
    for (let i = 0; i < arr.length; i++) {
        // Check if index exists (handle sparse arrays)
        if (i in arr) {
            // Execute callback with proper context
            const value = callback(arr[i], i, arr);
            result.push(value);
        } else {
            // Preserve sparse arrays
            result[i] = undefined;
        }
    }
    
    return result;
}

// Test with different scenarios
const numbers = [1, 2, 3, 4, 5];

// Basic usage
const doubled = customMap(numbers, num => num * 2);
console.log("Doubled:", doubled); // [2, 4, 6, 8, 10]

// With index
const indexed = customMap(numbers, (num, index) => `${index}: ${num}`);
console.log("Indexed:", indexed); // ['0: 1', '1: 2', ...]

// Sparse array
const sparse = [1, , , 4];
const sparseMapped = customMap(sparse, num => num * 2);
console.log("Sparse mapped:", sparseMapped); // [2, undefined, undefined, 8]

// Edge cases
console.log("Empty array:", customMap([], num => num * 2)); // []
console.log("String array:", customMap(["a", "b", "c"], str => str.toUpperCase())); // ['A', 'B', 'C']

// Performance test
const largeArray = Array.from({ length: 100000 }, (_, i) => i);
console.time("Custom map");
customMap(largeArray, x => x * 2);
console.timeEnd("Custom map");

console.time("Native map");
largeArray.map(x => x * 2);
console.timeEnd("Native map");
```
</details>

### Challenge Exercise 💪
**Task**: Build a functional programming utility library that:
1. Implements `map`, `filter`, `reduce`, `compose`, `pipe`
2. Uses currying for all functions
3. Implements memoization for performance
4. Supports chainable operations (like Lodash)
5. Includes comprehensive error handling

<details>
<summary>Solution</summary>

```javascript
class FunctionalUtils {
    constructor(arr = []) {
        this._data = arr;
        this._chain = false;
    }
    
    // Curried map
    static map = (fn) => (arr) => {
        if (!Array.isArray(arr)) {
            throw new TypeError("Expected array");
        }
        return arr.map((item, index) => fn(item, index, arr));
    };
    
    // Curried filter
    static filter = (predicate) => (arr) => {
        if (!Array.isArray(arr)) {
            throw new TypeError("Expected array");
        }
        return arr.filter((item, index) => predicate(item, index, arr));
    };
    
    // Curried reduce
    static reduce = (reducer, initialValue) => (arr) => {
        if (!Array.isArray(arr)) {
            throw new TypeError("Expected array");
        }
        return arr.reduce(reducer, initialValue);
    };
    
    // Curried find
    static find = (predicate) => (arr) => {
        if (!Array.isArray(arr)) {
            throw new TypeError("Expected array");
        }
        return arr.find(predicate);
    };
    
    // Curried some
    static some = (predicate) => (arr) => {
        if (!Array.isArray(arr)) {
            throw new TypeError("Expected array");
        }
        return arr.some(predicate);
    };
    
    // Curried every
    static every = (predicate) => (arr) => {
        if (!Array.isArray(arr)) {
            throw new TypeError("Expected array");
        }
        return arr.every(predicate);
    };
    
    // Function composition (right to left)
    static compose = (...fns) => {
        if (fns.length === 0) {
            throw new Error("At least one function required");
        }
        return (value) => {
            let result = value;
            for (let i = fns.length - 1; i >= 0; i--) {
                if (typeof fns[i] !== "function") {
                    throw new TypeError(`Expected function at position ${i}`);
                }
                result = fns[i](result);
            }
            return result;
        };
    };
    
    // Function pipeline (left to right)
    static pipe = (...fns) => {
        if (fns.length === 0) {
            throw new Error("At least one function required");
        }
        return (value) => {
            let result = value;
            for (let i = 0; i < fns.length; i++) {
                if (typeof fns[i] !== "function") {
                    throw new TypeError(`Expected function at position ${i}`);
                }
                result = fns[i](result);
            }
            return result;
        };
    };
    
    // Memoization
    static memoize = (fn) => {
        const cache = new Map();
        return (...args) => {
            const key = JSON.stringify(args);
            if (cache.has(key)) {
                return cache.get(key);
            }
            const result = fn(...args);
            cache.set(key, result);
            return result;
        };
    };
    
    // Chainable methods
    map(fn) {
        if (!this._chain) this._data = FunctionalUtils.map(fn)(this._data);
        else {
            const result = new FunctionalUtils(this._data);
            result._chain = true;
            result._data = FunctionalUtils.map(fn)(this._data);
            return result;
        }
        return this;
    }
    
    filter(predicate) {
        if (!this._chain) this._data = FunctionalUtils.filter(predicate)(this._data);
        else {
            const result = new FunctionalUtils(this._data);
            result._chain = true;
            result._data = FunctionalUtils.filter(predicate)(this._data);
            return result;
        }
        return this;
    }
    
    reduce(reducer, initialValue) {
        if (!this._chain) this._data = FunctionalUtils.reduce(reducer, initialValue)(this._data);
        else {
            const result = new FunctionalUtils(this._data);
            result._chain = true;
            result._data = FunctionalUtils.reduce(reducer, initialValue)(this._data);
            return result;
        }
        return this;
    }
    
    value() {
        return this._data;
    }
    
    // Chain start
    static chain(arr) {
        return new FunctionalUtils(arr);
    }
}

// Testing
const data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

// Basic usage
const even = FunctionalUtils.filter(x => x % 2 === 0);
const double = FunctionalUtils.map(x => x * 2);
const sum = FunctionalUtils.reduce((acc, val) => acc + val, 0);

const processed = FunctionalUtils.pipe(
    even,
    double,
    sum
)(data);

console.log("Processed:", processed); // 60

// Composition
const result = FunctionalUtils.compose(
    sum,
    double,
    even
)(data);

console.log("Composed:", result); // 60

// Currying
const isEven = x => x % 2 === 0;
const square = x => x * x;

const curriedResult = FunctionalUtils.pipe(
    FunctionalUtils.filter(isEven),
    FunctionalUtils.map(square),
    FunctionalUtils.reduce((acc, val) => acc + val, 0)
)(data);

console.log("Curried result:", curriedResult); // 220

// Memoization
const expensiveFn = (n) => {
    console.log(`Computing expensive operation for ${n}`);
    return n * n * n;
};

const memoizedFn = FunctionalUtils.memoize(expensiveFn);
console.log("First call:", memoizedFn(5));
console.log("Second call:", memoizedFn(5));
console.log("Third call:", memoizedFn(10));

// Chainable operations
const resultChain = FunctionalUtils.chain(data)
    .filter(x => x % 2 === 0)
    .map(x => x * 2)
    .map(x => x + 1)
    .reduce((acc, val) => acc + val, 0)
    .value();

console.log("Chain result:", resultChain); // 71

// Complex pipeline with error handling
const safeDivide = (arr) => {
    if (!Array.isArray(arr)) throw new TypeError("Expected array");
    return arr.map(x => {
        if (x === 0) return Infinity;
        return 100 / x;
    });
};

const processArray = FunctionalUtils.pipe(
    FunctionalUtils.filter(x => x > 0),
    safeDivide,
    FunctionalUtils.map(x => Math.round(x))
);

try {
    const result = processArray([10, -5, 0, 2, "invalid"]);
    console.log("Safe result:", result);
} catch (error) {
    console.log("Error caught:", error.message);
}

// Large dataset performance test
const largeData = Array.from({ length: 100000 }, (_, i) => i + 1);
console.time("Pipeline performance");
const pipelineResult = FunctionalUtils.pipe(
    FunctionalUtils.filter(x => x % 2 === 0),
    FunctionalUtils.map(x => x * 3),
    FunctionalUtils.reduce((acc, val) => acc + val, 0)
)(largeData);
console.timeEnd("Pipeline performance");
console.log("Pipeline result:", pipelineResult);

// Utility functions for common operations
const utils = {
    square: x => x * x,
    cube: x => x * x * x,
    isEven: x => x % 2 === 0,
    isOdd: x => x % 2 !== 0,
    sum: (a, b) => a + b,
    product: (a, b) => a * b,
    average: (arr) => arr.reduce((a, b) => a + b, 0) / arr.length,
    max: (arr) => Math.max(...arr),
    min: (arr) => Math.min(...arr)
};

// Advanced usage
const advancedResult = FunctionalUtils.pipe(
    FunctionalUtils.filter(utils.isEven),
    FunctionalUtils.map(utils.square),
    FunctionalUtils.reduce(utils.sum, 0)
)(data);

console.log("Advanced result:", advancedResult);
```

</details>

## Summary

### Key Takeaways 📌

#### Function Types
- **Declarations**: Hoisted, named, can be called before definition
- **Expressions**: Not hoisted, assigned to variables, anonymous or named
- **Arrow Functions**: Concise, lexical `this`, no `arguments`
- **Generators**: `function*` with `yield`, can pause and resume
- **Async Functions**: `async/await` for promises, returns Promise

#### Important Concepts
- **Closures**: Functions remember their lexical environment
- **Higher-Order Functions**: Functions that operate on other functions
- **Callbacks**: Functions passed as arguments
- **Currying**: Transform multi-argument functions
- **Composition**: Combine functions to create new functions
- **Memoization**: Cache results for performance

#### Best Practices
```
✅ Use const for function expressions
✅ Prefer arrow functions for callbacks
✅ Use default and rest parameters
✅ Avoid callback hell with promises/async
✅ Use closures for encapsulation
✅ Write pure functions when possible
✅ Document complex functions
✅ Use descriptive function names
✅ Handle edge cases and errors
✅ Test functions thoroughly
```

### Quick Reference Card 🎯

#### Function Creation
```javascript
// Declaration
function name(params) { return value; }

// Expression
const name = function(params) { return value; };

// Arrow (single expression)
const name = (params) => value;

// Arrow (multiple statements)
const name = (params) => { statements; return value; };

// Generator
function* name(params) { yield value; }

// Async
async function name(params) { return await promise; }
```

#### Function Methods
```javascript
// Call
fn.call(thisArg, arg1, arg2, ...);

// Apply
fn.apply(thisArg, [arg1, arg2, ...]);

// Bind
const boundFn = fn.bind(thisArg, arg1, arg2, ...);
```

#### Common Patterns
```javascript
// IIFE
(function() { /* code */ })();

// Module
const module = (function() {
    let private = 0;
    return { public: () => private++ };
})();

// Currying
const curry = fn => (...args) => 
    args.length >= fn.length ? fn(...args) : (...more) => curry(fn)(...args, ...more);

// Memoization
const memoize = fn => {
    const cache = new Map();
    return (...args) => {
        const key = JSON.stringify(args);
        return cache.has(key) ? cache.get(key) : cache.set(key, fn(...args)).get(key);
    };
};
```

**Functions are the heart of JavaScript - master them and you master the language!** 🚀
# JavaScript Objects

## Overview

**Objects** in JavaScript are fundamental data structures that store collections of key-value pairs. They are the building blocks of JavaScript and can represent real-world entities, data structures, and complex configurations. Objects are dynamic, meaning properties can be added, modified, or removed at runtime, making them incredibly flexible and powerful.

### Why Objects are Important 🎯
- **Data Organization**: Group related data and functionality together
- **Real-World Modeling**: Represent entities with properties and behaviors
- **Code Structure**: Organize code into meaningful units
- **Extensibility**: Dynamically add or modify properties
- **Prototypal Inheritance**: Share behavior between objects
- **JSON Compatibility**: Work seamlessly with web APIs and data exchange

## Key Concepts

### Object Fundamentals

#### Properties
- **Keys**: Strings (or Symbols) that identify values
- **Values**: Any JavaScript value (primitives, objects, functions)
- **Access**: Dot notation (`obj.prop`) or bracket notation (`obj["prop"]`)

#### Property Attributes
- **Value**: The actual value stored
- **Writable**: Whether the value can be changed
- **Enumerable**: Whether it shows up in enumeration
- **Configurable**: Whether it can be deleted or modified

#### Object Characteristics
- **Dynamic**: Properties can be added/removed at runtime
- **Mutable**: Object contents can change
- **Reference Type**: Variables hold references, not values
- **Prototype-based**: Inheritance through prototype chain

### Object Creation Methods

1. **Object Literals**: `{ key: value }`
2. **Constructor Functions**: `new Object()` or custom constructors
3. **Object.create()**: Creates objects with specified prototype
4. **Class Syntax**: `class MyClass { }`
5. **Object.assign()**: Copies properties from source objects
6. **Factory Functions**: Functions that return objects

### Prototype Chain
- Objects inherit properties from their prototype
- The prototype chain is a linked list of objects
- `__proto__` (deprecated) or `Object.getPrototypeOf()` to access

## Syntax

### Object Literal
```javascript
const obj = {
    property: value,
    method() {
        // Method body
    },
    "property with spaces": value
};
```

### Accessing Properties
```javascript
// Dot notation
obj.property;
obj.method();

// Bracket notation
obj["property"];
obj["property with spaces"];
obj[computedKey];

// Optional chaining
obj?.property;
obj?.method?.();
```

### Adding/Modifying Properties
```javascript
obj.newProperty = value;
obj["existingProperty"] = newValue;
Object.defineProperty(obj, "key", descriptor);
```

### Deleting Properties
```javascript
delete obj.property;
```

## Examples

### Example 1: Object Literals and Basic Operations
```javascript
// Creating an object literal
const person = {
    firstName: "John",
    lastName: "Doe",
    age: 30,
    email: "john@example.com",
    address: {
        street: "123 Main St",
        city: "New York",
        country: "USA"
    },
    // Method
    getFullName() {
        return `${this.firstName} ${this.lastName}`;
    },
    // Method with arrow function (not recommended for methods)
    greet: () => {
        console.log(`Hello, I'm ${person.firstName}`);
    }
};

console.log("Person object:", person);
// Output: Person object: { firstName: 'John', lastName: 'Doe', ... }

// Accessing properties
console.log("\nAccessing properties:");
console.log("First name:", person.firstName);
console.log("Last name:", person["lastName"]);
console.log("Full name:", person.getFullName());
console.log("City:", person.address.city);
console.log("Country:", person["address"]["country"]);

// Modifying properties
person.age = 31;
person.email = "john.doe@example.com";
console.log("\nAfter modification:", person.age, person.email);

// Adding new properties
person.phone = "555-1234";
person.isActive = true;
console.log("Added properties:", person.phone, person.isActive);

// Deleting properties
delete person.phone;
console.log("After deletion:", person.phone); // undefined

// Checking if property exists
console.log("\nProperty checks:");
console.log("'firstName' in person:", "firstName" in person); // true
console.log("'phone' in person:", "phone" in person); // false
console.log("person.hasOwnProperty('firstName'):", 
    person.hasOwnProperty("firstName")); // true
console.log("person.hasOwnProperty('toString'):", 
    person.hasOwnProperty("toString")); // false

// Looping through properties
console.log("\nEnumerating properties:");
for (const key in person) {
    if (person.hasOwnProperty(key)) {
        console.log(`${key}: ${person[key]}`);
    }
}

// Object.keys, values, entries
console.log("\nObject methods:");
console.log("Keys:", Object.keys(person));
console.log("Values:", Object.values(person));
console.log("Entries:", Object.entries(person));

// Descriptors
console.log("\nProperty descriptors:");
const descriptor = Object.getOwnPropertyDescriptor(person, "firstName");
console.log(descriptor);
// { value: 'John', writable: true, enumerable: true, configurable: true }

// Freezing an object
const frozen = Object.freeze({ prop: 42 });
try {
    frozen.prop = 100; // Fails silently or throws in strict mode
} catch (e) {
    console.log("Cannot modify frozen object");
}
console.log("Frozen prop:", frozen.prop); // 42
```

**Output:**
```
Person object: { firstName: 'John', lastName: 'Doe', age: 30, email: 'john@example.com', address: { street: '123 Main St', city: 'New York', country: 'USA' }, getFullName: [Function: getFullName], greet: [Function: greet] }

Accessing properties:
First name: John
Last name: Doe
Full name: John Doe
City: New York
Country: USA

After modification: 31 john.doe@example.com
Added properties: 555-1234 true
After deletion: undefined

Property checks:
'firstName' in person: true
'phone' in person: false
person.hasOwnProperty('firstName'): true
person.hasOwnProperty('toString'): false

Enumerating properties:
firstName: John
lastName: Doe
age: 31
email: john.doe@example.com
address: [object Object]
getFullName: function() {
        return `${this.firstName} ${this.lastName}`;
    }
greet: () => {
        console.log(`Hello, I'm ${person.firstName}`);
    }
isActive: true

Object methods:
Keys: [ 'firstName', 'lastName', 'age', 'email', 'address', 'getFullName', 'greet', 'isActive' ]
Values: [ 'John', 'Doe', 31, 'john.doe@example.com', { street: '123 Main St', city: 'New York', country: 'USA' }, [Function: getFullName], [Function: greet], true ]
Entries: [ [ 'firstName', 'John' ], [ 'lastName', 'Doe' ], [ 'age', 31 ], [ 'email', 'john.doe@example.com' ], [ 'address', { street: '123 Main St', city: 'New York', country: 'USA' } ], [ 'getFullName', [Function: getFullName] ], [ 'greet', [Function: greet] ], [ 'isActive', true ] ]

Property descriptors:
{ value: 'John', writable: true, enumerable: true, configurable: true }
Cannot modify frozen object
Frozen prop: 42
```

### Example 2: Object Creation Methods
```javascript
// 1. Object Literal
const obj1 = { name: "Literal" };
console.log("Object literal:", obj1);

// 2. Object Constructor
const obj2 = new Object();
obj2.name = "Constructor";
console.log("Object constructor:", obj2);

// 3. Object.create()
const prototype = {
    greet() {
        return `Hello, I'm ${this.name}`;
    }
};
const obj3 = Object.create(prototype);
obj3.name = "Object.create";
console.log("Object.create:", obj3.greet());
console.log("Prototype:", Object.getPrototypeOf(obj3));

// 4. Constructor Function
function Person(firstName, lastName) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.getFullName = function() {
        return `${this.firstName} ${this.lastName}`;
    };
}
const person1 = new Person("Alice", "Smith");
console.log("Constructor function:", person1.getFullName());

// 5. Class Syntax (ES6)
class User {
    constructor(name, email) {
        this.name = name;
        this.email = email;
    }
    
    getInfo() {
        return `${this.name} (${this.email})`;
    }
}
const user = new User("Bob", "bob@example.com");
console.log("Class syntax:", user.getInfo());

// 6. Factory Function
function createCar(make, model) {
    return {
        make,
        model,
        getDescription() {
            return `${this.make} ${this.model}`;
        }
    };
}
const car = createCar("Tesla", "Model 3");
console.log("Factory function:", car.getDescription());

// 7. Object.assign()
const defaults = { theme: "light", language: "en" };
const overrides = { theme: "dark", notifications: true };
const settings = Object.assign({}, defaults, overrides);
console.log("Object.assign:", settings);

// 8. Spread Operator (ES6)
const merged = { ...defaults, ...overrides };
console.log("Spread operator:", merged);

// Comparing creation methods
console.log("\nComparison:");
console.log("obj1 prototype:", Object.getPrototypeOf(obj1));
console.log("obj2 prototype:", Object.getPrototypeOf(obj2));
console.log("obj3 prototype:", Object.getPrototypeOf(obj3));
console.log("person1 prototype:", Object.getPrototypeOf(person1));
console.log("user prototype:", Object.getPrototypeOf(user));
console.log("car prototype:", Object.getPrototypeOf(car));
```

**Output:**
```
Object literal: { name: 'Literal' }
Object constructor: { name: 'Constructor' }
Object.create: Hello, I'm Object.create
Prototype: { greet: [Function: greet] }
Constructor function: Alice Smith
Class syntax: Bob (bob@example.com)
Factory function: Tesla Model 3
Object.assign: { theme: 'dark', language: 'en', notifications: true }
Spread operator: { theme: 'dark', language: 'en', notifications: true }

Comparison:
obj1 prototype: {}
obj2 prototype: {}
obj3 prototype: { greet: [Function: greet] }
person1 prototype: Person {}
user prototype: User {}
car prototype: {}
```

### Example 3: Property Descriptors
```javascript
// Creating object with property descriptors
const book = {};

Object.defineProperty(book, "title", {
    value: "JavaScript: The Definitive Guide",
    writable: true,
    enumerable: true,
    configurable: true
});

Object.defineProperty(book, "author", {
    value: "David Flanagan",
    writable: false,
    enumerable: true,
    configurable: false
});

Object.defineProperty(book, "year", {
    value: 2020,
    writable: true,
    enumerable: false,
    configurable: true
});

Object.defineProperty(book, "secret", {
    value: "Hidden property",
    enumerable: false,
    configurable: false
});

console.log("Book object:", book);
console.log("Book title:", book.title);
console.log("Book author:", book.author);

// Try to modify non-writable property
try {
    book.author = "New Author";
} catch (e) {
    console.log("Cannot modify non-writable property");
}
console.log("Author after attempt:", book.author); // Still "David Flanagan"

// Enumerability
console.log("\nEnumerable properties:", Object.keys(book));
console.log("All properties:", Object.getOwnPropertyNames(book));

// Property descriptors
console.log("\nProperty descriptors:");
console.log("Title descriptor:", Object.getOwnPropertyDescriptor(book, "title"));
console.log("Author descriptor:", Object.getOwnPropertyDescriptor(book, "author"));
console.log("Year descriptor:", Object.getOwnPropertyDescriptor(book, "year"));

// Define multiple properties at once
Object.defineProperties(book, {
    publisher: {
        value: "O'Reilly Media",
        writable: true,
        enumerable: true
    },
    pages: {
        value: 704,
        writable: false,
        enumerable: true
    }
});

console.log("\nAfter defineProperties:", book);

// Property attributes
const descriptorKeys = ["value", "writable", "enumerable", "configurable"];
for (const key of Object.keys(book)) {
    const desc = Object.getOwnPropertyDescriptor(book, key);
    if (desc) {
        console.log(`${key}:`);
        descriptorKeys.forEach(attr => {
            if (desc.hasOwnProperty(attr)) {
                console.log(`  ${attr}: ${desc[attr]}`);
            }
        });
    }
}

// Seal and Freeze
const sealedObj = Object.seal({ prop: 42 });
const frozenObj = Object.freeze({ prop: 42 });

console.log("\nObject states:");
console.log("Is sealed:", Object.isSealed(sealedObj)); // true
console.log("Is frozen:", Object.isFrozen(frozenObj)); // true
console.log("Is extensible:", Object.isExtensible(book)); // true

// Preventing extensions
Object.preventExtensions(book);
try {
    book.newProperty = "Can't add";
} catch (e) {
    console.log("Cannot add properties after preventing extensions");
}
console.log("Is extensible after preventExtensions:", Object.isExtensible(book));
```

**Output:**
```
Book object: { title: 'JavaScript: The Definitive Guide', author: 'David Flanagan' }
Book title: JavaScript: The Definitive Guide
Book author: David Flanagan
Cannot modify non-writable property
Author after attempt: David Flanagan

Enumerable properties: [ 'title', 'author', 'publisher', 'pages' ]
All properties: [ 'title', 'author', 'year', 'secret', 'publisher', 'pages' ]

Property descriptors:
Title descriptor: { value: 'JavaScript: The Definitive Guide', writable: true, enumerable: true, configurable: true }
Author descriptor: { value: 'David Flanagan', writable: false, enumerable: true, configurable: false }
Year descriptor: { value: 2020, writable: true, enumerable: false, configurable: true }

After defineProperties: { title: 'JavaScript: The Definitive Guide', author: 'David Flanagan', publisher: "O'Reilly Media", pages: 704 }
title:
  value: JavaScript: The Definitive Guide
  writable: true
  enumerable: true
  configurable: true
author:
  value: David Flanagan
  writable: false
  enumerable: true
  configurable: false
publisher:
  value: O'Reilly Media
  writable: true
  enumerable: true
  configurable: false
pages:
  value: 704
  writable: false
  enumerable: true
  configurable: false

Object states:
Is sealed: true
Is frozen: true
Is extensible: true
Cannot add properties after preventing extensions
Is extensible after preventExtensions: false
```

### Example 4: Prototype Chain and Inheritance
```javascript
// Base object
const animal = {
    eats: true,
    walk() {
        console.log(`${this.name} is walking`);
    },
    sleep() {
        console.log(`${this.name} is sleeping`);
    }
};

// Creating an object with animal as prototype
const dog = Object.create(animal);
dog.name = "Rex";
dog.barks = true;
dog.bark = function() {
    console.log(`${this.name} says Woof!`);
};

console.log("Dog object:", dog);
console.log("Dog prototype:", Object.getPrototypeOf(dog));

// Accessing inherited properties
console.log("\nInherited properties:");
console.log("Dog eats:", dog.eats); // true (inherited)
console.log("Dog barks:", dog.barks); // true (own)
dog.walk(); // Rex is walking (inherited)
dog.bark(); // Rex says Woof! (own)

// Checking own vs inherited
console.log("\nProperty checks:");
console.log("dog.hasOwnProperty('name'):", dog.hasOwnProperty("name")); // true
console.log("dog.hasOwnProperty('eats'):", dog.hasOwnProperty("eats")); // false
console.log("'eats' in dog:", "eats" in dog); // true

// Constructor inheritance
function Animal(name) {
    this.name = name;
    this.eats = true;
}

Animal.prototype.walk = function() {
    console.log(`${this.name} is walking`);
};

function Dog(name, breed) {
    Animal.call(this, name); // Call parent constructor
    this.breed = breed;
    this.barks = true;
}

// Set up prototype chain
Dog.prototype = Object.create(Animal.prototype);
Dog.prototype.constructor = Dog;

Dog.prototype.bark = function() {
    console.log(`${this.name} says Woof!`);
};

const dog2 = new Dog("Buddy", "Golden Retriever");
console.log("\nClass-based inheritance:");
console.log("Dog2:", dog2);
console.log("Dog2 eats:", dog2.eats);
console.log("Dog2 breed:", dog2.breed);
dog2.walk();
dog2.bark();

// ES6 Class inheritance
class AnimalClass {
    constructor(name) {
        this.name = name;
        this.eats = true;
    }
    
    walk() {
        console.log(`${this.name} is walking`);
    }
    
    sleep() {
        console.log(`${this.name} is sleeping`);
    }
}

class DogClass extends AnimalClass {
    constructor(name, breed) {
        super(name);
        this.breed = breed;
        this.barks = true;
    }
    
    bark() {
        console.log(`${this.name} says Woof!`);
    }
    
    // Override method
    sleep() {
        console.log(`${this.name} is sleeping like a dog`);
        super.sleep(); // Call parent method
    }
}

const dog3 = new DogClass("Charlie", "Beagle");
console.log("\nES6 Class inheritance:");
console.log("Dog3:", dog3);
console.log("Dog3 eats:", dog3.eats);
console.log("Dog3 breed:", dog3.breed);
dog3.walk();
dog3.bark();
dog3.sleep();

// Prototype chain visualization
console.log("\nPrototype chain:");
console.log("dog -> animal -> Object.prototype");
console.log("dog2 -> Dog.prototype -> Animal.prototype -> Object.prototype");
console.log("dog3 -> DogClass.prototype -> AnimalClass.prototype -> Object.prototype");

// Checking instanceof
console.log("\nInstance checks:");
console.log("dog2 instanceof Dog:", dog2 instanceof Dog); // true
console.log("dog2 instanceof Animal:", dog2 instanceof Animal); // true
console.log("dog2 instanceof Object:", dog2 instanceof Object); // true
console.log("dog3 instanceof DogClass:", dog3 instanceof DogClass); // true
console.log("dog3 instanceof AnimalClass:", dog3 instanceof AnimalClass); // true

// Object.create with null (no prototype)
const nullObject = Object.create(null);
nullObject.name = "No prototype";
console.log("\nObject with null prototype:", nullObject);
console.log("Prototype:", Object.getPrototypeOf(nullObject)); // null
console.log("hasOwnProperty:", nullObject.hasOwnProperty); // undefined
```

**Output:**
```
Dog object: { name: 'Rex', barks: true, bark: [Function: bark] }
Dog prototype: { eats: true, walk: [Function: walk], sleep: [Function: sleep] }

Inherited properties:
Dog eats: true
Dog barks: true
Rex is walking
Rex says Woof!

Property checks:
dog.hasOwnProperty('name'): true
dog.hasOwnProperty('eats'): false
'eats' in dog: true

Class-based inheritance:
Dog2: Dog { name: 'Buddy', eats: true, breed: 'Golden Retriever', barks: true }
Dog2 eats: true
Dog2 breed: Golden Retriever
Buddy is walking
Buddy says Woof!

ES6 Class inheritance:
Dog3: DogClass { name: 'Charlie', eats: true, breed: 'Beagle', barks: true }
Dog3 eats: true
Dog3 breed: Beagle
Charlie is walking
Charlie says Woof!
Charlie is sleeping like a dog
Charlie is sleeping

Prototype chain:
dog -> animal -> Object.prototype
dog2 -> Dog.prototype -> Animal.prototype -> Object.prototype
dog3 -> DogClass.prototype -> AnimalClass.prototype -> Object.prototype

Instance checks:
dog2 instanceof Dog: true
dog2 instanceof Animal: true
dog2 instanceof Object: true
dog3 instanceof DogClass: true
dog3 instanceof AnimalClass: true

Object with null prototype: { name: 'No prototype' }
Prototype: null
hasOwnProperty: undefined
```

### Example 5: Object Methods and Utilities
```javascript
// Object.keys, values, entries
const user2 = {
    id: 1,
    name: "Alice",
    age: 30,
    city: "New York"
};

console.log("Keys:", Object.keys(user2));
// Output: Keys: [ 'id', 'name', 'age', 'city' ]

console.log("Values:", Object.values(user2));
// Output: Values: [ 1, 'Alice', 30, 'New York' ]

console.log("Entries:", Object.entries(user2));
// Output: Entries: [ [ 'id', 1 ], [ 'name', 'Alice' ], [ 'age', 30 ], [ 'city', 'New York' ] ]

// Object.fromEntries (convert entries back to object)
const entries = Object.entries(user2);
const reconstructed = Object.fromEntries(entries);
console.log("Reconstructed:", reconstructed);

// Object.assign
const source1 = { a: 1, b: 2 };
const source2 = { b: 3, c: 4 };
const target = Object.assign({}, source1, source2);
console.log("Object.assign:", target); // { a: 1, b: 3, c: 4 }

// Deep clone with Object.assign (shallow)
const original = {
    name: "John",
    address: {
        street: "123 Main",
        city: "Boston"
    }
};
const shallowCopy = Object.assign({}, original);
const shallowCopy2 = { ...original };
const deepCopy = JSON.parse(JSON.stringify(original));

original.address.city = "Chicago";
console.log("\nShallow vs Deep copy:");
console.log("Original:", original);
console.log("Shallow copy:", shallowCopy); // City changed
console.log("Shallow copy2:", shallowCopy2); // City changed
console.log("Deep copy:", deepCopy); // City unchanged

// Custom deep clone function
function deepClone(obj) {
    if (obj === null || typeof obj !== "object") {
        return obj;
    }
    
    if (obj instanceof Date) {
        return new Date(obj);
    }
    
    if (obj instanceof Array) {
        return obj.map(item => deepClone(item));
    }
    
    const clone = {};
    for (const key in obj) {
        if (obj.hasOwnProperty(key)) {
            clone[key] = deepClone(obj[key]);
        }
    }
    return clone;
}

const complexObj = {
    name: "Complex",
    data: [1, 2, { nested: true }],
    date: new Date(),
    func: function() { return "function"; }
};
const customClone = deepClone(complexObj);
console.log("\nCustom deep clone:");
console.log("Original function:", complexObj.func());
console.log("Clone function:", customClone.func());

// Object.groupBy (ES2024)
const people = [
    { name: "Alice", age: 30 },
    { name: "Bob", age: 25 },
    { name: "Charlie", age: 30 },
    { name: "Diana", age: 25 }
];

const grouped = Object.groupBy(people, person => person.age);
console.log("Grouped by age:", grouped);

// hasOwn (ES2022)
const obj = { prop: 42 };
console.log("hasOwn vs hasOwnProperty:");
console.log("Object.hasOwn(obj, 'prop'):", Object.hasOwn(obj, "prop"));
console.log("obj.hasOwnProperty('prop'):", obj.hasOwnProperty("prop"));
console.log("Object.hasOwn(obj, 'toString'):", Object.hasOwn(obj, "toString"));
console.log("obj.hasOwnProperty('toString'):", obj.hasOwnProperty("toString"));

// Property ordering (ES6)
const orderedObj = {
    z: 1,
    a: 2,
    5: 3,
    b: 4,
    1: 5,
    c: 6
};
console.log("Property ordering:", Object.keys(orderedObj));
// Integer keys first (sorted), then string keys in insertion order

// Object.is vs ===
console.log("\nObject.is vs ===");
console.log("Object.is(NaN, NaN):", Object.is(NaN, NaN)); // true
console.log("NaN === NaN:", NaN === NaN); // false
console.log("Object.is(-0, +0):", Object.is(-0, +0)); // false
console.log("-0 === +0:", -0 === +0); // true
```

**Output:**
```
Keys: [ 'id', 'name', 'age', 'city' ]
Values: [ 1, 'Alice', 30, 'New York' ]
Entries: [ [ 'id', 1 ], [ 'name', 'Alice' ], [ 'age', 30 ], [ 'city', 'New York' ] ]
Reconstructed: { id: 1, name: 'Alice', age: 30, city: 'New York' }
Object.assign: { a: 1, b: 3, c: 4 }

Shallow vs Deep copy:
Original: { name: 'John', address: { street: '123 Main', city: 'Chicago' } }
Shallow copy: { name: 'John', address: { street: '123 Main', city: 'Chicago' } }
Shallow copy2: { name: 'John', address: { street: '123 Main', city: 'Chicago' } }
Deep copy: { name: 'John', address: { street: '123 Main', city: 'Boston' } }

Custom deep clone:
Original function: function
Clone function: function

Grouped by age: { '30': [ { name: 'Alice', age: 30 }, { name: 'Charlie', age: 30 } ], '25': [ { name: 'Bob', age: 25 }, { name: 'Diana', age: 25 } ] }
hasOwn vs hasOwnProperty:
Object.hasOwn(obj, 'prop'): true
obj.hasOwnProperty('prop'): true
Object.hasOwn(obj, 'toString'): false
obj.hasOwnProperty('toString'): false
Property ordering: [ '1', '5', 'z', 'a', 'b', 'c' ]

Object.is vs ===
Object.is(NaN, NaN): true
NaN === NaN: false
Object.is(-0, +0): false
-0 === +0: true
```

### Example 6: Advanced Object Patterns
```javascript
// 1. Singleton Pattern
const Singleton = (function() {
    let instance;
    
    function createInstance() {
        return {
            getData() {
                return "Singleton data";
            },
            setData(data) {
                this._data = data;
            }
        };
    }
    
    return {
        getInstance() {
            if (!instance) {
                instance = createInstance();
            }
            return instance;
        }
    };
})();

const singleton1 = Singleton.getInstance();
const singleton2 = Singleton.getInstance();
console.log("Singleton pattern:");
console.log("Same instance:", singleton1 === singleton2); // true
console.log(singleton1.getData());

// 2. Factory Pattern
function createUser(type, name) {
    const user = {
        name,
        type,
        getDescription() {
            return `${this.name} (${this.type})`;
        }
    };
    
    // Add type-specific methods
    if (type === "admin") {
        user.deleteUser = function() {
            console.log(`${this.name} deleted a user`);
        };
    } else if (type === "guest") {
        user.viewOnly = true;
    }
    
    return user;
}

const admin = createUser("admin", "Alice");
const guest = createUser("guest", "Bob");
console.log("\nFactory pattern:");
console.log(admin.getDescription());
admin.deleteUser();
console.log(guest.getDescription());

// 3. Mixin Pattern
const canFly = {
    fly() {
        console.log(`${this.name} is flying`);
    }
};

const canSwim = {
    swim() {
        console.log(`${this.name} is swimming`);
    }
};

const canRun = {
    run() {
        console.log(`${this.name} is running`);
    }
};

function createAnimal(name) {
    return { name };
}

// Mixin composition
function mixin(target, ...sources) {
    Object.assign(target, ...sources);
    return target;
}

const duck = mixin(
    createAnimal("Duck"),
    canFly,
    canSwim,
    canRun
);

console.log("\nMixin pattern:");
duck.fly(); // Duck is flying
duck.swim(); // Duck is swimming
duck.run(); // Duck is running

// 4. Module Pattern
const Module = (function() {
    // Private variables
    let privateCounter = 0;
    const privateData = [];
    
    // Private function
    function log(message) {
        console.log(`[Module] ${message}`);
    }
    
    // Public API
    return {
        increment() {
            privateCounter++;
            log(`Incremented to ${privateCounter}`);
            return privateCounter;
        },
        decrement() {
            privateCounter--;
            log(`Decremented to ${privateCounter}`);
            return privateCounter;
        },
        addData(item) {
            privateData.push(item);
            log(`Added ${item}`);
            return [...privateData];
        },
        getData() {
            return [...privateData];
        }
    };
})();

console.log("\nModule pattern:");
Module.increment(); // [Module] Incremented to 1
Module.increment(); // [Module] Incremented to 2
Module.addData("item1"); // [Module] Added item1
Module.addData("item2"); // [Module] Added item2
console.log(Module.getData()); // ['item1', 'item2']

// 5. Builder Pattern
class CarBuilder {
    constructor() {
        this.car = {
            make: "",
            model: "",
            year: 0,
            color: "",
            features: []
        };
    }
    
    setMake(make) {
        this.car.make = make;
        return this;
    }
    
    setModel(model) {
        this.car.model = model;
        return this;
    }
    
    setYear(year) {
        this.car.year = year;
        return this;
    }
    
    setColor(color) {
        this.car.color = color;
        return this;
    }
    
    addFeature(feature) {
        this.car.features.push(feature);
        return this;
    }
    
    build() {
        return { ...this.car };
    }
}

const car2 = new CarBuilder()
    .setMake("Toyota")
    .setModel("Camry")
    .setYear(2022)
    .setColor("Silver")
    .addFeature("Sunroof")
    .addFeature("Leather Seats")
    .build();

console.log("\nBuilder pattern:");
console.log(car2);

// 6. Proxy Pattern
const targetObj = {
    name: "Protected",
    secret: "This is secret",
    getData() {
        return this.secret;
    }
};

const handler = {
    get(target, prop, receiver) {
        if (prop === "secret") {
            return "Access Denied";
        }
        if (typeof target[prop] === "function") {
            return function(...args) {
                console.log(`Calling ${prop} with args:`, args);
                return target[prop].apply(this, args);
            };
        }
        return Reflect.get(target, prop, receiver);
    },
    set(target, prop, value) {
        if (prop === "secret") {
            console.log("Cannot modify secret");
            return false;
        }
        target[prop] = value;
        return true;
    }
};

const proxy = new Proxy(targetObj, handler);
console.log("\nProxy pattern:");
console.log("Name:", proxy.name); // Protected
console.log("Secret:", proxy.secret); // Access Denied
proxy.getData(); // Calling getData with args: []
proxy.name = "New Name";
console.log("New name:", proxy.name); // New Name
proxy.secret = "Try to change"; // Cannot modify secret
```

**Output:**
```
Singleton pattern:
Same instance: true
Singleton data

Factory pattern:
Alice (admin)
Alice deleted a user
Bob (guest)

Mixin pattern:
Duck is flying
Duck is swimming
Duck is running

Module pattern:
[Module] Incremented to 1
[Module] Incremented to 2
[Module] Added item1
[Module] Added item2
[ 'item1', 'item2' ]

Builder pattern:
{ make: 'Toyota', model: 'Camry', year: 2022, color: 'Silver', features: [ 'Sunroof', 'Leather Seats' ] }

Proxy pattern:
Name: Protected
Secret: Access Denied
Calling getData with args: []
New name: New Name
Cannot modify secret
```

## Explanation of Examples

### Example 1: Object Literals and Basic Operations
- **Creation**: Object literals provide a clean syntax for creating objects
- **Property Access**: Dot notation for simple keys, bracket notation for dynamic keys
- **Methods**: Functions as object properties using method shorthand
- **Dynamic Properties**: Add, modify, and delete properties at runtime
- **Property Checks**: `in` operator and `hasOwnProperty()` for existence checks
- **Enumeration**: `for...in` loops iterate over enumerable properties
- **Object Methods**: `Object.keys()`, `values()`, `entries()` for introspection
- **Descriptors**: Access property attributes with `getOwnPropertyDescriptor()`
- **Freezing**: Prevent modifications with `Object.freeze()`

### Example 2: Object Creation Methods
- **Literal**: Most common and readable
- **Constructor**: `new Object()` (rarely used)
- **Object.create()**: Create objects with a specific prototype
- **Constructor Functions**: Traditional way to create multiple objects
- **Classes**: Modern syntax (ES6) for constructor functions
- **Factory Functions**: Functions that return objects (no `new` required)
- **Object.assign()**: Merge properties from multiple objects
- **Spread Operator**: Shorter syntax for object merging

### Example 3: Property Descriptors
- **Attributes**: `value`, `writable`, `enumerable`, `configurable`
- **DefineProperty**: Fine-grained control over property behavior
- **Read-only**: Non-writable properties prevent modification
- **Non-enumerable**: Properties don't show up in enumeration
- **defineProperties**: Define multiple properties at once
- **Seal**: Prevent adding/deleting properties
- **Freeze**: Prevent any modifications to object
- **PreventExtensions**: Prevent adding new properties

### Example 4: Prototype Chain and Inheritance
- **Prototype**: Objects inherit from other objects
- **Object.create()**: Set up prototype chain
- **Constructor Inheritance**: Call parent constructor with `call()`
- **Prototype Assignment**: Set up prototype chain for constructors
- **Class Inheritance**: Clean syntax with `extends` and `super`
- **Method Overriding**: Subclasses can override parent methods
- **Instanceof**: Check object's constructor in prototype chain
- **Null Prototype**: Create objects without prototype

### Example 5: Object Methods and Utilities
- **Introspection**: `keys`, `values`, `entries` for object inspection
- **fromEntries**: Convert entries back to object
- **assign**: Shallow copy and merge properties
- **Shallow vs Deep Copy**: Understanding reference vs value
- **Custom Deep Clone**: Recursive cloning for nested objects
- **groupBy**: Group objects by property (ES2024)
- **hasOwn**: Safer alternative to `hasOwnProperty()` (ES2022)
- **Object.is**: Better equality comparison

### Example 6: Advanced Object Patterns
- **Singleton**: Ensure only one instance exists
- **Factory**: Create objects with type-specific behavior
- **Mixin**: Compose behavior from multiple sources
- **Module**: Encapsulate private data and expose public API
- **Builder**: Step-by-step object construction
- **Proxy**: Intercept object operations for custom behavior

## Important Notes

### Best Practices 📝
1. **Use object literals**: Prefer `{}` over `new Object()`
2. **Use method shorthand**: `method() {}` instead of `method: function() {}`
3. **Use computed property names**: Dynamic keys with `[expression]`
4. **Use shorthand properties**: `{ name }` instead of `{ name: name }`
5. **Use property existence**: `Object.hasOwn()` over `hasOwnProperty()`
6. **Prefer `Object.is()`**: For better equality comparisons
7. **Freeze for immutability**: Use `Object.freeze()` for constant objects
8. **Destructuring**: Extract properties cleanly
9. **Spread operator**: Shallow copy objects with `{ ...obj }`
10. **Optional chaining**: Safe property access with `obj?.prop`

### Things to Remember 💡
- Objects are reference types, compared by reference
- Property keys are strings (or Symbols)
- Objects have a prototype chain for inheritance
- `Object.create(null)` creates objects without prototype
- `JSON.stringify()` excludes functions and non-enumerable properties
- Property order: integer keys first, then insertion order
- `Object.assign()` does shallow copying only
- `for...in` includes inherited enumerable properties
- `hasOwnProperty()` is safer than `in` for own properties
- `delete` only removes own properties, not inherited ones

### Property Descriptor Flags

| Flag | Description | Default |
|------|-------------|---------|
| `value` | The value of the property | `undefined` |
| `writable` | Can the value be changed? | `false` |
| `enumerable` | Appears in enumeration? | `false` |
| `configurable` | Can it be deleted or modified? | `false` |

### Object Methods Quick Reference

| Method | Purpose | Returns |
|--------|---------|---------|
| `Object.keys()` | Get enumerable own property keys | Array |
| `Object.values()` | Get enumerable own property values | Array |
| `Object.entries()` | Get `[key, value]` pairs | Array |
| `Object.assign()` | Copy properties from sources | Object |
| `Object.freeze()` | Make object immutable | Object |
| `Object.seal()` | Prevent adding/deleting properties | Object |
| `Object.create()` | Create object with prototype | Object |
| `Object.defineProperty()` | Define property with descriptor | Object |
| `Object.getOwnPropertyDescriptor()` | Get property descriptor | Object |
| `Object.hasOwn()` | Check own property (ES2022) | Boolean |

## Common Mistakes

### Mistake 1: Comparing Objects by Reference
```javascript
// ❌ Bad - comparing objects by reference
const obj1 = { value: 1 };
const obj2 = { value: 1 };
if (obj1 === obj2) { // false (different references)
    console.log("Objects are equal");
}

// ✅ Good - compare by value (shallow)
function areEqual(obj1, obj2) {
    const keys1 = Object.keys(obj1);
    const keys2 = Object.keys(obj2);
    if (keys1.length !== keys2.length) return false;
    for (const key of keys1) {
        if (obj1[key] !== obj2[key]) return false;
    }
    return true;
}
console.log(areEqual(obj1, obj2)); // true
```

### Mistake 2: Modifying Objects from Functions
```javascript
// ❌ Bad - function mutates object
function addProperty(obj, key, value) {
    obj[key] = value; // Mutates original
    return obj;
}
const original = { name: "Alice" };
const result = addProperty(original, "age", 30);
console.log(original === result); // true (same object)

// ✅ Good - return new object
function addProperty(obj, key, value) {
    return { ...obj, [key]: value };
}
const original2 = { name: "Alice" };
const result2 = addProperty(original2, "age", 30);
console.log(original2 === result2); // false
console.log(original2); // { name: 'Alice' }
```

### Mistake 3: Using `for...in` Without `hasOwnProperty`
```javascript
// ❌ Bad - includes inherited properties
const parent = { inherited: "value" };
const child = Object.create(parent);
child.own = "value";

for (const key in child) {
    console.log(key); // "own", "inherited"
}

// ✅ Good - check own properties
for (const key in child) {
    if (child.hasOwnProperty(key)) {
        console.log(key); // "own"
    }
}

// ✅ Better - use Object.keys()
Object.keys(child).forEach(key => {
    console.log(key); // "own"
});
```

### Mistake 4: Shallow Copy with Nested Objects
```javascript
// ❌ Bad - nested objects remain shared
const original3 = {
    name: "John",
    address: {
        city: "New York"
    }
};
const copy = { ...original3 };
copy.address.city = "Boston";
console.log(original3.address.city); // "Boston" (changed!)

// ✅ Good - deep copy
const deepCopy2 = JSON.parse(JSON.stringify(original3));
deepCopy2.address.city = "Chicago";
console.log(original3.address.city); // "Boston" (unchanged)

// ✅ Or custom deep clone function
function deepClone2(obj) {
    if (obj === null || typeof obj !== "object") return obj;
    if (Array.isArray(obj)) return obj.map(deepClone2);
    const clone = {};
    for (const key in obj) {
        if (obj.hasOwnProperty(key)) {
            clone[key] = deepClone2(obj[key]);
        }
    }
    return clone;
}
```

### Mistake 5: Using `delete` on Inherited Properties
```javascript
// ❌ Bad - doesn't delete inherited property
const parent2 = { shared: "value" };
const child2 = Object.create(parent2);
child2.own = "value";
delete child2.shared; // No effect
console.log(child2.shared); // "value" (still inherited)

// ✅ Good - delete own property
delete child2.own;
console.log(child2.own); // undefined
console.log(child2.shared); // "value" (still inherited)
```

### Mistake 6: Forgetting `new` with Constructor
```javascript
// ❌ Bad - missing new
function Car(make, model) {
    this.make = make;
    this.model = model;
}
const car3 = Car("Toyota", "Camry"); // undefined, this = global
console.log(car3); // undefined
console.log(window.make); // "Toyota" (in browser)

// ✅ Good - use new
const car3 = new Car("Toyota", "Camry");
console.log(car3.make); // "Toyota"

// ✅ Better - use class
class Car {
    constructor(make, model) {
        this.make = make;
        this.model = model;
    }
}
const car3 = new Car("Toyota", "Camry");
console.log(car3.make); // "Toyota"
```

## Interview Questions

1. **What's the difference between dot notation and bracket notation?**  
   *Answer: Dot notation (`obj.prop`) is simpler and faster but only works with valid identifier names. Bracket notation (`obj["prop"]`) works with any string, including dynamic keys and keys with spaces. Use bracket notation when keys are dynamic or contain special characters.*

2. **Explain prototype inheritance in JavaScript.**  
   *Answer: Every object has a prototype (another object). When accessing a property, JavaScript looks for it in the object itself, then in its prototype, then in the prototype's prototype, etc. This forms the prototype chain. Objects inherit properties from their prototype chain.*

3. **What are property descriptors and why are they useful?**  
   *Answer: Property descriptors define attributes of properties: `value`, `writable`, `enumerable`, `configurable`. They provide fine-grained control over property behavior. Useful for creating read-only properties, non-enumerable properties, and preventing property deletion.*

4. **How do you create objects in JavaScript?**  
   *Answer: Multiple ways: object literals (`{}`), constructor functions with `new`, `Object.create()`, ES6 classes, factory functions, `Object.assign()`, and spread operator. Each has different use cases and prototype chain implications.*

5. **What's the difference between `Object.create()` and `new`?**  
   *Answer: `Object.create()` creates a new object with a specified prototype without calling any constructor. `new` creates an object using a constructor function, setting the prototype to the constructor's prototype and calling the constructor to initialize the object.*

6. **Explain object destructuring.**  
   *Answer: Object destructuring extracts properties from objects into variables. Syntax: `const { name, age } = person`. Supports renaming (`{ name: userName }`), default values (`{ name = "Guest" }`), and nested destructuring (`{ address: { city } }`).*

7. **What are the different ways to copy objects in JavaScript?**  
   *Answer: Shallow copy: `Object.assign()`, spread operator (`{ ...obj }`). Deep copy: `JSON.parse(JSON.stringify())` (limited), custom recursive function, or libraries like Lodash's `cloneDeep`. Shallow copies share nested object references.*

8. **What is the `hasOwn` method and why is it better than `hasOwnProperty`?**  
   *Answer: `Object.hasOwn(obj, key)` is a static method (ES2022) that checks if `obj` has an own property `key`. It's safer than `hasOwnProperty` because it works even when `obj` has a null prototype or the object has overridden `hasOwnProperty`.*

9. **Explain the concept of object freezing and sealing.**  
   *Answer: `Object.freeze()` makes an object immutable: cannot add, remove, or change properties. `Object.seal()` prevents adding or removing properties but allows modifying existing properties. `Object.preventExtensions()` only prevents adding properties.*

10. **What is the difference between `Object.assign()` and the spread operator?**  
    *Answer: Both perform shallow copies. The spread operator is more concise for copying objects (`{ ...obj }`). `Object.assign()` supports multiple sources and can modify an existing object. The spread operator is preferred for creating new objects, `Object.assign()` for merging into existing objects.*

## Practice Exercises

### Easy Exercise ✨
**Task**: Create a function that:
1. Takes a person object with `firstName` and `lastName`
2. Adds a `fullName` getter property
3. Adds a `greet` method
4. Returns the modified object without mutating the original

<details>
<summary>Solution</summary>

```javascript
function enhancePerson(person) {
    // Create a new object with spread
    const enhanced = { ...person };
    
    // Add getter for fullName
    Object.defineProperty(enhanced, "fullName", {
        get() {
            return `${this.firstName} ${this.lastName}`;
        },
        enumerable: true,
        configurable: true
    });
    
    // Add greet method
    enhanced.greet = function() {
        return `Hello, ${this.fullName}!`;
    };
    
    return enhanced;
}

// Test
const john = { firstName: "John", lastName: "Doe" };
const enhancedJohn = enhancePerson(john);

console.log("Original:", john);
console.log("Enhanced:", enhancedJohn);
console.log("Full name:", enhancedJohn.fullName);
console.log("Greeting:", enhancedJohn.greet());

// Verify immutability
john.firstName = "Jane";
console.log("Original after change:", john);
console.log("Enhanced after original change:", enhancedJohn);
```
</details>

### Medium Exercise 📘
**Task**: Build a deep object validator that:
1. Validates required fields
2. Validates data types
3. Validates custom validation rules
4. Provides detailed error messages
5. Handles nested objects

<details>
<summary>Solution</summary>

```javascript
class ObjectValidator {
    constructor(schema) {
        this.schema = schema;
        this.errors = [];
    }
    
    validate(obj) {
        this.errors = [];
        this._validate(obj, this.schema, "");
        return {
            valid: this.errors.length === 0,
            errors: this.errors
        };
    }
    
    _validate(obj, schema, path) {
        // Required fields
        if (schema.required) {
            if (obj === undefined || obj === null) {
                this.errors.push(`${path} is required`);
                return;
            }
        }
        
        // Type checking
        if (schema.type) {
            const type = typeof obj;
            if (type !== schema.type) {
                this.errors.push(`${path} must be ${schema.type}, got ${type}`);
                return;
            }
        }
        
        // Custom validation
        if (schema.validate && typeof schema.validate === "function") {
            const result = schema.validate(obj);
            if (result !== true) {
                this.errors.push(`${path}: ${result || "Validation failed"}`);
            }
        }
        
        // Nested object validation
        if (schema.properties && typeof obj === "object" && obj !== null) {
            for (const [key, propSchema] of Object.entries(schema.properties)) {
                const nestedPath = path ? `${path}.${key}` : key;
                const value = obj[key];
                
                // Check if property exists
                if (propSchema.required && value === undefined) {
                    this.errors.push(`${nestedPath} is required`);
                    continue;
                }
                
                // Validate nested property
                this._validate(value, propSchema, nestedPath);
            }
            
            // Check for unexpected properties
            if (schema.strict) {
                const allowedKeys = Object.keys(schema.properties);
                for (const key of Object.keys(obj)) {
                    if (!allowedKeys.includes(key)) {
                        this.errors.push(`${path}.${key} is not allowed`);
                    }
                }
            }
        }
    }
}

// Usage
const userSchema = {
    type: "object",
    properties: {
        id: {
            type: "number",
            required: true,
            validate: (value) => value > 0 || "ID must be positive"
        },
        name: {
            type: "string",
            required: true,
            validate: (value) => value.length >= 3 || "Name must be at least 3 characters"
        },
        age: {
            type: "number",
            required: true,
            validate: (value) => {
                if (value < 0) return "Age must be positive";
                if (value > 150) return "Age must be realistic";
                return true;
            }
        },
        email: {
            type: "string",
            required: true,
            validate: (value) => {
                const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
                return emailRegex.test(value) || "Invalid email format";
            }
        },
        address: {
            type: "object",
            properties: {
                street: {
                    type: "string",
                    required: true
                },
                city: {
                    type: "string",
                    required: true
                },
                zipCode: {
                    type: "string",
                    required: false,
                    validate: (value) => {
                        if (value && !/^\d{5}$/.test(value)) {
                            return "Invalid zip code (5 digits)";
                        }
                        return true;
                    }
                }
            }
        }
    },
    strict: true
};

// Test cases
const testCases = [
    {
        id: 1,
        name: "Alice",
        age: 25,
        email: "alice@example.com",
        address: {
            street: "123 Main St",
            city: "Boston",
            zipCode: "02110"
        }
    },
    {
        id: -1,
        name: "Bo",
        age: 200,
        email: "invalid-email",
        address: {
            street: "456 Oak Ave"
            // Missing city
        }
    },
    {
        id: 3,
        name: "Charlie",
        age: 30,
        email: "charlie@example.com",
        address: {
            street: "789 Pine St",
            city: "Chicago",
            zipCode: "6060" // Invalid zip
        },
        extra: "Not allowed" // Strict mode
    }
];

const validator = new ObjectValidator(userSchema);

testCases.forEach((data, index) => {
    console.log(`\n🔍 Test Case ${index + 1}:`);
    const result = validator.validate(data);
    if (result.valid) {
        console.log("✅ Data is valid");
    } else {
        console.log("❌ Validation errors:");
        result.errors.forEach(error => {
            console.log(`  - ${error}`);
        });
    }
});
```
</details>

### Challenge Exercise 💪
**Task**: Implement a reactive object system that:
1. Tracks changes to object properties
2. Notifies listeners when changes occur
3. Supports nested objects and arrays
4. Provides change tracking (old value, new value, path)
5. Works with getters and setters

<details>
<summary>Solution</summary>

```javascript
class ReactiveObject {
    constructor(target, parent = null, path = "") {
        this._target = target;
        this._parent = parent;
        this._path = path;
        this._listeners = [];
        this._proxy = this._createProxy(target);
    }
    
    _createProxy(obj) {
        const handler = {
            get: (target, prop) => {
                // Handle special properties
                if (prop === '_target' || prop === '_parent' || prop === '_path') {
                    return target[prop];
                }
                
                const value = target[prop];
                
                // Make nested objects reactive
                if (value && typeof value === 'object' && !Array.isArray(value)) {
                    if (!value._proxy) {
                        const reactive = new ReactiveObject(value, this, this._getPath(prop));
                        value._proxy = reactive;
                        return reactive._proxy;
                    }
                    return value._proxy;
                }
                
                return value;
            },
            set: (target, prop, value) => {
                const oldValue = target[prop];
                
                // Don't allow setting internal properties
                if (prop === '_target' || prop === '_parent' || prop === '_path') {
                    target[prop] = value;
                    return true;
                }
                
                const path = this._getPath(prop);
                const isNew = !(prop in target);
                const isChanged = oldValue !== value;
                
                if (isChanged || isNew) {
                    // Handle nested objects
                    if (value && typeof value === 'object') {
                        const reactive = new ReactiveObject(value, this, path);
                        value._proxy = reactive;
                        target[prop] = value;
                        this._notifyListeners({
                            type: isNew ? 'add' : 'change',
                            path,
                            oldValue,
                            newValue: value,
                            isNew
                        });
                    } else {
                        target[prop] = value;
                        this._notifyListeners({
                            type: isNew ? 'add' : 'change',
                            path,
                            oldValue,
                            newValue: value,
                            isNew
                        });
                    }
                }
                
                return true;
            },
            deleteProperty: (target, prop) => {
                const oldValue = target[prop];
                const path = this._getPath(prop);
                
                if (prop in target) {
                    delete target[prop];
                    this._notifyListeners({
                        type: 'delete',
                        path,
                        oldValue,
                        newValue: undefined
                    });
                }
                
                return true;
            }
        };
        
        return new Proxy(obj, handler);
    }
    
    _getPath(prop) {
        return this._path ? `${this._path}.${prop}` : String(prop);
    }
    
    _notifyListeners(change) {
        // Notify all listeners
        this._listeners.forEach(listener => {
            try {
                listener(change);
            } catch (error) {
                console.error('Error in listener:', error);
            }
        });
        
        // Propagate to parent
        if (this._parent) {
            this._parent._notifyListeners(change);
        }
    }
    
    // Public API
    addListener(callback) {
        this._listeners.push(callback);
        return () => {
            const index = this._listeners.indexOf(callback);
            if (index !== -1) {
                this._listeners.splice(index, 1);
            }
        };
    }
    
    getProxy() {
        return this._proxy;
    }
    
    // Track changes within a transaction
    transaction(callback) {
        const changes = [];
        const listener = (change) => changes.push(change);
        const removeListener = this.addListener(listener);
        
        try {
            callback(this._proxy);
        } catch (error) {
            console.error('Transaction error:', error);
        } finally {
            removeListener();
        }
        
        return changes;
    }
}

// Usage
const data = {
    user: {
        name: "Alice",
        age: 30,
        address: {
            street: "123 Main St",
            city: "Boston"
        }
    },
    settings: {
        theme: "dark",
        notifications: true
    }
};

const reactive = new ReactiveObject(data);
const proxy = reactive.getProxy();

// Add listeners
const unsubscribe1 = reactive.addListener((change) => {
    console.log(`📝 Change at ${change.path}: ${change.oldValue} -> ${change.newValue}`);
});

const unsubscribe2 = reactive.addListener((change) => {
    if (change.type === 'delete') {
        console.log(`🗑️ Deleted: ${change.path}`);
    }
});

console.log("🔧 Making changes...\n");

// Simple changes
proxy.user.name = "Bob";
proxy.user.age = 31;

// Nested changes
proxy.user.address.city = "New York";

// Adding new properties
proxy.user.email = "bob@example.com";

// Deleting properties
delete proxy.settings.notifications;

// Array handling
proxy.todos = [
    { text: "Learn React", done: false },
    { text: "Build project", done: false }
];

proxy.todos.push({ text: "Write tests", done: false });

// Transaction
console.log("\n💰 Transaction changes:");
const changes = reactive.transaction((state) => {
    state.user.age = 32;
    state.user.address.zipCode = "02111";
    state.settings.theme = "light";
    state.user.address.city = "Cambridge";
});

console.log("Changes in transaction:", changes);

// Get final state
console.log("\n🎯 Final state:", JSON.stringify(proxy, null, 2));

// Cleanup
unsubscribe1();
unsubscribe2();

// Advanced: Watcher for specific paths
class Watcher {
    constructor(reactive, path) {
        this.reactive = reactive;
        this.path = path;
        this.value = this._getValue();
        this.callbacks = [];
        
        // Listen for changes
        this.unsubscribe = reactive.addListener((change) => {
            if (change.path === path || change.path.startsWith(path + '.')) {
                const newValue = this._getValue();
                const oldValue = this.value;
                this.value = newValue;
                
                this.callbacks.forEach(cb => {
                    try {
                        cb(newValue, oldValue, change);
                    } catch (error) {
                        console.error('Watcher error:', error);
                    }
                });
            }
        });
    }
    
    _getValue() {
        const parts = this.path.split('.');
        let value = this.reactive.getProxy();
        
        for (const part of parts) {
            if (value && typeof value === 'object') {
                value = value[part];
            } else {
                return undefined;
            }
        }
        
        return value;
    }
    
    onChange(callback) {
        this.callbacks.push(callback);
        return () => {
            const index = this.callbacks.indexOf(callback);
            if (index !== -1) {
                this.callbacks.splice(index, 1);
            }
        };
    }
    
    dispose() {
        this.unsubscribe();
        this.callbacks = [];
    }
}

// Usage of Watcher
console.log("\n👁️ Watcher example:");
const watcher = new Watcher(reactive, "user.address.city");
watcher.onChange((newValue, oldValue, change) => {
    console.log(`📍 City changed from ${oldValue} to ${newValue}`);
});

// Change the city
proxy.user.address.city = "San Francisco";

// Dispose watcher
watcher.dispose();
```
</details>

## Summary

### Key Takeaways 📌

#### Object Basics
- **Key-Value Pairs**: Objects store data as properties
- **Dynamic**: Properties can be added, modified, or removed
- **Reference Type**: Variables hold references to objects
- **Mutable**: Object contents can be changed

#### Object Creation
- **Literals**: `{ key: value }` (most common)
- **Constructors**: `new Object()` or custom constructors
- **Object.create()**: Set prototype explicitly
- **Classes**: Modern ES6 syntax

#### Prototype Chain
- Objects inherit properties from prototypes
- Prototype chain is traversed for property lookup
- `__proto__` and `Object.getPrototypeOf()`
- `instanceof` checks prototype chain

#### Property Management
- **Access**: Dot and bracket notation
- **Descriptors**: Control property behavior
- **Freeze/Seal**: Prevent modifications
- **Copying**: Shallow vs deep copy

### Quick Reference Card 🎯

```javascript
// Object Creation
const obj = { key: 'value' };
const obj = new Object();
const obj = Object.create(prototype);
const obj = new Constructor();

// Property Access
obj.prop;
obj['prop'];
obj?.['prop'];

// Property Management
Object.defineProperty(obj, 'key', {
    value: 42,
    writable: true,
    enumerable: true,
    configurable: true
});

// Protection
Object.freeze(obj);    // Immutable
Object.seal(obj);      // No add/delete
Object.preventExtensions(obj); // No add

// Copying
const copy = { ...obj }; // Shallow
const copy = Object.assign({}, obj); // Shallow
const copy = JSON.parse(JSON.stringify(obj)); // Deep (limited)

// Introspection
Object.keys(obj);
Object.values(obj);
Object.entries(obj);
Object.hasOwn(obj, 'key');

// Prototype
Object.getPrototypeOf(obj);
Object.setPrototypeOf(obj, prototype);

// Inheritance (ES6)
class Child extends Parent {
    constructor() {
        super();
        // ...
    }
}
```

### Remember These Points 💡
1. Objects are reference types - they're compared by reference, not value
2. Properties are strings (or Symbols) - `obj[42]` becomes `obj["42"]`
3. The prototype chain enables inheritance
4. `Object.create(null)` creates objects without prototype
5. `for...in` includes inherited properties - use `Object.keys()` or `hasOwnProperty()`
6. `Object.assign()` and spread `{...obj}` are shallow copies only
7. `JSON.stringify()` excludes functions and non-enumerable properties
8. Getters and setters enable computed properties
9. Destructuring simplifies extracting properties
10. ES6 classes provide a cleaner way to use prototypes

**Objects are the foundation of JavaScript - mastering them is essential for building robust applications!** 🚀
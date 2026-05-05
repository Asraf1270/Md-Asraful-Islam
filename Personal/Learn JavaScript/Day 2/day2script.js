// Now day 2
let age = 21;
let nameme = "Md. Asraful Islam";
console.log("My name is ",nameme);
console.log("My age is = ",age);

// const 
const birthday = "January 26"
console.log("My birthday is on ",birthday);

let isStudent = true;
let isRaining = false;
console.log("Am I a student? ",isStudent);
console.log("Is it raining? ",isRaining);

// string vs number
console.log("5"+"3"); // this will concatenate the strings and output "53"
console.log(5+3); // this will add the numbers and output 8

// type coercion
console.log("The answer is " + 42); // this will convert the number 42 to a string and output "The answer is 42"
console.log("The answer is " + (5 + 3)); // this will first add the numbers and then convert the result to a string, outputting "The answer is 8"

// Exercise 1
let myCountry = "Bangladesh";
console.log("My country is ",myCountry);
console.log(`My country is ${myCountry}`); // This will also output "My country is Bangladesh" using template literals.

//Exercsie 2
let price = 50;
let item = "Shirt";
console.log("The ",item," costs ",price," dollars.");
console.log(`The ${item} costs ${price} dollars.`); // This will also output "The Shirt costs 50 dollars." using template literals.

// Exercise 3
const currenYear = 2026;
// currenYear = 2027; // This will cause an error because currenYear is a constant and cannot be reassigned.

// Some Mathematical Operations
let a = 10;
let b = 5;

console.log("a + b = ", a + b); // Addition
console.log("a - b = ", a - b); // Subtraction
console.log("a * b = ", a * b); // Multiplication
console.log("a / b = ", a / b); // Division
console.log("a % b = ", a % b); // Modulus (remainder)
console.log("a^b = ", a ** b); // Exponentiation (a raised to the power of b)

// Now, I learn about the loops in JavaScript. There are three types of loops: for, while, and do...while.

// For loop
console.log("For loop:");
for (let i = 0; i < 5; i++) {
    console.log(i);
}

// While loop
console.log("While loop:");
let j = 0;
while (j < 5) {
    console.log(j);
    j++;
}

// Do...while loop
console.log("Do...while loop:");
let k = 0;
do {
    console.log(k);
    k++;
} while (k < 5);   

// Looping through an array
const fruits = ["Apple", "Banana", "Orange", "Mango", "Grapes"];
// For loop
for (let i = 0; i < fruits.length; i++) {
    console.log(fruits[i]);
}

// For ... of (cleaner for arrays)
for (let fruit of fruits) {
    console.log(fruit);
}

// Continue and break statements
for (let i = 0; i < 10; i++) {
    if (i === 2) continue; // Skip the rest of the loop when i is 2
    if (i === 5) break; //Stop at 4
    console.log(i);
}

// Practice : print even numbers from 0 tp 20
for (let i=0; i <= 20; i++){
    if (i % 2 === 0) {
        console.log(i);
    }
}
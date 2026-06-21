function hi(name) {
    console.log("Hello, " + name);
    return 6;
    console.log(4); // This console don't show because return 
    // after return function did exicute anything
}

hi("Asraf");
hi("Rifat");


function myFunction(a, b) {
    return a * b;
}

let x = myFunction(4, 3);
console.log(x);
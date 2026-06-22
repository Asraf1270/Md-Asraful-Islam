const car = {
    name: "BMW",
    model: "500",
    weight: "950 kg",
    color: "Black",
    start: function(){
        console.log("Car is started")
    },
    drive: function(){
        console.log("Car is driving")
    }
};

console.log("car name is " + car.nam);
car.start();
car.drive();


const person = {
    firstName: "Asraful",
    lastName: "Islam",
    age: 22,
    fullName: function(){
        return this.firstName + " " + this.lastName;
    }
};

console.log("First name is " + person.firstName);
console.log("and last name is " + person.lastName);
console.log("So, full name is " + person.fullName());
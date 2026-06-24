let stc = "Apple, Banana, Kiwi"
let msg1 = stc.slice(7, 13);
console.log(msg1)
document.getElementById("showMsg").innerHTML = msg1;

let rep1 = stc.replace("Apple", "Orange")
console.log(rep1)
document.getElementById("showMsg2").innerHTML = rep1;

function makeUpper(){
    let text = document.getElementById("text").value;
    document.getElementById("showUpper").innerHTML = text.toUpperCase();
    console.log(text)
}
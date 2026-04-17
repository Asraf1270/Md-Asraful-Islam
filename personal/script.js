console.log("Script loaded successfully!");
console.log("This is my first Java/script code in this project.");

// Get the details elements
const detailsAboutMe = document.getElementById("details-about-me");
const detailsExpand = document.getElementById("details-expand");

// Add event listeners to the summary elements
detailsAboutMe.querySelector("summary").addEventListener("click", () => {
    console.log("About Me details toggled");
});

detailsExpand.querySelector("summary").addEventListener("click", () => {
    console.log("Expand details toggled");
});
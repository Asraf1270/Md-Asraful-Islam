# JavaScript Introduction

## What is JavaScript?

JavaScript (JS) is a programming language that allows you to create dynamic and interactive web pages.

JavaScript is one of the three core technologies of web development:

| Technology | Purpose                  |
| ---------- | ------------------------ |
| HTML       | Structure                |
| CSS        | Styling                  |
| JavaScript | Behavior & Interactivity |

---

## Why Learn JavaScript?

JavaScript is:

* Easy to learn
* Supported by all modern browsers
* Used for front-end development
* Used for back-end development (Node.js)
* Essential for modern web applications

---

## What Can JavaScript Do?

### 1. Change HTML Content

```html
<p id="demo">Hello World!</p>

<script>
document.getElementById("demo").innerHTML = "Hello JavaScript!";
</script>
```

---

### 2. Change HTML Attributes

```html
<button onclick="document.getElementById('myImage').src='on.png'">
Turn On
</button>
```

---

### 3. Change CSS Styles

```html
<p id="text">JavaScript Styling</p>

<script>
document.getElementById("text").style.color = "red";
</script>
```

---

### 4. Hide HTML Elements

```javascript
document.getElementById("demo").style.display = "none";
```

---

### 5. Show HTML Elements

```javascript
document.getElementById("demo").style.display = "block";
```

---

## JavaScript Example

```html
<!DOCTYPE html>
<html>
<body>

<h2>My First JavaScript</h2>

<button onclick="document.getElementById('demo').innerHTML = Date()">
Click Me
</button>

<p id="demo"></p>

</body>
</html>
```

---

## Where JavaScript Runs

### Browser

```html
<script>
alert("Hello");
</script>
```

### Server (Node.js)

```javascript
console.log("Hello from Node.js");
```

---

## Key Points

* JavaScript is a scripting language.
* JavaScript makes websites interactive.
* JavaScript works with HTML and CSS.
* JavaScript can run in browsers and servers.
* JavaScript is one of the most popular programming languages.

---

## Summary

* HTML = Structure
* CSS = Design
* JavaScript = Functionality
* JavaScript makes web pages dynamic and interactive.

# JavaScript Output

JavaScript can display data in several ways.

---

## 1. Using innerHTML

HTML:

```html
<p id="demo"></p>
```

JavaScript:

```javascript
document.getElementById("demo").innerHTML = "Hello JavaScript";
```

Output:

```text
Hello JavaScript
```

---

## 2. Using document.write()

```javascript
document.write("Hello World");
```

Example:

```javascript
document.write(10 + 5);
```

Output:

```text
15
```

### Warning

Using `document.write()` after the page loads will overwrite the page.

---

## 3. Using alert()

```javascript
alert("Welcome!");
```

or

```javascript
window.alert("Welcome!");
```

Displays a popup message.

---

## 4. Using console.log()

```javascript
console.log("Hello Console");
```

Open browser console:

```text
F12 → Console
```

Example:

```javascript
console.log(5 + 5);
```

Output:

```text
10
```

---

## 5. Using window.print()

```html
<button onclick="window.print()">
Print Page
</button>
```

Prints the current webpage.

---

## Complete Example

```html
<!DOCTYPE html>
<html>
<body>

<p id="demo"></p>

<script>

document.getElementById("demo").innerHTML = "innerHTML Output";

document.write("<br>document.write Output");

console.log("Console Output");

alert("Alert Output");

</script>

</body>
</html>
```

---

## Comparison Table

| Method           | Purpose                   |
| ---------------- | ------------------------- |
| innerHTML        | Display data in HTML      |
| document.write() | Write directly to webpage |
| alert()          | Show popup message        |
| console.log()    | Debugging                 |
| print()          | Print webpage             |

---

## Summary

* `innerHTML` is the most common output method.
* `document.write()` is mainly used for testing.
* `alert()` displays popup messages.
* `console.log()` is used for debugging.
* `print()` prints the webpage.

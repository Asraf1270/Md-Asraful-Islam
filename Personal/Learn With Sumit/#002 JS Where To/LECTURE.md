# JavaScript Where To

## The `<script>` Tag

JavaScript code is written inside the `<script>` tag.

```html
<script>
document.write("Hello JavaScript");
</script>
```

---

## JavaScript in HTML

```html
<!DOCTYPE html>
<html>
<body>

<h1>My Web Page</h1>

<script>
document.write("Hello World!");
</script>

</body>
</html>
```

---

## JavaScript Functions

```html
<script>
function myFunction() {
    document.getElementById("demo").innerHTML = "Paragraph Changed!";
}
</script>
```

---

## JavaScript in `<head>`

```html
<head>
<script>
function myFunction() {
    document.getElementById("demo").innerHTML = "Changed!";
}
</script>
</head>
```

---

## JavaScript in `<body>`

```html
<body>

<p id="demo">Hello</p>

<script>
document.getElementById("demo").innerHTML = "JavaScript Loaded";
</script>

</body>
```

### Recommended Placement

Place scripts just before:

```html
</body>
```

Reason:

* Faster page loading
* Better performance

---

## External JavaScript

### script.js

```javascript
function myFunction() {
    document.getElementById("demo").innerHTML = "External JS";
}
```

### HTML

```html
<script src="script.js"></script>
```

---

## Advantages of External JavaScript

* Cleaner code
* Easy maintenance
* Reusable code
* Faster page loading

---

## JavaScript File Extension

```text
.js
```

Examples:

```text
app.js
script.js
main.js
```

---

## Summary

* JavaScript code is placed inside `<script>`.
* Scripts can be written in `<head>` or `<body>`.
* External JavaScript files use the `.js` extension.
* Use the `src` attribute to link external files.
* External files are the preferred approach.

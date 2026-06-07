# Week - 8: HTML, CSS, and JavaScript

## Topics Covered

---

## Networking Fundamentals

### 1. IP (Internet Protocol)

#### What is IP?
IP (Internet Protocol) is the fundamental protocol that enables devices to communicate across networks by identifying them through unique addresses. Every device connected to the internet has an IP address, which acts like a postal address for data packets.

#### IPv4 (Internet Protocol Version 4)
- **Format**: 32-bit address divided into 4 octets (e.g., 192.168.1.1)
- **Total Addresses**: ~4.3 billion addresses
- **Structure**: Each octet ranges from 0-255
- **Example**: 8.8.8.8 (Google's public DNS server)

**Real-Life Example:**
When you visit Google, your device sends a request to 142.250.185.46 (Google's IP). The web browser translates "google.com" to this IP address using DNS.

#### IPv6 (Internet Protocol Version 6)
- **Format**: 128-bit address written in hexadecimal (e.g., 2001:0db8:85a3:0000:0000:8a2e:0370:7334)
- **Total Addresses**: ~340 undecillion addresses
- **Why IPv6?**: IPv4 addresses are running out due to exponential internet growth
- **Notation**: Can be abbreviated as 2001:db8:85a3::8a2e:370:7334

**Real-Life Example:**
Modern IoT devices (smart home appliances, sensors, wearables) often use IPv6 to accommodate the massive number of connected devices worldwide.

#### IPv8 (Emerging Research Protocol)
- **Status**: Currently in research phase
- **Goal**: Enhanced security, better performance, and improved routing
- **Features**: Advanced encryption standards, optimized packet handling
- **Future**: May complement IPv6 for specialized applications

---

### 2. TCP (Transmission Control Protocol)

#### What is TCP?
TCP is a connection-oriented protocol that ensures reliable, ordered, and error-checked delivery of data. It establishes a connection before sending data and maintains it until complete.

#### Key Characteristics:
- **Connection-Oriented**: Establishes connection before data transfer
- **Reliable**: Guarantees data delivery without loss or corruption
- **Ordered**: Data arrives in the same sequence it was sent
- **Flow Control**: Manages data transmission speed
- **Error Detection**: Checksums detect corrupted data

#### The Three-Way Handshake (TCP Handshake)
1. **SYN**: Client sends synchronization packet to server
2. **SYN-ACK**: Server acknowledges and sends its own synchronization
3. **ACK**: Client acknowledges the server's response
4. **Connection Established**: Data transfer begins

**Real-Life Example:**
When you click a link to visit a website:
- Your browser (client) sends a SYN packet to the web server
- The server responds with SYN-ACK
- Your browser sends ACK back
- Now the secure connection is established, and the webpage data is transferred reliably

---

### 3. TCP Header Format

The TCP header contains control information for managing communication. Each field plays a specific role:

```
0         8         16        24        32
+--------+--------+--------+--------+
| Source Port (16 bits)              |
+--------+--------+--------+--------+
| Destination Port (16 bits)         |
+--------+--------+--------+--------+
| Sequence Number (32 bits)          |
+--------+--------+--------+--------+
| Acknowledgment Number (32 bits)    |
+--------+--------+--------+--------+
| Offset | Flags  | Window Size (16) |
+--------+--------+--------+--------+
| Checksum (16)   | Urgent Pointer  |
+--------+--------+--------+--------+
```

#### Header Fields Explained:

| Field | Size | Purpose |
|-------|------|---------|
| Source Port | 16 bits | Which port the data is sent from |
| Destination Port | 16 bits | Which port the data is going to |
| Sequence Number | 32 bits | Orders packets; helps receiver reconstruct data |
| Acknowledgment Number | 32 bits | Confirms receipt of data |
| Flags | 8 bits | Control bits (SYN, ACK, FIN, RST, PSH, URG) |
| Window Size | 16 bits | Amount of data the receiver can accept |
| Checksum | 16 bits | Error detection mechanism |
| Urgent Pointer | 16 bits | Points to urgent data within the segment |

**Real-Life Example:**
When you download a large file, TCP breaks it into multiple packets. Each packet has a sequence number so your computer can reassemble them in the correct order, even if they arrive out of sequence on the internet.

---

### 4. Ports

#### What are Ports?
Ports are logical endpoints on a device that allow multiple applications to communicate over the same IP address simultaneously. Think of an IP address as a building address and ports as apartment numbers.

#### Port Ranges:
- **Well-Known Ports (0-1023)**: Reserved for standard services
- **Registered Ports (1024-49151)**: Assigned by IANA for specific services
- **Ephemeral Ports (49152-65535)**: Temporary ports for client applications

#### Common Ports:
| Port | Protocol | Purpose |
|------|----------|---------|
| 20 | FTP | File transfer (data) |
| 21 | FTP | File transfer (control) |
| 22 | SSH | Secure shell access |
| 25 | SMTP | Email sending |
| 53 | DNS | Domain name resolution |
| 80 | HTTP | Web browsing (unencrypted) |
| 110 | POP3 | Email retrieval |
| 143 | IMAP | Email access |
| 443 | HTTPS | Web browsing (encrypted) |
| 3306 | MySQL | Database |
| 5432 | PostgreSQL | Database |
| 8080 | HTTP Alternate | Web development |

**Real-Life Example:**
When you browse Facebook:
- Your computer connects to Facebook's server (IP: 157.240.x.x) on port 443 (HTTPS)
- Simultaneously, your email client connects to Gmail's server on port 993 (IMAPS)
- Each application uses a different port on the same device, preventing conflicts

---

### 5. DNS (Domain Name System)

#### What is DNS?
DNS is the "phonebook of the internet." It translates human-readable domain names (like google.com) into IP addresses (like 142.250.185.46) that computers can understand.

#### How DNS Works:
1. **User Query**: "What's the IP for google.com?"
2. **Recursive Resolver**: Your ISP's DNS server processes the request
3. **Root Nameserver**: Directs to the Top-Level Domain (TLD) server
4. **TLD Server**: Directs to the authoritative nameserver
5. **Authoritative Nameserver**: Returns the actual IP address
6. **Response**: IP is sent back to your browser

#### DNS Record Types:

| Record Type | Purpose | Example |
|-------------|---------|---------|
| **A** | Maps domain to IPv4 | example.com → 93.184.216.34 |
| **AAAA** | Maps domain to IPv6 | example.com → 2606:2800:220:1:248:1893:25c8:1946 |
| **CNAME** | Alias for another domain | www.example.com → example.com |
| **MX** | Email server location | mail.example.com handles emails |
| **NS** | Nameserver reference | Points to DNS provider |
| **TXT** | Text records | Verification, SPF, DKIM for email |
| **SOA** | Start of Authority | Primary DNS authority info |

**Real-Life Example:**
When you type "amazon.com" in your browser:
1. Browser queries DNS: "What's amazon.com's IP?"
2. DNS resolver looks up its records
3. Returns: 205.251.242.103
4. Browser connects to that IP and loads Amazon's website
5. This all happens in milliseconds!

---

### 6. DHCP (Dynamic Host Configuration Protocol)

#### What is DHCP?
DHCP automatically assigns IP addresses to devices when they connect to a network, eliminating the need for manual configuration. It also provides other network information like gateway and DNS servers.

#### DHCP Process (DORA):
1. **Discover**: Client broadcasts "I need an IP address"
2. **Offer**: DHCP server offers an available IP
3. **Request**: Client requests that specific IP
4. **Acknowledge**: Server confirms the assignment

#### DHCP Lease:
- IP addresses are temporary (leased)
- Typical lease duration: 24 hours to 7 days
- Before expiration, device requests renewal
- Prevents IP exhaustion in dynamic networks

**Real-Life Example:**
When you connect your phone to your home Wi-Fi:
1. Phone sends DHCP Discover message
2. Router's DHCP server (usually integrated) offers an IP like 192.168.1.105
3. Phone accepts and uses that IP for internet
4. When you leave the network, the IP returns to the pool for another device
5. Next time you connect, you might get 192.168.1.106 instead

---

### 7. HTTP (HyperText Transfer Protocol)

#### What is HTTP?
HTTP is the foundation of web communication. It's a stateless protocol where each request is independent. The client sends a request, and the server sends a response.

#### HTTP Methods (Verbs):
| Method | Purpose | Safe | Idempotent |
|--------|---------|------|-----------|
| **GET** | Retrieve data | Yes | Yes |
| **POST** | Submit data | No | No |
| **PUT** | Replace entire resource | No | Yes |
| **DELETE** | Remove resource | No | Yes |
| **PATCH** | Partial update | No | No |
| **HEAD** | Like GET, but no body | Yes | Yes |
| **OPTIONS** | Describe communication options | Yes | Yes |

#### HTTP Request Structure:
```
GET /path/to/resource HTTP/1.1
Host: www.example.com
User-Agent: Mozilla/5.0
Accept: text/html
Cookie: sessionId=abc123
```

#### HTTP Response Structure:
```
HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: 1234
Set-Cookie: sessionId=xyz789

<html>
  <!-- webpage content -->
</html>
```

**Real-Life Example:**
When you search on Google:
- **Method**: POST
- **Data Sent**: Your search query "JavaScript tutorial"
- **Google's Server**: Processes the query
- **Response**: Returns search results with HTTP 200 (OK)
- **Your Browser**: Displays the results

---

### 8. HTTPS (HyperText Transfer Protocol Secure)

#### What is HTTPS?
HTTPS is HTTP with encryption. It uses SSL/TLS protocols to encrypt data in transit, protecting it from interception by hackers.

#### SSL/TLS Encryption Process:
1. **Client Hello**: Browser initiates secure connection
2. **Server Certificate**: Server sends its public key and certificate
3. **Key Exchange**: Both parties agree on encryption keys
4. **Encrypted Communication**: All subsequent data is encrypted
5. **Secure Connection**: Green padlock appears in browser

#### Why HTTPS Matters:
- **Confidentiality**: Eavesdroppers can't read your data
- **Integrity**: Data can't be modified in transit
- **Authentication**: Verifies server identity (reduces phishing)
- **SEO Benefit**: Google prioritizes HTTPS sites

**Real-Life Example:**
Online Banking Security:
- When you log into your bank account at https://bank.example.com
- Your login credentials are encrypted
- Even if someone intercepts the traffic, they see: `ಟiಸ˜{ªñ¥ü}ñƒ`
- Without encryption (HTTP), they'd see: username=john&password=secure123

---

### 9. Inspect (Browser Developer Tools)

#### What are Browser Developer Tools?
Developer Tools allow you to inspect, debug, and analyze web pages. Access with F12 or Ctrl+Shift+I.

#### Key Tabs:

**Inspector/Elements Tab:**
- View and edit HTML structure
- Modify CSS live in browser
- See computed styles
- Debug layout issues

**Console Tab:**
- Execute JavaScript commands
- View error messages
- Debug code with console.log()

**Network Tab:**
- Monitor all HTTP requests and responses
- View request/response headers
- Check file sizes and load times
- Identify slow resources

**Application Tab:**
- View stored cookies
- Local storage and session storage
- View service workers
- Manage cache

**Example Inspection:**
```javascript
// In Console, you can test code live:
document.querySelectorAll('button').forEach(btn => {
  btn.style.backgroundColor = 'red';
});

// View network requests:
// Go to Network tab → Reload page → See all requests
// Click any request to view headers, response, timing
```

**Real-Life Example:**
A website loads slowly. Using DevTools:
1. Open Network tab and reload
2. See that images are 5MB each
3. Identify that this is the bottleneck
4. Developer optimizes images to 500KB
5. Website now loads 10x faster

---

### 10. HTTP Status Codes

Status codes indicate the result of an HTTP request. They're grouped into five categories:

#### 1xx - Informational (Rare)
- **100 Continue**: Request is proceeding
- **101 Switching Protocols**: Protocol upgrade (HTTP → WebSocket)

#### 2xx - Success (Happy Codes!)
- **200 OK**: Request successful, data follows
- **201 Created**: Resource successfully created
- **204 No Content**: Request successful, no content to return
- **206 Partial Content**: Server sending partial resource

#### 3xx - Redirection (Follow the Sign)
- **301 Moved Permanently**: Resource moved to new URL forever
- **302 Found**: Temporary redirect to another URL
- **304 Not Modified**: Client has cached version; use it
- **307 Temporary Redirect**: Temporary redirect, method preserved

#### 4xx - Client Error (Your Fault)
- **400 Bad Request**: Malformed request syntax
- **401 Unauthorized**: Authentication required
- **403 Forbidden**: Authenticated but not authorized
- **404 Not Found**: Resource doesn't exist
- **409 Conflict**: Request conflicts with current state
- **429 Too Many Requests**: Rate limit exceeded

#### 5xx - Server Error (Our Fault)
- **500 Internal Server Error**: Unexpected server error
- **502 Bad Gateway**: Invalid response from upstream server
- **503 Service Unavailable**: Server temporarily overloaded
- **504 Gateway Timeout**: Upstream server not responding

**Real-Life Examples:**

```
Scenario 1: Visit a dead link
→ Server responds with 404 (Not Found)

Scenario 2: Instagram limits API requests
→ Server responds with 429 (Too Many Requests)

Scenario 3: Bank website during maintenance
→ Server responds with 503 (Service Unavailable)

Scenario 4: Old website URL redirects to new one
→ Server responds with 301 (Moved Permanently)

Scenario 5: Twitter API authentication fails
→ Server responds with 401 (Unauthorized)
```

---

## HTML, CSS, and JavaScript

### HTML (HyperText Markup Language)

#### What is HTML?
HTML provides the structure and content of web pages using semantic markup. It's the foundation upon which CSS and JavaScript build.

#### HTML Basics:

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width">
  <title>My Awesome Page</title>
</head>
<body>
  <header>
    <h1>Welcome to My Site</h1>
    <nav>
      <a href="/">Home</a>
      <a href="/about">About</a>
    </nav>
  </header>

  <main>
    <article>
      <h2>Article Title</h2>
      <p>Article content here...</p>
    </article>
  </main>

  <footer>
    <p>&copy; 2026 My Company</p>
  </footer>
</body>
</html>
```

#### Semantic Elements:
- **`<header>`**: Page or section header
- **`<nav>`**: Navigation links
- **`<main>`**: Main content of page
- **`<article>`**: Self-contained content
- **`<section>`**: Thematic grouping
- **`<aside>`**: Sidebar or supplementary content
- **`<footer>`**: Footer information

#### Forms and Input Validation:

```html
<form action="/submit" method="POST">
  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required>

  <label for="age">Age:</label>
  <input type="number" id="age" name="age" min="18" max="100">

  <label for="message">Message:</label>
  <textarea id="message" name="message" rows="5"></textarea>

  <button type="submit">Submit</button>
</form>
```

**Real-Life Example:**
YouTube's HTML structure includes semantic elements for accessibility and SEO. Screen readers understand the page structure, and search engines properly index video metadata.

---

### CSS (Cascading Style Sheets)

#### What is CSS?
CSS styles HTML elements, controlling layout, colors, typography, animations, and responsive behavior.

#### CSS Box Model:

```
┌─────────────────────────────┐
│        Margin (outer)       │
│  ┌─────────────────────┐   │
│  │ Border              │   │
│  │  ┌───────────────┐  │   │
│  │  │ Padding       │  │   │
│  │  │ ┌───────────┐ │  │   │
│  │  │ │ Content   │ │  │   │
│  │  │ └───────────┘ │  │   │
│  │  └───────────────┘  │   │
│  └─────────────────────┘   │
└─────────────────────────────┘
```

#### Styling Example:

```css
body {
  font-family: 'Segoe UI', Tahoma, sans-serif;
  line-height: 1.6;
  color: #333;
}

.container {
  max-width: 1200px;
  margin: 0 auto;
  padding: 20px;
}

button {
  background-color: #007bff;
  color: white;
  padding: 10px 20px;
  border: none;
  border-radius: 5px;
  cursor: pointer;
  transition: background-color 0.3s ease;
}

button:hover {
  background-color: #0056b3;
}
```

#### Flexbox (Modern Layout):

```css
.navbar {
  display: flex;
  justify-content: space-between;
  align-items: center;
  background-color: #333;
  padding: 1rem;
}

.navbar a {
  color: white;
  text-decoration: none;
  margin: 0 15px;
}
```

#### CSS Grid (Advanced Layout):

```css
.gallery {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
  gap: 20px;
}

.gallery-item {
  background-color: #f0f0f0;
  padding: 20px;
  border-radius: 8px;
}
```

#### Responsive Design:

```css
/* Mobile first approach */
.hero {
  font-size: 16px;
  padding: 20px;
}

/* Tablet and up */
@media (min-width: 768px) {
  .hero {
    font-size: 24px;
    padding: 40px;
  }
}

/* Desktop and up */
@media (min-width: 1024px) {
  .hero {
    font-size: 32px;
    padding: 60px;
  }
}
```

**Real-Life Example:**
Netflix uses Flexbox and Grid for their responsive layout. On mobile, content stacks vertically. On desktop, it displays in a grid. CSS media queries ensure it looks perfect on all devices.

---

### JavaScript

#### What is JavaScript?
JavaScript adds interactivity to web pages. It runs in the browser and can manipulate HTML, respond to events, and communicate with servers.

#### DOM Manipulation:

```javascript
// Select elements
const button = document.getElementById('myButton');
const items = document.querySelectorAll('.item');

// Create elements
const newDiv = document.createElement('div');
newDiv.textContent = 'Hello World';
document.body.appendChild(newDiv);

// Modify content
document.getElementById('title').textContent = 'New Title';
document.getElementById('title').innerHTML = '<strong>Bold Title</strong>';

// Add/remove classes
element.classList.add('active');
element.classList.remove('hidden');
element.classList.toggle('visible');

// Set attributes
element.setAttribute('data-id', '123');
const id = element.getAttribute('data-id');
```

#### Event Handling:

```javascript
// Click event
button.addEventListener('click', function() {
  console.log('Button clicked!');
  alert('You clicked me!');
});

// Form submission
document.getElementById('form').addEventListener('submit', function(e) {
  e.preventDefault(); // Stop default behavior
  const formData = new FormData(this);
  const data = Object.fromEntries(formData);
  console.log(data);
});

// Keyboard events
document.addEventListener('keydown', function(e) {
  if (e.key === 'Enter') {
    console.log('Enter key pressed');
  }
});

// Mouse events
element.addEventListener('mouseover', () => {
  element.style.backgroundColor = 'yellow';
});

element.addEventListener('mouseout', () => {
  element.style.backgroundColor = 'white';
});
```

#### Asynchronous Programming (Promises & Async/Await):

```javascript
// Using Promises
fetch('https://api.example.com/data')
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));

// Using Async/Await (Modern)
async function fetchData() {
  try {
    const response = await fetch('https://api.example.com/data');
    const data = await response.json();
    console.log(data);
  } catch (error) {
    console.error('Error:', error);
  }
}

fetchData();
```

#### Fetch API for HTTP Requests:

```javascript
// GET request
fetch('/api/users')
  .then(res => res.json())
  .then(users => console.log(users));

// POST request with data
fetch('/api/users', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json'
  },
  body: JSON.stringify({
    name: 'John Doe',
    email: 'john@example.com'
  })
})
.then(res => res.json())
.then(data => console.log('User created:', data));

// PUT request (update)
fetch('/api/users/1', {
  method: 'PUT',
  headers: { 'Content-Type': 'application/json' },
  body: JSON.stringify({ name: 'Jane Doe' })
})
.then(res => res.json())
.then(data => console.log('User updated:', data));

// DELETE request
fetch('/api/users/1', { method: 'DELETE' })
  .then(res => res.json())
  .then(data => console.log('User deleted:', data));
```

#### Complete Real-Life Example - Todo App:

```html
<!DOCTYPE html>
<html>
<head>
  <title>Todo App</title>
  <style>
    body { font-family: Arial; margin: 20px; }
    #todo-input { padding: 8px; width: 300px; }
    #add-btn { padding: 8px 15px; cursor: pointer; }
    #todo-list { margin-top: 20px; }
    .todo-item { padding: 10px; margin: 5px 0; background: #f0f0f0; }
    .completed { text-decoration: line-through; color: gray; }
  </style>
</head>
<body>
  <h1>My Todo App</h1>
  <input type="text" id="todo-input" placeholder="Add a new task...">
  <button id="add-btn">Add Todo</button>
  <ul id="todo-list"></ul>

  <script>
    const input = document.getElementById('todo-input');
    const addBtn = document.getElementById('add-btn');
    const todoList = document.getElementById('todo-list');

    // Load todos from API
    async function loadTodos() {
      try {
        const response = await fetch('/api/todos');
        const todos = await response.json();
        todos.forEach(todo => addTodoToUI(todo));
      } catch (error) {
        console.error('Failed to load todos:', error);
      }
    }

    // Add todo to UI
    function addTodoToUI(todo) {
      const li = document.createElement('li');
      li.className = 'todo-item';
      if (todo.completed) li.classList.add('completed');
      li.innerHTML = `
        <input type="checkbox" ${todo.completed ? 'checked' : ''}>
        ${todo.text}
        <button onclick="deleteTodo(${todo.id})">Delete</button>
      `;
      todoList.appendChild(li);
    }

    // Add new todo
    addBtn.addEventListener('click', async function() {
      if (!input.value) return;
      
      try {
        const response = await fetch('/api/todos', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ text: input.value })
        });
        const todo = await response.json();
        addTodoToUI(todo);
        input.value = '';
      } catch (error) {
        console.error('Failed to add todo:', error);
      }
    });

    // Delete todo
    async function deleteTodo(id) {
      try {
        await fetch(`/api/todos/${id}`, { method: 'DELETE' });
        location.reload(); // Refresh page
      } catch (error) {
        console.error('Failed to delete todo:', error);
      }
    }

    // Load todos on page load
    loadTodos();
  </script>
</body>
</html>
```

---

## Summary

Week 8 covers the full web stack:
- **Networking**: Understanding how data travels across the internet
- **Web Protocols**: HTTP/HTTPS for client-server communication
- **Frontend**: HTML, CSS, and JavaScript for building interactive web pages
- **Developer Tools**: Using DevTools to inspect, debug, and optimize websites

By mastering these topics, you'll understand how the web works and be able to build modern, responsive, and secure web applications!
 
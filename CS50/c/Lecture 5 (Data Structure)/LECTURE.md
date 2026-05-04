# CS50 Lecture 5: Data Structures

## Table of Contents
1. [Abstract Data Type (ADT)](#abstract-data-type-adt)
2. [Stacks](#stacks)
3. [Queues](#queues)
4. [Key Concepts Summary](#key-concepts-summary)

---

## Abstract Data Type (ADT)

### What is an Abstract Data Type?
An **Abstract Data Type (ADT)** is a mathematical model for a data type that specifies:
- **Data**: What kind of data is stored
- **Operations**: What operations can be performed on the data
- **Behavior**: How the operations behave (without specifying implementation)

### Key Characteristics
- **Abstraction**: Hides implementation details
- **Encapsulation**: Data and operations are bundled together
- **Interface**: Defines what you can do, not how it's done

### Example: Integer ADT
```c
// Operations: add, subtract, multiply, divide
// But we don't care how integers are stored in memory
int x = 5;
int y = 3;
int sum = x + y;  // We know what happens, not how
```

### Why ADTs Matter
- ✓ Allows us to think about data structures at a high level
- ✓ Enables code reusability
- ✓ Separates interface from implementation
- ✓ Makes programs easier to maintain and modify

---

## Stacks

### What is a Stack?
A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle.

### Stack Operations
| Operation | Description | Example |
|-----------|-------------|---------|
| **Push** | Add an element to the top | Push 5 onto stack |
| **Pop** | Remove and return top element | Pop returns 5 |
| **Peek/Top** | View top element without removing | Peek shows 5 |
| **IsEmpty** | Check if stack is empty | Returns true/false |

### Stack Visualization
```
Push 1: [1]
Push 2: [1, 2]
Push 3: [1, 2, 3]
Pop:    [1, 2]    (returns 3)
Pop:    [1]       (returns 2)
```

### Stack Implementation in C (Array-based)
```c
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}
```

### Real-World Examples
- **Function Call Stack**: Programming languages use stacks to manage function calls
- **Undo Operations**: Text editors use stacks to track changes
- **Browser Back Button**: Web browsers use stacks to track page history

---

## Queues

### What is a Queue?
A **queue** is a linear data structure that follows the **First In, First Out (FIFO)** principle.

### Queue Operations
| Operation | Description | Example |
|-----------|-------------|---------|
| **Enqueue** | Add an element to the rear | Enqueue 5 |
| **Dequeue** | Remove and return front element | Dequeue returns 1 |
| **Front/Peek** | View front element without removing | Peek shows 1 |
| **IsEmpty** | Check if queue is empty | Returns true/false |

### Queue Visualization
```
Enqueue 1: [1]
Enqueue 2: [1, 2]
Enqueue 3: [1, 2, 3]
Dequeue:   [2, 3]    (returns 1)
Dequeue:   [3]       (returns 2)
```

### Queue Implementation in C (Array-based)
```c
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++(q->rear)] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}
```

### Real-World Examples
- **Print Queue**: Documents wait in a queue to be printed
- **Process Scheduling**: Operating systems use queues to manage processes
- **Breadth-First Search**: Algorithms use queues to explore nodes level by level

---

## Key Concepts Summary

### Abstract Data Type (ADT)
- Mathematical model defining data and operations
- Separates interface from implementation
- Enables modular programming

### Stacks (LIFO)
- Last In, First Out structure
- Operations: Push, Pop, Peek
- Used for function calls, undo operations, browser history

### Queues (FIFO)
- First In, First Out structure
- Operations: Enqueue, Dequeue, Peek
- Used for print queues, process scheduling, BFS

### Comparison
| Feature | Stack | Queue |
|---------|-------|-------|
| Principle | LIFO | FIFO |
| Add Operation | Push | Enqueue |
| Remove Operation | Pop | Dequeue |
| Real-world | Function calls | Print jobs |

### Implementation Options
- **Array-based**: Fixed size, fast access
- **Linked List-based**: Dynamic size, flexible
- **Choice depends on use case**: Arrays for known sizes, linked lists for unknown sizes

---

*Note: This lecture introduces fundamental data structures. In future lectures, we'll explore more complex structures like trees, graphs, and hash tables.*
# CS50 Lecture 5: Data Structures

## Table of Contents
1. [Abstract Data Type (ADT)](#abstract-data-type-adt)
2. [Stacks](#stacks)
3. [Queues](#queues)
4. [Resizing Arrays](#resizing-arrays)
5. [Linked Lists](#linked-lists)
6. [Key Concepts Summary](#key-concepts-summary)

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

## Resizing Arrays

### What is Array Resizing?
**Array resizing** is the process of dynamically increasing or decreasing the size of an array at runtime. Since fixed-size arrays have limitations, resizing allows us to:
- Grow arrays when we run out of space
- Shrink arrays to save memory
- Adapt to unknown data sizes

### The Problem with Fixed Arrays
```c
int arr[10];  // Fixed size of 10
// What if we need more than 10 elements?
```

### Resizing Strategy
When an array becomes full:
1. Create a new, larger array (usually 2x the original size)
2. Copy all elements from the old array to the new array
3. Free the old array's memory
4. Use the new array

### Array Resizing Implementation in C
```c
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* items;
    int size;      // Current number of elements
    int capacity;  // Total space allocated
} DynamicArray;

// Initialize with initial capacity
DynamicArray* initArray(int capacity) {
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    arr->items = (int*)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

// Add element with automatic resizing
void append(DynamicArray* arr, int value) {
    if (arr->size == arr->capacity) {
        // Double the capacity
        arr->capacity *= 2;
        int* newItems = (int*)malloc(arr->capacity * sizeof(int));
        
        // Copy old items to new array
        for (int i = 0; i < arr->size; i++) {
            newItems[i] = arr->items[i];
        }
        
        // Free old array
        free(arr->items);
        arr->items = newItems;
    }
    arr->items[arr->size++] = value;
}

// Get element
int get(DynamicArray* arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->items[index];
    }
    printf("Index out of bounds\n");
    return -1;
}

// Free memory
void freeArray(DynamicArray* arr) {
    free(arr->items);
    free(arr);
}
```

### Time Complexity Analysis
| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Append | O(1) | O(n) (when resize needed) |
| Get | O(1) | O(1) |
| Insert at middle | O(n) | O(n) |
| Delete | O(n) | O(n) |

### Key Points
- ✓ Doubling the capacity keeps amortized time O(1)
- ✓ More efficient than copying every time
- ✓ Trades space for time

---

## Linked Lists

### What is a Linked List?
A **linked list** is a linear data structure where elements (called **nodes**) are connected via pointers. Unlike arrays, nodes don't need to be adjacent in memory.

### Linked List Node Structure
```c
typedef struct node {
    int data;              // Data stored in node
    struct node* next;     // Pointer to next node
} Node;
```

### Linked List Visualization
```
[Data | Next] -> [Data | Next] -> [Data | Next] -> NULL
  Node 1           Node 2           Node 3
```

### Linked List Operations
| Operation | Description |
|-----------|-------------|
| **Insert** | Add a node at a position |
| **Delete** | Remove a node |
| **Search** | Find a node with specific data |
| **Traverse** | Visit each node |

### Basic Linked List Operations in C
```c
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Insert at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Delete a node with specific data
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }
    
    // If head needs to be deleted
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    // Search and delete in the middle or end
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return head;
        }
        current = current->next;
    }
    
    return head;
}

// Search for a value
Node* search(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Traverse and print
void traverse(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free the entire list
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
```

### Time Complexity Comparison
| Operation | Array | Linked List |
|-----------|-------|-------------|
| Access | O(1) | O(n) |
| Insert at beginning | O(n) | O(1) |
| Insert at end | O(1) or O(n) | O(n) |
| Delete | O(n) | O(n) |
| Search | O(n) | O(n) |

### Advantages of Linked Lists
- ✓ Dynamic size (grows as needed)
- ✓ Efficient insertion/deletion at beginning
- ✓ No memory waste (only allocate what's used)
- ✓ Flexible memory allocation (non-contiguous)

### Disadvantages of Linked Lists
- ✗ No direct access (must traverse from head)
- ✗ Extra memory for pointers
- ✗ Cache-unfriendly (scattered memory)
- ✗ More complex to implement

### Real-World Applications
- **Undo functionality**: Each state points to the previous state
- **Playlist**: Songs linked together
- **Browser history**: Pages linked in order
- **Memory management**: Free blocks managed as linked list

### Variants of Linked Lists
1. **Singly Linked List**: Each node points to the next (basic)
2. **Doubly Linked List**: Each node points to next and previous
3. **Circular Linked List**: Last node points back to first

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

### Comparison: Stacks vs Queues
| Feature | Stack | Queue |
|---------|-------|-------|
| Principle | LIFO | FIFO |
| Add Operation | Push | Enqueue |
| Remove Operation | Pop | Dequeue |
| Real-world | Function calls | Print jobs |

### Comparison: Arrays vs Linked Lists
| Feature | Array | Linked List |
|---------|-------|-------------|
| Access Time | O(1) | O(n) |
| Insert (beginning) | O(n) | O(1) |
| Insert (end) | O(1)* | O(n) |
| Memory | Contiguous | Scattered |
| Size | Fixed** | Dynamic |
| Cache Performance | Good | Poor |
| Memory Overhead | None | Pointers |

*With amortized resizing  
**Unless resizable array is used

### When to Use What
- **Array**: Fast access, known size, cache-friendly
- **Resizable Array**: Unknown size, need flexibility
- **Stack**: LIFO operations, function calls, undo/redo
- **Queue**: FIFO operations, scheduling, BFS
- **Linked List**: Frequent insertions/deletions, unknown size, memory flexibility

---

*Note: This lecture introduces fundamental data structures. In future lectures, we'll explore more complex structures like trees, graphs, and hash tables.*
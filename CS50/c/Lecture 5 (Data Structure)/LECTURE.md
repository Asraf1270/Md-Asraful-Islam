# CS50 Lecture 5: Data Structures

## Table of Contents
1. [Abstract Data Type (ADT)](#abstract-data-type-adt)
2. [Stacks](#stacks)
3. [Queues](#queues)
4. [Resizing Arrays](#resizing-arrays)
5. [Linked Lists](#linked-lists)
6. [Trees](#trees)
7. [Dictionaries](#dictionaries)
8. [Hashing and Hash Tables](#hashing-and-hash-tables)
9. [Tries](#tries)
10. [Comprehensive Summary](#comprehensive-summary)
11. [Final Notes](#final-notes)

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

## Trees

### What is a Tree?
A **tree** is a hierarchical data structure where elements (called **nodes**) are connected by **edges**. It has:
- A single **root** node at the top
- **Parent-child** relationships
- No cycles (unlike graphs)

### Tree Terminology
```
        A (root)
       / \
      B   C
     / \   \
    D   E   F (leaf nodes)
```

| Term | Definition |
|------|------------|
| **Root** | The topmost node |
| **Leaf** | A node with no children |
| **Height** | Distance from root to deepest leaf |
| **Depth** | Distance from root to a specific node |
| **Subtree** | A tree formed by a node and descendants |

### Binary Search Trees (BST)
A **Binary Search Tree** is a tree where:
- Each node has at most 2 children (left and right)
- Left child value < Parent value < Right child value
- Enables efficient searching

### BST Node Structure
```c
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} TreeNode;
```

### Binary Search Tree Operations
```c
// Create a new node
TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a value
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Search for a value
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (value == root->value) {
        return root;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Inorder traversal (Left-Root-Right) - prints sorted
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Find minimum
TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node
TreeNode* delete(TreeNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (value < root->value) {
        root->left = delete(root->left, value);
    } else if (value > root->value) {
        root->right = delete(root->right, value);
    } else {
        // Node to delete found
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node has two children
        TreeNode* temp = findMin(root->right);
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }
    return root;
}
```

### Binary Search Tree Complexity
| Operation | Best Case | Worst Case |
|-----------|-----------|------------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Traverse | O(n) | O(n) |

**Note**: Worst case occurs when tree becomes skewed (like a linked list). Balanced trees like AVL or Red-Black trees maintain O(log n) in all cases.

### Real-World Applications
- **Database indexing**: Fast lookups
- **File systems**: Directory hierarchies
- **DOM structure**: HTML/XML documents
- **Expression parsing**: Mathematical expressions

---

## Dictionaries

### What is a Dictionary?
A **dictionary** is an abstract data type that maps **keys** to **values**. Also called:
- **Hash map** (implementation detail)
- **Associative array**
- **Key-value store**

### Dictionary Operations
| Operation | Description |
|-----------|-------------|
| **Put/Set** | Add or update key-value pair |
| **Get** | Retrieve value by key |
| **Delete** | Remove key-value pair |
| **Contains** | Check if key exists |

### Dictionary Concept Example
```c
// Conceptual dictionary
// phone_numbers["Alice"] = "555-1234"
// phone_numbers["Bob"] = "555-5678"
// phone_numbers["Charlie"] = "555-9999"

struct Dictionary {
    char* keys[100];
    char* values[100];
    int size;
};
```

### Key Requirements
- Keys must be unique
- Fast lookup (ideally O(1))
- Support dynamic insertion/deletion

### Real-World Applications
- **Database records**: ID → Customer info
- **Phone books**: Name → Phone number
- **IP routing**: IP address → Router
- **Caching**: Query → Result

---

## Hashing and Hash Tables

### What is Hashing?
**Hashing** is a technique that converts a key into an array index using a **hash function**. This enables O(1) lookups.

### Hash Function
A good hash function should:
- ✓ Be deterministic (same input = same output)
- ✓ Distribute keys uniformly
- ✓ Be fast to compute
- ✓ Minimize collisions

### Simple Hash Function Example
```c
// Hash function for strings
int hash(char* key, int table_size) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % table_size;
}
```

### Hash Table
A **hash table** uses a hash function to store key-value pairs in an array.

```
Hash Function: hash(key) = key % 10

key = "Alice" → hash = 1 → Array[1]
key = "Bob"   → hash = 3 → Array[3]
key = "Charlie" → hash = 7 → Array[7]
```

### Collisions
**Collision** occurs when two keys hash to the same index.

### Collision Resolution Techniques

#### 1. Chaining (Most Common)
Store colliding entries in a linked list at each index.
```
Array:
[0] → NULL
[1] → ["Alice"] → NULL
[2] → ["Bob"] → ["Eve"] → NULL
[3] → NULL
```

#### 2. Open Addressing
Find another empty slot in the array.
- **Linear probing**: Check next index
- **Quadratic probing**: Check index + i²
- **Double hashing**: Use second hash function

### Hash Table Implementation (with Chaining)
```c
#define TABLE_SIZE 100

typedef struct {
    char* key;
    char* value;
} HashEntry;

typedef struct node {
    HashEntry entry;
    struct node* next;
} HashNode;

typedef struct {
    HashNode* table[TABLE_SIZE];
} HashTable;

// Initialize hash table
void initHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Hash function
int hash(char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// Insert into hash table
void insert(HashTable* ht, char* key, char* value) {
    int index = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->entry.key = key;
    newNode->entry.value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search in hash table
char* search(HashTable* ht, char* key) {
    int index = hash(key);
    HashNode* current = ht->table[index];
    
    while (current != NULL) {
        if (strcmp(current->entry.key, key) == 0) {
            return current->entry.value;
        }
        current = current->next;
    }
    return NULL;
}
```

### Hash Table Complexity
| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |
| Delete | O(1) | O(n) |

**Average**: Good hash function, no collisions  
**Worst**: All keys hash to same index (chain becomes linked list)

### Load Factor
**Load factor** = Number of entries / Table size

- If load factor > 0.75, resize table (rehash all entries)
- Keeps hash table performance efficient

### Real-World Applications
- **Database indexing**: Fast lookups
- **Caching**: URL → Webpage
- **Symbol tables**: Variable → Value
- **Spell checkers**: Dictionary lookup
- **De-duplication**: Remove duplicates

---

## Tries

### What is a Trie?
A **Trie** (pronounced "tree") is a tree-like data structure used for efficient string searching. Also called a **prefix tree**.

### Trie Structure
Each node represents a character, and paths from root represent strings.

```
        root
       / | \
      a  b  c
      |     |
      t     a
      |     |
      e     t
```
Words: "ate", "cat"

### Trie Node Structure
```c
#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;  // 1 if this node ends a word
} TrieNode;
```

### Trie Operations
```c
// Create new trie node
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Insert word into trie
void insert(TrieNode* root, char* word) {
    TrieNode* current = root;
    
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        
        if (current->children[index] == NULL) {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

// Search for word in trie
int search(TrieNode* root, char* word) {
    TrieNode* current = root;
    
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        
        if (current->children[index] == NULL) {
            return 0;  // Not found
        }
        current = current->children[index];
    }
    
    return current->isEndOfWord;
}

// Prefix search - check if prefix exists
int searchPrefix(TrieNode* root, char* prefix) {
    TrieNode* current = root;
    
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    
    return 1;  // Prefix exists
}
```

### Trie Complexity
| Operation | Complexity | Notes |
|-----------|------------|-------|
| Insert | O(m) | m = word length |
| Search | O(m) | m = word length |
| Delete | O(m) | m = word length |
| Prefix search | O(m) | m = prefix length |

**Key advantage**: Independent of number of words!

### Trie vs Hash Table
| Feature | Trie | Hash Table |
|---------|------|------------|
| Search | O(m) | O(1) avg |
| Insert | O(m) | O(1) avg |
| Prefix search | O(m) | O(n) |
| Space | High | Moderate |
| Collision handling | No | Yes |

### Real-World Applications
- **Autocomplete**: Search suggestions
- **Spell checking**: Dictionary lookups
- **IP routing**: Route prefixes
- **Phone directories**: Phone number prefixes
- **Genome sequencing**: DNA pattern matching
- **Word games**: Scrabble solvers

---

## Comprehensive Summary

### Data Structures at a Glance

#### Linear Structures
| Structure | Principle | Best Use |
|-----------|-----------|----------|
| **Array** | Sequential, indexed | Fast random access |
| **Linked List** | Pointer-based | Frequent insertions |
| **Stack** | LIFO | Function calls, undo |
| **Queue** | FIFO | Task scheduling |

#### Tree Structures
| Structure | Principle | Best Use |
|-----------|-----------|----------|
| **Binary Tree** | Hierarchical | General organization |
| **BST** | Ordered hierarchy | Sorted data, searching |
| **Balanced Tree** | Self-balancing | Guaranteed O(log n) |

#### Hash-Based
| Structure | Principle | Best Use |
|-----------|-----------|----------|
| **Hash Table** | Key → Index → Value | Fast key lookup |
| **Dictionary** | Abstract key-value store | Phone books, caches |
| **Trie** | Prefix tree | Autocomplete, spell check |

### Time Complexity Comparison

```
             Insert    Search    Delete    Access
Array        O(n)      O(n)*     O(n)      O(1)
Linked List  O(1)**    O(n)      O(n)      O(n)
Stack        O(1)      O(n)      O(1)***   -
Queue        O(1)      O(n)      O(1)***   -
BST          O(log n)  O(log n)  O(log n)  -
Hash Table   O(1)      O(1)      O(1)      -
Trie         O(m)      O(m)      O(m)      -

* Without index; O(1) with index
** At beginning; O(n) at end
*** LIFO/FIFO operations only
m = string/key length
```

### Choosing the Right Data Structure

**For fast lookups:**
- Hash Table (O(1) average)
- BST (O(log n) guaranteed)

**For insertions/deletions:**
- Linked List (O(1) at beginning)
- BST (O(log n) balanced)

**For LIFO operations:**
- Stack

**For FIFO operations:**
- Queue

**For prefix-based operations:**
- Trie

**For hierarchical data:**
- Tree/BST

### Memory Considerations
- **Array**: Fixed memory, O(n) space
- **Linked List**: Dynamic memory, O(n) space + pointers
- **Hash Table**: O(n) space, factor of load
- **Trie**: O(m × n) space, m = alphabet size, n = nodes
- **BST**: O(n) space

---

## Final Notes

### Key Takeaways from Data Structures Lecture

1. **Understand the Tradeoffs**
   - Speed vs. Space
   - Implementation complexity vs. efficiency
   - Best case vs. worst case

2. **Know Your Use Cases**
   - Different data structures solve different problems
   - No "one size fits all" solution
   - Context matters

3. **Master Fundamentals**
   - ADTs: Think in abstractions
   - Complexity analysis: Predict performance
   - Memory management: Avoid leaks in C

4. **Next Steps**
   - Practice implementing data structures
   - Understand when to use each structure
   - Learn advanced structures (B-trees, skip lists, graphs)
   - Study algorithm design patterns

### Common Pitfalls to Avoid
- ⚠️ Using wrong structure for your use case
- ⚠️ Ignoring memory leaks (in C)
- ⚠️ Not considering edge cases
- ⚠️ Premature optimization without profiling
- ⚠️ Confusing time and space complexity

### Practice Recommendations
1. Implement each data structure from scratch
2. Solve LeetCode/HackerRank problems
3. Analyze your code's complexity
4. Optimize based on requirements
5. Study real-world implementations

### Resources for Further Learning
- "Introduction to Algorithms" (CLRS) - comprehensive reference
- "Data Structures and Algorithms Made Easy" - practical guide
- LeetCode/HackerRank - hands-on practice
- CS50's online course materials

---

**🎓 Congratulations!** You've completed CS50 Lecture 5: Data Structures. You now understand:
- Abstract data types and their importance
- Linear structures (arrays, linked lists, stacks, queues)
- Tree-based structures (trees, BSTs)
- Hash-based structures (hash tables, tries, dictionaries)
- When and how to apply each structure

**Remember**: Mastering data structures is fundamental to becoming a skilled programmer. These concepts will appear in every interview and real-world project. Practice, experiment, and build!

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


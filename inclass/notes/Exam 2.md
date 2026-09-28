### 2 entry points to a linked list?
- Head
- Tail

### T/F: List are more expensive in terms of size to maintain than an array?
- False
### What are the two key piece of info that all link based implementation need?
- Data
- Link

### What are the 3 rules of a BST?
- Every thing in the left subtree must be less then the root
- Everything in the right subtree must be greater then the root
- Both the left and the right subtree must be BST

### T/F: Is a tree t is empty, it is considered a full tree?
- True

### How many nodes are there in a BST with height 4?
- 2^4 -1 = 15

### What are the 3 different conditions of removal of a node in a BST?
- If no children, then remove
- If 1 child then remove, and replace w/ the child
- 

### T/F: When performing deletion of a node with 2 children, we use in order traversal?
- T

### What color is the color of the root in a red/Black tree?
- Black

### Provide the 3 steps of post order traversal of a reb/Black tree?


### If you have key 5 and hash table of size 6, what will it hash to?
- Bucket 5, the last one

### T/F: a perfect hash function locates each key to a unique location?
- T

### When 2 or more keys map to the same location, what is it called?
- collision

###  Provide me an example of an open addressing collision scheme
- Linear, quadratic, double hashing

### What is the hash for linear probing?
- key % size + attempts

### What is the number 1 downside of linear probing?
- Primary clustering

### T/F: Separate chaining is an example of closed addressing scheme?
- T

### What is the time complexity of a singularly linked list in terms of separate chaining?
- O(n)

### How is load factor calculated in hashing? The Equation?
- \# of keys/table size


## Linked List
- Nodes: storage units which are linked together to create "chains"
- Two key aspects: Data and Link
- Linked base list normally have a O(n) time complexity for traversal/searching

## Binary Trees
![[Pasted image 20251213144243.png]]
- Every node has at most two children
- Left child is less then parent
- Right child is greater than parent
- **Full BT**: Assume we have a tree of height h, all nodes that are at a level less than h have two children each.
	- A full binary tree of height h ≥ 0 has 2h -1 nodes
	- The maximum number of nodes that a binary tree of height h can have is 2h -1
- **Complete BT**: A binary tree that is full down to level h-1, with level h filled in from left to right.
	- All nodes at level h-2 and above have two children each.
	- When a node at level h-1 has children, all nodes to its left at the same level have two children each.
	- When a node at level h-1 has one child it is a left child.
- Fully Balanced: If the height of any node’s right subtree differs from the height of the node’s left subtree by no more than 1.

## Red-Black Tree
- A type of Balanced Search Tree
- Each node is either red or black
- Most BST operations are O(h) time complexity, but worst case O(n) which is when the tree is unbalanced
- Balance aids in optimal search, insertion, and deletion times
- **6 Rules for Red Black Tree**
	- Must be a BST
	- The level 1 root must be black
	- Every node when inserted begins as red
	- If a node is red then its children must be black
	- Every path from a Node to a nullptr must contain the same number of Black Nodes
	- Every nullptr leaf must be black


## Hash Tables
- Stores elements in "buckets"
- General Hash Function: hash = key % size
- Collision 2 elements share the same hash, element b hashed to bucket x and element a is currently there
**Operations**
- **Insert(x)**
	- Keep probing until an empty slot is found. Once an empty slot is found, insert key.
- **Search(x)**
	- Keep probing until slot’s key doesn’t become equal to x or an empty slot is reached.
- **Delete(k)**
	- Keep probing until the keys slot is found and remove the key.
### Open Addressing
**Status Enumeration**
- **Occupied**
	- This indexed position is currently held by an entry in the Hash Table.
- **Empty**
	- This indexed position has never been used by an entry.
- **Removed**
	- This indexed position previously held an entry (Occupied) but is now available.
**Hashing Type**
- **Linear Probing**
	- hash = key % size + n, n is for every new attempt 
	- Primary clustering. This occurs do to the linear nature. Which mean long probing searches
- **Quadratic Probing**
	- hash = key % size + n^2, n is for every new attempt 
	- Secondary clustering. Similar problem as Linear but to a lesser degree
- **Double Hashing**
	- hash2 =(size/2) - (x % (size/2))
### Closed Addressing
**Separate Chaining**
- w/ single linked list time complexity of O(n)
- w/ doubly linked list time complexity of O(1)
### Hybrid
**Cuckoo Hashing**
- time complexity of O(1) worst case
- Uses two different hashing functions
	- h1 = key % size
	- h2 = (key/size) % size
- Load factor = entry_count / size
**Relocates**
- Pushes current value to other hashing table when collision occurs
- If alternative position is vacant insert
- else the current value keeps getting pushed and inserts the new value that caused the collision
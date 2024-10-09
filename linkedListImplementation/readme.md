# Linked List Project
## Overview
This project implements a singly linked list in C++. It provides basic linked list operations such as inserting, deleting, and traversing nodes. The program is divided into multiple files, each handling different aspects of the linked list implementation.

## Files
- **node.h**: Defines the structure of a node in the linked list. Each node contains data and a pointer to the next node.
- **linkedList.h**: Declares the class and the methods for managing the linked list, including inserting, deleting, and searching for elements.
- **linkedListPART.cpp**: Implements the functions declared in linkedList.h.
- **main.cpp**: Contains the main logic to test and demonstrate the functionality of the linked list by calling the appropriate methods on the linked list.
## Key Features
- **Insert Node**: Add a new node to the linked list at the beginning, end, or in a sorted manner.
- **Delete Node**: Remove a node based on a specified value.
- **Traverse List**: Print all the nodes in the list in order.
- **Search Node**: Find and return a node with a specific value.
## How the Code Works
- Node Definition (node.h):
  - A Node contains:
    - data: The value of the node.
    - next: A pointer to the next node in the list.

- Linked List Operations (linkedList.h and linkedListPART.cpp):
  - Insert: Nodes can be inserted at the head, tail, or in sorted order depending on the method called.
  - Delete: Removes the node with the specified value from the list.
  - Traversal: Prints out all the values in the linked list from head to tail.
  - Search: Finds if a value exists in the list and returns the corresponding node if it does.

- Main Logic (main.cpp):
  - The main.cpp file contains a menu-driven or test-driven approach where the user can insert nodes, delete nodes, or view the list.
  - It demonstrates linked list functionality by creating instances and performing various operations on the linked list.

## Example Output
### Example Test Case 1: Insert Nodes and Display the List
**Input Operations:**
- Insert 10
- Insert 5
- Insert 15
- Display List
  
**Expected Output:** `5 -> 10 -> 15`

### Example Test Case 2: Delete a Node
**Input Operations:**
- Insert 10
- Insert 5
- Insert 15
- Delete 10
- Display List
  
**Expected Output**: `5 -> 15`
  
### Example Test Case 3: Search for a Node
**Input Operations:**
- Insert 10
- Insert 5
- Insert 15
- Search for 15
  
**Expected Output:** `Node with value 15 found.`

### Example Test Case 4: Search for a Non-existent Node
**Input Operations:**
- Insert 10
- Insert 5
- Insert 15
- Search for 20
  
**Expected Output:** `Node with value 20 not found.`

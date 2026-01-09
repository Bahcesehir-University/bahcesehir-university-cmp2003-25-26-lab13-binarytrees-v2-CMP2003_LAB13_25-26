# CMP2003 – Data Structures  
## Lab 13: Binary Search Tree (BST)

### ⏱ Duration


---

## 🎯 Objective

In this lab, you will implement a **Binary Search Tree (BST)** from scratch and practice:

- Recursive insertion
- Tree traversals (inorder, preorder, postorder)
- Computing tree properties:
  - Height
  - Total number of nodes
  - Number of leaf nodes

You will work with a **single file** (`MainProgram.cpp`) and complete the missing parts marked as **TODO**.

---

## 📂 Files Provided

| File | Description |
|----|----|
| `MainProgram.cpp` | **Student skeleton** (you complete this file) |
| `test_bst.cpp` | Catch2 autograding tests (do not modify) |
| `catch_amalgamated.cpp/.hpp` | Catch2 testing framework |
| `Makefile` | Build & test automation |

---

## 🌳 Binary Search Tree Rules

Your BST **must follow these rules**:

- **Insertion rule**
  - If `item < node->info` → go **left**
  - Otherwise (including duplicates) → go **right**

- **Height definition**
  - Empty tree → `0`
  - Single node → `1`

- **Leaf definition**
  - A node with **no left and no right child**

---

## ⌨️ Input Format

The program reads integers from standard input.

- Input ends when `-999` is entered.
- Example input:
  ```
  68 43 10 56 77 82 61 82 33 56 72 66 99 88 12 6 7 21 -999
  ```

---

## 📤 Output Format

Your program must print:

1. Inorder traversal  
2. Preorder traversal  
3. Postorder traversal  
4. Tree height  
5. Number of nodes  
6. Number of leaf nodes  

Example output format:
```
Tree nodes in inorder: 6 7 10 12 21 33 43 56 56 61 66 68 72 77 82 82 88 99
Tree nodes in preorder: ...
Tree nodes in postorder: ...

Tree Height: 6
Number of Nodes: 18
Number of Leaves: 7
```

⚠️ **Spacing matters**  
- Print values separated by **a single space**
- No extra text or formatting

---

## 🧪 Autograding & Tests

This lab is graded automatically using **Catch2**.

### Build the project
```bash
make
```

### Run all tests
```bash
make test
```

### Run individual sections
```bash
make task1   # Insert + BST property
make task2   # Traversals
make task3   # Height
make task4   # Node count
make task5   # Leaf count
```

---

## 🧮 Grading Breakdown (100 pts)

| Task | Description | Points |
|---|---|---:|
| Task 1 | BST insertion + duplicate handling | 20 |
| Task 2 | Traversals (inorder, preorder, postorder) | 30 |
| Task 3 | Tree height | 20 |
| Task 4 | Number of nodes | 15 |
| Task 5 | Number of leaves | 15 |
| **Total** |  | **100** |

---

## 🚫 Important Rules

- ❌ Do **NOT** change function names or signatures  
- ❌ Do **NOT** add extra output (debug prints)
- ❌ Do **NOT** modify test files
- ✅ Only edit `MainProgram.cpp`

Failure to follow these rules may result in **test failures** even if your logic is correct.

---

## 💡 Hints

- Use **recursion** for all tree operations
- Inorder traversal of a BST is always **sorted**
- Height is `1 + max(leftHeight, rightHeight)`
- Count nodes and leaves using simple recursive sums

---

## ✅ Submission

- Push your completed `MainProgram.cpp` to GitHub
- Make sure **all tests pass locally** before submitting
- The autograder output is final

---

Good luck 🌱  
**CMP2003 – Data Structures**

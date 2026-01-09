/************************************************************
 CMP2003 – Data Structures
 Lab: Binary Search Tree (BST) – Traversals & Basic Stats
 Student Skeleton (fill the TODOs)
 Time: ~50 minutes

 GOAL
  - Implement a Binary Search Tree that supports:
      1) insert(x)
      2) inorderTraversal()
      3) preorderTraversal()
      4) postorderTraversal()
      5) treeHeight()
      6) treeNodeCount()
      7) treeLeavesCount()

 INPUT
  - User enters integers ending with -999 sentinel.

 RULES / NOTES
  - Duplicates: insert them into the RIGHT subtree.
  - Height definition for this lab:
      * empty tree => height = 0
      * single node => height = 1
  - Traversal format: print values separated by a single space.

************************************************************/

#include <iostream>
using namespace std;

/************************************************************
  BST NODE (template)
************************************************************/
template <class T>
struct nodeType {
    T info;
    nodeType<T>* llink;
    nodeType<T>* rlink;

    nodeType(const T& val)
        : info(val), llink(nullptr), rlink(nullptr) {}
};

/************************************************************
  BST CLASS
************************************************************/
template <class T>
class bSearchTreeType {
public:
    bSearchTreeType() : root(nullptr) {}
    ~bSearchTreeType() { destroy(root); }

    // ======= STUDENT TASKS =======
    void insert(const T& item);         // Task 1
    void inorderTraversal() const;      // Task 2
    void preorderTraversal() const;     // Task 2
    void postorderTraversal() const;    // Task 2

    int treeHeight() const;             // Task 3
    int treeNodeCount() const;          // Task 4
    int treeLeavesCount() const;        // Task 5

private:
    nodeType<T>* root;

    // recursive helpers
    void insert(nodeType<T>*& p, const T& item);

    void inorder(nodeType<T>* p) const;
    void preorder(nodeType<T>* p) const;
    void postorder(nodeType<T>* p) const;

    int height(nodeType<T>* p) const;
    int nodeCount(nodeType<T>* p) const;
    int leavesCount(nodeType<T>* p) const;

    // given helper
    void destroy(nodeType<T>*& p);
};

/************************************************************
  Helper: destroy tree (given)
************************************************************/
template <class T>
void bSearchTreeType<T>::destroy(nodeType<T>*& p) {
    if (p != nullptr) {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = nullptr;
    }
}

/************************************************************
  Task 1: insert (public wrapper)
************************************************************/
template <class T>
void bSearchTreeType<T>::insert(const T& item) {
    // TODO:
    // Call the recursive insert helper starting from root.
    // Example: insert(root, item);
}

/************************************************************
  Task 1: insert (recursive)
  Policy:
   - if item < p->info  => go left
   - else               => go right (also handles duplicates)
************************************************************/
template <class T>
void bSearchTreeType<T>::insert(nodeType<T>*& p, const T& item) {
    // TODO:
    // If p is null, create a new node.
    // Otherwise, recurse left or right based on BST rules.
}

/************************************************************
  Task 2: Traversals (public wrappers)
************************************************************/
template <class T>
void bSearchTreeType<T>::inorderTraversal() const {
    // TODO: call inorder(root)
}

template <class T>
void bSearchTreeType<T>::preorderTraversal() const {
    // TODO: call preorder(root)
}

template <class T>
void bSearchTreeType<T>::postorderTraversal() const {
    // TODO: call postorder(root)
}

/************************************************************
  Task 2: Traversals (recursive)
  inorder:   Left, Root, Right
  preorder:  Root, Left, Right
  postorder: Left, Right, Root
************************************************************/
template <class T>
void bSearchTreeType<T>::inorder(nodeType<T>* p) const {
    // TODO:
    // If p is null return
    // Visit left, print root, visit right
}

template <class T>
void bSearchTreeType<T>::preorder(nodeType<T>* p) const {
    // TODO:
    // If p is null return
    // Print root, visit left, visit right
}

template <class T>
void bSearchTreeType<T>::postorder(nodeType<T>* p) const {
    // TODO:
    // If p is null return
    // Visit left, visit right, print root
}

/************************************************************
  Task 3: treeHeight
  Height rules:
   - empty tree => 0
   - single node => 1
************************************************************/
template <class T>
int bSearchTreeType<T>::treeHeight() const {
    // TODO: return height(root)
    return 0;
}

template <class T>
int bSearchTreeType<T>::height(nodeType<T>* p) const {
    // TODO:
    // If p is null => 0
    // else => 1 + max(height(left), height(right))
    return 0;
}

/************************************************************
  Task 4: treeNodeCount
************************************************************/
template <class T>
int bSearchTreeType<T>::treeNodeCount() const {
    // TODO: return nodeCount(root)
    return 0;
}

template <class T>
int bSearchTreeType<T>::nodeCount(nodeType<T>* p) const {
    // TODO:
    // If p is null => 0
    // else => 1 + nodeCount(left) + nodeCount(right)
    return 0;
}

/************************************************************
  Task 5: treeLeavesCount
  Leaf = node with no children
************************************************************/
template <class T>
int bSearchTreeType<T>::treeLeavesCount() const {
    // TODO: return leavesCount(root)
    return 0;
}

template <class T>
int bSearchTreeType<T>::leavesCount(nodeType<T>* p) const {
    // TODO:
    // If p is null => 0
    // If p is leaf => 1
    // else => leavesCount(left) + leavesCount(right)
    return 0;
}

/************************************************************
  MAIN (same behavior as your snippet)
************************************************************/
// Data example:
// 68 43 10 56 77 82 61 82 33 56 72 66 99 88 12 6 7 21 -999

int main() {
    bSearchTreeType<int> treeRoot;

    int num;
    cout << "Enter numbers ending with -999" << endl;
    cin >> num;

    while (num != -999) {
        treeRoot.insert(num);
        cin >> num;
    }

    cout << endl << "Tree nodes in inorder: ";
    treeRoot.inorderTraversal();

    cout << endl << "Tree nodes in preorder: ";
    treeRoot.preorderTraversal();

    cout << endl << "Tree nodes in postorder: ";
    treeRoot.postorderTraversal();
    cout << endl;

    cout << "Tree Height: " << treeRoot.treeHeight() << endl;
    cout << "Number of Nodes: " << treeRoot.treeNodeCount() << endl;
    cout << "Number or Leaves: " << treeRoot.treeLeavesCount() << endl;
    cout << endl;

    return 0;
}

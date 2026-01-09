// test_bst.cpp
#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// Include student code (single-file lab)
#include "MainProgram.cpp"

// -------------------- helpers --------------------
static std::string normalize_ws(const std::string& s) {
    // compress all whitespace runs to single spaces, trim ends
    std::string out;
    out.reserve(s.size());

    bool in_ws = false;
    for (unsigned char ch : s) {
        if (std::isspace(ch)) {
            if (!out.empty()) in_ws = true;
        } else {
            if (in_ws) out.push_back(' ');
            in_ws = false;
            out.push_back((char)ch);
        }
    }
    // trim trailing space
    if (!out.empty() && out.back() == ' ') out.pop_back();
    return out;
}

static void build_tree(bSearchTreeType<int>& t, const std::vector<int>& vals) {
    for (int x : vals) t.insert(x);
}

static std::string capture_inorder(bSearchTreeType<int>& t) {
    std::ostringstream oss;
    auto* old = std::cout.rdbuf(oss.rdbuf());
    t.inorderTraversal();
    std::cout.rdbuf(old);
    return normalize_ws(oss.str());
}

static std::string capture_preorder(bSearchTreeType<int>& t) {
    std::ostringstream oss;
    auto* old = std::cout.rdbuf(oss.rdbuf());
    t.preorderTraversal();
    std::cout.rdbuf(old);
    return normalize_ws(oss.str());
}

static std::string capture_postorder(bSearchTreeType<int>& t) {
    std::ostringstream oss;
    auto* old = std::cout.rdbuf(oss.rdbuf());
    t.postorderTraversal();
    std::cout.rdbuf(old);
    return normalize_ws(oss.str());
}

// -------------------- TESTS --------------------

// ========== Task 1: Insert basics (BST property shows up in inorder) ==========
TEST_CASE("Task1 - Inorder traversal is sorted after inserts", "[task1][insert][10pts]") {
    bSearchTreeType<int> t;
    build_tree(t, {68, 43, 10, 56, 77, 82, 61, 33, 72, 66, 99, 88, 12, 6, 7, 21});

    // For a BST, inorder must be sorted non-decreasing (duplicates allowed)
    // We'll parse printed output and verify sortedness.
    std::string s = capture_inorder(t);
    REQUIRE_FALSE(s.empty());

    std::istringstream iss(s);
    std::vector<int> got;
    int x;
    while (iss >> x) got.push_back(x);

    REQUIRE(got.size() == 16);
    REQUIRE(std::is_sorted(got.begin(), got.end()));
}

// ========== Duplicates policy (go RIGHT) ==========
TEST_CASE("Task1 - Duplicate handling (duplicates go right) affects preorder", "[task1][insert][10pts]") {
    // Insert duplicates of 10; with 'duplicates go right', the structure is deterministic:
    // Insert order: 10, 5, 15, 10, 10
    // BST (duplicates right):
    //        10
    //       /  \
    //      5    15
    //          /
    //         10
    //           \
    //           10
    // Preorder: 10 5 15 10 10
    bSearchTreeType<int> t;
    build_tree(t, {10, 5, 15, 10, 10});

    REQUIRE(capture_preorder(t) == "10 5 15 10 10");
    REQUIRE(capture_inorder(t)  == "5 10 10 10 15");
}

// ========== Task 2: Traversals correctness on known small tree ==========
TEST_CASE("Task2 - Traversals output correct order (small fixed tree)", "[task2][traversal][30pts]") {
    // Insert: 8,3,10,1,6,14,4,7,13 (classic BST example)
    // Tree:
    //        8
    //      /   \
    //     3     10
    //    / \      \
    //   1   6      14
    //      / \     /
    //     4   7   13
    //
    // Inorder:   1 3 4 6 7 8 10 13 14
    // Preorder:  8 3 1 6 4 7 10 14 13
    // Postorder: 1 4 7 6 3 13 14 10 8
    bSearchTreeType<int> t;
    build_tree(t, {8, 3, 10, 1, 6, 14, 4, 7, 13});

    REQUIRE(capture_inorder(t)   == "1 3 4 6 7 8 10 13 14");
    REQUIRE(capture_preorder(t)  == "8 3 1 6 4 7 10 14 13");
    REQUIRE(capture_postorder(t) == "1 4 7 6 3 13 14 10 8");
}

// ========== Task 3: Height ==========
TEST_CASE("Task3 - Height definition (empty=0, one node=1, known tree)", "[task3][height][20pts]") {
    bSearchTreeType<int> empty;
    REQUIRE(empty.treeHeight() == 0);

    bSearchTreeType<int> one;
    one.insert(42);
    REQUIRE(one.treeHeight() == 1);

    // Skewed tree: insert ascending -> height = n
    bSearchTreeType<int> skew;
    build_tree(skew, {1,2,3,4,5});
    REQUIRE(skew.treeHeight() == 5);

    // Balanced-ish example from earlier: 8,3,10,1,6,14,4,7,13
    // Height should be 4 (8->3->6->7 or 8->10->14->13)
    bSearchTreeType<int> t;
    build_tree(t, {8, 3, 10, 1, 6, 14, 4, 7, 13});
    REQUIRE(t.treeHeight() == 4);
}

// ========== Task 4: Node count ==========
TEST_CASE("Task4 - Node count correct (empty, known sizes)", "[task4][count][15pts]") {
    bSearchTreeType<int> empty;
    REQUIRE(empty.treeNodeCount() == 0);

    bSearchTreeType<int> t;
    build_tree(t, {8, 3, 10, 1, 6, 14, 4, 7, 13});
    REQUIRE(t.treeNodeCount() == 9);

    bSearchTreeType<int> dup;
    build_tree(dup, {10, 10, 10});
    REQUIRE(dup.treeNodeCount() == 3);
}

// ========== Task 5: Leaf count ==========
TEST_CASE("Task5 - Leaf count correct", "[task5][leaves][15pts]") {
    bSearchTreeType<int> empty;
    REQUIRE(empty.treeLeavesCount() == 0);

    bSearchTreeType<int> one;
    one.insert(7);
    REQUIRE(one.treeLeavesCount() == 1);

    // In the classic example tree (8,3,10,1,6,14,4,7,13)
    // Leaves are: 1,4,7,13  => 4 leaves
    bSearchTreeType<int> t;
    build_tree(t, {8, 3, 10, 1, 6, 14, 4, 7, 13});
    REQUIRE(t.treeLeavesCount() == 4);

    // Skewed tree of 5 nodes has 1 leaf (the last node)
    bSearchTreeType<int> skew;
    build_tree(skew, {1,2,3,4,5});
    REQUIRE(skew.treeLeavesCount() == 1);
}

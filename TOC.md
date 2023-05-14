[TOC]

### 第3章 数组中的问题其实最常见

#### 1. 如何写出正确的程序

283, 27, 26, 80

#### 2. 基础算法思路的应用

755, 88, 215

#### 3. 对撞指针

167, 125, 344, 345, 11

#### 4. 滑动窗口

209, 3, 438, 76

### 第4章 查找表相关问题

#### 1. set与map

349, 350, 242, 202, 290, 205, 451

#### 4-4 使用查找表的经典问题 Two Sum

1, 15, 18, 16

#### 4-5 灵活选择键值 4Sum II

454: 
49: Group Anagrams

#### 4-6 灵活选择键值 Number of Boomerangs

447: 
149: Max Points on a Line

#### 4-7 查找表和滑动窗口 Contain Duplicate II

219: Contains Duplicate II
217: Contains Duplicate

#### 4-8 二分搜索树底层实现的顺序性 Contain Duplicate III

220

### 第5章 在链表中穿针引线

#### 5-1 链表，在节点间穿针引线 Reverse Linked List

206: Reverse Linked List
92: Reverse Linked List II

#### 5-2 测试你的链表程序

83: Remove Duplicates from Sorted List
86: Partition List
328: Odd Even Linked List
2: Add Two Numbers
445: Add Two Numbers II

#### 5-3 设立链表的虚拟头节点 Remove Linked List Elements

203: Remove Linked List Elements
82: Remove Duplicates from Sorted List II
21: Merge Two Sorted Lists

#### 5-4 复杂的穿针引线 Swap Nodes in Pairs

24: Swap Nodes in Pairs
25: Reverse Nodes in k-Group
147: Insertion Sort List
148: Sort List

#### 5-5 不仅仅是穿针引线 Delete Node in a Linked List

237: Delete Node in a Linked List

#### 5-6 链表与双指针 Remove Nth Node From End of List

19: Remove Nth Node From End of List
61: Rotate List
143: Reorder List
234: Palindrome Linked List

### 第6章 栈、队列、优先队列

#### 6-1 栈的基础应用 Valid Parentheses

20: Valid Parentheses
150: Evaluate Reverse Polish Notation
71: Simplify Path

#### 6-2 栈和递归的紧密关系 Binary Tree Preorder, Inorder and Postorder Traversal

144: Binary Tree Preorder Traversal
94: Binary Tree Inorder Traversal
145: Binary Tree Postorder Traversal

#### 6-3 运用栈模拟递归

341: Flatten Nested List Iterator

#### 6-4 队列的典型应用 Binary Tree Level Order Traversal

102: Binary Tree Level Order Traversal, 从上往下层次遍历
107: Binary Tree Level Order Traversal II, 从下往上层次遍历，102反过来
103: Binary Tree Zigzag Level Order Traversal
199: Binary Tree Right Side View

#### 6-5 BFS和图的最短路径 Perfect Squares

279: Perfect Squares
127: Word Ladder
126: Word Ladder II

#### 6-6 6-7 优先队列 Top K Frequent Elements

347: Top K Frequent Elements
23: Merge k Sorted Lists

### 第7章 二叉树和递归

#### 7-1 二叉树天然的递归结构

104: Maximum Depth of Binary Tree
111: Minimum Depth of Binary Tree

#### 7-2 一个简单的二叉树问题引发的血案 Invert Binary Tree

226: Invert Binary Tree
100: Same Tree
101: Symmetric Tree, refer to 226 and 100
222: Count Complete Tree Nodes
110: Balanced Binary Tree

#### 7-4 注意递归的终止条件 Sum Paths

112: Path Sum
404: Sum of Left Leaves

#### 7-5 定义递归问题 Binary Tree Path

257: Binary Tree Paths
113: Path Sum II
129: Sum Root to Leaf Numbers

#### 7-6 稍复杂的递归逻辑 Path Sum III

437: Path Sum III

#### 7-7 二分搜索树中的问题 Lowest Common Ancestor of a Binary Search Tree

235: Lowest Common Ancestor of a Binary Search Tree
98: Validate Binary Search Tree
450: Delete Node in a BST
108: Convert Sorted Array to Binary Search Tree
230: Kth Smallest Element in a BST
236: Lowest Common Ancestor of a Binary Tree

### 第8章 递归和回溯法

#### 8-1 树形问题 Letter Combinations of a Phone Number

17: Letter Combinations of a Phone Number

#### 8-2 什么是回溯

93: Restore IP Addresses
131: Palindrome Partitioning

#### 8-3 排列问题 Permutations

46: Permutations
47: Permutations II

#### 8-4 组合问题 Combinations

77: Combinations

#### 8-5 回溯法解决组合问题的优化

39: Combination Sum
40: Combination Sum II
216: Combination Sum III
78: Subsets
90: Subsets II
401: Binary Watch

#### 8-6 二维平面上的回溯法 Word Search

79: Word Search

#### 8-7 floodfill算法，一类经典问题 Number of Islands

200: Number of Islands
130: Surrounded Regions
417: Pacific Atlantic Water Flow

#### 8-8 回溯法是经典人工智能的基础 N Queens // TODO

51: N-Queens
52: N-Queens II
37: Sudoku Solver

### 第9章 动态规划基础

#### 9-2 第一个动态规划问题 Climbing Stairs

70: Climbing Stairs
120: Triangle
64: Minimum Path Sum

#### 9-3 发现重叠子问题 Integer Break

343: Integer Break
279: Perfect Squares
91: Decode Ways
62: Unique Paths
63: Unique Paths II

#### 9-4 状态的定义和状态转移 House Robber

198: House Robber
213: House Robber II
337: House Robber III

用状态机解决问题：
309: Best Time to Buy and Sell Stock with Cooldown
- 122 with cooldown

121: Best Time to Buy and Sell Stock
- 1 transaction

122: Best Time to Buy and Sell Stock II
- Unlimited transactions

123: Best Time to Buy and Sell Stock III
- 2 transactions (121)

188: Best Time to Buy and Sell Stock IV
- k transactions (121)

714: Best Time to Buy and Sell Stock with Transaction Fee
- 122 with transaction fee

[这类问题的通解](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/75924/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems/)

123的衍生题: 239

#### 9-5 背包问题

416: Partition Equal Subset Sum

322: Coin Change

518: Coin Change II

377: Combination Sum IV

474: Ones and Zeroes

139: Word Break

494: Target Sum

#### 9-8 LIS问题 Longest Increasing Subsequence

300: Longest Increasing Subsequence

376: Wiggle Subsequence

#### 9-10 动态规划经典问题

53: Maximum Subarray

1035: Uncrossed Lines

877: Stone Game

152: Maximum Product Subarray

1155: Number of Dice Rolls With Target Sum

1458: Max Dot Product of Two Subsequences

329: Longest Increasing Path in a Matrix

1092: Shortest Common Supersequence

1444: Number of Ways of Cutting a Pizza
- 304: Range Sum Query 2D - Immutable
- 303: Range Sum Query - Immutable

887: Super Egg Drop

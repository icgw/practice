A binary tree has the binary search tree property (BST property) if, for every node, the keys in its left subtree are smaller than its own key, and the keys in its right subtree are larger than its own key. It has the heap property if, for every node, the keys of its children are all smaller than its own key. You are given a set of binary tree nodes (i, j) where each node contains an integer i and an integer j. No two i values are equal and no two j values are equal. We must assemble the nodes into a single binary tree where the i values obey the BST property and the j values obey the heap property. If you pay attention only to the second key in each node, the tree looks like a heap, and if you pay attention only to the first key in each node, it looks like a binary search tree.

Example 1:

Input: [(1, 6), (3, 7), (2, 4)]
Output:

		(3, 7)
		/
	 (1, 6)
		\
	  (2, 4)
Example 2:

Input: [(1, 4), (8, 5), (3, 6), (10, -1), (4, 7)]
Output:

		(4, 7)
		/    \
	(3, 6)   (8, 5)
	 /          \
 (1, 4)       (10, -1)
You can assume that a solution always exists.

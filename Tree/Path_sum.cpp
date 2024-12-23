/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum

Input 1:

 Tree:    5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1

 B = 22
Input 2:

 Tree:    5
         / \
        4   8
       /   / \
     -11 -13  4

 B = -1


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 There exist a root-to-leaf path 5 -> 4 -> 11 -> 2 which has sum 22. So, return 1.
Explanation 2:

 There is no path which has sum -1.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int hasPath(TreeNode* curr, int sum)
{
    if(curr == nullptr)
        return 0;
    sum = sum - curr->val;
    if((curr->left == nullptr) && (curr->right == nullptr))
        return (sum == 0);
    return(hasPath(curr->left,sum) || hasPath(curr->right,sum));
    
}
int Solution::hasPathSum(TreeNode* A, int B) 
{
    return hasPath(A,B);
}

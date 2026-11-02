/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func goodNodes(root *TreeNode) int {
    ans := 0

    var dfs func(*TreeNode, int)
    dfs = func(node *TreeNode, maxV int) {
        if node == nil {
            return
        }

        if node.Val >= maxV {
            ans++
        }

        dfs(node.Left, max(maxV, node.Val))
        dfs(node.Right, max(maxV, node.Val))
    }

    dfs(root, -1e4-1)
    return ans
}

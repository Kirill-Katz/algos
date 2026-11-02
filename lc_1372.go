/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestZigZag(root *TreeNode) int {
    type Direction int

    const (
        Left Direction = iota
        Right
    )

    var dfs func(*TreeNode, Direction, int) int

    dfs = func(node *TreeNode, dir Direction, soFar int) int {
        if node == nil {
            return soFar - 1
        }

        cont := 0
        start := 0
        if dir == Left {
            cont = dfs(node.Right, Right, soFar + 1)
            start = dfs(node.Left, Left, 1)
        }

        if dir == Right {
            cont = dfs(node.Left, Left, soFar + 1)
            start = dfs(node.Right, Right, 1)
        }

        return max(start, cont)
    }

    return max(dfs(root, Left, 0), dfs(root, Right, 0))
}

func maxOperations(nums []int, k int) int {
   var ans int = 0

    slices.Sort(nums)
    n := len(nums)

    l, r := 0, n - 1
    for l < r {
        if nums[l] + nums[r] == k {
            l++
            r--
            ans++
        } else if nums[l] + nums[r] > k {
            r--
        } else {
            l++
        }
    }

    return ans
}

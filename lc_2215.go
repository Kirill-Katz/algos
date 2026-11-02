func findDifference(nums1 []int, nums2 []int) [][]int {
    set1 := make(map[int]struct{})
    set2 := make(map[int]struct{})

    for _, v := range nums1 {
        set1[v] = struct{}{}
    }

    for _, v := range nums2 {
        set2[v] = struct{}{}
    }

    ans := make([][]int, 2)

    for v := range set1 {
        if _, ok := set2[v]; !ok {
            ans[0] = append(ans[0], v)
        }
    }

    for v := range set2 {
        if _, ok := set1[v]; !ok {
            ans[1] = append(ans[1], v)
        }
    }

    return ans
}


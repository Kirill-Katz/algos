func eraseOverlapIntervals(intervals [][]int) int {
    slices.SortFunc(intervals, slices.Compare)

    ans := 0
    prevEnd := intervals[0][1]

    for _, interval := range intervals[1:] {
        l := interval[0]
        r := interval[1]

        if l >= prevEnd {
            prevEnd = r
        } else {
            prevEnd = min(prevEnd, r)
            ans++
        }
    }

    return ans
}

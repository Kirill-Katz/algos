func equalPairs(grid [][]int) int {
    n := len(grid)

    rows := make(map[string]int, n)
    cols := make(map[string]int, n)

    for i := 0; i < n; i++ {
        var row strings.Builder

        for j := 0; j < n; j++ {
            row.WriteString(strconv.Itoa(grid[i][j]))
            row.WriteByte('_')
        }
        rows[row.String()]++
    }

    for j := 0; j < n; j++ {
        var col strings.Builder

        for i := 0; i < n; i++ {
            col.WriteString(strconv.Itoa(grid[i][j]))
            col.WriteByte('_')
        }
        cols[col.String()]++
    }

    ans := 0
    for k, v := range rows {
        if cnt, ok := cols[k]; ok {
            ans += cnt * v
        }
    }

    return ans
}

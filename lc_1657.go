func closeStrings(word1 string, word2 string) bool {
    if len(word1) != len(word2) {
        return false
    }

    str1 := []byte(word1)
    str2 := []byte(word2)

    n := len(str1)

    map1 := make([]int, 26)
    map2 := make([]int, 26)

    for i := 0; i < n; i++ {
        map1[str1[i]-'a']++
        map2[str2[i]-'a']++
    }

    for i := 0; i < 26; i++ {
        if (map1[i] == 0) != (map2[i] == 0) {
            return false
        }
    }

    slices.Sort(map1)
    slices.Sort(map2)

    return slices.Compare(map1, map2) == 0
}

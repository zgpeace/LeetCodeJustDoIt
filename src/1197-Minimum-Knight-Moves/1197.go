func minKnightMoves(x int, y int) int {
    x, y = abs(x), abs(y)
    if x + y == 1 {
        return 3
    }
    res := max(max((x + 1)/2, (y + 1)/2), (x + y + 2)/3)
    res += (res ^ x ^ y) & 1
    return res
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
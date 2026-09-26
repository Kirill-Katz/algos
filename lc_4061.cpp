class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sx = source[0];
        int sy = source[1];

        int dx = target[0];
        int dy = target[1];

        // already in place
        if (dx == sx && dy == sy) return 0;

        // same row/col
        if (abs(sx - dx) == 0 || abs(sy - dy) == 0) {
            return 1;
        }

        // same diag
        if (abs(sx - dx) == abs(sy - dy)) {
            return 1;
        }

        // row + col move
        return 2;
    }
};

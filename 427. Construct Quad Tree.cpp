/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>> &grid, int rowStart, int colStart, int rowEnd, int colEnd) {
        if (rowStart == rowEnd && colStart == colEnd) return new Node(grid[rowStart][colStart], true, nullptr, nullptr, nullptr, nullptr);

        bool isLeaf = true;
        int val = grid[rowStart][colStart];
        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = colStart; j <= colEnd; j++) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) break;
        }

        if (isLeaf) return new Node(val, true, nullptr, nullptr, nullptr, nullptr);

        int rowMid = (rowStart + rowEnd) / 2;
        int colMid = (colStart + colEnd) / 2;

        Node* topLeft = helper(grid, rowStart, colStart, rowMid, colMid);
        Node* topRight = helper(grid, rowStart, colMid + 1, rowMid, colEnd);
        Node* bottomLeft = helper(grid, rowMid + 1, colStart, rowEnd, colMid);
        Node* bottomRight = helper(grid, rowMid + 1, colMid + 1, rowEnd, colEnd);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return helper(grid, 0, 0, n - 1, n - 1);
    }
};

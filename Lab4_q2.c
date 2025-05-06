#include <stdio.h>

// Helper function to perform DFS and mark visited land
void dfs(char** grid, int i, int j, int gridSize, int* gridColSize) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] != '1') {
        return;
    }

    grid[i][j] = '0';  // Mark the current land as visited

    // Visit all four directions
    dfs(grid, i + 1, j, gridSize, gridColSize); // Down
    dfs(grid, i - 1, j, gridSize, gridColSize); // Up
    dfs(grid, i, j + 1, gridSize, gridColSize); // Right
    dfs(grid, i, j - 1, gridSize, gridColSize); // Left
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0) return 0;

    int count = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[i]; ++j) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, gridSize, gridColSize); // Sink the island
            }
        }
    }

    return count;
}

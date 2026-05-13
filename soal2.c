#include <stdio.h>
#include <stdlib.h>

int dfs(int** grid, int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
        return 0;
    }
    grid[r][c] = 0;
    return 1 + dfs(grid, r + 1, c, rows, cols) + dfs(grid, r - 1, c, rows, cols) + dfs(grid, r, c + 1, rows, cols) + dfs(grid, r,  - 1, rows, cols);
}

void analyzeIslands(int** grid, int rows, int cols, int* outCount, int* outMaxArea) {
    int count = 0;
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                count++;

                int area = dfs(grid, i, j, rows, cols);

                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }

    *outCount = count;
    *outMaxArea = maxArea;
}

int main() {
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2) return -1;

    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%1d", &grid[i][j]);
        }
    }

    int count = 0;
    int maxArea = 0;

    analyzeIslands(grid, rows, cols, &count, &maxArea);

    printf("ISLANDS %d\n", count);
    printf("LARGEST %d\n", maxArea);

    for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    return 0;
}

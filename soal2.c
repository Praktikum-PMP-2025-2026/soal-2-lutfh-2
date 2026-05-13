/*============================================================
 *  EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul                : 05 - Foundation of Algorithm
 *   Hari dan Tanggal     : Rabu 13 Mei 2026
 *   Nama (NIM)           : Lutfi Hasan (13224091)
 *   Nama File            : soal2.c
 *   Deskripsi            : Membaca Banyak Pulau dan Pulau terbesar
 *   **/

// https://www.geeksforgeeks.org/dsa/find-length-largest-region-boolean-matrix/ 
// https://leetcode.com/problems/max-area-of-island/solutions/127762/max-area-of-island-by-leetcode-mgcs/*
// https://neetcode.io/solutions/max-area-of-island
// https://medium.com/@gyaluru/day-31-100-max-area-of-island-1e1c3335b211


#include <stdio.h>
#include <stdlib.h>

int dfs(int** grid, int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
        return 0;
    }
    grid[r][c] = 0;
    return 1 + dfs(grid, r + 1, c, rows, cols) + dfs(grid, r - 1, c, rows, cols) + dfs(grid, r, c + 1, rows, cols) + dfs(grid, r, c - 1, rows, cols);  // ← was: r,  - 1
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

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void ISLANDS();
void printMatrix(int** matrix, int M, int N);
void finishIsland(int*** matrix, int M, int N, int i, int j, int color);
void paintIslands(int*** matrix, int M, int N);
void randomInput(int*** matrix, int M, int N);
void inputInt(int* a, int x, int y);
#include"Header.h"

//заполнение матрицы
void randomInput(int*** matrix, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            (*matrix)[i][j] = rand() % 2;
        }
    }
}
//проверка на ввод 
void inputInt(int* a, int x, int y) {
    scanf_s("%d", a);
    while (getchar() != '\n' || *a < x || *a > y) {
        rewind(stdin);
        printf("\033[31mWrong input\033[m\n");
        scanf_s("%d", a);
    }
}

//выделение пам€ти под матрицу
void createMatrix(int*** matr, int* M, int* N) {
    printf("Matrix MxN\nEnter M = ");
    inputInt(M, 1, 100);
    printf("Enter N = ");
    inputInt(N, 1, 100);
    *matr = (int**)calloc(*M, sizeof(int*));
    for (int i = 0; i < *M; i++) {
        (*matr)[i] = (int*)calloc(*N, sizeof(int));
    }
}
//вывод матрицы
void printMatrix(int** matrix, int M, int N) {
    char c[4];
    printf("\nMatrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                printf("%2d ", matrix[i][j]);
            }
            else if (matrix[i][j] == 0) { 
                printf("   ");
            }
            else {
                _itoa(matrix[i][j] + 30, c, 10);
                printf("\033[1;38;5;%sm1  \033[0m", c, matrix[i][j]);
            }
        }
        printf("\n");
    }
}
//раскраска одного острова в один цвет
void finishIsland(int*** matrix, int M, int N, int i, int j, int color) {
    if (i < 0 || i >= M || j < 0 || j >= N || (*matrix)[i][j] != 1)
        return;
    (*matrix)[i][j] = color;

    finishIsland(matrix, M, N, i + 1, j, color);
    finishIsland(matrix, M, N, i - 1, j, color);
    finishIsland(matrix, M, N, i, j + 1, color);
    finishIsland(matrix, M, N, i, j - 1, color);
}
//раскраска островов
void paintIslands(int*** matrix, int M, int N) {
    int color = 2;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if ((*matrix)[i][j] == 1) {
                finishIsland(matrix, M, N, i, j, color);
                color++;
            }
        }
    }
}
void ISLANDS() {
    srand((unsigned int)time(NULL));
    int M, N;
    int** matrix = NULL;
    createMatrix(&matrix, &M, &N);
    randomInput(&matrix, M, N);

    printMatrix(matrix, M, N);
    paintIslands(&matrix, M, N);
    printMatrix(matrix, M, N);
    printf("\n");
}

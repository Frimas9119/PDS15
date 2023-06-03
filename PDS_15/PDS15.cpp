#include <iostream>

using namespace std;

bool isSafe(int board[], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        // Перевіряємо, чи знаходиться ферзь на тій самій колонці або на діагоналі
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void place(int board[], int row, int n, int& count) {
    // Всі ферзі були розміщені, тому збільшуємо лічильник розв'язків
    if (row == n) {
        count++;
        return;
    }

    // Розміщуємо ферзя на кожній колонці даного рядка
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            place(board, row + 1, n, count);
        }
    }
}

int count(int n) {
    int* board = new int[n];
    int count = 0;
    place(board, 0, n, count);
    delete[] board;
    return count;
}

int main() {
    int n;
    cout << "Enter size (n x n): ";
    cin >> n;
    int numSolutions = count(n);
    cout << "The number of ways to place queens: " << numSolutions << endl;

    return 0;
}

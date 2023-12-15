#include "main.h"

void DrawBorder() {
    for (int i = ((cols - 80) / 2); i <= ((cols + 80) / 2); ++i) mvaddch(0, i, '#');
    for (int i = ((cols - 80) / 2); i <= ((cols + 80) / 2); ++i) mvaddch(rows - 1, i, '#');
    for (int i = 0; i <= rows; ++i) mvaddch(i, (cols - 80) / 2, '#');
    for (int i = 0; i <= rows; ++i) mvaddch(i, (cols + 80) / 2, '#');
}

void ClearRow(int j) {
    attron(COLOR_PAIR(21));
    attroff(A_BOLD | A_UNDERLINE);
    for (int i = ((cols - 68) / 2); i <= ((cols + 68) / 2); ++i) mvaddch(j, i, '#');
}
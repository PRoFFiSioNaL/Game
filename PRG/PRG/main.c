#include "main.h"

typedef struct Character Character;

int main() {
    setlocale(0, "Ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Character hero;
    char c, v;
    initscr();
    start_color();
    curs_set(0);
    noecho();
    getmaxyx(stdscr, rows, cols);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_GREEN, COLOR_GREEN);
    init_pair(8, COLOR_RED, COLOR_RED);
    init_pair(9, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(10, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(11, COLOR_BLUE, COLOR_BLUE);

    init_pair(20, COLOR_WHITE, COLOR_BLACK);
    init_pair(21, COLOR_BLACK, COLOR_BLACK);
    init_pair(22, COLOR_CYAN, COLOR_BLACK);

    DrawMenu();
    while ((c = getch()) != 27) {
        if (c == 'z' || c == 'ˇ' || c == 'Z' || c == 'ﬂ') {
            clear();
            attron(COLOR_PAIR(6));
            attroff(A_BOLD);
            DrawBorder();
            attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
            mvprintw(4, (cols - 26) / 2, "z - Õ‡ÒÚÓÈÍË ÔÓ ÛÏÓÎ˜‡ÌË˛");
            mvprintw(7, (cols - 26) / 2, "x - –‡Ò¯ËÂÌÌ˚Â Ì‡ÒÚÓÈÍË");
            mvprintw(10, (cols - 18) / 2, "c - ¬ÓÁ‚‡Ú Í ÏÂÌ˛");
            while ((v = getch()) != 27) {
                if (v == 'z' || v == 'ˇ' || v == 'Z' || v == 'ﬂ') {
                    Setting(0);
                    hero = CreateCharacter();
                    int win = MiddlePhase(hero, 1);
                    if (win == 1) {
                        clear();
                        attron(COLOR_PAIR(7));
                        DrawBorder();
                        attron(A_UNDERLINE | A_BOLD | COLOR_PAIR(4));
                        mvprintw(rows / 2, (cols - 27) / 2, "œŒ«ƒ–¿¬Àﬂ≈Ã, ¬€ œ–ŒÿÀ» »√–”!");
                        attroff(A_UNDERLINE | A_BOLD);
                        getch();
                        clear();
                        DrawStatistics(hero);
                        attron(COLOR_PAIR(4) | A_UNDERLINE | A_BOLD);
                        mvprintw(2, (cols - 18) / 2, "»“Œ√Œ¬¿ﬂ —“¿“»—“» ¿");
                        getch();
                        clear();
                        DrawMenu();
                    }
                    else if (win == 0) {
                        clear();
                        attron(COLOR_PAIR(8));
                        DrawBorder();
                        attron(COLOR_PAIR(1) | A_UNDERLINE | A_BOLD);
                        mvprintw(rows / 2, (cols - 9) / 2, "œŒ–¿∆≈Õ»≈!");
                        attroff(A_UNDERLINE | A_BOLD);
                        getch();
                        clear();
                        DrawMenu();
                    }
                    else if (win == 2) {
                        clear();
                        attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
                        mvprintw((rows - 4) / 2, (cols - 13) / 2, "¬—≈√Œ ƒŒ¡–Œ√Œ!");
                        getch();
                        return EXIT_SUCCESS;
                    }
                    break;
                }
                else if (v == 'x' || v == '˜' || v == 'X' || v == '◊') {
                    Setting(1);
                    hero = CreateCharacter();
                    int win = MiddlePhase(hero, 1);
                    if (win == 1) {
                        clear();
                        attron(COLOR_PAIR(7));
                        DrawBorder();
                        attron(A_UNDERLINE | A_BOLD | COLOR_PAIR(4));
                        mvprintw(rows / 2, (cols - 27) / 2, "œŒ«ƒ–¿¬Àﬂ≈Ã, ¬€ œ–ŒÿÀ» »√–”!");
                        attroff(A_UNDERLINE | A_BOLD);
                        getch();
                        clear();
                        DrawStatistics(hero);
                        attron(COLOR_PAIR(4) | A_UNDERLINE | A_BOLD);
                        mvprintw(2, (cols - 18) / 2, "»“Œ√Œ¬¿ﬂ —“¿“»—“» ¿");
                        getch();
                        clear();
                        DrawMenu();
                    }
                    else if (win == 0) {
                        clear();
                        attron(COLOR_PAIR(8));
                        DrawBorder();
                        attron(COLOR_PAIR(1) | A_UNDERLINE | A_BOLD);
                        mvprintw(rows / 2, (cols - 9) / 2, "œŒ–¿∆≈Õ»≈!");
                        attroff(A_UNDERLINE | A_BOLD);
                        getch();
                        clear();
                        DrawMenu();
                    }
                    else if (win == 2) {
                        clear();
                        attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
                        mvprintw((rows - 4) / 2, (cols - 13) / 2, "¬—≈√Œ ƒŒ¡–Œ√Œ!");
                        getch();
                        return EXIT_SUCCESS;
                    }
                }
                else if (v == 'c' || v == 'Ò' || v == 'C' || v == '—') {
                    clear();
                    DrawMenu();
                    break;
                }
            }
        }
        else if (c == 'x' || c == '˜' || c == 'X' || c == '◊') {
            int num_loc;
            if (Load(&num_loc, &hero)) continue;
            int win = MiddlePhase(hero, num_loc);
            if (win == 1) {
                clear();
                attron(COLOR_PAIR(7));
                DrawBorder();
                attron(A_UNDERLINE | A_BOLD | COLOR_PAIR(4));
                mvprintw(rows / 2, (cols - 27) / 2, "œŒ«ƒ–¿¬Àﬂ≈Ã, ¬€ œ–ŒÿÀ» »√–”!");
                attroff(A_UNDERLINE | A_BOLD);
                getch();
                clear();
                DrawStatistics(hero);
                attron(COLOR_PAIR(4) | A_UNDERLINE | A_BOLD);
                mvprintw(2, (cols - 18) / 2, "»“Œ√Œ¬¿ﬂ —“¿“»—“» ¿");
                getch();
                clear();
                DrawMenu();
            }
            else if (win == 0) {
                clear();
                attron(COLOR_PAIR(8));
                DrawBorder();
                attron(COLOR_PAIR(1) | A_UNDERLINE | A_BOLD);
                mvprintw(rows / 2, (cols - 9) / 2, "œŒ–¿∆≈Õ»≈!");
                attroff(A_UNDERLINE | A_BOLD);
                getch();
                clear();
                DrawStatistics(hero);
                attron(COLOR_PAIR(4) | A_UNDERLINE | A_BOLD);
                mvprintw(2, (cols - 18) / 2, "»“Œ√Œ¬¿ﬂ —“¿“»—“» ¿");
                getch();
                clear();
                DrawMenu();
            }
            else if (win == 2) {
                clear();
                attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
                mvprintw((rows - 4) / 2, (cols - 13) / 2, "¬—≈√Œ ƒŒ¡–Œ√Œ!");
                getch();
                return EXIT_SUCCESS;
            }
        }
        else if (c == 'c' || c == 'Ò' || c == 'C' || c == '—') {
            clear();
            attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
            mvprintw((rows - 4) / 2, (cols - 13) / 2, "¬—≈√Œ ƒŒ¡–Œ√Œ!");
            getch();
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
    endwin();
}

void DrawMenu() {
    attron(COLOR_PAIR(7));
    attroff(A_BOLD);
    DrawBorder();
    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
    mvprintw(4, (cols - 24) / 2, "“ÂÍÒÚÓ‚‡ˇ “‡ÍÚË˜ÂÒÍ‡ˇ –œ√");
    mvprintw(6, (cols - 3) / 2, "Ã≈Õﬁ");
    attron(COLOR_PAIR(2));
    mvprintw(8, (cols - 13) / 2, "z - ÕÓ‚‡ˇ Ë„‡");
    mvprintw(9, (cols - 11) / 2, "x - «‡„ÛÁÍ‡");
    mvprintw(10, (cols - 8) / 2, "c - ¬˚ıÓ‰");
}
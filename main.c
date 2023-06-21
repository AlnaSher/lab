#include"Header.h"

int main() {
    int fl = 1;
    while (fl != 0) {
        printf("1. Islands\n0. Exit\n");;
        inputInt(&fl, 0, 1);
        switch (fl) {
        case 1:
            system("cls");
            ISLANDS();
            break;
        case 0:
            exit(0);
        }
    }
}
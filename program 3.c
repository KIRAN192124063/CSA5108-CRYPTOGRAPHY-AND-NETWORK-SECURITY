#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];
int pos[26][2];

void generateMatrix(char key[]) {
    int used[26] = {0}, x = 0, y = 0;
    for (int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c == 'J') c = 'I'; 
        if (!used[c - 'A']) {
            matrix[x][y] = c;
            pos[c - 'A'][0] = x;
            pos[c - 'A'][1] = y;
            used[c - 'A'] = 1;
            if (++y == 5) { y = 0; x++; }
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c - 'A']) {
            matrix[x][y] = c;
            pos[c - 'A'][0] = x;
            pos[c - 'A'][1] = y;
            used[c - 'A'] = 1;
            if (++y == 5) { y = 0; x++; }
        }
    }
}

void playfairEncrypt(char text[]) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) text[i] = toupper(text[i]);
    for (int i = 0; i < len; i += 2) {
        if (i == len - 1 || text[i] == text[i + 1]) {
            memmove(text + i + 1, text + i, len - i + 1);
            text[i + 1] = 'X';
            len++;
        }
        char a = (text[i] == 'J') ? 'I' : text[i];
        char b = (text[i + 1] == 'J') ? 'I' : text[i + 1];
        int ax = pos[a - 'A'][0], ay = pos[a - 'A'][1];
        int bx = pos[b - 'A'][0], by = pos[b - 'A'][1];
        if (ax == bx) {
            text[i] = matrix[ax][(ay + 1) % 5];
            text[i + 1] = matrix[bx][(by + 1) % 5];
        } else if (ay == by) {
            text[i] = matrix[(ax + 1) % 5][ay];
            text[i + 1] = matrix[(bx + 1) % 5][by];
        } else {
            text[i] = matrix[ax][by];
            text[i + 1] = matrix[bx][ay];
        }
    }
}

int main() {
    char key[50], text[100];
    printf("Enter key: ");
    scanf("%s", key);
    getchar();
    generateMatrix(key);

    printf("Enter plaintext: ");
    scanf("%[^\n]s", text);

    playfairEncrypt(text);
    printf("Ciphertext: %s\n", text);
    return 0;
}

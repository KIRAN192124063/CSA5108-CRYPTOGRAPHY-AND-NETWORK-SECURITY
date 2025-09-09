#include <stdio.h>
#include <ctype.h>

void caesarCipher(char text[], int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            text[i] = (c - base + k) % 26 + base;
        }
    }
}

int main() {
    char text[100];
    int k;

    printf("Enter plaintext: ");
    scanf("%[^\n]s", text);
    printf("Enter shift key (1-25): ");
    scanf("%d", &k);

    caesarCipher(text, k);
    printf("Ciphertext: %s\n", text);

    return 0;
}

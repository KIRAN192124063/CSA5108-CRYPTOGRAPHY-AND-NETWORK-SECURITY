#include <stdio.h>
#include <ctype.h>
#include <string.h>

void monoCipher(char text[], char key[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int pos = tolower(text[i]) - 'a';
            text[i] = isupper(text[i]) ? toupper(key[pos]) : key[pos];
        }
    }
}

int main() {
    char text[100];
    char key[27]; // substitution key (26 letters)

    printf("Enter plaintext: ");
    scanf("%[^\n]s", text);
    getchar(); 

    printf("Enter substitution key (26 letters): ");
    scanf("%s", key);

    monoCipher(text, key);
    printf("Ciphertext: %s\n", text);

    return 0;
}

#include <stdio.h>
#include <string.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long count_anagrams(char *word) {
    int len = strlen(word);
    long long total_factorial = factorial(len);

    int counts[256] = {0};
    for (int i = 0; i < len; ++i) {
        counts[(int)word[i]]++;
    }
    
    long long denominator = 1;
    for (int i = 0; i < 256; ++i) {
        if (counts[i] > 1) {
            denominator *= factorial(counts[i]);
        }
    }
    
    return total_factorial / denominator;
}

int main() {
    char word[15];

    printf("Введіть слово: ");
    scanf("%s", word);

    long long result = count_anagrams(word);

    printf("Кількість анаграм для слова '%s': %lld\n", word, result);
    
    return 0;
}

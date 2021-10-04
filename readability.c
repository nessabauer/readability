#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// letras do alfabeto
char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int pontuacao_frase(string word);

int main(void)
{
    // Get input sentence
    string frase = get_string("Text: ");

    // Pontuação da frase
    int l = pontuacao_frase(frase);

    // Print grade
    if (l < 1)
    {
        printf("Before Grade 1\n");

    }
    else
    {
        if (l >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", l);
        }
    }
}

int pontuacao_frase(string word)
{
    int qtd_letras = 0, qtd_frases = 0, qtd_palavras = 1;
    // TODO: Compute and return score for string
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //Calculando a qtd de letras
        for (int l = 0; l < 26; l++)
        {
            if (tolower(word[i]) == letras[l])
            {
                qtd_letras ++;
                break;
            }
        }

        //Calculando a qtd de frases e palavras
        if (word[i] == '!' || word[i] == '.' || word[i] == '?')
        {
            qtd_frases ++;
        }

        if (word[i] == ' ')
        {
            qtd_palavras ++;
        }
    }

    float ave_letters = ((float)qtd_letras / qtd_palavras) * 100.0;
    float ave_sentences = ((float)qtd_frases / qtd_palavras) * 100.0;
    float index = 0.0588 * ave_letters - 0.296 * ave_sentences - 15.8;

    return round(index);
}
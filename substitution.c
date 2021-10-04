#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// letras do alfabeto
char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    //Validação se tem mais de 2 argumentos passados
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY.\n");
        return 1;
    }

    //Validação se tem mais de 26 caracteres a KEY
    if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //FOR Percorrendo o texto
    for (int i = 0; i < 26; i++)
    {
        int valida = 0;

        //FOR percorrendo o alfabeto procurando por não letras
        for (int l = 0; l < 26; l++)
        {
            if (tolower(argv[1][i]) == letras[l])
            {
                valida = 1;
                break;
            }
        }

        if (valida == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        //FOR percorrendo o próprio texto procurando letras repetidas
        for (int l = i; l < (26 - i); l++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][l]) && i != l)
            {
                printf("Key most not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Get input text
    string text = get_string("plaintext: ");

    //FOR para percorrer o texto -- i posição da letra
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //FOR para percorrer o lfabeto -- r posição no alfabeto
        for (int r = 0; r < 26; r++)
        {
            if (tolower(text[i]) == letras[r])
            {
                if (isupper(text[i]))
                {
                    //Convertendo texto das maiusculas
                    text[i] = toupper(argv[1][r]);
                    break;
                }
                else
                {
                    //Convertendo texto das minusculas
                    text[i] = tolower(argv[1][r]);
                    break;
                }
            }
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
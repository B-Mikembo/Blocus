#include <stdlib.h>
#include <stdio.h>

int sauvegarde(int **map, int size)
{
    printf("****** Sauvegarde ******\n");
    FILE *fichier = NULL;
    int i = 0, j = 0;

    fichier = fopen("dernier_partie.lvl", "w");
    if (fichier == NULL)
        return 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            fprintf(fichier, "%d", map[j][i]);
        }
    }

    fclose(fichier);
    return 1;
}
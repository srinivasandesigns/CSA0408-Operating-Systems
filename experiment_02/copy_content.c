#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char filename1[100], filename2[100];
    int c;

    printf("Enter the filename to open for reading:\n");
    scanf("%99s", filename1);

    fptr1 = fopen(filename1, "r");

    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", filename1);
        return 1;
    }

    printf("Enter the filename to open for writing:\n");
    scanf("%99s", filename2);

    fptr2 = fopen(filename2, "w");

    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n", filename2);
        fclose(fptr1);
        return 1;
    }

    c = fgetc(fptr1);

    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("Contents copied to %s\n", filename2);

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}

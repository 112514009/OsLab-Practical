#include <stdio.h>
int main()
{

    int pages[100];

    int frames[50];
    int n, f;
    int i, j;
    int pageFaults = 0;
    int index = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
    scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++)
    {

        found = 0;

        for (j = 0; j < f; j++)
        {

            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {

            frames[index] = pages[i];

            index = (index + 1) % f;

            pageFaults++;
        }

        printf("%d\t", pages[i]);

        for (j = 0; j < f; j++)
        {

            if (frames[j] == -1)
            printf("- ");

            else
            printf("%d ", frames[j]);
        }

        if (!found)
        printf("(Page Fault)");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    printf("Total Page Hits = %d\n", n - pageFaults);

    return 0;
}

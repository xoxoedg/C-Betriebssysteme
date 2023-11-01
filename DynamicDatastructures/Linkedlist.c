#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct datum
{
    int tag;
    int monat;
    int jahr;
};

struct angestellt
{
    char name[20];
    char vorname[20];
    struct datum alter;
    struct datum eingestellt;
    long gehalt;
};

void modifyAge(struct datum *einstellungsDatum, struct angestellt *angestellter)
{
    (*angestellter).eingestellt = *einstellungsDatum;
}

int main()
{
    struct datum einstellungsDatum = {10, 10, 2022};
    struct datum newEinstellungsDatum = {5, 5, 2023};
    struct angestellt Angestellter =
        {
            .name = "werner",
            .vorname = "Wuff",
            .alter = {10, 10, 1993},
            .eingestellt = einstellungsDatum,
            .gehalt = 30};

    printf("%d.%d.%d\n", Angestellter.eingestellt.tag, Angestellter.eingestellt.monat, Angestellter.eingestellt.jahr);

    modifyAge(&newEinstellungsDatum, &Angestellter);

    printf("%d.%d.%d", Angestellter.eingestellt.tag, Angestellter.eingestellt.monat, Angestellter.eingestellt.jahr);

    return 0;
}
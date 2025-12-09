#include <stdio.h>
#include <locale.h>

typedef struct {
    char title[100];
    int year;
    char style[50];
    int tracks;
    double duration;
} Album;

void input_album(Album* a);
void print_album(Album a);
void print_suitable_albums(Album arr[], int n);

int main() {
    setlocale(LC_CTYPE, "RUS");

    int n = 5;
    Album arr[10];

    for (int i = 0; i < n; i++) {
        printf("\n=== Альбом %d ===\n", i + 1);
        input_album(&arr[i]);
    }

    printf("\nВсе введённые альбомы:\n");
    for (int i = 0; i < n; i++) {
        print_album(arr[i]);
    }

    print_suitable_albums(arr, n);

    return 0;
}

void input_album(Album* a) {
    printf("Введите название: ");
    fgets(a->title, sizeof(a->title), stdin);
    a->title[strcspn(a->title, "\n")] = '\0';

    printf("Введите год выпуска: ");
    scanf("%d", &a->year);
    getchar();

    printf("Введите стиль: ");
    fgets(a->style, sizeof(a->style), stdin);
    a->style[strcspn(a->style, "\n")] = '\0';

    printf("Введите количество треков: ");
    scanf("%d", &a->tracks);

    printf("Введите длительность альбома (в минутах): ");
    scanf("%lf", &a->duration);
    getchar();
}

void print_album(Album a) {
    printf("\nНазвание: %s\n", a.title);
    printf("Год выпуска: %d\n", a.year);
    printf("Стиль: %s\n", a.style);
    printf("Количество треков: %d\n", a.tracks);
    printf("Длительность: %.2f минут\n", a.duration);
}

void print_suitable_albums(Album arr[], int n) {
    printf("\nАльбомы, соответствующие условиям:\n");

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].tracks >= 10 && arr[i].duration <= 50) {
            print_album(arr[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Нет альбомов, подходящих под условия.\n");
    }
}
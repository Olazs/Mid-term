#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <time.h>

// 1. Függvény, amely visszatér a paraméterként kapott cím értékével
int getValue(int *ptr) {
    return *ptr;
}

// 2. Két változó értékének felcserélése cím szerinti paraméterátadással
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. Három változó növekvő sorrendbe rendezése
void sortThree(int *a, int *b, int *c) {
    if (*a > *b) swap(a, b);
    if (*a > *c) swap(a, c);
    if (*b > *c) swap(b, c);
}

// 4. Legkisebb és legnagyobb elem keresése egy tömbben
void findMinMax(int arr[], int size, int **min, int **max) {
    if (size <= 0) return;
    *min = *max = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < **min) *min = &arr[i];
        if (arr[i] > **max) *max = &arr[i];
    }
}

// 5. Három változó közül a legkisebb érték visszaadása
int minOfThree(int *a, int *b, int *c) {
    int min = *a;
    if (*b < min) min = *b;
    if (*c < min) min = *c;
    return min;
}

// 6. Tömb rendezése csökkenő sorrendbe
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// 7. Tömb elemeinek összekeverése
void shuffleArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

// 8. Tömb elemeinek nullázása
void zeroArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

// 9. Tömb elemeinek módosítása az előzővel vett átlagra
void modifyArray(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        arr[i] = (arr[i] + arr[i - 1]) / 2;
    }
}

// 10. Logikai függvény: első szám kisebb-e mint a második
int isLess(int *a, int *b) {
    return *a < *b;
}

// 11. Logikai függvény: első szám nagyobb-e mint a második
int isGreater(int *a, int *b) {
    return *a > *b;
}

// 12. Logikai függvény: két szám egyenlő-e
int isEqual(int *a, int *b) {
    return *a == *b;
}

// 13. Logikai függvény: lebegőpontos számok összehasonlítása
int isFloatGreater(float *a, float *b) {
    return *a > *b;
}

// 14. Logikai függvény: lebegőpontos számok közel azonosak-e (0.01 tűréshatár)
int isFloatAlmostEqual(float *a, float *b) {
    return (fabs(*a - *b) < 0.01);
}

// 15. Logikai függvény: két egész szám különbsége nagyobb-e mint 10
int isDifferenceGreaterThanTen(int *a, int *b) {
    return abs(*a - *b) > 10;
}

// 16. Maradék nélkül osztható számok számlálása egy tömbben
int countDivisible(int arr16[], int size, int A) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr16[i] % A == 0) {
            count++;
        }
    }
    return count;
}

// 17. Logikai függvény: Melyik a nagyobb pointerekkel
int isBiggerWithPointers(int *a, int *b) {
    // Ellenőrizzük, hogy melyik a nagyobb szám és azt adjuk vissza
    if (*a > *b) {
        return *a;
    }
    else {
        return *b;
    }
}

// 18. Logikai függvény: Melyik a kissebb pointerekkel
int isSmallerWithPointers(int *a, int *b) {
    if (*a < *b) {
        return *a;
    }
    else {
        return *b;
    }
}

// 19. Negyzetre emeles pointerekkel
float toSquare(float *num) {
    // Visszaadjuk a szám négyzetét
    return (*num) * (*num);
}

int main() {
    int x = 10, y = 20, z = 5;
    float a = 5.5; float b = 6.5;
    printf("1. A változó értéke: %d\n", getValue(&x));

    printf("2. Swap előtt: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("   Swap után: x = %d, y = %d\n", x, y);

    printf("3. Rendezés előtt: x = %d, y = %d, z = %d\n", x, y, z);
    sortThree(&x, &y, &z);
    printf("   Rendezés után: x = %d, y = %d, z = %d\n", x, y, z);

    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int *min, *max;
    findMinMax(arr, 8, &min, &max);
    printf("4. Legkisebb: %d, Legnagyobb: %d\n", *min, *max);

    printf("5. Legkisebb szám: %d\n", minOfThree(&x, &y, &z));

    sortDescending(arr, 8);
    printf("6. Csökkenő sorrend: ");
    for (int i = 0; i < 8; i++) printf("%d ", arr[i]);
    printf("\n");

    shuffleArray(arr, 8);
    printf("7. Összekevert tömb: ");
    for (int i = 0; i < 8; i++) printf("%d ", arr[i]);
    printf("\n");

    zeroArray(arr, 8);
    printf("8. Nullázott tömb: ");
    for (int i = 0; i < 8; i++) printf("%d ", arr[i]);
    printf("\n");

    int arr2[] = {1, 2, 3, 4, 5};
    modifyArray(arr2, 5);
    printf("9. Módosított tömb: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr2[i]);
    printf("\n");

    printf("10. x < y? %s\n", isLess(&x, &y) ? "IGAZ" : "HAMIS");

    printf("11. x > y? %s\n", isGreater(&x, &y) ? "IGAZ" : "HAMIS");

    printf("12. x == y? %s\n", isEqual(&x, &y) ? "IGAZ" : "HAMIS");

    printf("13. x > y? %s\n", isFloatGreater(&a, &b) ? "IGAZ" : "HAMIS");

    printf("14. x ~ y? %s\n", isFloatAlmostEqual(&a, &b) ? "IGAZ" : "HAMIS");

    printf("15. x - y > 10? %s\n", isDifferenceGreaterThanTen(&x, &y) ? "IGAZ" : "HAMIS");

    //16:
    int arr16[] = {3, 1, 4, 1, 5, 9, 2, 6};
    printf("16. Maradék nélkül osztható számok (2-vel): %d\n", countDivisible(arr16, 8, 2));

    //17:
    int x17 = 8; int y17 = 5;
    int *px17 = &x17, *py17 = &y17;
    printf("17. A nagyobb szám: %d\n", isBiggerWithPointers(px17, py17));

    //18:
    int x18 = 7; int y18 = 6;
    int *px18 = &x18, *py18 = &y18;
    printf("18. A kissebb szám: %d\n", isSmallerWithPointers(px18, py18));

    //19:
    float x19=3.5;
    float *px19=&x19;
    printf("19. A szam negyzete: %.2f\n", toSquare(px19));



    return 0;
}
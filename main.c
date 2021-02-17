#include <stdio.h>
#include <stdlib.h>

struct arr {
    int count;
    int items[];
};

struct arr *arr_create(int count, int mod) {
    struct arr *new = malloc(sizeof(struct arr) + count * sizeof(int));
    new->count = count;
    for(int i = 0; i < count; ++i)
        new->items[i] = rand() % mod;
    return new;
}

void arr_free(struct arr *this) {
    free(this);
}

void arr_print(struct arr * this) {
    printf("[ ");
    for(int i = 0; i < this->count; ++i) {
        printf("%d ", this->items[i]);
    }
    printf("]\n");
}

int main(void) {
    struct arr *items = arr_create(10, 100);
    arr_print(items);
    arr_free(items);
}

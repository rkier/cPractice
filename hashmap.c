#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

int hashCode(char* name);
void add(char* key, int value, Person map[]);
int getAge(char* key, Person map[]);

int main(void) {

    Person map[100] = {0};
    
    int size = sizeof(map)/sizeof(Person);

    add("ricky", 30, map);
    add("lil", 28, map);
    add("bob", 65, map);

    printf("%d\n", getAge("ricky", map));
    printf("%d\n", getAge("lil", map));
    printf("%d\n", getAge("bob", map));

}

int hashCode(char* name) {
    int hash = 1;
    for (int i = 0; i < strlen(name); i++) {
        hash = hash * 31 + name[i];
    }
    return hash % 100;
}

void add(char* key, int value, Person map[]) {
    int hash = hashCode(key);
    while (map[hash].age != 0) {
        hash = (hash +1) % 100;
        printf("%d\n", hash);
    }
    map[hash].age = value;
    strncpy(map[hash].name, key, strlen(key));
    
}

int getAge(char* key, Person map[]) {
    int hash = hashCode(key);
    while (map[hash].name[0] != '\0') {
        if (hash > 99) {
            hash %= 100;
        }
        if (!(strcmp(key, map[hash].name))) {
            return map[hash].age;
        }
        hash++;
    }
    return -1;
}
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME); // Use strnlen for safety
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        // This hash function is simple but can lead to many collisions.
        // Consider a more robust one for real-world applications.
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

bool hash_table_insert(person *p) {
    if (p == NULL) return false;

    int index = hash(p->name);

    // --- IMPORTANT: This is where collision handling is needed ---
    // Currently, it just fails if a slot is occupied.
    // For a robust hash table, you'd implement chaining (linked lists)
    // or open addressing (probing for next available slot) here.
    if (hash_table[index] != NULL) {
        printf("Collision detected at index %d for '%s'. Cannot insert.\n", index, p->name);
        return false; // Slot already occupied
    }

    hash_table[index] = p; // Corrected: use [] for array access
    return true;
}

void printTable() {
    printf("--- Current Hash Table ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s (Age: %d)\n", i, hash_table[i]->name, hash_table[i]->age);
        }
    }
    printf("--------------------------\n");
}

// find person by name
person *hash_table_lookup (char *name) {
    int index = hash(name);
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name,name, TABLE_SIZE) == 0) {
        return hash_table[index];
    } else {
        return NULL;
    }
}

person *delete_hash_table(char *name){
    int index = hash(name);
    if (hash_table[index] != NULL && 
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
            person *tmp = hash_table[index];
            hash_table[index] = NULL;
            return tmp;
        }
    else {
        return NULL;
    }
}

int main() {
    init_hash_table();
    printTable(); // Show empty table

    person jcob = {.name = "Jcob", .age = 11};
    person startx = {.name = "dinesh", .age = 21};
    person yess = {.name = "sahil", .age = 1445};
    person yess1 = {.name = "sahil", .age = 1445};
    person another_jcob = {.name = "Jcob", .age = 50}; // Will likely cause a collision

    printf("\nAttempting insertions...\n");
    hash_table_insert(&jcob);
    hash_table_insert(&startx);
    hash_table_insert(&yess);
    hash_table_insert(&another_jcob); // This will fail if Jcob hashes to the same spot
    
    person *tmp = hash_table_lookup("sahil");
    if (tmp == NULL){
        printf("not found \n");
    } else{
        printf("found %s\n", tmp->name);
    }

    tmp = hash_table_lookup("George");
    if (tmp == NULL){
        printf("not found \n");
    } else{
        printf("found %s\n", tmp->name);
    }


    printf("\n");
    printTable(); // Show table after insertions

    return 0;
}

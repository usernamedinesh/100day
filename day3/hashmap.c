#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;    

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;        
    for(int i=0;i<length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i<TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    //table is empty    
}

void printTable() {
    for (int i= 0; i<TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t ---\n",i);
        } else {
            printf("\t%i\t%s\n", i , hash_table[i]-> name);
        }
    }
}

int main() {
    init_hash_table();
    printTable();
    // printf("name=> %u\n", hash("johna"));
    // printf("name=> %u\n", hash("john1"));
    // printf("name=> %u\n", hash("john"));
    printf("\n");
}

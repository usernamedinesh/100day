// another hash map implementation
#include <stdio.h>
#include <string.h>


typedef struct {
    char* key;
    int value;
} item;

item* linear_search(item* items, size_t size, const char* key) {
    for (int i=0; i<size; ++i){
        //comparing strings
        if (strcmp(items[i].key, key) == 0) {
            return &items[i];
        }
    }
    return NULL;
}

// lets first imlement linear seaach 
int main() {
    item items[] = {
        { "foo", 10}, {"bar", 42}, {"bazz", 34}, {"bob", 33}, {"x", 35}
    };
    size_t s = sizeof(items)/sizeof(item); 
    item* found = linear_search(items, s, "foo");
    if(!found) {
        printf("not found");
    } else {
        printf("found");
    }
    printf(" \n");
    return 0;
}

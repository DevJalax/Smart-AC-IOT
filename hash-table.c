#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    int size;
    Node **table;
} HashTable;

HashTable *hash_table_new(int size) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->table = (Node **)calloc(size, sizeof(Node *));
    return table;
}

int hash(HashTable *table, char *key) {
    int hash = 0;
    int i = 0;
    while (key[i]!= '\0') {
        hash += key[i];
        i++;
    }
    return hash % table->size;
}

void hash_table_add(HashTable *table, char *key, int value) {
    int index = hash(table, key);
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = table->table[index];
    table->table[index] = node;
}

int hash_table_get(HashTable *table, char *key) {
    int index = hash(table, key);
    Node *node = table->table[index];
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void hash_table_free(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Node *node = table->table[i];
        while (node!= NULL) {
            Node *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table->table);
    free(table);
}

int main() {
    HashTable *table = hash_table_new(TABLE_SIZE);
    hash_table_add(table, "hello", 5);
    hash_table_add(table, "world", 10);
    printf("%d\n", hash_table_get(table, "hello")); // prints 5
    printf("%d\n", hash_table_get(table, "world")); // prints 10
    hash_table_free(table);
    return 0;
}

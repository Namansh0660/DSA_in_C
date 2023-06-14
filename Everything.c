#include <stdio.h>
#include <stdlib.h>

// Hash table node structure
typedef struct HashNode {
    int key;
    struct HashNode* next;
} HashNode;

// Hash table structure
typedef struct {
    int size;
    HashNode** table;
} HashTable;

// Function to create a new hash table node
HashNode* createNode(int key) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new hash table
HashTable* createTable(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->table = (HashNode**)malloc(sizeof(HashNode*) * size);
    for (int i = 0; i < size; i++)
        table->table[i] = NULL;
    return table;
}

// Hash function 1 (for double hashing)
int hash1(int key, int size) {
    return key % size;
}

// Hash function 2 (for double hashing)
int hash2(int key, int size) {
    return (key % (size - 2)) + 1;
}

// Separate chaining: Insert a key into the hash table using separate chaining
void separateChainingInsert(HashTable* table, int key) {
    int hashValue = key % table->size;
    HashNode* newNode = createNode(key);
    
    if (table->table[hashValue] == NULL)
        table->table[hashValue] = newNode;
    else {
        HashNode* currentNode = table->table[hashValue];
        while (currentNode->next != NULL)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }
}

// Linear probing: Insert a key into the hash table using linear probing
void linearProbingInsert(HashTable* table, int key) {
    int hashValue = key % table->size;
    
    if (table->table[hashValue] == NULL)
        table->table[hashValue] = createNode(key);
    else {
        int i = 1;
        while (table->table[(hashValue + i) % table->size] != NULL)
            i++;
        table->table[(hashValue + i) % table->size] = createNode(key);
    }
}

// Quadratic probing: Insert a key into the hash table using quadratic probing
void quadraticProbingInsert(HashTable* table, int key) {
    int hashValue = key % table->size;
    
    if (table->table[hashValue] == NULL)
        table->table[hashValue] = createNode(key);
    else {
        int i = 1;
        while (table->table[(hashValue + i * i) % table->size] != NULL)
            i++;
        table->table[(hashValue + i * i) % table->size] = createNode(key);
    }
}

// Double hashing: Insert a key into the hash table using double hashing
void doubleHashingInsert(HashTable* table, int key) {
    int hashValue = hash1(key, table->size);
    
    if (table->table[hashValue] == NULL)
        table->table[hashValue] = createNode(key);
    else {
        int stepSize = hash2(key, table->size);
        int i = 1;
        while (table->table[(hashValue + i * stepSize) % table->size] != NULL)
            i++;
        table->table[(hashValue + i * stepSize) % table->size] = createNode(key);
    }
}

// Function to display the hash table
void displayTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        printf("%d: ", i);
        HashNode* currentNode = table->table[i];
        while (currentNode != NULL) {
            printf("%d -> ", currentNode->key);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    int elements[] = {96, 48, 63, 29, 87, 77, 48, 65, 69, 94, 61};
    int numElements = sizeof(elements) / sizeof(elements[0]);
    int tableSize = 13;
    
    HashTable* separateChainingTable = createTable(tableSize);
    HashTable* linearProbingTable = createTable(tableSize);
    HashTable* quadraticProbingTable = createTable(tableSize);
    HashTable* doubleHashingTable = createTable(tableSize);
    
    printf("Separate Chaining:\n");
    for (int i = 0; i < numElements; i++)
        separateChainingInsert(separateChainingTable, elements[i]);
    displayTable(separateChainingTable);
    printf("\n");
    
    printf("Linear Probing:\n");
    for (int i = 0; i < numElements; i++)
        linearProbingInsert(linearProbingTable, elements[i]);
    displayTable(linearProbingTable);
    printf("\n");
    
    printf("Quadratic Probing:\n");
    for (int i = 0; i < numElements; i++)
        quadraticProbingInsert(quadraticProbingTable, elements[i]);
    displayTable(quadraticProbingTable);
    printf("\n");
    
    printf("Double Hashing:\n");
    for (int i = 0; i < numElements; i++)
        doubleHashingInsert(doubleHashingTable, elements[i]);
    displayTable(doubleHashingTable);
    printf("\n");

    return 0;
}

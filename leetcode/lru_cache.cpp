#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

#define CACHE_NEVER_USED -1000000

void *mem;

typedef struct Node {
    int key;
    int val;
    struct Node *prev, *next;
} Node;

map<int, Node*> hash_table;

Node *head, *tail;

void flushCache(Node *p) {
    if (p == head->next) {
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->next = head->next;
    head->next->prev = p;
    head->next = p;
}

void lruCacheInit(int capacity) {
    // all data in one memory call
    mem = malloc(sizeof(Node)*(capacity+2));
    Node *memNodeList = (Node*)mem + 1;
    int i;
    for (i=0; i<capacity; i++) {
        Node *node = memNodeList + i;
        node->key = CACHE_NEVER_USED;
        node->val = -1;
        node->prev = node - 1;
        node->next = node + 1;
    }
    head = memNodeList - 1;
    head->prev = NULL;
    head->next = head + 1;
    tail = memNodeList + capacity;
    tail->prev = tail - 1;
    tail->next = NULL;
}

void lruCacheFree() {
    free(mem);
    head = tail = NULL;
}

int lruCacheGet(int key) {
    // hash will be better
    Node *p = hash_table[key];
    if (p) {
        flushCache(p);
        return p->val;
    }
    else {
        return -1;
    }
}

void lruCacheSet(int key, int value) {
    Node *p = hash_table[key];
    if (p) {
        p->val = value;
        flushCache(p);
        return;
    }
    //not found, remove last one
    hash_table.erase(tail->prev->key);
    p = tail->prev;
    p->key = key;
    p->val = value;
    hash_table[key] = p;
    flushCache(p);
}

class LRUCache {
  public:
    LRUCache(int capacity) {
        lruCacheInit(capacity);
    }
    ~LRUCache() {
        lruCacheFree();
    }
    int get(int key) {
        return lruCacheGet(key);
    }

    void set(int key, int value) {
        lruCacheSet(key, value);
    }
};


int mmain(int argc, char *argv[]) {
    lruCacheInit(10);
    printf("Get key(10): %d\n", lruCacheGet(10));
    printf("Set key(10)\n");
    lruCacheSet(10, 11);
    printf("Get key(10): %d\n", lruCacheGet(10));
    int i;
    for (i=0; i<100; i++) {
        int r = rand() % 100;
        printf("Set key(%d) with %d\n", i, r);
        lruCacheSet(i, r);
        r = rand() % 100;
        printf("Get key(%d): %d\n", r/2, lruCacheGet(r/2));
    }
    return 0;
}

int main() {
    LRUCache c(2);
    printf("%d\n", c.get(2));
    c.set(2, 6);
    printf("%d\n", c.get(1));
    c.set(1, 5);
    c.set(1, 2);
    printf("%d\n", c.get(1));
    printf("%d\n", c.get(2));
    return 0;
}

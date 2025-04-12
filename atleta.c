#include <stdio.h>
#include <stdlib.h>

#define MAX 3  // Ordem da árvore B (máximo de chaves por nó)
#define MIN 2  // Grau mínimo (mínimo de chaves por nó)

// Estrutura do nó da árvore B
typedef struct BTreeNode {
    int keys[MAX + 1]; // Máximo de chaves por nó
    struct BTreeNode *children[MAX + 2]; // Máximo de filhos por nó
    int n; // Número de chaves no nó
    int leaf; // 1 se o nó é folha, 0 se não é
} BTreeNode;

// Estrutura da árvore B
typedef struct BTree {
    BTreeNode *root; // Ponteiro para o nó raiz
    int t; // Grau mínimo
} BTree;

// Declaração antecipada das funções
BTreeNode* createNode(int t, int leaf);
void traverse(BTreeNode *node);
BTreeNode* search(BTreeNode *node, int key);
void splitChild(BTreeNode *node, int idx, BTreeNode *y, int t);
void insertNonFull(BTreeNode *node, int key, int t);
void insert(BTree *tree, int key);
int findKey(BTreeNode *node, int key);
void borrowFromPrev(BTreeNode *node, int idx);
void borrowFromNext(BTreeNode *node, int idx);
void merge(BTreeNode *node, int idx);
void fill(BTreeNode *node, int idx);
void removeFromLeaf(BTreeNode *node, int idx);
void removeFromNonLeaf(BTreeNode *node, int idx, int t);
void deleteKey(BTreeNode *node, int key, int t);

// Função para criar um novo nó
BTreeNode* createNode(int t, int leaf) {
    BTreeNode *newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->leaf = leaf;
    newNode->n = 0;
    for (int i = 0; i < MAX + 2; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Função para percorrer a árvore
void traverse(BTreeNode *node) {
    int i;
    for (i = 0; i < node->n; i++) {
        if (!node->leaf) {
            traverse(node->children[i]);
        }
        printf("%d ", node->keys[i]);
    }
    if (!node->leaf) {
        traverse(node->children[i]);
    }
}

// Função para buscar uma chave na árvore B
BTreeNode* search(BTreeNode *node, int key) {
    int i = 0;
    while (i < node->n && key > node->keys[i]) {
        i++;
    }
    if (i < node->n && key == node->keys[i]) {
        return node;
    }
    if (node->leaf) {
        return NULL;
    }
    return search(node->children[i], key);
}

// Função para dividir o nó filho
void splitChild(BTreeNode *node, int idx, BTreeNode *y, int t) {
    BTreeNode *z = createNode(t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }

    if (!y->leaf) {
        for (int j = 0; j < t; j++) {
            z->children[j] = y->children[j + t];
        }
    }

    y->n = t - 1;

    for (int j = node->n; j >= idx + 1; j--) {
        node->children[j + 1] = node->children[j];
    }

    node->children[idx + 1] = z;

    for (int j = node->n - 1; j >= idx; j--) {
        node->keys[j + 1] = node->keys[j];
    }

    node->keys[idx] = y->keys[t - 1];
    node->n++;
}

// Função para inserir uma nova chave em um nó não cheio
void insertNonFull(BTreeNode *node, int key, int t) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    } else {
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;
        if (node->children[i]->n == MAX) {
            splitChild(node, i, node->children[i], t);
            if (node->keys[i] < key) {
                i++;
            }
        }
        insertNonFull(node->children[i], key, t);
    }
}

// Função para inserir uma nova chave na árvore B
void insert(BTree *tree, int key) {
    BTreeNode *root = tree->root;
    if (root->n == MAX) {
        BTreeNode *s = createNode(tree->t, 0);
        s->children[0] = root;
        splitChild(s, 0, root, tree->t);
        int i = 0;
        if (s->keys[0] < key) {
            i++;
        }
        insertNonFull(s->children[i], key, tree->t);
        tree->root = s;
    } else {
        insertNonFull(root, key, tree->t);
    }
}

// Função para encontrar o índice de uma chave em um nó
int findKey(BTreeNode *node, int key) {
    int idx = 0;
    while (idx < node->n && node->keys[idx] < key) {
        idx++;
    }
    return idx;
}

// Função para emprestar uma chave do irmão anterior
void borrowFromPrev(BTreeNode *node, int idx) {
    BTreeNode *child = node->children[idx];
    BTreeNode *sibling = node->children[idx - 1];

    for (int i = child->n - 1; i >= 0; --i) {
        child->keys[i + 1] = child->keys[i];
    }
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i) {
            child->children[i + 1] = child->children[i];
        }
    }
    child->keys[0] = node->keys[idx - 1];
    if (!child->leaf) {
        child->children[0] = sibling->children[sibling->n];
    }
    node->keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n += 1;
    sibling->n -= 1;
}

// Função para emprestar uma chave do irmão seguinte
void borrowFromNext(BTreeNode *node, int idx) {
    BTreeNode *child = node->children[idx];
    BTreeNode *sibling = node->children[idx + 1];

    child->keys[child->n] = node->keys[idx];
    if (!child->leaf) {
        child->children[child->n + 1] = sibling->children[0];
    }
    node->keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; ++i) {
        sibling->keys[i - 1] = sibling->keys[i];
    }
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i) {
            sibling->children[i - 1] = sibling->children[i];
        }
    }
    child->n += 1;
    sibling->n -= 1;
}

// Função para mesclar um nó com o irmão
void merge(BTreeNode *node, int idx) {
    BTreeNode *child = node->children[idx];
    BTreeNode *sibling = node->children[idx + 1];

    child->keys[MIN - 1] = node->keys[idx];
    for (int i = 0; i < sibling->n; ++i) {
        child->keys[i + MIN] = sibling->keys[i];
    }
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i) {
            child->children[i + MIN] = sibling->children[i];
        }
    }
    for (int i = idx + 1; i < node->n; ++i) {
        node->keys[i - 1] = node->keys[i];
    }
    for (int i = idx + 2; i <= node->n; ++i) {
        node->children[i - 1] = node->children[i];
    }
    child->n += sibling->n + 1;
    node->n--;
    free(sibling);
}

// Função para preencher o nó se estiver subpreenchido
void fill(BTreeNode *node, int idx) {
    if (idx != 0 && node->children[idx - 1]->n >= MIN) {
        borrowFromPrev(node, idx);
    } else if (idx != node->n && node->children[idx + 1]->n >= MIN) {
        borrowFromNext(node, idx);
    } else {
        if (idx != node->n) {
            merge(node, idx);
        } else {
            merge(node, idx - 1);
        }
    }
}

// Função para remover uma chave de um nó folha
void removeFromLeaf(BTreeNode *node, int idx) {
    for (int i = idx + 1; i < node->n; ++i) {
        node->keys[i - 1] = node->keys[i];
    }
    node->n--;
}

// Função para remover uma chave de um nó não folha
void removeFromNonLeaf(BTreeNode *node, int idx, int t) {
    int key = node->keys[idx];
    if (node->children[idx]->n >= t) {
        BTreeNode *cur = node->children[idx];
        while (!cur->leaf) {
            cur = cur->children[cur->n];
        }
        int pred = cur->keys[cur->n - 1];
        node->keys[idx] = pred;
        deleteKey(node->children[idx], pred, t);
    } else if (node->children[idx + 1]->n >= t) {
        BTreeNode *cur = node->children[idx + 1];
        while (!cur->leaf) {
            cur = cur->children[0];
        }
        int succ = cur->keys[0];
        node->keys[idx] = succ;
        deleteKey(node->children[idx + 1], succ, t);
    } else {
        merge(node, idx);
        deleteKey(node->children[idx], key, t);
    }
}

// Função para remover uma chave
void deleteKey(BTreeNode *node, int key, int t) {
    int idx = findKey(node, key);
    if (idx < node->n && node->keys[idx] == key) {
        if (node->leaf) {
            removeFromLeaf(node, idx);
        } else {
            removeFromNonLeaf(node, idx, t);
        }
    } else {
        if (node->leaf) {
            printf("The key %d is not present in the tree\n", key);
            return;
        }
        int flag = ((idx == node->n) ? 1 : 0);
        if (node->children[idx]->n < t) {
            fill(node, idx);
        }
        if (flag && idx > node->n) {
            deleteKey(node->children[idx - 1], key, t);
        } else {
            deleteKey(node->children[idx], key, t);
        }
    }
}

// Função principal
int main() {
    BTree tree;
    tree.t = MIN;
    tree.root = createNode(tree.t, 1);

    insert(&tree, 10);
    insert(&tree, 20);
    insert(&tree, 5);
    insert(&tree, 6);
    insert(&tree, 12);
    insert(&tree, 30);
    insert(&tree, 7);
    insert(&tree, 17);

    printf("Traversal of the tree:\n");
    traverse(tree.root);
    printf("\n");

    deleteKey(tree.root, 6, tree.t);
    printf("Traversal after deletion of 6:\n");
    traverse(tree.root);
    printf("\n");

    deleteKey(tree.root, 13, tree.t);
    printf("Traversal after deletion of 13:\n");
    traverse(tree.root);
    printf("\n");

    deleteKey(tree.root, 7, tree.t);
    printf("Traversal after deletion of 7:\n");
    traverse(tree.root);
    printf("\n");

    deleteKey(tree.root, 4, tree.t);
    printf("Traversal after deletion of 4:\n");
    traverse(tree.root);
    printf("\n");

    deleteKey(tree.root, 2, tree.t);
    printf("Traversal after deletion of 2:\n");
    traverse(tree.root);
    printf("\n");

    deleteKey(tree.root, 16, tree.t);
    printf("Traversal after deletion of 16:\n");
    traverse(tree.root);
    printf("\n");

    return 0;
}

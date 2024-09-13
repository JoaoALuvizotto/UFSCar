#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bst {
    struct _bst* l;
    struct _bst* r;
    char* str;
} bst;

bst* get(bst* root, char* str) {
    while(root)
    {
        if (strcmp(str, root->str) == 0)
            return root;
        else if(strcmp(str, root->str) > 0)
            root = root->r;
        else
            root = root->l;
    }
    
    return NULL;
}

bst* put(bst* root, char* str) {
    if(root) {
        int cmp = strcmp(root->str, str);
        if(cmp > 0)
            root->l = put(root->l,str);
        else if (cmp < 0)
            root->r = put(root->r,str);
        return root;
    } else {
        bst* novo = (bst*)malloc(sizeof(bst));
        novo->str = (char*)malloc(sizeof(char)*(strlen(str)+1));
        strcpy(novo->str,str);
        novo->l = novo->r = NULL;
        return novo;
    }
}

bst* max(bst* root) {
    while (root->r) {
        root = root->r;
    }
    return root;

}

bst* min(bst* root) {
    while (root->l) {
        root = root->l;
    }
    return root;
}

bst* rem(bst* root, char* str) {
    if (!root)
        return NULL;
    
    if (strcmp(root->str, str) == 0)
    {
        if (root->l == NULL && root->r == NULL)
            return NULL;
        else if (root->l != NULL && root->r == NULL)
            return root->l;
        else if (root->l == NULL && root->r != NULL)
            return root->r;
        else
        {
            bst* temp = max(root->l);
            char* tempC = strdup(root->str);
            root->str = strdup(temp->str);
            temp->str = tempC;
            root->l = rem(root->l, temp->str);
        }
    }
    else if (strcmp(str, root->str) > 0)
        root->r = rem(root->r, str);
    else
        root->l = rem(root->l, str);

    return root;
}

void del(bst* root) {
    if(root) {
        del(root->l);
        del(root->r);
        free(root->str);
        free(root);
    }
}

int main() {

    char comando[2], palavra[255];

    bst* raiz = NULL;

    while(scanf("%s", comando) != EOF) {
        scanf("%s", palavra);
        if( comando[0] == 'P' ) 
            raiz = put(raiz,palavra);
        else if( comando[0] == 'R' ) 
            raiz = rem(raiz,palavra);
        else if( comando[0] == 'G' ) {
            bst* result = get(raiz,palavra);
            if( result )
                printf("%s encontrada\n", result->str);
            else
                printf("%s nao foi encontrada\n", palavra);
        }
    }

    del(raiz);

    return 0;
}

#include "Pagoda.h"


Pagoda merge(Pagoda L, Pagoda R)
{
    // What if one of the pagodas is NULL
    if (L == NULL)   return R;
    if (R == NULL)   return L;
    Pagoda F = NULL;

    // Find bottom of L's rightmost edge
    Pagoda* BG = &L->right;
    // Find bottom of R's leftmost edge
    Pagoda* BD = &R->left;

    // Merge repeatedly until one of the pagodas is NULL
    Pagoda aux;
    while (L != NULL && R != NULL)
    {
        if ((*BG)->data > (*BD)->data)
        {
            aux = *BD;

            if (*BD == (*BD)->left)  R = NULL;
            *BD = (*BD)->left;

            if (F == NULL)   aux->left = aux;
            else
            {
                aux->left = F->left;
                F->left = aux;
            }

            F = aux;
        }
        else
        {
            aux = *BG;
            if (*BG == (*BG)->right) L = NULL;
            *BG = (*BG)->right;

            if (F == NULL) aux->right = aux;
            else
            {
                aux->right = F->right;
                F->right = aux;
            }

            F = aux;
        }
    }

    // Finish merge
    if (L != NULL)   aux = F->right, F->right = L->right, L->right = aux, F = L;
    if (R != NULL)   aux = F->left, F->left = R->left, R->left = aux, F = R;
    return F;
}

void deleteRoot_Pagoda(Pagoda* P)
{
    if (P == NULL || *P == NULL) return;

    Pagoda aux = *P;
    Pagoda L = *P;
    Pagoda R = *P;

    while (L->right != *P)   L = L->right;
    while (R->left != *P)   R = R->left;

    if (*P == R && *P == L) { free(*P), * P = NULL; return; }
    if (*P == R) { *P = L, L->right = aux->right; free(aux); return; }
    if (*P == L) { *P = R, R->left = aux->left; free(aux); return; }

    L->right = aux->right;
    R->left = aux->left;
    free(aux);

    *P = merge(L, R);
}

int insert_Pagoda(Pagoda* P, Pgcase e)
{
    if (P == NULL)   return 0;

    Pagoda new_node = (Pagoda)Construct(e, NULL, NULL);
    
    if (new_node == NULL)    return 0;

    new_node->left = new_node;
    new_node->right = new_node;

    *P = merge(*P, new_node);

    return 1;
}

void heapSort(int* A, int size)
{
    if (A == NULL || size <= 1)  return;

    Pagoda F = NULL;

    for (int i = 0; i < size; i++)
        insert_Pagoda(&F, *(A + i));

    for (int i = size - 1; i >= 0; i--)
        *(A + i) = F->data, deleteRoot_Pagoda(&F);
}
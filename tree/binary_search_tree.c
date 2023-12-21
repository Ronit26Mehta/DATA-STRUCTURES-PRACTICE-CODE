#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* tree;

void create_tree(struct node**);
struct node* insert_element(struct node*, int);
void preorderTraversal(struct node*);
void inorderTraversal(struct node*);
void postorderTraversal(struct node*);
struct node* findSamllestElement(struct node*);
struct node* findLargestElement(struct node*);
int totalNodes(struct node*);
struct node* deleteTree(struct node*);
struct node* deleteElement(struct node*, int);
struct node* mirrorImage(struct node*);
int totalExternalNodes(struct node*);
int totalInternalNodes(struct node*);
int height(struct node*);

int main() {
    int choice, val;
    struct node* ptr;
    create_tree(&tree);
    do {
        printf("\nRonitSatishMehta 6009230207");
        printf("\n\t------------MAIN MENU ---------\n");
        printf("\n1.Insert Element");
        printf("\n2.preorder traversal");
        printf("\n3.inorder traversal");
        printf("\n4.postorder traversal");
        printf("\n5.Find the smallest element");
        printf("\n6.Find the largest Element");
        printf("\n7. count the total number of nodes");
        printf("\n8.delete The tree");
        printf("\n9.delete an element");
        printf("\n10.mirrorImage of tree");
        printf("\n11.total internal nodes");
        printf("\n12.total external nodes");
        printf("\n13.height of tree");
        printf("\n14.Exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n Enter the value of the new node : ");
                scanf("%d", &val);
                tree = insert_element(tree, val);
                break;
            case 2:
                printf("\n The elements of the tree are : \n");
                preorderTraversal(tree);
                break;
            case 3:
                printf("\n The elements of the tree are : \n");
                inorderTraversal(tree);
                break;
            case 4:
                printf("\n The elements of the tree are : \n");
                postorderTraversal(tree);
                break;
            case 5:
                ptr = findSamllestElement(tree);
                printf("\n Smallest element is: %d", ptr->data);
                break;
            case 6:
                ptr = findLargestElement(tree);
                printf("\n Largest element is: %d", ptr->data);
                break;
            case 7:
                printf("\n Total no. of nodes = %d", totalNodes(tree));
                break;
            case 8:
                tree = deleteTree(tree);
                break;
            case 9:
                printf("\nEnter val to be deleted:");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 10:
                tree = mirrorImage(tree);
                printf("\nThe mirror image of tree is created.");
                break;
            case 11:
                printf("\nTotal number of the internal node=%d ", totalInternalNodes(tree));
                break;
            case 12:
                printf("\nTotal number of the external nodes=%d", totalExternalNodes(tree));
                break;
            case 13:
                printf("\nThe height of the tree is = %d", height(tree));
                break;
            case 14:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice");
                break;
        }
    } while (choice != 14);
    return 0;
}

void create_tree(struct node** tree) {
    *tree = NULL;
}

struct node* insert_element(struct node* tree, int val) {
    struct node* ptr, *nodeptr, *parentptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL) {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL) {
            parentptr = nodeptr;
            if (val < nodeptr->data) {
                nodeptr = nodeptr->left;
            }
            else {
                nodeptr = nodeptr->right;
            }
        }
        if (val < parentptr->data) {
            parentptr->left = ptr;
        }
        else {
            parentptr->right = ptr;
        }
    }
    return tree;
}

void preorderTraversal(struct node* tree) {
    if (tree != NULL) {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node* tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node* tree) {
    if (tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("\t%d", tree->data);
    }
}

struct node* findSamllestElement(struct node* tree) {
    if ((tree == NULL) || (tree->left == NULL)) {
        return tree;
    }
    else {
        return findSamllestElement(tree->left);
    }
}

struct node* findLargestElement(struct node* tree) {
    if ((tree == NULL) || (tree->right == NULL)) {
        return tree;
    }
    else {
        return findLargestElement(tree->right);
    }
}

int totalNodes(struct node* tree) {
    if (tree == NULL) {
        return 0;
    }
    else {
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
    }
}

struct node* deleteTree(struct node* tree) {
    if (tree != NULL) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    return NULL;
}

struct node* deleteElement(struct node* tree, int val) {
    struct node* cur, * parent, * suc, * psuc, * ptr;
    if (tree == NULL) {
        printf("\nTree is Empty");
        return tree;
    }
    parent = tree;
    cur = tree;
    while (cur != NULL && val != cur->data) {
        parent = cur;
        if (val < cur->data) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    if (cur == NULL) {
        printf("\nThe value to be deleted is not found");
        return tree;
    }
    if (cur->left == NULL) {
        ptr = cur->right;
    }
    else if (cur->right == NULL) {
        ptr = cur->left;
    }
    else {
        psuc = cur;
        suc = cur->left;
        while (suc->right != NULL) {
            psuc = suc;
            suc = suc->right;
        }
        if (cur == psuc) {
            suc->right = cur->right;
        }
        else {
            suc->right = cur->right;
            psuc->right = suc->left;
            suc->left = cur->left;
        }
        ptr = suc;
    }
    if (parent->left == cur) {
        parent->left = ptr;
    }
    else {
        parent->right = ptr;
    }
    free(cur);
    return tree;
}

struct node* mirrorImage(struct node* tree) {
    struct node* ptr;
    if (tree != NULL) {
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr = tree->left;
        tree->left = tree->right;
        tree->right = ptr;
    }
    return tree;
}

int totalInternalNodes(struct node* tree) {
    if ((tree == NULL) || (tree->left == NULL && tree->right == NULL)) {
        return 0;
    }
    else {
        return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
    }
}

int totalExternalNodes(struct node* tree) {
    if (tree == NULL) {
        return 0;
    }
    else if (tree->left == NULL && tree->right == NULL) {
        return 1;
    }
    else {
        return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
    }
}

int height(struct node* tree) {
    int leftheight, rightheight;
    if (tree == NULL) {
        return 0;
    }
    else {
        leftheight = height(tree->left);
        rightheight = height(tree->right);
        return (leftheight > rightheight) ? (leftheight + 1) : (rightheight + 1);
    }
}

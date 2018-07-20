//Remove all nodes which don’t lie in any path with sum>= k
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new Binary Tree node with given data
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void prune(Node *root,int k)
{
    if(root==NULL)
    {
        return NULL;
    }
    root->left = prune(root->left,(k-(root->data)));
    root->right = prune(root->right,k-(root->data));
    if(root->left==NULL&&root->right==NULL&&(root->data-sum)<0)
    {
        free(root);
        root = NULL;
    }
    return root;
}

int main()
{
    int k = 45;
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);
 
    printf("Tree before truncation\n");
    print(root);
 
    root = prune(root, k); // k is 45
 
    printf("\n\nTree after truncation\n");
    print(root);
 
    return 0;
}
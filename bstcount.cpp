#include <iostream>

using namespace std;

typedef struct node
{
    int key;
    int value;
    node *left;
    node *right;
} Node;

class tree
{

  private:
    Node *root;
    void insert(int key, Node *leaf);
    Node *createNode(int key);
    void inorder(Node *leaf);
    int countMoreThan(int key, Node *leaf);

  public:
    tree();
    void inorder();
    void insert(int key);
    int countMoreThan(int key);
};

tree::tree()
{
    root = NULL;
}

Node *tree::createNode(int key)
{
    Node *n = new Node;
    n->key = key;
    n->value = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void tree::insert(int key, Node *leaf)
{
    if (key <= leaf->key)
    {
        leaf->value += 1; //store new node
        if (leaf->left)   //root != NULL
        {
            insert(key, leaf->left);
        }
        else
        {
            leaf->left = createNode(key);
        }
    }
    else
    {
        leaf->value += 1;
        if (leaf->right) //root != NULL
        {
            insert(key, leaf->right);
        }
        else
        {
            leaf->right = createNode(key);
        }
    }
}
void tree::insert(int key)
{
    if (root) //root != NULL
    {
        insert(key, root);
    }
    else
    {
        root = createNode(key);
    }
}
int tree::countMoreThan(int key, Node *leaf)
{
    if (!leaf) //leaf == NULL;
    {
        return 0;
    }
    else if (key < leaf->key)
    {
        if (leaf->right) //leaf->right != NULL
            return 1 + leaf->right->value + countMoreThan(key, leaf->left);
        else
            return 1 + countMoreThan(key, leaf->left);
    }
    else if (key > leaf->key)
    {
        return countMoreThan(key, leaf->right);
    }
    else if (key == leaf->key)
    {
        if (leaf->right) //leaf->right != NULL
            return leaf->right->value;
        else
            return 0;
    }
    cout << "you should not been here!!!" << endl;
}
int tree::countMoreThan(int key)
{
    return countMoreThan(key, root);
}
void tree::inorder(Node *leaf)
{
    if (leaf) //leaf != NULL
    {
        inorder(leaf->left);
        // cout << "(" << leaf->key << ',' << leaf->value << "),"; //debug
        cout << leaf->key << ',';
        inorder(leaf->right);
    }
}

void tree::inorder()
{
    inorder(root);
    cout << endl;
}

int Number(char *str)
{
    int val = 0, i = 0;
    while (*(str + i) != '\0')
    {
        val = val * 10 + *(str + i) - '0';
        i++;
    }
    return val;
}
int main(int argc, char *argv[])
{
    /**
     *  programs that search value that more than key that you insert in first arugment
     *  next arugment will be set of number that we will search
     **/

    if (argc >= 3)
    {
        int value = Number(argv[1]);
        tree *t = new tree();

        cout << "input: ";
        for (int i = 2; i < argc; i++)
        {
            cout << argv[1] << ',';
            t->insert(Number(argv[i]));
        }
        cout << endl;

        cout << "x > " << value << endl;
        t->inorder();

        cout << "count: " << t->countMoreThan(value) << endl;
    }
    else
    {
        cout << "request ./bstcount {value} {set of number}" << endl;
        return 1;
    }
    tree *t = new tree();

    return 0;
}
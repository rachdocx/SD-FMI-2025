#include <iostream>

using namespace std;

struct ABC {
    int info;
    ABC* left;
    ABC* right;
};

void inserare(ABC* &root, int val) {
    if(root == NULL) {
        root = new ABC;
        root -> info = val;
        root -> left = NULL;
        root -> right = NULL;
    } else {
        if(val < root -> info) {
            inserare(root -> left, val);
        } else {
            inserare(root -> right, val);
        }
    }
}

int test_case(ABC* root);

int main() {
    int n;
    cin >> n;
    ABC* root = NULL;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        inserare(root, x);
    }
    int sol = test_case(root);
    cout << sol;
    return 0;
}

// MODIFY START

int test_case(ABC* root) {
    if (root == NULL ||root->left == NULL && root->right==NULL) {
        return 0;
    }
    ABC * minnod = root;
    while (minnod->left != NULL) {
        minnod = minnod->left;
    }
    ABC * maxnod = root;
    while (maxnod->right != NULL) {
        maxnod = maxnod ->right;
    }
    return maxnod->info - minnod->info;
}



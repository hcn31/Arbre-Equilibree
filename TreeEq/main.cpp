#include <iostream>
#include <queue>

class Node {
 public:
  int val;
  int taille;
  Node* left;
  Node* right;

  Node(int val) {
    this->val = val;
      this->taille = 1;
   this->left = NULL;
    this->right = NULL;
  }
};

class Mytree {
 public:
  Node* rac;

  Mytree() {
    rac = NULL;
  }

  int height(Node* node) {
    if (node == NULL) {
      return 0;
    }
    return node->taille;
  }

  int heigbal(Node* node) {
    if (node == NULL) {
      return 0;
    }
    return height(node->left) - height(node->right);
  }

  Node* Droit(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->taille = std::max(height(y->left), height(y->right)) + 1;
    x->taille = std::max(height(x->left), height(x->right)) + 1;
    return x;
  }

  Node* Gauche(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;


    x->taille = std::max(height(x->left), height(x->right)) + 1;
    y->taille = std::max(height(y->left), height(y->right)) + 1;


    return y;
  }

  Node* insert(Node* node, int key) {
      if (node == NULL) {
          return new Node(key);
      }

      if (key < node->val) {
          node->left = insert(node->left, key);
      } else if (key > node->val) {
          node->right = insert(node->right, key);
      } else {
          return node;
      }

      node->taille = std::max(height(node->left), height(node->right)) + 1;

      int balance = heigbal(node);

      if (balance > 1 && key < node->left->val) {
          return Droit(node);
      }

      if (balance < -1 && key > node->right->val) {
          return Gauche(node);
      }

      if (balance > 1 && key > node->left->val) {
          node->left = Gauche(node->left);
          return Droit(node);
      }

      if (balance < -1 && key < node->right->val) {
          node->right = Droit(node->right);
          return Gauche(node);
      }

      return node;
  }
    void AffArb(Node* root, int level) {
        if (root != NULL) {
            AffArb(root->right, level + 1);
            std::cout << std::endl;

            for (int i = 0; i < level && root != this->rac; i++)
                std::cout << "             ";
            std::cout << root->val;
            AffArb(root->left, level + 1);
        }
    }



};
int main() {
    Mytree tree;

    tree.rac = tree.insert(tree.rac, 1);
    tree.rac = tree.insert(tree.rac, 0);
    tree.rac = tree.insert(tree.rac, 55);
    tree.rac = tree.insert(tree.rac, 13);
    tree.rac = tree.insert(tree.rac, 10);
    tree.rac = tree.insert(tree.rac, 25);
    std::cout<<"\n";
    tree.AffArb(tree.rac,0);

    return 0;
}

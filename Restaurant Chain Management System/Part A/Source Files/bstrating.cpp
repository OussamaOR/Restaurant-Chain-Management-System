#include "bstrating.h"
#include "MonthRating.h"
//already have the root (head)
//get depending on a vall + r values things
bstrating::bstrating(MonthRating x) : data(x), left(nullptr), right(nullptr) {
}
bstrating::~bstrating()
{
    //dtor
}

/*bstrating::bstrating(const bstrating& other)
{
    //copy ctor
}

*/

void bstrating::insert_Mrating(MonthRating& x ,bstrating*& root ){
    if( root == nullptr ){
	     root = new bstrating{x};
}else {if( x < root->data ){ insert_Mrating( x, root->left );}
        else {if( root->data < x )
		      {insert_Mrating( x, root->right );}}}
}


void bstrating::remove_Mrating(MonthRating& x ,bstrating*& root )
 {
 	if( root == nullptr )
	    return;
 	if( x < root->data )
 	    remove_Mrating( x, root->left );
 	else if( root->data < x )
 		 remove_Mrating( x, root->right );
 	     else if( root->left != nullptr && root->right != nullptr )
 		  {
 		     // root->data = findMin( root->right )->data;
	 	      remove_Mrating( root->data, root->right );
		  }
		  else
 		  {
 		      bstrating *oldNode = root;
 		      root = ( root->left != nullptr ) ? root->left : root->right;
		      delete oldNode;
		   }
}
void bstrating::makeEmpty( bstrating*& root  )
 {
 	if( root != nullptr )
 	{
 	    makeEmpty( root->left );
	    makeEmpty( root->right );
 	    delete root;
	}
	root = nullptr; }

 void bstrating::printDailyratingdetails(bstrating* root) {
        if (root) {
            printDailyratingdetails(root->left);
        (root->data).printdilyrating();
        std::cout<<std::endl;
            printDailyratingdetails(root->right);
        }
    }
void bstrating::printMonthlyRating(bstrating* root) {
    if (root) {
        printMonthlyRating(root->getLeft());
        (root->getData()).print_RatingDates();
        std::cout << "the rating: " << (root->getData()).averagerating() << std::endl;
        printMonthlyRating(root->getRight());
    }
}
void bstrating::calculate_yearrating_helper(bstrating* root, int year, float& yrat) {
    if (root) {
        if ((root->data).get_RatingDates().second == year) {
            yrat += (root->data).averagerating();
        }
        calculate_yearrating_helper(root->left, year, yrat);
        calculate_yearrating_helper(root->right, year, yrat);
    }
}
float bstrating::ccalculate_yearrating(bstrating* root, int year) {
    float yrat = 0;
    calculate_yearrating_helper(root, year, yrat);
    return yrat / 12;
}
/*
//seethem again tomorow calculate the rating
int bstrating::get_maxrating(MounthlyRating* root) {
        // Keep traversing to the right until you reach the rightmost node
        while (root->right) {
            root = node->right;
        }
        return root->data;
    }

int bstrating::get_minrating(MounthlyRating* root) {
        // Keep traversing to the left until you reach the leftmost node
        while (root->left) {
            root = root->left;
        }
        return root->data;
    }*/
/*
/// the avl part
// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}
int height(Node *N) {
  if (N == NULL)
    return -1;
  return N->height;
}
// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}
// Utility function
int max(int a, int b){
  return (a > b) ? a : b;
}

// Insert a node
Node *insertNode(Node *node, int key) {
  // Find the correct position and insert the node
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and balance the tree
  node->height = 1 + max(height(node->left), height(node->right));
  int balanceFactor = getBalanceFactor(node);

  if (balanceFactor > 1) {
	// Left left imbalance
    if (key < node->left->key)
    return rightRotate(node);

	// Left right imbalance
    else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }

  // Right right imbalance
  if (balanceFactor < -1) {
    if (key > node->right->key)
      return leftRotate(node);

   // Right left imbalance
	else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}
Node *deleteNode(Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      }
	  else
      *root = *temp;
      free(temp);
    }

	else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and balance the tree
  root->height = 1 + max(height(root->left), height(root->right));
  int balanceFactor = getBalanceFactor(root);

  if (balanceFactor > 1) {
	// left left imbalance
    if (getBalanceFactor(root->left) >= 0)
      return rightRotate(root);

	// left right imbalance
    else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }

  // right right imbalance
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0)
      return leftRotate(root);

	// right left imbalance
    else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}
*/

template <typename Comparable>
 class BinarySearchTree
 {
   public:
 	BinarySearchTree( );
 	BinarySearchTree( const BinarySearchTree & rhs );
 	BinarySearchTree( BinarySearchTree && rhs );
 	~BinarySearchTree( );

 	const Comparable & findMin( ) const;
 	const Comparable & findMax( ) const;
 	bool contains( const Comparable & x ) const;
 	bool isEmpty( ) const;
 	void printTree( ostream & out = cout ) const;

 	void makeEmpty( );
 	void insert( const Comparable & x );
 	void insert( Comparable && x );
 	void remove( const Comparable & x );

 	BinarySearchTree & operator=( const BinarySearchTree & rhs );
 	BinarySearchTree & operator=( BinarySearchTree && rhs );

  private:
 	struct BinaryNode
 	{
 		Comparable element;
 		BinaryNode *left;
 		BinaryNode *right;

 		BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
 		   : element{ theElement }, left{ lt }, right{ rt } { }

 		BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
 		   : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
 	};

	BinaryNode *root;

 	void insert( const Comparable & x, BinaryNode * & t );
 	void insert( Comparable && x, BinaryNode * & t );
 	void remove( const Comparable & x, BinaryNode * & t );
 	BinaryNode * findMin( BinaryNode *t ) const;
 	BinaryNode * findMax( BinaryNode *t ) const;
 	bool contains( const Comparable & x, BinaryNode *t ) const;
 	void makeEmpty( BinaryNode * & t );
 	void printTree( BinaryNode *t, ostream & out ) const;
 	BinaryNode * clone( BinaryNode *t ) const;
 

//====================================================

 bool contains( const Comparable & x ) const
 {
 	return contains( x, root );
 }

 /**
10 * Method to insert x into the tree; duplicates are ignored.
11 */
 void insert( const Comparable & x )
 {
 	insert( x, root );
 }

 /**
18 * Method to remove x from the tree. Nothing is done if x is not found.
19 */
 void remove( const Comparable & x )
 {
 	remove( x, root );
2 }


//====================================================
/*
2 * Internal method Contains to test if an item is in a subtree.
3 * x is item to search for.
4 * t is the node that roots the subtree.
5 */
 bool contains( const Comparable & x, BinaryNode *t ) const
 {
 	if( t == nullptr )
 		return false;
 	else if( x < t->element )
 		return contains( x, t->left );
 	     else if( t->element < x )
 			return contains( x, t->right );
 		  else
 			return true; // Match
 }

//=====================================================
// Figure 4.19 Illustrates use of a function object to implement binary search tree
 template <typename Object, typename Comparator=less<Object>>
 class BinarySearchTree
 {
 public:

 // Same methods, with Object replacing Comparable

    private:

 	BinaryNode *root;
 	Comparator isLessThan;  // boolean function that implements the comparison of objects

 // Same methods, with Object replacing Comparable

    /**
16    * Internal method to test if an item is in a subtree.
17    * x is item to search for.
18    * t is the node that roots the subtree.
19    */
    bool contains( const Object & x, BinaryNode *t ) const
    {
 	  if( t == nullptr )
 	      return false;
 	  else if( isLessThan( x, t->element ) )
 	           return contains( x, t->left );
 	       else if( isLessThan( t->element, x ) )
 	                return contains( x, t->right );
 		  else
 	      	        return true; // Match
     }
 };

// ==============================================================
// Figure 4.20 Recursive implementation of findMin for binary search trees
 /**
2 * Internal method to find the smallest item in a subtree t.
3 * Return node containing the smallest item.
4 */


//========================================================
// Figure 4.21 Nonrecursive implementation of findMax for binary search trees
 /**
2 * Internal method to find the largest item in a subtree t.
3 * Return node containing the largest item.
4 */
 BinaryNode * findMax( BinaryNode *t ) const
 {
 	if( t != nullptr )
 	      while( t->right != nullptr )
 		  t = t->right;
 	return t;
 }

//==========================================================
// Figure 4.23 Insertion into a binary search tree
 /**
2 * Internal method to insert into a subtree.
3 * x is the item to insert.
4 * t is the node that roots the subtree.
5 * Set the new root of the subtree.
6 */
 void insert( const Comparable & x, BinaryNode * & t )
 {
 	if( t == nullptr )
 	    t = new BinaryNode{ x, nullptr, nullptr };
 	else if( x < t->element )
 	         insert( x, t->left );
 	     else if( t->element < x )
 		      insert( x, t->right );
 		  else
 			; // Duplicate; do nothing
 }

 /**
20 * Internal method to insert into a subtree.
21 * x is the item to insert by moving.
22 * t is the node that roots the subtree.
23 * Set the new root of the subtree.
24 */
 void insert( Comparable && x, BinaryNode * & t )
 {
 	if( t == nullptr )
 	    t = new BinaryNode{ std::move( x ), nullptr, nullptr };  
                 // std::move is exactly equivalent to a static_cast to an rvalue reference type
 	else if( x < t->element )
 		 insert( std::move( x ), t->left );
 	     else if( t->element < x )
 		      insert( std::move( x ), t->right );
 		  else
 			; // Duplicate; do nothing
 }

//===================================================
// Figure 4.26 Deletion routine for binary search trees
1 /**
2 * Internal method to remove from a subtree.
3 * x is the item to remove.
4 * t is the node that roots the subtree.
5 * Set the new root of the subtree.
6 */
 void remove( const Comparable & x, BinaryNode * & t )
 {
 	if( t == nullptr )
	    return; // Item not found; do nothing
 	if( x < t->element )
 	    remove( x, t->left );
 	else if( t->element < x )
 		 remove( x, t->right );
 	     else if( t->left != nullptr && t->right != nullptr ) // Two children
 		  {
 		      t->element = findMin( t->right )->element;
	 	      remove( t->element, t->right );
 		  }
		  else
 		  {
 		      BinaryNode *oldNode = t;
 		      t = ( t->left != nullptr ) ? t->left : t->right;
 		      delete oldNode;
 		   }
 }

//=========================================================
// Figure 4.27 Destructor and recursive makeEmpty member function
 /**
2 * Destructor for the tree
3 */
 ~BinarySearchTree( )
 {
 	makeEmpty( );
 }
 /**
9 * Internal method to make subtree empty.
10 */
 void makeEmpty( BinaryNode * & t )
 {
 	if( t != nullptr )
 	{
 	    makeEmpty( t->left );
	    makeEmpty( t->right );
 	    delete t;			// Note the postorder traversal. Is it logical?
	}
 	t = nullptr;
 }

//========================================================
// Figure 4.28 Copy constructor and recursive clone member function
 /**
2 * Copy constructor
3 */
 BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
 {
 	root = clone( rhs.root );
 }

 /**
10 * Internal method to clone a subtree.
11 */
 BinaryNode * clone( BinaryNode *t ) const
 {
 	if( t == nullptr )
	    return nullptr;
 	else
 	    return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
 }

//=============================================================
};
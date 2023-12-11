#include "RatingsBST.h"
#include "MonthlyRating.h"
//already have the root (head)
//get depending on a vall + r values things
ratingsBST::ratingsBST(MonthlyRating x) : data(x), left(nullptr), right(nullptr) {
}
ratingsBST::~ratingsBST()
{
    // makeEmpty(left);
    //makeEmpty(right);
}

/*ratingsBST::ratingsBST(const ratingsBST& other)
{
    //copy ctor
}

*/

void ratingsBST::insert_Mrating(MonthlyRating& x ,MonthlyRating*& root ){
    if( root == nullptr ){
	     root = new ratingsBST{x};
}else {if( x < root->data ){ insert_Mrating( x, root->left );}
        else {if( root->data < x )
		      {insert_Mrating( x, root->right );}}}
}


void ratingsBST::remove_Mrating(MonthlyRating& x ,ratingsBST*& root )
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
 		      ratingsBST *oldNode = root;
 		      root = ( root->left != nullptr ) ? root->left : root->right;
		      delete oldNode;
		   }
}
void ratingsBST::makeEmpty( ratingsBST*& root  )
 {
 	if( root != nullptr )
 	{
 	    makeEmpty( root->left );
	    makeEmpty( root->right );
 	    delete root;
	}
	root = nullptr; }

 void ratingsBST::printDailyratingdetails(ratingsBST* root) {
        if (root) {
            printDailyratingdetails(root->left);
        (root->data).printdilyrating();
        std::cout<<std::endl;
            printDailyratingdetails(root->right);
        }
    }
void ratingsBST::printMonthlyRating(ratingsBST* root) {
    if (root) {
        printMonthlyRating(root->getLeft());
        (root->getData()).print_RatingDates();
        float ratingofM = root->getmounthlyrating();
        std::cout << "the rating: " <<ratingofM << std::endl;
        printMonthlyRating(root->getRight());
    }
}
void ratingsBST::calculate_yearrating_helper(ratingsBST* root, int year, float& yrat) {
    if (root) {
        if ((root->data).get_RatingDates().second == year) {
            yrat += root->getmounthlyrating();
        }
        calculate_yearrating_helper(root->left, year, yrat);
        calculate_yearrating_helper(root->right, year, yrat);
    }
}
float ratingsBST::ccalculate_yearrating(ratingsBST* root, int year) {
    float yrat = 0;
    calculate_yearrating_helper(root, year, yrat);
    return yrat / 12;
}
float ratingsBST::getmounthlyrating() {
   mrating = data.averagerating();
return mrating;
}

float ratingsBST::get_maxrating(ratingsBST* root) {
    float maxRating = 0;
    if (root) {
        maxRating = std::max(maxRating, root->getmounthlyrating());
        float maxL = get_maxrating(root->left);
        float maxR = get_maxrating(root->right);
        float maxSubTree = std::max(maxL, maxR);
        maxRating = std::max(maxRating, maxSubTree);
    }
    return maxRating;
}
float ratingsBST::get_minrating(ratingsBST* root ){
    if (root) {
        float minRating = root->get_maxrating(root);
        minRating = std::min(minRating, root->getmounthlyrating());
        float minL = get_minrating(root->left);
        float minR = get_minrating(root->right);
        float minSubTree = std::min(minL, minR);
        minRating = std::min(minRating, minSubTree);
        return minRating;
    }else{
     return std::numeric_limits<float>::max();
    }
}
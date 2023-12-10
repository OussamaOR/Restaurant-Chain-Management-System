#include "bstrating.h"
#include "MonthRating.h"
//already have the root (head)
//get depending on a vall + r values things
bstrating::bstrating(MonthRating x) : data(x), left(nullptr), right(nullptr) {
}
bstrating::~bstrating()
{
    // makeEmpty(left);
    //makeEmpty(right);
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
        float ratingofM = root->getmounthlyrating();
        std::cout << "the rating: " <<ratingofM << std::endl;
        printMonthlyRating(root->getRight());
    }
}
void bstrating::calculate_yearrating_helper(bstrating* root, int year, float& yrat) {
    if (root) {
        if ((root->data).get_RatingDates().second == year) {
            yrat += root->getmounthlyrating();
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
float bstrating::getmounthlyrating() {
   mrating = data.averagerating();
return mrating;
}

float bstrating::get_maxrating(bstrating* root) {
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
float bstrating::get_minrating(bstrating* root ){
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
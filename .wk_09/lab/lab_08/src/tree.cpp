#include "tree.h"

template <typename T> node<T>* tree<T>::insert( node<T>* place, T inVal )
// insert new item into tree and balance the tree
// we're assuming theres only unique values being entered into the tree
// no idea what'll happen if one is place in here. most likely balance will
// break
{
    if ( place == nullptr )
    {
        place = new node<T>( inVal );
        if ( isRoot( nullptr ) ) // Tree is empty
        {
            this->root = place;
        }
        return place;
    }
    // find best place to insert into the array
    else if ( inVal < place->data )
    {
        place->left = insert( place->left, inVal );
    }
    else if ( inVal >= place->data )
    {
        place->right = insert( place->right, inVal );
    }
    return balance( place ); // balance afterwards
}

template <typename T> node<T>* tree<T>::remove( node<T>* parent, T inVal )
// only removes first case we're assuming the tree only has unique values
{
    if ( parent == nullptr )
    // base case
    {
        return parent;
    }
    if ( inVal < parent->data )
    // search left or right subtree
    {
        parent->left = remove( parent->left, inVal );
    }
    else if ( inVal > parent->data )
    {
        parent->right = remove( parent->right, inVal );
    }
    else
    {
        if ( parent->left == nullptr )
        // has only right child
        {
            node<T>* child = parent->right;
            delete parent;
            return child; // child is new parent
        }
        else if ( parent->right == nullptr )
        // has only left child
        {
            node<T>* child = parent->left;
            delete parent;
            return child; // child is new parent
        }
        else
        // has both children
        {
            T replace    = largest( parent->left )->data;
            parent->data = replace;
            parent->left = remove( parent->left, replace );
        }
    }
    return balance( parent );
}

template <typename T> node<T>* tree<T>::find( node<T>* node, T inVal )
{
    if ( node == nullptr )
    // base case
    {
        return nullptr;
    }
    if ( node->data == inVal )
    // base case
    {
        return node;
    }
    if ( inVal < node->data )
    // search left and right subtree
    {
        return find( node->left, inVal );
    }
    return find( node->right, inVal );
}

template <typename T> int tree<T>::size( node<T>* node )
{
    if ( node == nullptr )
    // base case
    {
        return 0;
    }
    // self explainetory
    return 1 + size( node->left ) + size( node->right );
}

template <typename T> node<T>** tree<T>::getAllAscending() //( int i = 0 )
{
    int i = 0;
    // casting size_t to suppress stupid  warnign
    //
    // Update - 100% a compiler setting problem
    node<T>** arr = new node<T>*[ static_cast<size_t>( this->size() ) ];
    this->getAllAscending( this->root, arr, i );
    return arr;
}

template <typename T> node<T>** tree<T>::getAllDescending() //( int i = 0 )
{
    int i = 0;
    // casting size_t to suppress stupid warnign
    //
    // Update - 100% a compiler setting problem
    //
    // If anyone actually reads this I would like an explaination as to
    // why I would ever use size_t over int and why my while strict compiler
    // settings would be freaking out over this
    node<T>** arr = new node<T>*[ static_cast<size_t>( this->size() ) ];
    this->getAllDescending( this->root, arr, i );
    return arr;
}

/* *********************************************************
 *                    START OF HELPERS
 * *********************************************************
 */

template <typename T>
void tree<T>::getAllAscending( node<T>* child, node<T>** arr, int& i )
// takes left most of each because we're assuming it's already balanced
// basically hits nullptr of the next lowest possible value and appends
// the array.. same thing with descending
{
    if ( child == nullptr )
    {
        return;
    }
    getAllAscending( child->left, arr, i );
    arr[ i++ ] = child;
    getAllAscending( child->right, arr, i );
}

template <typename T>
void tree<T>::getAllDescending( node<T>* child, node<T>** arr, int& i )
{
    if ( child == nullptr )
    {
        return;
    }
    getAllDescending( child->right, arr, i );
    arr[ i++ ] = child;
    getAllDescending( child->left, arr, i );
}

template <typename T> int tree<T>::height( node<T>* child )
{
    if ( child == nullptr )
    // base case
    {
        return 0;
    }

    // go to next child until you reachnullptr
    // return 0 leftHeight = 0, same for right height
    // for both (rightHeight + 1) because children of
    // leftHeight have children on the right
    int leftHeight  = height( child->left );
    int rightHeight = height( child->right );

    if ( leftHeight > rightHeight )
    {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

template <typename T> int tree<T>::balanceFactor( node<T>* parent )
// redundant but required
{
    return height( parent->left ) - height( parent->right );
}

template <typename T> node<T>* tree<T>::balance( node<T>* parent )
{
    if ( parent == nullptr )
    // base case
    {
        return nullptr;
    }

    if ( balanceFactor( parent ) > 1 ) // left skew
    // value balancing if left skewed
    {
        if ( height( parent->left->left ) > height( parent->left->right ) )
        {
            return rotateRight( parent );
        }
        else
        {
            return rotateLeftRight( parent );
        }
    }
    else if ( balanceFactor( parent ) < -1 ) // right skew
    // value balancing if right skewed
    {
        if ( height( parent->right->right ) > height( parent->right->left ) )
        {
            return rotateLeft( parent );
        }
        else
        {
            return rotateRightLeft( parent );
        }
    }

    return parent;
}

template <typename T> bool tree<T>::isRoot( node<T>* node )
// for sanity
{
    return this->root == node;
}

/////////////////////////////////////////////// Rotations
template <typename T> node<T>* tree<T>::rotateLeft( node<T>* parent )
{
    if ( parent == nullptr || parent->right == nullptr )
    {
        return parent;
    }
    node<T>* temp = parent->right;
    parent->right = temp->left;
    temp->left    = parent;

    if ( isRoot( parent ) )
    {
        this->root = temp;
    }
    return temp;
}

template <typename T> node<T>* tree<T>::rotateRight( node<T>* parent )
{
    if ( parent == nullptr || parent->left == nullptr )
    {
        return parent;
    }
    node<T>* temp = parent->left;
    parent->left  = temp->right;
    temp->right   = parent;

    if ( isRoot( parent ) )
    {
        this->root = temp;
    }
    return temp;
}

template <typename T> node<T>* tree<T>::rotateRightLeft( node<T>* parent )
{
    if ( parent == nullptr || parent->right == nullptr )
    {
        return parent;
    }
    parent->right = rotateRight( parent->right );
    return rotateLeft( parent );
}

template <typename T> node<T>* tree<T>::rotateLeftRight( node<T>* parent )
{
    if ( parent == nullptr || parent->left == nullptr )
    {
        return parent;
    }
    parent->left = rotateLeft( parent->left );
    return rotateRight( parent );
}

template <typename T> node<T>* tree<T>::lowest( node<T>* parent )
{
    if ( parent->left != nullptr )
    {
        parent = lowest( parent->left );
    }
    return parent;
}

template <typename T> node<T>* tree<T>::largest( node<T>* parent )
{
    if ( parent->right != nullptr )
    {
        parent = largest( parent->right );
    }
    return parent;
}


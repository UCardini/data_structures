#include <iostream>

template <typename T> class node
{
public:
    T data;
    node* left;
    node* right;

    node( T data )
    { //
        this->data = data;
    };
};

template <typename T> class tree
{
public:
    node<T>* root; // Should be ptr?

    tree() { root = nullptr; };

    // THis needs to be fucking recusive?!
    // How should I do this exactly
    //
    //          x
    //      y       z
    void insert( T inVal )
    {
        node<T>* temp = root;
        if ( root == nullptr )
        {
            root = new node( inVal );
        }
        else
        {
            while ( ( inVal < temp->data && temp->left != nullptr ) ||
                    ( inVal >= temp->data && temp->right != nullptr ) )
            {
                if ( inVal < temp->data )
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }

            if ( inVal < temp->data )
            {
                temp->left = new node( inVal );
            }
            else
            {
                temp->right = new node( inVal );
            }
        }
    };

    void print() { print( this->root ); };

    bool find( T inVal ) { return find( this->root, inVal ); };

private:
    bool find( node<T>* place, T inVal )
    {
        if ( place == nullptr )
        {
            return false;
        }
        if ( place->data == inVal )
        {
            return true;
        }
        if ( find( place->left, inVal ) )
        {
            return true;
        }
        return find( place->right, inVal );
    };

    void print( node<T>* place ) //
    {
        if ( place == nullptr )
        {
            return;
        }
        std::cout << place->data << std::endl << "(";
        if ( place->left == nullptr )
        {
            std::cout << "_";
        }
        else
        {
            std::cout << place->left->data;
        }
        std::cout << ", ";
        if ( place->right == nullptr )
        {
            std::cout << "_";
        }
        else
        {
            std::cout << place->right->data;
        }
        std::cout << ")";
        std::cout << std::endl;
        print( place->left );
        print( place->right );
    };

public:
    T* remove( T inVal )
    {
        if ( find( root, inVal ) )
        {
            return nullptr;
        }
        node<T>* temp = root;
        while ( ( temp->data > inVal && temp->left->data != inVal ) ||
                ( temp->data <= inVal && temp->right->data != inVal ) )
        {
            if ( temp->data > inVal && temp->left->left == nullptr &&
                 temp->left->right == nullptr )
            {
                // remove Left child, leaf
            }
            else if ( temp->data <= inVal && temp->right->left == nullptr &&
                      temp->right->right )
            {
                // remove right child, leaf
            }
            else if ( temp->data > inVal && ( temp->left->left == nullptr ||
                                              temp->left->right == nullptr ) )
            {
                T outVal = temp->left->data;
                node<T>* child;
                if ( temp->left->left == nullptr )
                {
                    child = temp->left->right;
                    delete temp->left;
                    temp->left = child;
                    return &outVal;
                }
                else
                {
                    child = temp->left->left;
                    delete temp->left;
                    temp->left = child;
                    return &outVal;
                }
            }
            else if ( temp->data > inVal && ( temp->right->left == nullptr ||
                                              temp->right->right == nullptr ) )
            {
                T outVal = temp->right->data;
                node<T>* child;
                if ( temp->right->left == nullptr )
                {
                    child = temp->right->right;
                    delete temp->right;
                    temp->right = child;
                    return &outVal;
                }
                else
                {
                    child = temp->right->left;
                    delete temp->right;
                    temp->right = child;
                    return &outVal;
                }
            }
            else if ( temp->data > inVal )
            {
                // 2 children, parent on right
                T replace = leftLargest( temp->left );
                remove( replace ); // recursive?!?!?
                T outVal         = temp->left->data;
                temp->left->data = replace;
                return &outVal;
            }
            else
            {
                // 2 children, parent on left
                T replace = leftLargest( temp->right );
                remove( replace ); // recursive?!?!?
                T outVal          = temp->right->data;
                temp->right->data = replace;
                return &outVal;
            }
        };
    };

private:
    T leftLargest( node<T>* parent ) // finds the closest value less than value
                                     // we're removing to replace it
    {
        node<T>* temp = parent->left;
        while ( temp->right != nullptr )
        {
            temp = temp->right;
        }
        return temp->data;
    };

    // could be written to find the height of a given child instead of head node
    // in main
    //
    //                            A
    //                          B   C
    //          Right now we call height(A) in main
    //          we could write height(B), height(C) to return
    //          the height for those given sides for balancing

    int height( node<T>* child )
    {
        if ( child == NULL )
        {
            return 0;
        }
        int leftCount  = height( child->left );
        int rightCount = height( child->right );

        if ( leftCount > rightCount )
        {
            return leftCount + 1;
        }
        return rightCount + 1;
    }

public:
    int levels() { return levels( this->root, NULL); };

    //int levels( node<T>* child ) { return levels( child, NULL ); };

    int levels( node<T>* child, node<T>* parent )
    {
        // add to the add and remove functions to balance unbalanced tree
        if ( child == NULL )
        {
            return 0;
        }
        int leftCount  = levels( child->left, child );  // child is new parent
        int rightCount = levels( child->right, child ); // child is new parent
        if ( leftCount - rightCount > 1 )
        {
            parent = child->left;
            if ( child->left != NULL &&
                 levels( child->left->left, child->left ) >
                     levels( child->left->right, child->left ) )
            {
                rotateRight( child, parent );
            }
            else
            {
                rotateLeftRight( child, parent );
            }
        }
        else if ( rightCount - leftCount > 1 )
        {
            parent = child->right;
            if ( child->right != NULL &&
                 levels( child->right->left, child->right ) >
                     levels( child->right->right, child->right ) )
            {
                rotateLeft( child, parent );
            }
            else
            {
                rotateRightLeft( child, parent );
            }
        }

        if ( leftCount > rightCount )
        {
            return leftCount + 1;
        }
        return rightCount + 1;
    }

    void rotateLeft( node<T>* parent, node<T>* child )
    {
        if (child == nullptr || child->right == nullptr) return;
        if ( root == child )
        { // child is root
            this->root       = child->right;
            child->right     = this->root->left;
            this->root->left = child;
        }
        else if ( parent->right == child )
        {
            parent->right       = child->right;
            child->right        = parent->right->left;
            parent->right->left = child;
        }
        else
        {
            parent->left       = child->right;
            child->right       = parent->left->left;
            parent->left->left = child;
        }
    }

    void rotateRight( node<T>* parent, node<T>* child )
    {
        if (child == nullptr || child->left == nullptr) return;
        if ( root == child )
        { // child is root
            this->root        = child->left;
            child->left       = this->root->right;
            this->root->right = child;
        }
        else if ( parent->right == child )
        {
            parent->right        = child->left;
            child->left          = parent->right->right;
            parent->right->right = child;
        }
        else
        {
            parent->left        = child->left;
            child->left         = parent->left->right;
            parent->left->right = child;
        }
    }

    void rotateRightLeft( node<T>* parent, node<T>* child )
    {
        if (child == nullptr || child->right == nullptr || child->right->left == nullptr) return;
        if ( root == child ) // root case
        {
            this->root         = child->right->left;
            child->right->left = this->root->right;
            this->root->right  = child->right;
            child->right       = this->root->left;
            this->root->left   = child;
        }
        else if ( parent->right == child )
        {
            parent->right        = child->right->left;
            child->right->left   = parent->right->right;
            parent->right->right = child->right;
            child->right         = parent->right->left;
            parent->right->left  = child;
        }
        else // parent->left == child
        {
            parent->left        = child->right->left;
            child->right->left  = parent->left->right;
            parent->left->right = child->right;
            child->right        = parent->left->left;
            parent->left->left  = child;
        }
    }

    void rotateLeftRight( node<T>* parent, node<T>* child )
    {
        if (child == nullptr || child->left == nullptr || child->left->right == nullptr) return;
        if ( root == child ) // root case
        {
            this->root         = child->left->right;
            child->left->right = this->root->left;
            this->root->left   = child->left;
            child->left        = this->root->right;
            this->root->right  = child;
        }
        else if ( parent->right == child )
        {
            parent->right        = child->left->right;
            child->left->right   = parent->right->left;
            parent->right->left  = child->left;
            child->left          = parent->right->right;
            parent->right->right = child;
        }
        else // parent->left == child
        {
            parent->left        = child->left->right;
            child->left->right  = parent->left->left;
            parent->left->left  = child->left;
            child->left         = parent->left->right;
            parent->left->right = child;
        }
    }

    int height() { return height( this->root ); };

    int size();
    node<T> getAllAscending();
    node<T> getAllDescending();
    void emptyTree();
};

int main()
{
    tree<int> myTree;
    myTree.insert(75);
    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(25);
    myTree.insert(20);
    myTree.insert(15);
    myTree.insert(12);
    myTree.insert(10);
    myTree.insert(5);

    // myTree.insert( 10 );
    // myTree.insert( 3 );
    // myTree.insert( 17 );
    // myTree.insert( 15 );
    // myTree.insert( 20 );
    // myTree.insert( 19 );
    // myTree.insert( 15 );
    // myTree.insert( 16 );
    // myTree.insert( 18 );
    // myTree.insert( 4 );
    // myTree.insert( 2 );
    // myTree.insert( 1 );
    // myTree.insert( 3 );
    // myTree.insert( 6 );
    // myTree.insert( 5 );
    // myTree.insert( 6 );
    // myTree.insert( 4 );
    // myTree.insert( 0 );

    if ( myTree.find( 95 ) )
    {
        std::cout << "works!";
    }
    // myTree.remove( 6 );
    // oooooooi
    // myTree.remove(4);
    myTree.print();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << myTree.height() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    myTree.levels();

    std::cout << std::endl;
    std::cout << std::endl;
    myTree.print();
    return 0;
}

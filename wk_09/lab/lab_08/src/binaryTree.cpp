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
private:
    node<T>* root; // Should be ptr?

public:
    tree() { root = nullptr; };
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
                    ( inVal < temp->data && temp->left != nullptr ) )
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

    void print() { print( root ); };

private:
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
    T remove( T inVal )
    { // check if in tree first by calling find
        // if it exists then there wont be an error
        // find( inVal ); creating find function inside of remove for the
        // example
        // check if in Tree
        node<T>* temp = root;
        // if ( root->data == inVal )
        // {
        //     if is leaf, root==null
        //     if is 1 child, root = child
        //     if is 2 child, root =left largest
        // }
        while ( temp->data > inVal && temp->data->left != inVal ||
                temp->data <= inVal && temp->data->right != inVal )
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
                    return outVal;
                }
                else
                {
                    child = temp->left->left;
                    delete temp->left;
                    temp->left = child;
                    return outVal;
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
                    return outVal;
                }
                else
                {
                    child = temp->right->left;
                    delete temp->right;
                    temp->right = child;
                    return outVal;
                }
            }
            else if ( temp->data > inVal )
            {
                // 2 children, parent on right
                T replace = leftLargest( temp->left );
                remove( replace ); // recursive?!?!?
                T outVal         = temp->left->data;
                temp->left->data = replace;
                return outVal;
            }
            else
            {
                // 2 children, parent on left
                T replace = leftLargest( temp->right );
                remove( replace ); // recursive?!?!?
                T outVal          = temp->right->data;
                temp->right->data = replace;
                return outVal;
            }

            // if ( inVal < temp->data ) // leaf
            // {
            //     temp = temp->left;
            // }
            // else
            // {
            //     temp = temp->right;
            // } // We found the parent of the node we
            // // want to remove
            // if ( inVal < temp->data ) // leaf
            // {
            //     int outVal = temp->left->data;
            //     delete temp->left;
            //     temp->left = nullptr;
            //     return outVal;
            // }
            // else
            // {
            //     int outVal = temp->right->data;
            //     delete temp->right;
            //     temp->right = nullptr;
            //     return outVal;
            // }
        };
    };

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
};

int main()
{
    tree<int> myTree;

    myTree.insert( 10 );
    myTree.insert( 3 );
    myTree.insert( 17 );
    myTree.insert( 15 );
    myTree.insert( 20 );
    myTree.insert( 19 );
    myTree.insert( 15 );
    myTree.insert( 16 );
    myTree.insert( 18 );
    myTree.insert( 4 );
    myTree.insert( 2 );
    myTree.insert( 1 );
    myTree.insert( 3 );
    myTree.insert( 6 );
    myTree.insert( 5 );
    myTree.insert( 0 );

    myTree.print();
    std::cout << std::endl;
    return 0;
}

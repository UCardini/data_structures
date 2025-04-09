#ifndef NODE_H
#define NODE_H

template <typename T> class node
{
public:
    T data;
    node* left;
    node* right;

    // member initializer list? wont let me write it normally
    // keeps saying that i have to make a default constructor or something
    // for wordCounts which i tried, didn't work
    // idk what this constructor does differently
    //
    // [Update]... Could be compiler settings, dont care enough to check
    node( T data ) : data( data ), left( nullptr ), right( nullptr ) {};

    ~node()
    {
        delete left;
        // std::cout << this->data << " ";
        delete right;
    }

};

#endif // !NODE_H

#pragma once // pragma twice
#include <string>

/* Class Name: fullShelf
 * ****** Description ******
 * This Class was made to fill the requirements explicitly stated in the lab
 * prompt initially I decided to pass the item that was throwing the exception
 * over here from shelfContents so that it could be used in main when the
 * exception is caught but that got removed because guess what I had to write a
 * template and now fullShelf has to be a template if I wanna keep that
 * functionality and here we are. Oh yeah... The exception is thrown over in
 * entertainmentCollection to be caught in main. Upon catching the exception in
 * main, from where the exception is thrown it passes a message to fullShelf
 * which is then passed to main where the exception is caught.
 */
class fullShelf
{
public:
    std::string msg;

    fullShelf( std::string msg ) { this->msg = msg; };
};

/* Class Name: emptyShelf
 * ****** Description ******
 * This Class is and exception that gets passed a message from specifically the
 * shelfRemove function inside of the entertainmentCollection class. This
 * exception is used in main and when caught displays the message passed by the
 * shelfRemove function.
 */
class emptyShelf
{
public:
    std::string msg;
    emptyShelf( std::string msg ) { this->msg = msg; };
};

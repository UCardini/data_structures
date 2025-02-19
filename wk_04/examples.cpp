/*  TOPIC: Inheritance 
 *  Allows a new class to be based on an existing class.
 *  It inherits all members from the base class except for constructors and destructors
 *
 *  Example: class derivedClass: access_specifier baseClass{...}
 *  What comes first the derivedClass or the baseClass?
 *  derivedClass inherits the baseClass!
 *
 *  when a derivedClass inherits a baseClass it inherits everything from the 
 *  base class but cannot access the private members from the base class.
 *
 *  Constructors are called from the baseClass to the derivedClass!
 *  Destructors are called from the derivedClass to the baseClass!
 *
 *  You can pass arguments from the derived class tot he base class constructors.
 *
 *  class animal
 *  {
 *    public:
 *      string name;
 *    private:
 *      string hidingSpot;
 *    protected:
 *      string foodBowl;
 *  }
 *  class dog:access_specifier animal{...} // access_specifier can be public private or protected
 *
 *  the access specifier can increase the security but not decrease it.
 *
 *  You can pass arguments from the derived class tot he base class constructors.
 *  Example: className::className(parameterList):BaseClassName(ArgList);
 *  Note - If the base class construcor has a construcor with parameters but no 
 *  constructor without parameters, you must call the constructor and pass the appropriate parameters.
 *
 *  Redefining a class can overload a base class function.
 *    Example:
 *      class Base 
 *        {
 *          public:
 *            int a;
 *            int GetA(){return a;}
 *            void SetA(int val){a=val;}
 *        };
 *      class derived: public Base
 *        {
 *          public:
 *            int b;
 *            int GetA(){return b;};
 *            void SetA(int val)
 *            {
 *              b=val;
 *              base:SetA(val);
 *            }
 *        };
 *
 *        Base b;
 *        Derived d;
 *        std::cout<<b.GetA(); // calls Base GetA
 *        std::cout<<d.GetA(); // calls Derived GetA
 *
 *        Base *bp = new Derived; // base pointer thats pointing at an instance of a derived class
 *
 *        cout<<bp->GetA(); // calls Base GetA
 *
 *        If you want the derived class version of a function to be called no matter what, 
 *        you need to make it in the base class. In the base class you add the keyword virtual.
 *
 *      class Base 
 *        {
 *          public:
 *            int a;
 *            virtual int GetA(){return a;}
 *            virtual void SetA(int val){a=val;}
 *        };
 *
 *        With the keyword virtual and override in the derived class, it uses dynamic binding 
 *        Base *bp = new Derived;  
 *        cout<<bp->GetA(); // calls Derived GetA
 *
 *        There is a keyword "final". What final does is it tells the derived class it 
 *        isn't allowed to override the base class version. They can still hide the base class version.
 *
 */
///////////////////////////////////////////////////////////////////////////////
/*  TOPIC: Polymorphism - many forms
 *  When a class inherits from another class. This allows an object to reference or object
 *  pointer...
 */
int main()
{

  return 0;
}

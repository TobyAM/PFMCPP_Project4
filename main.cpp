/*
Project 4: Part 5 / 9
 video: Chapter 5 Part 2
 Operator Overloading.

Do not delete your previous main. 

 Create a branch named Part5

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) replace the add/subtract/multiply/etc functions in your UDTs with overloaded math operators 
        e.g. add() would become operator+=() because it modifies the internal heap-allocated object.
        The easiest way to do this is to just rename your member functions.  
        Do not: delete your member functions and add new ones.  Simply rename them
        You do not need to change the Point class's multiply() functions.
 
 2) Your overloaded operators should only take primitives, passed by value.
    since they are passed by value, they do not need to be const.
 
 3) don't delete your conversion functions.
 
 4) your main() function should be the same as Project 4 part 4, 
    excluding the changes made due to 1)
     
 5) delete the example below after it makes sense how your code will change due to 1).
 */

#include <iostream>
namespace Example
{
    int main()
    {
        FloatType floatNum(4.3f);
        IntType intNum(2);
        IntType intNum2(6);

        /* 
        if you previously had a line like this demonstrating chaining:
            
            intNum.add(3).add(4.5f).divide(floatNum); 

        it should become:
        */
        intNum += 3;
        intNum += 4.5f;
        intNum /= floatNum;
        std::cout << "intNum: " << intNum << std::endl;
        
        return 0;
    }
}

 /*
 6) compile/link/run to make sure you don't have any errors or warnings.

 7) your program should produce the exact same output as Project 4 part 4, listed below.
    use https://www.diffchecker.com/diff to make sure it is the same.
 */

/*
your program should generate the following output EXACTLY.
This includes any warnings included below.  

The output should have zero warnings.


FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
Power tests with FloatType 
pow(ft1, floatExp) = 2^2 = 4
pow(ft1, itExp) = 4^2 = 16
pow(ft1, ftExp) = 16^2 = 256
pow(ft1, dtExp) = 256^2 = 65536
---------------------

Power tests with DoubleType 
pow(dt1, doubleExp) = 2^2 = 4
pow(dt1, itExp) = 4^2 = 16
pow(dt1, ftExp) = 16^2 = 256
pow(dt1, dtExp) = 256^2 = 65536
---------------------

Power tests with IntType 
pow(it1, intExp) = 2^2 = 4
pow(it1, itExp) = 4^2 = 16
pow(it1, ftExp) = 16^2 = 256
pow(it1, dtExp) = 256^2 = 65536
===============================

Point tests with float argument:
Point { x: 3, y: 6 }
Multiplication factor: 6
Point { x: 18, y: 36 }
---------------------

Point tests with FloatType argument:
Point { x: 3, y: 3 }
Multiplication factor: 3
Point { x: 9, y: 9 }
---------------------

Point tests with DoubleType argument:
Point { x: 3, y: 4 }
Multiplication factor: 4
Point { x: 12, y: 16 }
---------------------

Point tests with IntType argument:
Point { x: 3, y: 4 }
Multiplication factor: 5
Point { x: 15, y: 20 }
---------------------

good to go!

Use a service like https://www.diffchecker.com/diff to compare your output. 
*/


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
#include <string>
#include <cmath>

struct IntType;
struct FloatType;
struct DoubleType;

struct FloatType
{
    explicit FloatType(float f) : value(new float(f)) { }

    ~FloatType()
    {
        delete value;
        value = nullptr;
    }

    FloatType& add( float rhs );
    FloatType& subtract( float rhs );
    FloatType& multiply( float rhs );
    FloatType& divide( float rhs);
    operator float() const { return *value; }
    FloatType& pow(const FloatType&);
    FloatType& pow(const DoubleType&);
    FloatType& pow(const IntType&);
    FloatType& pow(float rhs);

private:
    float* value = nullptr;
    FloatType& powInternal(const float exp);
};

struct DoubleType
{
    explicit DoubleType(double d) : value(new double(d)) {}

    ~DoubleType()
    {
        delete value;
        value = nullptr;
    }

    DoubleType& add( double rhs );
    DoubleType& subtract( double rhs );
    DoubleType& multiply( double rhs );
    DoubleType& divide(double rhs);
    operator double() const {return *value;}
    DoubleType& pow(const FloatType&);
    DoubleType& pow(const DoubleType&);
    DoubleType& pow(const IntType&); 
    DoubleType& pow(double rhs);

private:
    double* value = nullptr;
    DoubleType& powInternal(const double exp);
        
};

struct IntType
{
    explicit IntType(int i) : value(new int(i)) {}
    
    ~IntType()
    {
        delete value;
        value = nullptr;
    }

    IntType& add( int rhs );
    IntType& subtract( int rhs );
    IntType& multiply( int rhs );
    IntType& divide( int rhs );
    operator int() const {return *value;}
    IntType& pow(const FloatType&);
    IntType& pow(const DoubleType&);
    IntType& pow(const IntType&);
    IntType& pow(int rhs);

private:
    int* value = nullptr;
    IntType& powInternal(const int exp);
};

FloatType& FloatType::add( float rhs )
{
    *value += rhs;
    return *this;   
}

FloatType& FloatType::subtract( float rhs )
{
    *value -= rhs;
    return *this;
}

FloatType& FloatType::multiply( float rhs )
{
    *value *= rhs;
    return *this;
}

FloatType& FloatType::divide( float rhs)
{
    if( rhs == 0.f )
        std::cout << "warning: floating point division by zero!\n";
    *value /= rhs;
    return *this;
}

FloatType& FloatType::pow(const FloatType& argType)
{    
    return powInternal(static_cast<float>(argType));
}

FloatType& FloatType::pow(const DoubleType& argType)
{    
    return powInternal(static_cast<float>(argType));
}

FloatType& FloatType::pow(const IntType& argType)
{    
    return powInternal(static_cast<float>(argType));
}

FloatType& FloatType::pow( float rhs)
{    
    return powInternal(rhs);
}

FloatType& FloatType::powInternal(const float arg)
{
    *value = std::pow( *value, arg );
    return *this;
}


DoubleType& DoubleType::add( double rhs )
{
    *value += rhs;
    return *this;
}

DoubleType& DoubleType::subtract( double rhs )
{
    *value -= rhs;
    return *this;
}

DoubleType& DoubleType::multiply( double rhs )
{
    *value *= rhs;
    return *this;
}

DoubleType& DoubleType::divide(double rhs)
{
    if( rhs == 0.0 )
        std::cout << "warning: floating point division by zero!\n";
    *value /= rhs;

    return *this;
}

DoubleType& DoubleType::pow( double rhs)
{    
    return powInternal(rhs);
}

DoubleType& DoubleType::pow(const FloatType& argType)
{    
    return powInternal(static_cast<double>(argType));
}

DoubleType& DoubleType::pow(const DoubleType& argType)
{    
    return powInternal(static_cast<double>(argType));
}

DoubleType& DoubleType::pow(const IntType& argType)
{    
    return powInternal(static_cast<double>(argType));
}

DoubleType& DoubleType::powInternal(const double arg)
{
    *value = std::pow( *value, arg );
    return *this;
}

IntType& IntType::add( int rhs )
{
    *value += rhs;
    return *this;
}

IntType& IntType::subtract( int rhs )
{
    *value -= rhs;
    return *this;
}

IntType& IntType::multiply( int rhs )
{   
    *value *= rhs;
    return *this;
}

IntType& IntType::divide( int rhs )
{
    if( rhs == 0 )
    {
        std::cout << "error: integer division by zero is an error and will crash the program!\n";
        return *this;
    }
    *value /= rhs;
    return *this;
}

IntType& IntType::pow( int rhs)
{    
    return powInternal(rhs);
}

IntType& IntType::pow(const FloatType& argType)
{    
    return powInternal(static_cast<int>(argType));
}

IntType& IntType::pow(const DoubleType& argType)
{    
    return powInternal(static_cast<int>(argType));
}

IntType& IntType::pow(const IntType& argType)
{    
    return powInternal(static_cast<int>(argType));
}

IntType& IntType::powInternal(const int arg)
{
    *value = static_cast<int>(std::pow( *value, arg ));
    return *this;
}

struct Point
{
    Point(float a, float b) : x(a), y(b) {}

    Point(const FloatType& a, const FloatType& b) : Point((static_cast<float>(a)), (static_cast<float>(b))) {}
    Point(const IntType& a, const IntType& b) : Point((static_cast<float>(a)), (static_cast<float>(b))) {}
    Point(const DoubleType& a, const DoubleType& b) : Point((static_cast<float>(a)), (static_cast<float>(b))) {}

    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    Point& multiply(const FloatType& m)
    {
        return multiply(static_cast<float>(m));
    }

    Point& multiply(const DoubleType& m)
    {
        return multiply(static_cast<float>(m));
    }

    Point& multiply(const IntType& m)
    {
        return multiply(static_cast<float>(m));
    }

    void toString() {std::cout << "Point { x: " << x << ", y: " << y << " }\n";}

private:
    float x{0}, y{0};
};

struct A {};
struct HeapA
{ 
    HeapA() : a(new A) {}
    ~HeapA()
    {
        delete a;
    }
    A* a = nullptr;
};

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^4 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( static_cast<int>(pi) ).multiply( static_cast<int>(dt) ).subtract( static_cast<int>(ft) ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( static_cast<int>(ft) ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( static_cast<int>(dt) ).add( static_cast<int>(ft) ).multiply( 24 ) << std::endl;
}

void part4()
{
    // ------------------------------------------------------------
    //                          Power tests
    // ------------------------------------------------------------
    FloatType ft1(2);
    DoubleType dt1(2);
    IntType it1(2);    
    float floatExp = 2.0f;
    double doubleExp = 2.0;
    int intExp = 2;
    IntType itExp(2);
    FloatType ftExp(2.0f);
    DoubleType dtExp(2.0);
    
    // Power tests with FloatType
    std::cout << "Power tests with FloatType " << std::endl;
    std::cout << "pow(ft1, floatExp) = " << ft1 << "^" << floatExp << " = " << ft1.pow(floatExp)  << std::endl;
    std::cout << "pow(ft1, itExp) = " << ft1 << "^" << itExp << " = " << ft1.pow(itExp)  << std::endl;
    std::cout << "pow(ft1, ftExp) = " << ft1 << "^" << ftExp << " = " << ft1.pow(ftExp)  << std::endl;    
    std::cout << "pow(ft1, dtExp) = " << ft1 << "^" << dtExp << " = " << ft1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;  

    // Power tests with DoubleType
    std::cout << "Power tests with DoubleType " << std::endl;
    std::cout << "pow(dt1, doubleExp) = " << dt1 << "^" << doubleExp << " = " << dt1.pow(intExp)  << std::endl;
    std::cout << "pow(dt1, itExp) = " << dt1 << "^" << itExp << " = " << dt1.pow(itExp)  << std::endl;
    std::cout << "pow(dt1, ftExp) = " << dt1 << "^" << ftExp << " = " << dt1.pow(ftExp)  << std::endl;    
    std::cout << "pow(dt1, dtExp) = " << dt1 << "^" << dtExp << " = " << dt1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;    

    // Power tests with IntType
    std::cout << "Power tests with IntType " << std::endl;
    std::cout << "pow(it1, intExp) = " << it1 << "^" << intExp << " = " << it1.pow(intExp)  << std::endl;
    std::cout << "pow(it1, itExp) = " << it1 << "^" << itExp << " = " << it1.pow(itExp)  << std::endl;
    std::cout << "pow(it1, ftExp) = " << it1 << "^" << ftExp << " = " << it1.pow(ftExp)  << std::endl;    
    std::cout << "pow(it1, dtExp) = " << it1 << "^" << dtExp << " = " << it1.pow(dtExp)  << std::endl;    
    std::cout << "===============================\n" << std::endl; 

    // ------------------------------------------------------------
    //                          Point tests
    // ------------------------------------------------------------
    FloatType ft2(3.0f);
    DoubleType dt2(4.0);
    IntType it2(5);
    float floatMul = 6.0f;

    // Point tests with float
    std::cout << "Point tests with float argument:" << std::endl;
    Point p0(ft2, floatMul);
    p0.toString();   
    std::cout << "Multiplication factor: " << floatMul << std::endl;
    p0.multiply(floatMul); 
    p0.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with FloatType
    std::cout << "Point tests with FloatType argument:" << std::endl;
    Point p1(ft2, ft2);
    p1.toString();   
    std::cout << "Multiplication factor: " << ft2 << std::endl;
    p1.multiply(ft2); 
    p1.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with DoubleType
    std::cout << "Point tests with DoubleType argument:" << std::endl;
    Point p2(ft2, static_cast<float>(dt2));
    p2.toString();   
    std::cout << "Multiplication factor: " << dt2 << std::endl;
    p2.multiply(dt2); 
    p2.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with IntType
    std::cout << "Point tests with IntType argument:" << std::endl;
    Point p3(ft2, static_cast<float>(dt2));
    p3.toString();   
    std::cout << "Multiplication factor: " << it2 << std::endl;
    p3.multiply(it2); 
    p3.toString();   
    std::cout << "---------------------\n" << std::endl;
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ) << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ) << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ) << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0) << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0) << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0) << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(static_cast<double>(5.f)) << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2) << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2) << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2) << std::endl;
    std::cout << "IntType divide result=" << it.divide(3) << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)) << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f) << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt << std::endl;
    std::cout << "Initial value of it: " << it << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(static_cast<double>(5.0f)).add(static_cast<double>(ft))) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0) << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0) << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0) << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    part3();
    part4();

    std::cout << "good to go!\n";

    return 0;
}

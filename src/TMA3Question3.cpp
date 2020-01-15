//: TMA3Question3.cpp

/**
 * Title: TMA3Question3.cpp
 * Description:
 *      Operator overloading.
 * Date: November 18, 2019
 * Author: Tommy Wu
 */

/**
 * DOCUMENTATION
 * 
 * Program Purpose:
 *      1. Create a class with a int
 *      2. Overload operator + - ++ -- <<, and also a print function
 * 
 * Compile: clang++ TMA3Question3.cpp -o TMA3Question3
 * Execution : ./TMA3Question3
 */

/**
 * No test available for a fully static program.
 * 
 * The program should generate following output from stdout:
 *  normal arithmetic
 *  2 + 3 - (-5) = 10
 *  
 *  DoStuff arithmetic
 *  2 + 3 - (-5) = 10
 *   
 *  Increment d prefix and postfix: 
 *  d = 10
 *  d++ = 10
 *  d = 11
 *  ++d = 12
 *  d = 12
 *   
 *  d-- = 12
 *  d = 11
 *  --d = 10
 *  (using operator<<) d = 10 * stderr displays the calculation result.
 */


#include <iostream>
#include <string>


// TODO: implement a reversed polish parser if time permits
class DoStuff
{
private:
    int payload;

public:
    // constructors
    DoStuff() : payload(0) {}
    DoStuff(int newInteger) : payload(newInteger) {}
    DoStuff(const DoStuff &toCopy) : payload(toCopy.payload) {}

    //unary +
    const DoStuff operator+ () const 
    {
        return *this;
    }  // unary + does nothing!


    // binary +
    const DoStuff operator+(const DoStuff& rvalue) const
    {
        return DoStuff(this -> payload + rvalue.payload);
    }
    
    // binary -
    const DoStuff operator-(const DoStuff& rvalue) const
    {

        return DoStuff(this -> payload - rvalue.payload);
    }

    // const DoStuff& operator++ (DoStuff& a) is invalid in c++11!!!!
    // prefix overloaded operater++ function takes no parameters

    //prefix ++
    DoStuff& operator++ ()
    {
        ++ this ->payload;
        return *this;
    }

    //prefix --
    DoStuff& operator-- ()
    {
        -- this -> payload;
        return *this;
    }

    //postfix ++
    DoStuff operator++ (int)
    {
        DoStuff ret(*this);
        this -> payload++;
        return ret;
    }

    //postfix --
    DoStuff operator-- (int)
    {
        DoStuff ret(*this);
        this ->payload--;
        return ret;
    }

    friend std::ostream& operator<<(std::ostream& loperand, 
                                                        const DoStuff& roperand)
    {
        return loperand << std::to_string(roperand.payload);
    }

    void print(std::ostream& out)
    {
        out << std::to_string(this -> payload);
    }
};


int main()
{
    DoStuff a(2);
    DoStuff b(3);
    DoStuff c(-5);

    DoStuff d(a + b - c);

    std::cout << "normal arithmetic" << std::endl;
    std::cout << "2 + 3 - (-5) = " << 2 + 3 - (-5) << std::endl;
    std::cout << std::endl;

    std::cout << "DoStuff arithmetic" << std::endl;
    std::cout << "2 + 3 - (-5) = " ;
    d.print(std::cout);
    std::cout << std::endl << std::endl;

    // std:: cout << ++DoStuff(4) + DoStuff(5) - DoStuff(99) << std::endl;

    std::cout << "Increment d prefix and postfix: " << std::endl;
    
    std::cout << "d = ";
    d.print(std::cout);   // 10
    std::cout << std::endl;

    std::cout << "d++ = ";    
    d++.print(std::cout);  // 10
    std::cout << std::endl;
    
    std::cout << "d = ";    
    d.print(std::cout);   //  11
    std::cout << std::endl;
    
    std::cout << "++d = ";    
    (++d).print(std::cout);  // 12
    std::cout << std::endl;
    
    std::cout << "d = ";    
    d.print(std::cout);      // 12
    std::cout << std::endl;


    std::cout << std::endl;


    std::cout << "d-- = ";    
    d--.print(std::cout);  // 12
    std::cout << std::endl;
    
    std::cout << "d = ";    
    d.print(std::cout);   //  11
    std::cout << std::endl;
    
    std::cout << "--d = ";    
    (--d).print(std::cout);  // 10
    std::cout << std::endl;
    
    // d.print(std::cout);      // 10
    std::cout << "(using operator<<) d = ";    
    std::cout << d << std::endl;


    return 0;
} ///:~
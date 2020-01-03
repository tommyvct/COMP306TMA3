#include <iostream>
#include <string>


// TODO: format to submission standards
// TODO: impllement a reversed polish evaluator if time permits
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

    std::cout << "Increment d prefix and postfix: " << std::endl;
    d++.print(std::cout);  // 10
    std::cout << std::endl;
    
    d.print(std::cout);   //  11
    std::cout << std::endl;
    
    (++d).print(std::cout);  // 12
    std::cout << std::endl;
    
    d.print(std::cout);      // 12
    std::cout << std::endl;


    std::cout << std::endl;


    d--.print(std::cout);  // 12
    std::cout << std::endl;
    
    d.print(std::cout);   //  11
    std::cout << std::endl;
    
    (--d).print(std::cout);  // 10
    std::cout << std::endl;
    
    // d.print(std::cout);      // 10
    
    std::cout << d << std::endl;


    return 0;
}
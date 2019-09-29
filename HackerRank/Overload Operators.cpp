//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator + (Complex const& v1,Complex const& v2)
{
    Complex v;
    v.a = v1.a + v2.a;
    v.b = v1.b + v2.b;
    return v;
}

ostream& operator << (ostream& os,Complex const& a)
{
    os << a.a << "+i" << a.b ;
    return os;
}
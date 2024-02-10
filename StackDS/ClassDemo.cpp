#include<iostream>

using namespace std ;

class Student
{
    public :

    string name = "xyz";
    int age = 300;
    int rollno = 30 ;

    // default constructor
    Student()
    {
        name = "abcd" ;
        age = 1000 ;
        rollno = 200 ;
    }

    // parametrised constructor
    Student(string name, int age, int rollno)
    {
        // this->name = name ;
        // this->age = age ;
        // this->rollno = rollno ;
    }

    void introduceYourself()
    {
        cout << name << " is " << age << " years old." << endl ;
    }

    void sayHi(string name)
    {
        cout << this->name << " says hi to " << name << endl ;
    }
} ;

int main()
{
    Student s ;
    s.name = "Aman" ;
    s.age = 10 ;
    s.rollno = 50 ;

    s.introduceYourself() ;

    cout << (*(&s)).name << endl ;
    cout << (*(&s)).age << endl ;
    cout << (*(&s)).rollno << endl ;

    Student *ptr = &s ; 
    cout << (&s) -> name << endl ;
    cout << (&s) -> age << endl ;
    cout << (&s) -> rollno << endl ;

    cout << ptr -> name << endl ;
    cout << ptr -> age << endl ;
    cout << ptr -> rollno << endl ;

    s.sayHi("Rohit") ;

    Student *s1 = new Student() ;
    s1->name = "Mohit" ;
    s1->introduceYourself() ;

    Student s2 ;
    s2.introduceYourself() ;

    Student s3("Riya", 10, 1) ;
    s3.introduceYourself() ;

    return 0 ;
}
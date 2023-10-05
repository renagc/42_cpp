# Introduction to C++

C++ is a powerful, general-purpose programming language that builds upon the foundation of C. It allows you to write efficient and high-performance code while also supporting object-oriented programming principles.


## C00
### Namespaces

Namespaces are used to prevent naming conflicts in C++. They provide a way to organize code into distinct containers. A common use case is to avoid naming clashes between different libraries or your own code. Here's an example:

```cpp
#include <iostream>

namespace A {
    int value = 5;
}

namespace B {
    int value = 10;
}

int main() {
    std::cout << A::value << std::endl;  // Outputs 5
    std::cout << B::value << std::endl;  // Outputs 10
    return 0;
}
```

### Stdio Streams

C++ provides a rich library of input and output stream classes for reading and writing data. `iostream` is one such library, allowing you to work with standard input and output. Here's a basic example:

```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;
    return 0;
}
```

### Class and Instance

In C++, classes are used to create user-defined data types. An instance (or object) is a specific variable of a class type. Here's a simple class definition and object creation:

```cpp
class Person {
public:
    std::string name;
    int age;
};

int main() {
    Person person1;
    person1.name = "Alice";
    person1.age = 25;

    std::cout << "Name: " << person1.name << ", Age: " << person1.age << std::endl;
    return 0;
}
```

### Member Attributes and Member Functions

Member attributes are variables within a class, and member functions are functions defined within a class that can operate on these attributes. Here's an example:

```cpp
class Rectangle {
public:
    int length;
    int width;

    int calculateArea() {
        return length * width;
    }
};

int main() {
    Rectangle rect;
    rect.length = 5;
    rect.width = 3;
    int area = rect.calculateArea();
    std::cout << "Area of the rectangle: " << area << std::endl;
    return 0;
}
```

### `this` Keyword

The `this` keyword refers to the current object within a member function of a class. It is often used to disambiguate between member attributes and local variables with the same name:

```cpp
class MyClass {
public:
    int value;

    void setValue(int value) {
        this->value = value; // 'this' refers to the object's attribute
    }
};

int main() {
    MyClass obj;
    obj.setValue(42);
    std::cout << "Value: " << obj.value << std::endl;
    return 0;
}
```

These are the first few topics from Module00. If you'd like to learn about any specific topic in more detail or have further questions, please let me know, and I'll continue explaining the next topics for you.

Certainly! Let's continue with the explanation of the remaining topics from Module00 of C++:

### Initialization List

Initialization lists are used in constructors to initialize member attributes of a class. They can help improve performance and are especially useful for initializing non-static `const` members and reference members. Here's an example:

```cpp
class MyClass {
public:
    int x;
    int y;

    MyClass(int a, int b) : x(a), y(b) {
        // Initialization list initializes x and y
    }
};

int main() {
    MyClass obj(10, 20);
    return 0;
}
```

### Const

The `const` keyword is used to declare constants and also to specify that a variable or member function should not modify an object. It's commonly used with member functions to indicate that they won't modify the object's state:

```cpp
class Circle {
public:
    const double PI = 3.14159;
    
    double calculateArea() const {
        return PI * radius * radius;
    }
    
    double radius;
};

int main() {
    Circle circle;
    circle.radius = 5.0;
    double area = circle.calculateArea();
    std::cout << "Area of the circle: " << area << std::endl;
    return 0;
}
```

### Visibility (public, private, protected)

In C++, class members can have three access specifiers: `public`, `private`, and `protected`. These determine the visibility and accessibility of members within and outside the class. 

- `public`: Members declared as public are accessible from anywhere.
- `private`: Members declared as private are only accessible from within the class.
- `protected`: Members declared as protected are accessible from within the class and derived classes.

Here's an example:

```cpp
class MyClass {
public:
    int publicVar;

private:
    int _privateVar;

protected:
    int protectedVar;
};

int main() {
    MyClass obj;
    obj.publicVar = 42; // Accessing a public member is allowed
    // obj._privateVar = 10; // This would result in a compile-time error
    // obj.protectedVar = 20; // This would also result in a compile-time error
    return 0;
}
```

### Class vs. Struct

In C++, both `class` and `struct` can be used to define user-defined data types with member attributes and member functions. The primary difference is in default member visibility: members of a `class` are private by default, while members of a `struct` are public by default.

```cpp
class MyClass {
public:
    int x;
};

struct MyStruct {
    int y;
};

int main() {
    MyClass obj1;
    obj1.x = 5;

    MyStruct obj2;
    obj2.y = 10;
    
    return 0;
}
```

### Accessors (Getters and Setters)

Accessors are member functions used to get (getters) and set (setters) the values of private member attributes. They provide controlled access to class attributes and help maintain encapsulation.

```cpp
class Rectangle {
private:
    int _length;
    int _width;

public:
    int getLength() const {
        return this->_length;
    }

    void setLength(int l) {
        this->_length = l;
    }

    int getWidth() const {
        return this->_width;
    }

    void setWidth(int w) {
        this->_width = w;
    }
};

int main() {
    Rectangle rect;
    rect.setLength(5);
    rect.setWidth(3);

    int length = rect.getLength();
    int width = rect.getWidth();

    std::cout << "Length: " << length << ", Width: " << width << std::endl;
    return 0;
}
```

### Comparisons

C++ allows you to compare objects of user-defined classes using operator overloading. You can define how the `==` and other comparison operators work for your custom types.

```cpp
class Point {
public:
    int x, y;

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
};

int main() {
    Point p1{3, 4};
    Point p2{3, 4};
    
    if (p1 == p2) {
        std::cout << "p1 and p2 are equal." << std::endl;
    } else {
        std::cout << "p1 and p2 are not equal." << std::endl;
    }
    return 0;
}
```

### Non-Member Attributes and Non-Member Functions

Non-member attributes and non-member functions are not directly associated with a class but can still be used in C++. They are typically declared outside of any class and can be accessed globally. Non-member functions are often used for utility purposes.

```cpp
// Non-member attributes
int globalVar = 42;

// Non-member function
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(10, 20);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```

### Pointers to Members

Pointers to members allow you to create pointers that can access class members, both data members and member functions. They are used less frequently but can be powerful in certain situations.

```cpp
class MyClass {
public:
    int dataMember = 42;
    void memberFunction() {
        std::cout << "Inside member function" << std::endl;
    }
};

int main() {
    MyClass obj;
    int MyClass::*ptrDataMember = &MyClass::dataMember;
    void (MyClass::*ptrMemberFunction)() = &MyClass::memberFunction;

    std::cout << obj.*ptrDataMember << std::endl;
    (obj.*ptrMemberFunction)();

    return 0;
}
```


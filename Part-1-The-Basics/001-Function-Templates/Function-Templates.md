# 1. Function Templates

This part introduces the general concepts and C++ template features offered by C++ standards such as C++11, C++14 and C++17. I will cover core concept and goals by example. Then I will cover additional template features such as nontype template parameters, variadic templates and member template etc.

## Why Template ?

C++ is strongly typed language meaning we need to declare variables, functions etc. with specific data type. It is possible that for most of applications, the specific code, kind of looks the same for different data types.

For e.g. at simplest it could be finding maximum number, adding two or more numbers. At complex scenarios it could be the implementation of sorting algorithm.

Now, you can have other options as well like using macros or may be using same functions for different data types. Using macros may lead to semantics errors. In terms of the rewriting the function again means we carry the same issues all over again for all datatypes. And in fact the behavior may get strange. Or your algorithm could be having issues which will have impact on your performance for all other datatypes.

Template allows us to write a generic code and avoid all above drawbacks. In fact, containers like vector, arrays(#include < array > ) in C++ standard library are implemented with templates.

**_Note : -_**  Templates are compile-time.



## 1.1 Function Template

It is nothing but a group or family of functions with identical behavior for other different data-types.

Template parameter must be declared as follows:

```C++
    template < list-of-parameters-comma-separated >
```

In our example its _template < typename T >_. The keyword typename creates a new parameter of type T. You can use any name instead of T. 
Now here point to note is - Prior to C++17, templates parameters such as x & y must be copyable in order to be returned. But since C++17 you can pass rvalue references even if both copy and move constructors are invalid.

``` C++
template <typename T>
T max(T x, T b){
    return ( x < y ? y : x );
}


// Both are equivalent
template <class T>
T max(T x, T b){
    return ( x < y ? y : x );
}

```

* Code Example

```C++

#include <iostream>
#include <string>

template<typename T>
T max(T x, T y) {
    return (x < y ? y : x);
}

int main()
{
    int a{}, b{};
    std::cout << "Please provide input : ";
    std::cin >> a >> b;
    std::cout << "\nThe maximum of " << a << " & " << b << " is : " << max(a, b) << std::endl;
    
    double d1{ 12.89 }, d2{98.99};
    std::cout << "\n\nThe maximum of " << d1 << " & " << d2 << " is : " << max(d1, d2) << std::endl;
    
    std::string s1 = "Vaibhav";
    std::string s2 = "Apurwa";
    std::cout << "\n\nThe maximum of " << s1 << " & " << s2 << " is : " << ::max(s1, s2) << std::endl;
}

```

So, when we compile the code, the compiler actually generates 3 or 4 or whatever definitions of function for us. Meaning for first call of max() ->int template yields a following code : 
```C++
int max(int x, int y) {
    return (x < y ? y : x);
}
```
## What is template instantiation ?

The process of replacing template parameters with concrete data-types is known as template instantiation.

## How Template gets compiled ?

Template compilation is two phase process.

**Phase 1 -** Before instantiation (i.e. at definition time), the code itself is checked for correctness. This process ignores template parameters.

* Syntax errors
* Using unknown names or unknown function calls
* Static Assertions

All above issues are checked provided that these are not dependent of template parameters.

**Phase 2 -** At instantiation time, the template code is checked again. Now all parts that depend on template parameters are checked.

```C++

template<typename T>
void myFunction(T t){
    randomFunc();   // Phase 1 error unknown function
    randomFunc(t);  // Phase 2 error as t is dependent

    // always fails if sizeof(int) <= 12
    static_assert(sizeof(int) > 12, "too small");
}

```
 
 The name two-phase because everything is looked up twice.

**_Note :-_** To avoid subtle issues, at simplest make sure to write template definitions in separate header file.

## 1.2 How Template Argument Deduction Works ?

Usually, template parameters are determined by the arguments we pass.

* Two arguments declared with the same template parameter T must match exactly.
\
e.g.

```C++

int i{20}, j{30};
max(i,j); //Correct as both parameters yields to int

max(10,72.97); //ERROR : T can be deduced as int or double.


//ERROR: In following example, T can be deduced to either const char[6] for hello or std::string for name.
std::string name {"Template"};
max("hello:, name);

```

### How to Fix this ?
* Use casting operators to make sure argument types match.
```C++
max(static_cast<double>(10), 72.97);
```
* Explicitly set the type qualifier to the function call to prevent compiler from auto deduction.

```C++
max<double>(10,72.97);
```

_**Note :-**_ Template auto type deduction doesn't work for default call arguments.

```C++
    //ERROR - Incorrect way to define a template
    template<typename T>
    void print(T = "");

    print(80); //OK: T yields to int
    print();  //ERROR: T deduction fails.

    // Correct way of implementation
    template<typename T = std::string>
    void print(T = "");
    print(80); //OK: T yields to int
    print(); //OK: T yields to std::string
```
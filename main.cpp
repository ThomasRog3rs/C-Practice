#include <iostream>     // For input/output operations
#include <string>       // For string handling
#include <vector>       // Similar to C# List<T> or JavaScript arrays
#include <map>          // Similar to C# Dictionary or JavaScript objects
#include <memory>       // For smart pointers
#include <algorithm>    // For STL algorithms
#include <functional>   // For function objects, lambdas
#include <sstream>      // For string streams
#include <iomanip>      // For io manipulators
#include <string_view>  // For efficient string views (C++17)

// Include these when using C++20 features
#if __cplusplus >= 202002L
#include <format>       // For std::format (C++20)
#endif

/*
 * Welcome to C++ from C# and JavaScript!
 * 
 * This file demonstrates key C++ concepts with examples
 * and comparisons to C# and JavaScript where applicable.
 */

// Forward declarations
void demonstrateBasicSyntax();
void demonstrateModernIO(); // New section for modern I/O
void demonstrateVariablesAndTypes();
void demonstrateControlFlow();
void demonstrateFunctions(int value);
int returnSum(int a, int b);
void demonstrateReferencesAndPointers();
void demonstrateClasses();
void demonstrateModernCpp();
void demonstrateStl();
void demonstrateErrorHandling();

// Entry point of the program
int main() {
    std::cout << "==============================" << std::endl;
    std::cout << "C++ Tutorial for C# and JS Developers" << std::endl;
    std::cout << "==============================" << std::endl;
    
    demonstrateBasicSyntax();
    demonstrateVariablesAndTypes();
    demonstrateControlFlow();
    demonstrateFunctions(42);
    std::cout << "Sum: " << returnSum(5, 7) << std::endl;
    demonstrateReferencesAndPointers();
    demonstrateClasses();
    demonstrateModernCpp();
    demonstrateStl();
    demonstrateErrorHandling();
    demonstrateModernIO(); // Added this call
    
    std::cout << "\nTutorial completed successfully!" << std::endl;
    return 0;
}

// ----- Basic Syntax -----
void demonstrateBasicSyntax() {
    std::cout << "\n----- Basic Syntax -----\n";
    
    // Comments are the same as in C# and JavaScript
    // Single line comment
    
    /*
     * Multi-line comment
     */
    
    // Statements end with semicolons (like C# and unlike JavaScript where they're optional)
    std::cout << "Hello, World!" << std::endl;
    
    // std::cout is for console output (similar to Console.WriteLine in C# or console.log in JS)
    // << is the stream insertion operator
    // std::endl inserts a newline and flushes the buffer (similar to \n but with flush)
}

// ----- Variables and Types -----
void demonstrateVariablesAndTypes() {
    std::cout << "\n----- Variables and Types -----\n";
    
    // C++ is statically typed
    // Basic types
    int integerValue = 42;                 // 32-bit integer
    double floatingPoint = 3.14159;        // Double precision floating point
    char singleCharacter = 'A';            // Single character
    bool booleanValue = true;              // Boolean (true/false)
    
    // In C++, strings are objects, not primitive types like in C#
    std::string text = "Hello, C++";       // String class 
    
    // C++ has const for constants (similar to const in C# and JavaScript)
    const int unchangeable = 100;
    
    // C++ handles Unicode differently than C# and JavaScript
    // Unicode strings often use wstring, u16string, or u32string
    std::wstring wideText = L"Wide character string";
    
    // Print variables
    std::cout << "Integer: " << integerValue << std::endl;
    std::cout << "Double: " << floatingPoint << std::endl;
    std::cout << "Char: " << singleCharacter << std::endl;
    std::cout << "Boolean: " << std::boolalpha << booleanValue << std::endl;
    std::cout << "String: " << text << std::endl;
    
    // Type conversion (more explicit than JavaScript, similar to C#)
    int x = 5;
    double y = static_cast<double>(x) / 2;  // 2.5 (not 2 because of explicit conversion)
    std::cout << "5/2 with conversion: " << y << std::endl;
    
    // Without conversion, integer division would truncate:
    std::cout << "5/2 without conversion: " << 5/2 << std::endl;
}

// ----- Control Flow -----
void demonstrateControlFlow() {
    std::cout << "\n----- Control Flow -----\n";
    
    // If statements (similar to C# and JavaScript)
    int x = 10;
    if (x > 5) {
        std::cout << "x is greater than 5" << std::endl;
    } else if (x == 5) {
        std::cout << "x is equal to 5" << std::endl;
    } else {
        std::cout << "x is less than 5" << std::endl;
    }
    
    // Switch statements (similar to C# and JavaScript)
    switch (x) {
        case 5:
            std::cout << "x is 5" << std::endl;
            break;
        case 10:
            std::cout << "x is 10" << std::endl;
            break;
        default:
            std::cout << "x is neither 5 nor 10" << std::endl;
            break;
    }
    
    // For loop (similar to C# and JavaScript)
    std::cout << "For loop: ";
    for (int i = 0; i < 5; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // Range-based for loop (similar to foreach in C# or for...of in JavaScript)
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Range-based for loop: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // While loop (similar to C# and JavaScript)
    std::cout << "While loop: ";
    int i = 0;
    while (i < 5) {
        std::cout << i << " ";
        i++;
    }
    std::cout << std::endl;
    
    // Do-while loop (similar to C# and JavaScript)
    std::cout << "Do-while loop: ";
    i = 0;
    do {
        std::cout << i << " ";
        i++;
    } while (i < 5);
    std::cout << std::endl;
}

// ----- Functions -----
// Function with a parameter (similar to C# and JavaScript)
void demonstrateFunctions(int value) {
    std::cout << "\n----- Functions -----\n";
    std::cout << "Function parameter: " << value << std::endl;
    
    // Local variable scope (similar to C# and JavaScript)
    {
        int localVar = 100;
        std::cout << "Inside local scope: " << localVar << std::endl;
    }
    // localVar is not accessible here
    
    // Default parameters (similar to C# and JavaScript)
    auto defaultParamFunction = [](int a = 1, int b = 2) {
        return a + b;
    };
    
    std::cout << "Default params (no args): " << defaultParamFunction() << std::endl;
    std::cout << "Default params (one arg): " << defaultParamFunction(10) << std::endl;
    std::cout << "Default params (two args): " << defaultParamFunction(10, 20) << std::endl;
}

// Function with return value (similar to C# and JavaScript)
int returnSum(int a, int b) {
    return a + b;
}

// ----- References and Pointers -----
void demonstrateReferencesAndPointers() {
    std::cout << "\n----- References and Pointers -----\n";
    
    // References (similar to ref parameters in C#)
    int original = 42;
    int& reference = original;  // Reference to original
    
    std::cout << "Original: " << original << std::endl;
    std::cout << "Reference: " << reference << std::endl;
    
    // Modifying through reference affects original
    reference = 100;
    std::cout << "After modifying reference, original: " << original << std::endl;
    
    // Pointers (no direct equivalent in C# or JavaScript)
    int value = 42;
    int* pointer = &value;  // Pointer to value
    
    std::cout << "Value: " << value << std::endl;
    std::cout << "Pointer address: " << pointer << std::endl;
    std::cout << "Dereferenced pointer: " << *pointer << std::endl;
    
    // Modifying through pointer affects original
    *pointer = 200;
    std::cout << "After modifying pointer, value: " << value << std::endl;
    
    // Smart pointers (Modern C++, somewhat similar to C# reference types)
    std::unique_ptr<int> smartPtr = std::make_unique<int>(42);
    std::cout << "Smart pointer value: " << *smartPtr << std::endl;
    
    // std::unique_ptr automatically deallocates memory when it goes out of scope
    // No need for manual memory management!
}

// ----- Classes and OOP -----
// Class definition (similar to C# classes, different from JavaScript classes)
class Person {
  private:
      std::string name;
      int age;
      
  public:
      // Constructor
      Person(const std::string& n, int a) : name(n), age(a) {
          std::cout << "Person created: " << name << std::endl;
      }
      
      // Destructor (called automatically when object is destroyed)
      // No equivalent in C# (handled by garbage collection) or JavaScript
      ~Person() {
          std::cout << "Person destroyed: " << name << std::endl;
      }
      
      // Member functions (methods)
      void introduce() const {
          std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
      }
      
      // Getters and setters (similar to C# properties)
      std::string getName() const { return name; }
      void setName(const std::string& n) { name = n; }
      
      int getAge() const { return age; }
      void setAge(int a) { age = a; }
};

// Inheritance example
class Employee : public Person {
  private:
      std::string company;
      
  public:
      Employee(const std::string& n, int a, const std::string& c) 
          : Person(n, a), company(c) {
          std::cout << "Employee created at " << company << std::endl;
      }
      
      // Override method
      void introduce() const {
          std::cout << "Hi, I'm " << getName() << ", " << getAge() 
                    << " years old, and I work at " << company << "." << std::endl;
      }
};

void demonstrateClasses() {
    std::cout << "\n----- Classes and OOP -----\n";
    
    // Create objects on the stack (automatically destroyed when out of scope)
    Person alice("Alice", 30);
    alice.introduce();
    
    // Create objects on the heap (manually managed in raw pointers)
    Person* bob = new Person("Bob", 25);
    bob->introduce();  // Note: -> operator for accessing members via pointer
    delete bob;        // Manual memory cleanup required
    
    // Smart pointers for better memory management
    std::shared_ptr<Person> charlie = std::make_shared<Person>("Charlie", 35);
    charlie->introduce();
    // No manual delete needed!
    
    // Inheritance
    Employee dave("Dave", 40, "Acme Inc");
    dave.introduce();  // Calls the overridden method
}

// ----- Modern C++ Features -----
void demonstrateModernCpp() {
    std::cout << "\n----- Modern C++ Features -----\n";
    
    // Auto type deduction (similar to var in C# and JavaScript)
    auto value = 42;      // int
    auto text = "hello";  // const char*
    auto pi = 3.14159;    // double
    
    std::cout << "Auto variables: " << value << ", " << text << ", " << pi << std::endl;
    
    // Lambda expressions (similar to lambdas in C# and arrow functions in JavaScript)
    auto add = [](int a, int b) { return a + b; };
    std::cout << "Lambda result: " << add(3, 4) << std::endl;
    
    // Lambda with capture
    int multiplier = 10;
    auto multiply = [multiplier](int x) { return x * multiplier; };
    std::cout << "Lambda with capture: " << multiply(5) << std::endl;
    
    // Move semantics (no direct equivalent in C# or JavaScript)
    std::string source = "Original string";
    std::string destination = std::move(source); // Efficiently transfers ownership
    
    std::cout << "After move, destination: " << destination << std::endl;
    std::cout << "After move, source: " << source << std::endl; // source may be empty
    
    // Initializer lists (similar to collection initializers in C#)
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Initializer list: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// ----- Standard Template Library (STL) -----
void demonstrateStl() {
    std::cout << "\n----- Standard Template Library -----\n";
    
    // Vectors (similar to List<T> in C# or arrays in JavaScript)
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    
    numbers.push_back(60);  // Add element to end
    numbers.pop_back();     // Remove last element
    
    std::cout << "Vector elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Maps (similar to Dictionary<K,V> in C# or objects in JavaScript)
    std::map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages["Charlie"] = 35;
    
    std::cout << "Map elements:" << std::endl;
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // STL algorithms (some similarity to LINQ in C# or array methods in JavaScript)
    std::cout << "Find 30 in vector: ";
    auto it = std::find(numbers.begin(), numbers.end(), 30);
    if (it != numbers.end()) {
        std::cout << "Found at position " << (it - numbers.begin()) << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    // Sort elements
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Transform elements (similar to .map() in JavaScript or .Select() in C# LINQ)
    std::vector<int> doubled(numbers.size());
    std::transform(numbers.begin(), numbers.end(), doubled.begin(),
                  [](int x) { return x * 2; });
    
    std::cout << "Doubled vector: ";
    for (int num : doubled) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// ----- Error Handling -----
void demonstrateErrorHandling() {
    std::cout << "\n----- Error Handling -----\n";
    
    // Try-catch blocks (similar to C# and JavaScript)
    try {
        std::cout << "Attempting division..." << std::endl;
        
        int numerator = 10;
        int denominator = 2;  // Try changing this to 0
        
        if (denominator == 0) {
            // Throw an exception (similar to C# and JavaScript)
            throw std::runtime_error("Division by zero!");
        }
        
        int result = numerator / denominator;
        std::cout << "Result: " << result << std::endl;
        
        // Using array with bounds checking
        std::vector<int> vec = {1, 2, 3};
        // This will throw std::out_of_range if i is out of bounds:
        std::cout << "vec[1]: " << vec.at(1) << std::endl; 
        
    } catch (const std::runtime_error& e) {
        // Catch specific exception type
        std::cout << "Runtime error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        // Catch out of range exceptions
        std::cout << "Out of range error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Catch all standard exceptions
        std::cout << "Standard exception: " << e.what() << std::endl;
    } catch (...) {
        // Catch all other exceptions
        std::cout << "Unknown exception occurred" << std::endl;
    }
}

// ----- Modern I/O Operations -----
void demonstrateModernIO() {
    std::cout << "\n----- Modern I/O Operations -----\n";
    
    // ===== OUTPUT METHODS =====
    std::cout << "===== Modern Output Methods =====\n";
    
    // 1. Traditional std::cout
    std::cout << "1. Traditional std::cout with concatenation" << std::endl;
    
    // 2. Using stream manipulators for formatting
    int num = 42;
    double pi = 3.14159265359;
    
    // Format with manipulators
    std::cout << "2. Formatted output with manipulators:" << std::endl;
    std::cout << "   Hex: " << std::hex << std::showbase << num << std::endl;
    std::cout << "   Decimal: " << std::dec << num << std::endl;
    std::cout << "   Fixed precision: " << std::fixed << std::setprecision(2) << pi << std::endl;
    std::cout << "   Scientific: " << std::scientific << pi << std::endl;
    // Reset formatting
    std::cout << std::defaultfloat << std::setprecision(6);
    
    // 3. Using string streams for complex formatting
    std::cout << "3. Using string streams:" << std::endl;
    std::ostringstream oss;
    oss << "String stream allows building complex strings: ";
    oss << "Value=" << num << ", Pi=" << std::fixed << std::setprecision(2) << pi;
    std::cout << "   " << oss.str() << std::endl;
    
    // 4. printf-style formatting (still available)
    std::cout << "4. printf-style formatting:" << std::endl;
    printf("   Classic printf: num=%d, pi=%.2f\n", num, pi);
    
    // 5. C++20 std::format (similar to C# string interpolation)
    // Only include if C++20 is available
#if __cplusplus >= 202002L
    std::cout << "5. C++20 std::format (like C# string interpolation):" << std::endl;
    std::cout << "   " << std::format("Number: {}, Pi: {:.2f}", num, pi) << std::endl;
    
    // Complex formatting with std::format
    std::cout << "   " << std::format("Hex: {0:#x}, Decimal: {0}, Pi: {1:.3f}", num, pi) << std::endl;
#else
    std::cout << "5. C++20 std::format not available with current compiler settings" << std::endl;
#endif
    
    // 6. Modern print alternative without std::endl for better performance
    std::cout << "6. Modern printing without std::endl (better performance)\n";
    
    // 7. Using string_view for efficient string operations (C++17)
    std::string_view sv = "Efficient string_view for print operations";
    std::cout << "7. Using string_view: " << sv << "\n";
    
    // ===== INPUT METHODS =====
    std::cout << "\n===== Modern Input Methods =====\n";
    
    // 1. Traditional std::cin
    std::cout << "1. Traditional std::cin (uncomment to use):" << std::endl;
    /*
    int input_number;
    std::cout << "   Enter a number: ";
    std::cin >> input_number;
    std::cout << "   You entered: " << input_number << std::endl;
    
    // Clear any leftover newlines in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    */
    
    // 2. Reading entire lines with getline
    std::cout << "2. Reading lines with std::getline (uncomment to use):" << std::endl;
    /*
    std::string input_line;
    std::cout << "   Enter a line of text: ";
    std::getline(std::cin, input_line);
    std::cout << "   You entered: " << input_line << std::endl;
    */
    
    // 3. Input with validation
    std::cout << "3. Input with validation (uncomment to use):" << std::endl;
    /*
    int validated_input;
    bool valid_input = false;
    while (!valid_input) {
        std::cout << "   Enter a positive number: ";
        if (std::cin >> validated_input && validated_input > 0) {
            valid_input = true;
        } else {
            std::cout << "   Invalid input. Please try again.\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input
        }
    }
    std::cout << "   Valid input received: " << validated_input << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    */
    
    // 4. String streams for parsing
    std::cout << "4. Using string streams for parsing:" << std::endl;
    std::string data = "123 3.14 Hello";
    std::istringstream iss(data);
    
    int parsed_int;
    double parsed_double;
    std::string parsed_string;
    
    iss >> parsed_int >> parsed_double >> parsed_string;
    
    std::cout << "   Parsed int: " << parsed_int << std::endl;
    std::cout << "   Parsed double: " << parsed_double << std::endl;
    std::cout << "   Parsed string: " << parsed_string << std::endl;
    
    // 5. Modern approaches to parsing
    std::cout << "5. Modern parsing approaches:" << std::endl;
    std::string number_str = "42";
    int converted = std::stoi(number_str); // String to int (also: stol, stoll, stof, stod)
    std::cout << "   String to int: " << converted << std::endl;
    
    // 6. Best practices for I/O in modern C++
    std::cout << "6. Modern I/O best practices:" << std::endl;
    std::cout << "   • Prefer '\\n' over std::endl when flushing isn't needed\n";
    std::cout << "   • Use string_view when not modifying strings\n";
    std::cout << "   • Use std::format in C++20 for readable formatting\n";
    std::cout << "   • Consider using <charconv> for fast numeric conversions\n";
    std::cout << "   • Always validate user input\n";
}

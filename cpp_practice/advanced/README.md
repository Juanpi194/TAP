# GUIDE

## HPP
Class Person will be used as an example (fields: unsigned int age, std::string name).
Each *ClassName.hpp* should have its own *ClassName.cpp*, where the methods will be defined.

### ENCAPSULATION
Word 'private' is used to not let those fields being accessed from other files.
Word 'public' is used to let those fields being able to be accessed from other files.

### CONSTRUCTORS
```cpp
Person(void);	// Default constructor
Person(unsigned int age, const std::string& name);	// Other constructor
~Person(void) = default;	// Destructor ('= default' only if default behavior)
```
`Default constructor` will be used when none is specified.
Other constructors will be used when they are specified.
`Destructor` will be called when the `delete` word is used (HEAP) or when the scope of the variable ends (STACK, automatic)

### OPERATORS
```cpp
Person&	operator=(const Person& other);
bool	operator==(const Person& other) const;
```
`Operator =` is used when doing p1 = p2 (for example).
There are lots of operators, but that one is the most used.

### GETTERS AND SETTERS
These are really important to get and set the values of the private fields.
```cpp
unsigned int	get_age(void) const;
```
This method will access the variable `age` of the instance and return it (or at least it is suppossed to do so).
The word `const` at the end of a method means that no field of the instance will be modified in the method.

```cpp
void	set_name(const std::string& name);
```
This method will set the variable `name` of the instance to the one given in the parameter (or at least it is suppossed to do so).
The `&` means 'left value will be used'. **lvalues** and **rvalues** will be explained later on.

```cpp
static unsigned int	count;
```
The `static` word means that this variable is a class variable, not an instance variable.
The difference is that the static variables are related with the class, and are the same for all of its instances.
If count = 3, p1.count will be 3 and p2.count will be 3 aswell. If the variable changes, all the instances will have its own variable changed to.


### EXCEPTIONS
Common exception types:

	- std::exception
	- std::invalid_argument
	- std::runtime_error
	- std::out_of_range 

### NOEXCEPT
Word to indicate that a function will not throw an exception

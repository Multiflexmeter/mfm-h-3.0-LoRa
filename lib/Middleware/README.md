MFM-V3 Middleware V1.0
---
This library provides a middleware solution, allowing chaining of functions which
modify a context object.

## Usage
The middleware system is initialized as follows:
```cpp
    #include <MiddlewareSystem.h>

    int main() {
        MiddlewareSystem<int, 5> system;
    }
```

The class requires two template items, namely **T** and **N**. They define the object class and the chain size respectively. If a user tries to add more middleware than N, then it just won't be added.

## Adding and defining middleware
Middleware is defined as to the following format, where T is the defined class in your middleware system:
```cpp
    bool (*)(T*)
    // Or more readable
    bool FunctionName(T* context);
```

Adding the middleware is as trivial as executing the `add` function:
```cpp
    MiddlewareSystem<T,N> add(MiddewareFunctionPtr<T>);
```

*If you don't get it yet see the example below*

## Executing & Example
The system can be executed using `execute` with a pointer to the context object.

A full example:

An example:
```cpp
    #include <MiddlewareSystem.h>

    /*
     * Our middleware function, this will be executed when
     * the chain is executed
     */
    bool AdditionMiddleware(int* context) {
        *context += 10;
    }

    /*
     * Psuedo application entry point
     */
    int main() {
        // Initialize the middleware system
        MiddlewareSystem<int, 5> system;

        // Add middleware functions
        // With more than 1 middleware, order is important
        system.add(&AdditionMiddleware);

        // Our context object
        int context = 10;

        // Execute the chain with our context pointer
        system.execute(&context);

        // context is now 20
    }
```

## LICENSE
This library is developed and maintained by [Tim van Osch](https://github.com/timvosch) ([Pollex' Projects](https://github.com/pollexprojects)) and is licensed under AGPL V3. Please see the accompanying LICENSE file for the full license.

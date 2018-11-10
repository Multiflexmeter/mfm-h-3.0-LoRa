/**
 * Author: Pollex' (Tim van Osch)
 * Email: timvosch@pollexprojects.nl
 * Date: 10-11-2018 12:25
 */

#ifndef _MIDDLEWARE_SYSTEM_H_
#define _MIDDLEWARE_SYSTEM_H_

/**
 * A middleware system which executes a chain of functions of size N, that modifies a
 * given object, whose type is defined by T.
 * @param  MiddlewareFunction The executed function with parameter of type T
 * @return                    modified T
 */
template<typename T, short unsigned int N>
class MiddlewareSystem {
public:
    // Define the MiddlewareFunction signature
    typedef bool(*MiddlewareFunction)(T*);
    // Ctor
    MiddlewareSystem();
    // Dtor
    ~MiddlewareSystem();
    void add(MiddlewareFunction, char);
    void execute(T*);
private:
    // Define templated struct for this middleware system
    struct Middleware_t {
        MiddlewareFunction middlewareFunction;
        char priority;
    };
    // amount of middlewares
    Middleware_t chain[N];
    // Utility
    static void shiftRight(Middleware_t*, unsigned short int);
};

#endif /* end of include guard: _MIDDLEWARE_SYSTEM_H_ */

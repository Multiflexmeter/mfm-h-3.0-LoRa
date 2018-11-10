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
template<class T, int N>
class MiddlewareSystem {
public:
    // Define the MiddlewareFunction signature
    typedef bool(*MiddlewareFunction)(T*);
    MiddlewareSystem();
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

template<class T, int N>
MiddlewareSystem<T, N>::MiddlewareSystem() {
    // CTOR
}

template<class T, int N>
MiddlewareSystem<T, N>::~MiddlewareSystem() {
    delete[] this->chain;
}

#endif /* end of include guard: _MIDDLEWARE_SYSTEM_H_ */

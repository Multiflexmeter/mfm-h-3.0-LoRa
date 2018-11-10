/**
 * Author: Pollex' (Tim van Osch)
 * Email: timvosch@pollexprojects.nl
 * Date: 10-11-2018 12:25
 */

#include "MiddlewareSystem.h"

/**
 * Static utitlity
 */
template<typename T, short unsigned int N>
void MiddlewareSystem<T,N>::shiftRight(Middleware_t *chain, unsigned short int position) {

}

/**
 * Middleware constructor
 */
template<typename T, short unsigned int N>
MiddlewareSystem<T,N>::MiddlewareSystem() {

}

/**
 * Middleware disposal
 */
template<typename T, short unsigned int N>
MiddlewareSystem<T,N>::~MiddlewareSystem() {
    delete[] this->chain;
    // TODO: Remove referenc function as well?
}

/**
 * Add a middleware function
 */
template<typename T, short unsigned int N>
void MiddlewareSystem<T,N>::add(MiddlewareFunction function, char priority) {
    Middleware_t newChainEntry {
        function,
        priority
    };
    // Insert at correct position
}

/*
 * Execute the chain of middleware functions that modify a passed object
 */
template<typename T, short unsigned int N>
void MiddlewareSystem<T,N>::execute(T* context) {

}

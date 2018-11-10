/**
 * Author: Pollex' (Tim van Osch)
 * Email: timvosch@pollexprojects.nl
 * Date: 10-11-2018 12:25
 */

#include "MiddlewareSystem.h"

/**
 * Shift the entries of the middleware chain to the right starting at given position.
 * Note that the Nth entry will awlays be cut off.
 * @param chain    The chain to shift to the right
 * @param position Where to start shifting
 */
template<typename T, int N>
void MiddlewareSystem<T,N>::shiftRight(Middleware_t *chain, unsigned short int position) {
    for (unsigned short int i = N - 1; i > position; i--) {
        memcpy(
            chain + sizeof(Middleware_t) * i,
            chain + sizeof(Middleware_t) * (i - 1),
            sizeof(Middleware_t)
        );
    }
}

/**
 * Add a middleware function
 */
template<typename T, int N>
void MiddlewareSystem<T,N>::add(MiddlewareFunction function, char priority) {
    Middleware_t newChainEntry {
        function,
        priority
    };
    // Insert at correct position
    for (int i = 0; i < N; i++) {
        // entry at index i
        Middleware_t chainEntry = this->chain[i];
        // Check if priority is lower than ours
        if (chainEntry->priority < priority) {
            MiddlewareSystem::shiftRight(&this->chain, i);
            this->chain[i] = newChainEntry;
            return;
        }
    }
}

/*
 * Execute the chain of middleware functions that modify a passed object
 */
template<typename T, int N>
void MiddlewareSystem<T,N>::execute(T* context) {

}

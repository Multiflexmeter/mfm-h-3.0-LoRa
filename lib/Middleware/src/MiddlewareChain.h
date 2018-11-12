#ifndef _MIDDLEWARE_CHAIN_H_
#define _MIDDLEWARE_CHAIN_H_

#include "MiddlewareFunction.h"

template<class T, unsigned short int N>
class MiddlewareChain {
public:
    void add(MiddlewareFunctionPtr<T>);
    MiddlewareFunctionPtr<T> entries[N];
private:
    unsigned short int position = 0;
};

#include "MiddlewareChain.tpp"

#endif /* end of include guard: _MIDDLEWARE_CHAIN_H_ */

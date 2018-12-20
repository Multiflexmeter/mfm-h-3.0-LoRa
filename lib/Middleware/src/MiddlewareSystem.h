#ifndef _MIDDLEWARE_SYSTEM_H_
#define _MIDDLEWARE_SYSTEM_H_

#include "MiddlewareFunction.h"
#include "MiddlewareChain.h"

template<class T, unsigned short int N>
class MiddlewareSystem {
public:
    void add(MiddlewareFunctionPtr<T>);
    void execute(T& context);
private:
    MiddlewareChain<T,N> chain;
};

#include "MiddlewareSystem.tpp"

#endif /* end of include guard: _MIDDLEWARE_SYSTEM_H_ */

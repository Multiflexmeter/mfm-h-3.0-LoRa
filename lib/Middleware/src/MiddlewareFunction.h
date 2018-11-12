#ifndef _MIDDLEWARE_FUNCTION_H_
#define _MIDDLEWARE_FUNCTION_H_

template<typename T>
using MiddlewareFunctionPtr = bool(*)(T*);

#endif /* end of include guard: _MIDDLEWARE_FUNCTION_H_ */

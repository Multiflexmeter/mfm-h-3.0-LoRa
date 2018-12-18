template<class T, unsigned short int N>
void MiddlewareSystem<T,N>::add(MiddlewareFunctionPtr<T> functionPtr) {
    this->chain.add(functionPtr);
}

template<class T, unsigned short int N>
void MiddlewareSystem<T,N>::execute(T& context) {
    for (unsigned short int i = 0; i < N; i++) {
        MiddlewareFunctionPtr<T> functionPtr = this->chain.entries[i];
        if (!(*functionPtr)(context)) {
            return;
        }
    }
}

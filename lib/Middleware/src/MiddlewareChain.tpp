
template<class T, unsigned short int N>
void MiddlewareChain<T,N>::add(MiddlewareFunctionPtr<T> functionPtr) {
    if (this->position == N) { return; }
    this->entries[this->position] = functionPtr;
    this->position++;
}

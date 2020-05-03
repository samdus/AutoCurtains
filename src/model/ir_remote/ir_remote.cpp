#include "ir_remote.hpp"

void IrRemote::init(){
    this->enableIRIn();
    this->blink13(true);
}

int IrRemote::decode(){
    int res = this->IRrecv::decode(&lastResult);
    this->resume();
    return res;
}
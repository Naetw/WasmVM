#include <structures/WasmFunc.h>

#include <stdlib.h>

WasmFunc* new_WasmFunc()
{
    WasmFunc* newWasmFunc = (WasmFunc*) malloc(sizeof(WasmFunc));
    // vectors
    newWasmFunc->locals = new_vector(sizeof(ValueType));
    newWasmFunc->body = new_list((void(*)(void*))free_WasmInstr);

    return newWasmFunc;
}

void free_WasmFunc(WasmFunc* thisWasmFunc)
{
    free_vector(thisWasmFunc->locals);
    free_list(thisWasmFunc->body);
    free(thisWasmFunc);
}

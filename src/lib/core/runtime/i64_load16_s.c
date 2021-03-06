#include <core/Runtime.h>
#include <dataTypes/Value.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int runtime_i64_load16_s(Stack *stack, MemInst *memory, uint32_t offset,
                         uint32_t align)
{
    Value *value1 = NULL;

    stack->entries->pop(stack->entries, (void **)&value1);

    uint32_t ea = value1->value.u32 + offset;

    if (ea + (16 / 8) >= memory->max * 65536) {
        fprintf(stderr, "over the memory range! \n");
        free(value1);
        return -1;
    }

    int16_t *data = (int16_t *)((uint8_t *)memory->data->data + ea);

    stack->entries->push(stack->entries, new_i64Value((int64_t)*data));
    free(value1);
    return 0;
}

#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 50

uint32_t buffer1[BUFFER_SIZE] = {0};
uint32_t buffer2[BUFFER_SIZE] = {0};

enum buff_num {
    BUFFER1,
    BUFFER2
};

typedef enum {
    false,
    true
} bool;

bool check_unsigned_limit(uint8_t value, uint32_t limit)
{
    if(value >= limit || value < 0)
    {
        return false;
    }
    return true;

}
typedef struct {
    void (* pbuffer_init) (uint32_t *);
    void (* pbuffer_write) (uint8_t, uint32_t);
    uint32_t (* pbuffer_read) (uint8_t);
}buffer_intf_t;

void buffer_init(uint32_t *buffer)
{
    for(int x =0; x < BUFFER_SIZE; x++)
    {
        buffer[x] = 1;
    }
}

void buffer1_write(uint8_t index, uint32_t value)
{
    if(!check_unsigned_limit(index, BUFFER_SIZE))
    {
        printf("invalid index\n");
        return;
    }
    buffer1[index] = value;
}

uint32_t buffer1_read(uint8_t index)
{
    if(!check_unsigned_limit(index, BUFFER_SIZE))
    return 0;
    return buffer1[index];
}


void buffer2_write(uint8_t index, uint32_t value)
{
    if(!check_unsigned_limit(index, BUFFER_SIZE))
    return;
    buffer2[index] = value;
}

uint32_t buffer2_read(uint8_t index)
{
    if(!check_unsigned_limit(index, BUFFER_SIZE))
    return 0;
    return buffer2[index];
}


int main(void)
{
    buffer_intf_t buffer_intf[] = {
        {buffer_init, buffer1_write, buffer1_read}, 
        {buffer_init, buffer2_write, buffer2_read}
        };
    // buffer_init(buffer1);
    buffer_intf[BUFFER1].pbuffer_init(buffer1);
    buffer_intf[BUFFER2].pbuffer_init(buffer2);
    buffer_intf[BUFFER1].pbuffer_write(4, 237);
    buffer_intf[BUFFER2].pbuffer_write(4, 1364);

    printf("buffer 1: %d\n",buffer_intf[BUFFER1].pbuffer_read(4));
    printf("buffer 2: %d\n",buffer_intf[BUFFER2].pbuffer_read(4));
    return 0;
}
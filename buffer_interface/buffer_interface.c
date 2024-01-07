#include <stdio.h>

#define BUFFER_SIZE 50

u_int32_t buffer1[BUFFER_SIZE] = {0};
u_int32_t buffer2[BUFFER_SIZE] = {0};

enum buff_num {
    BUFFER1,
    BUFFER2
};

typedef enum {
    false,
    true
} bool;

bool check_unsigned_limit(u_int8_t value, u_int32_t limit)
{
    if(value >= limit || value < 0)
    {
        return false;
    }
    return true;

}
typedef struct {
    void (* pbuffer_init) (u_int32_t *);
    void (* pbuffer_write) (u_int8_t, u_int32_t);
    u_int32_t (* pbuffer_read) (u_int8_t);
}buffer_intf_t;

void buffer_init(u_int32_t *buffer)
{
    for(int x =0; x < BUFFER_SIZE; x++)
    {
        buffer[x] = 1;
    }
}

void buffer1_write(u_int8_t index, u_int32_t value)
{
    if(!check_unsigned_limit(index, BUFFER_SIZE))
    {
        printf("invalid index\n");
        return;
    }
    buffer1[index] = value;
}

u_int32_t buffer1_read(u_int8_t index)
{
    if(!check_unsigned_limit(index, BUFFER_SIZE))
    return 0;
    return buffer1[index];
}


void buffer2_write(u_int8_t index, u_int32_t value)
{
    if(!check_unsigned_limit(index, BUFFER_SIZE))
    return;
    buffer2[index] = value;
}

u_int32_t buffer2_read(u_int8_t index)
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
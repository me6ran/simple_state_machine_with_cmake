#include <stdio.h>

#define BUFFER_SIZE 50

unsigned int buffer1[BUFFER_SIZE] = {0};
unsigned int buffer2[BUFFER_SIZE] = {0};

enum buff_num {
    BUFFER1,
    BUFFER2
};

typedef struct {
    void (* pbuffer_init) (unsigned int *);
    void (* pbuffer_write) (short int, unsigned int);
    unsigned int (* pbuffer_read) (short int);
}buffer_intf_t;

void buffer_init(unsigned int *buffer)
{
    for(int x =0; x < BUFFER_SIZE; x++)
    {
        buffer[x] = 1;
    }
}

void buffer1_write(short int index, unsigned int value)
{
    if(index >= BUFFER_SIZE)
    return;
    buffer1[index] = value;
}

unsigned int buffer1_read(short int index)
{
    if(index >= BUFFER_SIZE)
    return 0;
    return buffer1[index];
}


void buffer2_write(short int index, unsigned int value)
{
    if(index >= BUFFER_SIZE)
    return;
    buffer2[index] = value;
}

unsigned int buffer2_read(short int index)
{
    if(index >= BUFFER_SIZE)
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
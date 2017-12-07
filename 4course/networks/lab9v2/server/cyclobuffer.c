#include "cyclobuffer.h"
#include <string.h>

void append(struct cycloBuffer* buffer, char* data, int datasize)
{
    //проверяем, что точно хватает места
    if (buffer->tail > buffer->head) {
        int freeBytes = buffer->capacity - buffer->tail + buffer->head;
        if (freeBytes > buffer->capacity) {
            expand(buffer);
        }
        if ((buffer->capacity - buffer->tail) > datasize) {
            memcpy(buffer->buffer + buffer->tail, data, datasize);
        } else { //если места не хватает
            //записываем capacity - tail bytes
            int writeBytes = buffer->capacity - buffer->tail;
            memcpy(buffer->buffer + buffer->tail, data, writeBytes);
            memcpy(buffer->buffer, data + writeBytes, datasize - writeBytes);
            buffer->tail = datasize - writeBytes;
        }

    } else {
        if ((buffer->capacity - (buffer->head - buffer->tail)) < datasize) {
            expand(buffer);
        }
        memcpy(buffer->buffer + buffer->tail, data, datasize);
        buffer->tail += datasize;
    }
}

void getData(struct cycloBuffer* buffer, char* dataBuffer, int dataBufferSize)
{
    int countBytes = 0;

    if (buffer->tail >= buffer->head) //memmove :)
        for (int i = buffer->head; i < buffer->tail && dataBufferSize > countBytes; i++) {
            dataBuffer[countBytes] = buffer->buffer[i];
            countBytes++;
        }
    else {
        //тейл в начала, хеад в конце
        for (int i = buffer->head; i < buffer->capacity && dataBufferSize > countBytes; i++) {
            dataBuffer[countBytes] = buffer->buffer[i];
            countBytes++;
        }
        for (int i = 0; i < buffer->tail && dataBufferSize > countBytes; i++) {
            dataBuffer[countBytes] = buffer->buffer[i];
            countBytes++;
        }
    }
}

void moveHead(struct cycloBuffer* buffer, int numBytes)
{
    buffer->head += (buffer->head + numBytes) % buffer->capacity;
}

void expand(struct cycloBuffer* buffer)
{
    char* temp = (char*)malloc(buffer->capacity * 2);
    memmove(temp, buffer->buffer, buffer->head);
    memmove(temp + buffer->capacity * 2 - buffer->tail, buffer->buffer, buffer->tail);
    if (buffer->buffer)
        free(buffer->buffer);
    buffer->buffer = temp;
}

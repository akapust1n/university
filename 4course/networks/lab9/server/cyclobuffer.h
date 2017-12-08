#ifndef CYCLOBUFFER_H
#define CYCLOBUFFER_H

struct cycloBuffer {
    int capacity;
    char* buffer;
    int tail; //первый свободный
    int head; //первый занятый
};
void getData(struct cycloBuffer* buffer, char* dataBuffer, int dataBufferSize);
void append(struct cycloBuffer* buffer, char* data, int datasize);

void moveHead(struct cycloBuffer* buffer, int numBytes);
void expand(struct cycloBuffer* buffer);
#endif // CYCLOBUFFER_H

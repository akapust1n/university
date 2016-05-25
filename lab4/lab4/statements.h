#ifndef STATEMENTS_H
#define STATEMENTS_H
enum class state_lift { wait,
    go,
    doors_opening,
    doors_closing,
    doors_opened,
    minor_wait };
enum class emp { empty,
    full };
enum class state{st_opening,st_closing, st_opened, st_closed};


#endif // STATEMENTS_H

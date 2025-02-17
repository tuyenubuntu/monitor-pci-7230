#include <stdio.h>
#include <stdlib.h>  // Thêm thư viện này để dùng exit()
#include <unistd.h>
#include <pthread.h>
#include "dask.h"
#include <stdint.h> // cho uint16_t
#include <windows.h>



typedef uint16_t DASK_USHORT;  // Rename USHORT to DASK_USHORT
typedef int DASK_BOOLEAN;      // Rename BOOLEAN to DASK_BOOLEAN

#ifndef BOOLEAN
    typedef int DASK_BOOLEAN;
#endif

#ifndef HANDLE
    typedef void* DASK_HANDLE;
#endif


// Hàm để thiết lập trạng thái DO
void SetDOState(U16 port, U32 val)
{
    I16 card = -1, card_number = 0;
    if((card = Register_Card(PCI_7230, card_number)) < 0){
        printf("Can't open device file: PCI7230\n");
        exit(-1);
    }
    DO_WritePort(card, port, val);
    if(card >= 0){
        Release_Card(card);
    }
}

// Hàm để lấy trạng thái DI từ một port
U32 GetDIState(U16 port)
{
    I16 card = -1, card_number = 0;
    U32 input = 0;
    if((card = Register_Card(PCI_7230, card_number)) < 0){
        printf("Can't open device file: PCI7230\n");
        exit(-1);
    }
    DI_ReadPort(card, port, &input);
    if(card >= 0){
        Release_Card(card);
    }
    return input;
}

// Hàm để lấy trạng thái DO từ một port
U32 GetDOState(U16 port)
{
    I16 card = -1, card_number = 0;
    U32 output = 0;
    if((card = Register_Card(PCI_7230, card_number)) < 0){
        printf("Can't open device file: PCI7230\n");
        exit(-1);
    }
    if (DO_ReadPort(card, port, &output) < 0) {
        printf("Error reading DO state from port %d\n", port);
        if(card >= 0){
            Release_Card(card);
        }
        exit(-1);
    }
    if(card >= 0){
        Release_Card(card);
    }
    return output;
}

// Hàm để lấy trạng thái của một dòng DI cụ thể
U16 GetDIState_Line(U16 port, U16 line)
{
    I16 card = -1, card_number = 0;
    U16 state;
    if((card = Register_Card(PCI_7230, card_number)) < 0){
        printf("Can't open device file: PCI7230\n");
        exit(-1);
    }
    DI_ReadLine(card, port, line, &state);
    if(card >= 0){
        Release_Card(card);
    }
    return state;
}

// Hàm để lấy trạng thái của một dòng DO cụ thể
U16 GetDOState_Line(U16 port, U16 line)
{
    I16 card = -1, card_number = 0;
    U16 state;
    if((card = Register_Card(PCI_7230, card_number)) < 0){
        printf("Can't open device file: PCI7230\n");
        exit(-1);
    }
    DO_ReadLine(card, port, line, &state);
    if(card >= 0){
        Release_Card(card);
    }
    return state;
}

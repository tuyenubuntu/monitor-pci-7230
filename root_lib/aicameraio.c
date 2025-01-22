#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "dask.h"

void SetDOState(U16 port, U32 val)
{
    I16 card = -1, card_number = 0;
    if((card = Register_Card(PCI_7230, card_number))<0){
        printf("Can't open device file: PCI7230\n");
        exit(-1);
    }
    DO_WritePort(card, port, val);
    if(card>=0){
        Release_Card(card);
    }
}

U32 GetDIState(U16 port){
    I16 card = -1,  card_number = 0;
    U32 input = 0;
    if((card = Register_Card(PCI_7230, card_number))<0){
        printf("Can't open device file: PCI7230\n");
        exit(-1);
    }
    DI_ReadPort(card, port, &input);
    if(card>=0){
        Release_Card(card);
    }
    return input;
}
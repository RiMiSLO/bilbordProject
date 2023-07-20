#ifndef TTYSEND_H
#define TTYSEND_H

#include <string>
#include <linux/serial.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cassert>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "include.h"


#define START_BYTE     0x02 // Стартовый байт пакета
#define STOP_BYTE      0x03 // Стоповый байт пакета
#define MAX_DATA_LEN 255  // максимальная длина пользовательских данных пакета
#define MAX_PACKET_LEN MAX_DATA_LEN + 8  // максимальная длина пакета
//namespace ttyBilbord{

class ttySend
{
public:
private:
    typedef struct {
         const uint8_t startdataTTY=0x25;
         const uint8_t modedatatTTY=0x34;
         const uint8_t submodeTTY=0x62;
         uint8_t numbertable[2];
     } dataTTYmess;

    typedef struct {
        const uint8_t startTTYpack = START_BYTE;
        const uint8_t adress[2]={0x30, 0x31};
        uint8_t lenData[2];
        dataTTYmess data;
        uint8_t crc;
        const uint8_t finishTTYpack = STOP_BYTE;
     } sendTTYmess;

    typedef struct {

        uint8_t adress[2]={0x30, 0x31};
        uint8_t lenData[2];
        dataTTYmess data;
     } sendTTYmessTEST;



    ttySend();
    void openttk();
    char* createMessage( int a);
};


//}


#endif // TTYSEND_H

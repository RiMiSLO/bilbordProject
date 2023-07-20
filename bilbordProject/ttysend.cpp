#include "ttysend.h"
#include  <QDebug>
#include <iostream>


#define MAX_DATA_LEN 255  // максимальная длина пользовательских данных пакета
#define MAX_PACKET_LEN MAX_DATA_LEN + 8  // максимальная длина пакета



ttySend::ttySend()
{

}
void ttySend::openttk(){




    int fd;/*File Descriptor*/

            printf("\n +----------------------------------+");
            printf("\n |        TTY/COM Port               |");
            printf("\n +----------------------------------+");

            /*------------------------------- Opening the Serial Port -------------------------------*/
            /* Change /dev/ttyUSB0 to the one corresponding to your system */

                fd = open("/dev/ttyUSB0",O_RDWR);	/* ttyUSB0 is the FT232 based USB2SERIAL Converter   */
                                    /* O_RDWR   - Read/Write access to serial port       */
                                    /* O_NOCTTY - No terminal will control the process   */
                                    /* Open in blocking mode,read will wait              */


                //if(fd == -1)						/* Error Checking */
           if(fd < 0) {						/* Error Checking */
                printf("\n  Error! in Opening ttyUSB0  ");
                return;
                //exit(0);
            }
            printf("\n  ttyUSB0 Opened Successfully ");

            /*---------- Setting the Attributes of the serial port using termios structure --------- */

            struct termios SerialPortSettings;	/* Create the structure                          */

            tcgetattr(fd, &SerialPortSettings);	/* Get the current attributes of the Serial port */

            /* Setting the Baud rate */
            cfsetispeed(&SerialPortSettings,B9600); /* Set Read  Speed as 9600                       */
            cfsetospeed(&SerialPortSettings,B9600); /* Set Write Speed as 9600                       */

            /* 8N1 Mode */
            SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
            SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
            SerialPortSettings.c_cflag &= ~CSIZE;	 /* Clears the mask for setting the data size [ Clears the mask for setting the data size]              */
            SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */

            SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
            SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */

            SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
            SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */

            SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

            /* Setting Time outs */
            SerialPortSettings.c_cc[VMIN] = 40; /* Read at least 10 characters */
            SerialPortSettings.c_cc[VTIME] = 10; /* Wait indefinetly   */


            if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
                printf("\n  ERROR ! in Setting attributes");
            else
                        printf("\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none");

                /*------------------------------- Read data from serial port -----------------------------*/
            while(true){

            char read_buffer[20]={0x02,0x30,0x31,0x30, 0x35,0x25,0x34,0x62,0x30,0x36,0x38,0x45,0x03};   /* Buffer to store the data received              */

            int  bytes_read = 0;    /* Number of bytes read by the read() system call */
//            switch(a){
//            case 1:read_buffer[10]=0x38;read_buffer[11]=0x39;       break;
//            case 2:read_buffer[10]=0x38;read_buffer[11]=0x41;       break;
//            case 3:read_buffer[10]=0x38;read_buffer[11]=0x42;       break;
//            case 4:read_buffer[10]=0x38;read_buffer[11]=0x43;       break;
//            case 5:read_buffer[10]=0x38;read_buffer[11]=0x44;       break;
//            case 6:read_buffer[10]=0x38;read_buffer[11]=0x45;       break;
//            case 7:read_buffer[10]=0x38;read_buffer[11]=0x46;       break;
//            case 8:read_buffer[10]=0x38;read_buffer[11]=0x30;       break;
//            case 9:read_buffer[10]=0x38;read_buffer[11]=0x31;       break;
//            case 10:read_buffer[10]=0x38;read_buffer[11]=0x32;      break;
//            }

            sendTTYmess newMess;
            sendTTYmessTEST secondMess;
            if( isEmptyQueueList()==false){
            int a = getQueueList();
                /* назначение номера изображения */
                if ( a >= 10){
                    uint8_t b=0;
                    b=a%10;
                    newMess.data.numbertable[0]=0x30+b;
                    newMess.data.numbertable[1]=0x30+(a/10);
                }
                else{
                    newMess.data.numbertable[0]=0x30;
                    newMess.data.numbertable[1]=0x30+a;
                }
                /* addr of pc */
                newMess.adress;

                //kol-vo data size
                int sizeDatamess = sizeof(newMess.data);
                if (sizeDatamess >= 10){
                    int b=0;
                    b=sizeDatamess%10;
                    newMess.lenData[0]=0x30+(uint8_t)b;
                    newMess.lenData[1]=0x30+(sizeDatamess/10);
                }
                else{
                    newMess.lenData[0]=0x30;
                    newMess.lenData[1]=0x30+sizeDatamess;
                }
                //crc
                secondMess.lenData[0]=newMess.lenData[0];
                secondMess.lenData[1]=newMess.lenData[1];
                secondMess.data.numbertable[0]=newMess.data.numbertable[0];
                secondMess.data.numbertable[1]=newMess.data.numbertable[1];

                newMess.crc=0;
                int l=4+sizeof(newMess.data);

                //newMess.crc = CRC16((uint8_t *) secondMess, l);
                           tcflush(fd, TCIFLUSH);
                           bytes_read = write(fd, read_buffer, sizeof(read_buffer));
                           printf("%d hi", bytes_read);
                           }

           // while (1) {
                tcflush(fd, TCIFLUSH);   /* Discards old data in the rx buffer  */
                bytes_read = read(fd,&read_buffer,32); /* Read the data                   */
                printf("\n\n  Bytes Rxed -%d", bytes_read); /* Print the number of bytes read */
                printf("\n\n  ");
                if(bytes_read==0){
                    break;
                }
                for(int i=0;i<bytes_read;i++)	 /*printing only the received characters*/
                    printf("%c",read_buffer[i]);
                //}

            close(fd); /* Close the serial port */
        }
    return;
}

char * ttySend::createMessage( int a){


}



//--------------------------------------------------------
// Формирование двухбайтного ASCII представления одного байта
void SetASCIIByteValue(__uint8_t AData, __uint8_t * APAddr){

  __uint8_t b;

  b = (AData & 0xF0) >> 4;
  if (b <= 9)
    b += 0x30;
  else
    b = b - 10 + 0x41;

  *APAddr = b;

  printf( " H: %X", b);

  b = AData & 0x0F;
  if (b <= 9)
    b += 0x30;
  else
    b = b - 10 + 0x41;

  *(APAddr + 1) = b;

    printf( " L: %X", b);
}

//--------------------------------------------------------
// Получение байта - двоичного значения однобайтного ASCII

__uint8_t GetByte1ASCIIValue(__uint8_t * APAddr){

  __uint8_t b, bRes;

  printf( " str: %X %X", *APAddr, *(APAddr + 1));

  if (*APAddr > 0x60)
    bRes = *APAddr - 0x60 + 9;
  else
  if (*APAddr > 0x40)
    bRes = *APAddr - 0x40 + 9;
  else
    bRes = *APAddr - 0x30;

  //if (bRes > 9)
  //  bRes = bRes - 7;

    printf( " L: %X", bRes);


  return bRes;
}

//--------------------------------------------------------
// Получение байта - двоичного значения двухбайтного ASCII

__uint8_t GetByte2ASCIIValue(__uint8_t * APAddr){

  __uint8_t b, bRes;

  printf( " str: %X %X", *APAddr, *(APAddr + 1));

  if (*APAddr > 0x60)
    bRes = *APAddr - 0x60 + 9;
  else
  if (*APAddr > 0x40)
    bRes = *APAddr - 0x40 + 9;
  else
    bRes = *APAddr - 0x30;

//  bRes = *APAddr - 0x30;
//  if (bRes > 9)
//    bRes = bRes - 7;

    printf( " H: %X", bRes);

  bRes = bRes << 4;

  if (*(APAddr + 1) > 0x60)
    b = *(APAddr + 1) - 0x60 + 9;
  else
  if (*(APAddr + 1) > 0x40)
    b = *(APAddr + 1) - 0x40 + 9;
  else
    b = *(APAddr + 1) - 0x30;

//  b = *(APAddr + 1) - 0x30;
//  if (b > 9)
//    b = b - 7;

  bRes += b;

    printf( " L: %X", b);

  return bRes;
}


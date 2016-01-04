#include "wsDrive.h"

wsDrive::wsDrive(PinName mosi, PinName miso, PinName clk) : BurstSPI(mosi,miso,clk)
{
    frequency(2400000);
    format(12);
    pixArray = NULL;
    pixArray16 = NULL;
    pixelLen = 0;
}

void wsDrive::setData(pixelInfo *dataStart, uint16_t dataLen)
{
    pixArray = dataStart;
    pixelLen = dataLen;
    pixArray16 = NULL;
}

void wsDrive::sendData()
{
    frequency(2400000);
    format(12);
    setFormat();


    uint16_t pixIndex = 0;
    if (pixArray) {
        while (pixIndex < pixelLen) {
            sendPixel(pixArray + pixIndex++);
        }
    } else if (pixArray16) {
        while (pixIndex < pixelLen) {
            sendPixel(pixArray16 + pixIndex++);
        }
    }
}

// each bytes sent as two 12 bit messages (3 bits of data per LED bit).
void wsDrive::sendByte(unsigned char value)
{
    uint16_t dataToSend = 0;

    uint8_t mask = 0x80;
    while (mask) {
        dataToSend += (value & mask)?0x06:0x4; // 100 for a 0 or 110 for a 1
        if (mask & 0x11) {                     // trans
            fastWrite(dataToSend);
            dataToSend = 0;
        }
        dataToSend = dataToSend << 3;
        mask = mask >> 1;
    }
}

void wsDrive::sendPixel(pixelInfo *pixToSend)
{
    sendByte(pixToSend->G);
    sendByte(pixToSend->R);
    sendByte(pixToSend->B);
}

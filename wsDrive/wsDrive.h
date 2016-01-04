#ifndef __wsDrive_h__
#define __wsDrive_h__

#include "BurstSPI.h"

/****************************************************************
* An alternative WS2811/2812 driver using the BusrtSPI library
* Credit for the inspiration goes to Jacob for his pixelArray library
* http://developer.mbed.org/users/JacobBramley/code/PixelArray/
*
* This version was written mainly to help me understand what was going on
* While the end result is the same the code is completely from scratch.
*
*****************************************************************/


/** A structure used to hold a single pixel or a pixel colour
*
* Each colour can be set to any value between about -32,768 and +32,767 (the 16 bit signed number range)
* 0 or negative values mean that colour is off, 255 or more mean on at full brightness.
* In between means partially on.
* If you are never going to go outside the 0-255 range then use pixelInfo, it uses half the memory.
* however if you are calculating pixel values when superimposing two images and don't want to worry about wrap around then use this version.
*
* Note, lots of LEDs on bright will use a lot of power, make sure your supply can cope.
*
* @param G The green component
* @param R The red component
* @param B The blue component
*/
typedef struct pixelInfo16 {
    int16_t G;
    int16_t R;
    int16_t B;
} pixelInfo16;


/** A structure used to hold a single pixel or a pixel colour
*
* Each colour can be set to any value between 0 and 255.
* 0 = off, 255 = full brightness.
*
* Note, lots of LEDs on bright will use a lot of power, make sure your supply can cope.
*
* @param G The green component
* @param R The red component
* @param B The blue component
*/
typedef struct pixelInfo {
    unsigned char G;
    unsigned char R;
    unsigned char B;
} pixelInfo;


/** Drives a WS2812 LED chain
*
* An alternative WS2811/2812 driver using the BusrtSPI library
*
* Credit for the inspiration goes to Jacob for his pixelArray library
* http://developer.mbed.org/users/JacobBramley/code/PixelArray/
*
* This version was written mainly to help me understand what was going on and is a little more basic.
* While the end result is muc the same the code is completely from scratch.
*
*  BurstSPI is used to generate the timing so support is limited to the parts supported by that library.
*
*  Also note that while all 3 SPI pins are specified only the MOSI pin is actually needed and should connect to the data in on the LEDs
*
*  Values for each LED are stored in either an array of pixelInfo or pixelInfo16 structures
*  Each LED only supports 0-255 for each colour, the limits of the pixelInfo data type.
*
*  The 16 bit version is for when you are adding/subtracting values in order to avoid
*  wraparound issues. When displayed the values outside the range are clamped to the limits.
*  This allows tricks like having a point with negative brighnesses moving along the line to add a
*  dark spot without having to worry about what happens if a number goes negative.
*
*
*  Example code to run a single lit led along a chain
*
*  @code
*
*  #include "mbed.h"
*  #include "wsDrive.h"
*
*  // update period in ms
*  #define updatePeriod 100
*  // number of LEDs
*  #define chainLen 8
*
*  DigitalIn dummy(MOSI,PullDown); // first activate the pulldown on the pin.
*  wsDrive ledDriver(MOSI,MISO,CLK); // create the SPI bus. You can normally list the MISO and CLK as NC but some mbed library versions don't like that
*
*  // pixel storage buffer
*  pixelInfo pixelData[chainLen];
*
*  Timer updateRateTimer;
*
*  void blankBuffer(pixelInfo *Ptr)
*  {
*     memset( (void *)Ptr, 0, chainLen*sizeof(pixelInfo) );
*  }
* 
*  void setPixel(unsigned int index, pixelInfo *colourToUse) {
*    if (index < chainLen) {
*      pixelData[index].R = colourToUse->R;
*      pixelData[index].G = colourToUse->G;
*      pixelData[index].B = colourToUse->B;
*    }
*  }
*
*  void clearPixel(unsigned int index) {
*    if (index < chainLen) {
*      pixelData[index].R = 0;
*      pixelData[index].G = 0;
*      pixelData[index].B = 0;
*    }
*  }
*
* int main () {
*
*   int litLed = 0;
*
*   pixelInfo colour;
*   colour.R = 0x80;
*   colour.G = 0x00;
*   colour.B = 0x00;
*
*   // Tell the driver where the data is stored
*   ledDriver.setData(pixelData, chainLen);
*
*   // Set the buffer to the pattern we want
*   blankBuffer(pixelData);
*   setPixel(litLed, &colour);
*
*   updateRateTimer.start();
*   while (true) {
*
*     ledDriver.sendData(); // send the LED data
*
*     // modify the buffer ready for the next update
*     clearPixel(litLed);
*     litLed++;
*     if (litLed == chainLen)
*       litLed = 0;
*     setPixel(litLed, &colour);
*
*     // wait until the correct time since the last update...
*     while (updateRateTimer.read_ms() < updatePeriod) {
*     }

*    updateRateTimer.reset();
*    }
* }
* @endcode
*
* Troubleshooting:
*
* If the LEDs aren't lighting up correctly then check that your power supply is up to the job (or decrease the brightness you are using)
*
* Also check the supply voltage, on paper when running off 5V the WS2812 needs 4V on the data in pin to detect a high. Mbed based boards rarely output much over 3.1V.
* This problem is normally indicated by the very first pattern send on power up being displayed but then no further updates being recieved. Dropping the supply voltage
* to about 4.2 - 4.3 V will normally fix this problem without any meaningful impact on the LED output.
*
*/
class wsDrive : private BurstSPI
{
public:
    /** create the driver
    */
    wsDrive(PinName mosi, PinName miso, PinName clk);

    /** Set the data pointer

    Before data can be sent the driver must be given a pointer to the pixel data to use.
    Setting this is normally a one time operation unless you want to switch between buffers.
    Calling this function will replace any prior buffers including pixelInfo16 ones.

    @param dataStart The start of an array of pixelInfo items. This will be sent to the chain in order.
    @param dataLen   The length of the array.
    */
    void setData(pixelInfo *dataStart, uint16_t dataLen);

    /** Set the data pointer

    Before data can be sent the driver must be given a pointer to the pixel data to use.
    Setting this is normally a one time operation unless you want to switch between buffers.
    Calling this function will replace any prior buffers including pixelInfo ones.
    
    @param dataStart The start of an array of pixelInfo16 items. This will be sent to the chain in order.
    @param dataLen   The length of the array.
    */
    void setData(pixelInfo16 *dataStart, uint16_t dataLen);


    /** Sends the data to the LEDs
    * setData() must be called prior to this.
    */
    void sendData();

private:

    void sendByte(unsigned char value);
    void sendPixel(pixelInfo *pixToSend);
    void sendPixel(pixelInfo16 *pixToSend);

    pixelInfo *pixArray;
    pixelInfo16 *pixArray16;
    uint16_t pixelLen;

};

#endif
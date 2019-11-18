/*
* ----------------------------------------------------------------------------
* (Revision 1):
* <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a coffee in return.
* -----------------------------------------------------------------------------
* Please define your platform specific functions in this file ...
* -----------------------------------------------------------------------------
*/
#include "Peripheral_Headers/F2802x_Device.h"

#define set_bit(reg,bit) reg |= (1<<bit)
#define clr_bit(reg,bit) reg &= ~(1<<bit)
#define check_bit(reg,bit) (reg&(1<<bit))

/* ------------------------------------------------------------------------- */

void nrf24_setupPins()
{
    GpioDataRegs.GPASET.bit.GPIO0 = 1; // CE output
    GpioDataRegs.GPASET.bit.GPIO1 = 1; // CSN output
    GpioDataRegs.GPASET.bit.GPIO2 = 1; // SCK output
    GpioDataRegs.GPASET.bit.GPIO3 = 1; // MOSI output
    //clr_bit(RF_DDR,4); // MISO input
}
/* ------------------------------------------------------------------------- */
void nrf24_ce_digitalWrite(uint8_t state) // GPIO-00
{
    if(state)
    {
        GpioDataRegs.GPASET.bit.GPIO0 = 1;
    }
    else
    {
        GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_csn_digitalWrite(uint8_t state) // GPIO-01
{
    if(state)
    {
        GpioDataRegs.GPASET.bit.GPIO1 = 1;
    }
    else
    {
        GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_sck_digitalWrite(uint8_t state) // GPIO-02
{
    if(state)
    {
        GpioDataRegs.GPASET.bit.GPIO2 = 1;
    }
    else
    {
        GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_mosi_digitalWrite(uint8_t state) // GPIO-03
{
    if(state)
    {
        GpioDataRegs.GPASET.bit.GPIO3 = 1;
    }
    else
    {
        GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;
    }
}
/* ------------------------------------------------------------------------- */
uint8_t nrf24_miso_digitalRead() // GPIO-04
{
    return GpioDataRegs.GPADAT.bit.GPIO4;
}
/* ------------------------------------------------------------------------- */

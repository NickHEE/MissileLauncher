//===============================================================
// FILE:   DeviceInit_18Nov2018.c
//
// DESC:   Peripheral Initialization for F2802x
// 
// Version:     1.2
//
// Modified by: DNR 18Nov2018 for use with SYS/BIOS
//===============================================================

#include "Peripheral_Headers/F2802x_Device.h"

void DeviceInit(void);

//---------------------------------------------------------------
//  Configure Device for target Application Here
//---------------------------------------------------------------
void DeviceInit(void)
{
   EALLOW; // temporarily unprotect registers

// LOW SPEED CLOCKS prescale register settings
   SysCtrlRegs.LOSPCP.all = 0x0002; // Sysclk / 4 (15 MHz)
   SysCtrlRegs.XCLK.bit.XCLKOUTDIV=2;
      	
// PERIPHERAL CLOCK ENABLES 
//---------------------------------------------------
// If you are not using a peripheral you may want to switch
// the clock off to save power, i.e., set to =0 
// 
// Note: not all peripherals are available on all 280x derivates.
// Refer to the datasheet for your particular device. 

   SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 0;    // ADC
   //------------------------------------------------
   SysCtrlRegs.PCLKCR3.bit.COMP1ENCLK = 0;	// COMP1
   SysCtrlRegs.PCLKCR3.bit.COMP2ENCLK = 0;	// COMP2
   //------------------------------------------------
   SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 0;   // I2C
   //------------------------------------------------
   SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 0;	// SPI-A
   //------------------------------------------------
   SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 0;  	// SCI-A
   //------------------------------------------------
   SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 0;	//eCAP1
   //------------------------------------------------
   SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 0;  // ePWM1
   SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 0;  // ePWM2
   SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 0;  // ePWM3
   SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 0;  // ePWM4
   //------------------------------------------------
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;   // Enable TBCLK
   //------------------------------------------------
                  
                                     
//---------------------------------------------------------------
// GPIO (GENERAL PURPOSE I/O) CONFIG
//---------------------------------------------------------------
//-----------------------
// QUICK NOTES on USAGE:
//-----------------------
// If GpioCtrlRegs.GP?MUX?bit.GPIO?= 1, 2, or 3 (i.e., Non GPIO func), then leave rest of lines commented
// If GpioCtrlRegs.GP?MUX?bit.GPIO?= 0 (i.e., GPIO func), then:
//	1) uncomment GpioCtrlRegs.GP?DIR.bit.GPIO? = ? and choose pin to be IN or OUT
//	2) If IN, can leave next two lines commented
//	3) If OUT, uncomment line with ..GPACLEAR.. to force pin LOW or
//       uncomment line with ..GPASET.. to force pin HIGH or
//---------------------------------------------------------------
//---------------------------------------------------------------
//  GPIO-00 - PIN FUNCTION = CE
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;     // 0=GPIO,  1=EPWM1A,  2=Resv,  3=Resv
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;      // 1=OUTput,  0=INput
//  GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;    // uncomment if --> Set Low initially
    GpioDataRegs.GPASET.bit.GPIO0 = 1;      // uncomment if --> Set High initially
//--------------------------------------------------------------------------------------
//  GPIO-01 - PIN FUNCTION = CSN
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;     // 0=GPIO,  1=EPWM1B,  2=EMU0,  3=COMP1OUT
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;      // 1=OUTput,  0=INput
//  GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;    // uncomment if --> Set Low initially
//  GpioDataRegs.GPASET.bit.GPIO1 = 1;      // uncomment if --> Set High initially
//--------------------------------------------------------------------------------------
//  GPIO-02 - PIN FUNCTION = SCK
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;     // 0=GPIO,  1=EPWM2A,  2=Resv,  3=Resv
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;      // 1=OUTput,  0=INput
//  GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;    // uncomment if --> Set Low initially
//  GpioDataRegs.GPASET.bit.GPIO2 = 1;      // uncomment if --> Set High initially
//--------------------------------------------------------------------------------------
//  GPIO-03 - PIN FUNCTION = MOSI
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;     // 0=GPIO,  1=EPWM2B,  2=Resv,  3=COMP2OUT
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;      // 1=OUTput,  0=INput
//  GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;    // uncomment if --> Set Low initially
//  GpioDataRegs.GPASET.bit.GPIO3 = 1;      // uncomment if --> Set High initially
//--------------------------------------------------------------------------------------
//  GPIO-04 - PIN FUNCTION = MSIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;     // 0=GPIO,  1=EPWM3A, 2=Resv,   3=Resv
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 0;      // 1=OUTput,  0=INput
//  GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;    // uncomment if --> Set Low initially
//  GpioDataRegs.GPASET.bit.GPIO4 = 1;      // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-05 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0; // 0=GPIO,  1=EPWM3B,  2=Resv,  3=ECAP1
	GpioCtrlRegs.GPADIR.bit.GPIO5 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO5 = 1; // uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO5 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-06 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0; // 0=GPIO,  1=EPWM4A,  2=SYNCI,  3=SYNCO
	GpioCtrlRegs.GPADIR.bit.GPIO6 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO6 = 1; // uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO6 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-07 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0; // 0=GPIO,  1=EPWM4B,  2=SCIRX-A,  3=Resv
	GpioCtrlRegs.GPADIR.bit.GPIO7 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO7 = 1; // uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO7 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-08 - GPIO-11 Do Not Exist
//---------------------------------------------------------------
//  GPIO-12 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0; // 0=GPIO,  1=TZ1,  2=SCITX-A,  3=Resv
	GpioCtrlRegs.GPADIR.bit.GPIO12 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO12 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-13 - GPIO-15 = Do Not Exist
//---------------------------------------------------------------
//---------------------------------------------------------------

//  GPIO-16 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 0; // 0=GPIO,  1=SPISIMO-A,  2=Resv,  3=TZ2
	GpioCtrlRegs.GPADIR.bit.GPIO16 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO16 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO16 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-17 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 0; // 0=GPIO,  1=SPISOMI-A,  2=Resv,  3=TZ3
	GpioCtrlRegs.GPADIR.bit.GPIO17 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO17 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO17 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-18 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0; // 0=GPIO,  1=SPICLK-A,  2=SCITX-A,  3=XCLKOUT
	GpioCtrlRegs.GPADIR.bit.GPIO18 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO18 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO18 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-19 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0; // 0=GPIO,  1=SPISTE-A,  2=SCIRX-A,  3=ECAP1
	GpioCtrlRegs.GPADIR.bit.GPIO19 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO19 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-20 - GPIO-27 = Do Not Exist
//---------------------------------------------------------------
//  GPIO-28 - PIN FUNCTION = --Spare-- (can connect to SCIRX on LaunchPad)
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 0; // 0=GPIO,  1=SCIRX-A,  2=I2C-SDA,  3=TZ2
//	GpioCtrlRegs.GPADIR.bit.GPIO28 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO28 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO28 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-29 - PIN FUNCTION = --Spare-- (can connect to SCITX on LaunchPad)
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0; // 0=GPIO,  1=SCITXD-A,  2=I2C-SCL,  3=TZ3
//	GpioCtrlRegs.GPADIR.bit.GPIO29 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPACLEAR.bit.GPIO29 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPASET.bit.GPIO29 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-30 - GPIO-31 = Do Not Exist
//---------------------------------------------------------------
//--------------------------------------------------------------

//  GPIO-32 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0; // 0=GPIO,  1=I2C-SDA,  2=SYNCI,  3=ADCSOCA
	GpioCtrlRegs.GPBDIR.bit.GPIO32 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPBSET.bit.GPIO32 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-33 - PIN FUNCTION = --Spare--
	GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0; // 0=GPIO,  1=I2C-SCL,  2=SYNCO,  3=ADCSOCB
	GpioCtrlRegs.GPBDIR.bit.GPIO33 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;	// uncomment if --> Set Low initially
//	GpioDataRegs.GPBSET.bit.GPIO33 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-34 - PIN FUNCTION = switch S1.1 on LaunchPad
	GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0; // 0=GPIO,  1=COMP2OUT,  2=EMU1,  3=Resv
	GpioCtrlRegs.GPBDIR.bit.GPIO34 = 0; // 1=OUTput,  0=INput 
//	GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1; // uncomment if --> Set Low initially
//	GpioDataRegs.GPBSET.bit.GPIO34 = 1; // uncomment if --> Set High initially
//---------------------------------------------------------------
//  GPIO-35 - GPIO-38 = Used for JTAG Port
//---------------------------------------------------------------
//---------------------------------------------------------------

	EDIS;	// restore protection of registers

} // end DeviceInit()

//===============================================================
// End of file
//===============================================================

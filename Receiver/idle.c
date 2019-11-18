/* 
 *  28x specific Idle example.
 *  
 *  This example:
 * 
 *  1) prints "Hello world" in main()
 *  
 *  2) prints the current value of a counter from
 *     within an Idle function each time an
 *     a timer interrupt goes off.
 * 
 *  All output is routed to a log buffer which can be viewed
 *  using the RTA "Raw Logs" viewer. After loading and running
 *  the application, launch the Tools->RTA->Raw Logs tool to
 *  view the logs.
 */
#define xdc__strict
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/BIOS.h>
#include "nrf24.h"

/* Flag used by idle function to check if interrupt occurred */
volatile Bool isrFlag = FALSE;

/* Counter incremented by timer interrupt */
volatile UInt tickCount = 0;

uint8_t temp;
uint8_t data_array[4];
uint8_t tx_address[5] = {0xE7,0xE7,0xE7,0xE7,0xE7};
uint8_t rx_address[5] = {0xD7,0xD7,0xD7,0xD7,0xD7};

void DeviceInit(void);

/*
 *  ======== main ========
 */
Int main()
{
    /*
     * Print "Hello world" to a log buffer. 
     */
    System_printf("Hello folks!\n");

    DeviceInit();

    /* init hardware pins */
    nrf24_init();

    /* Channel #2 , payload length: 4 */
    nrf24_config(2,4);

    /* Set the device addresses */
    nrf24_tx_address(tx_address);
    nrf24_rx_address(rx_address);

    BIOS_start();    /* does not return */
    return(0);
}

/*
 *  ======== myTickFxn ========
 *  Timer Tick function that increments a counter, and sets the isrFlag.
 */
Void myTickFxn(UArg arg) 
{
    data_array[0] = 0x00;
    data_array[1] = 0xAA;
    data_array[2] = 0x55;
    data_array[3] = tickCount++;

    nrf24_send(data_array);

    isrFlag = TRUE;    /* tell background that new data is available */

    /* Wait for transmission to end */
    while(nrf24_isSending());

    /* Make analysis on last transmission attempt */
    temp = nrf24_lastMessageStatus();

    if(temp == NRF24_TRANSMISSON_OK)
    {
        System_printf("> Transmission went OK\r\n");
    }
    else if(temp == NRF24_MESSAGE_LOST)
    {
        System_printf("> Message is lost ...\r\n");
    }

    isrFlag = TRUE;    /* tell background that new data is available */
}

/*
 *  ======== myIdleFxn ========
 *  Background idle function that is called repeatedly 
 *  from within BIOS_start() thread.
 */
Void myIdleFxn(Void) 
{
    if (isrFlag == TRUE) {
        isrFlag = FALSE;
        /*
         * Print the current value of tickCount to a log buffer. 
         */
        System_printf("Tick Count = %d\n", tickCount);
    }
}

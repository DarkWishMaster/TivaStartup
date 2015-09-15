/*
 * main.c
 *
 *  Created on: Sep 15, 2015
 *      Author: Vlad
 */

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"


int main(void) {

	ROM_FPULazyStackingEnable();

	// Setup the system clock to run at 50 Mhz from PLL with crystal reference
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_20|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|
					SYSCTL_OSC_MAIN);

	/* Enable all GPIO Peripherals */
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2);

	while (1) {
		ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2, GPIO_PIN_1);
		SysCtlDelay(SysCtlClockGet()/6);
		ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2, GPIO_PIN_2);
		SysCtlDelay(SysCtlClockGet()/6);
		ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2, GPIO_PIN_1 | GPIO_PIN_2);
		SysCtlDelay(SysCtlClockGet()/6);
	}

	return 0;
}

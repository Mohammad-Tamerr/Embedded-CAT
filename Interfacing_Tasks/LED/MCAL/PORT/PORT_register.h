/*
 * PORT_register.h
 *
 *  Created on: Apr 23, 2024
 *      Author: Mohammad Tamer
 */

#ifndef MCAL_PORT_PORT_REGISTER_H_
#define MCAL_PORT_PORT_REGISTER_H_

#define DDR_A   *((volatile u8*)0x3A)
#define DDR_B   *((volatile u8*)0x37)
#define DDR_C   *((volatile u8*)0x34)
#define DDR_D   *((volatile u8*)0x31)

#define PORT_A  *((volatile u8*)0x3B)
#define PORT_B  *((volatile u8*)0x38)
#define PORT_C  *((volatile u8*)0x35)
#define PORT_D  *((volatile u8*)0x32)


#endif /* MCAL_PORT_PORT_REGISTER_H_ */

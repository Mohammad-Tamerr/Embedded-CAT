/*****************************************
 * ADC_register.h
 *
 *  	Created on: Jul 1, 2024
 *  	Author: Mohammad Tamer
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_

/*ADC multiplexer selection register*/
#define ADMUX               *((volatile u8 *) 0x27) //Register address
#define ADCMUX_REFS1        7                       //reference selection bit1
#define ADCMUX_REFS0        6                       //reference selection bit0
#define ADCMUX_ADLAR        5                       //ADC left adjust result
#define ADCMUX_MUX4         4                       //Channel selection bit4
#define ADCMUX_MUX3         3                       //Channel selection bit3
#define ADCMUX_MUX2         2                       //Channel selection bit2
#define ADCMUX_MUX1         1                       //Channel selection bit1
#define ADCMUX_MUX0         0                       //Channel selection bit0

/*ADC control and status PORTA */
#define ADCSRA              *((volatile u8*) 0x26)  //Register address
#define ADCSRA_ADEN         7                       //ADC enable
#define ADCSRA_ADSC         6                       //ADC start conversion
#define ADCSRA_ADATE        5                       //ADC auto trigger enable
#define ADCSRA_ADIF         4                       // ADC interrupt flag
#define ADCSRA_ADIE         3                       //ADC interrupt enable
#define ADCSRA_ADPS2        2                       //prescaler bit2
#define ADCSRA_ADPS1        1                       //prescaler bit1
#define ADCSRA_ADPS0        0                       //prescaler bit0

/*ADC High register*/
#define ADCH            *((volatile u8 *) 0x25)

/*ADC Low register*/
#define ADCL            *((volatile u8 *) 0x24)
#define ADC				*((volatile u16 *)0x24)

/*Special Function I/O Register*/
#define SFIOR			*((volatile u8 *) 0x50) 	//Register address
#define SFIOR_ADTS2		7							//ADC Auto Trigger Source bit2
#define SFIOR_ADTS1		6							//ADC Auto Trigger Source bit1
#define SFIOR_ADTS0		5							//ADC Auto Trigger Source bit0



#endif /* MCAL_ADC_ADC_REGISTER_H_ */

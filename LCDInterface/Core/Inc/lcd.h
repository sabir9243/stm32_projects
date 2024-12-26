/*
 * lcd.h
 *
 *  Created on: Dec 23, 2024
 *      Author: sabir
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "main.h"
void LCD_EnablePulse(void);
void LCD_Write4Bits(char data);
void LCD_Write(char c,int cD);
void LCD_Init(void);
void LCD_WriteString(char *string);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Clear();

#endif /* INC_LCD_H_ */

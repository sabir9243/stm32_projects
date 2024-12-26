#include "lcd.h"
void LCD_Clear(){
	LCD_Write(0x01, 0);
	HAL_Delay(10);
}
void LCD_Write(char c,int cD){
	if(cD==0){
		HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
	}
	else {
		HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
	}

	HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);
//send a pulse

	LCD_Write4Bits(c>>4);
	LCD_Write4Bits(c&0x0F);

}

void LCD_Write4Bits(char data) {
    HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data >> 0) & 0x01);
    HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data >> 1) & 0x01);
    HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data >> 2) & 0x01);
    HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data >> 3) & 0x01);
    LCD_EnablePulse();
}

// Generate Enable Pulse (to latch data)
void LCD_EnablePulse(void) {
    HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
    HAL_Delay(1);  // Delay for pulse
    HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
    HAL_Delay(1);
}

void LCD_Init(){
	LCD_Write(0x02,0);
	LCD_Write(0x28,0);
	LCD_Write(0x0F,0);
	LCD_Write(0x01,0);
	LCD_Write(0x06,0);

	HAL_Delay(10);
}

void LCD_WriteString(char *string){
	char *ptr=string;
	while((*ptr)!='\0'){
		LCD_Write(*(ptr),1);
		ptr++;
	}
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    uint8_t address = (row == 0) ? 0x80 : 0xC0;
    address += col;
    LCD_Write(address,0);
}

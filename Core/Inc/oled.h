#ifndef OLED_H
#define OLED_H

#include <string.h>
#include<stdint.h>
#include "stm32f1xx_hal.h"

#define WIDTH 128
#define HEIGHT 64
#define WIRE_MAX 32
#define heigh 8
#define width 8
#define TW_START 0x08 // start
#define  TW_REP_START  0x10    // repeat start
#define  TW_MT_SLA_ACK 0x18   // truyen slave addr de ghi co ack
#define  TW_MT_SLA_NACK 0x20 //  truyen slave addr de ghi  ko co ack
#define  TW_MR_SLA_ACK 0x40   // truyen slave addr de doc co ack
#define  TW_MT_DATA_ACK 0x28 // gui dl co ack
#define  TW_MT_DATA_NACK 0x30  // nhan dl khong co ack
#define SSD1306_COLUMNADDR          0x21 ///< See datasheet
#define SSD1306_PAGEADDR            0x22        ///< See datasheet
#define BUFF_SIZE WIDTH*HEIGHT/8



#define addr_oled 0x78
#define MESS_SIZE 32

void initOLED(I2C_HandleTypeDef *i2cInstance);
void drawChar(int16_t x, int16_t y, unsigned char c);
void drawChars(uint8_t *x, uint8_t *y, char *mess);
void drawBitmap(int x, int y, unsigned char bitmap[], int w, int h);
void drawImage(unsigned char bitmap[], int LOGO_HEIGHT, int LOGO_WIDTH);
void clearDisplay();
void test(int x, int y);
#endif

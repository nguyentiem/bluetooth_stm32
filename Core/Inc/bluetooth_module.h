/*
 * bluetooth_module.h
 *
 *  Created on: Jun 9, 2024
 *      Author: nguye
 */

#ifndef INC_BLUETOOTH_MODULE_H_
#define INC_BLUETOOTH_MODULE_H_
#include <stdint.h>

typedef enum coming_message_state{
  MSG_START_BYTE,
  MSG_TYPE_BYTE,
  MSG_LENG_BYTE,
  MSG_DATA_BYTE,
  MSG_CRC_BYTE,
};
void receive_byte_handle(uint8_t coming_byte);
void transfer_bytes_handle();
void transfer_byte_callback();


#endif /* INC_BLUETOOTH_MODULE_H_ */

/*
 * tlv.h
 *
 *  Created on: Jun 9, 2024
 *      Author: nguye
 */

#ifndef INC_TLV_H_
#define INC_TLV_H_

#define START_BYTE 0xAA

typedef void (*callback)(void*param);

struct tlv{
	uint8_t type;
	uint8_t length;
	uint8_t *data;
}tlv;


struct action{
	uint8_t type;
	union {
		callback onDone;
		callback onFail;
		callback onTimeOut;
	};
};

typedef enum tlv_t{
	NO_TYPE,
	LIST_CMD,
	CMD_OPEN,
	CMD_CLOSE,
	CMD_PARTICIAL,
	CMD_DP_STRING,
	CMD_DP_IMAGE,
	
	CMD_END_TYPE,

};
#endif /* INC_TLV_H_ */

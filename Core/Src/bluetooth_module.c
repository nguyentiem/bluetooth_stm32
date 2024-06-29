/*
 * bluetooth_module.c
 *
 *  Created on: Jun 9, 2024
 *      Author: nguye
 */
#include "queue.h"
#include <stdint.h>
#include "tlv.h"
#include"bluetooth_module.h"

static queue tx_queue;
static queue rx_queue;

static volatile uint8_t state_command;
static volatile uint8_t lenth_cmd;
static volatile uint8_t crc;
static volatile uint8_t queue_idx;

void bt_init()
{
    queue_init(&tx_queue);
    queue_init(&rx_queue);
    crc = 0xFF;
    lenth_cmd = 0;
    state_command = MSG_START_BYTE;
}

static void get_phase_command(uint8_t coming_byte)
{
    switch (coming_byte)
    {
    case MSG_START_BYTE:
        queue_idx = rx_queue.tail;
        if (coming_byte == START_BYTE)
        {

            queue_push(&rx_queue, coming_byte);
            state_command = MSG_TYPE_BYTE;
            crc = 0xff ^ coming_byte;
        }
        else
        {
            printf("Error start byte\n");
            state_command = MSG_START_BYTE;
            queue_reset_push(&rx_queue, queue_idx);
        }
        break;

    case MSG_TYPE_BYTE:
        if (coming_byte <= NO_TYPE || coming_byte >= CMD_END_TYPE)
        {
            printf("Error type byte\n");
            state_command = MSG_START_BYTE;
            queue_reset_push(&rx_queue, queue_idx);
        }
        else
        {
            queue_push(&rx_queue, coming_byte);
            state_command = MSG_LENG_BYTE;
            crc ^= coming_byte;
        }
        break;

    case MSG_LENG_BYTE:
        if (coming_byte < 0 || coming_byte >= 255)
        {
            printf("Error length byte\n");
            state_command = MSG_START_BYTE;
            queue_reset_push(&rx_queue, queue_idx);
        }
        else
        {
            queue_push(&rx_queue, coming_byte);
            state_command = MSG_DATA_BYTE;
            lenth_cmd = coming_byte;
            crc ^= coming_byte;
            if (lenth_cmd == 0)
            {
                state_command = MSG_CRC_BYTE;
            }
        }
        break;

    case MSG_DATA_BYTE:
        if (lenth_cmd > 0)
        {
            queue_push(&rx_queue, coming_byte);
            lenth_cmd = coming_byte;
            crc ^= coming_byte;
            lenth_cmd--;
            if (lenth_cmd == 0)
            {
                state_command = MSG_CRC_BYTE;
            }
        }
        break;

    case MSG_CRC_BYTE:
        if (crc == coming_byte)
        {
            queue_push(&rx_queue, coming_byte);
            state_command = MSG_START_BYTE;
            // trigger handle task
        }
        else
        {
            printf("Error crc byte\n");
            state_command = MSG_START_BYTE;
            queue_reset_push(&rx_queue, queue_idx);
        }
        break;

    default:
        break;
    }
}

void receive_byte_handle(uint8_t byte)
{
   get_phase_command(byte);
}

void transfer_bytes_handle(){

}

void transfer_byte_callback(){

}

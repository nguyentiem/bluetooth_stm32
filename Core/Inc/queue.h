/*
 * queue.h
 *
 *  Created on: Jun 9, 2024
 *      Author: nguye
 */
#include<stdint.h>
#include <stdbool.h>
#define QUEUE_MAX_SIZE 255

typedef struct queue{
	volatile uint8_t head;
	volatile uint8_t tail;
	volatile uint8_t data[QUEUE_MAX_SIZE];
}queue;

void queue_init(queue * mQueue);

bool queue_pop(queue * mQueue, uint8_t *value);

bool queue_push(queue * mQueue, uint8_t value);

bool queue_push_arr(queue * mQueue, uint8_t *value, uint8_t len);

bool queue_peek(queue * mQueue, uint8_t *value);

bool queue_is_full(queue * mQueue);

bool queue_is_empty(queue * mQueue);

uint8_t queue_get_space(queue * mQueue);

bool queue_reset_push(queue *mQueue, uint8_t idx);

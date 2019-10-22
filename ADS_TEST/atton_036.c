#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "heap.h"
#include <stdio.h>


static void _swap_(int32_t *data1, int32_t *data2) {
	int32_t temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

static int32_t conversion(int32_t time_stamp[])
{
	time_stamp=0;
	if(time_stamp<0630 && time_stamp>1130)
	{
		time_stamp+=10;
	}
	else
	{
		initial=1130;
		actual=(time_stamp%10);
		time_stamp=actual
		
	}
	return time_stamp;

}


static void _heapify_ (int32_t time_stamp[];, uint32_t len, uint32_t parent) {
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (time_stamp[child+1] < time_stamp[child]){
				++child;
			}
		}
		if (time_stamp[parent] <= time_stamp[child]) {
			break;
		}
		_swap_(&time_stamp[parent], &time_stamp[child]);
		parent = child;
		child = 2 * parent;
	}
}

static void _test_heap_(int32_t time_stamp[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(time_stamp[child] <= time_stamp[child/2]);
	}

}

Heap*	heap_test(Heap *heap)
{
	_test_heap_(heap->data, heap->size);
}



Heap 	heap_new(int32_t time_stamp[], uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	Heap heap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(data, len, idx);
	}
	heap.size = len;
	memcpy(heap.time_stamp, time_stamp, (len+1) * sizeof(int32_t));
	_test_heap_(heap.time_stamp, heap.size);

	return heap;
}



Heap*	heap_sort(Heap *heap) {
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	uint32_t idx = heap->size;

	for (idx = heap->size; idx > 1; idx--) {
		_swap_(&heap->time_stamp[idx], &heap->time_stamp[1]);
		_heapify_(heap->time_stamp, idx-1, 1);
	}

	return heap;
}


Heap*	heap_insert(Heap *heap, int32_t key)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);

	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;

	while ( loc > 1 && heap->time_stamp[parent] < key) {
		heap->time_stamp[loc] = heap->time_stamp[parent];
		loc = parent;
		parent = parent/2;
	}
	heap->time_stamp[loc] = key;
	return heap;

}

int32_t		heap_get_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->data[1];

}

int32_t		heap_extract_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	int32_t max = heap->data[1];	
	_swap_(&heap->data[1], &heap->data[heap->size]);
	--heap->size;
	_heapify_(heap->data, heap->size, 1);

	return max;
}

uint32_t	heap_size(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}


void display_heap(Heap *heap,int32_t len)
{
    int32_t i;
    for(i=0;i<len;i++)
    {
        printf("%d\t",heap->data[i]);
    }
}


#ifndef __READ_CACHE_H__
#define __READ_CACHE_H__

// includes
#include "common.h"

// constants
#define CACHED_BUFFERS (2)

// typedefs
typedef struct {
	u_char* buffer;
	uint32_t buffer_size;
	uint64_t start_offset;
	uint64_t end_offset;
} cache_buffer_t;

typedef struct {
	request_context_t* request_context;
	cache_buffer_t buffers[CACHED_BUFFERS];
	cache_buffer_t* target_buffer;
	size_t buffer_size;
	size_t alignment;
} read_cache_state_t;

// functions
void read_cache_init(
	read_cache_state_t* state, 
	request_context_t* request_context, 
	size_t buffer_size, 
	size_t alignment);
	
bool_t read_cache_get_from_cache(
	read_cache_state_t* state, 
	int cache_slot_id, 
	uint64_t offset, 
	u_char** buffer, 
	uint32_t* size);
	
vod_status_t read_cache_get_read_buffer(
	read_cache_state_t* state, 
	uint64_t offset, 
	uint64_t* out_offset, 
	u_char** buffer, 
	uint32_t* size);
	
void read_cache_read_completed(
	read_cache_state_t* state, 
	ssize_t bytes_read);

#endif // __READ_CACHE_H__
#ifndef _PRIVATE_VALUES_H_
#define _PRIVATE_VALUES_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BP__KV_HEADER_SIZE 24
#define BP__KV_SIZE(kv)  BP__KV_HEADER_SIZE + kv.length
#define BP__STOVAL(str, key)		\
	key.value = (char *) str;           \
	key.length = strlen(str) + 1;

typedef struct bp__kv_s bp__kv_t;


int bp__value_load(bp_db_t *t,
				   const uint64_t offset,
				   const uint64_t length,
				   bp_value_t *value);
int bp__value_save(bp_db_t *t,
				   const bp_value_t *value,
				   const bp__kv_t *previous,
				   uint64_t *offset,
				   uint64_t *length);

int bp__kv_copy(const bp__kv_t *source, bp__kv_t *target, int alloc);

struct bp__kv_s {
	BP_KEY_FIELDS

	uint64_t offset;
	uint64_t config;

	uint8_t allocated;
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _PRIVATE_VALUES_H_ */

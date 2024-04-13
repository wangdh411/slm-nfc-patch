#ifndef __SLM_DFU__
#define __SLM_DFU__

#ifdef __cplusplus
extern "C" {
#endif

#include <hardware/nfc.h>

typedef int8_t (*pfn_init)(int8_t *);
typedef int8_t (*pfn_get_chip)(void);
typedef int8_t (*pfn_get_conf)(uint8_t, uint8_t *, uint32_t, uint32_t *);
typedef int8_t (*pfn_event_cb) (uint8_t, uint8_t);
typedef int8_t (*pfn_data_cb) (uint16_t, uint8_t*);

typedef struct {
    pfn_init pfn_slm_init;
    pfn_get_chip pfn_slm_get_chip;
    pfn_get_conf pfn_slm_get_config;
    pfn_event_cb pfn_slm_event_cb;
    pfn_data_cb pfn_slm_data_cb;
}st_slm_nfc_t;


extern st_slm_nfc_t slm_nfc;

extern void slm_nfc_dl_init(nfc_stack_callback_t *evt_cb, nfc_stack_data_callback_t *data_cb);

#ifdef __cplusplus
}
#endif

#endif


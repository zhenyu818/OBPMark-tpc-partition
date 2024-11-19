#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wcast-qual"
#define __NV_CUBIN_HANDLE_STORAGE__ static
#if !defined(__CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__)
#define __CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__
#endif
#include "crt/host_runtime.h"
#include "processing.fatbin.c"
extern void __device_stub__Z16AES_KeyExpansionP12AES_values_t(struct AES_values_t *);
extern void __device_stub__Z26AES_KeyExpansion_RedundantP12AES_values_t(struct AES_values_t *);
extern void __device_stub__Z11AES_encryptP12AES_values_t(struct AES_values_t *);
extern void __device_stub__Z21AES_encrypt_Redundantv(void);
static void __nv_cudaEntityRegisterCallback(void **);
static void __sti____cudaRegisterAll(void) __attribute__((__constructor__));
void __device_stub__Z16AES_KeyExpansionP12AES_values_t(struct AES_values_t *__par0){__cudaLaunchPrologue(1);__cudaSetupArgSimple(__par0, 0UL);__cudaLaunch(((char *)((void ( *)(struct AES_values_t *))AES_KeyExpansion)));}
# 48 "src/ports/cuda/processing.cu"
void AES_KeyExpansion( struct AES_values_t *__cuda_0)
# 49 "src/ports/cuda/processing.cu"
{__device_stub__Z16AES_KeyExpansionP12AES_values_t( __cuda_0);
# 70 "src/ports/cuda/processing.cu"
}
# 1 "processing.cudafe1.stub.c"
void __device_stub__Z26AES_KeyExpansion_RedundantP12AES_values_t( struct AES_values_t *__par0) {  __cudaLaunchPrologue(1); __cudaSetupArgSimple(__par0, 0UL); __cudaLaunch(((char *)((void ( *)(struct AES_values_t *))AES_KeyExpansion_Redundant))); }
# 72 "src/ports/cuda/processing.cu"
void AES_KeyExpansion_Redundant( struct AES_values_t *__cuda_0)
# 73 "src/ports/cuda/processing.cu"
{__device_stub__Z26AES_KeyExpansion_RedundantP12AES_values_t( __cuda_0);
# 94 "src/ports/cuda/processing.cu"
}
# 1 "processing.cudafe1.stub.c"
void __device_stub__Z11AES_encryptP12AES_values_t( struct AES_values_t *__par0) {  __cudaLaunchPrologue(1); __cudaSetupArgSimple(__par0, 0UL); __cudaLaunch(((char *)((void ( *)(struct AES_values_t *))AES_encrypt))); }
# 264 "src/ports/cuda/processing.cu"
void AES_encrypt( struct AES_values_t *__cuda_0)
# 265 "src/ports/cuda/processing.cu"
{__device_stub__Z11AES_encryptP12AES_values_t( __cuda_0);
# 289 "src/ports/cuda/processing.cu"
}
# 1 "processing.cudafe1.stub.c"
void __device_stub__Z21AES_encrypt_Redundantv(void) {  __cudaLaunchPrologue(1); __cudaLaunch(((char *)((void ( *)(void))AES_encrypt_Redundant))); }
# 291 "src/ports/cuda/processing.cu"
void AES_encrypt_Redundant(void)
# 292 "src/ports/cuda/processing.cu"
{__device_stub__Z21AES_encrypt_Redundantv();




}
# 1 "processing.cudafe1.stub.c"
static void __nv_cudaEntityRegisterCallback( void **__T0) {  __nv_dummy_param_ref(__T0); __nv_save_fatbinhandle_for_managed_rt(__T0); __cudaRegisterEntry(__T0, ((void ( *)(void))AES_encrypt_Redundant), _Z21AES_encrypt_Redundantv, (-1)); __cudaRegisterEntry(__T0, ((void ( *)(struct AES_values_t *))AES_encrypt), _Z11AES_encryptP12AES_values_t, (-1)); __cudaRegisterEntry(__T0, ((void ( *)(struct AES_values_t *))AES_KeyExpansion_Redundant), _Z26AES_KeyExpansion_RedundantP12AES_values_t, (-1)); __cudaRegisterEntry(__T0, ((void ( *)(struct AES_values_t *))AES_KeyExpansion), _Z16AES_KeyExpansionP12AES_values_t, (-1)); }
static void __sti____cudaRegisterAll(void) {  __cudaRegisterBinary(__nv_cudaEntityRegisterCallback);  }

#pragma GCC diagnostic pop

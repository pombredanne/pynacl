#ifndef crypto_stream_salsa20_H
#define crypto_stream_salsa20_H

/*
 *  WARNING: This is just a stream cipher. It is NOT authenticated encryption.
 *  While it provides some protection against eavesdropping, it does NOT
 *  provide any security against active attacks.
 *  Unless you know what you're doing, what you are looking for is probably
 *  the crypto_box functions.
 */

#if 1
# ifndef SODIUM_HAVE_AMD64_ASM
#  define SODIUM_HAVE_AMD64_ASM
# endif
#endif

#include "export.h"

#define crypto_stream_salsa20_KEYBYTES 32U
#define crypto_stream_salsa20_NONCEBYTES 8U

#ifdef __cplusplus
extern "C" {
#endif

SODIUM_EXPORT
int crypto_stream_salsa20(unsigned char *,unsigned long long,const unsigned char *,const unsigned char *);

SODIUM_EXPORT
int crypto_stream_salsa20_xor(unsigned char *,const unsigned char *,unsigned long long,const unsigned char *,const unsigned char *);

#ifdef SODIUM_HAVE_AMD64_ASM
# define crypto_stream_salsa20_amd64_xmm6 crypto_stream_salsa20
# define crypto_stream_salsa20_amd64_xmm6_xor crypto_stream_salsa20_xor
#else
# define crypto_stream_salsa20_ref crypto_stream_salsa20
# define crypto_stream_salsa20_ref_xor crypto_stream_salsa20_xor
#endif

#ifdef __cplusplus
}
#endif

#endif

// SPDX-License-Identifier: 0BSD
// Copyright (C) 2022 Ayman El Didi
#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inlines all #includes which use quotation marks ("") ignoring includes which
// use angle brackets (<>). Given a filename without an extension, outputs an
// amalgamated .c and .h file.
//
// All includes are relative to the file being amalgamated.

#define MAX(x, y) ((x) > (y) ? (x) : (y))

static const char* c_files[] = {
		"bn_cutoffs.c",
		"bn_deprecated.c",
		"bn_mp_2expt.c",
		"bn_mp_abs.c",
		"bn_mp_add.c",
		"bn_mp_add_d.c",
		"bn_mp_addmod.c",
		"bn_mp_and.c",
		"bn_mp_clamp.c",
		"bn_mp_clear.c",
		"bn_mp_clear_multi.c",
		"bn_mp_cmp.c",
		"bn_mp_cmp_d.c",
		"bn_mp_cmp_mag.c",
		"bn_mp_cnt_lsb.c",
		"bn_mp_complement.c",
		"bn_mp_copy.c",
		"bn_mp_count_bits.c",
		"bn_mp_decr.c",
		"bn_mp_div.c",
		"bn_mp_div_2.c",
		"bn_mp_div_2d.c",
		"bn_mp_div_3.c",
		"bn_mp_div_d.c",
		"bn_mp_dr_is_modulus.c",
		"bn_mp_dr_reduce.c",
		"bn_mp_dr_setup.c",
		"bn_mp_error_to_string.c",
		"bn_mp_exch.c",
		"bn_mp_expt_u32.c",
		"bn_mp_exptmod.c",
		"bn_mp_exteuclid.c",
		"bn_mp_fread.c",
		"bn_mp_from_sbin.c",
		"bn_mp_from_ubin.c",
		"bn_mp_fwrite.c",
		"bn_mp_gcd.c",
		"bn_mp_get_double.c",
		"bn_mp_get_i32.c",
		"bn_mp_get_i64.c",
		"bn_mp_get_l.c",
		"bn_mp_get_ll.c",
		"bn_mp_get_mag_u32.c",
		"bn_mp_get_mag_u64.c",
		"bn_mp_get_mag_ul.c",
		"bn_mp_get_mag_ull.c",
		"bn_mp_grow.c",
		"bn_mp_incr.c",
		"bn_mp_init.c",
		"bn_mp_init_copy.c",
		"bn_mp_init_i32.c",
		"bn_mp_init_i64.c",
		"bn_mp_init_l.c",
		"bn_mp_init_ll.c",
		"bn_mp_init_multi.c",
		"bn_mp_init_set.c",
		"bn_mp_init_size.c",
		"bn_mp_init_u32.c",
		"bn_mp_init_u64.c",
		"bn_mp_init_ul.c",
		"bn_mp_init_ull.c",
		"bn_mp_invmod.c",
		"bn_mp_is_square.c",
		"bn_mp_iseven.c",
		"bn_mp_isodd.c",
		"bn_mp_kronecker.c",
		"bn_mp_lcm.c",
		"bn_mp_log_u32.c",
		"bn_mp_lshd.c",
		"bn_mp_mod.c",
		"bn_mp_mod_2d.c",
		"bn_mp_mod_d.c",
		"bn_mp_montgomery_calc_normalization.c",
		"bn_mp_montgomery_reduce.c",
		"bn_mp_montgomery_setup.c",
		"bn_mp_mul.c",
		"bn_mp_mul_2.c",
		"bn_mp_mul_2d.c",
		"bn_mp_mul_d.c",
		"bn_mp_mulmod.c",
		"bn_mp_neg.c",
		"bn_mp_or.c",
		"bn_mp_pack.c",
		"bn_mp_pack_count.c",
		"bn_mp_prime_fermat.c",
		"bn_mp_prime_frobenius_underwood.c",
		"bn_mp_prime_is_prime.c",
		"bn_mp_prime_miller_rabin.c",
		"bn_mp_prime_next_prime.c",
		"bn_mp_prime_rabin_miller_trials.c",
		"bn_mp_prime_rand.c",
		"bn_mp_prime_strong_lucas_selfridge.c",
		"bn_mp_radix_size.c",
		"bn_mp_radix_smap.c",
		"bn_mp_rand.c",
		"bn_mp_read_radix.c",
		"bn_mp_reduce.c",
		"bn_mp_reduce_2k.c",
		"bn_mp_reduce_2k_l.c",
		"bn_mp_reduce_2k_setup.c",
		"bn_mp_reduce_2k_setup_l.c",
		"bn_mp_reduce_is_2k.c",
		"bn_mp_reduce_is_2k_l.c",
		"bn_mp_reduce_setup.c",
		"bn_mp_root_u32.c",
		"bn_mp_rshd.c",
		"bn_mp_sbin_size.c",
		"bn_mp_set.c",
		"bn_mp_set_double.c",
		"bn_mp_set_i32.c",
		"bn_mp_set_i64.c",
		"bn_mp_set_l.c",
		"bn_mp_set_ll.c",
		"bn_mp_set_u32.c",
		"bn_mp_set_u64.c",
		"bn_mp_set_ul.c",
		"bn_mp_set_ull.c",
		"bn_mp_shrink.c",
		"bn_mp_signed_rsh.c",
		"bn_mp_sqr.c",
		"bn_mp_sqrmod.c",
		"bn_mp_sqrt.c",
		"bn_mp_sqrtmod_prime.c",
		"bn_mp_sub.c",
		"bn_mp_sub_d.c",
		"bn_mp_submod.c",
		"bn_mp_to_radix.c",
		"bn_mp_to_sbin.c",
		"bn_mp_to_ubin.c",
		"bn_mp_ubin_size.c",
		"bn_mp_unpack.c",
		"bn_mp_xor.c",
		"bn_mp_zero.c",
		"bn_prime_tab.c",
		"bn_s_mp_add.c",
		"bn_s_mp_balance_mul.c",
		"bn_s_mp_exptmod.c",
		"bn_s_mp_exptmod_fast.c",
		"bn_s_mp_get_bit.c",
		"bn_s_mp_invmod_fast.c",
		"bn_s_mp_invmod_slow.c",
		"bn_s_mp_karatsuba_mul.c",
		"bn_s_mp_karatsuba_sqr.c",
		"bn_s_mp_montgomery_reduce_fast.c",
		"bn_s_mp_mul_digs.c",
		"bn_s_mp_mul_digs_fast.c",
		"bn_s_mp_mul_high_digs.c",
		"bn_s_mp_mul_high_digs_fast.c",
		"bn_s_mp_prime_is_divisible.c",
		"bn_s_mp_rand_jenkins.c",
		"bn_s_mp_rand_platform.c",
		"bn_s_mp_reverse.c",
		"bn_s_mp_sqr.c",
		"bn_s_mp_sqr_fast.c",
		"bn_s_mp_sub.c",
		"bn_s_mp_toom_mul.c",
		"bn_s_mp_toom_sqr.c",
};
#define NUM_C_FILES (sizeof(c_files) / sizeof(*c_files))

#define FNV_64_PRIME   UINT64_C(0x100000001b3)
#define FNV_64_INITIAL UINT64_C(0xcbf29ce484222325)

uint64_t
fnv_1a(const size_t buf_len, const uint8_t* buf)
{
	uint64_t hash = FNV_64_INITIAL;

	for (size_t i = 0; i < buf_len; i += 1) {
		hash = (hash ^ buf[i]) * FNV_64_PRIME;
	}

	return hash;
}

static char*
vformat(const char* fmt, va_list args)
{
	// The v*printf functions destroy the va_list after use.
	// So I have to copy the va_list for the second call or we segfault.
	va_list ap;
	va_copy(ap, args);
	int len = vsnprintf(NULL, 0, fmt, args);
	if (len < 0 || len == INT_MAX) {
		return NULL;
	}

	char* result = calloc(len + 1, 1);
	if (result == NULL) {
		return NULL;
	}

	(void)vsnprintf(result, len + 1, fmt, ap);
	va_end(ap);
	return result;
}

static char*
format(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	char* result = vformat(fmt, ap);
	va_end(ap);
	return result;
}

static uint8_t*
readfull(char* filename)
{
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	uint8_t* result = calloc(2, 1);
	if (result == NULL) {
		fclose(f);
		return result;
	}

	int    c = 0;
	size_t i = 0;
	for (;;) {
		c = fgetc(f);
		if (c == EOF) {
			break;
		}
		result[i]     = c & 0xff;
		result[i + 1] = '\0';
		i += 1;
		void* ptr = realloc(result, i + 2);
		if (ptr == NULL) {
			free(result);
			fclose(f);
			return NULL;
		}
		result = ptr;
	}

	fclose(f);
	return result;
}

#define MAX_INCLUDES 1000

bool
file_has_been_included(const size_t str_len, const char* str,
		const size_t hashes_len, const uint64_t* hashes)
{
	uint64_t hash = fnv_1a(str_len, (uint8_t*)str);
	for (size_t i = 0; i < hashes_len; i += 1) {
		if (hash == hashes[i]) {
			return true;
		}
	}

	return false;
}

// Amalgamates file in dir into f, using pool to check if a file has already
// been included.
void
amalgamate_file(const char* dir, const char* file, FILE* f, size_t* hashes_len,
		uint64_t* hashes)
{
	char* filename = format("%s/%s", dir, file);
	assert(filename != NULL);
	char* content = (char*)readfull(filename);
	assert(content != NULL);
	free(filename);

	char* prev = content;
	char* ptr  = content;
	while ((ptr = strstr(ptr, "#include \"")) != NULL) {
		(void)fprintf(f, "%.*s", (int)(ptr - prev), prev);
		ptr += strlen("#include \"");

		char* closing_quote = strchr(ptr, '"');
		assert(closing_quote != NULL);

		size_t include_len = closing_quote - ptr;
		if (file_has_been_included(
				    include_len, ptr, *hashes_len, hashes)) {
			prev = closing_quote + 2;
			continue;
		}

		assert(*hashes_len + 1 < MAX_INCLUDES);
		hashes[*hashes_len] = fnv_1a(include_len, (uint8_t*)ptr);
		*hashes_len += 1;

		char* fname = format("%.*s", closing_quote - ptr, ptr);
		assert(fname != NULL);
		amalgamate_file(dir, fname, f, hashes_len, hashes);
		free(fname);

		prev = closing_quote + 2;
	}

	(void)fprintf(f, "%s", prev);
	free(content);
}

int
main(int argc, char** argv)
{
	if (argc != 2) {
		(void)fprintf(stderr,
				"usage: %s [src directory]\n"
				"Amalgamates tommath.c and tommath.h given "
				"the source directory.\n"
				"All includes are resolved relative to the "
				"directory given.\n",
				argv[0]);
		return EXIT_FAILURE;
	}

	FILE* f = fopen("tommath.c", "w");
	assert(f != NULL);

	static uint64_t include_hashes[MAX_INCLUDES];
	size_t          include_hashes_len = 0;

	for (size_t i = 0; i < NUM_C_FILES; i += 1) {
		amalgamate_file(argv[1], c_files[i], f, &include_hashes_len,
				include_hashes);
	}

	fclose(f);

	f = fopen("tommath.h", "w");
	assert(f != NULL);

	include_hashes_len = 0;
	amalgamate_file(argv[1], "tommath.h", f, &include_hashes_len,
			include_hashes);

	fclose(f);
}

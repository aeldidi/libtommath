# SPDX-License-Identifier: Unlicense
test_exe = executable(
	'libtommath_test',
	[
		files(
			'shared.c',
			'test.c',
		),
		srcs,
	],
	include_directories: incdirs,
)

if not meson.is_subproject()
	test(
		'test',
		test_exe,
	)
endif

timing_exe = executable(
	'timing',
	files(
		'shared.c',
		'timing.c',
	),
	dependencies: libtommath_dep,
)

mtest_opponent_exe = executable(
	'mtest_opponent',
	files(
		'shared.c',
		'mtest_opponent.c',
	),
	dependencies: libtommath_dep,
)

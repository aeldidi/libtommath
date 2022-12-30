# SPDX-License-Identifier: Unlicense
test_exe = executable(
    'libtommath_test',
    [
        files(
            'shared.c',
            'test.c',
        ),
        tommath_srcs,
    ],
    include_directories: incdir,
)

test(
    'test',
    test_exe,
)

timing_exe = executable(
    'timing',
    [
        files(
            'shared.c',
            'timing.c',
        ),
        tommath_srcs,
    ],
    include_directories: incdir,
)

mtest_opponent_exe = executable(
    'mtest_opponent',
    [
        files(
            'mtest_opponent.c',
            'shared.c',
        ),
        tommath_srcs,
    ],
    include_directories: incdir,
)

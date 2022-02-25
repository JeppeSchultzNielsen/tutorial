cmake_minimum_required(VERSION 3.21)
project(tutorial)

set(CMAKE_CXX_STANDARD 14)

include_directories(unpacker)
include_directories(unpacker/gen)
include_directories(unpacker/gen/acc_auto_def)
include_directories(unpacker/mc_gen)

find_package(AUSALIB REQUIRED)
find_package(libconfig++ QUIET)

add_executable(tutorial
        unpacker/gen/acc_auto_def/byteorder_include.h
        unpacker/gen/acc_auto_def/byteswap_include.h
        unpacker/gen/acc_auto_def/has_pthread_getname_np.h
        unpacker/gen/cal_struct_fcncall.hh
        unpacker/gen/cal_struct_mirror.hh
        unpacker/gen/cal_structure.hh
        unpacker/gen/clean_cal_structure.hh
        unpacker/gen/clean_raw_structure.hh
        unpacker/gen/clean_structures.hh
        unpacker/gen/data_mapping.hh
        unpacker/gen/default_fcncall_define.hh
        unpacker/gen/default_fcncall_undef.hh
        unpacker/gen/default_mirror_define.hh
        unpacker/gen/default_mirror_undef.hh
        unpacker/gen/locations.hh
        unpacker/gen/matcher.hh
        unpacker/gen/packer.hh
        unpacker/gen/raw_struct_fcncall.hh
        unpacker/gen/raw_struct_mirror.hh
        unpacker/gen/raw_structure.hh
        unpacker/gen/struct_fcncall.hh
        unpacker/gen/struct_mirror.hh
        unpacker/gen/struct_mirror_decl.hh
        unpacker/gen/structures.hh
        unpacker/gen/subevent_names.hh
        unpacker/gen/unpacker.hh
        unpacker/mc_gen/mc_lexer.cc
        unpacker/mc_gen/mc_parser.cc
        unpacker/mc_gen/mc_parser.hh
        unpacker/mc_gen/y.tab.c
        unpacker/mc_gen/y.tab.h
        unpacker/control.hh
        unpacker/ext_AUSA.h
        unpacker/MBS_user.cc
        Analyse.cpp)
find_package(AUSALIB REQUIRED)
target_link_libraries(tutorial PRIVATE AUSA::AUSA config++)
target_include_directories(tutorial PRIVATE ${CMAKE_SOURCE_DIR}/include)
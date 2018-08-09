rootdir := $(shell pwd)/../..
project ?= ubuntu-base

include $(rootdir)/build/project/$(project).mk
include $(rootdir)/build/common/common.mk

MODULE_NAME = libonutils
MODULEVERSION = 0.1.0
TARGET_ARCHIVE = $(MODULE_NAME).a

COMMON_SRC_FILES = $(rootdir)/source/$(MODULE_NAME)/src/hexdump.c		\
				   $(rootdir)/source/$(MODULE_NAME)/src/rbtree.c		\
				   $(rootdir)/source/$(MODULE_NAME)/src/time.c			\
				   $(rootdir)/source/$(MODULE_NAME)/src/rbtree_api.c
COMMON_INCLUDE_DIRS = $(rootdir)/source/$(MODULE_NAME)/include
COMMON_INST_HEADER_DIRS = $(rootdir)/source/$(MODULE_NAME)/include

include $(rootdir)/build/utils/archive.mk

.PHONY : sync

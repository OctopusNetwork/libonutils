rootdir := $(shell pwd)/../..
project ?= ubuntu-base

include $(rootdir)/build/project/$(project).mk
include $(rootdir)/build/common/common.mk

MODULENAME = libonutils
MODULEVERSION = 0.1.0
TARGET_ARCHIVE = $(MODULENAME).a

COMMON_SRC_FILES = $(rootdir)/source/$(MODULENAME)/src/hexdump.c		\
				   $(rootdir)/source/$(MODULENAME)/src/rbtree.c		\
				   $(rootdir)/source/$(MODULENAME)/src/time.c			\
				   $(rootdir)/source/$(MODULENAME)/src/rbtree_api.c
COMMON_INCLUDE_DIRS = $(rootdir)/source/$(MODULENAME)/include
COMMON_INST_HEADER_DIRS = $(rootdir)/source/$(MODULENAME)/include

include $(rootdir)/build/utils/archive.mk

.PHONY : sync

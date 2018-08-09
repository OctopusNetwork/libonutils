rootdir := $(shell pwd)/../../../..
project := ubuntu-base

MODULENAME = libonutils

include $(rootdir)/build/project/$(project).mk
include $(rootdir)/build/common/common.mk

####
##  Application targets
####
DEP_HEADERS += $(incdir)

apps = mt_rbtree mt_list

mt_rbtree_SRCS = $(rootdir)/source/$(MODULENAME)/test/mt/rbtree_test.c
mt_rbtree_ARCHIVES = onutils
mt_rbtree_LDLIBS =
mt_rbtree_DISTSOLIBS =

mt_list_SRCS = $(rootdir)/source/$(MODULENAME)/test/mt/list_test.c
mt_list_ARCHIVES = onutils
mt_list_LDLIBS =
mt_list_DISTSOLIBS =

include $(rootdir)/build/utils/app.mk

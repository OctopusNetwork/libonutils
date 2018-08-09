rootdir := $(shell pwd)/../../../..

include ../../modulename.mk

####
##  Application targets
####
DEP_HEADERS += $(hostincdir)

apps = mt_rbtree mt_list

mt_rbtree_SRCS = $(rootdir)/source/$(MODULE_NAME)/test/mt/rbtree_test.c
mt_rbtree_ARCHIVES = utils
mt_rbtree_LDLIBS =
mt_rbtree_DISTSOLIBS =

mt_list_SRCS = $(rootdir)/source/$(MODULE_NAME)/test/mt/list_test.c
mt_list_ARCHIVES = utils
mt_list_LDLIBS =
mt_list_DISTSOLIBS =

include $(rootdir)/build/utils/app.mk

#
# Makefile
#
# Makefile for Extension
#

include $(POCO_BASE)/OSP/BundleCreator/BundleCreator.make

objects = Extension

target         = com.appinf.osp.samples.extension
target_version = 1
target_libs    = PocoOSP PocoUtil PocoXML PocoFoundation

postbuild      = $(SET_LD_LIBRARY_PATH) $(BUNDLE_TOOL) -n$(OSNAME) -a$(OSARCH) -o../bundles Extension.bndlspec

include $(POCO_BASE)/build/rules/dylib

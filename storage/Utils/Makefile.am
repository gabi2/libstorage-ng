#
# Makefile.am for libstorage/storage/Utils
#

noinst_LTLIBRARIES = libutils.la

libutils_la_SOURCES =					\
	Logger.h		Logger.cc		\
	LoggerImpl.h		LoggerImpl.cc		\
	AppUtil.cc		AppUtil.h		\
	FileUtils.cc		FileUtils.h		\
	Exception.h		Exception.cc		\
	ExceptionImpl.h					\
	AsciiFile.cc 		AsciiFile.h		\
	Enum.h						\
	GraphUtils.h					\
	HumanString.h		HumanString.cc		\
	Lock.cc 		Lock.h			\
	OutputProcessor.cc	OutputProcessor.h	\
	Regex.cc 		Regex.h			\
	Region.cc 		Region.h		\
	RegionImpl.cc 		RegionImpl.h		\
	StorageTmpl.h					\
	StorageTypes.h					\
	SystemCmd.cc		SystemCmd.h		\
	Mockup.cc		Mockup.h		\
	Remote.cc		Remote.h		\
	XmlFile.h		XmlFile.cc		\
	CDgD.h						\
	StorageDefines.h

$(srcdir)/gen-pathlist.cc: StorageDefines.h
	grep BIN $< | sed -e "s/^[^ ]*[ ]\+//" -e "s/ .*/,/" > $@

BUILT_SOURCES = gen-pathlist.cc

pkgincludedir = $(includedir)/storage/Utils

pkginclude_HEADERS =		\
	Logger.h		\
	Exception.h		\
	HumanString.h		\
	Region.h		\
	Remote.h


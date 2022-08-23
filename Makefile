SUBDIRS := build

all clean : $(SUBDIRS)


$(SUBDIRS) :
	cd $(SUBDIRS); $(MAKE)

.PHONY: all clean $(SUBDIRS)
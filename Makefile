TOPTARGETS = all clean remake
SUBDIRS = server client

$(TOPTARGETS) : $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY : $(TOPTARGETS) $(SUBDIRS)
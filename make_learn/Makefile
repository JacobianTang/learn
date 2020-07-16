comma :=,
empty :=
space :=$(empty) $(empty)
foo := a b c
bar :=$(subst $(space),$(comma),$(foo))
test_str :="feet on the street"
do := a.c b.c c.c
test_subst :=$(subst e,E,$(test_str))
sources := foo.c bar.c baz.s ugh.h

VPATH =src:../headers
CFLAGS :=$(patsubst %,-I%,$(subst :, ,$(VPATH)))
names := a b c d
files :=$(foreach n,$(names),$(n).o)

reverse=$(1) good  $(2)
foo =$(call reverse,a,b)

.PHONY: all

all:good bad | test
	@echo $@
	@echo $^
	@echo $<
	@echo $(bar) 
	@echo $(test_str)
	@echo $(test_subst)
	@echo $(patsubst %.c,%.o,$(do))
	@echo $(filter %.c %.s,$(sources))
	@echo $(words $(test_str))
	@echo $(filter-out %.c %.s,$(sources))
	@echo $(CFLAGS)
	@echo $(files)
	@echo $(foo)

bad:
	@echo "print bad"

good:
	@echo "print good"

test:
	@echo "print test"

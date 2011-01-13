# ------------------------------------------------------------------------------
# 
# Copyright (c) 2010, Jean-David Gadina <macmade@eosgarden.com>
# Distributed under the Boost Software License, Version 1.0.
# 
# Boost Software License - Version 1.0 - August 17th, 2003
# 
# Permission is hereby granted, free of charge, to any person or organization
# obtaining a copy of the software and accompanying documentation covered by
# this license (the "Software") to use, reproduce, display, distribute,
# execute, and transmit the Software, and to prepare derivative works of the
# Software, and to permit third-parties to whom the Software is furnished to
# do so, all subject to the following:
# 
# The copyright notices in the Software and this entire statement, including
# the above license grant, this restriction and the following disclaimer,
# must be included in all copies of the Software, in whole or in part, and
# all derivative works of the Software, unless such copies or derivative
# works are solely in the form of machine-executable object code generated by
# a source language processor.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
# SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
# FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
# 
# ------------------------------------------------------------------------------

# $Id$

DIR_BUILD       = ./build/
DIR_BUILD_TMP   = $(DIR_BUILD)tmp/
DIR_SRC         = ./src/
DIR_SRC_INC     = $(DIR_SRC)include/
DEPS            = $(foreach dir,$(DIR_SRC_INC),$(wildcard $(DIR_SRC_INC)*.h))
STEM            = %
CC              = gcc
ARGS_CC         = -I $(DIR_SRC_INC) -std=c99 -Os -pedantic -Werror -Wall -Wextra -Wbad-function-cast -Wdeclaration-after-statement -Werror-implicit-function-declaration -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers -Wmissing-prototypes -Wnested-externs -Wold-style-definition -Wparentheses -Wreturn-type -Wshadow -Wsign-compare -Wstrict-prototypes -Wswitch -Wuninitialized -Wunknown-pragmas -Wunused-function -Wunused-label -Wunused-parameter -Wunused-value -Wunused-variable

.SUFFIXES:
.SUFFIXES: .c .h .o

VPATH =
vpath
vpath %.c $(DIR_SRC)
vpath %.h $(DIR_SRC_INC)
vpath %.o $(DIR_BUILD_TMP)

.PHONY: all clean install uninstall test

all: $(DIR_BUILD)eos-skl
	
clean:
	@find $(DIR_BUILD) -type f -print0 | xargs -0 rm

install: all
	@install $(DIR_BUILD)/eos-skl /usr/local/bin/eos-skl

uninstall:
	@if [ -f "/usr/local/bin/eos-skl" ]; then sudo rm "/usr/local/bin/eos-skl"; fi
	
test: all
	@./$(DIR_BUILD)/eos-skl

$(DIR_BUILD_TMP)%.o: %.c %.h $(DEPS)
	$(CC) $(ARGS_CC) -o $(DIR_BUILD_TMP)$(@F) -c $< $(CFLAGS)

$(DIR_BUILD_TMP)%.o: %.c $(DEPS)
	$(CC) $(ARGS_CC) -o $(DIR_BUILD_TMP)$(@F) -c $< $(CFLAGS)

$(DIR_BUILD)%: $(DIR_BUILD_TMP)%.o
	$(CC) $(ARGS_CC) -o $(DIR_BUILD)$(@F) $< $(CFLAGS)
TARGET		:=	Dbi-indonesia
BUILD		:=	build
SOURCES		:=	.
DATA		:=	data
INCLUDES	:=	include

include $(DEVKITPRO)/libnx/switch_rules

export CXXFLAGS	:=	$(CFLAGS) -Wall -Wextra -std=gnu++17
export LDFLAGS	:=	-specs=$(DEVKITPRO)/libnx/switch.specs

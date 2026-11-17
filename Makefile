#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITPRO)),)
export DEVKITPRO	:=	/opt/devkitpro
endif

export DEVKITARM	:=	$(DEVKITPRO)/devkitARM
export DEVKITA64	:=	$(DEVKITPRO)/devkitA64

TARGET		:=	$(notdir $(CURDIR))
BUILD		:=	build
SOURCES		:=	.
DATA		:=	data
INCLUDES	:=	include

#---------------------------------------------------------------------------------
include $(DEVKITPRO)/libnx/switch_rules
#---------------------------------------------------------------------------------

export CXXFLAGS	:=	$(CFLAGS) -Wall -Wextra -std=gnu++17
export LDFLAGS	:=	-specs=$(DEVKITPRO)/libnx/switch.specs

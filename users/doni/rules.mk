SRC += doni.c
ifeq ($(strip $(ENABLE_TEXT_MEMES)), yes)
OPT_DEFS += -DENABLE_TEXT_MEMES
SRC += text_macros/taunt_text.c
SRC += text_macros/wide_text.c
endif

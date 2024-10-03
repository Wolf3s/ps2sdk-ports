EE_SRC_DIR = ../build/madplay-0.15.2b/
EE_BIN_DIR = bin/

EE_BIN = $(EE_BIN_DIR)madplay.elf

EE_OBJS = $(EE_SRC_DIR)audio.o $(EE_SRC_DIR)audio_aiff.o $(EE_SRC_DIR)audio_snd.o $(EE_SRC_DIR)audio_wave.o $(EE_SRC_DIR)audio_raw.o \
	$(EE_SRC_DIR)audio_hex.o $(EE_SRC_DIR)audio_cdda.o $(EE_SRC_DIR)audio_null.o $(EE_SRC_DIR)crc.o $(EE_SRC_DIR)filter.o $(EE_SRC_DIR)getopt.o \
	$(EE_SRC_DIR)getopt1.o $(EE_SRC_DIR)madplay.o $(EE_SRC_DIR)resample.o $(EE_SRC_DIR)rgain.o $(EE_SRC_DIR)player.o \
	$(EE_SRC_DIR)strcasecmp.o $(EE_SRC_DIR)strncasecmp.o $(EE_SRC_DIR)tag.o $(EE_SRC_DIR)tagger.o $(EE_SRC_DIR)version.o  \
	file.o directory.o \
	audio_sjpcm.o isjpcm_irx.o

EE_LIBS += -lfileXio -ldebug -lmad -lid3tag \
	-lcdvd -lsjpcm -lz -lm -lpatches

EE_CXXFLAGS += -fno-exceptions -fno-rtti

EE_CFLAGS += -DHAVE_STRNCASECMP -DHAVE_CONFIG_H -DHAVE_UNISTD_H -DHAVE_ERRNO_H \
	-DHAVE_FCNTL_H -DHAVE_STRING_H -DHAVE_SYS_TYPES_H -DHAVE_ASSERT_H

EE_INCS += -I./ -I$(EE_SRC_DIR) -I$(PS2SDK)/common/include -I$(PS2SDK)/ee/include \
	-I$(PS2SDK)/ports/include -L$(PS2DEV)/isjpcm/include

EE_LDFLAGS += -L$(PS2SDK)/ee/lib -L$(PS2SDK)/ports/lib -L$(PS2DEV)/isjpcm/lib

all: $(EE_BIN_DIR) $(EE_BIN)

$(EE_BIN_DIR):
	mkdir -p $(EE_BIN_DIR)

install: all
	mkdir -p $(DESTDIR)$(PS2SDK)/ports/bin
	cp -f $(EE_BIN) $(DESTDIR)$(PS2SDK)/ports/bin/

isjpcm_irx.c: $(PS2DEV)/isjpcm/bin/isjpcm.irx
	$(PS2SDK)/bin/bin2c $< $@ isjpcm_irx

clean:
	rm -f -r $(EE_BIN_DIR)

sample:

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal

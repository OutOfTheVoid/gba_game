CC := $(DEVKITARM)/bin/arm-none-eabi-gcc
CXX := $(DEVKITARM)/bin/arm-none-eabi-g++
LD := $(DEVKITARM)/bin/arm-none-eabi-ld
OBJCOPY := $(DEVKITARM)/bin/arm-none-eabi-objcopy

ARCH := -mthumb -mthumb-interwork
SPECS := -specs=gba.specs

COMMON_FLAGS := $(ARCH)  -mcpu=arm7tdmi -fno-strict-aliasing -Iinc -g -fno-threadsafe-statics
C_FLAGS := $(COMMON_FLAGS) -c -std=c99 -pedantic -Wall -Wextra
CPP_FLAGS := $(COMMON_FLAGS) -c -std=c++17 -Wall -Wextra -fno-rtti -fno-exceptions
LD_FLAGS := -g $(SPECS) $(ARCH) -std=c++17

TARGET := gba_dev

OBJ_SOURCES := \
	main.cpp \
	gba/tile_manager.cpp \
	gba/pal_manager.cpp \
	gba/sprite_manager.cpp \
	gba/keys.cpp \
	gba/interrupts.cpp \
	gba/sound_driver.cpp \
	gba/panic.cpp \
	gba/cpp_rt.cpp \
	gba/str.cpp \
	gba/bg_dynamic_scene.cpp \
	\
	math/fx16.cpp \
	math/fx16_lut.cpp \
	\
	events/event.cpp \
	\
	animation/tween.cpp \
	animation/sprite_tween.cpp \
	\
	drawing/sprite_bitmap.cpp \
	drawing/fonts.cpp \
	drawing/basic_numeric.cpp \
	drawing/basic_alpha.cpp \
	drawing/basic_symbol.cpp \
	\
	game/random.cpp \
	game/scene.cpp \
	\
	game/test_scene/test.cpp \
	game/test_scene/assets.cpp \
	\
	game/menu_scene/menu.cpp \
	game/menu_scene/assets.cpp \
	\
	game/collision/player_walk.cpp\
	game/collision/walk_area.cpp

GBA_EMU := mgba
#EMU_FLAGS := -4
EMU_FLAGS := -2
DEBUG_EMU_FLAGS := -g
DEBUGGER := $(DEVKITARM)/bin/arm-none-eabi-gdb
DEBUGGER_FLAGS := -x debug_gdb.txt -silent

run: | build
	$(GBA_EMU) $(TARGET).gba $(EMU_FLAGS)
	
debug: | build
	$(GBA_EMU) $(TARGET).gba $(EMU_FLAGS) $(DEBUG_EMU_FLAGS) & $(DEBUGGER) $(DEBUGGER_FLAGS) && killall $(GBA_EMU)

build: $(TARGET).gba

crun: | clean run
cdebug: | clean debug

$(TARGET).gba : obj/cart.elf
	$(OBJCOPY) -v -O binary obj/cart.elf $(TARGET).gba
	gbafix $(TARGET).gba
	
obj/cart.elf: $(addsuffix .o, $(addprefix obj/, $(OBJ_SOURCES)))
	$(CC) $(addsuffix .o, $(addprefix obj/, $(OBJ_SOURCES))) $(LD_FLAGS) -o obj/cart.elf
	
obj/%.cpp.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $< $(CPP_FLAGS) -o $@
	
obj/%.s.o: src/%.s
	@mkdir -p $(dir $@)
	$(CC) $< $(C_FLAGS) -o $@

clean:
	rm -rf obj
	rm -fv *.sav
	rm -fv *.gba

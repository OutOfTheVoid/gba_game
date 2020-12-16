CC := $(DEVKITARM)/bin/arm-none-eabi-gcc
CXX := $(DEVKITARM)/bin/arm-none-eabi-g++
LD := $(DEVKITARM)/bin/arm-none-eabi-ld
OBJCOPY := $(DEVKITARM)/bin/arm-none-eabi-objcopy
CARGO := cargo

ARCH := -mthumb -mthumb-interwork
SPECS := -specs=gba.specs

COMMON_FLAGS := $(ARCH)  -mcpu=arm7tdmi -fno-strict-aliasing -Iinc -g -fno-threadsafe-statics
C_FLAGS := $(COMMON_FLAGS) -c -std=c99 -pedantic -Wall -Wextra
CPP_FLAGS := $(COMMON_FLAGS) -c -std=c++17 -Wall -Wextra -fno-rtti -fno-exceptions
LD_FLAGS := -g $(SPECS) $(ARCH) -std=c++17

TARGET := gba_dev

PNG_2_GBA := png_2_gba/target/debug/png_2_gba

PNG_2_GBA_SPRITE_OUTPUT_4BPP = -o src/game/assets/$(1).cpp -h inc/game/assets/$(1).hpp -f sprite_4bpp_asset_pal -n $(1) -i game/assets/$(1).hpp

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
	\
	game/menu_scene/menu.cpp \
	game/menu_scene/assets.cpp \
	\
	game/collision/player_walk.cpp\
	game/collision/walk_area.cpp\
	\
	game/assets/bridge.cpp
	
PNG_2_GBA_OUTPUT_SOURCES := \
	game/assets/boy1.cpp \
	game/assets/cat1.cpp
	
GBA_EMU := mgba
#EMU_FLAGS := -4
EMU_FLAGS := -4
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
	
obj/cart.elf: $(addsuffix .o, $(addprefix obj/, $(PNG_2_GBA_OUTPUT_SOURCES))) $(addsuffix .o, $(addprefix obj/, $(OBJ_SOURCES)))
	$(CC) $(addsuffix .o, $(addprefix obj/, $(PNG_2_GBA_OUTPUT_SOURCES))) $(addsuffix .o, $(addprefix obj/, $(OBJ_SOURCES))) $(LD_FLAGS) -o obj/cart.elf
	
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
	cargo clean --manifest-path png_2_gba/Cargo.toml
	
src/game/assets/boy1.cpp: $(PNG_2_GBA) assets/boy1/frame_00.png assets/boy1/frame_01.png assets/boy1/frame_02.png assets/boy1/frame_03.png assets/boy1/frame_04.png assets/boy1/frame_05.png assets/boy1/frame_06.png assets/boy1/frame_07.png assets/boy1/frame_08.png assets/boy1/frame_09.png assets/boy1/frame_10.png assets/boy1/frame_11.png
	$(PNG_2_GBA) assets/boy1/frame_00.png assets/boy1/frame_01.png assets/boy1/frame_02.png assets/boy1/frame_03.png assets/boy1/frame_04.png assets/boy1/frame_05.png assets/boy1/frame_06.png assets/boy1/frame_07.png assets/boy1/frame_08.png assets/boy1/frame_09.png assets/boy1/frame_10.png assets/boy1/frame_11.png -o src/game/assets/boy1.cpp -h inc/game/assets/boy1.hpp -f sprite_4bpp_asset_pal -n boy1 -i game/assets/boy1.hpp
	
src/game/assets/cat1.cpp: $(PNG_2_GBA) assets/cat1/frame_0.png assets/cat1/frame_1.png assets/cat1/frame_2.png
	$(PNG_2_GBA) assets/cat1/frame_0.png assets/cat1/frame_1.png assets/cat1/frame_2.png $(call PNG_2_GBA_SPRITE_OUTPUT_4BPP,cat1)
	
$(PNG_2_GBA):
	$(CARGO) build --manifest-path png_2_gba/Cargo.toml

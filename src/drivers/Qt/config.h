#ifndef CONFIG_H_HF128
#define CONFIG_H_HF128

#include "common/configSys.h"

Config *InitConfig(void);
void UpdateEMUCore(Config *);
int LoadCPalette(const std::string &file);

// hotkey definitions
// TODO: encapsulate this in an improved data structure
enum HOTKEY { 
	// ROM Open and Close
	HK_OPEN_ROM=0, HK_CLOSE_ROM, 

	// Emulation power, reset, pause, quit
	HK_POWER, HK_RESET, HK_PAUSE, HK_QUIT,

	// Emulation Execution Control
	HK_FRAME_ADVANCE, HK_DECREASE_SPEED, HK_INCREASE_SPEED, HK_TURBO,
	
	// Save States
	HK_SAVE_STATE,
	HK_SAVE_STATE_0, HK_SAVE_STATE_1, HK_SAVE_STATE_2, HK_SAVE_STATE_3, HK_SAVE_STATE_4,
	HK_SAVE_STATE_5, HK_SAVE_STATE_6, HK_SAVE_STATE_7, HK_SAVE_STATE_8, HK_SAVE_STATE_9,

	// Load States
	HK_LOAD_STATE,
	HK_LOAD_STATE_0, HK_LOAD_STATE_1, HK_LOAD_STATE_2, HK_LOAD_STATE_3, HK_LOAD_STATE_4,
	HK_LOAD_STATE_5, HK_LOAD_STATE_6, HK_LOAD_STATE_7, HK_LOAD_STATE_8, HK_LOAD_STATE_9,

	// Select State Slot
	HK_SELECT_STATE_0, HK_SELECT_STATE_1, HK_SELECT_STATE_2, HK_SELECT_STATE_3, HK_SELECT_STATE_4,
	HK_SELECT_STATE_5, HK_SELECT_STATE_6, HK_SELECT_STATE_7, HK_SELECT_STATE_8, HK_SELECT_STATE_9, 
	HK_SELECT_STATE_NEXT, HK_SELECT_STATE_PREV,

	// GUI
	HK_FULLSCREEN, HK_MAIN_MENU_HIDE, 

	// FDS 
	HK_FDS_SELECT, HK_FDS_EJECT,

	// VS
	HK_VS_INSERT_COIN, HK_VS_TOGGLE_DIPSWITCH,

	// Movie
	HK_TOGGLE_FRAME_DISPLAY, HK_TOGGLE_SUBTITLE, HK_SCREENSHOT,
	HK_BIND_STATE, HK_MOVIE_TOGGLE_RW,
	HK_PLAY_MOVIE_FROM, HK_MOVIE_PLAY_RESTART, HK_RECORD_MOVIE_TO, HK_STOP_MOVIE,
	HK_RECORD_AVI, HK_RECORD_AVI_TO, HK_STOP_AVI,
	HK_RECORD_WAV, HK_RECORD_WAV_TO, HK_STOP_WAV,

	// Display
	HK_TOGGLE_FG, HK_TOGGLE_BG, HK_TOGGLE_INPUT_DISPLAY, HK_LAG_COUNTER_DISPLAY,
	
	HK_CHEAT_MENU, HK_LOAD_LUA,
	HK_MUTE_CAPTURE,
	HK_FA_LAG_SKIP,
	HK_VOLUME_DOWN, HK_VOLUME_UP,
	HK_FKB_ENABLE,
	HK_MAX};

int getHotKeyConfig( int i, const char **nameOut, const char **keySeqOut, const char **titleOut = NULL );

#endif


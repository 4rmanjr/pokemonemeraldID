EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Aku adalah anggota terakhir dari EMPAT\n"
	.string "ELIT LIGA POKéMON, DRAKE sang master\l"
	.string "NAGA!\p"
	.string "Dalam keadaan alami, POKéMON adalah\n"
	.string "makhluk liar. Mereka bebas.\p"
	.string "Terkadang, mereka menghalangi kita.\n"
	.string "Terkadang, mereka membantu kita.\p"
	.string "Agar kita bisa bertarung dengan POKéMON\n"
	.string "sebagai partner, tahukah kamu apa\l"
	.string "yang dibutuhkan?\p"
	.string "Tahukah kamu apa yang diperlukan?\p"
	.string "Jika tidak, maka kamu tidak akan pernah\n"
	.string "mengalahkanku!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Luar biasa, harus dikatakan.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "Kamu pantas mendapatkan semua pujian\n"
	.string "karena telah sampai sejauh ini sebagai\l"
	.string "TRAINER POKéMON.\p"
	.string "Kamu tampaknya tahu apa yang dibutuhkan.\p"
	.string "Ya, yang dibutuhkan seorang TRAINER\n"
	.string "adalah hati yang mulia.\p"
	.string "POKéMON menyentuh hati baik para\n"
	.string "TRAINER dan belajar yang benar dari\l"
	.string "yang salah.\p"
	.string "Mereka menyentuh hati baik para\n"
	.string "TRAINER dan tumbuh kuat.\p"
	.string "Pergi! Teruslah maju!\n"
	.string "JUARA sedang menunggu!$"


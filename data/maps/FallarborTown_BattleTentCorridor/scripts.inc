//aistudio
FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "Kami lumayan di babak awal,\n"
	.string "tapi tak pernah menang daya tarik…\p"
	.string "Mungkin aku harus melihat apa\n"
	.string "yang dilakukan kontestan lain…$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "Lihat! POKéMON-ku memenangkan\n"
	.string "semua RIBBON ini!\p"
	.string "Apa POKéMON-mu dapat RIBBON?\n"
	.string "Cek di POKéNAV-mu.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "Aku tidak bisa mengalahkan\n"
	.string "PEMIMPIN GYM…\p"
	.string "Aku tidak bisa memenangkan\n"
	.string "KONTEST apa pun…\p"
	.string "Aku sudah ke sana kemari,\n"
	.string "tapi semuanya sia-sia…$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "KONTEST POKéMON\n"
	.string "TAHAP RANK SUPER!$"

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "KONTEST apa yang ingin kamu ikuti?\n"
	.string "Mau saran?\p"
	.string "Dalam KONTEST apa pun, misalnya\n"
	.string "KONTEST KEIMUTAN, kurasa mereka\l"
	.string "tidak hanya menilaimu dari\n"
	.string "keimutan di babak pertama.\p"
	.string "Kamu perlu mencari cara untuk\n"
	.string "melatih POKéMON lebih baik.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "Aku melatih POKéMON-ku agar imut.\p"
	.string "Aku baru tahu kalau kamu bisa\n"
	.string "memasukkan POKéMON ke KONTEST\l"
	.string "keimutan!\p"
	.string "Aku senang sekali melatih POKéMON-ku\n"
	.string "dengan penuh kasih sayang…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "POKéMON-ku hebat!\p"
	.string "Dia keren, tangguh tapi indah,\n"
	.string "imut, & cerdas. Dia sempurna!\p"
	.string "Aku mungkin akan memenangkan\n"
	.string "setiap KONTEST.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "KONTEST POKéMON\n"
	.string "TAHAP NORMAL!$"

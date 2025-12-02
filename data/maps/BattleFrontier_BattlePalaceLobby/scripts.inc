BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "Di mana hati para TRAINER\n"
	.string "diuji.\p"
	.string "Aku menyambutmu di BATTLE PALACE.\p"
	.string "Aku menerima tantangan ke SINGLE\n"
	.string "BATTLE HALLS.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "Apakah kamu ingin menerima\n"
	.string "tantangan SINGLE BATTLE HALL?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "Di BATTLE PALACE, ada beberapa\n"
	.string "auditorium untuk SINGLE BATTLES\l"
	.string "yang disebut SINGLE BATTLE HALLS.\p"
	.string "SINGLE BATTLES dilakukan seperti\n"
	.string "biasa, kecuali ada satu aturan\l"
	.string "penting yang harus dipatuhi.\p"
	.string "TRAINER hanya diizinkan untuk\n"
	.string "menukar POKéMON mereka masuk & keluar.\p"
	.string "TRAINER dilarang memerintah\n"
	.string "POKéMON mereka.\p"
	.string "POKéMON harus bertindak sesuai\n"
	.string "sifat mereka & bertarung sendiri.\p"
	.string "Kamu harus percaya pada POKéMON-mu\n"
	.string "& mengawasi mereka.\p"
	.string "Jika kamu berhasil mengalahkan\n"
	.string "tujuh TRAINER berturut-turut,\l"
	.string "kami akan memberimu Battle Points.\p"
	.string "Jika kamu ingin menghentikan\n"
	.string "tantanganmu, kamu harus simpan game.\p"
	.string "Jika kamu tidak simpan sebelum\n"
	.string "menghentikan, kamu akan didiskualifikasi.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Saat kamu telah menguatkan hati\n"
	.string "& POKéMON-mu, kamu harus kembali.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Ada dua BATTLE HALLS,\n"
	.string "Level 50 & Open Level.\l"
	.string "Tantangan mana yang kamu pilih?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Hah…\p"
	.string "Kamu tidak punya tiga POKéMON\n"
	.string "yang dibutuhkan untuk tantangan.\p"
	.string "Untuk masuk, kamu harus siapkan\n"
	.string "tiga jenis POKéMON berbeda.\p"
	.string "POKéMON ini semua harus\n"
	.string "Level 50 atau lebih rendah.\p"
	.string "Mereka juga tidak boleh membawa\n"
	.string "jenis item yang sama.\p"
	.string "TELUR{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd:
	.string "Kembalilah saat kamu sudah\n"
	.string "melakukan persiapan.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Hah…\p"
	.string "Kamu tidak punya tiga POKéMON\n"
	.string "yang dibutuhkan untuk tantangan.\p"
	.string "Untuk masuk, kamu harus siapkan\n"
	.string "tiga jenis POKéMON berbeda.\p"
	.string "Mereka juga tidak boleh membawa\n"
	.string "jenis item yang sama.\p"
	.string "TELUR{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Bagus. Sekarang, kamu harus pilih\n"
	.string "tiga POKéMON-mu.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Aku harus simpan sebelum\n"
	.string "mengantarmu ke BATTLE HALL. Oke?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Baik.\n"
	.string "Sekarang, ikuti aku.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "Aku merasa terhormat melihat\n"
	.string "aksi POKéMON-mu.\p"
	.string "Hasilnya akan dicatat.\n"
	.string "Aku minta kamu menunggu sebentar.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "Untuk mencapai 7 kemenangan\n"
	.string "beruntun…\p"
	.string "Ikatan hatimu dengan POKéMON-mu\n"
	.string "terlihat kuat & sejati.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "Prestasimu akan dicatat.\n"
	.string "Aku minta kamu menunggu sebentar.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "Atas prestasi 7 kemenangan beruntunmu,\n"
	.string "kami memberimu Battle Point(s).$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Kamu sepertinya tidak punya ruang\n"
	.string "untuk hadiah kami.\p"
	.string "Kamu harus kembali setelah\n"
	.string "mengatur TAS-mu.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Kami sudah menunggumu…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Aku harus simpan sebelum\n"
	.string "mengantarmu ke BATTLE HALL. Oke?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Hah…\p"
	.string "Kamu gagal simpan sebelum\n"
	.string "mengakhiri tantanganmu terakhir kali.\p"
	.string "Akibatnya, tantanganmu\n"
	.string "didiskualifikasi. Sangat disayangkan.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} menerima hadiah\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "Untuk orang tangguh sepertiku,\n"
	.string "POKéMON tangguh adalah yang terbaik.\p"
	.string "Serangan adalah pertahanan terbaik!\n"
	.string "Serangan tanpa henti adalah pamungkas!\p"
	.string "Tapi bukan itu yang ingin kubahas.\p"
	.string "Sesekali ada wanita manis\n"
	.string "yang mampir ke sini.\p"
	.string "Dia bilang dia bisa tahu apa\n"
	.string "yang POKéMON pikirkan.\p"
	.string "Aku tidak tahu soal itu,\n"
	.string "tapi dia memang manis.\p"
	.string "Hah?\n"
	.string "Kenapa kamu melihatku begitu?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Hmm…\p"
	.string "Tampaknya sifat POKéMON\n"
	.string "& jurus yang telah\l"
	.string "diajarkan adalah kunci\l"
	.string "pertarungan di sini.\p"
	.string "Lebih tepatnya, seberapa\n"
	.string "cocok jurus dengan sifat\l"
	.string "POKéMON.\p"
	.string "Jika POKéMON-mu dalam\n"
	.string "masalah & tidak dapat\l"
	.string "mencapai potensinya,\l"
	.string "kamu perlu memeriksa\l"
	.string "kecocokan jurus & sifatnya.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "POKéMON-ku biasanya\n"
	.string "sangat jinak.\p"
	.string "Tapi saat di BATTLE HALL,\n"
	.string "kadang ia seperti berubah\l"
	.string "menjadi sesuatu yang jahat!\p"
	.string "Ia jadi sangat\n"
	.string "mengintimidasi.\l"
	.string "Mengejutkan sekali.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Aku ingin tahu sifat POKéMON\n"
	.string "seperti apa yang suka\l"
	.string "melemahkan lawan &\l"
	.string "menyerang perlahan.\p"
	.string "Aku akan terkejut jika\n"
	.string "itu sifat LAX.\p"
	.string "Tapi, ah, itu tidak\n"
	.string "mungkin benar.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "Tempat hati TRAINER\n"
	.string "diuji.\p"
	.string "Aku menyambutmu di\n"
	.string "BATTLE PALACE.\p"
	.string "Aku menerima tantangan\n"
	.string "ke DOUBLE BATTLE HALLS.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "Apakah kamu ingin\n"
	.string "menerima tantangan\l"
	.string "DOUBLE BATTLE HALL?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "Di BATTLE PALACE, ada\n"
	.string "beberapa auditorium\l"
	.string "untuk DOUBLE BATTLE\l"
	.string "bernama DOUBLE BATTLE\l"
	.string "HALLS.\p"
	.string "DOUBLE BATTLE dilakukan\n"
	.string "seperti biasa, kecuali\l"
	.string "ada satu aturan penting\l"
	.string "yang harus dipatuhi.\p"
	.string "TRAINER hanya diizinkan\n"
	.string "untuk menukar POKéMON\l"
	.string "mereka.\p"
	.string "TRAINER dilarang untuk\n"
	.string "memerintah POKéMON\l"
	.string "mereka.\p"
	.string "POKéMON harus bertindak\n"
	.string "sesuai sifatnya &\l"
	.string "bertarung sendiri.\p"
	.string "Kamu harus percaya pada\n"
	.string "POKéMON-mu &\l"
	.string "mengawasi mereka.\p"
	.string "Jika kamu berhasil\n"
	.string "mengalahkan tujuh\l"
	.string "TRAINER berturut-turut,\l"
	.string "kami akan memberimu\l"
	.string "Battle Points.\p"
	.string "Jika kamu ingin\n"
	.string "menghentikan tantanganmu,\l"
	.string "harap simpan permainan.\p"
	.string "Jika kamu tidak menyimpan\n"
	.string "sebelum menghentikan,\l"
	.string "kamu akan didiskualifikasi.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "Untuk mengalahkan\n"
	.string "PALACE MAVEN & tujuh\l"
	.string "TRAINER berturut-turut…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "Sebagai penghormatan\n"
	.string "atas ikatanmu dengan\l"
	.string "POKéMON-mu, kami\l"
	.string "memberimu Battle Point(s)\l"
	.string "ini.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "Apakah kamu ingin merekam\n"
	.string "pertandingan BATTLE PALACE\l"
	.string "terakhirmu di FRONTIER\l"
	.string "PASS-mu?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "Aturan BATTLE HALL tercantum.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "Judul mana yang ingin\n"
	.string "kamu baca?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Di sini, POKéMON harus\n"
	.string "berpikir & bertarung\l"
	.string "sendiri.\p"
	.string "Tidak seperti di alam\n"
	.string "liar, POKéMON yang\l"
	.string "hidup dengan manusia\l"
	.string "berperilaku berbeda\l"
	.string "tergantung sifatnya.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Tergantung sifatnya,\n"
	.string "POKéMON mungkin lebih\l"
	.string "suka menyerang apa pun.\p"
	.string "POKéMON lain mungkin\n"
	.string "lebih suka melindungi\l"
	.string "diri dari bahaya.\p"
	.string "Ada juga yang mungkin\n"
	.string "suka mengganggu atau\l"
	.string "membingungkan musuhnya.\p"
	.string "Karena sifatnya, POKéMON\n"
	.string "akan memiliki jurus\l"
	.string "favorit yang pandai\l"
	.string "digunakannya.\p"
	.string "Ia juga mungkin tidak\n"
	.string "menyukai jurus tertentu\l"
	.string "yang sulit digunakannya.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Ada jurus ofensif yang\n"
	.string "memberikan kerusakan\l"
	.string "langsung pada lawan.\p"
	.string "Ada jurus defensif yang\n"
	.string "digunakan untuk bersiap\l"
	.string "menghadapi serangan\l"
	.string "musuh atau untuk\l"
	.string "memulihkan HP & sbgnya.\p"
	.string "Ada juga jurus lain yang\n"
	.string "agak aneh yang dapat\l"
	.string "melemahkan lawan dengan\l"
	.string "masalah status termasuk\l"
	.string "racun & kelumpuhan.\p"
	.string "POKéMON akan\n"
	.string "mempertimbangkan untuk\l"
	.string "menggunakan jurus dalam\l"
	.string "tiga kategori ini.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "Saat tidak di bawah\n"
	.string "perintah TRAINER-nya,\l"
	.string "POKéMON mungkin tidak\l"
	.string "dapat menggunakan jurus\l"
	.string "tertentu secara efektif.\p"
	.string "POKéMON tidak pandai\n"
	.string "menggunakan jurus apa\l"
	.string "pun yang tidak disukainya.\p"
	.string "Jika POKéMON hanya tahu\n"
	.string "jurus yang tidak cocok\l"
	.string "dengan sifatnya, ia\l"
	.string "seringkali tidak dapat\l"
	.string "mencapai potensinya.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "Tergantung sifatnya,\n"
	.string "POKéMON mungkin mulai\l"
	.string "menggunakan jurus yang\l"
	.string "tidak cocok dengan\l"
	.string "sifatnya saat dalam\l"
	.string "masalah.\p"
	.string "Jika POKéMON mulai\n"
	.string "berperilaku aneh dalam\l"
	.string "keadaan darurat, awasi\l"
	.string "baik-baik.$"

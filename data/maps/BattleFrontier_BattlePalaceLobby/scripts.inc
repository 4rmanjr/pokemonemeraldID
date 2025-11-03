//gemini
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
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
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
	.string "Di mana hati para TRAINER diuji.\p"
	.string "Aku menyambut Kamu di ISTANA\n"
	.string "PERTARUNGAN (BATTLE PALACE).\p"
	.string "Aku menerima tantangan untuk RUANG\n"
	.string "PERTARUNGAN TUNGGAL (SINGLE BATTLE\l"
	.string "HALLS).$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "Apakah Kamu ingin mengambil\n"
	.string "tantangan RUANG PERTARUNGAN\l"
	.string "TUNGGAL?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "Di ISTANA PERTARUNGAN, ada beberapa\n"
	.string "auditorium untuk PERTARUNGAN\l"
	.string "TUNGGAL yang dinamakan RUANG\l"
	.string "PERTARUNGAN TUNGGAL.\p"
	.string "PERTARUNGAN TUNGGAL dilakukan\n"
	.string "dengan cara biasa, kecuali satu\l"
	.string "aturan krusial yang harus ditaati.\p"
	.string "TRAINER hanya diizinkan untuk\n"
	.string "menukar keluar dan masuk POKéMON\l"
	.string "mereka.\p"
	.string "TRAINER dilarang untuk memberikan\n"
	.string "perintah kepada POKéMON mereka.\p"
	.string "POKéMON harus bertingkah laku\n"
	.string "sesuai sifat mereka dan bertarung\l"
	.string "sendiri.\p"
	.string "Kamu harus menaruh kepercayaan pada\n"
	.string "POKéMON-mu dan mengawasi mereka.\p"
	.string "Jika Kamu mencapai kehormatan\n"
	.string "mengalahkan tujuh TRAINER\l"
	.string "berturut-turut, kami akan\l"
	.string "memberikan Poin Pertarungan (Battle\l"
	.string "Points) kepadamu.\p"
	.string "Jika Kamu ingin menginterupsi\n"
	.string "tantanganmu, Kamu harus menyimpan\l"
	.string "permainan.\p"
	.string "Jika Kamu tidak menyimpan sebelum\n"
	.string "menginterupsi, Kamu akan\l"
	.string "didiskualifikasi.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Ketika Kamu telah menguatkan hati\n"
	.string "dan POKéMON-mu, Kamu harus kembali.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Ada dua RUANG PERTARUNGAN, Level 50\n"
	.string "dan Level Terbuka. Mana pilihan\l"
	.string "tantanganmu?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Hah…\p"
	.string "Kamu tidak memiliki tiga POKéMON\n"
	.string "yang diperlukan untuk tantangan.\p"
	.string "Untuk masuk, Kamu harus menyediakan\n"
	.string "tiga jenis POKéMON yang berbeda.\p"
	.string "POKéMON ini semua harus berada di\n"
	.string "Level 50 atau lebih rendah.\p"
	.string "Mereka juga tidak boleh memegang\n"
	.string "jenis item yang sama.\p"
	.string "TELUR{STR_VAR_1} tidak memenuhi\n"
	.string "syarat.\p"
	.string "Kembalilah setelah Kamu membuat\n"
	.string "persiapanmu.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Hah…\p"
	.string "Kamu tidak memiliki tiga POKéMON\n"
	.string "yang diperlukan untuk tantangan.\p"
	.string "Untuk masuk, Kamu harus menyediakan\n"
	.string "tiga jenis POKéMON yang berbeda.\p"
	.string "Mereka juga tidak boleh memegang\n"
	.string "jenis item yang sama.\p"
	.string "TELUR{STR_VAR_1} tidak memenuhi\n"
	.string "syarat.\p"
	.string "Kembalilah setelah Kamu membuat\n"
	.string "persiapanmu.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Bagus. Sekarang, Kamu harus memilih\n"
	.string "tiga POKéMON-mu.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Aku harus menyimpan sebelum Aku\n"
	.string "menunjukkan Kamu ke RUANG\l"
	.string "PERTARUNGAN. Apakah tidak apa-apa?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Bagus. Sekarang, ikuti Aku.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "Aku merasa terhormat telah melihat\n"
	.string "eksploitasi POKéMON-mu.\p"
	.string "Hasilnya akan dicatat. Aku harus\n"
	.string "meminta Kamu menunggu sebentar.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "Untuk mencapai 7 kemenangan\n"
	.string "beruntun…\p"
	.string "Ikatan yang mengikat hatimu dengan\n"
	.string "POKéMON-mu tampak teguh dan tulus.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "Pencapaianmu akan dicatat. Aku\n"
	.string "harus meminta Kamu menunggu\l"
	.string "sebentar.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "Atas pencapaian 7 kemenangan\n"
	.string "beruntunmu, kami memberimu Poin\l"
	.string "Pertarungan.$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Kamu tampaknya tidak memiliki ruang\n"
	.string "untuk hadiah kami.\p"
	.string "Kamu harus kembali setelah Kamu\n"
	.string "mengatur TAS-mu.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Kami telah menunggumu…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Aku harus menyimpan sebelum Aku\n"
	.string "menunjukkan Kamu ke RUANG\l"
	.string "PERTARUNGAN. Apakah tidak apa-apa?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Hah…\p"
	.string "Kamu gagal menyimpan sebelum Kamu\n"
	.string "mengakhiri tantanganmu terakhir\l"
	.string "kali.\p"
	.string "Akibatnya, tantanganmu telah\n"
	.string "didiskualifikasi. Ini sangat\l"
	.string "disayangkan.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} menerima hadiah\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "Untuk pria tangguh sepertiku,\n"
	.string "POKéMON yang tangguh adalah yang\l"
	.string "terbaik.\p"
	.string "Menyerang adalah pertahanan\n"
	.string "terbaik! Serangan tanpa henti\l"
	.string "adalah yang tertinggi!\p"
	.string "Tapi bukan itu yang ingin Aku\n"
	.string "bicarakan.\p"
	.string "Sesekali ada wanita yang sangat\n"
	.string "manis mampir ke sini.\p"
	.string "Dia bilang dia bisa tahu apa yang\n"
	.string "dipikirkan POKéMON.\p"
	.string "Aku tidak tahu tentang bagian itu,\n"
	.string "tapi dia benar-benar manis.\p"
	.string "Hah? Kenapa Kamu melihatku seperti\n"
	.string "itu?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Hmm…\p"
	.string "Tampaknya sifat POKéMON dan jurus\n"
	.string "yang telah diajarkan kepada mereka\l"
	.string "adalah kunci pertarungan di sini.\p"
	.string "Lebih tepatnya, seberapa baik\n"
	.string "jurus-jurus itu cocok dengan sifat\l"
	.string "POKéMON.\p"
	.string "Jika POKéMON-mu dalam masalah dan\n"
	.string "tidak dapat memenuhi potensinya,\l"
	.string "Kamu mungkin perlu memeriksa\l"
	.string "seberapa baik jurusnya cocok dengan\l"
	.string "sifatnya.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "POKéMON-ku biasanya sangat jinak.\p"
	.string "Tapi saat berada di RUANG\n"
	.string "PERTARUNGAN, terkadang ia tampak\l"
	.string "berubah menjadi sesuatu yang jahat!\p"
	.string "Ia menjadi sangat mengintimidasi.\n"
	.string "Bahkan mengejutkan.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Aku ingin tahu sifat seperti apa\n"
	.string "yang dimiliki POKéMON jika ia lebih\l"
	.string "suka melemahkan lawannya dan\l"
	.string "mengikis perlahan.\p"
	.string "Aku akan terkejut jika itu sifat\n"
	.string "LAX.\p"
	.string "Tapi, ah, itu pasti tidak benar.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "Di mana hati para TRAINER diuji.\p"
	.string "Aku menyambut Kamu di ISTANA\n"
	.string "PERTARUNGAN (BATTLE PALACE).\p"
	.string "Aku menerima tantangan untuk RUANG\n"
	.string "PERTARUNGAN GANDA (DOUBLE BATTLE\l"
	.string "HALLS).$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "Apakah Kamu ingin mengambil\n"
	.string "tantangan RUANG PERTARUNGAN GANDA?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "Di ISTANA PERTARUNGAN, ada beberapa\n"
	.string "auditorium untuk PERTARUNGAN GANDA\l"
	.string "yang dinamakan RUANG PERTARUNGAN\l"
	.string "GANDA.\p"
	.string "PERTARUNGAN GANDA dilakukan dengan\n"
	.string "cara biasa, kecuali satu aturan\l"
	.string "krusial yang harus ditaati.\p"
	.string "TRAINER hanya diizinkan untuk\n"
	.string "menukar keluar dan masuk POKéMON\l"
	.string "mereka.\p"
	.string "TRAINER dilarang untuk memberikan\n"
	.string "perintah kepada POKéMON mereka.\p"
	.string "POKéMON harus bertingkah laku\n"
	.string "sesuai sifat mereka dan bertarung\l"
	.string "sendiri.\p"
	.string "Kamu harus menaruh kepercayaan pada\n"
	.string "POKéMON-mu dan mengawasi mereka.\p"
	.string "Jika Kamu mencapai kehormatan\n"
	.string "mengalahkan tujuh TRAINER\l"
	.string "berturut-turut, kami akan\l"
	.string "memberikan Poin Pertarungan (Battle\l"
	.string "Points) kepadamu.\p"
	.string "Jika Kamu ingin menginterupsi\n"
	.string "tantanganmu, tolong simpan\l"
	.string "permainan.\p"
	.string "Jika Kamu tidak menyimpan sebelum\n"
	.string "menginterupsi, Kamu akan\l"
	.string "didiskualifikasi.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "Untuk mengalahkan PAKAR ISTANA dan\n"
	.string "tujuh TRAINER berturut-turut…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "Untuk menghormati ikatan yang Kamu\n"
	.string "bagi dengan POKéMON-mu, kami\l"
	.string "memberimu Poin Pertarungan ini.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "Apakah Kamu ingin merekam\n"
	.string "pertandingan ISTANA PERTARUNGAN\l"
	.string "terbarumu di KARTU FRONTIER-mu?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "Aturan RUANG PERTARUNGAN tercantum.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "Judul mana yang ingin Kamu baca?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Di sini, POKéMON diwajibkan untuk\n"
	.string "berpikir dan bertarung sendiri.\p"
	.string "Tidak seperti di alam liar, POKéMON\n"
	.string "yang hidup dengan manusia\l"
	.string "berperilaku berbeda tergantung pada\l"
	.string "sifat mereka.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Bergantung pada sifatnya, POKéMON\n"
	.string "mungkin lebih suka menyerang apa\l"
	.string "pun yang terjadi.\p"
	.string "POKéMON lain mungkin lebih suka\n"
	.string "melindungi dirinya dari bahaya apa\l"
	.string "pun.\p"
	.string "Yang lain lagi mungkin suka\n"
	.string "mengganggu atau membingungkan\l"
	.string "musuhnya.\p"
	.string "Karena sifatnya, POKéMON akan\n"
	.string "memiliki jurus favorit yang pandai\l"
	.string "ia gunakan.\p"
	.string "Ia mungkin juga tidak menyukai\n"
	.string "jurus tertentu yang sulit ia\l"
	.string "gunakan.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Ada jurus ofensif yang menimbulkan\n"
	.string "kerusakan langsung pada lawan.\p"
	.string "Ada jurus defensif yang digunakan\n"
	.string "untuk bersiap menghadapi serangan\l"
	.string "musuh atau digunakan untuk\l"
	.string "menyembuhkan HP dan sebagainya.\p"
	.string "Ada juga jurus lain yang agak aneh\n"
	.string "yang dapat melemahkan musuh dengan\l"
	.string "masalah status termasuk racun dan\l"
	.string "kelumpuhan.\p"
	.string "POKéMON akan mempertimbangkan untuk\n"
	.string "menggunakan jurus dalam tiga\l"
	.string "kategori ini.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "Ketika tidak berada di bawah\n"
	.string "perintah TRAINER-nya, POKéMON\l"
	.string "mungkin tidak dapat secara efektif\l"
	.string "menggunakan jurus tertentu.\p"
	.string "POKéMON tidak pandai menggunakan\n"
	.string "jurus apa pun yang tidak\l"
	.string "disukainya.\p"
	.string "Jika POKéMON hanya mengetahui jurus\n"
	.string "yang tidak cocok dengan sifatnya,\l"
	.string "ia seringkali tidak dapat memenuhi\l"
	.string "potensinya.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "Bergantung pada sifatnya, POKéMON\n"
	.string "mungkin mulai menggunakan jurus\l"
	.string "yang tidak cocok dengan sifatnya\l"
	.string "ketika ia dalam masalah.\p"
	.string "Jika POKéMON mulai berperilaku aneh\n"
	.string "dalam keadaan genting, awasi dengan\l"
	.string "cermat.$"

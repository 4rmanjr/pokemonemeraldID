//gemini
BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "Di mana kecerdasan TRAINER diuji!\p"
	.string "Selamat datang di PABRIK\n"
	.string "PERTARUNGAN!\p"
	.string "Aku adalah pemandu Kamu untuk\n"
	.string "Turnamen Tunggal Tukar Pertarungan.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "Apakah Kamu ingin menerima\n"
	.string "tantangan Tunggal Tukar\l"
	.string "Pertarungan?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "Turnamen Tunggal Tukar Pertarungan\n"
	.string "adalah kompetisi PERTARUNGAN\l"
	.string "TUNGGAL yang hanya menggunakan\l"
	.string "POKéMON sewaan.\p"
	.string "Pertama, Kamu akan dipinjami tiga\n"
	.string "POKéMON khusus untuk acara ini.\p"
	.string "Menggunakan POKéMON sewaan yang\n"
	.string "disediakan, Kamu harus melakukan\l"
	.string "PERTARUNGAN TUNGGAL.\p"
	.string "Jika Kamu menang, Kamu diizinkan\n"
	.string "untuk menukar salah satu POKéMON\l"
	.string "sewaan Kamu.\p"
	.string "Ulangi siklus pertarungan dan\n"
	.string "penukaran ini--jika Kamu menang\l"
	.string "tujuh kali berturut-turut, Kamu\l"
	.string "akan mendapatkan Poin Pertarungan.\p"
	.string "Jika Kamu ingin menginterupsi\n"
	.string "tantangan Kamu, harap simpan\l"
	.string "permainan.\p"
	.string "Jika Kamu tidak menyimpan, Kamu\n"
	.string "akan didiskualifikasi dari\l"
	.string "tantangan Kamu.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Kami menantikan kunjungan Kamu\n"
	.string "berikutnya.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "Tingkat mana yang ingin Kamu\n"
	.string "tantang? Tingkat 50 atau Tingkat\l"
	.string "Terbuka?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Sebelum Kamu memulai tantangan\n"
	.string "Kamu, Aku perlu menyimpan\l"
	.string "permainan. Apakah tidak apa-apa?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "Baiklah, Aku akan menyimpan POKéMON\n"
	.string "Kamu untuk diamankan selama Kamu\l"
	.string "berkompetisi.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "Silakan ikuti Aku.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "Terima kasih atas partisipasi Kamu!\p"
	.string "Aku akan mengembalikan POKéMON Kamu\n"
	.string "sebagai ganti POKéMON sewaan kami.\p"
	.string "Aku juga harus menyimpan hasil\n"
	.string "acara. Mohon tunggu.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Aku akan mengembalikan POKéMON Kamu\n"
	.string "sebagai ganti POKéMON sewaan kami.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "Selamat! Kamu telah memenangkan\n"
	.string "tujuh pertandingan Tukar\l"
	.string "Pertarungan berturut-turut!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "Sebagai pengakuan atas 7 kemenangan\n"
	.string "beruntun Kamu, kami menghadiahkan\l"
	.string "Poin Pertarungan ini.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "Oh, oh, oh!\p"
	.string "Poin Pertarungan Kamu sudah\n"
	.string "maksimal.\p"
	.string "Silakan kembali setelah menggunakan\n"
	.string "sebagian Poin Pertarungan.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "Kami telah menunggu Kamu!\p"
	.string "Sebelum kami melanjutkan tantangan\n"
	.string "Kamu, Aku harus menyimpan\l"
	.string "permainan.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Aku menyesal mengatakan ini, tetapi\n"
	.string "Kamu tidak menyimpan sebelum\l"
	.string "berhenti bermain terakhir kali.\p"
	.string "Akibatnya, Kamu telah\n"
	.string "didiskualifikasi dari tantangan\l"
	.string "Kamu.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Kami akan mengembalikan POKéMON\n"
	.string "pribadi Kamu.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} menerima hadiah\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "Di mana kecerdasan TRAINER diuji!\p"
	.string "Selamat datang di PABRIK\n"
	.string "PERTARUNGAN!\p"
	.string "Aku adalah pemandu Kamu untuk\n"
	.string "Turnamen Ganda Tukar Pertarungan.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "Apakah Kamu ingin menerima\n"
	.string "tantangan Ganda Tukar Pertarungan?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "Turnamen Ganda Tukar Pertarungan\n"
	.string "adalah kompetisi PERTARUNGAN GANDA\l"
	.string "yang hanya menggunakan POKéMON\l"
	.string "sewaan.\p"
	.string "Pertama, Kamu akan dipinjami tiga\n"
	.string "POKéMON khusus untuk acara ini.\p"
	.string "Menggunakan POKéMON sewaan yang\n"
	.string "disediakan, Kamu harus melakukan\l"
	.string "PERTARUNGAN GANDA.\p"
	.string "Jika Kamu menang, Kamu diizinkan\n"
	.string "untuk menukar salah satu POKéMON\l"
	.string "sewaan Kamu.\p"
	.string "Ulangi siklus pertarungan dan\n"
	.string "penukaran ini--jika Kamu menang\l"
	.string "tujuh kali berturut-turut, Kamu\l"
	.string "akan mendapatkan Poin Pertarungan.\p"
	.string "Jika Kamu ingin menginterupsi\n"
	.string "tantangan Kamu, harap simpan\l"
	.string "permainan.\p"
	.string "Jika Kamu tidak menyimpan sebelum\n"
	.string "menginterupsi, Kamu akan\l"
	.string "didiskualifikasi.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "Selamat karena telah mengalahkan\n"
	.string "KEPALA PABRIK dan memenangkan tujuh\l"
	.string "pertandingan berturut-turut!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "Sebagai pengakuan atas kekayaan\n"
	.string "pengetahuan dan kecerdasan tajam\l"
	.string "Kamu, kami menghadiahkan Poin\l"
	.string "Pertarungan ini.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Izinkan Aku menukar POKéMON Kamu\n"
	.string "dengan POKéMON sewaan kami.\p"
	.string "Aku perlu menyimpan data\n"
	.string "pertarungan, jadi mohon tunggu.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "Apakah Kamu ingin merekam\n"
	.string "pertandingan PABRIK PERTARUNGAN\l"
	.string "terakhir Kamu di KARTU FRONTIER\l"
	.string "Kamu?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "Hai! Kamu, di sana!\p"
	.string "Apakah Kamu berpikir bahwa acara di\n"
	.string "sini mudah karena Kamu tidak perlu\l"
	.string "memiliki tim POKéMON yang\l"
	.string "dibesarkan?\p"
	.string "Aku tidak akan terlalu yakin\n"
	.string "tentang menang semudah itu.\p"
	.string "Jika Kamu tidak memiliki\n"
	.string "pengetahuan menyeluruh tentang\l"
	.string "POKéMON dan gerakan mereka, akan\l"
	.string "sulit untuk terus menang.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "Aku menukar dengan POKéMON yang\n"
	.string "lemah… Aku pikir itu jenis yang\l"
	.string "bagus untuk dimiliki…\p"
	.string "Mereka mengalahkan kami\n"
	.string "habis-habisan…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Segalanya tidak berjalan sesuai\n"
	.string "keinginanku sama sekali.\p"
	.string "Kamu perlu memeriksa POKéMON lawan\n"
	.string "Kamu selama pertarungan untuk\l"
	.string "melihat apakah mereka bagus.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "Kamu tahu bagaimana staf di sini\n"
	.string "memberi Kamu beberapa petunjuk\l"
	.string "tentang lawan Kamu berikutnya?\p"
	.string "Yah, aku pria dewasa, tetapi aku\n"
	.string "kesulitan memahami petunjuk mereka.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Seperti, aku benar-benar tangguh,\n"
	.string "tetapi aku mudah bosan, jadi aku\l"
	.string "terus menukar dan bertarung\l"
	.string "berulang kali.\p"
	.string "Jadi, ketika aku terus memasuki\n"
	.string "acara Tukar Pertarungan, aku\l"
	.string "menyadari bahwa mereka\l"
	.string "memvariasikan POKéMON sewaan.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "Aturan Tukar Pertarungan tercantum.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "Judul mana yang ingin Kamu baca?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "Dalam acara Tukar Pertarungan, Kamu\n"
	.string "hanya boleh menggunakan tiga\l"
	.string "POKéMON.\p"
	.string "Baik Kamu menyewa atau menukar, tim\n"
	.string "Kamu tidak boleh memiliki dua atau\l"
	.string "lebih POKéMON yang sama.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Kamu hanya boleh menukar POKéMON\n"
	.string "dengan TRAINER yang baru saja Kamu\l"
	.string "kalahkan.\p"
	.string "Kamu hanya boleh menukar POKéMON\n"
	.string "yang digunakan oleh TRAINER yang\l"
	.string "dikalahkan.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "Setelah setiap pertarungan yang\n"
	.string "Kamu menangkan, Kamu dapat menukar\l"
	.string "dengan salah satu POKéMON lawan\l"
	.string "yang Kamu kalahkan.\p"
	.string "Kamu tidak akan bisa menukar\n"
	.string "POKéMON dengan TRAINER ketujuh\l"
	.string "dalam acara tersebut.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Ada dua poin kunci yang perlu\n"
	.string "diperhatikan saat menukar POKéMON.\p"
	.string "Pertama, saat menukar, Kamu tidak\n"
	.string "dapat memeriksa statistik POKéMON\l"
	.string "yang akan Kamu terima.\p"
	.string "Kedua, POKéMON di tim Kamu berbaris\n"
	.string "berurutan, tergantung pada urutan\l"
	.string "Kamu menyewanya.\p"
	.string "Urutan ini tetap tidak berubah\n"
	.string "bahkan ketika penukaran dilakukan.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "Di Tingkat Terbuka, POKéMON sewaan\n"
	.string "dan POKéMON TRAINER lawan semuanya\l"
	.string "adalah Tingkat 100.$"

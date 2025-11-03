//gemini
BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "Tempat semangat bertarung TRAINER\n"
	.string "diuji!\p"
	.string "Aku menyambut kamu di BATTLE ARENA!\p"
	.string "Aku adalah pemandumu untuk Turnamen\n"
	.string "KO Set!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Sekarang, apakah kamu ingin\n"
	.string "mengambil tantangan BATTLE ARENA?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Kami menantikan tantangan kamu di\n"
	.string "lain kesempatan!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "Di BATTLE ARENA, kita melaksanakan\n"
	.string "Turnamen KO Set.\p"
	.string "Semua peserta masuk dengan tim\n"
	.string "berisi tiga POKéMON.\p"
	.string "Ketiga POKéMON harus diurutkan\n"
	.string "dalam urutan penampilan mereka.\p"
	.string "Selama pertarungan, POKéMON akan\n"
	.string "muncul satu per satu dalam urutan\l"
	.string "yang telah ditentukan.\p"
	.string "Setelah POKéMON masuk pertarungan,\n"
	.string "ia harus tetap di sana hingga\l"
	.string "pertandingan diputuskan.\p"
	.string "Jika pertandingan tetap tidak\n"
	.string "diputuskan dalam tiga giliran, itu\l"
	.string "akan dinilai.\p"
	.string "Jika kamu ingin mengganggu\n"
	.string "tantanganmu, silakan simpan\l"
	.string "permainan.\p"
	.string "Jika kamu tidak menyimpan, kamu\n"
	.string "tidak akan dapat melanjutkan\l"
	.string "tantangan kamu.\p"
	.string "Jika kamu berhasil mengalahkan\n"
	.string "tujuh TRAINER berturut-turut, kami\l"
	.string "akan memberikan kamu Battle Point.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Sebelum menunjukkan kamu ke BATTLE\n"
	.string "ARENA, kamu harus menyimpan. Apakah\l"
	.string "itu baik-baik saja?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "BATTLE ARENA menawarkan dua tingkat\n"
	.string "tantangan, Level 50 dan Level\l"
	.string "Terbuka. Mana pilihan kamu?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Baiklah, sekarang pilih tiga\n"
	.string "POKéMON kamu, silakan.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Penantangku yang terkasih!\p"
	.string "Kamu tidak memiliki tiga POKéMON\n"
	.string "yang diperlukan untuk masuk.\p"
	.string "Untuk memenuhi syarat, kamu harus\n"
	.string "membawa tiga jenis POKéMON yang\l"
	.string "berbeda.\p"
	.string "Mereka juga tidak boleh memegang\n"
	.string "jenis Item yang sama.\p"
	.string "TELUR{STR_VAR_1} tidak memenuhi\n"
	.string "syarat.\p"
	.string "Setelah kamu selesai dengan\n"
	.string "persiapan, silakan kembali.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Penantangku yang terkasih!\p"
	.string "Kamu tidak memiliki tiga POKéMON\n"
	.string "yang diperlukan untuk masuk.\p"
	.string "Untuk memenuhi syarat, kamu harus\n"
	.string "membawa tiga jenis POKéMON yang\l"
	.string "berbeda.\p"
	.string "Ketiga POKéMON yang berbeda itu\n"
	.string "harus Level 50 atau lebih rendah.\p"
	.string "Mereka juga tidak boleh memegang\n"
	.string "jenis Item yang sama.\p"
	.string "TELUR{STR_VAR_1} tidak memenuhi\n"
	.string "syarat.\p"
	.string "Setelah kamu selesai dengan\n"
	.string "persiapan, silakan kembali.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Aku sekarang akan memandu kamu ke\n"
	.string "BATTLE ARENA.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Penantangku yang terkasih!\p"
	.string "Kamu tidak menyimpan permainan\n"
	.string "sebelum mematikan, bukan?\p"
	.string "Sangat disayangkan, tetapi itu\n"
	.string "mengakibatkan diskualifikasi kamu\l"
	.string "dari tantangan kamu.\p"
	.string "Tentu saja, kamu dapat memulai\n"
	.string "dengan tantangan baru.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Kami mengucapkan selamat atas\n"
	.string "rentetan kemenangan luar biasa kamu\l"
	.string "atas tujuh TRAINER!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Pencapaian kamu akan dicatat. Mohon\n"
	.string "tunggu selagi Aku menyimpan\l"
	.string "permainan.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "Untuk memperingati 7 kemenangan\n"
	.string "beruntun kamu, kami memberikan kamu\l"
	.string "hadiah ini.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} menerima hadiah\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Oh? TAS kamu sepertinya penuh.\p"
	.string "Aku mendesak kamu untuk\n"
	.string "mengosongkan ruang dan kembali\l"
	.string "untuk hadiah kamu.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Terima kasih banyak atas\n"
	.string "partisipasi kamu!\p"
	.string "Mohon tunggu selagi Aku menyimpan\n"
	.string "permainan.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Kami menantikan tantangan kamu di\n"
	.string "lain kesempatan!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Kami telah menantikan kedatangan\n"
	.string "kamu.\p"
	.string "Sebelum Aku menunjukkan kamu ke\n"
	.string "BATTLE ARENA, Aku harus menyimpan\l"
	.string "permainan. Mohon tunggu.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Haruskah Aku merekam pertandingan\n"
	.string "BATTLE ARENA terakhir kamu di\l"
	.string "FRONTIER PASS kamu?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "Aku kalah atas keputusan WASIT…\p"
	.string "Aku tidak berpikir itu ide yang\n"
	.string "baik untuk hanya menggunakan\l"
	.string "gerakan defensif dan tidak\l"
	.string "menyerang…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "Aku menang dalam penilaian!\p"
	.string "Mendaratkan serangan secara\n"
	.string "konsisten pada POKéMON lawan\l"
	.string "berhasil!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Pertandingan kami dinyatakan seri.\p"
	.string "Ketika kami kehabisan waktu, baik\n"
	.string "POKéMON-ku maupun POKéMON lawan\l"
	.string "memiliki jumlah HP yang hampir sama\l"
	.string "tersisa.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "Di BATTLE ARENA, urutan POKéMON\n"
	.string "benar-benar penting.\p"
	.string "Contohnya, jika POKéMON pertama\n"
	.string "kamu memiliki kelemahan tipe\l"
	.string "tertentu, coba jadikan POKéMON\l"
	.string "kedua kamu salah satu dengan\l"
	.string "gerakan yang sangat efektif\l"
	.string "melawannya.\p"
	.string "Aku pikir itu akan menjadi cara\n"
	.string "yang baik untuk membuat tim yang\l"
	.string "efektif.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Aturan Turnamen KO Set tercantum.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Judul mana yang ingin kamu baca?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "Turnamen KO Set memiliki aturan\n"
	.string "khusus, tidak seperti pertarungan\l"
	.string "standar.\p"
	.string "Pertama, satu pertarungan hanya\n"
	.string "berlangsung tiga giliran.\p"
	.string "Jika hasilnya tidak diputuskan\n"
	.string "setelah tiga giliran, itu akan\l"
	.string "dinilai.\p"
	.string "WASIT akan memilih pemenang\n"
	.string "berdasarkan bagaimana POKéMON\l"
	.string "bertarung.\p"
	.string "Juga, POKéMON tidak dapat diganti\n"
	.string "keluar sampai hasil pertarungannya\l"
	.string "diputuskan.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "Faktor penilaian pertama adalah\n"
	.string "“Pikiran.” Faktor ini mengevaluasi\l"
	.string "seberapa agresif para petarung.\p"
	.string "Penilaian didasarkan pada seberapa\n"
	.string "sering TRAINER memerintahkan\l"
	.string "penggunaan gerakan ofensif.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "Faktor penilaian kedua adalah\n"
	.string "“Keahlian.” Faktor ini mengevaluasi\l"
	.string "seberapa efektif gerakan POKéMON\l"
	.string "digunakan.\p"
	.string "Jika suatu gerakan berhasil,\n"
	.string "peringkat Keahlian naik.\p"
	.string "Jika suatu gerakan gagal, peringkat\n"
	.string "Keahlian diturunkan.\p"
	.string "Jika itu adalah gerakan ofensif,\n"
	.string "peringkat Keahlian naik jika\l"
	.string "gerakan itu “sangat efektif” atau\l"
	.string "“kurang efektif.” Peringkat\l"
	.string "Keahlian tidak akan naik untuk\l"
	.string "gerakan seperti PROTECT dan DETECT.\p"
	.string "Jika lawan menggunakan PROTECT atau\n"
	.string "DETECT, dan POKéMON kamu gagal\l"
	.string "menyerang dengan suatu gerakan,\l"
	.string "peringkat Keahliannya tidak akan\l"
	.string "turun.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "Faktor penilaian ketiga adalah\n"
	.string "“Badan.” Faktor ini didasarkan pada\l"
	.string "seberapa banyak HP yang tersisa\l"
	.string "pada akhir pertarungan.\p"
	.string "Peringkat memperhitungkan berapa\n"
	.string "banyak HP yang dimiliki POKéMON\l"
	.string "pada awal pertarungan, dan apa yang\l"
	.string "tersisa pada akhirnya.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Kemenangan direbut dari ARENA\n"
	.string "TYCOON, dan sapuan tujuh TRAINER!\p"
	.string "Kami mengucapkan selamat atas\n"
	.string "tantangan kamu yang paling luar\l"
	.string "biasa!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Penantangku yang terkasih, sebagai\n"
	.string "pengakuan atas semangat kamu yang\l"
	.string "tak kenal lelah, terimalah Battle\l"
	.string "Point ini.$"

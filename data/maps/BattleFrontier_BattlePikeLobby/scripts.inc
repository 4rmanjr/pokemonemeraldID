//gemini
BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitstate
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "Di mana keberuntungan TRAINER\n"
	.string "diuji…\p"
	.string "Selamat datang di BATTLE PIKE…\p"
	.string "Aku adalah pemandumu ke BATTLE\n"
	.string "PIKE…$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "Maukah Kamu mengikuti tantangan\n"
	.string "Pilihan Pertarungan?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "Di sini kami mengadakan acara yang\n"
	.string "kami sebut Pilihan Pertarungan.\p"
	.string "Aturan Pilihan Pertarungan sangat\n"
	.string "sederhana…\p"
	.string "Pilih satu dari tiga jalur dan buat\n"
	.string "jalanmu ke ruang tujuan di ujung\l"
	.string "BATTLE PIKE. Sesederhana itu.\p"
	.string "Namun, apa yang terjadi di jalur\n"
	.string "yang dipilih sepenuhnya bergantung\l"
	.string "pada keberuntungan penantang…\p"
	.string "Jika Kamu mencapai tujuan, Kamu\n"
	.string "akan diberi hadiah Poin\l"
	.string "Pertarungan.\p"
	.string "Jika Kamu ingin menghentikan\n"
	.string "tantanganmu, silakan bicara dengan\l"
	.string "staf kami di ruangan besar di\l"
	.string "jalan.\p"
	.string "Jika Kamu tidak menyimpan sebelum\n"
	.string "menginterupsi, Kamu akan\l"
	.string "didiskualifikasi.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "Kami berharap dapat melihatmu di\n"
	.string "kesempatan lain…$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "Kamu memiliki pilihan dua jalur,\n"
	.string "Level 50 dan Level Terbuka. Mana\l"
	.string "yang akan Kamu tantang?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "Aku mohon maaf, tapi…\p"
	.string "Kamu tidak memiliki tiga POKéMON\n"
	.string "yang memenuhi syarat untuk acara\l"
	.string "Pilihan Pertarungan.\p"
	.string "Kamu harus memiliki tiga POKéMON\n"
	.string "berbeda dengan Level 50 atau kurang\l"
	.string "untuk masuk.\p"
	.string "Mereka juga harus memegang jenis\n"
	.string "item yang berbeda.\p"
	.string "TELUR{STR_VAR_1} tidak memenuhi\n"
	.string "syarat.\p"
	.string "Silakan datang temui Aku ketika\n"
	.string "Kamu siap…$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Aku mohon maaf, tapi…\p"
	.string "Kamu tidak memiliki tiga POKéMON\n"
	.string "yang memenuhi syarat untuk acara\l"
	.string "Pilihan Pertarungan.\p"
	.string "Kamu harus memiliki tiga POKéMON\n"
	.string "berbeda untuk masuk.\p"
	.string "Mereka juga harus memegang jenis\n"
	.string "item yang berbeda.\p"
	.string "TELUR{STR_VAR_1} tidak memenuhi\n"
	.string "syarat.\p"
	.string "Silakan datang temui Aku ketika\n"
	.string "Kamu siap…$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "Silakan pilih tiga POKéMON yang\n"
	.string "ingin Kamu masukkan dalam\l"
	.string "tantangan…$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "Sebelum memulai tantangan Pilihan\n"
	.string "Pertarunganmu, Aku harus menyimpan\l"
	.string "permainan. Apakah ini dapat\l"
	.string "diterima?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "Silakan ikuti Aku…$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "Tantanganmu telah berakhir…\p"
	.string "Aku akan mencatat hasilmu. Mohon\n"
	.string "tunggu…$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "Kamu telah menyelesaikan tantangan…\p"
	.string "Aku harus mengatakan… Kamu\n"
	.string "tampaknya memiliki keberuntungan\l"
	.string "yang melimpah…$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "Aku akan mencatat hasilmu. Mohon\n"
	.string "tunggu…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "Untuk memperingati penyelesaian\n"
	.string "tantangan Pilihan Pertarunganmu,\l"
	.string "kami memberimu Poin Pertarungan\l"
	.string "ini…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "Kamu tampaknya telah mencapai batas\n"
	.string "untuk Poin Pertarungan…\p"
	.string "Silakan tukarkan beberapa Poin\n"
	.string "Pertarungan dengan hadiah, lalu\l"
	.string "kembali…$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "Aku mohon maaf, tapi…\p"
	.string "Kamu gagal menyimpan sebelum Kamu\n"
	.string "mengakhiri tantanganmu terakhir\l"
	.string "kali.\p"
	.string "Karena itu, tantanganmu sejauh ini\n"
	.string "didiskualifikasi. Aku minta maaf…$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "Selamat…\p"
	.string "Kamu telah merebut kemenangan dari\n"
	.string "RATU PIKE dan menyelesaikan acara…$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "Sebagai pengakuan atas\n"
	.string "keberuntunganmu yang luar biasa,\l"
	.string "kami memberimu Poin Pertarungan\l"
	.string "ini…$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "Arrgh! Aku menyia-nyiakan\n"
	.string "kesempatanku! Aku hanya satu\l"
	.string "ruangan lagi dari tujuan!\p"
	.string "Di tempat ini, lebih baik Kamu\n"
	.string "berhati-hati terhadap racun,\l"
	.string "pembekuan, dan sebagainya.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "Aku sudah menyelesaikan tantangan\n"
	.string "10 kali sekarang, tapi Aku tidak\l"
	.string "pernah harus melawan TRAINER sekali\l"
	.string "pun.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "Dengar! Dengar!\p"
	.string "Tidakkah Kamu berpikir bahwa\n"
	.string "kemampuan khusus POKéMON akan\l"
	.string "berguna di sini?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "Tempat aneh apa ini? Aku tidak bisa\n"
	.string "memahaminya sama sekali!\p"
	.string "Aku sudah mengikuti tantangan\n"
	.string "berkali-kali, tapi yang Aku lakukan\l"
	.string "hanyalah bertemu TRAINER di jalur\l"
	.string "mana pun yang Aku pilih.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "Aturan Pilihan Pertarungan\n"
	.string "terdaftar.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "Judul mana yang ingin Kamu baca?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "TAS dan POKéNAV tidak boleh\n"
	.string "digunakan selama tantangan Pilihan\l"
	.string "Pertarungan.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "Selama tantangan Pilihan\n"
	.string "Pertarungan, BERRY atau HERB apa\l"
	.string "pun yang dipegang oleh POKéMON\l"
	.string "hanya akan efektif sekali.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "Selama tantangan Pilihan\n"
	.string "Pertarungan, urutan POKéMON tidak\l"
	.string "dapat diubah.\p"
	.string "Urutan harus diatur sebelum memulai\n"
	.string "tantanganmu.$"

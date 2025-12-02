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
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
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
	.string "Aku adalah pemandumu di BATTLE PIKE…$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "Apakah kamu ingin mengikuti Battle\n"
	.string "Choice challenge?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "Di sini kami mengadakan acara yang\n"
	.string "kami sebut Battle Choice.\p"
	.string "Aturan Battle Choice sangat\n"
	.string "sederhana…\p"
	.string "Pilih satu dari tiga jalur & capai\n"
	.string "ruang tujuan di ujung BATTLE PIKE.\l"
	.string "Sesederhana itu.\p"
	.string "Namun, apa yang terjadi di jalur\n"
	.string "yang dipilih sepenuhnya tergantung\l"
	.string "pada keberuntungan penantang…\p"
	.string "Jika kamu mencapai tujuan, kamu akan\n"
	.string "dihadiahi Battle Point.\p"
	.string "Jika kamu ingin menghentikan\n"
	.string "tantanganmu, bicaralah dengan staf\l"
	.string "kami di ruangan besar di jalan.\p"
	.string "Jika kamu tidak menyimpan sebelum\n"
	.string "menghentikan, kamu akan\l"
	.string "didiskualifikasi.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "Kami menantikan kedatanganmu\n"
	.string "di lain kesempatan…$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "Kamu punya pilihan dua jalur,\n"
	.string "Level 50 & Level Bebas.\l"
	.string "Yang mana yang akan kamu tantang?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "Maafkan aku, tapi…\p"
	.string "Kamu tidak punya tiga POKéMON yang\n"
	.string "memenuhi syarat untuk acara Battle\l"
	.string "Choice.\p"
	.string "Kamu harus punya tiga POKéMON\n"
	.string "berbeda dengan Level 50 atau kurang\l"
	.string "untuk masuk.\p"
	.string "Mereka juga harus memegang jenis\n"
	.string "item yang berbeda.\p"
	.string "TELUR{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd:
	.string "Silakan datang menemuiku saat\n"
	.string "kamu siap…$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Maafkan aku, tapi…\p"
	.string "Kamu tidak punya tiga POKéMON yang\n"
	.string "memenuhi syarat untuk acara Battle\l"
	.string "Choice.\p"
	.string "Kamu harus punya tiga POKéMON\n"
	.string "berbeda untuk masuk.\p"
	.string "Mereka juga harus memegang jenis\n"
	.string "item yang berbeda.\p"
	.string "TELUR{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "Silakan pilih tiga POKéMON yang\n"
	.string "ingin kamu masukkan dalam\l"
	.string "tantangan…$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "Sebelum memulai tantangan Battle\n"
	.string "Choice-mu, aku harus menyimpan\l"
	.string "permainan. Apakah itu bisa\l"
	.string "diterima?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "Silakan lewat sini…$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "Tantanganmu telah berakhir…\p"
	.string "Aku akan mencatat hasilmu.\n"
	.string "Mohon tunggu…$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "Kamu telah menyelesaikan\n"
	.string "tantangan…\p"
	.string "Aku harus bilang… Kamu sepertinya\n"
	.string "punya keberuntungan berlimpah…$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "Aku akan mencatat hasilmu.\n"
	.string "Mohon tunggu…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "Untuk memperingati penyelesaian\n"
	.string "tantangan Battle Choice-mu, kami\l"
	.string "memberimu Battle Point ini…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "Kamu sepertinya telah mencapai\n"
	.string "batas Battle Point…\p"
	.string "Silakan tukarkan beberapa Battle\n"
	.string "Point untuk hadiah, lalu kembali…$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "Maafkan aku, tapi…\p"
	.string "Kamu gagal menyimpan sebelum kamu\n"
	.string "berhenti dari tantanganmu terakhir\l"
	.string "kali.\p"
	.string "Karena itu, tantanganmu sejauh ini\n"
	.string "telah didiskualifikasi. Aku minta\l"
	.string "maaf…$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "Selamat…\p"
	.string "Kamu telah merebut kemenangan dari\n"
	.string "PIKE QUEEN & menyelesaikan acara\l"
	.string "ini…$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "Sebagai pengakuan atas\n"
	.string "keberuntunganmu yang luar biasa,\l"
	.string "kami memberimu Battle Point ini…$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "Arrgh! Aku menyia-nyiakan\n"
	.string "kesempatanku!\p"
	.string "Aku hanya satu ruangan lagi dari\n"
	.string "tujuan!\p"
	.string "Di tempat ini, kamu sebaiknya\n"
	.string "hati-hati terhadap racun,\l"
	.string "pembekuan, & sebagainya.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "Aku sudah menyelesaikan tantangan\n"
	.string "10 kali, tapi aku belum pernah\l"
	.string "harus melawan TRAINER sekali pun.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "Dengar! Dengar!\p"
	.string "Tidakkah kamu pikir kemampuan\n"
	.string "spesial POKéMON akan berguna\l"
	.string "di sini?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "Tempat aneh apa ini?\n"
	.string "Aku tidak bisa memahaminya sama\l"
	.string "sekali!\p"
	.string "Aku sudah mengikuti tantangan\n"
	.string "berkali-kali, tapi yang kulakukan\l"
	.string "hanyalah bertemu TRAINER di jalur\l"
	.string "mana pun yang kupilih.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "Aturan Battle Choice tercantum.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "Judul mana yang ingin kamu baca?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "TAS & POKéNAV tidak boleh\n"
	.string "digunakan selama tantangan Battle\l"
	.string "Choice.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "Selama tantangan Battle Choice,\n"
	.string "BERRY atau HERB apa pun yang\l"
	.string "dipegang POKéMON hanya akan\l"
	.string "efektif sekali.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "Selama tantangan Battle Choice,\n"
	.string "urutan POKéMON tidak bisa\l"
	.string "diubah.\p"
	.string "Urutan harus diatur sebelum\n"
	.string "memulai tantanganmu.$"

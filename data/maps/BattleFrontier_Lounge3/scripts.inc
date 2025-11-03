BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…Apa maumu?\p"
	.string "Tidak bisakah kamu lihat kami sedang sibuk?\n"
	.string "Tidak bisakah urusanmu menunggu nanti?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Hah?\n"
	.string "Kamu terlihat seperti TRAINER yang tangguh.\p"
	.string "Heheh…\n"
	.string "Dengar, aku punya tawaran.\p"
	.string "Kami punya grup kecil di sini,\n"
	.string "dan kami memainkan permainan kecil dengan apa\l"
	.string "yang terjadi di BATTLE FRONTIER.\p"
	.string "Aturannya sangat sederhana.\p"
	.string "Pertama, kami memilih salah satu fasilitas\n"
	.string "di BATTLE FRONTIER.\p"
	.string "Lalu, kami masing-masing memilih TRAINER\n"
	.string "berbeda yang mengikuti tantangan fasilitas itu,\l"
	.string "dan bertaruh dengan Battle Point kami.\p"
	.string "Orang yang bertaruh pada TRAINER dengan\n"
	.string "rekor terbaik akan mengambil semua Battle\l"
	.string "Point yang terkumpul.\p"
	.string "Terdengar sederhana, kan?\n"
	.string "Jadi, begini…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan menantang RUANG SINGLE BATTLE\l"
	.string "di BATTLE TOWER.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan menantang RUANG DOUBLE BATTLE\l"
	.string "di BATTLE TOWER.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan menantang RUANG MULTI BATTLE\l"
	.string "di BATTLE TOWER.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan memasuki Turnamen SINGLE BATTLE\l"
	.string "di BATTLE DOME.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan memasuki Turnamen DOUBLE BATTLE\l"
	.string "di BATTLE DOME.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan memasuki Turnamen Battle Swap Single\l"
	.string "di BATTLE FACTORY.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan memasuki Turnamen Battle Swap Double\l"
	.string "di BATTLE FACTORY.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan menantang AULA SINGLE BATTLE\l"
	.string "di BATTLE PALACE.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan menantang AULA DOUBLE BATTLE\l"
	.string "di BATTLE PALACE.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan memasuki Turnamen Set KO\l"
	.string "di BATTLE ARENA.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan memasuki Battle Choice\l"
	.string "di BATTLE PIKE.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Yang kucari adalah seorang TRAINER yang\n"
	.string "akan memasuki Battle Quest\l"
	.string "di BATTLE PYRAMID.\p"
	.string "Tapi sejauh ini, aku belum melihat TRAINER\n"
	.string "yang memiliki kualitas pemenang.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Aku akan pastikan kamu juga mendapat keuntungan.\n"
	.string "Jadi bagaimana?\l"
	.string "Bagaimana kalau mengikuti acara itu untukku?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Baiklah, itu sempurna.\n"
	.string "Jadi, uh… Bagaimana kalau kamu meminjamiku\l"
	.string "beberapa Battle Point-mu?\p"
	.string "Percayalah, aku akan menunjukkan rasa\n"
	.string "terima kasihku nanti.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Bagus, bagus!\n"
	.string "Jadi, berapa banyak yang bisa kamu pinjamkan?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh, tidak, tidak, tidak!\n"
	.string "Battle Point-mu tidak cukup!\p"
	.string "Jangan main-main dan\n"
	.string "membuang-buang waktu semua orang!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Heheh! Terima kasih banyak!\n"
	.string "Sekarang, pergilah!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Segera ke RUANG SINGLE BATTLE\n"
	.string "di BATTLE TOWER!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Segera ke RUANG DOUBLE BATTLE\n"
	.string "di BATTLE TOWER!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"


BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Segera ke RUANG MULTI BATTLE\n"
	.string "di BATTLE TOWER!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Segera ke Turnamen SINGLE BATTLE\n"
	.string "di BATTLE DOME!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Segera ke Turnamen DOUBLE BATTLE\n"
	.string "di BATTLE DOME!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Segera ke Turnamen Battle Swap Single\n"
	.string "di BATTLE FACTORY!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Segera ke Turnamen Battle Swap Double\n"
	.string "di BATTLE FACTORY!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Segera ke AULA SINGLE BATTLE\n"
	.string "di BATTLE PALACE!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Segera ke AULA DOUBLE BATTLE\n"
	.string "di BATTLE PALACE!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Segera ke Turnamen Set KO\n"
	.string "di BATTLE ARENA!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Segera ke Battle Choice\n"
	.string "di BATTLE PIKE!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Segera ke Battle Quest\n"
	.string "di BATTLE PYRAMID!\p"
	.string "Ini adalah situasi yang harus dimenangkan!\n"
	.string "Jangan sia-siakan kesempatanmu!\l"
	.string "Masa depan kita berdua bergantung padamu!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, itu kamu…\n"
	.string "Usaha yang bagus…\p"
	.string "Aku benci mengatakannya, tapi aku tidak bisa\n"
	.string "mengembalikan Battle Point-mu…\p"
	.string "Kurasa kita harus menjadikannya motivasi\n"
	.string "untuk berusaha lebih keras lain kali!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh, ya!\n"
	.string "Halo, juara!\p"
	.string "Aku tahu kamu bisa!\n"
	.string "Aku tahu kamu akan melakukannya!\l"
	.string "Kita berdua pemenang besar!\p"
	.string "Aku akan mengembalikan Battle Point-mu dan,\n"
	.string "tentu saja, sedikit tambahan dariku!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} mendapatkan\n"
	.string "{STR_VAR_1} Battle Point.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Jika kamu siap untuk tantangan lain,\n"
	.string "tolong ingat aku!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Tidak tertarik?! Kamu seharusnya tidak\n"
	.string "begitu takut mengambil kesempatan!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "Aku salah mendukung TRAINER lagi!\p"
	.string "Mungkin aku harus bertarung normal\n"
	.string "seperti orang lain…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "TRAINER itu…\p"
	.string "Dia bagus, tapi dia terlalu mudah\n"
	.string "gugup untuk bertahan di BATTLE DOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Terkikik!\n"
	.string "Aku tahu seorang pemenang saat melihatnya!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Para TRAINER itu…\n"
	.string "Apa yang mereka lakukan?\l"
	.string "Seharusnya mereka mengambil tantangan.$"


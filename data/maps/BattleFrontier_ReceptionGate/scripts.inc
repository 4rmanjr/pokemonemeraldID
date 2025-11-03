BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "Apakah ini pertama kalinya kamu ke sini?\n"
	.string "Silakan lewat sini!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "Garis depan pertarungan POKéMON!\n"
	.string "Selamat datang di BATTLE FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Untuk pengunjung pertama kali, kami\n"
	.string "menerbitkan FRONTIER PASS.\p"
	.string "Ini untuk digunakan di semua fasilitas\n"
	.string "di BATTLE FRONTIER.\p"
	.string "Ini dia!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "FRONTIER PASS\n"
	.string "didapatkan.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "TRAINER CARD diletakkan\n"
	.string "di dalam FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Kami harap kamu menikmati semua yang\n"
	.string "BATTLE FRONTIER tawarkan!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Wah, bukankah itu {PLAYER}{KUN}!\n"
	.string "Kamu datang ke sini!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "PANDUAN: Oh! Tuan SCOTT!\n"
	.string "Selamat siang, Tuan!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: Senang bertemu denganmu di sini,\n"
	.string "aku serius!\p"
	.string "Aku harap kamu tidak terburu-buru dan\n"
	.string "menjelajahi semuanya.\p"
	.string "Tentu saja, aku harap kamu juga merasakan\n"
	.string "esensi murni dari pertarungan.\p"
	.string "Aku juga punya kamar di sini, jadi jangan\n"
	.string "sungkan untuk berkunjung jika ada waktu.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Aku pemandumu untuk berbagai fasilitas\n"
	.string "di BATTLE FRONTIER ini.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Mana yang ingin kamu ketahui?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "Itu adalah menara raksasa yang dianggap\n"
	.string "sebagai simbol BATTLE FRONTIER.\p"
	.string "Ada empat jenis BATTLE ROOMS\n"
	.string "di menara untuk SINGLE, DOUBLE, MULTI,\l"
	.string "dan LINK MULTI BATTLE.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "BATTLE DOME adalah bangunan besar\n"
	.string "berbentuk seperti telur raksasa.\p"
	.string "Acara bernama Battle Tourney diadakan\n"
	.string "di fasilitas ini.\p"
	.string "Battle Tourney ditawarkan dalam\n"
	.string "dua jalur--untuk SINGLE dan DOUBLE\l"
	.string "BATTLE.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "BATTLE PALACE adalah bangunan merah\n"
	.string "di sebelah kanan BATTLE FRONTIER.\p"
	.string "Ada dua jenis BATTLE HALLS\n"
	.string "untuk SINGLE dan DOUBLE BATTLE.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "BATTLE ARENA adalah bangunan seperti dojo\n"
	.string "di tengah-kanan\l"
	.string "BATTLE FRONTIER.\p"
	.string "Sebuah acara bernama Set KO Tourney\n"
	.string "berlangsung di BATTLE ARENA.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "BATTLE FACTORY adalah bangunan besar\n"
	.string "yang paling dekat dengan kita.\p"
	.string "Sebuah acara bernama Battle Swap\n"
	.string "diadakan di sana.\p"
	.string "Acara Battle Swap ditawarkan dalam\n"
	.string "dua jalur untuk SINGLE dan DOUBLE\l"
	.string "BATTLE.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "BATTLE PIKE adalah bangunan berbentuk\n"
	.string "seperti POKéMON di tengah-kiri\l"
	.string "BATTLE FRONTIER.\p"
	.string "Sebuah acara bernama Battle Choice\n"
	.string "diadakan di sana.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "BATTLE PYRAMID adalah piramida yang\n"
	.string "sangat besar.\p"
	.string "Sebuah acara bernama Battle Quest\n"
	.string "diadakan di sana.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "RANKING HALL terletak di dekat\n"
	.string "BATTLE TOWER.\p"
	.string "Di sana, kamu bisa melihat rekor paling\n"
	.string "fantastis yang ditinggalkan oleh para\l"
	.string "TRAINER yang menghadapi banyak\l"
	.string "tantangan di BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "EXCHANGE SERVICE CORNER ada di dekat\n"
	.string "BATTLE TOWER.\p"
	.string "Battle Point yang kamu dapatkan di\n"
	.string "BATTLE FRONTIER dapat ditukar\l"
	.string "dengan hadiah-hadiah luar biasa di sana.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Aku pemandumu untuk aturan dasar yang\n"
	.string "umum untuk semua tantangan\l"
	.string "yang ditawarkan oleh fasilitas di BATTLE\l"
	.string "FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Apa yang ingin kamu pelajari?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Semua tantangan di fasilitas BATTLE\n"
	.string "FRONTIER tersedia dalam\l"
	.string "dua jalur--Level 50 dan Open Level.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Jalur Level 50 terbuka untuk POKéMON\n"
	.string "hingga Level 50.\p"
	.string "Namun, perlu diingat, TRAINER yang\n"
	.string "kamu hadapi tidak akan memiliki\l"
	.string "POKéMON di bawah Level 50.\p"
	.string "Jalur ini adalah level awal untuk\n"
	.string "pertarungan di BATTLE FRONTIER.\p"
	.string "Sebagai permulaan, kami harap kamu akan\n"
	.string "menantang jalur ini.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Jalur Open Level tidak membatasi\n"
	.string "level POKéMON yang memasuki\l"
	.string "tantangan.\p"
	.string "Level lawanmu akan\n"
	.string "disesuaikan agar cocok dengan level\l"
	.string "POKéMON milikmu.\p"
	.string "Namun, TRAINER yang kamu hadapi tidak\n"
	.string "akan memiliki POKéMON di bawah Level 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Hampir semua jenis POKéMON dapat\n"
	.string "mengikuti tantangan di semua fasilitas.\p"
	.string "Namun, EGG dan jenis POKéMON tertentu\n"
	.string "tidak diizinkan.\p"
	.string "Jumlah POKéMON yang dibutuhkan untuk\n"
	.string "tantangan akan tergantung pada fasilitas.\p"
	.string "Namun, di semua fasilitas, dua atau lebih\n"
	.string "jenis POKéMON yang sama tidak\l"
	.string "diizinkan.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Saat memasuki tantangan di fasilitas\n"
	.string "BATTLE FRONTIER, POKéMON tidak boleh\l"
	.string "memegang item yang sama.\p"
	.string "Pastikan semua POKéMON yang memasuki\n"
	.string "tantangan memegang item yang\l"
	.string "berbeda.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Aku pemandumu untuk FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Mana yang ingin kamu ketahui?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Ada tujuh fasilitas di\n"
	.string "BATTLE FRONTIER.\p"
	.string "TRAINER yang mendapatkan pengakuan atas\n"
	.string "kemampuan mereka akan dihadiahi\l"
	.string "simbol dari setiap fasilitas.\p"
	.string "Untuk mendapatkan simbol, TRAINER mungkin\n"
	.string "perlu mengalahkan TRAINER lain berturut-turut,\l"
	.string "dan mungkin perlu memenangkan acara berulang kali.\p"
	.string "Tentu tidak mudah untuk memenangkan simbol.\n"
	.string "Semoga kamu beruntung!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Satu pertarungan dapat direkam\n"
	.string "di FRONTIER PASS milikmu.\p"
	.string "Kamu dapat merekam pertarungan yang kamu\n"
	.string "lakukan dengan seorang teman atau teman-teman.\p"
	.string "Atau kamu dapat merekam pertarungan yang\n"
	.string "dilakukan di BATTLE FRONTIER, tidak\l"
	.string "termasuk pertarungan di BATTLE PIKE atau\l"
	.string "di BATTLE PYRAMID.\p"
	.string "Kamu dapat memilih untuk merekam\n"
	.string "pertarunganmu di akhir pertarungan.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Battle Point adalah hadiah yang diberikan\n"
	.string "kepada TRAINER yang bertarung dengan\l"
	.string "luar biasa di BATTLE FRONTIER.\p"
	.string "Kamu dapat menukarkan Battle Point\n"
	.string "milikmu dengan hadiah di EXCHANGE\l"
	.string "SERVICE CORNER.$"


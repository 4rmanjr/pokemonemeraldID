SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideplayer
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "Maaf, apa? Kamu mencari kapal?\p"
	.string "Maaf, layanan feri belum tersedia\n"
	.string "saat ini…$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "Halo, apa Kamu di sini untuk feri?\n"
	.string "Boleh Aku lihat TIKET-mu?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER} tidak punya TIKET…\p"
	.string "Aku benar-benar minta maaf.\p"
	.string "Kamu harus punya TIKET untuk naik\n"
	.string "feri.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER} memperlihatkan TIKET.\p"
	.string "Sempurna! Itu saja yang Kamu\n"
	.string "butuhkan!\p"
	.string "Dan Kamu ingin pergi ke mana?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "Silakan berlayar bersama kami lain\n"
	.string "waktu!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "LILYCOVE CITY, kalau begitu!$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "BATTLE FRONTIER, kalau begitu!$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "Silakan naik feri dan tunggu\n"
	.string "keberangkatan.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Jadi, Kamu ingin pergi ke mana?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "Perjalanan ke dasar laut… Aku ingin\n"
	.string "tahu akan seperti apa rasanya?\p"
	.string "Aku ingin sekali pergi jauh di\n"
	.string "bawah air seperti itu suatu hari\l"
	.string "nanti.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "Agar kapal bisa berlayar dengan\n"
	.string "aman, kita harus tahu tentang\l"
	.string "cuaca!\p"
	.string "Ngomong-ngomong soal cuaca, Aku\n"
	.string "dengar sesuatu dari seseorang di\l"
	.string "INSTITUT CUACA.\p"
	.string "Dia bilang cuaca abnormal telah\n"
	.string "dilaporkan di mana-mana!\p"
	.string "Kamu harus mengunjungi INSTITUT\n"
	.string "CUACA dan bertanya-tanya!$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "Aku ingin ikut dengan KAPT. STERN\n"
	.string "dalam eksplorasi dasar samudra.\p"
	.string "Tapi kapal selam itu terlalu kecil\n"
	.string "untuk Aku.\p"
	.string "Jika Aku memaksakan diri masuk,\n"
	.string "tidak akan ada ruang untuk SANG\l"
	.string "KAPTEN…$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "KAPT. STERN: Preman-preman itu…\p"
	.string "Mereka adalah kelompok yang sama\n"
	.string "yang mencoba merampok BARANG DEVON\l"
	.string "di MUSEUM.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "ARCHIE: Oh? Bukan Kamu lagi…\p"
	.string "Kamu gigih melacak kami ke sini,\n"
	.string "Aku akui itu.\p"
	.string "Tapi sekarang… Tidak ada yang bisa\n"
	.string "menghentikan kami! Tidak ada!\p"
	.string "Atau, maukah Kamu mengikuti kami\n"
	.string "kembali ke MARKAS kami di LILYCOVE\l"
	.string "CITY?\p"
	.string "Fwahahahaha…$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "KAPT. STERN: Kenapa…\p"
	.string "Kenapa TIM AQUA mencuri KAPAL SELAM\n"
	.string "EKSPLORER 1 milikku?\p"
	.string "Mereka pasti bukan mengincar\n"
	.string "POKéMON yang tertidur di dasar\l"
	.string "laut…\p"
	.string "Tapi meskipun Aku mengejar mereka,\n"
	.string "Aku tidak punya harapan melawan\l"
	.string "mereka…$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "KAPT. STERN: Oh, {PLAYER}{KUN}…\p"
	.string "Baiklah… Jadi TIM AQUA pergi\n"
	.string "sebelum Kamu sempat menghentikan\l"
	.string "mereka…\p"
	.string "Oh, tidak, jangan menyalahkan diri\n"
	.string "sendiri. Kamu tidak bertanggung\l"
	.string "jawab untuk ini.\p"
	.string "Mencoba mengejar kapal selam… Itu\n"
	.string "mustahil bagi kebanyakan orang.\p"
	.string "Kamu membutuhkan POKéMON yang tahu\n"
	.string "cara MENYELAM (DIVE)…\p"
	.string "Mungkin jika Kamu pergi ke MOSSDEEP\n"
	.string "CITY…\p"
	.string "Banyak penyelam tinggal di sana,\n"
	.string "jadi seseorang mungkin bisa\l"
	.string "mengajarimu…$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "KAPT. STERN: Mencoba mengejar kapal\n"
	.string "selam… Itu mustahil.\p"
	.string "Kamu membutuhkan POKéMON yang tahu\n"
	.string "cara MENYELAM (DIVE)…\p"
	.string "Mungkin jika Kamu pergi ke MOSSDEEP\n"
	.string "CITY…\p"
	.string "Banyak penyelam tinggal di sana,\n"
	.string "jadi seseorang mungkin bisa\l"
	.string "mengajarimu…$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "KAPT. STERN: Oh, ya. TN. BRINEY\n"
	.string "datang ke GALANGAN KAPAL kami.\p"
	.string "Tidak akan lama lagi sebelum kami\n"
	.string "selesai membuat feri!$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "KAPT. STERN: {PLAYER}{KUN}!\p"
	.string "Kami akhirnya selesai membuat feri\n"
	.string "S.S. TIDAL!\p"
	.string "Kami tidak akan bisa melakukannya\n"
	.string "tanpa temanmu, TN. BRINEY.\p"
	.string "Silakan lakukan pelayaran singkat\n"
	.string "dengannya!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "KAPT. STERN: Oh? {PLAYER}{KUN},\n"
	.string "benda yang Kamu punya itu…\p"
	.string "Itu sebuah SCANNER! Itu pasti akan\n"
	.string "membantu kami dalam eksplorasi\l"
	.string "kami.\p"
	.string "{PLAYER}{KUN}, maukah Kamu menukar\n"
	.string "SCANNER-mu dengan sesuatu?\p"
	.string "Seperti, misalnya, GIGI LAUT DALAM\n"
	.string "atau SISIK LAUT DALAM yang Aku\l"
	.string "miliki?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "KAPT. STERN: Kamu yakin? Itu tidak\n"
	.string "berguna untukmu, {PLAYER}{KUN}…\p"
	.string "Baiklah, kalau begitu. Jika Kamu\n"
	.string "ingin menukar SCANNER-mu, beritahu\l"
	.string "Aku.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "KAPT. STERN: Jadi, Kamu akan\n"
	.string "menukarnya dengan GIGI LAUT DALAM\l"
	.string "milikku?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "KAPT. STERN: Jadi, Kamu akan\n"
	.string "menukarnya dengan SISIK LAUT DALAM\l"
	.string "milikku?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "KAPT. STERN: Kamu ingin yang mana?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER} menyerahkan SCANNER kepada\n"
	.string "KAPT. STERN.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "KAPT. STERN: Terima kasih,\n"
	.string "{PLAYER}{KUN}! Ini akan sangat\l"
	.string "membantu penelitian kami!$"

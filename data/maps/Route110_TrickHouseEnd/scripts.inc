//gemini
Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER_END
	showobjectat LOCALID_TRICK_MASTER_END, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER_END
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER_END, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Aak! Kamu berhasil mencapai Aku? Hmmm\n"
	.string "… Kamu cerdas!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "Aku menghabiskan sepanjang malam\n"
	.string "untuk menanam semua pohon itu…\p"
	.string "Kamu hampir setara dengan kehebatan\n"
	.string "Aku, selisih satu, dua, tiga, empat,\l"
	.string "lima, enam tempat!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "Aku menghabiskan sepanjang malam\n"
	.string "untuk membuat labirin…\p"
	.string "Kamu hampir setara dengan kehebatan\n"
	.string "Aku, selisih satu, dua, tiga, empat,\l"
	.string "lima tempat!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "Aku menghabiskan sepanjang malam\n"
	.string "untuk menyiapkan panel dinding…\p"
	.string "Kamu hampir setara dengan kehebatan\n"
	.string "Aku, selisih satu, dua, tiga, empat\l"
	.string "tempat!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "Aku menghabiskan sepanjang malam\n"
	.string "untuk mendorong masuk batu-batu besar\l"
	.string "itu…\p"
	.string "Kamu hampir setara dengan kehebatan\n"
	.string "Aku, selisih satu, dua, tiga tempat!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "Aku menghabiskan sepanjang malam\n"
	.string "untuk membuat MECHADOLLS dan satu\l"
	.string "malam lagi untuk memikirkan kuis…\p"
	.string "Kamu hampir setara dengan kehebatan\n"
	.string "Aku, selisih satu, dua tempat!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "Aku menghabiskan sepanjang malam\n"
	.string "untuk memasang pintu-pintu…\p"
	.string "Kamu hampir setara dengan kehebatan\n"
	.string "Aku!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "Aku menghabiskan sepanjang malam\n"
	.string "memasang panah…\p"
	.string "Kamu setara dengan kehebatan Aku!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "Aku menghabiskan sepanjang malam\n"
	.string "memoles lantai…\p"
	.string "Kamu di atas Aku dalam kehebatan!\n"
	.string "Mungkin…$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "A-apa yang harus Aku lakukan? Sumber\n"
	.string "ide Aku untuk jebakan telah mengering\l"
	.string "…\p"
	.string "Mungkin sudah waktunya Aku\n"
	.string "berkeliling negeri dalam pencarian\l"
	.string "untuk merancang jebakan baru…$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "Aku benci mengakui kekalahan, tetapi\n"
	.string "Kamu telah mengalahkan Aku!\p"
	.string "Namun, Kamu pasti tertarik oleh\n"
	.string "karisma Aku sehingga Kamu mengunjungi\l"
	.string "Aku lagi dan lagi. Ya, pasti begitu!\p"
	.string "Tapi itu tidak ada hubungannya dengan\n"
	.string "kekalahan Aku!\p"
	.string "Sebagai pengakuan atas persahabatan\n"
	.string "antara Kamu, yang gigih, dan si\l"
	.string "jenius yaitu diri-Ku, Aku menuntut\l"
	.string "agar Kamu mengambil kenang-kenangan\l"
	.string "ini!\p"
	.string "Sebenarnya ada dua-sebuah RED TENT\n"
	.string "dan sebuah BLUE TENT. Mana yang Kamu\l"
	.string "sukai?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "Apa? Tidak ada ruang di PC Kamu? Apa\n"
	.string "yang harus Aku simpulkan dari itu?\p"
	.string "Aku ingin mengatakan itu, tetapi Aku\n"
	.string "terlalu baik dan peduli, jadi\l"
	.string "kembalilah nanti!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "………………\p"
	.string "Aku akan pergi dalam perjalanan\n"
	.string "penemuan. Sebuah pencarian untuk\l"
	.string "mencari jebakan baru.\p"
	.string "Aku berharap suatu hari nanti Kamu\n"
	.string "akan berkunjung dan menghibur Aku\l"
	.string "lagi.\p"
	.string "Dan sekarang, selamat tinggal!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Baik! Kamu telah mendapatkan hadiah\n"
	.string "ini!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "Apa? Kamu tidak punya ruang untuk ini\n"
	.string "? Barang macam apa yang Kamu bawa?\p"
	.string "Tapi baiklah, karena Kamu telah\n"
	.string "mencapai Aku, hadiah Kamu akan ada\l"
	.string "bersama Aku sampai nanti.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Hapus cengiran sombong itu dari wajah\n"
	.string "Kamu! Terlalu pagi untuk berpikir\l"
	.string "Kamu sudah menang!\p"
	.string "Aku akan membuat jebakan baru untuk\n"
	.string "menjebak Kamu, sungguh. Kamu boleh\l"
	.string "mengejek Aku hanya ketika Kamu sudah\l"
	.string "selesai.\p"
	.string "Kembalilah untuk episode seru\n"
	.string "berikutnya!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Nah, nah! Kamu mengabaikan Aku\n"
	.string "sekarang? Itu, Aku anggap menyedihkan.$"

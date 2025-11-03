PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Kamu…\n"
	.string "Ah, kamu pasti {PLAYER}{KUN}, kan?\p"
	.string "Terima kasih sudah bermain dengan WALLY\n"
	.string "beberapa waktu lalu.\p"
	.string "Dia rapuh dan sakit-sakitan\n"
	.string "sejak bayi.\p"
	.string "Kami mengirimnya untuk tinggal bersama\n"
	.string "kerabatku di KOTA VERDANTURF sebentar.\p"
	.string "Udaranya jauh lebih bersih di sana\n"
	.string "daripada di sini.\p"
	.string "Apa itu? Di mana WALLY?\n"
	.string "Dia sudah pergi, WALLY kami.\p"
	.string "Aku ingin tahu di mana dia\n"
	.string "sekarang?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Aku ingin tahu bagaimana kabar WALLY kami?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Maafkan kami karena\n"
	.string "menyeretmu ke sini dengan cara ini.\p"
	.string "Tapi WALLY kami menjadi sangat sehat\n"
	.string "sejak dia pergi ke KOTA VERDANTURF.\p"
	.string "Kami berhutang semuanya padamu!\p"
	.string "Ketika WALLY meninggalkan kota, kamu membantunya\n"
	.string "menangkap POKéMON, kan?\p"
	.string "Aku pikir itu membuat WALLY sangat\n"
	.string "senang.\p"
	.string "Sebenarnya, bukan hanya WALLY.\n"
	.string "Itu membuatku, ayahnya, juga senang.\p"
	.string "Senang karena dia mendapatkan teman\n"
	.string "yang hebat sepertimu.\p"
	.string "Ini bukan suap atau apa pun, tapi\n"
	.string "Aku sangat ingin kamu memiliki ini.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Jika POKéMON-mu bisa BERSELANCAR, kamu\n"
	.string "akan bisa pergi ke berbagai tempat.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY akan segera pulang.\n"
	.string "Aku menantikannya.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh? Kamu bertemu WALLY di\n"
	.string "KOTA EVER GRANDE?\p"
	.string "Oh, {PLAYER}{KUN}, jangan konyol.\p"
	.string "Dia mungkin sudah sehat, tapi dia\n"
	.string "tidak bisa pergi ke tempat yang jauh seperti\l"
	.string "itu sendirian.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY sangat senang ketika dia memberi\n"
	.string "tahu kami bahwa dia menangkap POKéMON.\p"
	.string "Sudah lama sekali Aku tidak melihatnya\n"
	.string "tersenyum seperti itu.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Aku ingin kamu merahasiakan ini\n"
	.string "dari suamiku…\p"
	.string "Tapi WALLY kami meninggalkan KOTA VERDANTURF\n"
	.string "tanpa memberi tahu siapa pun.\p"
	.string "Kamu tahu, WALLY rapuh, tapi\n"
	.string "dia memiliki kemauan yang sangat kuat.\p"
	.string "Aku yakin dia akan kembali dengan selamat\n"
	.string "suatu hari nanti!$"


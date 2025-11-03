BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Ini BATTLE DOME!\n"
	.string "Jalanmu menuju superstar tak terkalahkan!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Ini BATTLE FACTORY!\n"
	.string "Carilah POKéMON terkuat!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Ini BATTLE PIKE!\n"
	.string "Pilih salah satu dari tiga jalur!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Ini adalah BATTLE TOWER.\p"
	.string "Para TRAINER membawa POKéMON terbaik\n"
	.string "mereka untuk pertandingan gaya eliminasi.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Halo, apa kamu ke sini untuk naik feri?\n"
	.string "Boleh aku lihat TIKET-mu?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} tidak punya TIKET…\p"
	.string "Maaf sekali.\p"
	.string "Kamu harus punya TIKET untuk naik\n"
	.string "feri.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} menunjukkan TIKET.\p"
	.string "Sempurna! Hanya itu yang kamu butuhkan!\p"
	.string "Dan ke mana kamu ingin pergi?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "Baiklah, ke SLATEPORT CITY!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "Baiklah, ke LILYCOVE CITY!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Silakan berlayar bersama kami lain waktu!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Silakan naik ke feri dan tunggu\n"
	.string "keberangkatan.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Jadi, ke mana kamu ingin pergi?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Aku yang terbaik di antara semua temanku.\n"
	.string "Tapi di sini…\l"
	.string "Aku tidak berguna!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Aku ingin pergi ke BATTLE TOWER,\n"
	.string "tapi tidak bisa menemukannya meskipun aku punya\l"
	.string "peta BATTLE FRONTIER.\p"
	.string "Tempat ini terlalu besar!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Aku ingin langsung menerima tantangan\n"
	.string "setelah tiba di sini.\p"
	.string "Tapi di perjalanan, aku mabuk laut…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Tidak sembarang orang bisa datang\n"
	.string "ke sini, tahu?\p"
	.string "Hanya TRAINER yang diakui tangguh\n"
	.string "yang dibawa ke sini.\p"
	.string "Itulah sebabnya banyak TRAINER bahkan\n"
	.string "tidak tahu tentang BATTLE FRONTIER.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Hei, bro…\p"
	.string "Apa kamu yakin kita bisa ikut tantangan\n"
	.string "meskipun kita tidak punya POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Uh…\n"
	.string "Aku yakin akan baik-baik saja.\p"
	.string "Kurasa…\p"
	.string "Tapi ingat orang besar menakutkan itu?\n"
	.string "Dia bilang, “Aku akan pinjamkan POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Itu BATTLE FACTORY.\n"
	.string "Kamu bisa menyewa POKéMON kuat di sana.\p"
	.string "Tapi itu membuatku bertanya-tanya.\n"
	.string "Siapa yang membesarkan POKéMON sewaan itu?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Aku takut masuk ke BATTLE\n"
	.string "PIKE karena ada SEVIPER…\p"
	.string "T-tapi aku sudah datang jauh-jauh ke sini, jadi aku akan\n"
	.string "mencoba menaklukkan semuanya!\l"
	.string "…Gemetar…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Ayo main batu, kertas, gunting!\n"
	.string "Satu, dua, tiga!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Hore! Aku menang!\n"
	.string "Aku akan mengambil tantangan BATTLE PIKE!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, tidak…\n"
	.string "Aku kalah.\p"
	.string "Kurasa aku tidak terlalu beruntung hari ini.\n"
	.string "Aku akan menunda tantangan BATTLE PIKE-ku\l"
	.string "sampai besok.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Aku yakin aku satu-satunya orang di sini yang,\n"
	.string "untuk alasan yang tidak diketahui, akan memilih\l"
	.string "memancing daripada bertarung.\p"
	.string "Hah? Tidak bisa menangkap apa pun di sini?\n"
	.string "Mengecewakan…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Hari ini, aku akan terus bertarung, apa\n"
	.string "pun yang terjadi, sampai aku mendapatkan Symbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Kamu akan menantang\n"
	.string "BATTLE DOME?\p"
	.string "Semoga kamu beruntung.\n"
	.string "Mari kita berdua menang dan bertemu\l"
	.string "di tantangan.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Kakek, di sini!\n"
	.string "BATTLE DOME ada di sini!\l"
	.string "Semangat, Kakek!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, jadi ini BATTLE DOME?\n"
	.string "Aku tidak akan membiarkan GENTLEMEN mengalahkanku!\p"
	.string "Tapi di mana pintu masuknya?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Dulu tidak ada apa-apa di sini belum\n"
	.string "lama ini.\p"
	.string "Tapi, sekarang lihat tempat ini! Luar biasa!\n"
	.string "Aku akan mengajak ibuku untuk melihat ini.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Akhirnya aku tiba di BATTLE\n"
	.string "FRONTIER!\p"
	.string "Aku yakin akan menarik perhatian dengan\n"
	.string "penampilan dan kemampuanku!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Nyam, nyam…\p"
	.string "Sepertinya alun-alun ini dipenuhi\n"
	.string "orang-orang tangguh.\p"
	.string "Nyam, nyam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Kres, nyam…\p"
	.string "Beberapa waktu lalu, aku bertemu seorang gadis\n"
	.string "di BATTLE PIKE.\p"
	.string "Dia punya mata yang menakutkan\n"
	.string "dengan cara yang sangat galak.\p"
	.string "Kres, nyam…\p"
	.string "Dia menjadi sangat marah: “Berhenti\n"
	.string "makan!” Lalu dia memukulku.\p"
	.string "Itu adalah pengalaman menakutkan\n"
	.string "yang membuat bulu kuduk berdiri.\p"
	.string "Kres, nyam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Hah? Coba dengarkan dirimu sendiri!\n"
	.string "Itu bukan apa-apa!\p"
	.string "Terakhir kali aku menyemangatinya,\n"
	.string "mata kami bertemu dan bunga api beterbangan!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Apaaaaaa?!\n"
	.string "Pfft!\p"
	.string "Itu hanya terjadi karena\n"
	.string "aku kebetulan duduk di sebelahmu!\p"
	.string "DOME ACE hanya melihat ke arah kita\n"
	.string "karena sorakanku sangat keras!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, diam!\n"
	.string "Jangan berisik!\p"
	.string "Penggemar musiman sepertimu sebaiknya\n"
	.string "menyemangati GYM LEADER saja!\p"
	.string "DOME ACE adalah milikku!\n"
	.string "Satu-satunya idola untukku!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Orang-orang yang bertengkar di sana itu…\p"
	.string "Sulit dipercaya, tapi mereka dulunya\n"
	.string "adalah TRAINER, dan yang hebat juga.\p"
	.string "Mereka dulu sangat tangguh,\n"
	.string "dan mereka juga terkenal.\p"
	.string "Tapi mereka dihancurkan oleh\n"
	.string "TRAINER tertentu di sebuah turnamen.\p"
	.string "Mereka begitu telak dikalahkan,\n"
	.string "hingga mereka terpikat oleh TRAINER itu.\p"
	.string "Sekarang mereka hanya penggemar TRAINER itu.\n"
	.string "Mereka pergi menyemangati idola mereka di\l"
	.string "BATTLE DOME setiap hari sekarang.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Aku dengar rumor bahwa seseorang melihat\n"
	.string "POKéMON dengan ekor yang sangat panjang\l"
	.string "di suatu tempat di BATTLE FRONTIER.\p"
	.string "Pasti menggemaskan. Aku yakin itu…\p"
	.string "Oh, tantangan bisa menunggu. Aku merasa terdorong\n"
	.string "untuk menemukan makhluk yang menyenangkan itu!$"


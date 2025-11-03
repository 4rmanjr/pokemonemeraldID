LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "IBU: Lihat, {PLAYER}?\n"
	.string "Di sini juga bagus, kan?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "POKéMON jasa pindahan melakukan semua\n"
	.string "pekerjaan pindahan dan bersih-bersih.\l"
	.string "Praktis sekali!\p"
	.string "{PLAYER}, kamarmu di lantai atas.\n"
	.string "Coba lihat, sayang!\p"
	.string "AYAH membelikanmu jam baru untuk\n"
	.string "menandai kepindahan kita.\l"
	.string "Jangan lupa diatur ya!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "IBU: Nah, {PLAYER}?\p"
	.string "Apa kamu tidak tertarik melihat\n"
	.string "kamarmu sendiri?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "IBU: {PLAYER}.\p"
	.string "Atur jam di kamarmu ya, sayang.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "IBU: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Cepat! Sini cepat!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "IBU: Lihat! Itu GYM PETALBURG!\n"
	.string "Mungkin AYAH akan muncul!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "IBU: Oh… Sudah selesai.\p"
	.string "Sepertinya tadi ada AYAH, tapi kita\n"
	.string "ketinggalan. Sayang sekali.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Oh, ya.\n"
	.string "Salah satu teman AYAH tinggal di kota ini.\p"
	.string "Namanya PROF. BIRCH.\p"
	.string "Dia tinggal di sebelah, jadi kamu\n"
	.string "harus ke sana dan memperkenalkan diri.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "IBU: Sampai jumpa, sayang!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "IBU: Apa kamu sudah memperkenalkan\n"
	.string "diri ke PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "IBU: Bagaimana kabarmu, {PLAYER}?\n"
	.string "Kamu terlihat sedikit lelah.\p"
	.string "Sebaiknya kamu istirahat sebentar.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "IBU: Hati-hati, sayang!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "IBU: Oh? Apa AYAH memberimu BADGE itu?\p"
	.string "Kalau begitu ini ada sesuatu dari IBU!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Jangan terlalu memaksakan diri, sayang.\n"
	.string "Kamu selalu bisa pulang.\p"
	.string "Semangat, sayang!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "IBU: Apa itu, sayang? Sebuah POKéNAV?\n"
	.string "Seseorang dari DEVON memberikannya?\p"
	.string "Nah, sayang, bagaimana kalau\n"
	.string "mendaftarkan ibumu?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "IBU terdaftar\n"
	.string "di POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "PEWAWANCARA: …Kami bawakan laporan\n"
	.string "ini dari depan GYM PETALBURG.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Ada film di TV.\p"
	.string "Dua pria menari di atas keyboard\n"
	.string "piano besar.\p"
	.string "Sebaiknya pergi!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "Ini buku petunjuk untuk RUNNING SHOES.\p"
	.string "“Tekan Tombol B untuk berlari saat\n"
	.string "memakai RUNNING SHOES-mu.\p"
	.string "“Ikat tali RUNNING SHOES-mu dan\n"
	.string "mulailah berlari!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "AYAH: Hm?\p"
	.string "Hei, itu {PLAYER}!\p"
	.string "Sudah lama tidak bertemu, tapi kamu\n"
	.string "terlihat… lebih kuat, entah bagaimana.\p"
	.string "Itulah kesanku.\n"
	.string "Tapi ayahmu ini belum menyerah!\p"
	.string "Oh, ya, aku punya sesuatu untukmu.\n"
	.string "Ini datang untukmu dari seseorang\l"
	.string "bernama MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "AYAH: Hm, sebuah TIKET untuk feri?\p"
	.string "Seingatku, ada pelabuhan feri di\n"
	.string "SLATEPORT dan LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Sebaiknya aku kembali ke GYM PETALBURG.\p"
	.string "IBU, terima kasih sudah menjaga rumah\n"
	.string "selagi aku pergi.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "IBU: AYAHmu itu…\p"
	.string "Pulang setelah sekian lama, tapi yang\n"
	.string "dibicarakan hanya POKéMON.\p"
	.string "Seharusnya dia santai dan tinggal\n"
	.string "sedikit lebih lama.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "IBU: Apa itu berita terbaru?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Kami sampaikan berita darurat!\p"
	.string "Di berbagai lokasi HOENN, ada laporan\n"
	.string "tentang POKéMON berwarna BZZT…\l"
	.string "yang sedang terbang.\p"
	.string "Identitas POKéMON ini saat ini\n"
	.string "tidak diketahui.\p"
	.string "Kami sekarang kembali ke program\n"
	.string "film reguler.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "IBU: {PLAYER}, apa kamu mendengarnya?\p"
	.string "Penyiar bilang POKéMON itu warna apa?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "IBU: Wah, hebat sekali!\n"
	.string "Masih ada POKéMON yang tidak dikenal.$"

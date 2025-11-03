RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Aku MR. STONE, PRESIDEN dari\n"
	.string "DEVON CORPORATION.\p"
	.string "Aku baru saja mendengar kabarmu!\p"
	.string "Kamu menyelamatkan staf kami tidak\n"
	.string "hanya sekali, tapi dua kali!\p"
	.string "Aku punya permintaan tolong dari\n"
	.string "orang luar biasa sepertimu.\p"
	.string "Aku mengerti kamu sedang mengantarkan\n"
	.string "paket ke GALANGAN KAPAL SLATEPORT.\p"
	.string "Nah, dalam perjalanan, bisakah kamu\n"
	.string "mampir ke KOTA DEWFORD?\p"
	.string "Aku berharap kamu bisa mengantarkan\n"
	.string "SURAT kepada STEVEN di DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. STONE: Nah, kamu harus tahu bahwa\n"
	.string "aku adalah PRESIDEN yang hebat.\p"
	.string "Jadi, aku tidak akan pernah begitu\n"
	.string "murah hati meminta bantuan tanpa\l"
	.string "imbalan apa pun.\p"
	.string "Itulah mengapa aku ingin kamu memiliki\n"
	.string "ini!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} mendapatkan POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "MR. STONE: Perangkat itu…\p"
	.string "Itu adalah POKéMON NAVIGATOR, atau\n"
	.string "singkatnya POKéNAV.\p"
	.string "Ini adalah alat yang sangat diperlukan\n"
	.string "untuk setiap TRAINER dalam petualangan.\p"
	.string "Ini memiliki peta wilayah HOENN.\p"
	.string "Kamu bisa memeriksa lokasi KOTA DEWFORD\n"
	.string "dan SLATEPORT dengan mudah!\p"
	.string "Omong-omong, aku dengar para\n"
	.string "kriminal jahat-MAGMA dan AQUA,\l"
	.string "kurasa-telah membuat masalah di mana-\l"
	.string "mana.\p"
	.string "Kurasa akan lebih baik jika kamu\n"
	.string "beristirahat sebelum melanjutkan\l"
	.string "perjalanan.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "MR. STONE: Baiklah, kalau begitu,\n"
	.string "{PLAYER}{KUN}, pergilah dengan hati-hati\l"
	.string "dan waspada!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "MR. STONE: Aku mengandalkanmu!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. STONE: Kamu mengantarkan SURAT-ku?\n"
	.string "Terima kasih banyak!\p"
	.string "Ini adalah caraku berterima kasih.\n"
	.string "Ini akan membantumu, seorang TRAINER.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "MR. STONE: POKéMON yang memegang\n"
	.string "EXP. SHARE itu akan diberikan\l"
	.string "beberapa Poin EXP dari pertarungan.\p"
	.string "Ia akan mendapatkan Poin EXP meskipun\n"
	.string "ia tidak benar-benar bertarung.\p"
	.string "Aku akan bilang EXP. SHARE cukup\n"
	.string "berguna untuk melatih POKéMON yang\l"
	.string "lemah.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "MR. STONE: Sejak masa mudaku, aku\n"
	.string "telah membenamkan diriku dalam\l"
	.string "pekerjaan.\p"
	.string "Akibatnya, aku tidak akrab dengan\n"
	.string "tren dan hal semacam itu.\p"
	.string "Tapi apakah semua anak muda ingin\n"
	.string "menjadi TRAINER di LIGA POKéMON?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Ini adalah lantai tiga DEVON\n"
	.string "CORPORATION.\p"
	.string "KANTOR PRESIDEN kami ada di\n"
	.string "lantai ini.\p"
	.string "Pokoknya, aku tidak bisa mengungkapkan\n"
	.string "betapa berterima kasihnya aku atas\l"
	.string "apa yang telah kamu lakukan.\p"
	.string "Um… Omong-omong, paket yang\n"
	.string "kamu ambilkan untuk kami itu…\p"
	.string "Bisakah kamu mengantarkannya ke\n"
	.string "GALANGAN KAPAL di SLATEPORT?\p"
	.string "Akan sangat buruk jika para perampok\n"
	.string "itu mencoba mengambilnya lagi.\p"
	.string "Uh… Hehehe, jadi, uh, bisakah aku\n"
	.string "mengandalkanmu untuk melakukan\l"
	.string "itu untukku?\p"
	.string "Oh, benar.\n"
	.string "Bisakah kamu menunggu di sini sebentar?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "PRESIDEN kami ingin berbicara\n"
	.string "denganmu.\p"
	.string "Silakan ikut denganku.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Silakan, duluan.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Jika kamu mengunjungi GALANGAN\n"
	.string "KAPAL di SLATEPORT, kamu harus\l"
	.string "menemui KAPTEN STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Produk baru DEVON, REPEAT BALL\n"
	.string "dan TIMER BALL, telah menjadi sangat\l"
	.string "populer di kalangan TRAINER.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Ini adalah koleksi batuan dan\n"
	.string "batu langka yang dikumpulkan oleh\l"
	.string "PRESIDEN.$"


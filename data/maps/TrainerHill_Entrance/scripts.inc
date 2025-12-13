//gemini
TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Inilah BUKIT TRAINER tempat kamu\n"
	.string "bisa menikmati pertarungan tim\l"
	.string "dengan banyak TRAINER.\p"
	.string "Sayangnya, kami masih menyiapkan\n"
	.string "segalanya. Silakan kembali nanti!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Selamat datang!\p"
	.string "Inilah BUKIT TRAINER tempat kamu\n"
	.string "bisa menikmati pertarungan tim\l"
	.string "dengan banyak TRAINER!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Apakah ini kunjungan pertamamu ke\n"
	.string "sini?\p"
	.string "Sebelum kamu masuk, mohon simpan\n"
	.string "permainanmu.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Mari kita lihat… Para TRAINER yang\n"
	.string "ada di sini sekarang adalah…\p"
	.string "Sampai lantai no. {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Mari kita lihat… Para TRAINER yang\n"
	.string "ada di sini sekarang adalah…\p"
	.string "Tampaknya ada TRAINER berkumpul di\n"
	.string "setiap ruangan.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Apakah kamu ingin menantang para\n"
	.string "TRAINER yang menunggu?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Aku akan mencatat waktumu. Semoga\n"
	.string "berhasil!\p"
	.string "Siap-siap…\p"
	.string "Pasang posisi…\p"
	.string "Mulai!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Silakan kunjungi kami lagi!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Sayang sekali.\p"
	.string "Aku rasa kamu sudah mengerahkan\n"
	.string "upaya luar biasa dalam\l"
	.string "pertarunganmu.\p"
	.string "Silakan datang kembali dan coba\n"
	.string "lagi!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Aku harap kamu berikan yang\n"
	.string "terbaik.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Ketika para TRAINER berganti\n"
	.string "tempat, pergerakannya bisa menjadi\l"
	.string "kacau.\p"
	.string "Untuk menghindari kekacauan, kami\n"
	.string "memindahkan meja resepsionis ke\l"
	.string "sini.\p"
	.string "Aku mohon maaf atas ketidaknyamanan\n"
	.string "ini.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Terima kasih sudah bermain!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Di BUKIT TRAINER ini, kami\n"
	.string "mengadakan acara yang disebut\l"
	.string "Serangan Waktu.\p"
	.string "Ini adalah balapan yang mengukur\n"
	.string "seberapa lama kamu mencapai pemilik\l"
	.string "kami di atap dari meja ini.\p"
	.string "Waktu tercepat dipasang di Papan\n"
	.string "Waktu--coba bersaing dengan\l"
	.string "teman-temanmu.\p"
	.string "Dalam pertarungan TRAINER di\n"
	.string "sepanjang jalan, baik Poin Exp.\l"
	.string "maupun uang tidak akan diberikan.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, aku minta maaf, tetapi kamu\n"
	.string "tampaknya hanya membawa satu\l"
	.string "POKéMON.\p"
	.string "Kamu akan membutuhkan setidaknya\n"
	.string "dua POKéMON untuk mengikuti acara\l"
	.string "ini.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "Kamu akhirnya datang! Ya, kamu\n"
	.string "sudah tiba!\p"
	.string "Tunggu! Jangan katakan! Aku tahu\n"
	.string "mengapa kamu datang jauh-jauh ke\l"
	.string "sini sendirian!\p"
	.string "Kamu ingin bertemu aku, pemilik\n"
	.string "BUKIT TRAINER ini, karena…\p"
	.string "Kamu ingin membentuk tim tag\n"
	.string "denganku! Wa-hoo!\p"
	.string "…Uh? Bukan itu?\p"
	.string "Pokoknya, aku melihatmu saat kamu\n"
	.string "naik. Pertarungan yang luar biasa!\l"
	.string "Sungguh hebat!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Untuk seseorang yang luar biasa\n"
	.string "sepertimu, aku punya hadiah paling\l"
	.string "luar biasa!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh, tidak, bawaanmu penuh! Kamu\n"
	.string "harus kembali lagi nanti untuk ini!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, tunggu sebentar! Apakah kamu\n"
	.string "mungkin tiba di sini dengan sangat\l"
	.string "cepat?\p"
	.string "Betapa hebat! Kamu tidak perlu\n"
	.string "terburu-buru seperti itu hanya\l"
	.string "untuk menemuiku!\p"
	.string "Itu sungguh menyenangkan. Aku akan\n"
	.string "meminta Papan Waktu di resepsionis\l"
	.string "diperbarui!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Tapi, oh… Kamu tidak terlalu cepat\n"
	.string "sampai di sini.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Mungkin aku akan lebih senang jika\n"
	.string "kamu tiba lebih cepat lain kali.\p"
	.string "Kalau begitu, aku akan senang untuk\n"
	.string "membentuk tim tag denganmu!\p"
	.string "Sampai kita bertemu lagi, amigo!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Aku membangun BUKIT TRAINER ini\n"
	.string "hanya untuk satu alasan, dan satu\l"
	.string "alasan saja!\p"
	.string "Untuk menemukan rekan paling cocok\n"
	.string "untuk membentuk tim tag bersamaku!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} mnt.\n"
	.string "{STR_VAR_2}.{STR_VAR_3} dtk.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Siapa yang tahu kombinasi TRAINER\n"
	.string "dan POKéMON macam apa yang ada di\l"
	.string "depan?\p"
	.string "Yang aku tahu adalah aku akan\n"
	.string "menyingkirkan siapa pun yang\l"
	.string "menghalangiku!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Aku dengar TRAINER tangguh datang\n"
	.string "ke BUKIT TRAINER ini dari\l"
	.string "mana-mana.\p"
	.string "Aku tidak sabar untuk mencoba!\p"
	.string "Aku akan menyingkirkan siapa pun\n"
	.string "yang menghalangiku!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Apakah kamu melihat Papan Waktu di\n"
	.string "sana?\p"
	.string "Teman-temanku dan aku mencoba\n"
	.string "melihat siapa yang dapat mencapai\l"
	.string "puncak dalam waktu tersingkat.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Apakah kamu tahu kapan mereka akan\n"
	.string "membuka tempat ini?\p"
	.string "Aku menunggu di sini untuk menjadi\n"
	.string "penantang pertama!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Apakah kamu ingin kembali ke meja\n"
	.string "resepsionis?$"

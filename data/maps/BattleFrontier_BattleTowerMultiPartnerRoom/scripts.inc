BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Silakan cari partner dari para\n"
	.string "TRAINER yang berkumpul di sini.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, kamu belum menemukan partner\n"
	.string "untuk tag team-mu.\p"
	.string "Apa kamu mau berhenti mencari dan\n"
	.string "kembali ke konter resepsionis?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Kalau begitu, silakan cari partner dari\n"
	.string "para TRAINER yang berkumpul di sini.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Terima kasih telah memilih partner.\p"
	.string "Aku akan mengantarmu ke\n"
	.string "RUANG MULTI BATTLE sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Aku murid no. {STR_VAR_2} dari {STR_VAR_1}.\n"
	.string "Panggil saja aku {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Atas saran {STR_VAR_1}, aku membawa\n"
	.string "satu {STR_VAR_3} dengan {STR_VAR_2} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Tolong, ayo kita bentuk tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Terima kasih!\n"
	.string "Aku akan segera mendaftar.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Padahal aku sangat ingin membentuk\n"
	.string "tag team denganmu, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Aku murid no. {STR_VAR_2} dari {STR_VAR_1}.\n"
	.string "Namaku {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Aku mendapat saran dari {STR_VAR_1} dan memilih\n"
	.string "satu {STR_VAR_3} dengan {STR_VAR_2} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Tolong, ayo kita bentuk tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Terima kasih banyak!\n"
	.string "Aku akan cepat selesaikan pendaftarannya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, padahal aku berharap bisa\n"
	.string "menjadi partner-mu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Um, namaku {STR_VAR_3}, dan aku\n"
	.string "murid no. {STR_VAR_2} dari {STR_VAR_1}.\p"
	.string "Hiks…\p"
	.string "Maaf!\n"
	.string "Aku jadi menangis karena tegang…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} menasihatiku, jadi aku punya\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Hiks…\n"
	.string "Tolong, tolong, ayo jadi partner-ku!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, benarkah? Kamu mau?\n"
	.string "Luar biasa! Asyik! Awoooh!\p"
	.string "Oh… maaf…\n"
	.string "Aku menangis karena terlalu senang…\p"
	.string "Aku akan segera mendaftar.\n"
	.string "Tolong jangan pergi, ya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, t-tapi…\n"
	.string "Hiks… Waaaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Halo! Aku {STR_VAR_3}!\n"
	.string "Murid no. {STR_VAR_2} dari {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} merekomendasikan tim-ku.\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1},\n"
	.string "itu yang aku punya! Keren, kan?\p"
	.string "Jadi, ayolah!\n"
	.string "Ayo kita bentuk tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Yay! Hebat!\n"
	.string "Oke, aku daftar dulu ya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Aww, kenapa?\n"
	.string "Aku ingin jadi partner-mu, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Aku {STR_VAR_3}, murid no. {STR_VAR_2}\n"
	.string "dari {STR_VAR_1} yang terkenal itu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Aku meminta saran pada {STR_VAR_3}.\n"
	.string "Satu {STR_VAR_2} yang memakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "dan satu {STR_VAR_2} dengan {STR_VAR_1},\n"
	.string "itulah pasanganku.\p"
	.string "Tolong, maukah kamu bergabung\n"
	.string "denganku dalam tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Terima kasih!\n"
	.string "Aku akan segera mendaftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, padahal aku berharap bisa\n"
	.string "bergabung denganmu dalam tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Um… Aku sangat senang kamu mau\n"
	.string "meluangkan waktu untuk bicara denganku.\p"
	.string "Aku {STR_VAR_3}.\n"
	.string "Murid no. {STR_VAR_2} dari {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} memberiku saran.\n"
	.string "Aku sangat berterima kasih untuk itu.\p"
	.string "Aku punya tim yang terdiri dari satu {STR_VAR_2}\n"
	.string "dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\n"
	.string "Aku tahu aku banyak meminta…\p"
	.string "Aku rasa kamu tidak akan bersedia,\n"
	.string "tapi bolehkah aku menjadi partner-mu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Benarkah? Aku tidak percaya!\n"
	.string "Aku tidak percaya kamu mengizinkanku bergabung!\l"
	.string "Aku… Aku tidak akan mengecewakanmu!\p"
	.string "Um… Kalau memang boleh, aku akan mendaftar\n"
	.string "sekarang juga!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "Kukira aku memang tidak cukup baik…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hi, aku {STR_VAR_3}.\n"
	.string "Aku murid no. {STR_VAR_2} dari {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} bilang akan bagus\n"
	.string "kalau membuat tim ini:\l"
	.string "satu {STR_VAR_2} yang memakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "dan satu {STR_VAR_2} yang tahu cara\n"
	.string "memakai {STR_VAR_1}.\p"
	.string "Lumayan, kan?\n"
	.string "Mau jadi partner-ku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Oke, senang bergabung denganmu!\n"
	.string "Kuharap kamu tidak mengacaukannya untukku!\l"
	.string "Aku akan mendaftar sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Hah? Kenapa kamu menolakku?\n"
	.string "Kamu tidak bisa menilai orang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Aku {STR_VAR_3} dan aku seorang TRIATHLETE.\n"
	.string "Aku sibuk setiap hari dengan jogging,\l"
	.string "latihan, dan nge-rap.\p"
	.string "Aku juga murid no. {STR_VAR_2}\n"
	.string "dari {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Ini yang direkomendasikan {STR_VAR_3}.\n"
	.string "Satu {STR_VAR_2} yang memakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "dan satu {STR_VAR_2} yang memakai\n"
	.string "{STR_VAR_1}.\p"
	.string "Aku berusaha keras membesarkan\n"
	.string "mereka, meskipun aku sibuk.\p"
	.string "Ayo kita bentuk tag team\n"
	.string "dan kita coba!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Makasih, itu baru semangat!\n"
	.string "Tunggu sebentar selagi aku mendaftar, oke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Aku sudah meluangkan waktu dari jadwal\n"
	.string "sibukku untuk ke sini! Ayolah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hi!\n"
	.string "Apa kabar?\p"
	.string "Aku {STR_VAR_3}, murid no. {STR_VAR_2}\n"
	.string "dari {STR_VAR_1}. Senang bertemu denganmu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Dengar, dengar! Kamu harus dengar tentang\n"
	.string "POKéMON yang direkomendasikan {STR_VAR_3}.\l"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\n"
	.string "Tentu saja aku membesarkan mereka dengan hebat!\p"
	.string "Jadi, mau jadi partner?\n"
	.string "Aku yakin ini akan jadi kombo yang hebat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Yay, sepertinya ini akan menyenangkan!\n"
	.string "Aku akan mendaftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, kamu jahat!\n"
	.string "Aku ini direkomendasikan, lho.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Izinkan aku memperkenalkan diri.\n"
	.string "Aku {STR_VAR_3}.\p"
	.string "Aku adalah murid no. {STR_VAR_2}\n"
	.string "dari {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Aku mencari nasihat bijak dari\n"
	.string "{STR_VAR_3} dan membesarkan timku\l"
	.string "yang terdiri dari satu {STR_VAR_2} dengan {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "dan satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Tolong setuju untuk menjadi tag team denganku!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… Aku senang sekali!\n"
	.string "Aku janji akan memberikan yang terbaik!\p"
	.string "Tentu saja aku akan mendaftarkan kita!\n"
	.string "Tolong tunggu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Padahal aku berharap bisa bergabung denganmu,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eek! Kamu bicara padaku!\n"
	.string "Aku… Aku senang sekali!\p"
	.string "Aku {STR_VAR_3}! Aku murid no. {STR_VAR_2}\n"
	.string "dari {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Atas saran {STR_VAR_3}, aku melatih\n"
	.string "satu {STR_VAR_2} yang memakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "dan satu {STR_VAR_2} yang memakai\n"
	.string "{STR_VAR_1}.\p"
	.string "Tolong, bisakah kamu kabulkan keinginanku?\n"
	.string "Aku ingin menjadi partner tag team-mu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eek! Aku… Aku merasa pusing!\n"
	.string "Terima kasih banyak!\l"
	.string "Aku akan segera mendaftarkan kita!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! Apa kamu tidak kasihan?\n"
	.string "Tapi itu membuatmu lebih keren…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Yeehaw! Aku murid no. {STR_VAR_2}\n"
	.string "dari {STR_VAR_1}!\p"
	.string "Namaku {STR_VAR_3}, halo, halo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Mentorku {STR_VAR_3} merekomendasikan\n"
	.string "satu {STR_VAR_2} master-{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "dan satu {STR_VAR_2} master-\n"
	.string "{STR_VAR_1}.\p"
	.string "Bagus, kan?\n"
	.string "Kamu mau jadi partner-ku, kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Oke, luar biasa!\n"
	.string "Aku akan selesaikan pendaftarannya dengan cepat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah!\n"
	.string "Kamu penuh perhitungan, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hei! Ada masalah besar! Ini adalah\n"
	.string "hari terakhir BATTLE TOWER!\p"
	.string "… … … … … …\n"
	.string "Aku hanya bercanda!\p"
	.string "Orang-orang memanggilku {STR_VAR_3} dan aku juga!\n"
	.string "Aku murid ke-1.000 dari {STR_VAR_1}!\l"
	.string "Sebenarnya, aku no. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} memberiku beberapa saran.\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} dengan {STR_VAR_1}.\n"
	.string "Aku punya sepuluh dari setiap jenis!\l"
	.string "Sebenarnya, hanya satu dari masing-masing!\p"
	.string "Bagaimana?\n"
	.string "Mau coba tag battle denganku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Yippee!\n"
	.string "Aku akan memberimu POKéMON sebagai ucapan terima kasih!\p"
	.string "Bercanda! Tapi aku akan benar-benar pergi\n"
	.string "mendaftar, oke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, dingin sekali! Aku harus menghancurkan\n"
	.string "BATTLE TOWER untuk itu!\p"
	.string "Tentu saja tidak!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hey, yo, aku terus bergoyang!\n"
	.string "POKéMON, selalu dalam genggaman!\p"
	.string "Aku {STR_VAR_3} si SAILOR nge-rap.\n"
	.string "Jangan salah sangka aku tak siap!\p"
	.string "Aku murid no. {STR_VAR_2} dari {STR_VAR_1}.\n"
	.string "Aku, jangan cepat kamu hakimi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Dengan saran dari {STR_VAR_3} aku\n"
	.string "patuhi, kubentuk tim kebanggaanku ini!\l"
	.string "Satu {STR_VAR_2} pemakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "dan satu {STR_VAR_2} pemakai\n"
	.string "{STR_VAR_1}!\p"
	.string "Pertemuan kita harus dirayakan,\n"
	.string "dengan kemenangan tag-team tuk dibanggakan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hey, hey, aku suka gayamu!\n"
	.string "Pendaftaran kita, akan kuurus untukmu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, hey, {PLAYER}, dingin sekali!\n"
	.string "Kalau boleh aku beropini!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yippee-yahoo!\n"
	.string "Oh, jangan lari! Aku hanya bercanda!\p"
	.string "Howdy! Aku {STR_VAR_3}!\n"
	.string "Aku murid no. {STR_VAR_2} dari {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} memberitahuku apa yang harus dilakukan.\n"
	.string "Jadi satu {STR_VAR_2} pemakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "dan satu {STR_VAR_2} pemakai {STR_VAR_1},\n"
	.string "aku pilih.\p"
	.string "Jadi, bagaimana katamu?\n"
	.string "Ayolah, buat hariku!\p"
	.string "Tolong, aku mohon padamu!\n"
	.string "Izinkan aku bergabung, jangan buatku pilu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Yeahah! Keberuntungan bersamaku!\n"
	.string "Itu benar-benar membuatku bahagia!\p"
	.string "Sebelum kita mulai bertarung,\n"
	.string "Aku akan segera mendaftar sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Kamu menolakku?\n"
	.string "{PLAYER}, kamu membuatku cemberut!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Uhuk!\p"
	.string "Oh, maaf, aku sedang pilek.\n"
	.string "Tapi POKéMON-ku baik-baik saja.\p"
	.string "Namaku {STR_VAR_3}, murid no. {STR_VAR_2}\n"
	.string "dari {STR_VAR_1}. Uhuk!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Aku menerima saran {STR_VAR_3}\n"
	.string "dan membentuk timku yang terdiri dari\l"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Aku melatih mereka setiap hari,\n"
	.string "bahkan dalam angin dan hujan.\p"
	.string "Itulah kenapa aku pilek,\n"
	.string "kurasa.\p"
	.string "Begitulah aku.\n"
	.string "Mau jadi partner tag-ku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Terima kasih, aku menghargai ini!\n"
	.string "Uhuk, uhuk!\l"
	.string "Tunggu sebentar selagi aku mendaftar.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, kamu tidak mau?\n"
	.string "{PLAYER}, kupikir kita akan jadi pasangan yang baik.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, halo!\n"
	.string "Ini menegangkan.\p"
	.string "Aku {STR_VAR_3}.\n"
	.string "Aku murid no. {STR_VAR_2} dari {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} bilang tim ini akan bagus--\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Aku merasa tidak percaya diri tentang ini,\n"
	.string "tapi maukah kamu mengizinkanku bergabung?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, astaga, terima kasih!\n"
	.string "Aku merasa malu, tapi aku akan melakukan yang terbaik!\p"
	.string "Aku akan menyelesaikan pendaftarannya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, tolong jangan katakan tidak!\n"
	.string "Aku sudah merasa tidak percaya diri…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Aku {STR_VAR_3}, dan itu bukan kebohongan.\n"
	.string "Aku murid no. {STR_VAR_2} dari {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} merekomendasikan timku.\p"
	.string "Karena sarannya terdengar tulus,\n"
	.string "Aku memutuskan untuk membawa\l"
	.string "{STR_VAR_2} pemakai {STR_VAR_1}-ku dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "{STR_VAR_2} pemakai {STR_VAR_1}-ku.\p"
	.string "Jika memungkinkan, aku ingin kamu menerima\n"
	.string "aku sebagai partner tag-team-mu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Kamu benar-benar akan menerimaku?\n"
	.string "Akan sangat buruk jika tidak.\p"
	.string "Tapi karena kamu sudah setuju, ini baik-baik saja.\n"
	.string "Aku akan mendaftarkan kita berdua.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Kenapa kamu menolak?\n"
	.string "Apa ini leluconmu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Aku {STR_VAR_1}, dan aku seorang LASS!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Yang aku punya adalah satu {STR_VAR_2}\n"
	.string "yang memakai {STR_VAR_1} dan satu$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} yang memakai {STR_VAR_1}.\n"
	.string "Itulah yang kubawa.\p"
	.string "Maukah kamu menjadi partner-ku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Terima kasih!\n"
	.string "Aku akan pergi mendaftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Kamu tidak mau jadi partner-ku?\n"
	.string "Kamu akan menyesal nanti!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Halo!\p"
	.string "Aku YOUNGSTER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Mau tahu apa yang aku punya?\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Kamu akan jadi partner tag-team-ku,\n"
	.string "kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Yay!\n"
	.string "Aku akan pergi mendaftar, oke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Aww! Jika kamu membentuk tag team dengan\n"
	.string "POKéMON-ku, kita takkan terkalahkan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yahoo!\n"
	.string "Aku HIKER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Tahu apa yang kubawa?\n"
	.string "{STR_VAR_2} pemakai {STR_VAR_1}-ku dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "{STR_VAR_2} pemakai {STR_VAR_1}-ku!\p"
	.string "Kedengarannya bagus, kan?\n"
	.string "Mau membentuk tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yahoo!\n"
	.string "Kalau begitu, aku akan mendaftar.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Aku ingin sekali bertarung denganmu\n"
	.string "di sisiku.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Halo!\n"
	.string "Aku {STR_VAR_1}, dan aku seorang BEAUTY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Apa kamu tahu apa yang telah kubesarkan?\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Bagaimana menurutmu?\n"
	.string "Mau membuat tag team bersama?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Luar biasa!\n"
	.string "Aku akan selesaikan pendaftarannya sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Mengecewakan sekali!\p"
	.string "Kita berdua bersama--kita akan\n"
	.string "menjadi yang terbaik!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Yo!\p"
	.string "Kamu tahu siapa aku?\n"
	.string "Aku {STR_VAR_1} si FISHERMAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Aku punya tim yang terdiri dari satu\n"
	.string "{STR_VAR_2} pemakai {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "satu {STR_VAR_2} pemakai {STR_VAR_1}.\p"
	.string "Jadi, bagaimana?\n"
	.string "Maukah kamu bertarung di sisiku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bagus, bagus!\n"
	.string "Serahkan padaku!\p"
	.string "Aku akan pergi mendaftarkan kita sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Padahal kita sangat cocok…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Senang berkenalan denganmu.\n"
	.string "Aku {STR_VAR_1}, seorang LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Aku ditemani oleh sebuah tim\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Kuharap aku mendapat persetujuanmu.\n"
	.string "Karena aku ingin kamu menjadi partner-ku.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Aku berterima kasih dengan tulus.\n"
	.string "Aku akan mengurus pendaftarannya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Aku yakin kamu akan menyesal tidak\n"
	.string "menjadikanku sebagai partner-mu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Aku TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Yang aku punya…\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\n"
	.string "Itulah pasanganku!\p"
	.string "Tolong?\n"
	.string "Maukah kamu membentuk tag team denganku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Wah, makasih!\n"
	.string "Aku akan mendaftar di konter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Kita berdua bersama, kita pasti\n"
	.string "akan tangguh!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hiya!\n"
	.string "Aku BUG CATCHER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Lihat apa yang aku punya!\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Jadi, dengar!\n"
	.string "Apa kamu mau membentuk tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Dapat!\p"
	.string "Aku akan mengurus pendaftaran\n"
	.string "di konter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Aww, POKéMON-ku luar biasa.\n"
	.string "Kuharap kamu tidak akan menyesali ini!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Selamat siang!\n"
	.string "Aku SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Yang telah kubesarkan adalah satu\n"
	.string "{STR_VAR_2} yang memakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "dan satu {STR_VAR_2} yang memakai\n"
	.string "{STR_VAR_1}.\p"
	.string "Tidak terlalu buruk, kan?\n"
	.string "Maukah kamu membentuk tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Terima kasih banyak!\n"
	.string "Aku akan menyelesaikan pendaftarannya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Sayang sekali…\p"
	.string "Padahal aku berharap bisa belajar\n"
	.string "darimu sebagai partner-mu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo! Biar kuberitahu siapa aku!\n"
	.string "Aku RICH BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Tebak apa yang aku punya!\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Aku bersedia memberimu kesempatan\n"
	.string "untuk berada dalam tag team denganku.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Langkah cerdas!\p"
	.string "Aku akan menyelesaikan proses\n"
	.string "pendaftaran dengan cepat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Kamu menolakku dari semua orang?\n"
	.string "Kamu pasti akan menyesali keputusan itu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah!\n"
	.string "Aku BLACK BELT {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Sebagai temanku, aku punya\n"
	.string "satu {STR_VAR_2} yang memakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "dan satu {STR_VAR_2} yang memakai\n"
	.string "{STR_VAR_1}.\p"
	.string "Tolong, kabulkan permohonanku!\n"
	.string "Izinkan aku menjadi partner tag-mu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah!\n"
	.string "Aku akan segera mendaftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Begitu… Kuharap ada kesempatan\n"
	.string "lain kali kita bertemu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hai!\n"
	.string "Aku {STR_VAR_1}, dan aku seorang TUBER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Akan kuberitahu apa yang aku punya.\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\n"
	.string "Bolehkah aku masuk ke dalam tag team-mu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Terima kasih!\n"
	.string "Aku akan mendaftarkan kita sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Jika kita menjadi partner, kita bisa\n"
	.string "menjadi sangat kuat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Salam…\n"
	.string "Aku HEX MANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Aku membawa satu {STR_VAR_2} pemakai\n"
	.string "{STR_VAR_1} bersama dengan satu$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} pemakai {STR_VAR_1}…\p"
	.string "Aku mohon padamu…\n"
	.string "Bergabunglah denganku dalam tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Aku berterima kasih…\n"
	.string "Aku akan mendaftarkan kita…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Aku sangat ingin bergabung denganmu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Apa kabar? Aku {STR_VAR_1},\n"
	.string "dan aku seorang POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Aku membesarkan beberapa yang bagus!\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Bagaimana?\n"
	.string "Ingin membuat tag team denganku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Terima kasih banyak!\p"
	.string "Aku akan mengurus pendaftaran,\n"
	.string "jadi tunggu di sini!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Aku sudah tidak sabar untuk menjadi\n"
	.string "partner-mu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Wah, halo!\n"
	.string "Aku TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Mau tahu dengan apa aku berlari?\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Jadi?\n"
	.string "Mau masuk tag team denganku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Bagus!\p"
	.string "Aku akan cepat menyelesaikan\n"
	.string "semua pendaftarannya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Kamu dan aku, kita akan menjadi yang teratas.\n"
	.string "Sayang sekali…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Hei! Namaku {STR_VAR_1}!\n"
	.string "Aku seorang TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Aku berlari dengan timku yang tangguh--\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Tidak terlalu buruk, kan?\n"
	.string "Kita harus berada dalam satu tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Baiklah!\n"
	.string "Aku akan mendaftar secepat kilat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Aku sangat ingin bertarung sebagai\n"
	.string "partner tag-team-mu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Aku BATTLE GIRL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "Aku telah melatih satu\n"
	.string "{STR_VAR_2} pemakai {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "satu {STR_VAR_2} pemakai {STR_VAR_1}!\p"
	.string "Apa kamu suka kombo itu?\n"
	.string "Bagaimana kalau kita bergabung?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Wah, makasih!\p"
	.string "Aku akan menyelesaikan pendaftaran\n"
	.string "sekarang juga!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Denganmu, kupikir kita bisa membentuk\n"
	.string "tag team terhebat…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Aku TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Aku telah berlari dengan satu {STR_VAR_2}\n"
	.string "yang tahu cara memakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "dan satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Kita bisa menjadi satu tag team.\n"
	.string "Bukankah itu hebat?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Terima kasih!\p"
	.string "Aku akan mendaftarkan kita, dan itu\n"
	.string "sekarang juga!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Aww, sayang sekali. Kita akan menjadi\n"
	.string "tag team terkuat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Aku?\n"
	.string "Aku TUBER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Apa yang kubawa?\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Hei?\n"
	.string "Kamu mau jadi partner-ku, kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Oke!\p"
	.string "Aku akan mendaftar!\n"
	.string "Ayo jadi yang terbaik bersama!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "POKéMON-ku pasti tangguh…\n"
	.string "Sayang sekali kamu tidak mau satu tim.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yay-hey!\n"
	.string "Panggil aku GUITARIST {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Lihat rombonganku!\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Yay-hey! Cukup liar, kan?\n"
	.string "Kita harus berduet dalam tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Yay-hey! Keren!\n"
	.string "Aku akan urus pendaftarannya sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "POKéMON-ku keren abis!\n"
	.string "Kamu akan menyesal, kuberitahu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Senang bertemu denganmu.\n"
	.string "Aku {STR_VAR_1}, seorang GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Aku ditemani oleh {STR_VAR_2} pemakai\n"
	.string "{STR_VAR_1} kepercayaanku dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "satu {STR_VAR_2} pemakai {STR_VAR_1}.\p"
	.string "Bolehkah aku memintamu untuk bergabung denganku\n"
	.string "dalam pengaturan kemitraan tag-team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, aku berterima kasih atas kepercayaanmu.\n"
	.string "Aku akan menyelesaikan pendaftarannya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Sangat disayangkan…\p"
	.string "Aku akan menantikan kesempatan\n"
	.string "berikutnya…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Halo, aku {STR_VAR_1},\n"
	.string "dan aku seorang POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Aku punya satu {STR_VAR_2}\n"
	.string "yang tahu jurus {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Apa kamu suka yang kamu lihat?\n"
	.string "Kenapa kamu tidak jadi partner tag-ku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Terima kasih!\n"
	.string "Aku akan mengurus pendaftarannya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "POKéMON-ku kelas atas…\n"
	.string "Sayang sekali kamu tidak bisa menghargainya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm!\n"
	.string "Aku {STR_VAR_1}, dan aku seorang EXPERT!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "POKéMON yang telah kulatih adalah\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Bagaimana kalau kita satu tim tag?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm!\n"
	.string "Aku akan segera mendaftarkan kita!\l"
	.string "Mari kita berdua melakukan yang terbaik!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Aku akan berharap pilihanmu\n"
	.string "memang benar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Halo, halo.\n"
	.string "Aku {STR_VAR_1}, dan aku seorang EXPERT.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "Aku telah membesarkan POKéMON-ku dengan baik.\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}--\n"
	.string "itulah yang aku punya.\p"
	.string "Tidakkah kamu ingin satu tim denganku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bagus, bagus.\n"
	.string "Aku akan segera mengurus pendaftarannya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Mungkin kita bisa membentuk tim lain\n"
	.string "kali kita bertemu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Aku DRAGON TAMER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Tim yang telah kulatih adalah\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Bagaimana?\n"
	.string "Mau jadi partner-ku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Oke, aku akan berikan yang terbaik!\n"
	.string "Aku akan mendaftar sekarang, oke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Kamu tidak akan menemukan banyak partner\n"
	.string "yang lebih tangguh dariku!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Aku BIRD KEEPER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "POKéMON apa yang aku punya?\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Tidakkah menurutmu kita akan menjadi\n"
	.string "tim tag yang layak?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Bagus, makasih!\n"
	.string "Aku akan mengurus pendaftarannya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "POKéMON-ku dan aku kuat.\n"
	.string "Mengecewakan sekali.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Aku NINJA BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Tim POKéMON-ku terdiri dari satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Ayo kita buat tag team bersama!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Yay!\n"
	.string "Biar aku yang mendaftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Kamu akan menyesal tidak memiliki POKéMON\n"
	.string "tangguhku di sisimu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Halo!\n"
	.string "Aku PARASOL LADY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Yang menemaniku sekarang adalah {STR_VAR_2}-ku\n"
	.string "yang memakai {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "satu {STR_VAR_2} yang memakai\n"
	.string "{STR_VAR_1}.\p"
	.string "Bukankah mereka baik?\n"
	.string "Mau bergabung dengan kami dalam tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Terima kasih banyak!\p"
	.string "Aku akan mendaftar di konter.\n"
	.string "Jangan sampai kita saling mengecewakan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "POKéMON-ku luar biasa kuat.\n"
	.string "Mengecewakan sekali…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Halo.\n"
	.string "Aku {STR_VAR_1}, dan aku seorang BUG MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Aku telah menemukan POKéMON-ku, ya.\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}--\n"
	.string "itulah yang kutemukan.\p"
	.string "Bolehkah aku menarik minatmu untuk membentuk\n"
	.string "sebuah tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Oke!\n"
	.string "Dimengerti!\p"
	.string "Aku tidak akan lama dengan pendaftarannya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Dengan POKéMON yang kutemukan, kita tidak\n"
	.string "akan kalah…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoy!\n"
	.string "Aku SAILOR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Biar kutunjukkan kebanggaan dan kegembiraanku!\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Tentu saja kamu tidak akan menolakku.\n"
	.string "Kita akan satu tim, kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Aku tidak mengharapkan yang kurang!\n"
	.string "Aku akan mendaftar sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Kita akan menyerbu lawan!\n"
	.string "Sayang sekali!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hai, aku {STR_VAR_1}.\n"
	.string "Aku seorang COLLECTOR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Permata dalam koleksiku adalah\n"
	.string "{STR_VAR_2}-ku dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Hebat, kan?\n"
	.string "Kita harus berada dalam satu tim.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, ya!\p"
	.string "Baiklah, jangan buang waktu.\n"
	.string "Aku akan mendaftarkan kita berdua.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Yah, itu menyebalkan.\n"
	.string "Kamu tidak menghargai POKéMON-ku.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Howdy, aku {STR_VAR_1}.\n"
	.string "Aku seorang POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Yang menemaniku adalah satu\n"
	.string "{STR_VAR_2} pemakai {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Tidakkah menurutmu kita akan membuat\n"
	.string "tag team yang mengesankan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Itu super!\n"
	.string "Aku akan mengurus pendaftarannya sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Lain kali, pilih POKéMON-ku,\n"
	.string "ya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Namaku {STR_VAR_1}.\n"
	.string "Aku seorang POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Biar kuceritakan tentang timku. Aku punya\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Bagaimana kalau kamu membentuk tag team\n"
	.string "dengan pasukan kecilku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Kita akan menjadi yang terbaik!\n"
	.string "Aku akan menyelesaikan pendaftarannya dengan cepat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Kuharap kamu akan memilih POKéMON-ku\n"
	.string "lain kali.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Senang bertemu denganmu. Aku {STR_VAR_1}.\n"
	.string "Aku menganggap diriku seorang AROMA LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Aku bepergian dengan satu {STR_VAR_2}\n"
	.string "yang memakai {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "satu {STR_VAR_2} yang memakai\n"
	.string "{STR_VAR_1}.\p"
	.string "Kuharap mereka menarik perhatianmu.\n"
	.string "Maukah kamu menjadi partner-ku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Aku merasa terhormat atas penerimaanmu.\n"
	.string "Aku akan segera mendaftar.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Akan sangat menyenangkan jika kita bisa\n"
	.string "membentuk tag team lain kali kita bertemu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Mau tahu siapa aku?\n"
	.string "Aku {STR_VAR_1}, si RUIN MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "POKéMON yang kubawa adalah\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Menarik, kan?\n"
	.string "Bagaimana kalau kita berpartner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Itu keputusan yang bagus!\n"
	.string "Aku akan mengurus surat-surat pendaftarannya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\n"
	.string "Kupikir POKéMON-ku tangguh…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Aku COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "POKéMON yang aku punya sekarang adalah satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\n"
	.string "Keren, kan?\p"
	.string "Tidakkah menurutmu akan sangat keren\n"
	.string "jika kita membuat tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Keren!\n"
	.string "Aku akan mendaftar dalam sekejap!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Kupikir kita akan menjadi tim\n"
	.string "terhebat yang pernah ada.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Aku COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "Tim yang kubesarkan punya satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Kedengarannya oke?\n"
	.string "Bagaimana kalau kita menjadi partner tag?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Terdengar A-OK!\n"
	.string "Sebaiknya aku melakukan pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Aku berpikir bagaimana kita akan menjadi\n"
	.string "satu tim yang tangguh…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Heyo!\n"
	.string "Aku {STR_VAR_1}, sang POKéMANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Apa yang dimiliki orang sepertiku?\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1},\n"
	.string "begitulah!\p"
	.string "Ayo lakukan!\n"
	.string "Kita akan menggebrak sebagai tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Pilihan bagus!\n"
	.string "Aku akan mendaftarkan kita berdua!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "POKéMON-ku brutal!\n"
	.string "Bukan salahku jika kamu menyesal!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Yo, halo!\n"
	.string "Aku KINDLER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Kamu tahu apa yang dihasilkan latihanku?\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Jadi, bagaimana katamu?\n"
	.string "Mau membentuk tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Baiklah!\n"
	.string "Aku akan melanjutkan pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Berjanjilah kamu akan berpartner denganku\n"
	.string "lain kali kita bertemu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Aku {STR_VAR_1}, dan aku seorang CAMPER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "Aku telah membesarkan satu {STR_VAR_1}-\n"
	.string "memakai {STR_VAR_2} dan satu$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} pemakai {STR_VAR_1}.\p"
	.string "Menurutmu menyenangkan tidak untuk satu tim?\n"
	.string "Aku yakin akan menyenangkan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Yeah!\n"
	.string "Aku pergi mendaftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Lain kali, ya?\n"
	.string "Aku ingin ada di timmu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Halo!\n"
	.string "Aku {STR_VAR_1}, dan aku seorang PICNICKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "POKéMON yang kubawa adalah\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Apa kamu tertarik bergabung denganku\n"
	.string "dalam sebuah tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Wah, terima kasih!\n"
	.string "Aku akan melakukan pendaftaran sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Akan menyenangkan jika aku bisa bergabung\n"
	.string "denganmu lain waktu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Aku PSYCHIC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Pasangan yang kubesarkan adalah\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Maukah kamu membentuk tag team\n"
	.string "denganku?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Tentu saja!\n"
	.string "Aku akan mengurus pendaftarannya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Jika kita bertemu lagi, saat itulah aku ingin\n"
	.string "satu tim denganmu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Aku {STR_VAR_1}.\n"
	.string "Aku seorang PSYCHIC.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}--\n"
	.string "mereka adalah murid-muridku.\p"
	.string "Tidakkah ide membentuk kemitraan\n"
	.string "tag-team membuatmu tertarik?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Terima kasih.\n"
	.string "Aku akan mengurus pendaftarannya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Kuharap akan ada kesempatan lain\n"
	.string "untuk menjalin aliansi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Aku SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Satu {STR_VAR_2} pemakai {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "dan satu {STR_VAR_2} pemakai {STR_VAR_1}\n"
	.string "adalah pasangan POKéMON-ku.\p"
	.string "Bolehkah aku menjadi partnermu di\n"
	.string "sebuah tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, terima kasih!\n"
	.string "Aku akan segera mendaftar di konter!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Tolong?\n"
	.string "Bolehkah aku bergabung lain kali?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hiya! Namaku {STR_VAR_1}!\n"
	.string "Aku seorang POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "POKéMON yang kubesarkan adalah satu\n"
	.string "{STR_VAR_2} pemakai {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "satu {STR_VAR_2} pemakai {STR_VAR_1}.\p"
	.string "Terdengar menarik?\n"
	.string "Bagaimana kalau kita membentuk tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Baiklah!\n"
	.string "Serahkan pendaftaran padaku!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Kamu harus satu tim denganku lain kali,\n"
	.string "oke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Aku {STR_VAR_1}, dan dengan bangga kukatakan\n"
	.string "bahwa aku adalah seorang POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "POKéMON kesayangan yang kubesarkan adalah\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Bukankah mereka yang paling lucu?\n"
	.string "Kita harus membuat sebuah tim!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Terima kasih, sayang!\n"
	.string "Aku akan segera mendaftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "POKéMON kesayanganku yang terbaik,\n"
	.string "asal kamu tahu. Menyebalkan sekali!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hai, Aku PERENANG {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Satu {STR_VAR_2} pengguna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "dan satu {STR_VAR_2} pengguna {STR_VAR_1}\n"
	.string "yang sudah kulatih.\p"
	.string "Ayo kita buat tim tag.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Keren!\n"
	.string "Aku akan mendaftarkan kita berdua.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Jika bertemu lagi, kamu harus\n"
	.string "satu tim denganku!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Ada apa?\n"
	.string "Aku {STR_VAR_1}, seorang ATLET TRIATLON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Aku punya beberapa POKéMON lumayan.\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Akan keren jika kita membentuk tim\n"
	.string "tag, bagaimana?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Mantap!\n"
	.string "Tunggu selagi aku mendaftar, oke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Lain kali, ajak aku bergabung ya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Aku ATLET TRIATLON {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "{STR_VAR_2} lain yang bisa menggunakan\n"
	.string "{STR_VAR_1}. Itulah pasanganku.\p"
	.string "Bagaimana menurutmu?\n"
	.string "Menurutku kita akan jadi tim yang bagus.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "Aku suka jawaban itu!\n"
	.string "Aku akan segera selesaikan pendaftaran!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Beri aku kesempatan lain untuk\n"
	.string "bermitra, ya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Hai! Halo!\n"
	.string "Aku {STR_VAR_1}, seorang PERENANG!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Lihat yang sudah kulatih!\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Keren, kan?\n"
	.string "Akan keren juga jika membentuk tim!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Terima kasih!\n"
	.string "Aku akan selesaikan pendaftaran ini!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Jika kita bertemu lagi, kamu harus\n"
	.string "satu tim denganku. Janji, ya?$"

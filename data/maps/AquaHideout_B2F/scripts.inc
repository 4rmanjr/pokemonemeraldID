AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe…\p"
	.string "Sudah sampai sini, ya?\n"
	.string "Kami meremehkanmu!\p"
	.string "Tapi cukup sampai di sini!\p"
	.string "Aku jauh lebih hebat dari para KROCO\n"
	.string "yang kamu temui.\p"
	.string "Aku tidak mengulur waktu.\n"
	.string "Aku akan menghancurkanmu!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe…\n"
	.string "Jadi, aku kalah juga…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "Selama aku bermain-main denganmu, BOS\n"
	.string "kami sudah menyelesaikan persiapannya!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "BOS kami sudah pergi menuju\n"
	.string "gua di bawah laut!\p"
	.string "Kalau mau mengejar, lebih baik cari\n"
	.string "di lautan luas sekitar LILYCOVE.\p"
	.string "Tapi apa kamu akan menemukannya?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, aku bosan menunggu!\n"
	.string "Lawan aku juga!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Lelah menunggu…\n"
	.string "Kalah dan linglung…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BOS…\n"
	.string "Apa ini sudah cukup?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Panel warp, kebanggaan MARKAS ini!\p"
	.string "Kamu bingung ada di mana, kan?\p"
	.string "Buat bingung dan lelahkan musuh, lalu\n"
	.string "habisi! Itulah rencana kami!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Ada apa denganmu?\n"
	.string "Kamu tidak lelah sama sekali!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Ngomong-ngomong… Aku lupa di mana\n"
	.string "menaruh MASTER BALL.\p"
	.string "Kalau gagal menjaganya, aku bisa\n"
	.string "dimarahin BOS…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Saat gabung TIM AQUA, hal pertama\n"
	.string "yang harus kupelajari adalah koneksi\l"
	.string "antar panel warp ini.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Aku terlalu sibuk memikirkan\n"
	.string "panel warp…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Aku harus belajar cara bertarung\n"
	.string "yang lebih efektif…$"

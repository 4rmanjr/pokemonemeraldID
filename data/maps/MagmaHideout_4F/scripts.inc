MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Aku juga ingin melihat GROUDON, tapi\n"
	.string "mereka tidak mengizinkanku melihat\l"
	.string "ekornya pun…\p"
	.string "Itu membuatku sangat frustrasi.\p"
	.string "Oh, tidak!\n"
	.string "Aku keceplosan tentang GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Kurasa mustahil menang jika pikiran\n"
	.string "tidak tenang…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Apa GROUDON punya ekor, ya?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Segera! Sebentar lagi!\l"
	.string "Tujuan besar kita akan tercapai!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "Sudah sejauh ini, tapi sekarang begini?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "Tuan MAXIE!\n"
	.string "Penyusup menuju ke arahmu!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Kamu belum selesai!\n"
	.string "Kamu tidak akan melewatiku dengan mudah!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Apa aku semudah itu dikalahkan?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "A-ayo, satu ronde lagi…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "Kamu sudah sampai sejauh ini, jadi akan\l"
	.string "kuberitahu!\p"
	.string "Benar sekali!\n"
	.string "Di depan sana, GROUDON sedang tidur!\p"
	.string "MAXIE baru saja pergi ke GROUDON\n"
	.string "beberapa detik yang lalu!\p"
	.string "Dia akan segera bangun!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Kalah lagi…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Dan selagi kamu buang-buang waktu\n"
	.string "denganku, MAXIE seharusnya sudah\l"
	.string "membangunkan GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Tidak ada yang bisa membangunkanmu dari\n"
	.string "tidurmu yang bermandikan magma…\p"
	.string "BLUE ORB ini yang kamu cari.\n"
	.string "Bukan begitu?\p"
	.string "Aku sudah membawakanmu BLUE ORB.\n"
	.string "Biar sinarnya membangunkanmu!\p"
	.string "Dan tunjukkan padaku…\n"
	.string "Tunjukkan kekuatan penuhmu!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "Ada apa?\p"
	.string "Bukankah BLUE ORB kuncinya?\p"
	.string "GROUDON!\n"
	.string "Ke mana kamu pergi…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Oh, jadi itu kamu?\p"
	.string "Aku sudah melihatmu berkeliaran tanpa\n"
	.string "diundang di sana-sini…\p"
	.string "Aku mengerti sekarang!\n"
	.string "Kamu pasti melakukan trik murahan!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Apa yang membuatmu begitu mahir\n"
	.string "menangani POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE: Pasti ada alasan kenapa\n"
	.string "GROUDON lari…\p"
	.string "Itu yang ingin kamu katakan, kan?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Huh…\n"
	.string "Kamu pikir aku tidak tahu itu?\p"
	.string "Dengan perginya GROUDON, tidak ada lagi\n"
	.string "kegunaan gunung berapi terkutuk ini.\p"
	.string "Aku akan mengejar GROUDON, jadi di\n"
	.string "sinilah kita berpisah!$"

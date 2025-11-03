FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "Dengan bersama POKéMON, orang-orang\n"
	.string "mendapatkan lebih banyak teman.\p"
	.string "Dan itu membuat dunia menjadi lebih\n"
	.string "dekat. Menurutku itu luar biasa!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Itu dia!\n"
	.string "Pergi, POKéMON BURUNG!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Heheh, aku meminta WINGULL-ku untuk\n"
	.string "melakukan sesuatu untukku.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Bagus!\n"
	.string "Selamat datang kembali, WINGULL!\p"
	.string "Hah? Apa ini?\n"
	.string "Apa yang dibawanya?\p"
	.string "MENTAL HERB?\n"
	.string "Pasti ia memungutnya di suatu tempat.\p"
	.string "Tapi aku bukan TRAINER, jadi kamu\n"
	.string "boleh mengambilnya.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Berkat WINGULL-ku, aku punya teman\n"
	.string "yang tinggal jauh.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

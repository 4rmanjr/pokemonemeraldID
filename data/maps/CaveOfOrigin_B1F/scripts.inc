CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, jadi kamu {PLAYER}{KUN}?\n"
	.string "Aku sudah mendengar kisah-kisah kehebatanmu.\p"
	.string "Namaku WALLACE.\p"
	.string "Aku pernah menjadi GYM LEADER\n"
	.string "SOOTOPOLIS, tapi ada sesuatu yang terjadi.\p"
	.string "Jadi sekarang, aku telah mempercayakan\n"
	.string "pengoperasian GYM kepada mentorku, JUAN.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON dan KYOGRE, dua POKéMON yang\n"
	.string "membuat kekacauan di sini, dianggap\l"
	.string "sebagai POKéMON super-purba.\p"
	.string "Tapi POKéMON super-purba tidak hanya\n"
	.string "ada dua.\p"
	.string "Ada satu lagi di suatu tempat.\p"
	.string "Di suatu tempat, ada POKéMON super-purba\n"
	.string "bernama RAYQUAZA.\p"
	.string "Dikatakan bahwa RAYQUAZA-lah yang\n"
	.string "menenangkan kedua petarung itu di\l"
	.string "masa lalu.\p"
	.string "Tapi bahkan aku tidak tahu di mana\n"
	.string "keberadaan RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, apakah kamu mungkin\n"
	.string "tahu di mana RAYQUAZA sekarang?\p"
	.string "Jika iya, tolong beritahu aku.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: CAVE OF ORIGIN?\p"
	.string "Tapi itu kan di sini!\n"
	.string "Aku butuh jawaban yang lebih baik dari itu!\p"
	.string "Tolong, aku ingin kamu memikirkan di mana\n"
	.string "RAYQUAZA mungkin berada saat ini.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: MT. PYRE?\p"
	.string "Tapi saat aku bertemu wanita tua di sana\n"
	.string "tadi, dia tidak menyebutkannya sama sekali.\p"
	.string "Aku sangat ragu wanita tua itu akan\n"
	.string "mencoba menyembunyikan sesuatu dariku…\p"
	.string "{PLAYER}{KUN}, bisakah kamu memikirkan ini\n"
	.string "lebih cermat lagi untukku?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Hah? Kamu tidak ingat?\n"
	.string "Hmm… Ini masalah…\p"
	.string "Tidak bisakah kamu mengingatnya?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: SKY PILLAR?\p"
	.string "Itu dia!\n"
	.string "Pasti itu SKY PILLAR!\p"
	.string "{PLAYER}{KUN}, tidak ada waktu lagi!\n"
	.string "Kita akan segera menuju ke SKY PILLAR!$"


//aistudio
MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Tidak! Preman TEAM MAGMA itu sudah\n"
	.string "sampai duluan di sini!\p"
	.string "Kita tidak boleh tertinggal!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Aku kira kamu salah satu anggota\n"
	.string "MAGMA yang kembali…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ya, kamu memang kuat…\n"
	.string "Tapi kami banyak!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Kasihan sekali kamu!\p"
	.string "Kalau kamu datang lebih awal, kamu\n"
	.string "hanya akan melawan TEAM MAGMA yang\l"
	.string "lemah.\p"
	.string "Tapi karena kamu datang sekarang,\n"
	.string "kamu harus menghadapi kami yang\l"
	.string "tangguh!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… Seharusnya aku biarkan kamu\n"
	.string "melawan TEAM MAGMA dulu…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Kamu tidak tahu apa-apa!\n"
	.string "Jadi kenapa kamu mengganggu kami?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Kamu…\n"
	.string "Kami melihatmu di MT. CHIMNEY.\p"
	.string "Kamu bukan anggota TEAM mana pun,\n"
	.string "jadi kenapa kamu di sini?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Kalau kamu mau mengganggu siapa pun,\n"
	.string "biarkan saja TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, tidak masalah!\n"
	.string "Kami sudah mengulur waktu!\p"
	.string "BOSS pasti sudah mengambil apa yang\n"
	.string "dia inginkan!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, aku tahu!\n"
	.string "Kamu mencoba bergabung dengan TEAM\l"
	.string "MAGMA, tapi mereka tidak mau\l"
	.string "menerimamu!\p"
	.string "Yah, jangan kira kami akan\n"
	.string "membiarkanmu bergabung dengan TEAM\l"
	.string "AQUA kami!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Kalau kamu sangat ingin bergabung\n"
	.string "dengan TEAM AQUA, kami bisa\l"
	.string "mempertimbangkannya…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Kami punya kombinasi hebat antara\n"
	.string "anggota & pemimpin kami.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: MAXIE dari TEAM MAGMA\n"
	.string "mendahului kami, tapi kami juga\l"
	.string "mendapatkan apa yang kami inginkan.\p"
	.string "RED ORB yang tersimpan di MT. PYRE…\n"
	.string "Aku, ARCHIE, sekarang memilikinya!\p"
	.string "Fufufu… Sekarang kami bisa\n"
	.string "mewujudkan tujuan utama kami!\p"
	.string "Oke, TEAM!\n"
	.string "Kita mundur!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, tidak…\n"
	.string "Ini tidak boleh terjadi…\p"
	.string "Bukan hanya BLUE ORB, tapi bahkan\n"
	.string "RED ORB juga telah diambil…\p"
	.string "BLUE ORB & RED ORB tidak boleh\n"
	.string "terpisah. Mereka harus bersama.\p"
	.string "Apa yang coba dilakukan orang-orang\n"
	.string "itu dengan kedua ORB?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, ya. Apakah TEAM MAGMA yang\n"
	.string "datang & mengambil BLUE ORB duluan?\p"
	.string "Yah, karena terburu-buru, mereka\n"
	.string "meninggalkan ini.\p"
	.string "Aku tidak bisa membayangkan apa\n"
	.string "sebenarnya ini.\p"
	.string "Aku ingin kamu memilikinya.\n"
	.string "Mungkin ini akan berguna.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "BLUE ORB & RED ORB diambil oleh\n"
	.string "orang-orang jahat itu…\p"
	.string "Mereka tidak boleh terpisah…\n"
	.string "Aku takut sesuatu yang buruk akan\l"
	.string "terjadi…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Astaga…\p"
	.string "Kamu bilang GROUDON & KYOGRE\n"
	.string "keduanya sudah terbangun?\p"
	.string "Konon BLUE ORB & RED ORB\n"
	.string "meredakan amarah kedua POKéMON\l"
	.string "itu…\p"
	.string "Konon juga pemilik asli ORB\n"
	.string "masih ada.\p"
	.string "Namun, tidak ada yang tahu siapa,\n"
	.string "atau apa sebenarnya, pemilik ORB\l"
	.string "itu.\p"
	.string "Bisa jadi manusia, atau mungkin\n"
	.string "POKéMON, tapi tidak ada yang tahu.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Kedua pria yang mengambil ORB itu\n"
	.string "kembali untuk mengembalikannya\l"
	.string "sendiri.\p"
	.string "Orang-orang itu…\n"
	.string "Mungkin mereka tidak sejahat itu.$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Wujud dari daratan, lautan, &\n"
	.string "langit…\p"
	.string "Konon itulah identitas POKéMON\n"
	.string "super-kuno…\p"
	.string "Sama seperti kita manusia &\n"
	.string "POKéMON punya kehidupan, dunia\l"
	.string "kita juga hidup…\p"
	.string "POKéMON super-kuno telah\n"
	.string "mengajarkan kita itu…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "MT. PYRE adalah tempat kami\n"
	.string "menenangkan arwah POKéMON yang\l"
	.string "telah tiada…\p"
	.string "Ini adalah tempat tinggi di mana\n"
	.string "seseorang bisa melihat seluruh\l"
	.string "HOENN…\p"
	.string "Arwah POKéMON yang tak berwujud\n"
	.string "pasti menemukan kedamaian di sini…\p"
	.string "Apakah kebetulan kamu ada di sini…\p"
	.string "Maukah kamu mendengarkan ceritaku?\n"
	.string "Sebuah kisah yang sudah lama\l"
	.string "diceritakan di wilayah HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Itu terjadi sudah sangat, sangat\n"
	.string "lama…\p"
	.string "Dunia dilanda bentrokan sengit\n"
	.string "antara POKéMON daratan & POKéMON\l"
	.string "lautan…\p"
	.string "POKéMON daratan mengangkat gunung\n"
	.string "& menciptakan benua…\p"
	.string "POKéMON lautan mengangkat ombak\n"
	.string "besar & mengukir samudra…\p"
	.string "Duel sengit mereka berkecamuk\n"
	.string "tanpa akhir.\p"
	.string "Dunia diliputi api besar &\n"
	.string "badai ganas.\p"
	.string "BLUE ORB & RED ORB mengakhiri\n"
	.string "bencana itu.\p"
	.string "Cahaya memancar dari kedua ORB &\n"
	.string "menenangkan musuh yang marah.\p"
	.string "Pasangan itu, menjadi jinak,\n"
	.string "menyelam jauh ke dalam laut di\l"
	.string "mana akhirnya mereka menghilang…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Aku mengerti…\n"
	.string "Yah, itu juga tidak apa-apa…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Tugasku adalah mewariskan legenda\n"
	.string "HOENN kepada generasi mendatang.\p"
	.string "Dan krisis yang baru saja berakhir\n"
	.string "di SOOTOPOLIS menulis ulang sebuah\l"
	.string "legenda…\p"
	.string "Apakah kamu punya waktu untuk\n"
	.string "mendengar legenda baru HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Itu terjadi sudah sangat, sangat\n"
	.string "lama…\p"
	.string "Dunia dilanda bentrokan sengit\n"
	.string "antara POKéMON daratan & POKéMON\l"
	.string "lautan…\p"
	.string "POKéMON daratan mengangkat gunung\n"
	.string "& menciptakan benua…\p"
	.string "POKéMON lautan mengangkat ombak\n"
	.string "besar & mengukir samudra…\p"
	.string "Duel sengit mereka berkecamuk\n"
	.string "tanpa akhir.\p"
	.string "Dunia diliputi api besar &\n"
	.string "badai ganas.\p"
	.string "Saat itulah POKéMON langit turun\n"
	.string "dari badai.\p"
	.string "POKéMON itu, bersinar hijau\n"
	.string "terang, menenangkan kedua POKéMON\l"
	.string "yang marah.\p"
	.string "Kemudian, tugasnya selesai,\n"
	.string "POKéMON hijau itu terbang ke\l"
	.string "angkasa biru yang luas…$"

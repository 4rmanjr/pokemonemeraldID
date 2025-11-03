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
	.string "Tidak! Para berandal TEAM MAGMA itu\n"
	.string "mendahului kami!\p"
	.string "Kami tidak boleh ketinggalan!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Aku pikir kamu adalah salah satu dari MAGMA\n"
	.string "yang kebetulan kembali…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ya, jadi kamu kuat…\n"
	.string "Tapi kami banyak!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Sayang sekali bagimu!\p"
	.string "Jika kamu datang lebih awal, kamu hanya akan\n"
	.string "bertarung melawan TEAM MAGMA yang lemah.\p"
	.string "Tapi karena kamu tiba sekarang, kamu harus\n"
	.string "melawan kami para jagoan!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… Seharusnya Aku membiarkanmu melawan\n"
	.string "TEAM MAGMA duluan…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Kamu tidak tahu apa-apa!\n"
	.string "Jadi mengapa kamu mengganggu kami?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Kamu…\n"
	.string "Kami melihatmu di GUNUNG CHIMNEY.\p"
	.string "Kamu tidak termasuk dalam tim mana pun,\n"
	.string "jadi mengapa kamu ada di sini?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Jika kamu akan mengganggu siapa pun,\n"
	.string "biarkan itu TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, tidak masalah!\n"
	.string "Kami membeli waktu untuk diri kami sendiri!\p"
	.string "KETUA seharusnya sudah merebut apa\n"
	.string "yang dia inginkan!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, Aku tahu!\n"
	.string "Kamu mencoba bergabung dengan TEAM MAGMA,\l"
	.string "tapi mereka tidak menerimamu!\p"
	.string "Yah, jangan berpikir kami akan membiarkanmu\n"
	.string "bergabung dengan TEAM AQUA kami!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Jika kamu sangat ingin bergabung dengan TEAM AQUA,\n"
	.string "kami bisa mempertimbangkannya…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Kami memiliki kombinasi yang hebat\n"
	.string "dengan anggota kami dan pemimpin kami.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: MAXIE dari TEAM MAGMA mendahului\n"
	.string "kami, tapi kami juga mendapatkan apa yang kami inginkan.\p"
	.string "RED ORB yang disimpan di GUNUNG PYRE…\n"
	.string "Aku, ARCHIE, sekarang memilikinya!\p"
	.string "Fufufu… Sekarang kami bisa mewujudkan\n"
	.string "tujuan utama kami!\p"
	.string "Baiklah, TIM!\n"
	.string "Kami mundur!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, tidak…\n"
	.string "Ini tidak boleh terjadi…\p"
	.string "Bukan hanya BLUE ORB, tapi bahkan\n"
	.string "RED ORB pun telah diambil…\p"
	.string "BLUE ORB dan RED ORB tidak boleh\n"
	.string "dipisahkan. Mereka saling melengkapi.\p"
	.string "Apa yang coba dilakukan orang-orang itu dengan\n"
	.string "kedua ORB itu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, ya. Apakah TEAM MAGMA yang datang\n"
	.string "dan mengambil BLUE ORB duluan?\p"
	.string "Nah, karena terburu-buru, mereka meninggalkan\n"
	.string "ini.\p"
	.string "Aku tidak bisa membayangkan apa sebenarnya\n"
	.string "itu.\p"
	.string "Aku ingin kamu memilikinya.\n"
	.string "Mungkin akan berguna dengan cara tertentu.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "BLUE ORB dan RED ORB yang diambil oleh\n"
	.string "orang-orang jahat itu…\p"
	.string "Mereka tidak boleh terpisah…\n"
	.string "Aku takut sesuatu yang mengerikan akan terjadi…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Ya ampun…\p"
	.string "Kamu bilang GROUDON dan KYOGRE\n"
	.string "sudah terbangun?\p"
	.string "Dikatakan bahwa BLUE ORB dan\n"
	.string "RED ORB meredakan amarah\l"
	.string "kedua POKéMON itu…\p"
	.string "Dikatakan juga bahwa pemilik asli\n"
	.string "ORB-ORB itu masih ada.\p"
	.string "Namun, tidak ada yang tahu siapa, atau apa\n"
	.string "sebenarnya, pemilik ORB-ORB itu.\p"
	.string "Bisa jadi manusia, atau mungkin\n"
	.string "POKéMON, tapi tidak ada yang tahu.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Kedua pria yang mengambil ORB-ORB itu datang\n"
	.string "kembali untuk mengembalikannya sendiri.\p"
	.string "Orang-orang itu…\n"
	.string "Mungkin mereka tidak sejahat itu setelah semua…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Perwujudan daratan, lautan,\n"
	.string "dan langit…\p"
	.string "Itulah yang dikatakan sebagai identitas\n"
	.string "POKéMON super-kuno…\p"
	.string "Sama seperti kita manusia dan\n"
	.string "POKéMON memiliki kehidupan, dunia kita juga\l"
	.string "hidup…\p"
	.string "POKéMON super-kuno telah\n"
	.string "mengajarkan kita itu…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "GUNUNG PYRE adalah tempat kami menenangkan roh\n"
	.string "POKéMON yang telah meninggal…\p"
	.string "Ini adalah tempat tinggi di mana seseorang bisa\n"
	.string "melihat seluruh HOENN…\p"
	.string "Roh-roh POKéMON yang tidak berwujud\n"
	.string "pasti menemukan kedamaian di sini…\p"
	.string "Apakah kebetulan kamu ada di sini…\p"
	.string "Maukah kamu mendengarkan ceritaku? Sebuah cerita yang telah\n"
	.string "lama diceritakan di wilayah HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Itu terjadi sudah sangat, sangat lama…\p"
	.string "Dunia dilanda oleh bentrokan sengit\n"
	.string "antara POKéMON daratan\l"
	.string "dan POKéMON lautan…\p"
	.string "POKéMON daratan mengangkat\n"
	.string "gunung dan menciptakan benua…\p"
	.string "POKéMON lautan mengangkat gelombang besar\n"
	.string "dan mengukir lautan…\p"
	.string "Duel sengit mereka berkecamuk tanpa henti.\p"
	.string "Dunia diliputi oleh\n"
	.string "neraka besar dan badai ganas.\p"
	.string "BLUE ORB dan RED ORB mengakhiri\n"
	.string "bencana itu.\p"
	.string "Cahaya memancar dari kedua ORB dan\n"
	.string "menenangkan musuh yang marah.\p"
	.string "Pasangan itu, menjadi jinak, menyelam jauh ke dalam\n"
	.string "laut di mana akhirnya mereka\l"
	.string "menghilang…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Aku mengerti…\n"
	.string "Yah, itu juga tidak apa-apa…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Adalah tugasku untuk meneruskan legenda\n"
	.string "HOENN kepada generasi mendatang.\p"
	.string "Dan krisis yang baru saja berakhir di\n"
	.string "SOOTOPOLIS menulis ulang sebuah legenda…\p"
	.string "Apakah kamu punya waktu untuk mendengar legenda\n"
	.string "baru HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Itu terjadi sudah sangat, sangat lama…\p"
	.string "Dunia dilanda oleh bentrokan sengit\n"
	.string "antara POKéMON daratan\l"
	.string "dan POKéMON lautan…\p"
	.string "POKéMON daratan mengangkat\n"
	.string "gunung dan menciptakan benua…\p"
	.string "POKéMON lautan mengangkat gelombang besar\n"
	.string "dan mengukir lautan…\p"
	.string "Duel sengit mereka berkecamuk tanpa henti.\p"
	.string "Dunia diliputi oleh\n"
	.string "api besar dan badai ganas.\p"
	.string "Saat itulah POKéMON\n"
	.string "langit turun dari badai.\p"
	.string "POKéMON itu, bersinar hijau terang,\n"
	.string "menenangkan kedua POKéMON yang marah.\p"
	.string "Kemudian, setelah tugasnya selesai, POKéMON hijau itu\n"
	.string "terbang menuju langit biru yang luas…$"


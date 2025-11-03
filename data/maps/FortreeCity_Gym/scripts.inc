FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, apa kabar, calon CHAMPION\n"
	.string "{PLAYER}?\p"
	.string "PEMIMPIN GYM FORTREE, WINONA, adalah\n"
	.string "master POKéMON tipe TERBANG.\p"
	.string "Dia menunggu di belakang GYM ini, di\n"
	.string "balik pintu putar.\p"
	.string "Dia menunggu penantang baru yang\n"
	.string "mencoba untuk terbang tinggi!\p"
	.string "Oke, semangat!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Kamu berhasil!\n"
	.string "Kamu telah lepas landas!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Saksikan gaya bertarung elegan dari\n"
	.string "POKéMON BURUNG!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Kamu…\n"
	.string "Kamu kuat…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Seorang TRAINER harus cerdas untuk\n"
	.string "menghadapi kejadian tak terduga.\p"
	.string "Apa kamu cukup cerdas untuk sampai\n"
	.string "ke PEMIMPIN kami?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Para pecinta POKéMON BURUNG\n"
	.string "bercita-cita untuk bergabung GYM ini.\p"
	.string "Sebagai anggota GYM FORTREE, aku\n"
	.string "tidak boleh kalah!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Beban ini terlalu berat untukku\n"
	.string "bawa…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Dunia ini luas, dan ada banyak\n"
	.string "sekali TRAINER tangguh.\p"
	.string "Aku akan terus berlatih dan membuat\n"
	.string "diriku lebih kuat.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "WINONA, PEMIMPIN GYM kami, tidak\n"
	.string "perlu berurusan denganmu!\p"
	.string "Aku saja sudah lebih dari cukup!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "WINONA, aku…\n"
	.string "Aku kalah!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA itu imut dan kuat.\n"
	.string "Dia PEMIMPIN terhebat!\p"
	.string "tersipu…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "WINONA mengajariku secara pribadi!\n"
	.string "Kamu takkan bisa kalahkanku mudah!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Aku dikalahkan…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Berkat WINONA, penduduk FORTREE\n"
	.string "bisa hidup tanpa rasa takut.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Saat WINONA bertarung, wajahnya\n"
	.string "bersinar dengan tekad yang indah…\p"
	.string "Aku takkan membiarkanmu menyaksikan\n"
	.string "pemandangan indah itu!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urk!\n"
	.string "Aku tak bisa menghentikanmu.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Sebaiknya kamu hati-hati!\n"
	.string "Jangan terpesona menatap WINONA\l"
	.string "atau kamu akan jatuh tersungkur!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Kamu harus tahu bahwa ada berbagai\n"
	.string "macam POKéMON tipe TERBANG.\p"
	.string "Kamu tahu itu, kan?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Sepertinya kamu cukup tahu!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Tentu, kamu mengalahkanku.\n"
	.string "Tapi hati-hati! POKéMON PEMIMPIN\l"
	.string "kami, WINONA, sangat serius.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Aku WINONA. PEMIMPIN GYM POKéMON\n"
	.string "FORTREE.\p"
	.string "Aku telah menyatu dengan POKéMON\n"
	.string "BURUNG dan membumbung di angkasa…\p"
	.string "Sekeras apapun pertarungannya, kami\n"
	.string "menang dengan anggun…\p"
	.string "Saksikan koreografi elegan antara\n"
	.string "POKéMON BURUNG dan aku!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Belum pernah kulihat TRAINER\n"
	.string "memerintah POKéMON lebih anggun\l"
	.string "dariku…\p"
	.string "Sebagai pengakuan atas kehebatanmu,\n"
	.string "kuberikan LENCANA GYM ini.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} mendapatkan FEATHER BADGE\n"
	.string "dari WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Dengan FEATHER BADGE, semua POKéMON\n"
	.string "hingga LV 70, bahkan dari pertukaran,\l"
	.string "akan mematuhi setiap perintahmu.\p"
	.string "Kamu juga bisa menggunakan HM FLY\n"
	.string "di luar pertarungan.\p"
	.string "Dan ini…\n"
	.string "Ini hadiah dariku.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 berisi AERIAL ACE.\p"
	.string "Kecepatannya…\n"
	.string "Tak ada POKéMON yang bisa\l"
	.string "menghindarinya.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "PEMIMPIN GYM WINONA terdaftar\n"
	.string "di POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Meskipun aku kalah darimu, aku akan\n"
	.string "tetap setia pada POKéMON BURUNG.$"

FortreeCity_Gym_Text_GymStatue:
	.string "GYM POKéMON KOTA FORTREE$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "GYM POKéMON KOTA FORTREE\p"
	.string "TRAINER BERSERTIFIKAT WINONA:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: Kita manusia tidak akan\n"
	.string "pernah lepas dari gravitasi bumi.\p"
	.string "Tapi dengan berjuang untuk\n"
	.string "keunggulan, kita bisa terbang!\p"
	.string "Kamu telah mencapai puncak sebagai\n"
	.string "CHAMPION yang berkuasa.\p"
	.string "Tolong, izinkan aku melihat kekuatan\n"
	.string "penuhmu saat terbang!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Aku gagal mencapai ketinggianmu lagi…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Meskipun aku kalah, sayap\n"
	.string "hatiku tetap tak terpatahkan.\p"
	.string "Aku bisa bangkit dan terbang lagi\n"
	.string "dan lagi.\p"
	.string "Aku yakin akan hal itu!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: Kita manusia tidak akan\n"
	.string "pernah lepas dari gravitasi bumi.\p"
	.string "Tapi dengan berjuang untuk\n"
	.string "keunggulan, kita bisa terbang!\p"
	.string "Kamu telah mencapai puncak sebagai\n"
	.string "CHAMPION yang berkuasa.\p"
	.string "Tolong, izinkan aku melihat kekuatan\n"
	.string "penuhmu saat terbang!\p"
	.string "Oh, tidak… Apa kamu hanya punya\n"
	.string "satu POKéMON?\p"
	.string "Tolong kembali dengan setidaknya\n"
	.string "dua POKéMON.$"

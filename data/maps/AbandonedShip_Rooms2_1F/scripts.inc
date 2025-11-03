//gemini
AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Saat mencari harta, kami\n"
	.string "menemukan TRAINER!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Kami tidak bisa menang\n"
	.string "meskipun kami bekerja sama…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: Kami tidak bisa menemukan\n"
	.string "harta apa pun… Aku ingin tahu\l"
	.string "apakah sudah diambil orang?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Kamu bahkan tidak punya dua\n"
	.string "POKéMON. Kamu tidak bisa berharap\l"
	.string "mengalahkan kami seperti itu.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: Oh? Kami mencari harta. Tapi\n"
	.string "kami malah menemukan TRAINER!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Ooh, kuat sekali!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Di mana ya harta itu?\p"
	.string "Aku sudah memutuskan apa yang akan\n"
	.string "Aku beli saat kami menemukan harta\l"
	.string "itu!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Oh, Kamu tidak punya dua\n"
	.string "POKéMON? Kita harus bertarung di\l"
	.string "lain waktu!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Oh, Kamu membuatku marah\n"
	.string "sekali! Aku akan mendaftarkanmu\l"
	.string "untuk itu!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: Kami sudah mencari harta\n"
	.string "selama ini.\p"
	.string "POKéMON kami juga sudah bertambah\n"
	.string "kuat. Biar kami tunjukkan padamu,\l"
	.string "oke?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Kamu kuat, seperti biasa!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: Kami tidak bisa menemukan\n"
	.string "harta, kami kalah dalam POKéMON…\p"
	.string "Aku ingin pulang… Tapi jika Aku\n"
	.string "bilang begitu, dia jadi marah\l"
	.string "padaku…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Kamu bahkan tidak punya dua\n"
	.string "POKéMON. Kamu tidak bisa berharap\l"
	.string "mengalahkan kami seperti itu.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Oh? Kita bertemu lagi!\p"
	.string "Sama seperti kami, Kamu masih belum\n"
	.string "menyerah mencari harta, kan?\p"
	.string "Mau membuat yang kalah harus\n"
	.string "menyerah mencari?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Oh, kami kalah lagi…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: Kami tidak akan pergi sampai\n"
	.string "kami melatih POKéMON kami lebih\l"
	.string "lagi dan kami menemukan harta di\l"
	.string "sini!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Oh, Kamu tidak punya dua\n"
	.string "POKéMON? Kita harus bertarung di\l"
	.string "lain waktu!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Aku tidak pandai berenang, tapi Aku\n"
	.string "pandai bertarung!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Ups. Itu tidak berjalan dengan\n"
	.string "baik.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Berjalan tanpa alas kaki di kapal\n"
	.string "ini agak menjijikkan.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Kekuatan dan kasih sayang… Itulah\n"
	.string "harta seorang TRAINER!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, ada sesuatu tentang Kamu yang\n"
	.string "berkilauan.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Di suatu kabin di kapal, Aku\n"
	.string "melihat sesuatu berkilauan.$"

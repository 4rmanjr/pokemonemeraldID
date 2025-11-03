DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Santaplah matamu dengan ini!\p"
	.string "Ini adalah SYAL SUTRA. Ini ada di\n"
	.string "garis terdepan mode, ya!\p"
	.string "Oh, Aku bisa melihat matamu\n"
	.string "berbinar! Kamu menghargai gayaku\l"
	.string "yang memukau!\p"
	.string "Oh, Kamu menyenangkan! Ini dia. Aku\n"
	.string "ingin Kamu memilikinya!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, Kamu tidak punya ruang?\p"
	.string "Nah, dengarkan baik-baik, SYAL ini\n"
	.string "wajib punya! Mengapa, Aku akan\l"
	.string "menjual semua barang-barangku demi\l"
	.string "mendapatkannya!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "SYAL SUTRA meningkatkan kekuatan\n"
	.string "jurus bertipe NORMAL.\p"
	.string "Ini adalah SYAL luar biasa yang\n"
	.string "akan cocok dengan hampir semua\l"
	.string "POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, Kamu repot-repot menyeberangi\n"
	.string "laut untuk mengunjungi DEWFORD?\p"
	.string "Apa Kamu datang ke sini mungkin\n"
	.string "karena Kamu dengar tentang BRAWLY?\p"
	.string "Dia sangat keren… Semua orang\n"
	.string "mengidolakannya.$"

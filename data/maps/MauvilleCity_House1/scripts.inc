//gemini
MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woohoo!\p"
	.string "Aku dengar orang-orang\n"
	.string "memanggilku SI PENGHANCUR\l"
	.string "BATU, tapi aku merasa itu\l"
	.string "agak merendahkan.\p"
	.string "Aku pikir aku pantas dihormati\n"
	.string "lebih, seperti mungkin SI\l"
	.string "PENGHANCUR BATU HEBAT.\p"
	.string "Woohoo!\p"
	.string "Ngomong-ngomong, POKéMON-mu\n"
	.string "terlihat cukup kuat.\p"
	.string "Aku suka itu!\n"
	.string "Ini, ambil HIDDEN MACHINE ini!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "HM itu berisi ROCK SMASH.\p"
	.string "Jika kamu menemukan batu-batu\n"
	.string "besar yang menghalangi jalanmu…\p"
	.string "Nah, gunakan gerakan HM itu\n"
	.string "& hancurkan mereka dari jalanmu!\p"
	.string "Ya, Tuan! Hancurkan batu-batu itu,\n"
	.string "kataku! Woohoo!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Oh, ya, jika kamu menghancurkan\n"
	.string "batu, seekor POKéMON bisa saja\l"
	.string "terbang keluar dari\l"
	.string "persembunyiannya.\p"
	.string "Woohoo!$"

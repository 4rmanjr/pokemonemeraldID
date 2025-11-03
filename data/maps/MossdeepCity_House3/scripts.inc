MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Hei, TRAINER!\n"
	.string "SUPER ROD benar-benar super!\p"
	.string "Apa pun yang kamu katakan, tapi alat\n"
	.string "ini bisa menangkap POKéMON dari dasar\l"
	.string "laut!\p"
	.string "Bagaimana menurutmu?\n"
	.string "Kamu menginginkannya, bukan?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Tentu saja, tentu saja!\n"
	.string "Bagaimanapun, SUPER ROD memang super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Jika ada air, coba lemparkan\n"
	.string "PANCING-mu dan lihat apa yang menggigit!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hah?\n"
	.string "Kamu tidak suka memancing?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Kejar POKéMON dasar laut dengan\n"
	.string "SUPER ROD-mu.$"


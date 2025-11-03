MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "REVIVE itu hebat!\p"
	.string "Berikan pada POKéMON yang pingsan,\n"
	.string "dan POKéMON itu akan bangkit.\p"
	.string "Tapi hati-hati, REVIVE tidak memulihkan\n"
	.string "PP yang terpakai dari gerakan.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "MAX REPEL menjauhkan semua POKéMON lemah.\p"
	.string "Dari semua semprotan REPEL, ini yang\n"
	.string "bertahan paling lama.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "NET BALL dan DIVE BALL adalah POKé BALL\n"
	.string "langka yang hanya dibuat di MOSSDEEP.\p"
	.string "NET BALL efektif melawan POKéMON\n"
	.string "tipe SERANGGA dan AIR.\p"
	.string "DIVE BALL paling baik digunakan pada POKéMON\n"
	.string "di dasar laut.$"


FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	pokemartlistend

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "SUPER REPEL bertahan lama, dan\n"
	.string "sangat efektif.\p"
	.string "Jauh lebih baik daripada REPEL\n"
	.string "biasa.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Aku selalu menyetok lebih banyak item\n"
	.string "dari yang kubutuhkan.\p"
	.string "Kita tidak pernah tahu apa yang akan\n"
	.string "terjadi. Lebih baik sedia payung\l"
	.string "sebelum hujan!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "RARE CANDY membuat POKéMON langsung\n"
	.string "naik satu level.$"

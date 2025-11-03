LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "Gunakan X SPEED untuk menambah SPEED\n"
	.string "POKéMON dalam pertarungan.\p"
	.string "Itu akan membantunya menyerang lebih\n"
	.string "dulu--sebuah keuntungan yang pasti!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "Di puncak MT. CHIMNEY, ada makanan\n"
	.string "khas lokal yang hanya bisa dibeli di\l"
	.string "sana.\p"
	.string "Berikan pada POKéMON--ia akan\n"
	.string "sangat senang.$"

//gemini
VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Untuk setiap pertandingan POKéMON,\n"
	.string "X SPECIAL sangat penting.\p"
	.string "Ini meningkatkan kekuatan beberapa\n"
	.string "gerakan, meskipun hanya untuk satu\l"
	.string "pertarungan.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Sepertinya mereka tidak menjual\n"
	.string "panduan strategi kemenangan untuk\l"
	.string "BATTLE TENT…\p"
	.string "Sepertinya seseorang harus\n"
	.string "mengandalkan kecerdasan sendiri\l"
	.string "pada akhirnya…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "NEST BALL bekerja lebih baik pada\n"
	.string "POKéMON yang melemah.\p"
	.string "VERDANTURF adalah satu-satunya\n"
	.string "tempat kamu bisa membelinya.$"

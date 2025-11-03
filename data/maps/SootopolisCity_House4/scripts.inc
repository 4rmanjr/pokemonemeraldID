//gemini
SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Dengarkan, dan Aku akan\n"
	.string "memberitahumu sesuatu yang bagus.\p"
	.string "Konon ada reruntuhan kuno di laut\n"
	.string "sekitar sini.\p"
	.string "Mungkin ada harta karun yang\n"
	.string "menunggu untuk ditemukan di sana.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Harta karun kuno…\p"
	.string "Alangkah baiknya jika itu ada, tapi\n"
	.string "kalaupun tidak ada, akan sangat\l"
	.string "indah untuk berjalan-jalan di bawah\l"
	.string "air bersama POKéMON-ku.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

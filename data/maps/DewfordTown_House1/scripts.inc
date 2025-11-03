DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Ada banyak hal baik tentang hidup\n"
	.string "di pulau kecil seperti ini, selaras\l"
	.string "dengan POKéMON dan keluarga.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Aku meninggalkan pelabuhan utama\n"
	.string "KOTA SLATEPORT ketika Aku menikah\l"
	.string "dengan suamiku di sini.\p"
	.string "Hidup berjalan lambat di pulau\n"
	.string "kecil ini. Tapi dikelilingi oleh\l"
	.string "laut yang indah-itu juga\l"
	.string "kebahagiaan.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

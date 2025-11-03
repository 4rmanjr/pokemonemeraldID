OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Ketika POKéMON bertarung, mereka\n"
	.string "akhirnya naik level dan\lmenjadi lebih kuat.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Jika POKéMON bersamamu menjadi\n"
	.string "lebih kuat, kamu akan bisa pergi lebih\l"
	.string "jauh dari sini.$"


//gemini
SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Mau kiat untuk bertarung?\p"
	.string "Aku akan bilang, itu adalah\n"
	.string "membesarkan berbagai jenis POKéMON\l"
	.string "dengan cara yang seimbang.\p"
	.string "Tidak bagus jika hanya membuat satu\n"
	.string "POKéMON menjadi kuat.\p"
	.string "Jika memiliki kelemahan tipe,\n"
	.string "mungkin tidak akan punya peluang.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Aku menukar POKéMON dengan\n"
	.string "teman-temanku.\p"
	.string "Jika POKéMON yang ditukar membawa\n"
	.string "item, itu membuatku dua kali lebih\l"
	.string "senang!$"

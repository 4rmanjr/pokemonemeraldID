OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
    .string "Komputer di sudut sana\n"
    .string "dapat digunakan oleh semua\lTRAINER POKÉMON.\p"
    .string "Tentu saja, itu berarti\lAnda juga dipersilakan\l"
    .string "untuk menggunakannya.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTER luar biasa!\p"
	.string "Kamu bisa menggunakan layanan mereka\n"
	.string "sebanyak yang kamu mau,\ldan semuanya gratis.\p"
	.string "Kamu tidak perlu khawatir!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "POKéMON WIRELESS CLUB di lantai\n"
	.string "dua baru saja dibangun.\p"
	.string "Tapi mereka bilang masih melakukan\n"
	.string "penyesuaian.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "POKéMON WIRELESS CLUB di\n"
	.string "lantai dua baru saja dibangun.\p"
	.string "Aku langsung menukarkan POKéMON.$"


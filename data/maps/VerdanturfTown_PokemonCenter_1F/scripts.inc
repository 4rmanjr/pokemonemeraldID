//gemini
VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Kamu tak bisa jadi TRAINER sejati\n"
	.string "jika tak percaya POKéMON-mu.\p"
	.string "Hanya orang yang percaya pada\n"
	.string "POKéMON yang bertarunglah\l"
	.string "yang bisa menang sampai akhir.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "Alasan mengapa orang mengunjungi\n"
	.string "VERDANTURF… Itu BATTLE TENT.\p"
	.string "Sudah jelas.\p"
	.string "Atau apakah ada seseorang di sini\n"
	.string "yang kamu datang untuk temui?$"

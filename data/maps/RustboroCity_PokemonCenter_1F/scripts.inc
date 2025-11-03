RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "POKéMON-ku berwatak NAIVE, dan POKéMON\n"
	.string "temanku berwatak JOLLY.\p"
	.string "Menarik sekali bagaimana POKéMON\n"
	.string "memiliki kepribadian!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Sama seperti manusia, ada POKéMON\n"
	.string "jantan dan betina.\p"
	.string "Tapi sepertinya tidak ada yang tahu\n"
	.string "apa bedanya.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Pria di sebelah memberiku HM!\p"
	.string "Aku menggunakannya untuk mengajari\n"
	.string "POKéMON-ku cara CUT pohon kurus.$"


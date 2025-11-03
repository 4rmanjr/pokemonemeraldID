PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "Apa warna KARTU TRAINER-mu?\n"
	.string "Punyamu tembaga!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "KOTA PACIFIDLOG mengapung di atas\n"
	.string "koloni CORSOLA.\p"
	.string "Jika Aku memberitahumu itu, apakah kamu\n"
	.string "akan percaya?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "Nenek moyang orang-orang di\n"
	.string "PACIFIDLOG dikatakan lahir di kapal\l"
	.string "dan kemudian hidup serta mati di dalamnya.\p"
	.string "Aku mengerti bahwa mereka hidup seperti itu\n"
	.string "karena mereka mencari\l"
	.string "sesuatu.$"


PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Sistem Penyimpanan POKéMON berbasis\n"
	.string "PC itu…\p"
	.string "Siapa pun yang membuatnya pasti\n"
	.string "sejenis penyihir ilmiah!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Ketika POKéMON-ku memakan\n"
	.string "ORAN BERRY, HP-nya pulih!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Ada banyak jenis POKéMON.\p"
	.string "Semua jenis memiliki kekuatan dan\n"
	.string "kelemahan terhadap jenis lain.\p"
	.string "Tergantung jenis POKéMON-nya,\n"
	.string "pertarungan bisa mudah atau sulit.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Misalnya, TREECKO-mu\n"
	.string "adalah tipe RUMPUT.\p"
	.string "Ia kuat terhadap tipe AIR dan\n"
	.string "TANAH.\p"
	.string "Tapi, ia lemah terhadap POKéMON\n"
	.string "tipe API.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Misalnya, TORCHIC-mu\n"
	.string "adalah tipe API.\p"
	.string "Ia kuat terhadap tipe RUMPUT dan\n"
	.string "SERANGGA.\p"
	.string "Tapi, ia lemah terhadap POKéMON\n"
	.string "tipe AIR.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Misalnya, MUDKIP-mu\n"
	.string "adalah tipe AIR.\p"
	.string "Ia kuat terhadap tipe API.\p"
	.string "Tapi, ia lemah terhadap POKéMON\n"
	.string "tipe RUMPUT dan tipe LISTRIK.$"


FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Dengar, Nak, apa kamu sedang\n"
	.string "mengerjakan POKéDEX?\p"
	.string "Hmm… Pergilah ke SAFARI ZONE.\n"
	.string "Itu saranku.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Apa kamu sudah mencoba\n"
	.string "RECORD CORNER?\p"
	.string "Keren lho. Itu mencampur dan\n"
	.string "mencocokkan rekor para TRAINER.\p"
	.string "Aku tidak tahu cara kerjanya, tapi\n"
	.string "itu keren. Bahkan seru!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wow, kamu punya POKéNAV!\n"
	.string "Sama seperti milikku!\p"
	.string "Apa kamu tahu tentang sistem MATCH\n"
	.string "CALL di POKéNAV?\p"
	.string "Akses itu, dan kamu bisa mengobrol\n"
	.string "dengan TRAINER terdaftar kapan saja.\p"
	.string "Itu juga menunjukkan TRAINER mana\n"
	.string "yang ingin tanding ulang denganmu.\p"
	.string "Benar-benar praktis! Orang-orang\n"
	.string "DEVON memang hebat!$"

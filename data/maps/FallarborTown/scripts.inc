//aistudio
FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Ada sesuatu yang terjadi,\n"
	.string "& aku tidak suka itu!\p"
	.string "Aku melihat karakter mencurigakan\n"
	.string "keluar masuk rumah PROF. COZMO…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Wilayah ini dikenal karena meteor\n"
	.string "sejak zaman dahulu.\p"
	.string "Mereka bilang AIR TERJUN METEOR\n"
	.string "terbentuk karena meteorit yang\l"
	.string "jatuh dulu sekali.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Lihat! Ini AZURILL-ku\n"
	.string "yang berharga!\p"
	.string "Dia licin, halus, & juga empuk!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Apakah kamu sudah menantang\n"
	.string "FLANNERY, PEMIMPIN GYM\l"
	.string "LAVARIDGE?\p"
	.string "Kakek gadis itu terkenal.\n"
	.string "Dia pernah menjadi salah satu\l"
	.string "ELITE FOUR di POKéMON LEAGUE.\p"
	.string "Aku tidak akan terkejut melihat\n"
	.string "FLANNERY menjadi TRAINER hebat\l"
	.string "dengan caranya sendiri.$"

FallarborTown_Text_BattleTentSign:
	.string "TENDA PERTARUNGAN LOKASI\n"
	.string "FALLARBOR\n"
	.string "“Semoga Tim Terhebat Berkumpul!”$"

FallarborTown_Text_TownSign:
	.string "KOTA FALLARBOR\n"
	.string "“Komunitas pertanian dengan\n"
	.string "kebun kecil.”$"

FallarborTown_Text_MoveTutorSign:
	.string "RUMAH GURU GERAKAN\n"
	.string "“Gerakan baru diajarkan ke\n"
	.string "POKéMON.”$"

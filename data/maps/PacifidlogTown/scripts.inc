PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "Laut antara PACIFIDLOG dan\n"
	.string "SLATEPORT memiliki arus yang cepat.\p"
	.string "Jika kamu memutuskan untuk BERSELANCAR,\n"
	.string "kamu bisa tersapu ke tempat lain.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Lihat, bukankah ini rapi?\n"
	.string "Rumah-rumah ini di atas air!\p"
	.string "Aku lahir di sini!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "Pilar Langit?\p"
	.string "…Oh, maksudmu menara tinggi itu\n"
	.string "sedikit lebih jauh.\p"
	.string "Jika kamu bertanya padaku, Aku tidak akan\n"
	.string "memanjatnya. Terlalu menakutkan untuk setinggi itu.\p"
	.string "Hidup di permukaan laut di PACIFIDLOG,\n"
	.string "itu cocok untukku.$"

PacifidlogTown_Text_TownSign:
	.string "KOTA PACIFIDLOG\p"
	.string "“Di mana matahari pagi tersenyum pada\n"
	.string "perairan.”$"


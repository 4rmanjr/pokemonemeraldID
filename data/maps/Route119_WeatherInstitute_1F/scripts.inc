//gemini
Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "BOSS tertarik dengan\n"
	.string "penelitian yang ada di sini,\l"
	.string "jadi dia mengirim kami.\p"
	.string "Kamu berhenti ikut campur!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Sialan…\n"
	.string "Dikalahkan oleh anak kecil…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "BOSS kami tahu segalanya.\p"
	.string "Tapi aku hanya GRUNT. Apa yang\n"
	.string "kutahu tentang apa yang dia\l"
	.string "pikirkan?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hah?\n"
	.string "Apa yang anak kecil lakukan di sini?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hah?\n"
	.string "Aku kalah?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, tidak…\n"
	.string "Aku akan dimarahi karena kalah\l"
	.string "dari anak kecil…\p"
	.string "Seharusnya aku tidur saja di\n"
	.string "ranjang…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Saat aku tidur, semua orang\n"
	.string "naik ke atas!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wow, kamu sangat kuat!\p"
	.string "Aku harap aku bisa menjadi\n"
	.string "POKéMON TRAINER sepertimu!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "PROFESOR suka hujan.\n"
	.string "Itu fakta.\p"
	.string "Tapi jika terus hujan, orang-orang\n"
	.string "akan kesulitan. Itu fakta lain.\p"
	.string "Maka dari itu, PROFESOR sedang\n"
	.string "meneliti apakah hujan bisa\l"
	.string "dimanfaatkan dengan baik.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Di lantai 2 INSTITUT, kami\n"
	.string "mempelajari pola cuaca di\l"
	.string "wilayah HOENN.\p"
	.string "Kami telah memperhatikan kasus\n"
	.string "kekeringan & hujan lebat\l"
	.string "sementara & terisolasi akhir-akhir\n"
	.string "ini…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Halo!\n"
	.string "Kami telah diselamatkan oleh\l"
	.string "tindakanmu!\p"
	.string "Yang tidak kumengerti adalah\n"
	.string "apa sebenarnya yang AQUAS\l"
	.string "lakukan.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Ada ranjang…\n"
	.string "Ayo istirahat.$"

//aistudio
MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Kenangan SKITTY-ku tersayang…\n"
	.string "Mataku berlinang memikirkannya.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Aduh, aduh… Ada lubang di tanah\n"
	.string "di sana-sini.\p"
	.string "Aku tidak sadar & terjatuh dari\n"
	.string "lantai atas.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hei! Kamu mencari POKéMON?\n"
	.string "Kamu mengikutiku! Kamu tidak sopan!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ayieeeeh!\n"
	.string "Maafkan aku, tolong maafkan!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Orang jarang datang ke sini, jadi\n"
	.string "aku pikir ada POKéMON langka.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: Kami di sini karena tantangan.\p"
	.string "Heheh, jika aku menunjukkan betapa\n"
	.string "kerennya aku, dia pasti akan jatuh\l"
	.string "cinta padaku. Aku tahu itu!\p"
	.string "Aku tahu! Aku akan mengalahkanmu &\n"
	.string "menunjukkan padanya betapa kerennya\l"
	.string "aku!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Ups!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: Yah, kami kalah tapi tidak\n"
	.string "apa-apa! Aku di sini di sisimu.\l"
	.string "Kami akan melewati tantangan ini!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Jika kamu ingin melawanku,\n"
	.string "bawa POKéMON lebih banyak.\p"
	.string "Jika tidak, aku tidak akan bisa\n"
	.string "pamer pada gadisku betapa kerennya\l"
	.string "aku!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Aku datang ke sini karena\n"
	.string "tantangan bersama pacarku.\p"
	.string "Ini sangat menakutkan, tapi aku\n"
	.string "bersama pacarku. Tidak apa-apa.\p"
	.string "Aku tahu! Aku akan membuat pacarku\n"
	.string "terlihat keren dengan mengalahkanmu!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Waaaah! Aku takut!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: Kami saling mencintai, jadi\n"
	.string "kami tidak peduli jika kalah!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Jika kamu ingin menantang\n"
	.string "kami, kamu harus membawa setidaknya\l"
	.string "dua POKéMON.\p"
	.string "Pacarku kuat.\n"
	.string "Satu POKéMON saja tidak akan cukup.$"

MtPyre_2F_Text_LeahIntro:
	.string "Kamu pemandangan yang asing…\n"
	.string "Pergi sebelum sesuatu menimpamu!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "Kamu tangguh.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Keluargaku telah menjadi TRAINER\n"
	.string "di sini sejak zaman nenek buyutku…\p"
	.string "Adalah tugasku untuk melindungi\n"
	.string "gunung ini…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyaaaaah!\n"
	.string "Aku ketakutan!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Tidak!\n"
	.string "Aku kehilangan akal!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Aku ketakutan setiap kali melihat\n"
	.string "sesuatu bergerak…\p"
	.string "Seharusnya aku tidak datang ke sini\n"
	.string "untuk berlatih…$"

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
	.string "Kenangan SKITTY kesayanganku…\n"
	.string "Mataku berkaca-kaca memikirkannya.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Aduh, aduh… Ada lubang di\n"
	.string "tanah di sana-sini.\p"
	.string "Aku tidak menyadarinya dan jatuh\n"
	.string "dari lantai atas.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hei! Apakah kamu mencari POKéMON?\n"
	.string "Kamu datang setelahku! Kamu tidak sopan!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ayieeeeh!\n"
	.string "Maafkan Aku, tolong maafkan Aku!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Orang-orang jarang datang ke sini, jadi\n"
	.string "Aku pikir akan ada POKéMON langka.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: Kami di sini karena tantangan.\p"
	.string "Heheh, jika Aku menunjukkan padanya betapa kerennya Aku,\n"
	.string "dia pasti akan jatuh cinta padaku. Aku tahu itu!\p"
	.string "Aku tahu! Aku akan mengalahkanmu dan menunjukkan padanya\n"
	.string "betapa kerennya Aku!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Ups!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: Yah, kami kalah tapi tidak apa-apa!\n"
	.string "Aku di sini di sisimu.\l"
	.string "Kita akan melewati tantangan ini!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Jika kamu ingin melawanku,\n"
	.string "bawalah lebih banyak POKéMON.\p"
	.string "Jika tidak, Aku tidak akan bisa memamerkan\n"
	.string "kepada gadisku betapa kerennya Aku!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Aku datang ke sini karena tantangan dengan\n"
	.string "pacarku.\p"
	.string "Ini benar-benar menakutkan, tapi Aku bersama\n"
	.string "pacarku. Tidak apa-apa.\p"
	.string "Aku tahu! Aku akan membuat pacarku terlihat\n"
	.string "keren dengan mengalahkanmu!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Waaaah! Aku takut!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: Kami saling mencintai, jadi kami tidak\n"
	.string "peduli jika kami kalah!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Jika kamu ingin menantang kami, kamu\n"
	.string "harus membawa setidaknya dua POKéMON.\p"
	.string "Pacarku kuat.\n"
	.string "Satu POKéMON saja tidak akan cukup.$"

MtPyre_2F_Text_LeahIntro:
	.string "Kamu adalah pemandangan yang tidak biasa…\n"
	.string "Pergilah sebelum sesuatu menimpamu!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "Kamu tangguh.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Keluarga kami telah menjadi TRAINER di sini\n"
	.string "sejak zaman nenek buyutku…\p"
	.string "Adalah tugasku untuk melindungi\n"
	.string "gunung ini…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyaaaaah!\n"
	.string "Aku ketakutan!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Tidaaaak!\n"
	.string "Aku kehilangan akal sehatku!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Aku panik setiap kali melihat\n"
	.string "sesuatu bergerak…\p"
	.string "Seharusnya Aku tidak datang ke sini untuk berlatih…$"


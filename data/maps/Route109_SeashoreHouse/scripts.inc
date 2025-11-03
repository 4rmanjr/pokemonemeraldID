//gemini
Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
.if OW_SHOW_ITEM_DESCRIPTIONS != OW_ITEM_DESCRIPTIONS_OFF
	hidemoneybox
	giveitem ITEM_SODA_POP
.else
	giveitem ITEM_SODA_POP
	hidemoneybox
.endif
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Aku pemilik SEASHORE HOUSE. Tapi kamu\n"
	.string "bisa panggil Aku MR. SEA!\p"
	.string "Yang paling Aku suka di atas\n"
	.string "segalanya adalah melihat POKéMON\l"
	.string "bertarung dengan sengit.\p"
	.string "Biarkan Aku lihat hatimu membara!\p"
	.string "Jika kamu bisa mengalahkan semua\n"
	.string "TRAINER di sini, Aku akan menghadiahi\l"
	.string "usahamu.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Tunjukkan padaku beberapa pertarungan\n"
	.string "panas!\p"
	.string "Aku mengelola SEASHORE HOUSE ini\n"
	.string "hanya demi alasan itu!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Kamu sangat membara! Pertarungan tadi\n"
	.string "berkobar! Aku lebih dari sekadar puas\l"
	.string "!\p"
	.string "Sebagai ucapan terima kasih karena\n"
	.string "telah menunjukkan rentetan panasmu,\l"
	.string "Aku ingin kamu mengambil ini.\p"
	.string "Ini setengah lusin botol SODA POP!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, tapi hei, TAS-mu penuh sesak. Aku\n"
	.string "akan menyimpannya untukmu.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Mau beli SODA POP? POKéMON\n"
	.string "menyukainya!\p"
	.string "Hanya¥ 300 sebotol! Beli!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Ini dia!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Kamu tidak punya uang.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Tidak? Sayang sekali.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Jika kamu mencari pertarungan di\n"
	.string "SEASHORE HOUSE, kamu tidak akan\l"
	.string "menemukan TRAINER yang lebih panas\l"
	.string "dariku, kawan!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Itu pertarungan yang panas! Aku bisa\n"
	.string "menerima kekalahan itu, kawan!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Kapan pun Aku di SLATEPORT, Aku\n"
	.string "menikmati pertarungan panas dan SODA\l"
	.string "POP sedingin es!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Pertarungan yang membosankan tidak\n"
	.string "sebanding dengan usaha.\p"
	.string "Pertarungan yang berapi-api adalah\n"
	.string "yang menguatkan TRAINER dan POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Itu panas!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Fiuh, Aku haus sekali. Mungkin Aku\n"
	.string "akan minum SODA POP.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Aku akan menunjukkan padamu betapa\n"
	.string "hebatnya POKéMON milikku, tapi jangan\l"
	.string "menangis!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "… Aku kalah, tapi Aku tidak akan\n"
	.string "menangis…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Jika salah satu POKéMON-ku tahu\n"
	.string "gerakan untuk membawaku menyeberangi\l"
	.string "air di punggungnya, Aku bisa\l"
	.string "menyingkirkan ban dalam ini.$"

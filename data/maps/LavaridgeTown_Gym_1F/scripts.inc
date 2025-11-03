LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hei, apa kabar, calon CHAMPION\n"
	.string "{PLAYER}?\p"
	.string "PEMIMPIN GYM LAVARIDGE, FLANNERY,\n"
	.string "menggunakan POKéMON tipe API.\p"
	.string "Semangatnya pada POKéMON membara\n"
	.string "lebih panas dari gunung berapi.\p"
	.string "Jangan terlalu dekat--kamu akan\n"
	.string "terbakar! Siram dia dengan air lalu\l"
	.string "maju!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! Pertarungan yang sangat panas!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Owowowowow!\n"
	.string "Aduh, panas!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Aku silau karena keringat di mataku…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Terkubur di pasir panas melancarkan\n"
	.string "sirkulasi.\p"
	.string "Ini efektif untuk menyembuhkan nyeri\n"
	.string "sendi.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Aku sedang mencoba menghilangkan\n"
	.string "stres. Jangan datang dan membuatku\l"
	.string "stres!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Kuharap FLANNERY membakarmu\n"
	.string "habis-habisan!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Fiuuh…\p"
	.string "Kalau terlalu lama terkubur di pasir\n"
	.string "panas, kamu akan kelelahan…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Kamu pasti sudah mulai lelah.\n"
	.string "Kamu ingin istirahat di pasir panas,\l"
	.string "kan?\p"
	.string "Tapi kamu harus tahu bahwa menjaga\n"
	.string "tekad adalah kemampuan penting bagi\l"
	.string "semua TRAINER.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Bermain api, dan terbakar…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Keahlianmu nyata…\n"
	.string "Tapi PEMIMPIN kami, FLANNERY, kuat.\p"
	.string "Jika tidak hati-hati, kamu akan\n"
	.string "terbakar parah.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Bisakah POKéMON-mu menahan panas\n"
	.string "200 derajat?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Apinya kurang panas…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Suhu magma adalah 200 derajat.\p"
	.string "POKéMON-mu mengalahkanku, jadi\n"
	.string "mereka seharusnya bisa bertahan di\l"
	.string "magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Um…\n"
	.string "Oke, aku akan bertarung denganmu.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, tapi kamu terlalu kuat.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Aku akan menjadi TRAINER yang cantik\n"
	.string "dan kuat seperti FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Ayo, semangat!\n"
	.string "Mari kita mulai sebelum perasaanku\l"
	.string "mendingin!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Sangat panas, namun hatiku terasa\n"
	.string "dingin membeku…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Dengan semangat bertarung yang\n"
	.string "membara dalam dirimu, kamu mungkin\l"
	.string "punya kesempatan melawan PEMIMPIN kami.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Lihat bagaimana apinya berkobar liar?\n"
	.string "Itu pertanda kemenanganku!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Ada yang tidak beres.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Yah, terus kenapa? Kubilang terus\n"
	.string "kenapa? Aku bisa berjalan di atas\l"
	.string "bara tanpa alas kaki!\p"
	.string "…Jangan pernah berpikir untuk\n"
	.string "mencobanya!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Aku sangat suka gunung, tapi aku\n"
	.string "lebih suka gunung berapi.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Yah, sepertinya aku kalah tanpa\n"
	.string "pernah bisa mengendalikan keadaan.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Aku di sini karena aku mengagumi\n"
	.string "kekuatan FLANNERY.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Selamat datang… Bukan, tunggu.\p"
	.string "TRAINER lemah, senang melihatmu\n"
	.string "berhasil sampai di sini!\p"
	.string "Aku telah dipercayakan dengan…\n"
	.string "Bukan, tunggu.\p"
	.string "Aku FLANNERY, dan aku PEMIMPIN GYM\n"
	.string "di sini!\p"
	.string "Uh…\n"
	.string "Jangan meremehkanku, meskipun aku\l"
	.string "baru sebentar menjadi PEMIMPIN!\p"
	.string "Dengan keahlian warisan kakekku,\n"
	.string "aku akan, uh… menunjukkan jurus\l"
	.string "panas yang telah kami asah di sini!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Kurasa aku terlalu berusaha…\p"
	.string "Aku… Aku baru saja menjadi\n"
	.string "PEMIMPIN GYM.\p"
	.string "Aku terlalu berusaha menjadi orang\n"
	.string "lain.\p"
	.string "Aku harus melakukan segalanya dengan\n"
	.string "caraku sendiri. Jika tidak, POKéMON\l"
	.string "-ku akan bingung.\p"
	.string "Terima kasih telah mengajariku itu.\n"
	.string "Untuk itu, kamu pantas mendapatkan ini.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} mendapatkan HEAT BADGE\n"
	.string "dari FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Jika kamu punya HEAT BADGE, semua\n"
	.string "POKéMON hingga Level 50, bahkan yang\l"
	.string "dari pertukaran, akan mematuhimu\l"
	.string "sepenuhnya.\p"
	.string "Dan, itu memungkinkan POKéMON\n"
	.string "menggunakan HM STRENGTH di luar\l"
	.string "pertarungan.\p"
	.string "Ini adalah tanda terima kasihku.\n"
	.string "Jangan malu-malu mengambilnya!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "TM50 itu berisi OVERHEAT.\p"
	.string "Jurus itu memberikan kerusakan serius\n"
	.string "pada lawan.\p"
	.string "Tapi itu juga menurunkan SP. ATK\n"
	.string "POKéMON yang menggunakannya secara\l"
	.string "drastis. Mungkin tidak cocok untuk\l"
	.string "pertarungan yang lama.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "PEMIMPIN GYM FLANNERY terdaftar\n"
	.string "di POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Kekuatanmu mengingatkanku pada\n"
	.string "seseorang…\p"
	.string "Oh! Aku tahu! Kamu bertarung seperti\n"
	.string "NORMAN, PEMIMPIN GYM PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "GYM POKéMON KOTA LAVARIDGE$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "GYM POKéMON KOTA LAVARIDGE\p"
	.string "TRAINER BERSERTIFIKAT FLANNERY:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Kalah dalam pertarungan\n"
	.string "tidak akan membuatku putus asa.\p"
	.string "Aku cinta POKéMON.\n"
	.string "Aku cinta bertarung.\l"
	.string "Dan… Aku cinta GYM ini!\p"
	.string "Ayo kita bertukar jurus super panas\n"
	.string "di pertarungan lain!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Fiuuh!\n"
	.string "Di ambang letusan!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: Aku kalah, tapi aku\n"
	.string "benar-benar puas.\p"
	.string "Tidak sering aku bisa menikmati\n"
	.string "pertarungan sepanas ini.\p"
	.string "Ayo kita lakukan lagi pertarungan\n"
	.string "seperti ini lain waktu!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Kalah dalam pertarungan\n"
	.string "tidak akan membuatku putus asa.\p"
	.string "Aku cinta POKéMON.\n"
	.string "Aku cinta bertarung.\l"
	.string "Dan… Aku cinta GYM ini!\p"
	.string "Ayo kita bertukar jurus super panas\n"
	.string "di pertarungan lain!\p"
	.string "Oh, tunggu. Apa kamu hanya punya\n"
	.string "satu POKéMON yang bisa bertarung?\p"
	.string "Aku benci mengatakan ini, tapi saat\n"
	.string "kamu menemuiku, bawalah setidaknya\l"
	.string "dua POKéMON.$"

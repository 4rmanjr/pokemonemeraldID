DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Hei, apa kabar, calon JUARA\n"
	.string "{PLAYER}?\p"
	.string "PEMIMPIN GYM DEWFORD, BRAWLY,\n"
	.string "mengendalikan POKéMON tipe\l"
	.string "FIGHTING.\p"
	.string "Melawannya dengan POKéMON tipe\n"
	.string "NORMAL sama saja mencari masalah.\p"
	.string "POKéMON FIGHTING akan menghajar\n"
	.string "POKéMON NORMAL dengan serius, jadi\l"
	.string "hati-hati!\p"
	.string "Yang lebih parah, GYM ini gelap\n"
	.string "seperti dasar lautan.\p"
	.string "Tapi tempat ini akan lebih terang\n"
	.string "setelah Kamu mengalahkan para\l"
	.string "TRAINER yang menghalangi.\p"
	.string "Hei, oke, lakukanlah!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Whoah! Tempat ini jadi terlalu\n"
	.string "terang!\p"
	.string "Masa depanmu juga cerah!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Kekuatan adalah kebenasan! Ayo!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Kekuatan tak cukup…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Keahlianmu mengatasi kekuatanku!\n"
	.string "Teknikmu patut dipuji!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "BRAWLY tak perlu terlibat!\p"
	.string "Aku akan menghancurkanmu!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Tapi… Bagaimana? Bagaimana aku bisa\n"
	.string "kalah semudah ini?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Aku tak akan menyia-nyiakan\n"
	.string "kekalahan ini. Aku akan\l"
	.string "menjadikannya motivasi untuk\l"
	.string "berlatih!\p"
	.string "Suatu hari aku akan menjadi\n"
	.string "PEMIMPIN GYM…\p"
	.string "Tidak, aku akan menjadi JUARA LIGA\n"
	.string "POKéMON!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Jangan berani-beraninya\n"
	.string "mengabaikanku! Bukan salahku kalau\l"
	.string "Kamu menangis!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaaaaaah! Aku kalah!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Aku bertarung dalam gelap untuk\n"
	.string "membuat hatiku lebih kuat.\p"
	.string "Tapi karena sangat gelap, aku tak\n"
	.string "pernah bisa melihat wajah BRAWLY…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu… Apa Kamu tersandung-sandung\n"
	.string "dalam gelap?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, Kamu… Aku tidak mau mengenalmu!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Kamu pantas tetap tersesat dan\n"
	.string "berakhir kembali di pintu masuk!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Aku akan menunjukkan padamu\n"
	.string "semangat seorang pelaut!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Bagaimana ini bisa terjadi? Bukan\n"
	.string "gayaku kalah seperti ini!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Oh, iya! Kamu layak bertemu\n"
	.string "PEMIMPIN GYM kami.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Jika Kamu ingin lewat, Kamu harus\n"
	.string "melaluiku!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr! Kekuatan yang jauh\n"
	.string "melampaui!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Kamu menang! Kejar LENCANA itu!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Aku BRAWLY! PEMIMPIN GYM DEWFORD!\p"
	.string "Aku telah diaduk-aduk dalam ombak\n"
	.string "kasar di daerah ini, dan Aku telah\l"
	.string "tumbuh kuat di gua yang gelap\l"
	.string "gulita!\p"
	.string "Jadi, Kamu ingin menantangku? Biar\n"
	.string "kulihat kemampuanmu!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Whoah, wow! Kamu membuat cipratan\n"
	.string "yang jauh lebih besar dari yang Aku\l"
	.string "duga!\p"
	.string "Kamu menenggelamkanku!\p"
	.string "Oke, Kamu mengalahkanku. Ambil\n"
	.string "LENCANA GYM ini!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} menerima KNUCKLE BADGE\n"
	.string "dari BRAWLY.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "KNUCKLE BADGE membuat semua POKéMON\n"
	.string "hingga Level 30, bahkan yang Kamu\l"
	.string "dapatkan dari pertukaran, patuh\l"
	.string "tanpa pertanyaan.\p"
	.string "Dan, Kamu akan dapat menggunakan\n"
	.string "jurus HM FLASH di luar pertarungan.\p"
	.string "Jika Kamu mau, gunakan juga\n"
	.string "TECHNICAL MACHINE ini.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "TM08 itu berisi BULK UP.\p"
	.string "Itu adalah jurus yang menaikkan\n"
	.string "stat SERANGAN dan PERTAHANAN.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Mendaftarkan PEMIMPIN GYM BRAWLY di\n"
	.string "POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Aku bisa melihat bakatmu suatu hari\n"
	.string "akan menjadi gelombang raksasa yang\l"
	.string "menyebabkan badai kekagetan di\l"
	.string "antara para TRAINER!$"

DewfordTown_Gym_Text_GymStatue:
	.string "GYM POKéMON KOTA DEWFORD$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "GYM POKéMON KOTA DEWFORD\p"
	.string "TRAINER BERSERTIFIKASI BRAWLY:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: Gelombang mungkin surut,\n"
	.string "tetapi selalu kembali ke pantai.\p"
	.string "Bakat sebesar gelombang raksasa\n"
	.string "sepertimu… Aku tahu Kamu akan\l"
	.string "kembali!\p"
	.string "Tunjukkan padaku seberapa tinggi\n"
	.string "Kamu telah berkembang!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Wow! Tenggelam lagi!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: Pertarungan itu luas dan\n"
	.string "dalam. Kamu tak bisa melihat\l"
	.string "dasarnya. Itu sama seperti lautan\l"
	.string "HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: Gelombang mungkin surut,\n"
	.string "tetapi selalu kembali ke pantai.\p"
	.string "Bakat sebesar gelombang raksasa\n"
	.string "sepertimu… Aku tahu Kamu akan\l"
	.string "kembali!\p"
	.string "Oh? Kamu hanya punya satu POKéMON\n"
	.string "yang bisa bertarung.\p"
	.string "Maaf, tapi Aku ingin Kamu kembali\n"
	.string "dengan setidaknya dua POKéMON.$"

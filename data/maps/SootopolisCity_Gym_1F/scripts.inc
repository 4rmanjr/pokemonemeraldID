//gemini
SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! Bagaimana kabarmu, calon JUARA\n"
	.string "{PLAYER}?\p"
	.string "PEMIMPIN GYM SOOTOPOLIS, JUAN,\n"
	.string "adalah master POKéMON tipe AIR.\p"
	.string "Dan, untuk mencapai JUAN, lantai es\n"
	.string "akan menghambat kemajuanmu…\p"
	.string "Dengar, Aku minta maaf, tapi hanya\n"
	.string "itu saran yang Aku miliki untukmu.\p"
	.string "Sisa perjalanan, Kamu harus\n"
	.string "berjuang sendiri!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! Kamu bahkan telah mengalahkan\n"
	.string "JUAN, yang konon terbaik di seluruh\l"
	.string "HOENN!\p"
	.string "Oke! Cek KARTU PELATIHmu.\p"
	.string "Jika Kamu sudah mendapatkan semua\n"
	.string "LENCANA, Kamu siap untuk tantangan\l"
	.string "LIGA POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Boleh Aku bertanya. Tahukah Kamu?\n"
	.string "Ah, Aku tidak seharusnya malu-malu.\p"
	.string "Akulah yang mengajarkan WALLACE\n"
	.string "segala sesuatu yang perlu diketahui\l"
	.string "tentang POKéMON.\p"
	.string "Dulu, Aku telah melepaskan posisiku\n"
	.string "sebagai PEMIMPIN GYM.\p"
	.string "Di tempatku, Aku telah\n"
	.string "mempercayakan GYM kepada WALLACE.\p"
	.string "Namun, ada alasan kuat yang muncul\n"
	.string "bagi Aku untuk kembali.\p"
	.string "Ah, tapi cukup bicara. Mari kita\n"
	.string "mulai pertarungan kita, maukah\l"
	.string "Kamu?\p"
	.string "Kumohon, Kamu akan menyaksikan\n"
	.string "kepiawaian kami.\p"
	.string "Sebuah ilusi agung air yang dipahat\n"
	.string "oleh POKéMON dan Aku sendiri!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, luar biasa! Baiklah, Kamu\n"
	.string "adalah pemenangnya.\p"
	.string "Dari dirimu, Aku merasakan kilau\n"
	.string "cemerlang keahlian yang akan\l"
	.string "mengatasi segalanya.\p"
	.string "Namun, dibandingkan dengan Aku atau\n"
	.string "bahkan WALLACE, Kamu kurang dalam\l"
	.string "keanggunan.\p"
	.string "Mungkin Aku harus meminjamkan\n"
	.string "setelan pakaian-Ku kepadamu?\p"
	.string "… … … … … … … … … … … …\p"
	.string "Hahaha, Aku hanya bercanda!\p"
	.string "Daripada pakaian-Ku, Aku akan\n"
	.string "menghadiahimu ini, RAIN BADGE!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} menerima RAIN BADGE dari\n"
	.string "JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Memiliki RAIN BADGE akan menjamin\n"
	.string "Kamu mendapatkan kepatuhan penuh\l"
	.string "dari semua POKéMON-mu atas setiap\l"
	.string "perintahmu.\p"
	.string "RAIN BADGE juga memungkinkan\n"
	.string "penggunaan jurus HM WATERFALL untuk\l"
	.string "mendaki dinding air terjun.\p"
	.string "Dan, agar Kamu tidak pernah\n"
	.string "melupakan pertarungan yang kita\l"
	.string "bagikan, ambil ini…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "TECHNICAL MACHINE yang Aku berikan\n"
	.string "kepadamu berisi WATER PULSE.\p"
	.string "Saat digunakan, terkadang akan\n"
	.string "membuat target bingung dengan\l"
	.string "gelombang ultrasonik.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Mendaftarkan PEMIMPIN GYM JUAN di\n"
	.string "POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Para TRAINER yang telah\n"
	.string "mengumpulkan semua BADGE GYM HOENN\l"
	.string "harus menuju ke tujuan akhir.\p"
	.string "POKéMON LEAGUE.\p"
	.string "Perjalanan ke ujung timur HOENN, ke\n"
	.string "pulau EVER GRANDE.\p"
	.string "Di sana, Kamu akan menemukan\n"
	.string "POKéMON LEAGUE.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Hanya tersisa satu BADGE untuk\n"
	.string "didapatkan di HOENN.\p"
	.string "Jika Kamu ingin menantang POKéMON\n"
	.string "LEAGUE, Kamu harus mendapatkan\l"
	.string "BADGE terakhir dari GYM di FORTREE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "GYM POKéMON KOTA SOOTOPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "GYM POKéMON KOTA SOOTOPOLIS\p"
	.string "TRAINER TERSERTIFIKASI JUAN:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, GYM ini telah kembali ke\n"
	.string "keadaan tenangnya yang biasa…\p"
	.string "Namun topan muda kita telah kembali\n"
	.string "untuk menguji kita lagi!\p"
	.string "Tentu saja, temanku!\p"
	.string "Aku akan senang menari denganmu\n"
	.string "sesering yang Kamu inginkan!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, Kamu adalah pemenangnya!\n"
	.string "Kamu telah mengalahkan Aku lagi!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Jika Aku memintamu menjadi\n"
	.string "muridku, Kamu akan menolak, Aku\l"
	.string "yakin.\p"
	.string "Aku ingin memberikan jas-Ku\n"
	.string "kepadamu.\p"
	.string "Tetapi sekali lagi, Kamu akan\n"
	.string "menolak. Aku membayangkan demikian.\p"
	.string "Dan itu, temanku, adalah tanda\n"
	.string "tertentu dari kemuliaan!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, GYM ini telah kembali ke\n"
	.string "keadaan tenangnya yang biasa…\p"
	.string "Namun topan muda kita telah kembali\n"
	.string "untuk menguji kita lagi!\p"
	.string "Tentu saja, temanku! Aku akan\n"
	.string "senang menari denganmu…\p"
	.string "Ah, tidak, tidak, tidak. Kamu hanya\n"
	.string "membawa satu POKéMON.\p"
	.string "Aku ingin Kamu kembali dengan dua,\n"
	.string "mungkin lebih, POKéMON, kumohon.$"

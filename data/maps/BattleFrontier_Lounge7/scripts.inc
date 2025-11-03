BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_COUNTER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SNORE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MUD_SLAP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SWIFT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ENDURE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_PSYCH_UP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "Mungkin sekarang tidak terlihat, tapi\n"
	.string "dulu aku seorang TRAINER yang tangguh.\p"
	.string "Aku punya reputasi sebagai BEAUTY\n"
	.string "tertangguh, lho!\p"
	.string "… … … … … …\p"
	.string "Kenapa?\n"
	.string "Kamu tidak percaya padaku.\p"
	.string "Aku tidak seperti wanita pembual di\n"
	.string "sebelah sana. Aku benar-benar berbakat!\p"
	.string "Akan kubuktikan padamu.\n"
	.string "Aku bisa mengajari POKéMON-mu jurus\l"
	.string "spesial yang imut.\p"
	.string "Tapi pelajaranku tidak gratis.\n"
	.string "Bagaimana kalau membayar jurus yang\l"
	.string "kuajarkan dengan sedikit Battle Point?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Kamu kembali untuk belajar jurus\n"
	.string "POKéMON spesial yang imut?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Baik, baik, lihat sini!\n"
	.string "Jurus mana yang harus kuajarkan?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "Jurus {STR_VAR_1}, ya?\n"
	.string "Harganya {STR_VAR_2} Battle Point, oke?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Baik, baik, sekarang pilih POKéMON\n"
	.string "yang akan kuajari jurus itu.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Apa-apaan…\n"
	.string "Battle Point-mu tidak cukup!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Sekarang kamu lihat betapa hebatnya aku?\n"
	.string "Battle Point-nya kuambil, terima kasih!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Apa katamu?\n"
	.string "Kamu tidak mau…\p"
	.string "Kalau mau lihat sehebat apa aku,\n"
	.string "datang saja kapan pun!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "Aku tahu sekarang sulit dilihat, tapi\n"
	.string "dulu aku TRAINER yang fantastis.\p"
	.string "Aku punya reputasi sebagai SWIMMER\n"
	.string "paling tak terkalahkan, lho!\p"
	.string "… … … … … …\p"
	.string "Ada apa?\n"
	.string "Kamu tidak percaya padaku.\p"
	.string "Aku tidak seperti wanita konyol di\n"
	.string "sebelah sana. Aku berpengalaman!\p"
	.string "Aku bisa buktikan padamu.\n"
	.string "Aku bisa mengajari POKéMON-mu jurus\l"
	.string "keras namun cantik.\p"
	.string "Tapi pelajaranku tidak gratis.\n"
	.string "Bagaimana kalau membayar jurus yang\l"
	.string "kuajarkan dengan sedikit Battle Point?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Kamu datang untuk belajar jurus\n"
	.string "POKéMON yang keras namun cantik?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Para nona itu, cara mereka saling\n"
	.string "menjelekkan, kamu mungkin berpikir\l"
	.string "mereka tidak akur.\p"
	.string "Tapi kalau itu benar, mereka tidak akan\n"

	.string "tinggal bersama di sini, kan?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Waktu aku masih kecil, para nona itu\n"
	.string "kuat dan cantik.\p"
	.string "Mereka adalah idola di antara kami\n"
	.string "para TRAINER.\p"
	.string "Bahkan sekarang, usia tidak menumpulkan\n"
	.string "kemampuan mereka.\p"
	.string "Faktanya, jurus POKéMON mereka\n"
	.string "telah tumbuh lebih hebat.\p"
	.string "Tapi… Entah kenapa, aku tidak bisa\n"
	.string "menahan perasaan ini…\p"
	.string "Waktu begitu kejam…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Memulihkan hingga\n"
	.string "setengah HP\n"
	.string "maksimum pengguna.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Memberi damage\n"
	.string "setara dengan\n"
	.string "level pengguna.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Pulihkan setengah\n"
	.string "damage dari musuh\n"
	.string "yang tertidur.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Pukulan kuat yang\n"
	.string "dilontarkan dengan\n"
	.string "kekuatan luar biasa.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Tendangan sangat\n"
	.string "kuat dengan\n"
	.string "kekuatan besar.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Serangan seluruh\n"
	.string "tubuh yang dapat\n"
	.string "menyebabkan kelumpuhan.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Batu-batu besar\n"
	.string "dilemparkan. Dapat\n"
	.string "membuat musuh gentar.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Membalas serangan\n"
	.string "fisik apa pun dengan\n"
	.string "kekuatan ganda.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Kejutan listrik\n"
	.string "lemah yang melumpuhkan\n"
	.string "musuh.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Tarian pertarungan\n"
	.string "yang meningkatkan\n"
	.string "ATTACK secara tajam.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Menggulung untuk\n"
	.string "sembunyikan titik\n"
	.string "lemah & naikkan DEFENSE.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Serangan keras\n"
	.string "yang hanya bisa\n"
	.string "digunakan saat tidur.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Melempar lumpur ke\n"
	.string "wajah musuh untuk\n"
	.string "menurunkan akurasi.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Menyemprotkan sinar\n"
	.string "berbentuk bintang\n"
	.string "yang tak pernah meleset.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Serangan dingin\n"
	.string "yang menurunkan\n"
	.string "SPEED musuh.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Menahan serangan\n"
	.string "apa pun selama 1 giliran,\n"
	.string "menyisakan 1 HP.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Menyalin efek musuh\n"
	.string "dan memberikannya\n"
	.string "kepada pengguna.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Pukulan es\n"
	.string "yang dapat\n"
	.string "membekukan musuh.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Pukulan listrik\n"
	.string "yang dapat\n"
	.string "melumpuhkan musuh.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Pukulan api\n"
	.string "yang dapat\n"
	.string "membakar musuh.$"

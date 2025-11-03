MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
	.string "Aku kagum kamu tahu di mana\l"
	.string "menemukanku.\p"
	.string "Apakah kamu, uh… mungkin menganggapku\n"
	.string "hanya seorang maniak batu?\p"
	.string "Tidak, itu tidak mungkin benar.\p"
	.string "Kita bertarung bersama di SOOTOPOLIS\n"
	.string "SPACE CENTER.\p"
	.string "Kamu seharusnya tahu betul seberapa\n"
	.string "hebatnya aku.\p"
	.string "Baiklah, {PLAYER}{KUN}, jika kamu akan\n"
	.string "memberikan tantangan serius,\l"
	.string "bersiaplah untuk yang terburuk!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Kamu…\n"
	.string "Aku tidak tahu kamu menjadi sekuat…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Kalau dipikir-pikir, sejak\n"
	.string "jalan kita pertama kali bertemu di\l"
	.string "GRANITE CAVE di DEWFORD, aku punya\l"
	.string "perasaan ini.\p"
	.string "Aku pikir kamu pada akhirnya akan\n"
	.string "menjadi CHAMPION.\p"
	.string "Prediksiku biasanya menjadi kenyataan.\p"
	.string "Dan ke mana kamu akan pergi dari sini?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, bahkan aku tidak bisa\n"
	.string "memberitahumu itu.$"


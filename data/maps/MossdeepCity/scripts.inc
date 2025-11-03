MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Aku dapat ini dari STEVEN, tapi aku\n"
	.string "tidak tahu apa gunanya.\p"
	.string "Sepertinya ini disebut KING'S ROCK.\n"
	.string "Kamu mau?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Kenapa kamu menginginkannya?\n"
	.string "Kamu aneh.\p"
	.string "Kamu boleh menyimpannya, tapi\n"
	.string "rahasiakan dari STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "Rumah STEVEN ada di sebelah sana!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Ya, kamu juga berpikir begitu! Apa yang\n"
	.string "harus dilakukan dengan batu aneh ini?$"

MossdeepCity_Text_WailmerWatching:
	.string "Di sekitar MOSSDEEP, kamu bisa\n"
	.string "melihat WAILMER liar.\p"
	.string "Itu disebut, uh…\n"
	.string "Apa ya namanya…\p"
	.string "WAI, WAI, WAI…\p"
	.string "Menonton WAILMER!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "SPACE CENTER di pulau ini telah\n"
	.string "meluncurkan roket-roket besar.\p"
	.string "Ada semacam keributan karena surat\n"
	.string "yang mereka terima baru-baru ini.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "SPACE CENTER di pulau ini telah\n"
	.string "meluncurkan roket-roket besar.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Aku dengar dari teman SAILOR bahwa\n"
	.string "TIM AQUA mendirikan markas di LILYCOVE.\p"
	.string "Aku juga dengar ada seseorang yang\n"
	.string "datang dan mengalahkan mereka!\p"
	.string "Tapi MOSSDEEP di sini telah menjadi\n"
	.string "target oleh TIM MAGMA itu.\p"
	.string "Jika kamu ingin tahu apa yang mereka\n"
	.string "rencanakan, kunjungi SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Aku seorang SAILOR, jadi laut jelas\n"
	.string "lebih penting bagiku.\p"
	.string "Tapi tahu tidak? Saat aku kembali ke\n"
	.string "darat setelah pelayaran panjang, aku\l"
	.string "merasa lega!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Bukankah akan menyenangkan?\p"
	.string "Jika seluruh dunia tertutup oleh\n"
	.string "tanaman dan bunga seperti pulau ini?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Semua kehidupan membutuhkan laut untuk\n"
	.string "hidup, meskipun rumahnya di darat.\p"
	.string "Kehidupan, setelah selesai, menjadi\n"
	.string "tanah dan kembali ke daratan.\p"
	.string "Dan laut selalu terhubung dengan\n"
	.string "daratan.\p"
	.string "Ya, seperti garis pantai di sini.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Perjalanan dengan kapal baik-baik saja.\p"
	.string "Tapi menyeberangi laut dengan POKéMON\n"
	.string "menggunakan SURF…\p"
	.string "Nah, itu perjalanan yang mengasyikkan!\n"
	.string "Tidakkah kamu setuju, anak muda?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Batu ini punya arti khusus bagi\n"
	.string "orang-orang di SPACE CENTER.\p"
	.string "Mereka meletakkannya di sini sebagai\n"
	.string "harapan agar roket mereka terbang\l"
	.string "dengan aman.\p"
	.string "Saat kamu membuat permohonan, apa yang\n"
	.string "kamu gunakan? Apakah kamu berharap\l"
	.string "pada bintang?\p"
	.string "Aku menggunakan wish tag untuk\n"
	.string "mewujudkannya. Itulah yang aku lakukan.$"
	
MossdeepCity_Text_ItsAWhiteRock:
	.string "Ini adalah batu putih.$"

MossdeepCity_Text_GymSign:
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“Kombinasi mistis!”$"

MossdeepCity_Text_CitySign:
	.string "MOSSDEEP CITY\n"
	.string "“Slogan kami: Sayangi POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“Tempat terdekat ke luar angkasa.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, apa kabar?\n"
	.string "Aku baik-baik saja!\p"
	.string "Aku dengar GYM LEADER MOSSDEEP cukup\n"
	.string "kuat, jadi aku memutuskan untuk datang\l"
	.string "melihatnya sendiri.\p"
	.string "Tapi ada yang aneh dengan kota ini.\p"
	.string "Orang-orang membicarakan tentang surat\n"
	.string "peringatan dan SPACE CENTER…\p"
	.string "Tapi kurasa itu bukan urusanku.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… Rasanya menyenangkan membiarkan\n"
	.string "ombak membasahi kakiku…\p"
	.string "Bicara soal ombak, kamu tahu kota\n"
	.string "pulau SOOTOPOLIS?\p"
	.string "Sepertinya GYM di sana punya LEADER\n"
	.string "baru.\p"
	.string "Orang-orang bilang LEADER baru itu\n"
	.string "pernah menjadi mentor WALLACE.$"

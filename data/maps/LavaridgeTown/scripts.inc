LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "MAY: {PLAYER}{KUN}! Lama tidak bertemu!\p"
	.string "Oh? Saat aku mengunjungi pemandian\n"
	.string "air panas, kamu mendapatkan LENCANA\l"
	.string "GYM LAVARIDGE.\p"
	.string "Kamu pasti sudah mengumpulkan\n"
	.string "POKéMON yang bagus…\l"
	.string "Tidak, aku yakin kamu membesarkannya.\p"
	.string "Kurasa tidak apa-apa jika kamu\n"
	.string "memiliki ini.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "MAY: Dengan GO-GOGGLES itu, kamu\n"
	.string "tidak akan kesulitan melewati gurun\l"
	.string "dekat ROUTE 111.\p"
	.string "Tapi, wow, {PLAYER}{KUN}…\n"
	.string "Menantang GYM…\p"
	.string "Kamu berusaha keras karena tidak mau\n"
	.string "kalah dariku, aku yakin!\p"
	.string "{PLAYER}{KUN}, kurasa aku harus\n"
	.string "menantang ayahmu di GYM PETALBURG.\p"
	.string "Sampai jumpa lagi!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRENDAN: {PLAYER}, hei, sudah lama ya.\n"
	.string "Apa kabar?\p"
	.string "Hmm…\n"
	.string "Koleksi LENCANA yang lumayan.\p"
	.string "Baiklah kalau begitu.\n"
	.string "Kamu boleh ambil ini.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN: Bawa itu jika kamu\n"
	.string "berencana pergi ke gurun dekat\l"
	.string "ROUTE 111.\p"
	.string "Seharusnya ada beberapa POKéMON yang\n"
	.string "hanya tinggal di gurun.\l"
	.string "Kamu bisa mencarinya di sana.\p"
	.string "Sedangkan aku…\n"
	.string "Aku sedang mempertimbangkan untuk\l"
	.string "menantang NORMAN, PEMIMPIN GYM\l"
	.string "PETALBURG.\p"
	.string "Tidak sepertimu, {PLAYER}, ayahmu\n"
	.string "kelihatannya sangat tangguh.\p"
	.string "Sampai jumpa!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Aku punya TELUR di sini.\p"
	.string "Aku berharap bisa menetaskannya\n"
	.string "dengan menguburnya di pasir panas\l"
	.string "dekat pemandian air panas.\p"
	.string "Tapi sepertinya itu tidak cukup…\p"
	.string "Kudengar akan lebih baik jika\n"
	.string "disimpan bersama POKéMON dan\l"
	.string "dibawa-bawa.\p"
	.string "Kamu seorang TRAINER, kan?\n"
	.string "Dan POKéMON-mu memancarkan\l"
	.string "vitalitas.\p"
	.string "Jadi, bagaimana?\n"
	.string "Maukah kamu mengambil TELUR ini\l"
	.string "untuk ditetaskan?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Bagus! Kuharap kamu akan sering\n"
	.string "berjalan dengan TELUR ini!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} mendapatkan TELUR.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? POKéMON-mu terlalu banyak.\n"
	.string "Tidak ada tempat untuk TELUR ini…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Terserah kamu, kalau begitu…\p"
	.string "Jika kamu berubah pikiran tentang\n"
	.string "menetaskan TELUR ini, aku akan ada\l"
	.string "di sini.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Kadang-kadang, sebuah TELUR akan\n"
	.string "ditemukan di POKéMON DAY CARE.\p"
	.string "Atau setidaknya begitulah rumornya.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Kami mengambil air panas sebanyak\n"
	.string "yang kami butuhkan, namun sumbernya\l"
	.string "tidak pernah kering.\p"
	.string "Ajaib, bukan?\p"
	.string "Pemandian air panas ini muncul di\n"
	.string "dekat gunung berapi aktif. Aliran air\l"
	.string "di bawah tanah dipanaskan oleh magma\l"
	.string "hingga muncul ke permukaan sebagai\l"
	.string "mata air panas.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Terkubur di pasir panas ini…\n"
	.string "Huh…\p"
	.string "Sangat hangat dan nikmat…\p"
	.string "Eh? Gyaah! Aduh!\p"
	.string "Seekor POKéMON menggigit bokongku!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, kamu suka pemandian air panas,\n"
	.string "ya?\p"
	.string "Mengejutkan untuk anak semudamu.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Aku mandi di pemandian air panas\n"
	.string "setiap hari.\p"
	.string "Aku ingin menjadi PEMIMPIN GYM yang\n"
	.string "cantik dan kuat seperti FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Jika orang memasukkan POKéMON ke\n"
	.string "pemandian air panas, itu bisa jadi\l"
	.string "sangat aneh.\p"
	.string "Bisa jadi pemandian listrik, atau\n"
	.string "pemandian busa, atau bahkan\l"
	.string "pemandian lava…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Katanya pemandian air panas ini bagus\n"
	.string "untuk menenangkan ketegangan saraf,\l"
	.string "meredakan nyeri otot, menyelesaikan\l"
	.string "masalah asmara, dan menarik uang…$"

LavaridgeTown_Text_TownSign:
	.string "KOTA LAVARIDGE\p"
	.string "“Pemandian Air Panas POKéMON CENTER\n"
	.string "Tempat yang sangat baik untuk\l"
	.string "bersantai!”$"

LavaridgeTown_Text_GymSign:
	.string "GYM POKéMON KOTA LAVARIDGE\n"
	.string "PEMIMPIN: FLANNERY\l"
	.string "“Seseorang dengan semangat yang\l"
	.string "membara!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "TOKO HERBAL POKéMON\n"
	.string "“Rasa pahit--obat manjur!”$"

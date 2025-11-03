//gemini
SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_PARTS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Ya? Jika Kamu mencari STERN, itu\n"
	.string "adalah Aku.\p"
	.string "Ah! Itu pasti suku cadang yang Aku\n"
	.string "pesan dari MR. STONE dari DEVON.\p"
	.string "Terima kasih! Bagus sekali! Kami\n"
	.string "bisa mempersiapkan ekspedisi kami\l"
	.string "sekarang.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hehehe, tunggu! Kami akan mengambil\n"
	.string "suku cadang itu!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "KAPT. STERN: A-apa? Siapa kalian?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Kami TEAM AQUA!\p"
	.string "BOSS kami menginginkan suku cadang\n"
	.string "itu! Tutup mulutmu dan serahkan!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Awaaaah! Seorang anak\n"
	.string "mengalahkanku!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Ya ampun, sungguh bencana... BOSS\n"
	.string "pasti akan sangat marah...$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Hmph, pecundang cengeng! Biar Aku\n"
	.string "yang urus ini!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Apa?! Aku kalah juga!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Sekarang bagaimana? Jika kita tidak\n"
	.string "mendapatkan suku cadang itu, kita\l"
	.string "akan celaka!\p"
	.string "Arrgh, Aku tidak menyangka akan\n"
	.string "diganggu oleh anak yang suka ikut\l"
	.string "campur!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Aku datang untuk melihat mengapa\n"
	.string "kalian begitu lama mengambil suku\l"
	.string "cadang, dan kalian para bodoh\l"
	.string "dihalangi oleh seorang anak kecil\l"
	.string "saja?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Kami adalah TEAM AQUA, dan kami\n"
	.string "mencintai laut!\p"
	.string "Dan Aku adalah pemimpin TEAM AQUA,\n"
	.string "ARCHIE!\p"
	.string "Apa yang membuatmu mengganggu kami?\p"
	.string "...Tidak! Mustahil! Kamu bukan\n"
	.string "salah satu dari TEAM MAGMA?\p"
	.string "Tunggu, tidak mungkin. Pakaianmu\n"
	.string "tidak cocok.\p"
	.string "… … … … … … … … … … … …\p"
	.string "POKéMON, manusia... Semua kehidupan\n"
	.string "bergantung pada laut.\p"
	.string "Jadi, TEAM AQUA berdedikasi untuk\n"
	.string "perluasan laut.\p"
	.string "Tidakkah Kamu setuju? Apa yang kami\n"
	.string "lakukan adalah usaha yang luar\l"
	.string "biasa.\p"
	.string "Ah, baiklah... Kamu masih terlalu\n"
	.string "muda untuk memahami tujuan mulia\l"
	.string "kami.\p"
	.string "Tapi, Aku peringatkan, jangan\n"
	.string "pernah berpikir untuk mengganggu\l"
	.string "rencana kami lagi.\p"
	.string "Konsekuensinya akan merugikanmu\n"
	.string "sangat mahal!\p"
	.string "Dan jangan pernah lupakan itu!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "KAPT. STERN: Kamu... Ah, oke, Kamu\n"
	.string "{PLAYER}{KUN}...\p"
	.string "Bagaimanapun, itu situasi yang\n"
	.string "menegangkan! Terima kasih telah\l"
	.string "menyelamatkan kami!\p"
	.string "Oh, ya, Aku hampir lupa bahwa Kamu\n"
	.string "bahkan membawa suku cadang dari\l"
	.string "DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "KAPT. STERN: Aduh! Tidak ada waktu\n"
	.string "untuk dihabiskan!\p"
	.string "Kami harus segera berangkat untuk\n"
	.string "ekspedisi dasar laut kami.\p"
	.string "Terima kasih lagi, tapi sekarang\n"
	.string "Aku harus pergi!\p"
	.string "Namun, jangan ragu untuk\n"
	.string "berkeliling dan melihat fasilitas\l"
	.string "kami.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Aku melihat model kapal di sini.\p"
	.string "Itu mengingatkanku pada KAPAL\n"
	.string "TERLANTAR di dekat KOTA DEWFORD...$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Jangan berani-berani berlarian di\n"
	.string "dalam MUSEUM!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Wow, kapal selamnya luar biasa! Aku\n"
	.string "ingin ikut naik!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“SAMPEL KUALITAS AIR 1,” tertulis\n"
	.string "pada label.\p"
	.string "Laut semuanya terhubung, tetapi\n"
	.string "airnya tampak berbeda menurut\l"
	.string "wilayah.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“SAMPEL KUALITAS AIR 2,” tertulis\n"
	.string "pada label.\p"
	.string "Apakah kadar garam air laut juga\n"
	.string "berbeda menurut wilayah?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Sebuah bola karet mengembang dan\n"
	.string "menyusut.\p"
	.string "“Di laut, berat air itu sendiri\n"
	.string "memberikan tekanan.\p"
	.string "“Di perairan dangkal, tekanannya\n"
	.string "tidak terlalu berat.\p"
	.string "“Namun, di perairan yang sangat\n"
	.string "dalam, tekanan dapat mencapai\l"
	.string "bahkan puluhan ribu ton pada area\l"
	.string "kecil."

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MODEL WILAYAH HOENN” Itu adalah\n"
	.string "diorama miniatur wilayah HOENN.\p"
	.string "Di mana KOTA LITTLEROOT di sini?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "Ini adalah tampilan tentang aliran\n"
	.string "air laut.\p"
	.string "“Di dekat dasar laut, air mengalir\n"
	.string "karena perbedaan faktor-faktor\l"
	.string "seperti suhu dan salinitas."

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "Ini adalah tampilan tentang aliran\n"
	.string "air laut.\p"
	.string "“Menuju permukaan, air laut\n"
	.string "mengalir sebagai arus yang didorong\l"
	.string "oleh angin."

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“KAPAL FERRY S.S. TIDAL”\p"
	.string "“Replika skala kapal yang sedang\n"
	.string "dibangun di GALANGAN KAPAL STERN."

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“KAPAL SELAM EXPLORER 1”\p"
	.string "“Replika kapal selam eksplorasi\n"
	.string "dasar laut berkinerja tinggi."

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“KAPAL SELAM MINI”\p"
	.string "“Replika pod ringkas tanpa awak\n"
	.string "untuk eksplorasi dasar laut."

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE”\p"
	.string "“Replika kapal pesiar mewah yang\n"
	.string "mengelilingi dunia."

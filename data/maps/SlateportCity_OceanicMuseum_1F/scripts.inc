//gemini
SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Selamat datang di MUSEUM LAUT.\p"
	.string "Biaya masuknya ¥50. Apakah Kamu mau\n"
	.string "masuk?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Silakan nikmati waktunya.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh? Maaf, sepertinya uang Kamu\n"
	.string "tidak cukup.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh? Kamu dengan kelompok yang masuk\n"
	.string "lebih awal itu?\p"
	.string "Hanya Kamu yang terlambat.\n"
	.string "Sebaiknya Kamu segera menyusul\l"
	.string "mereka!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Kami, TIM AQUA, ada demi kebaikan\n"
	.string "semua!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Kami disuruh berkumpul di sini,\n"
	.string "jadi kami lakukan, tapi…\p"
	.string "BOSS kami, intinya, tidak ada di\n"
	.string "sini.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Jika Aku mencuri barang di sini,\n"
	.string "apakah itu akan membuatku kaya?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Apa yang Aku pelajari di sini, bisa\n"
	.string "Aku terapkan pada perbuatan jahat…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Jika anak buah kami tidak mengacau\n"
	.string "di RUSTBORO, kami tidak akan ada di\l"
	.string "sini!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Aku tidak punya ¥50, jadi butuh\n"
	.string "waktu lama untuk melewati\l"
	.string "resepsionis.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Aku ingin belajar tentang laut dan\n"
	.string "menggunakan pengetahuan itu untuk\l"
	.string "bertarung.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Aku jadi gembira dan terharu saat\n"
	.string "melihat laut!\p"
	.string "Bagiku, KAP. STERN adalah panutan\n"
	.string "nomor satu!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "Laut itu luas tanpa akhir, dan\n"
	.string "sangat dalam…\p"
	.string "Pasti ada banyak POKéMON yang tidak\n"
	.string "kita ketahui.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Aku ingin POKéMON laut.\p"
	.string "Menurutku akan terasa sejuk dan\n"
	.string "nyaman untuk dipeluk.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aduh! Apa yang Kamu lakukan di\n"
	.string "sini?\p"
	.string "Aku? Aku anggota TIM AQUA yang Kamu\n"
	.string "hajar sebelumnya, ingat? Di\l"
	.string "TEROWONGAN RUSTURF?\p"
	.string "Ini, ambil ini! Kamu harus\n"
	.string "memaafkan Aku!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "TM itu, lebih cocok untukmu\n"
	.string "daripada untukku.\p"
	.string "Semoga Aku tidak pernah melihatmu\n"
	.string "lagi! Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Aduh, ayolah! Kamu harus mengambil\n"
	.string "ini dan biarkan Aku pergi!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Cairan biru berputar-putar di dalam\n"
	.string "wadah kaca.\p"
	.string "“Ini adalah eksperimen untuk\n"
	.string "menciptakan PUSARAN AIR secara\l"
	.string "buatan menggunakan angin.$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Bola merah mengambang naik turun di\n"
	.string "dalam wadah kaca.\p"
	.string "“Ini adalah eksperimen yang\n"
	.string "menyimulasikan AIR TERJUN\l"
	.string "menggunakan daya apung bola.$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Ini adalah sampel tanah dari dasar\n"
	.string "laut.\p"
	.string "“Selama bertahun-tahun, sisa-sisa\n"
	.string "makhluk hidup mengendap di dasar\l"
	.string "laut, membentuk lapisan sedimen.\p"
	.string "“Dengan menganalisis\n"
	.string "lapisan-lapisan ini, masa lalu kuno\l"
	.string "terungkap.$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Ini adalah sampel pasir pantai.\p"
	.string "“Batu dari gunung hanyut dibawa\n"
	.string "sungai di mana mereka terkelupas\l"
	.string "dan terkikis.\p"
	.string "“Mereka tereduksi menjadi butiran\n"
	.string "dan berakhir sebagai pasir di\l"
	.string "pantai.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“FAKTA MINI LAUT 1 Mengapa air laut\n"
	.string "berwarna biru?\p"
	.string "“Cahaya terdiri dari banyak warna.\p"
	.string "“Ketika cahaya melewati air,\n"
	.string "sebagian besar jenis cahaya\l"
	.string "kehilangan warna.\p"
	.string "“Namun, cahaya biru mempertahankan\n"
	.string "warnanya, membuat laut tampak biru.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“FAKTA MINI LAUT 2 Mengapa laut\n"
	.string "asin?\p"
	.string "“Air laut mengandung garam terlarut\n"
	.string "dalam bentuk ion natrium dan\l"
	.string "klorin.\p"
	.string "“Ion-ion ini meresap keluar dari\n"
	.string "batuan dan terbawa ke laut oleh\l"
	.string "hujan.\p"
	.string "“Konsentrasi garam terlarutlah yang\n"
	.string "membuat laut asin.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“FAKTA MINI LAUT 3 Mana yang lebih\n"
	.string "besar? Laut atau daratan?\p"
	.string "“Laut menutupi sekitar 70% planet,\n"
	.string "dan sisanya adalah daratan.\p"
	.string "“Oleh karena itu, laut lebih dari\n"
	.string "dua kali lipat ukuran daratan.$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Ini adalah fosil dengan punggung\n"
	.string "bergelombang di atasnya.\p"
	.string "“Tanah di dasar laut terkikis oleh\n"
	.string "air pasang.\p"
	.string "“Air laut yang mengalir menandai\n"
	.string "tanah dengan punggungan dan lembah\l"
	.string "kecil.\p"
	.string "“Jika tanah ini menjadi fosil, itu\n"
	.string "disebut tanda riak.$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Mesin aneh berputar di bawah kubah\n"
	.string "kaca.\p"
	.string "Mungkin ini untuk mengukur\n"
	.string "kedalaman sesuatu…$"

//gemini
SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Hmm… Kalau ini ditaruh di sini, dan\n"
	.string "itu ditaruh di sana…\p"
	.string "Lalu benda ini ditaruh di mana? Dan\n"
	.string "bagaimana dengan perkakas kecil\l"
	.string "itu?\p"
	.string "Aaarrggh! Aku tidak mengerti\n"
	.string "apa-apa tentang ini!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm? Hai, aku DOCK.\p"
	.string "KAPT. STERN menugaskanku merancang\n"
	.string "sebuah kapal feri.\p"
	.string "Oh! Itu di sana… Apakah itu BARANG\n"
	.string "DEVON?\p"
	.string "Tapi, hmm… Ini tidak akan berhasil…\p"
	.string "KAPT. STERN pergi entah ke mana.\n"
	.string "Katanya dia ada urusan.\p"
	.string "Bisakah aku meminta Kamu mencari\n"
	.string "KAPT. STERN dan mengantarkan itu\l"
	.string "padanya?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: Ke mana KAPT. STERN pergi ya?\p"
	.string "Bisakah Kamu pergi mencari KAPT.\n"
	.string "STERN dan mengantarkan paket itu\l"
	.string "padanya?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Membuat kapal adalah sebuah\n"
	.string "seni.\p"
	.string "Banyak hal tidak bisa dipecahkan\n"
	.string "hanya dengan perhitungan.\p"
	.string "Aku benar-benar butuh nasihat dari\n"
	.string "seorang veteran yang tahu tentang\l"
	.string "lautan…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Hai! MR. BRINEY telah\n"
	.string "bergabung untuk membantu kami.\p"
	.string "Berkat pelaut veteran itu, kapal\n"
	.string "feri ini perlahan-lahan mulai\l"
	.string "terbentuk.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: Kapal feri ini akhirnya siap!\p"
	.string "S.S. TIDAL yang baru benar-benar\n"
	.string "keajaiban teknologi!\p"
	.string "Tapi, aku merasa kita bisa membuat\n"
	.string "sesuatu yang bahkan lebih baik.\p"
	.string "Kamu tahu, kemajuan teknologi tidak\n"
	.string "pernah berakhir.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "MR. BRINEY: Ah, {PLAYER}{KUN}!\n"
	.string "Sudah lama sekali!\p"
	.string "Ya, sejak aku bertemu Kamu, pelaut\n"
	.string "tua ini jadi merasa bersemangat!\p"
	.string "Jadi, aku memutuskan untuk membantu\n"
	.string "DOCK membuat kapal feri.\p"
	.string "Ya, bagaimanapun juga, feri akan\n"
	.string "bisa mengangkut banyak orang.\p"
	.string "Tapi, Kamu tahu, DOCK itu\n"
	.string "benar-benar orang yang istimewa.\p"
	.string "Dengan bakatnya dalam teknologi dan\n"
	.string "pengalamanku, aku yakin kita bisa\l"
	.string "membangun satu kapal yang hebat,\l"
	.string "ya!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Musim, cuaca, posisi bulan di\n"
	.string "langit…\p"
	.string "Kondisi ini dan kondisi lainnya\n"
	.string "membuat lautan mengubah\l"
	.string "ekspresinya.\p"
	.string "Benar! Lautan itu seperti makhluk\n"
	.string "hidup!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Aku mudah mabuk laut. Jadi aku\n"
	.string "membantu di sini saja.$"

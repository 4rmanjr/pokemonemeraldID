//gemini
Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Terowongan RUSTURF itu…\p"
	.string "Awalnya, kami punya kru besar yang\n"
	.string "mengebor batu pakai mesin terbaru.\l"
	.string "Tapi, kami harus berhenti.\p"
	.string "Ternyata, kami akan berdampak\n"
	.string "negatif pada POKéMON liar di area\l"
	.string "ini.\p"
	.string "Jadi, kami hanya bermalas-malasan\n"
	.string "di sini tanpa melakukan apa-apa.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Ada pria yang menggali jalannya ke\n"
	.string "VERDANTURF sendirian.\l"
	.string "Dia sangat ingin menembus.\p"
	.string "Dia bilang kalau dia menggali sedikit\n"
	.string "demi sedikit tanpa pakai mesin, dia\l"
	.string "tidak akan mengganggu POKéMON &\l"
	.string "menghindari merusak lingkungan alami.\p"
	.string "Aku ingin tahu apakah dia sudah\n"
	.string "berhasil menembus.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Untuk ke VERDANTURF tanpa pakai\n"
	.string "Terowongan ini, Kamu harus menyeberang\l"
	.string "laut ke DEWFORD, berlayar ke SLATEPORT,\l"
	.string "lalu melewati MAUVILLE.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Sudah dengar? Terowongan ke\n"
	.string "VERDANTURF sudah tembus!\p"
	.string "Kadang, kalau Kamu berharap cukup\n"
	.string "kuat, impian bisa jadi kenyataan.$"

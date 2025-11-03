//gemini
VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Papa-ku bilang.\p"
	.string "Katanya terowongan ini penuh\n"
	.string "POKéMON penakut.\p"
	.string "Mereka ketakutan karena suara\n"
	.string "keras & bikin keributan.\p"
	.string "Jadi, proyek terowongan besar\n"
	.string "itu harus dihentikan.\p"
	.string "Tapi ada satu pria. Dia mencoba\n"
	.string "menggali terowongan itu sendiri!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Ada pria yang menggali terowongan\n"
	.string "untuk wanita yang dicintainya.\p"
	.string "Aku tidak begitu mengerti,\n"
	.string "tapi ya sudahlah!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Karena arah angin, abu vulkanik\n"
	.string "tak pernah tertiup ke sini.\p"
	.string "Udara di sini bersih & segar.\n"
	.string "Tinggal di sini akan sangat baik\l"
	.string "bahkan untuk orang lemah & sakit.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "POKéMON-ku & aku sedang dalam\n"
	.string "rentetan kemenangan.\p"
	.string "Jadi, aku memutuskan untuk debut\n"
	.string "di BATTLE TENT kota ini.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Kamu lihat gua di sebelah\n"
	.string "POKéMON MART?\p"
	.string "Ada pria di sana yang mencoba\n"
	.string "menghancurkan batu-batu agar\l"
	.string "bisa menembus ke sisi lain.\p"
	.string "Akan sangat bagus jika kita bisa\n"
	.string "lewat… Mudah ke RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Gua di sebelah POKéMON MART itu\n"
	.string "sekarang jadi terowongan ke sana.\p"
	.string "Bagus sekali--mudah belanja\n"
	.string "produk DEVON baru di RUSTBORO.$"

VerdanturfTown_Text_TownSign:
	.string "KOTA VERDANTURF\p"
	.string "“Dataran tinggi berangin dengan\n"
	.string "wangi rumput yang manis.”$"

VerdanturfTown_Text_WandasHouse:
	.string "RUMAH WANDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "BATTLE TENT LOKASI VERDANTURF\n"
	.string "“Manjakan Matamu dengan Pertarungan!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TEROWONGAN RUSTURF\n"
	.string "“Menghubungkan RUSTBORO &\p"
	.string "VERDANTURF\p"
	.string "“Proyek terowongan telah\n"
	.string "dibatalkan.”$"

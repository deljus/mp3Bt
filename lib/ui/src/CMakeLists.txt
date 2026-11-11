SET(SOURCES ui_main.c
    ui_player.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_img_music_disk_png.c
    ui_img_advertising_png.c
    ui_img_wireless_signal_png.c
    ui_img_connect_png.c)

add_library(ui ${SOURCES})

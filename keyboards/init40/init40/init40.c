/* Copyright 2023 Finalkey
 * Copyright 2023 LiWenLiu <https://github.com/LiuLiuQMK>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../../lib/rdr_lib/rdr_common.h"


/**********************系统函数***************************/
/*  键盘扫描按键延时 */
void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

led_config_t g_led_config = { {
	{ 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       },
    { 12       , 13       , 14       , 15       , 16       , 17       , 18       , 19       , 20       , 21       , 22       , 33       },
	{ 23       , 24       , 25       , 26       , 27       , 28       , 29       , 30       , 31       , 32       , NO_LED   , NO_LED   },
	{ 34       , 35       , 36       , 37       , NO_LED   , NO_LED   , 38       , NO_LED   , 39       , 40       , 41       , NO_LED   }
},{
    // 背光灯
    { 0,  10},  { 20, 10},  { 40, 10},  { 60, 10},  { 80, 10}, { 100, 10}, { 120, 10}, { 140, 10}, { 160, 10}, { 180, 10}, { 200, 10}, { 224, 10},
    { 4,  20},  { 24, 20},  { 44, 20},  { 64, 20},  { 84, 20}, { 104, 20}, { 124, 20}, { 144, 20}, { 164, 20}, { 184, 20}, { 214, 20},
    { 8,  30},  { 34, 30},  { 54, 30},  { 74, 30},  { 94, 30}, { 114, 30}, { 134, 30}, { 154, 30}, { 174, 30}, { 194, 30}, { 224, 30},
    { 0,  40},  { 25, 40},  { 45, 40},  { 84, 40},                         { 124, 40},             { 174, 40}, { 194, 40}, { 224, 40},

    { 255,65},  { 255,65},  { 255,65},  { 255,65},  { 255,65}
}, {
    // 背光灯
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,          1,      1,  1,  1,

    0,  0,  0,  0,  0
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();

    return false;
}

/************************休眠*****************************/
// USB枚举
bool usb_enum_done = false;

void notify_usb_device_state_change_user(struct usb_device_state usb_device_state)
{
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if (usb_device_state.configure_state == USB_DEVICE_STATE_CONFIGURED) {
            if (!usb_enum_done) { // 只在第一次 CONFIGURED 时执行
                Usb_If_Ok = true;
                Usb_If_Ok_Led = true;
                Usb_If_Ok_Delay = 0;
                usb_enum_done = true; // 标记已完成
            }
        } else {
            Usb_If_Ok = false;
            Usb_If_Ok_Led = false;
            usb_enum_done = false; // 断开时重置
        }
    } else {
        Usb_If_Ok = false;
        Usb_If_Ok_Led = false;
    }
}

void housekeeping_task_user(void) {
    User_Keyboard_Reset();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}
/*********************************************************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
                                                                    /*只要有按键就不会进入休眠*/
    return Key_Value_Dispose(keycode, record);
}

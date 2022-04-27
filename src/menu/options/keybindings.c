/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** keybindings
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static const struct keys_s key_list[] = {
    {sfKeyA, "A"},
    {sfKeyB, "B"},
    {sfKeyC, "C"},
    {sfKeyD, "D"},
    {sfKeyE, "E"},
    {sfKeyF, "F"},
    {sfKeyG, "G"},
    {sfKeyH, "H"},
    {sfKeyI, "I"},
    {sfKeyJ, "J"},
    {sfKeyK, "K"},
    {sfKeyL, "L"},
    {sfKeyM, "M"},
    {sfKeyN, "N"},
    {sfKeyO, "O"},
    {sfKeyP, "P"},
    {sfKeyQ, "Q"},
    {sfKeyR, "R"},
    {sfKeyS, "S"},
    {sfKeyT, "T"},
    {sfKeyU, "U"},
    {sfKeyV, "V"},
    {sfKeyW, "W"},
    {sfKeyX, "X"},
    {sfKeyY, "Y"},
    {sfKeyZ, "Z"},
    {sfKeyNum0, "0"},
    {sfKeyNum1, "1"},
    {sfKeyNum2, "2"},
    {sfKeyNum3, "3"},
    {sfKeyNum4, "4"},
    {sfKeyNum5, "5"},
    {sfKeyNum6, "6"},
    {sfKeyNum7, "7"},
    {sfKeyNum8, "8"},
    {sfKeyNum9, "9"},
    {sfKeyEscape, "ESCAPE"},
    {sfKeyLControl, "LEFT CONTROL"},
    {sfKeyLShift, "LEFT SHIFT"},
    {sfKeyLAlt, "LEFT ALT"},
    {sfKeyLSystem, "WINDOWS"},
    {sfKeyRControl, "RIGHT CONTROL"},
    {sfKeyRShift, "RIGHT SHIFT"},
    {sfKeyRAlt, "RIGHT ALT"},
    {sfKeyRSystem, "ALT GR"},
    {sfKeyMenu, "MENU"},
    {sfKeyLBracket, "{"},
    {sfKeyRBracket, "}"},
    {sfKeySemicolon, ";"},
    {sfKeyComma, " , "},
    {sfKeyPeriod, "."},
    {sfKeyQuote, "'"},
    {sfKeySlash, "/"},
    {sfKeyBackslash, "\\"},
    {sfKeyTilde, "~"},
    {sfKeyEqual, " = "},
    {sfKeySpace, "SPACE"},
    {sfKeyEnter, "ENTER"},
    {sfKeyBackspace, "BACKSPACE"},
    {sfKeyTab, "TAB"},
    {sfKeyPageUp, "PAGE UP"},
    {sfKeyPageDown, "PAGE DOWN"},
    {sfKeyEnd, "END"},
    {sfKeyHome, "HOME"},
    {sfKeyInsert, "INSERT"},
    {sfKeyDelete, "SUPPR"},
    {sfKeyAdd, "+"},
    {sfKeySubtract, "-"},
    {sfKeyMultiply, "*"},
    {sfKeyDivide, "/"},
    {sfKeyLeft, "LEFT ARROW"},
    {sfKeyRight, "RIGHT ARROW"},
    {sfKeyUp, "UP ARROW"},
    {sfKeyDown, "DOWN ARROW"},
    {sfKeyNumpad0, "NUMPAD 0"},
    {sfKeyNumpad1, "NUMPAD 1"},
    {sfKeyNumpad2, "NUMPAD 2"},
    {sfKeyNumpad3, "NUMPAD 3"},
    {sfKeyNumpad4, "NUMPAD 4"},
    {sfKeyNumpad5, "NUMPAD 5"},
    {sfKeyNumpad6, "NUMPAD 6"},
    {sfKeyNumpad7, "NUMPAD 7"},
    {sfKeyNumpad8, "NUMPAD 7"},
    {sfKeyNumpad9, "NUMPAD 8"},
    {sfKeyF1, "F1"},
    {sfKeyF2, "F2"},
    {sfKeyF3, "F3"},
    {sfKeyF4, "F4"},
    {sfKeyF5, "F5"},
    {sfKeyF6, "F6"},
    {sfKeyF7, "F7"},
    {sfKeyF8, "F8"},
    {sfKeyF9, "F9"},
    {sfKeyF10, "F10"},
    {sfKeyF11, "F11"},
    {sfKeyF12, "F12"},
    {sfKeyF13, "F13"},
    {sfKeyF14, "F14"},
    {sfKeyF15, "F15"},
    {sfKeyPause, "PAUSE"},
    {-1, "NULL"}
};

static char *getkey(int key)
{
    size_t i = 0;
    for (; key_list[i].data != -1; i++)
        if (key_list[i].data == key)
            return key_list[i].name;
    return key_list[i].name;
}

static char *replace_str(char *name, char *new)
{
    char *my_return = NULL;
    size_t i = 0;

    for (; name[i] != ':'; i++);
    i += 2;
    my_return = malloc(sizeof(char) * (i + my_strlen(new)) + 1);
    my_strncpy(my_return, name, i);
    my_return = my_strcat(my_return, new);
    return my_return;
}

static int check_all_keys(rpg_t *rpg, int key)
{
    if (KEYUP == key)
        return 84;
    if (KEYDOWN == key)
        return 84;
    if (KEYLEFT == key)
        return 84;
    if (KEYRIGHT == key)
        return 84;
    if (KEYATK == key)
        return 84;
    if (KEYINV == key)
        return 84;
    if (KEYRUN == key)
        return 84;
    if (KEYPROTECT == key)
        return 84;
    return 0;
}

static int replace_keys(rpg_t *rpg, int button, int key)
{
    if (check_all_keys(rpg, key) == 84)
        return 84;
    if (button == 9)
        rpg->keybinds->key_up = key;
    if (button == 10)
        rpg->keybinds->key_down = key;
    if (button == 11)
        rpg->keybinds->key_left = key;
    if (button == 12)
        rpg->keybinds->key_right = key;
    if (button == 13)
        rpg->keybinds->key_inventory = key;
    if (button == 14)
        rpg->keybinds->key_attack = key;
    if (button == 15)
        rpg->keybinds->key_protect = key;
    if (button == 16)
        rpg->keybinds->key_run = key;
    return 0;
}

void replace_text(rpg_t *rpg, int button)
{
    int value = 0;
    char *str = NULL;
    char *name = NULL;

    while (str == NULL) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            print_parralax(rpg);
            do_parralax_keyinput(rpg);
            sfRenderWindow_drawSprite(rpg->window, BUTTONSO->lst_bt[18]->sprite,
            NULL);
            sfRenderWindow_drawText(rpg->window, BUTTONSO->lst_bt[18]->text, NULL);
            if (rpg->event.type == sfEvtClosed)
                sfRenderWindow_close(rpg->window);
            if (rpg->event.type == sfEvtKeyPressed) {
                value = rpg->event.key.code;
                str = getkey(value);
            }
            sfRenderWindow_display(rpg->window);
        }
    }
    if (value != 0) {
        if (replace_keys(rpg, button, value) == 84)
            return;
        str = getkey(value);
        name = (char *)sfText_getString(BUTTONSO->lst_bt[button]->text);
        str = replace_str(name, str);
        sfText_setString(BUTTONSO->lst_bt[button]->text, str);
    }
}
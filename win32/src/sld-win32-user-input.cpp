#pragma once

#include "ifb-win32.hpp"

inline const key_code_t 
ifb::win32::user_input_keycode(
    const u32 win32_keycode) {
        
    key_code_t ifb_keycode = 0;

    switch (win32_keycode) {

        case VK_BACK:        { ifb_keycode = key_code_Back;                  } break;
        case VK_TAB:         { ifb_keycode = key_code_Tab;                   } break;
        case VK_CLEAR:       { ifb_keycode = key_code_Clear;                 } break;
        case VK_RETURN:      { ifb_keycode = key_code_Return;                } break;
        case VK_SHIFT:       { ifb_keycode = key_code_Shift;                 } break;
        case VK_CONTROL:     { ifb_keycode = key_code_Control;               } break;
        case VK_MENU:        { ifb_keycode = key_code_Menu;                  } break;
        case VK_PAUSE:       { ifb_keycode = key_code_Pause;                 } break;
        case VK_CAPITAL:     { ifb_keycode = key_code_Capital;               } break;
        case VK_ESCAPE:      { ifb_keycode = key_code_Escape;                } break;
        case VK_SPACE:       { ifb_keycode = key_code_Space;                 } break;
        case VK_PRIOR:       { ifb_keycode = key_code_Prior;                 } break;
        case VK_NEXT:        { ifb_keycode = key_code_Next;                  } break;
        case VK_END:         { ifb_keycode = key_code_End;                   } break;
        case VK_HOME:        { ifb_keycode = key_code_Home;                  } break;
        case VK_LEFT:        { ifb_keycode = key_code_Left;                  } break;
        case VK_UP:          { ifb_keycode = key_code_Up;                    } break;
        case VK_RIGHT:       { ifb_keycode = key_code_Right;                 } break;
        case VK_DOWN:        { ifb_keycode = key_code_Down;                  } break;
        case VK_SELECT:      { ifb_keycode = key_code_Select;                } break;
        case VK_PRINT:       { ifb_keycode = key_code_Print;                 } break;
        case VK_SNAPSHOT:    { ifb_keycode = key_code_Snapshot;              } break;
        case VK_INSERT:      { ifb_keycode = key_code_Insert;                } break;
        case VK_DELETE:      { ifb_keycode = key_code_Delete;                } break;
        case VK_HELP:        { ifb_keycode = key_code_Help;                  } break;
        case 0x30:           { ifb_keycode = key_code_0;                     } break;
        case 0x31:           { ifb_keycode = key_code_1;                     } break;
        case 0x32:           { ifb_keycode = key_code_2;                     } break;
        case 0x33:           { ifb_keycode = key_code_3;                     } break;
        case 0x34:           { ifb_keycode = key_code_4;                     } break;
        case 0x35:           { ifb_keycode = key_code_5;                     } break;
        case 0x36:           { ifb_keycode = key_code_6;                     } break;
        case 0x37:           { ifb_keycode = key_code_7;                     } break;
        case 0x38:           { ifb_keycode = key_code_8;                     } break;
        case 0x39:           { ifb_keycode = key_code_9;                     } break;
        case 0x41:           { ifb_keycode = key_code_A;                     } break;
        case 0x42:           { ifb_keycode = key_code_B;                     } break;
        case 0x43:           { ifb_keycode = key_code_C;                     } break;
        case 0x44:           { ifb_keycode = key_code_D;                     } break;
        case 0x45:           { ifb_keycode = key_code_E;                     } break;
        case 0x46:           { ifb_keycode = key_code_F;                     } break;
        case 0x47:           { ifb_keycode = key_code_G;                     } break;
        case 0x48:           { ifb_keycode = key_code_H;                     } break;
        case 0x49:           { ifb_keycode = key_code_I;                     } break;
        case 0x4A:           { ifb_keycode = key_code_J;                     } break;
        case 0x4B:           { ifb_keycode = key_code_K;                     } break;
        case 0x4C:           { ifb_keycode = key_code_L;                     } break;
        case 0x4D:           { ifb_keycode = key_code_M;                     } break;
        case 0x4E:           { ifb_keycode = key_code_N;                     } break;
        case 0x4F:           { ifb_keycode = key_code_O;                     } break;
        case 0x50:           { ifb_keycode = key_code_P;                     } break;
        case 0x51:           { ifb_keycode = key_code_Q;                     } break;
        case 0x52:           { ifb_keycode = key_code_R;                     } break;
        case 0x53:           { ifb_keycode = key_code_S;                     } break;
        case 0x54:           { ifb_keycode = key_code_T;                     } break;
        case 0x55:           { ifb_keycode = key_code_U;                     } break;
        case 0x56:           { ifb_keycode = key_code_V;                     } break;
        case 0x57:           { ifb_keycode = key_code_W;                     } break;
        case 0x58:           { ifb_keycode = key_code_X;                     } break;
        case 0x59:           { ifb_keycode = key_code_Y;                     } break;
        case 0x5A:           { ifb_keycode = key_code_Z;                     } break;
        case VK_LWIN:        { ifb_keycode = key_code_WinLeft;               } break;
        case VK_RWIN:        { ifb_keycode = key_code_WinRight;              } break;
        case VK_APPS:        { ifb_keycode = key_code_Apps;                  } break;
        case VK_NUMPAD0:     { ifb_keycode = key_code_Numpad0;               } break;
        case VK_NUMPAD1:     { ifb_keycode = key_code_Numpad1;               } break;
        case VK_NUMPAD2:     { ifb_keycode = key_code_Numpad2;               } break;
        case VK_NUMPAD3:     { ifb_keycode = key_code_Numpad3;               } break;
        case VK_NUMPAD4:     { ifb_keycode = key_code_Numpad4;               } break;
        case VK_NUMPAD5:     { ifb_keycode = key_code_Numpad5;               } break;
        case VK_NUMPAD6:     { ifb_keycode = key_code_Numpad6;               } break;
        case VK_NUMPAD7:     { ifb_keycode = key_code_Numpad7;               } break;
        case VK_NUMPAD8:     { ifb_keycode = key_code_Numpad8;               } break;
        case VK_NUMPAD9:     { ifb_keycode = key_code_Numpad9;               } break;
        case VK_MULTIPLY:    { ifb_keycode = key_code_Multiply;              } break;
        case VK_ADD:         { ifb_keycode = key_code_Add;                   } break;
        case VK_SEPARATOR:   { ifb_keycode = key_code_Separator;             } break;
        case VK_SUBTRACT:    { ifb_keycode = key_code_Subtract;              } break;
        case VK_DECIMAL:     { ifb_keycode = key_code_Decimal;               } break;
        case VK_DIVIDE:      { ifb_keycode = key_code_Divide;                } break;
        case VK_F1:          { ifb_keycode = key_code_F1;                    } break;
        case VK_F2:          { ifb_keycode = key_code_F2;                    } break;
        case VK_F3:          { ifb_keycode = key_code_F3;                    } break;
        case VK_F4:          { ifb_keycode = key_code_F4;                    } break;
        case VK_F5:          { ifb_keycode = key_code_F5;                    } break;
        case VK_F6:          { ifb_keycode = key_code_F6;                    } break;
        case VK_F7:          { ifb_keycode = key_code_F7;                    } break;
        case VK_F8:          { ifb_keycode = key_code_F8;                    } break;
        case VK_F9:          { ifb_keycode = key_code_F9;                    } break;
        case VK_F10:         { ifb_keycode = key_code_F10;                   } break;
        case VK_F11:         { ifb_keycode = key_code_F11;                   } break;
        case VK_F12:         { ifb_keycode = key_code_F12;                   } break;
        case VK_NUMLOCK:     { ifb_keycode = key_code_Numlock;               } break;
        case VK_LSHIFT:      { ifb_keycode = key_code_ShiftLeft;             } break;
        case VK_RSHIFT:      { ifb_keycode = key_code_ShiftRight;            } break;
        case VK_LCONTROL:    { ifb_keycode = key_code_ControlLeft;           } break;
        case VK_RCONTROL:    { ifb_keycode = key_code_ControlRight;          } break;
        case VK_LMENU:       { ifb_keycode = key_code_MenuLeft;              } break;
        case VK_RMENU:       { ifb_keycode = key_code_MenuRight;             } break;
        case VK_VOLUME_MUTE: { ifb_keycode = key_code_VolumeMute;            } break;
        case VK_VOLUME_DOWN: { ifb_keycode = key_code_VolumeDown;            } break;
        case VK_VOLUME_UP:   { ifb_keycode = key_code_VolumeUp;              } break;
        case VK_OEM_PLUS:    { ifb_keycode = key_code_Plus;                  } break;
        case VK_OEM_COMMA:   { ifb_keycode = key_code_Comma;                 } break;
        case VK_OEM_MINUS:   { ifb_keycode = key_code_Minus;                 } break;
        case VK_OEM_PERIOD:  { ifb_keycode = key_code_Period;                } break;
        case VK_OEM_2:       { ifb_keycode = key_code_SlashForward_Question; } break;
        case VK_OEM_3:       { ifb_keycode = key_code_Tilde;                 } break;
        case VK_OEM_4:       { ifb_keycode = key_code_BracketOpen;           } break;
        case VK_OEM_5:       { ifb_keycode = key_code_SlashBack_Pipe;        } break;
        case VK_OEM_6:       { ifb_keycode = key_code_BracketClose;          } break;
        case VK_OEM_7:       { ifb_keycode = key_code_Quote;                 } break;
        default: break;
    }

    return(ifb_keycode);
}
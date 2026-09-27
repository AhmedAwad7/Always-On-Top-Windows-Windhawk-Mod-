// ==WindhawkMod==
// @id              always-on-top
// @name            Always On Top Windows
// @description     Pin/unpin any window on top of others, with an accent border, OSD, sound and system menu integration
// @version         1.3
// @author          AhmedAwad7
// @github          https://github.com/AhmedAwad7
// @license         MIT
// @include         windhawk.exe
// @include         *
// @compilerOptions -luser32 -lwinmm -lgdi32 -ldwmapi
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Always On Top Windows

![Screenrecord](https://raw.githubusercontent.com/AhmedAwad7/Always-On-Top-Windows-Windhawk-Mod-/main/Screenrecord/Demo.gif)

## English

Press **`Ctrl+Alt+T`** (customizable) to pin/unpin the active window on top of all other windows.

This mod helps you multitask by pinning important windows so they always remain visible.

**Features:**
- 🔊 Audio notifications to indicate pinning/unpinning, with the ability to customize or disable them.
- 🖥️ A floating text displayed above the taskbar, on the monitor of the affected window, to indicate pinning/unpinning.
![Floating Text](https://raw.githubusercontent.com/AhmedAwad7/Always-On-Top-Windows-Windhawk-Mod-/main/Screenrecord/Floating_text.gif)
- 🟨 A colored accent border drawn around pinned windows, similar to PowerToys' Always on Top.
- 📌 A native "Always on Top" item in each window's system menu (title bar icon / Alt+Space) and in its taskbar thumbnail preview menu, kept in sync with the real pinned state.
- ⚡ Event-based shortcut (`RegisterHotKey`) with no continuous polling, fully customizable modifiers and key.
- 🧹 The persistent hotkey/OSD/border logic runs in a single dedicated `windhawk.exe` process; only a small, passive system-menu hook runs in other processes.

**System Requirements:**
- 📀 Windows 7 \ 8 \ 8.1 \ 10 \ 11
- 📊 Windhawk application (latest version preferred)

**What's new in 1.3:**
- Pin state is now read directly from the window's native `WS_EX_TOPMOST` style instead of an internal list, so it never gets out of sync with other tools.
- Added the accent border, native system menu integration (including taskbar thumbnails), multi-monitor aware notifications, and a fully configurable hotkey.
- Hardened GDI/handle lifecycle: notification window is reused instead of recreated, window classes are registered once, and every handle is released on unload.
- Broadened the excluded-window list to also skip `Shell_TrayWnd` and `Shell_SecondaryTrayWnd`.

**Contributing:**
Contributors are welcome! You can open Issues or Pull Requests on GitHub.
---
**How to Handle Settings Within the Mod**
---
- You can turn off sounds, turn off the floating text, turn off the accent border, turn off system menu integration, or enable any combination—it's up to you:
![Settings](https://raw.githubusercontent.com/AhmedAwad7/Always-On-Top-Windows-Windhawk-Mod-/main/Screenrecord/settings.gif)
- You can also customize the pin/unpin sounds by placing your preferred audio files in a folder and entering the path in the text box, as shown in this example:
![Custom Sound](https://raw.githubusercontent.com/AhmedAwad7/Always-On-Top-Windows-Windhawk-Mod-/main/Screenrecord/custom_sound.png)

---

## العربية

اضغط **`Ctrl+Alt+T`** (قابل للتخصيص) لتثبيت/إلغاء تثبيت النافذة النشطة فوق جميع النوافذ الأخرى.

هذا المود يساعدك في تعدد المهام عن طريق تثبيت النوافذ المهمة لتظل مرئية دائماً.

**المميزات:**
- 🔊 إشعارات صوتية لتوضيح التثبيت\إلغاء التثبيت مع إمكانية تخصيصها أو تعطيلها.
- 🖥️ نص عائم فوق شريط المهام، على شاشة النافذة المتأثرة، لتوضيح التثبيت\إلغاء التثبيت.
![Floating Text](https://raw.githubusercontent.com/AhmedAwad7/Always-On-Top-Windows-Windhawk-Mod-/main/Screenrecord/Floating_text.gif)
- 🟨 إطار ملون حول النوافذ المثبتة، مشابه لخاصية Always on Top في PowerToys.
- 📌 خيار "التثبيت دائماً" داخل قائمة النظام لكل نافذة وداخل قائمة معاينة شريط المهام، ويبقى متزامناً مع الحالة الفعلية.
- ⚡ اختصار يعتمد على الأحداث (`RegisterHotKey`) بدون استقصاء مستمر، وقابل للتخصيص بالكامل.
- 🧹 منطق الاختصار والإشعارات والإطار يعمل في عملية واحدة مخصصة لـ `windhawk.exe`؛ بينما تعمل خطافة خفيفة وسلبية فقط لقائمة النظام داخل بقية التطبيقات.

**متطلبات النظام:**
- 📀 ويندوز 7 \ 8 \ 8.1 \ 10 \ 11
- 📊 تطبيق Windhawk ويفضل أحدث إصدار

**الجديد في الإصدار 1.3:**
- أصبحت حالة التثبيت تُقرأ مباشرة من نمط النافذة `WS_EX_TOPMOST` بدلاً من قائمة داخلية، لتبقى متزامنة دائماً مع الأدوات الأخرى.
- إضافة الإطار المميز، والتكامل مع قائمة النظام (بما في ذلك معاينة شريط المهام)، وإشعارات تراعي الشاشة المتعددة، واختصار قابل للتخصيص بالكامل.
- تحسين إدارة الذاكرة والمقابض: إعادة استخدام نافذة الإشعار بدلاً من إعادة إنشائها، وتسجيل أصناف النوافذ مرة واحدة فقط، وتحرير كل مقبض عند الإغلاق.
- توسيع قائمة النوافذ المستثناة لتشمل أيضاً `Shell_TrayWnd` و `Shell_SecondaryTrayWnd`.

**المساهمة:**
نرحب بالمساهمين! يمكنكم فتح Issues أو Pull Requests على GitHub.
---
**طريقة التعامل مع الإعدادات داخل المود**
---
- يمكنك إيقاف الاصوات أو النص العائم أو الإطار المميز أو التكامل مع قائمة النظام، أو تشغيلهم معاً، الأمر يرجع لك:
![Settings](https://raw.githubusercontent.com/AhmedAwad7/Always-On-Top-Windows-Windhawk-Mod-/main/Screenrecord/settings.gif)
- ويمكنك تخصيص صوت التثبيت\إلغاء التثبيت عن طريق وضع اصواتك المفضلة في مجلد وكتابة المسار في المستطيل مثل هذا المثال:
![Custom Sound](https://raw.githubusercontent.com/AhmedAwad7/Always-On-Top-Windows-Windhawk-Mod-/main/Screenrecord/custom_sound.png)

*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- soundEnabled: true
  $name: Enable Sounds
  $name:ar-SA: تفعيل الصوت
  $description: Enable or disable sound notifications
  $description:ar-SA: تفعيل أو تعطيل إشعارات الصوت
- soundOn: C:\Windows\Media\Speech On.wav
  $name: Sound for Pin
  $name:ar-SA: صوت للتثبيت
  $description: When choosing a custom sound for pin, the audio file should be in .wav format
  $description:ar-SA: عند اختيار صوت مخصص لوضع التثبيت، يجب أن يكون صيغة الملف الصوتي .wav
- soundOff: C:\Windows\Media\Speech Off.wav
  $name: Sound for Unpin
  $name:ar-SA: صوت لإلغاء التثبيت
  $description: When choosing a custom sound for unpin, the audio file should be in .wav format
  $description:ar-SA: عند اختيار صوت مخصص لوضع إلغاء التثبيت، يجب أن يكون صيغة الملف الصوتي .wav
- notificationsEnabled: true
  $name: Enable Notifications
  $name:ar-SA: تفعيل الإشعارات
  $description: Show floating text notifications
  $description:ar-SA: إظهار إشعارات نصية عائمة
- osdTimeoutMs: 5000
  $name: Notification Duration (ms)
  $name:ar-SA: مدة ظهور الإشعار (مللي ثانية)
  $description: How long the floating notification stays on screen, in milliseconds
  $description:ar-SA: مدة بقاء الإشعار العائم على الشاشة، بالمللي ثانية
- borderEnabled: true
  $name: Enable Accent Border
  $name:ar-SA: تفعيل الإطار المميز
  $description: Draw a colored border around pinned windows
  $description:ar-SA: رسم إطار ملون حول النوافذ المثبتة
- borderThickness: 2
  $name: Border Thickness (px)
  $name:ar-SA: سماكة الإطار (بكسل)
  $description: Width of the accent border in pixels
  $description:ar-SA: عرض الإطار المميز بالبكسل
- borderColor: "#FFC107"
  $name: Border Color (hex)
  $name:ar-SA: لون الإطار (Hex)
  $description: "Accent border color as a hex code, e.g. #FFC107"
  $description:ar-SA: "لون الإطار المميز بصيغة Hex، مثال: #FFC107"
- systemMenuIntegration: true
  $name: System Menu Integration
  $name:ar-SA: التكامل مع قائمة النظام
  $description: Add a pin/unpin item to each window's system menu and taskbar thumbnail preview menu. This requires the mod to load into every application, not only windhawk.exe.
  $description:ar-SA: إضافة خيار للتثبيت\إلغاء التثبيت إلى قائمة النظام لكل نافذة وقائمة معاينة شريط المهام. يتطلب ذلك تحميل المود داخل جميع التطبيقات، وليس windhawk.exe فقط.
- hotkeyCtrl: true
  $name: Hotkey - Ctrl
  $name:ar-SA: الاختصار - Ctrl
  $description: Require Ctrl as part of the pin/unpin hotkey
  $description:ar-SA: اشتراط زر Ctrl ضمن اختصار التثبيت\إلغاء التثبيت
- hotkeyAlt: true
  $name: Hotkey - Alt
  $name:ar-SA: الاختصار - Alt
  $description: Require Alt as part of the pin/unpin hotkey
  $description:ar-SA: اشتراط زر Alt ضمن اختصار التثبيت\إلغاء التثبيت
- hotkeyShift: false
  $name: Hotkey - Shift
  $name:ar-SA: الاختصار - Shift
  $description: Require Shift as part of the pin/unpin hotkey
  $description:ar-SA: اشتراط زر Shift ضمن اختصار التثبيت\إلغاء التثبيت
- hotkeyWin: false
  $name: Hotkey - Win
  $name:ar-SA: الاختصار - Win
  $description: Require the Windows key as part of the pin/unpin hotkey
  $description:ar-SA: اشتراط زر Windows ضمن اختصار التثبيت\إلغاء التثبيت
- hotkeyKey: T
  $name: Hotkey - Key
  $name:ar-SA: الاختصار - المفتاح
  $description: A single letter, digit, or function key name (e.g. T, 5, F9)
  $description:ar-SA: "حرف واحد أو رقم أو اسم مفتاح دالة (مثال: T أو 5 أو F9)"
*/
// ==/WindhawkModSettings==


#include <windows.h>
#include <shellapi.h>
#include <dwmapi.h>
#include <mmsystem.h>
#include <string>
#include <vector>
#include <optional>
#include <atomic>
#include <cwctype>

// ============================================================
// ===== ثوابت المود =====
// ===== Mod-wide constants =====
// ============================================================

constexpr UINT WM_USER_QUIT = WM_USER + 101;
constexpr UINT WM_APPLY_SETTINGS = WM_USER + 102;
constexpr UINT WM_MOD_PIN_STATE_CHANGED = WM_APP + 300;

constexpr int HOTKEY_ID = 1;
constexpr UINT_PTR NOTIFICATION_TIMER_ID = 1001;
constexpr UINT_PTR BORDER_SAFETY_TIMER_ID = 1002;
constexpr UINT BORDER_SAFETY_INTERVAL_MS = 2000;

// Application-defined System Menu command. Must stay below 0xF000 (reserved
// for SC_* system commands) and have zero low-order 4 bits, since the OS
// uses those bits internally and callers must mask them off when reading.
constexpr UINT IDM_PIN_TOGGLE = 0x9010;

constexpr int kDefaultOsdTimeoutMs = 5000;
constexpr int kDefaultBorderThickness = 2;
constexpr COLORREF kDefaultBorderColor = RGB(0xFF, 0xC1, 0x07);
// Chroma-key color used to make the border overlay's interior transparent.
// Chosen to be all but impossible to pick as a real accent color.
constexpr COLORREF kBorderKeyColor = RGB(1, 2, 3);

constexpr PCWSTR kModWindowClassName = L"AlwaysOnTopModMsgWnd";
constexpr PCWSTR kNotificationWindowClassName = L"AlwaysOnTopModNotifyWnd";
constexpr PCWSTR kBorderWindowClassName = L"AlwaysOnTopModBorderWnd";

// ============================================================
// ===== الإعدادات =====
// ===== Settings =====
// ============================================================

struct Settings {
    bool soundEnabled = true;
    std::wstring soundOn = L"C:\\Windows\\Media\\Speech On.wav";
    std::wstring soundOff = L"C:\\Windows\\Media\\Speech Off.wav";
    bool notificationsEnabled = true;
    int osdTimeoutMs = kDefaultOsdTimeoutMs;
    bool borderEnabled = true;
    int borderThickness = kDefaultBorderThickness;
    COLORREF borderColor = kDefaultBorderColor;
    bool hotkeyCtrl = true;
    bool hotkeyAlt = true;
    bool hotkeyShift = false;
    bool hotkeyWin = false;
    BYTE hotkeyVk = L'T';
    UINT hotkeyModifiers = MOD_CONTROL | MOD_ALT | MOD_NOREPEAT;
};

Settings g_settings;
CRITICAL_SECTION g_cs;

// Parses a single hex color such as "#FFC107" or "FFC107". Falls back to
// `fallback` on any malformed input.
COLORREF ParseHexColor(const std::wstring& text, COLORREF fallback) {
    std::wstring hex = text;
    if (!hex.empty() && hex.front() == L'#') {
        hex.erase(0, 1);
    }
    if (hex.size() != 6) {
        return fallback;
    }
    for (wchar_t c : hex) {
        if (!iswxdigit(c)) {
            return fallback;
        }
    }
    wchar_t* end = nullptr;
    unsigned long value = wcstoul(hex.c_str(), &end, 16);
    if (!end || *end != L'\0') {
        return fallback;
    }
    BYTE r = (BYTE)((value >> 16) & 0xFF);
    BYTE g = (BYTE)((value >> 8) & 0xFF);
    BYTE b = (BYTE)(value & 0xFF);
    return RGB(r, g, b);
}

BYTE ParseVirtualKey(const std::wstring& text) {
    if (text.size() == 1) {
        wchar_t c = towupper(text[0]);
        if ((c >= L'A' && c <= L'Z') || (c >= L'0' && c <= L'9')) {
            return (BYTE)c;
        }
    }
    if (text.size() >= 2 && (text[0] == L'F' || text[0] == L'f')) {
        int n = _wtoi(text.c_str() + 1);
        if (n >= 1 && n <= 24) {
            return (BYTE)(VK_F1 + (n - 1));
        }
    }
    return L'T';
}

// ===== تحديث الإعدادات تحت القفل =====
// ===== Update settings under lock =====
void UpdateSettings() {
    EnterCriticalSection(&g_cs);

    g_settings.soundEnabled = Wh_GetIntSetting(L"soundEnabled") != 0;

    PCWSTR onStr = Wh_GetStringSetting(L"soundOn");
    g_settings.soundOn = (onStr && *onStr) ? onStr : L"C:\\Windows\\Media\\Speech On.wav";
    Wh_FreeStringSetting(onStr);

    PCWSTR offStr = Wh_GetStringSetting(L"soundOff");
    g_settings.soundOff = (offStr && *offStr) ? offStr : L"C:\\Windows\\Media\\Speech Off.wav";
    Wh_FreeStringSetting(offStr);

    g_settings.notificationsEnabled = Wh_GetIntSetting(L"notificationsEnabled") != 0;

    int osdTimeout = Wh_GetIntSetting(L"osdTimeoutMs");
    g_settings.osdTimeoutMs = (osdTimeout > 0) ? osdTimeout : kDefaultOsdTimeoutMs;

    g_settings.borderEnabled = Wh_GetIntSetting(L"borderEnabled") != 0;

    int thickness = Wh_GetIntSetting(L"borderThickness");
    g_settings.borderThickness = (thickness > 0) ? thickness : kDefaultBorderThickness;

    PCWSTR colorStr = Wh_GetStringSetting(L"borderColor");
    g_settings.borderColor = ParseHexColor(colorStr ? colorStr : L"", kDefaultBorderColor);
    Wh_FreeStringSetting(colorStr);

    g_settings.hotkeyCtrl = Wh_GetIntSetting(L"hotkeyCtrl") != 0;
    g_settings.hotkeyAlt = Wh_GetIntSetting(L"hotkeyAlt") != 0;
    g_settings.hotkeyShift = Wh_GetIntSetting(L"hotkeyShift") != 0;
    g_settings.hotkeyWin = Wh_GetIntSetting(L"hotkeyWin") != 0;

    PCWSTR keyStr = Wh_GetStringSetting(L"hotkeyKey");
    g_settings.hotkeyVk = ParseVirtualKey(keyStr ? keyStr : L"T");
    Wh_FreeStringSetting(keyStr);

    UINT modifiers = MOD_NOREPEAT;
    if (g_settings.hotkeyCtrl) modifiers |= MOD_CONTROL;
    if (g_settings.hotkeyAlt) modifiers |= MOD_ALT;
    if (g_settings.hotkeyShift) modifiers |= MOD_SHIFT;
    if (g_settings.hotkeyWin) modifiers |= MOD_WIN;
    g_settings.hotkeyModifiers = modifiers;

    LeaveCriticalSection(&g_cs);

    Wh_Log(L"✅ Settings updated");
}

// ===== قراءة نسخة من الإعدادات بشكل آمن =====
// ===== Read a copy of settings safely =====
Settings GetSettingsCopy() {
    Settings copy;
    EnterCriticalSection(&g_cs);
    copy = g_settings;
    LeaveCriticalSection(&g_cs);
    return copy;
}

void LoadSettings() {
    UpdateSettings();
}

// ============================================================
// ===== أدوات مشتركة =====
// ===== Shared utilities (used in every process the mod loads into) =====
// ============================================================

bool IsWindowTopMost(HWND hWnd) {
    return (GetWindowLongPtrW(hWnd, GWL_EXSTYLE) & WS_EX_TOPMOST) != 0;
}

bool IsShellExcludedWindow(HWND hWnd) {
    wchar_t className[64];
    if (!GetClassNameW(hWnd, className, ARRAYSIZE(className))) {
        return false;
    }
    static constexpr PCWSTR kExcludedClasses[] = {
        L"Progman",
        L"WorkerW",
        L"Shell_TrayWnd",
        L"Shell_SecondaryTrayWnd",
    };
    for (PCWSTR excluded : kExcludedClasses) {
        if (wcscmp(className, excluded) == 0) {
            return true;
        }
    }
    return false;
}

bool IsModOwnWindowClass(HWND hWnd) {
    wchar_t className[64];
    if (!GetClassNameW(hWnd, className, ARRAYSIZE(className))) {
        return false;
    }
    return wcscmp(className, kModWindowClassName) == 0 ||
           wcscmp(className, kNotificationWindowClassName) == 0 ||
           wcscmp(className, kBorderWindowClassName) == 0;
}

std::optional<bool> ToggleTopMostCore(HWND hWnd) {
    if (!hWnd || !IsWindow(hWnd) || IsShellExcludedWindow(hWnd) || IsModOwnWindowClass(hWnd)) {
        return std::nullopt;
    }

    bool willPin = !IsWindowTopMost(hWnd);
    HWND insertAfter = willPin ? HWND_TOPMOST : HWND_NOTOPMOST;
    if (!SetWindowPos(hWnd, insertAfter, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE)) {
        Wh_Log(L"❌ Failed to %s window %p (UIPI or other error)", willPin ? L"pin" : L"unpin", hWnd);
        return std::nullopt;
    }

    if (HMENU hMenu = GetSystemMenu(hWnd, FALSE)) {
        CheckMenuItem(hMenu, IDM_PIN_TOGGLE, MF_BYCOMMAND | (willPin ? MF_CHECKED : MF_UNCHECKED));
    }

    Wh_Log(L"%s window %p", willPin ? L"🔼 Pinned" : L"🔽 Unpinned", hWnd);
    return willPin;
}

void NotifyToolProcess(HWND hWnd, bool pinned) {
    HWND toolWnd = FindWindowExW(HWND_MESSAGE, nullptr, kModWindowClassName, nullptr);
    if (toolWnd) {
        PostMessageW(toolWnd, WM_MOD_PIN_STATE_CHANGED, (WPARAM)pinned, (LPARAM)hWnd);
    }
}

// ============================================================
// ===== منطق العملية الدائمة (داخل windhawk.exe) =====
// ===== Persistent tool-mod process logic (inside windhawk.exe) =====
// ============================================================
//
// Everything below in this section only ever runs inside the dedicated,
// long-lived windhawk.exe process created by the launcher (see
// Wh_ModAfterInit near the end of this file). It owns the hotkey, the OSD,
// sound playback, and every accent border overlay, so there is exactly one
// place that creates/destroys those resources.

HWND g_hwndMod = nullptr;
HANDLE g_hThread = nullptr;
HWND g_notificationHwnd = nullptr;
HWINEVENTHOOK g_locationHook = nullptr;
HWINEVENTHOOK g_foregroundHook = nullptr;

struct BorderOverlay {
    HWND target = nullptr;
    HWND overlay = nullptr;
};
std::vector<BorderOverlay> g_borderOverlays;
CRITICAL_SECTION g_borderCs;

DWORD WINAPI MainThread(LPVOID lpParam);
LRESULT CALLBACK ModWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NotificationWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BorderWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void CALLBACK WinEventProc(HWINEVENTHOOK hook, DWORD event, HWND hwnd, LONG idObject,
                            LONG idChild, DWORD idEventThread, DWORD dwmsEventTime);
void HandlePinStateChanged(HWND hWnd, bool pinned);

// ===== تشغيل صوت من النظام =====
// ===== Play a sound from the system =====
void PlaySystemSound(bool isPinned) {
    Settings settings = GetSettingsCopy();

    if (!settings.soundEnabled) {
        return;
    }

    const std::wstring& soundStr = isPinned ? settings.soundOn : settings.soundOff;
    if (soundStr.empty()) {
        return;
    }

    bool isFilePath = (soundStr.find(L'\\') != std::wstring::npos ||
                        soundStr.find(L':') != std::wstring::npos ||
                        soundStr.find(L'.') != std::wstring::npos);

    if (isFilePath) {
        if (GetFileAttributesW(soundStr.c_str()) != INVALID_FILE_ATTRIBUTES) {
            if (PlaySoundW(soundStr.c_str(), nullptr, SND_FILENAME | SND_ASYNC)) {
                return;
            }
            Wh_Log(L"⚠️ Failed to play file: %s", soundStr.c_str());
        } else {
            Wh_Log(L"⚠️ File not found: %s", soundStr.c_str());
        }
    }

    if (PlaySoundW(soundStr.c_str(), nullptr, SND_ALIAS | SND_ASYNC)) {
        return;
    }

    MessageBeep(isPinned ? MB_ICONASTERISK : MB_ICONEXCLAMATION);
}

// ===== نافذة الإشعارات العائمة =====
// ===== Floating notification window =====
LRESULT CALLBACK NotificationWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        RECT rect;
        GetClientRect(hwnd, &rect);

        HBRUSH bgBrush = CreateSolidBrush(RGB(40, 40, 40));
        HPEN borderPen = CreatePen(PS_SOLID, 2, RGB(230, 230, 230));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, bgBrush);
        HPEN oldPen = (HPEN)SelectObject(hdc, borderPen);

        RoundRect(hdc, rect.left, rect.top, rect.right, rect.bottom, 12, 12);

        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldPen);
        DeleteObject(bgBrush);
        DeleteObject(borderPen);

        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(255, 255, 255));
        PCWSTR text = (PCWSTR)GetPropW(hwnd, L"NotificationText");
        if (text) {
            DrawTextW(hdc, text, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }

        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_ERASEBKGND:
        return 1;
    case WM_TIMER:
        if (wParam == NOTIFICATION_TIMER_ID) {
            ShowWindow(hwnd, SW_HIDE);
            KillTimer(hwnd, NOTIFICATION_TIMER_ID);
        }
        return 0;
    case WM_DESTROY:
        KillTimer(hwnd, NOTIFICATION_TIMER_ID);
        RemovePropW(hwnd, L"NotificationText");
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void ShowNotification(HWND targetWindow, PCWSTR text, bool isPinned) {
    Settings settings = GetSettingsCopy();
    if (!settings.notificationsEnabled) {
        return;
    }

    HMONITOR hMon = MonitorFromWindow(targetWindow ? targetWindow : g_hwndMod, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi{ sizeof(mi) };
    if (!GetMonitorInfoW(hMon, &mi)) {
        return;
    }
    RECT rcWork = mi.rcWork;

    const int width = 200;
    const int height = 40;
    const int marginBottom = 20;
    int x = (rcWork.left + rcWork.right - width) / 2;
    int y = rcWork.bottom - height - marginBottom;

    if (!g_notificationHwnd || !IsWindow(g_notificationHwnd)) {
        g_notificationHwnd = CreateWindowExW(
            WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_NOACTIVATE | WS_EX_TOOLWINDOW,
            kNotificationWindowClassName, L"", WS_POPUP,
            x, y, width, height,
            nullptr, nullptr, nullptr, nullptr);
        if (!g_notificationHwnd) {
            Wh_Log(L"❌ Failed to create notification window");
            return;
        }
        SetLayeredWindowAttributes(g_notificationHwnd, 0, 230, LWA_ALPHA);
    } else {
        SetWindowPos(g_notificationHwnd, HWND_TOPMOST, x, y, width, height, SWP_NOACTIVATE);
    }

    SetPropW(g_notificationHwnd, L"NotificationText", (HANDLE)text);
    ShowWindow(g_notificationHwnd, SW_SHOWNOACTIVATE);
    InvalidateRect(g_notificationHwnd, nullptr, TRUE);
    UpdateWindow(g_notificationHwnd);

    SetTimer(g_notificationHwnd, NOTIFICATION_TIMER_ID, (UINT)settings.osdTimeoutMs, nullptr);
}

// ===== الإطار المميز حول النوافذ المثبتة =====
// ===== Accent border overlay around pinned windows =====

LRESULT CALLBACK BorderWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        RECT rect;
        GetClientRect(hwnd, &rect);

        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;

        if (width <= 0 || height <= 0) {
            EndPaint(hwnd, &ps);
            return 0;
        }

        HDC memDC = CreateCompatibleDC(hdc);
        HBITMAP memBmp = CreateCompatibleBitmap(hdc, width, height);
        HGDIOBJ oldBmp = SelectObject(memDC, memBmp);

        Settings settings = GetSettingsCopy();
        int thickness = settings.borderThickness > 0 ? settings.borderThickness : kDefaultBorderThickness;
        HWND target = (HWND)GetPropW(hwnd, L"TargetHwnd");

        HBRUSH bgKeyBrush = CreateSolidBrush(kBorderKeyColor);
        FillRect(memDC, &rect, bgKeyBrush);
        DeleteObject(bgKeyBrush);

        int cornerRadius = 0;
        if (target && IsWindow(target) && !IsZoomed(target)) {
            DWORD cornerPref = 0;
            if (SUCCEEDED(DwmGetWindowAttribute(target, (DWMWINDOWATTRIBUTE)33, &cornerPref, sizeof(cornerPref)))) {
                if (cornerPref != 1 /* DWMWCP_DONOTROUND */) {
                    UINT dpi = 96;
                    HMODULE u32 = GetModuleHandleW(L"user32.dll");
                    if (u32) {
                        auto pGetDpiForWindow = (UINT(WINAPI*)(HWND))GetProcAddress(u32, "GetDpiForWindow");
                        if (pGetDpiForWindow) {
                            dpi = pGetDpiForWindow(target);
                        }
                    }
                    int baseRadius = (cornerPref == 3 /* DWMWCP_ROUNDSMALL */) ? 4 : 8;
                    cornerRadius = MulDiv(baseRadius, dpi, 96);
                }
            }
        }

        if (cornerRadius > 0) {
            int outerDiameter = (cornerRadius + thickness) * 2;
            int innerDiameter = cornerRadius * 2;

            HPEN borderPen = CreatePen(PS_SOLID, 1, settings.borderColor);
            HBRUSH borderBrush = CreateSolidBrush(settings.borderColor);
            HGDIOBJ oldPen = SelectObject(memDC, borderPen);
            HGDIOBJ oldBrush = SelectObject(memDC, borderBrush);

            RoundRect(memDC, rect.left, rect.top, rect.right, rect.bottom, outerDiameter, outerDiameter);

            HPEN keyPen = CreatePen(PS_SOLID, 1, kBorderKeyColor);
            HBRUSH keyBrush = CreateSolidBrush(kBorderKeyColor);
            SelectObject(memDC, keyPen);
            SelectObject(memDC, keyBrush);

            RECT inner = rect;
            InflateRect(&inner, -thickness, -thickness);
            RoundRect(memDC, inner.left, inner.top, inner.right, inner.bottom, innerDiameter, innerDiameter);

            SelectObject(memDC, oldBrush);
            SelectObject(memDC, oldPen);
            DeleteObject(borderPen);
            DeleteObject(borderBrush);
            DeleteObject(keyPen);
            DeleteObject(keyBrush);
        } else {
            HBRUSH borderBrush = CreateSolidBrush(settings.borderColor);
            RECT inset = rect;
            for (int i = 0; i < thickness; ++i) {
                FrameRect(memDC, &inset, borderBrush);
                InflateRect(&inset, -1, -1);
            }
            DeleteObject(borderBrush);
        }

        BitBlt(hdc, 0, 0, width, height, memDC, 0, 0, SRCCOPY);

        SelectObject(memDC, oldBmp);
        DeleteObject(memBmp);
        DeleteDC(memDC);

        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_ERASEBKGND:
        return 1;
    case WM_DESTROY:
        RemovePropW(hwnd, L"TargetHwnd");
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}



HWND CreateBorderOverlayWindow() {
    HWND hwnd = CreateWindowExW(
        WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_NOACTIVATE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
        kBorderWindowClassName, L"", WS_POPUP,
        0, 0, 0, 0, nullptr, nullptr, nullptr, nullptr);
    if (hwnd) {
        SetLayeredWindowAttributes(hwnd, kBorderKeyColor, 0, LWA_COLORKEY);
    }
    return hwnd;
}

bool GetTargetFrameRect(HWND target, RECT& out) {
    if (DwmGetWindowAttribute(target, DWMWA_EXTENDED_FRAME_BOUNDS, &out, sizeof(out)) == S_OK) {
        return true;
    }
    return GetWindowRect(target, &out) != 0;
}

void UpdateBorderOverlay(const BorderOverlay& border) {
    if (!border.overlay || !IsWindow(border.overlay)) {
        return;
    }

    Settings settings = GetSettingsCopy();
    if (!settings.borderEnabled || !IsWindow(border.target) || !IsWindowVisible(border.target) ||
        IsIconic(border.target) || !IsWindowTopMost(border.target)) {
        ShowWindow(border.overlay, SW_HIDE);
        return;
    }

    RECT rc;
    if (!GetTargetFrameRect(border.target, rc)) {
        ShowWindow(border.overlay, SW_HIDE);
        return;
    }

    SetPropW(border.overlay, L"TargetHwnd", (HANDLE)border.target);

    int thickness = settings.borderThickness > 0 ? settings.borderThickness : kDefaultBorderThickness;

    HWND hAbove = GetWindow(border.target, GW_HWNDPREV);
    HWND insertAfter = HWND_TOPMOST;
    UINT swpFlags = SWP_NOACTIVATE | SWP_NOCOPYBITS | SWP_SHOWWINDOW;

    if (hAbove == border.overlay) {
        swpFlags |= SWP_NOZORDER;
        insertAfter = nullptr;
    } else if (hAbove != nullptr) {
        insertAfter = hAbove;
    }

    SetWindowPos(border.overlay, insertAfter,
                 rc.left - thickness, rc.top - thickness,
                 (rc.right - rc.left) + thickness * 2, (rc.bottom - rc.top) + thickness * 2,
                 swpFlags);

    InvalidateRect(border.overlay, nullptr, FALSE);
    UpdateWindow(border.overlay);
}


void EnsureBorderOverlay(HWND target) {
    Settings settings = GetSettingsCopy();
    if (!settings.borderEnabled || !target || !IsWindow(target)) {
        return;
    }

    EnterCriticalSection(&g_borderCs);
    for (const BorderOverlay& b : g_borderOverlays) {
        if (b.target == target) {
            LeaveCriticalSection(&g_borderCs);
            UpdateBorderOverlay(b);
            return;
        }
    }
    HWND overlay = CreateBorderOverlayWindow();
    BorderOverlay created{ target, overlay };
    if (overlay) {
        g_borderOverlays.push_back(created);
    } else {
        Wh_Log(L"❌ Failed to create border overlay window");
    }
    LeaveCriticalSection(&g_borderCs);

    if (overlay) {
        UpdateBorderOverlay(created);
    }
}

void RemoveBorderOverlay(HWND target) {
    EnterCriticalSection(&g_borderCs);
    for (auto it = g_borderOverlays.begin(); it != g_borderOverlays.end(); ++it) {
        if (it->target == target) {
            if (it->overlay && IsWindow(it->overlay)) {
                DestroyWindow(it->overlay);
            }
            g_borderOverlays.erase(it);
            break;
        }
    }
    LeaveCriticalSection(&g_borderCs);
}

void RefreshAllBorderOverlays() {
    EnterCriticalSection(&g_borderCs);
    std::vector<BorderOverlay> snapshot = g_borderOverlays;
    LeaveCriticalSection(&g_borderCs);
    for (const BorderOverlay& b : snapshot) {
        UpdateBorderOverlay(b);
    }
}

void PruneDeadBorderOverlays() {
    EnterCriticalSection(&g_borderCs);
    for (auto it = g_borderOverlays.begin(); it != g_borderOverlays.end(); ) {
        if (!IsWindow(it->target)) {
            if (it->overlay && IsWindow(it->overlay)) {
                DestroyWindow(it->overlay);
            }
            it = g_borderOverlays.erase(it);
        } else {
            ++it;
        }
    }
    LeaveCriticalSection(&g_borderCs);
}

void DestroyAllBorderOverlays() {
    EnterCriticalSection(&g_borderCs);
    for (const BorderOverlay& b : g_borderOverlays) {
        if (b.overlay && IsWindow(b.overlay)) {
            DestroyWindow(b.overlay);
        }
    }
    g_borderOverlays.clear();
    LeaveCriticalSection(&g_borderCs);
}

BOOL CALLBACK EnumWindowsSyncBordersProc(HWND hwnd, LPARAM) {
    if (!IsWindowVisible(hwnd) || GetWindow(hwnd, GW_OWNER) != nullptr) {
        return TRUE;
    }
    if (IsModOwnWindowClass(hwnd) || IsShellExcludedWindow(hwnd)) {
        return TRUE;
    }
    if (IsWindowTopMost(hwnd)) {
        EnsureBorderOverlay(hwnd);
    }
    return TRUE;
}

void SyncBordersWithSystemState() {
    Settings settings = GetSettingsCopy();
    if (!settings.borderEnabled) {
        DestroyAllBorderOverlays();
        return;
    }
    EnumWindows(EnumWindowsSyncBordersProc, 0);
}

// ===== متتبع الأحداث للنوافذ المثبتة =====
// ===== WinEvent tracking for pinned windows =====
void CALLBACK WinEventProc(HWINEVENTHOOK /*hook*/, DWORD event, HWND hwnd, LONG idObject,
                            LONG idChild, DWORD /*idEventThread*/, DWORD /*dwmsEventTime*/) {
    if (idObject != OBJID_WINDOW || idChild != CHILDID_SELF || !hwnd) {
        return;
    }

    if (event == EVENT_OBJECT_LOCATIONCHANGE) {
        EnterCriticalSection(&g_borderCs);
        BorderOverlay match{};
        bool found = false;
        for (const BorderOverlay& b : g_borderOverlays) {
            if (b.target == hwnd) {
                match = b;
                found = true;
                break;
            }
        }
        LeaveCriticalSection(&g_borderCs);
        if (found) {
            UpdateBorderOverlay(match);
        }
    } else if (event == EVENT_SYSTEM_FOREGROUND) {
        RefreshAllBorderOverlays();
    }
}

// ===== رد الفعل المركزي لتغيّر حالة التثبيت =====
// ===== Central reaction to a pin-state change =====
// Called either directly (hotkey path, already on MainThread) or via
// WM_MOD_PIN_STATE_CHANGED (system-menu path from another process).
void HandlePinStateChanged(HWND hWnd, bool pinned) {
    PlaySystemSound(pinned);
    ShowNotification(hWnd, pinned ? L"📌 Pinned" : L"📍 Unpinned", pinned);
    if (pinned) {
        EnsureBorderOverlay(hWnd);
    } else {
        RemoveBorderOverlay(hWnd);
    }
}

void ApplyHotkeySettings() {
    Settings settings = GetSettingsCopy();
    UnregisterHotKey(g_hwndMod, HOTKEY_ID);
    if (!RegisterHotKey(g_hwndMod, HOTKEY_ID, settings.hotkeyModifiers, settings.hotkeyVk)) {
        Wh_Log(L"⚠️ Failed to register hotkey (may already be in use)");
    }
}

// ===== معالج الرسائل =====
// ===== Message processor =====
LRESULT CALLBACK ModWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_HOTKEY:
        if (wParam == HOTKEY_ID) {
            HWND hWnd = GetForegroundWindow();
            std::optional<bool> pinned = ToggleTopMostCore(hWnd);
            if (pinned.has_value()) {
                HandlePinStateChanged(hWnd, *pinned);
            }
        }
        return 0;
    case WM_MOD_PIN_STATE_CHANGED:
        HandlePinStateChanged((HWND)lParam, wParam != 0);
        return 0;
    case WM_APPLY_SETTINGS:
        ApplyHotkeySettings();
        SyncBordersWithSystemState();
        RefreshAllBorderOverlays();
        return 0;
    case WM_TIMER:
        if (wParam == BORDER_SAFETY_TIMER_ID) {
            PruneDeadBorderOverlays();
            RefreshAllBorderOverlays();
        }
        return 0;
    case WM_USER_QUIT:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

// ===== الخيط الرئيسي =====
// ===== The main thread =====
DWORD WINAPI MainThread(LPVOID /*lpParam*/) {
    WNDCLASSEXW modWc{ sizeof(modWc) };
    modWc.lpfnWndProc = ModWndProc;
    modWc.lpszClassName = kModWindowClassName;
    if (!RegisterClassExW(&modWc)) {
        Wh_Log(L"❌ Failed to register mod window class");
        return 0;
    }

    WNDCLASSEXW notifWc{ sizeof(notifWc) };
    notifWc.lpfnWndProc = NotificationWndProc;
    notifWc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    notifWc.lpszClassName = kNotificationWindowClassName;
    if (!RegisterClassExW(&notifWc)) {
        Wh_Log(L"❌ Failed to register notification window class");
    }

    WNDCLASSEXW borderWc{ sizeof(borderWc) };
    borderWc.lpfnWndProc = BorderWndProc;
    borderWc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    borderWc.lpszClassName = kBorderWindowClassName;
    if (!RegisterClassExW(&borderWc)) {
        Wh_Log(L"❌ Failed to register border window class");
    }

    g_hwndMod = CreateWindowExW(0, kModWindowClassName, L"", 0, 0, 0, 0, 0,
                                 HWND_MESSAGE, nullptr, nullptr, nullptr);
    if (!g_hwndMod) {
        Wh_Log(L"❌ Failed to create message window");
        UnregisterClassW(kModWindowClassName, nullptr);
        UnregisterClassW(kNotificationWindowClassName, nullptr);
        UnregisterClassW(kBorderWindowClassName, nullptr);
        return 0;
    }

    ApplyHotkeySettings();

    g_locationHook = SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE, EVENT_OBJECT_LOCATIONCHANGE,
                                      nullptr, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);
    g_foregroundHook = SetWinEventHook(EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND,
                                        nullptr, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);
    if (!g_locationHook || !g_foregroundHook) {
        Wh_Log(L"⚠️ Failed to install one or more WinEvent hooks; the accent border may not track moved/resized windows");
    }

    SetTimer(g_hwndMod, BORDER_SAFETY_TIMER_ID, BORDER_SAFETY_INTERVAL_MS, nullptr);
    SyncBordersWithSystemState();

    Wh_Log(L"✅ Mod loaded in windhawk.exe, waiting for hotkey...");

    MSG msg;
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    KillTimer(g_hwndMod, BORDER_SAFETY_TIMER_ID);

    if (g_locationHook) {
        UnhookWinEvent(g_locationHook);
        g_locationHook = nullptr;
    }
    if (g_foregroundHook) {
        UnhookWinEvent(g_foregroundHook);
        g_foregroundHook = nullptr;
    }

    DestroyAllBorderOverlays();

    if (g_notificationHwnd && IsWindow(g_notificationHwnd)) {
        DestroyWindow(g_notificationHwnd);
        g_notificationHwnd = nullptr;
    }

    UnregisterHotKey(g_hwndMod, HOTKEY_ID);
    DestroyWindow(g_hwndMod);
    g_hwndMod = nullptr;

    UnregisterClassW(kModWindowClassName, nullptr);
    UnregisterClassW(kNotificationWindowClassName, nullptr);
    UnregisterClassW(kBorderWindowClassName, nullptr);

    Wh_Log(L"🛑 Main thread exiting");
    return 0;
}

// ============================================================
// ===== دوال المود كأداة (Tool Mod) =====
// ===== Mod functions as a tool (Tool Mod) =====
// ============================================================

BOOL WhTool_ModInit() {
    Wh_Log(L"🔧 Initializing mod as a tool in windhawk.exe...");
    InitializeCriticalSection(&g_cs);
    InitializeCriticalSection(&g_borderCs);
    LoadSettings();

    g_hThread = CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);
    if (!g_hThread) {
        Wh_Log(L"❌ Failed to create main thread");
        DeleteCriticalSection(&g_borderCs);
        DeleteCriticalSection(&g_cs);
        return FALSE;
    }

    return TRUE;
}

void WhTool_ModSettingsChanged() {
    Wh_Log(L"⚙️ Settings changed, reloading...");
    LoadSettings();
    if (g_hwndMod) {
        PostMessageW(g_hwndMod, WM_APPLY_SETTINGS, 0, 0);
    }
}

void WhTool_ModUninit() {
    Wh_Log(L"🛑 Unloading tool mod...");

    if (g_hwndMod) {
        PostMessageW(g_hwndMod, WM_USER_QUIT, 0, 0);
    }

    if (g_hThread) {
        WaitForSingleObject(g_hThread, INFINITE);
        CloseHandle(g_hThread);
        g_hThread = nullptr;
    }

    DeleteCriticalSection(&g_borderCs);
    DeleteCriticalSection(&g_cs);
    Wh_Log(L"✅ Tool mod unloaded");
}

// ============================================================
// ===== التكامل مع قائمة النظام (داخل كل تطبيق) =====
// ===== System menu integration (inside every regular application) =====
// ============================================================

std::atomic<bool> g_systemMenuIntegrationEnabled{ true };

void UpdateSystemMenuIntegrationSetting() {
    g_systemMenuIntegrationEnabled.store(Wh_GetIntSetting(L"systemMenuIntegration") != 0);
}

void AppendPinMenuItem(HWND hWnd, HMENU hMenu) {
    if (!hMenu || IsShellExcludedWindow(hWnd) || IsModOwnWindowClass(hWnd)) {
        return;
    }

    MENUITEMINFOW mii{ sizeof(mii) };
    mii.fMask = MIIM_ID;
    if (!GetMenuItemInfoW(hMenu, IDM_PIN_TOGGLE, FALSE, &mii)) {
        AppendMenuW(hMenu, MF_SEPARATOR, 0, nullptr);
        AppendMenuW(hMenu, MF_STRING, IDM_PIN_TOGGLE, L"📌 Always on Top");
    }
    CheckMenuItem(hMenu, IDM_PIN_TOGGLE, MF_BYCOMMAND | (IsWindowTopMost(hWnd) ? MF_CHECKED : MF_UNCHECKED));
}

using DefWindowProcW_t = LRESULT(WINAPI*)(HWND, UINT, WPARAM, LPARAM);
DefWindowProcW_t pOriginalDefWindowProcW = nullptr;

using DefWindowProcA_t = LRESULT(WINAPI*)(HWND, UINT, WPARAM, LPARAM);
DefWindowProcA_t pOriginalDefWindowProcA = nullptr;

using GetSystemMenu_t = HMENU(WINAPI*)(HWND, BOOL);
GetSystemMenu_t pOriginalGetSystemMenu = nullptr;

HMENU WINAPI GetSystemMenu_Hook(HWND hWnd, BOOL bRevert) {
    HMENU hMenu = pOriginalGetSystemMenu(hWnd, bRevert);
    if (hMenu && !bRevert && g_systemMenuIntegrationEnabled.load()) {
        AppendPinMenuItem(hWnd, hMenu);
    }
    return hMenu;
}

LRESULT WINAPI DefWindowProcW_Hook(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
    if (g_systemMenuIntegrationEnabled.load()) {
        if (Msg == WM_INITMENUPOPUP) {
            if (HIWORD(lParam)) {
                AppendPinMenuItem(hWnd, (HMENU)wParam);
            }
        } else if (Msg == WM_SYSCOMMAND && (wParam & 0xFFF0) == IDM_PIN_TOGGLE) {
            std::optional<bool> pinned = ToggleTopMostCore(hWnd);
            if (pinned.has_value()) {
                NotifyToolProcess(hWnd, *pinned);
            }
            return 0;
        }
    }
    return pOriginalDefWindowProcW(hWnd, Msg, wParam, lParam);
}

LRESULT WINAPI DefWindowProcA_Hook(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
    if (g_systemMenuIntegrationEnabled.load()) {
        if (Msg == WM_INITMENUPOPUP) {
            if (HIWORD(lParam)) {
                AppendPinMenuItem(hWnd, (HMENU)wParam);
            }
        } else if (Msg == WM_SYSCOMMAND && (wParam & 0xFFF0) == IDM_PIN_TOGGLE) {
            std::optional<bool> pinned = ToggleTopMostCore(hWnd);
            if (pinned.has_value()) {
                NotifyToolProcess(hWnd, *pinned);
            }
            return 0;
        }
    }
    return pOriginalDefWindowProcA(hWnd, Msg, wParam, lParam);
}

BOOL InitSystemMenuIntegration() {
    UpdateSystemMenuIntegrationSetting();

    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    if (!user32) {
        return FALSE;
    }

    void* pDefW = (void*)GetProcAddress(user32, "DefWindowProcW");
    if (pDefW) {
        Wh_SetFunctionHook(pDefW, (void*)DefWindowProcW_Hook, (void**)&pOriginalDefWindowProcW);
    }

    void* pDefA = (void*)GetProcAddress(user32, "DefWindowProcA");
    if (pDefA) {
        Wh_SetFunctionHook(pDefA, (void*)DefWindowProcA_Hook, (void**)&pOriginalDefWindowProcA);
    }

    void* pGetSysMenu = (void*)GetProcAddress(user32, "GetSystemMenu");
    if (pGetSysMenu) {
        Wh_SetFunctionHook(pGetSysMenu, (void*)GetSystemMenu_Hook, (void**)&pOriginalGetSystemMenu);
    }

    return TRUE;
}

void UninitSystemMenuIntegration() {
    // Windhawk cleans up Wh_SetFunctionHook hooks automatically on unload
}


// ============================================================
// ===== كود "Launcher" =====
// ===== "Launcher" code =====
// ============================================================
bool g_isToolModProcessLauncher = false;
bool g_isRegularAppProcess = false;
HANDLE g_toolModProcessMutex = nullptr;

void WINAPI EntryPoint_Hook() {
    Wh_Log(L">");
    ExitThread(0);
}

BOOL Wh_ModInit() {
    DWORD sessionId;
    if (ProcessIdToSessionId(GetCurrentProcessId(), &sessionId) && sessionId == 0) {
        return FALSE;
    }

    WCHAR processPath[MAX_PATH];
    DWORD pathLen = GetModuleFileNameW(nullptr, processPath, ARRAYSIZE(processPath));
    bool isWindhawkExe = false;
    if (pathLen > 0 && pathLen < ARRAYSIZE(processPath)) {
        PCWSTR fileName = wcsrchr(processPath, L'\\');
        fileName = fileName ? fileName + 1 : processPath;
        isWindhawkExe = (_wcsicmp(fileName, L"windhawk.exe") == 0);
    }

    if (!isWindhawkExe) {
        g_isRegularAppProcess = true;
        return InitSystemMenuIntegration();
    }

    bool isExcluded = false;
    bool isToolModProcess = false;
    bool isCurrentToolModProcess = false;

    int argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    if (!argv) {
        Wh_Log(L"CommandLineToArgvW failed");
        return FALSE;
    }

    for (int i = 1; i < argc; i++) {
        if (wcscmp(argv[i], L"-service") == 0 ||
            wcscmp(argv[i], L"-service-start") == 0 ||
            wcscmp(argv[i], L"-service-stop") == 0) {
            isExcluded = true;
            break;
        }
    }

    for (int i = 1; i < argc - 1; i++) {
        if (wcscmp(argv[i], L"-tool-mod") == 0) {
            isToolModProcess = true;
            if (wcscmp(argv[i + 1], WH_MOD_ID) == 0) {
                isCurrentToolModProcess = true;
            }
            break;
        }
    }

    LocalFree(argv);

    if (isExcluded) {
        return FALSE;
    }

    if (isCurrentToolModProcess) {
        g_toolModProcessMutex = CreateMutexW(nullptr, TRUE, L"windhawk-tool-mod_" WH_MOD_ID);
        if (!g_toolModProcessMutex) {
            Wh_Log(L"CreateMutex failed");
            ExitProcess(1);
        }
        if (GetLastError() == ERROR_ALREADY_EXISTS) {
            Wh_Log(L"Tool mod already running (%s)", WH_MOD_ID);
            ExitProcess(1);
        }

        if (!WhTool_ModInit()) {
            ExitProcess(1);
        }

        IMAGE_DOS_HEADER* dosHeader = (IMAGE_DOS_HEADER*)GetModuleHandleW(nullptr);
        IMAGE_NT_HEADERS* ntHeaders = (IMAGE_NT_HEADERS*)((BYTE*)dosHeader + dosHeader->e_lfanew);
        DWORD entryPointRVA = ntHeaders->OptionalHeader.AddressOfEntryPoint;
        void* entryPoint = (BYTE*)dosHeader + entryPointRVA;

        Wh_SetFunctionHook(entryPoint, (void*)EntryPoint_Hook, nullptr);
        return TRUE;
    }

    if (isToolModProcess) {
        return FALSE;
    }

    g_isToolModProcessLauncher = true;
    return TRUE;
}

void Wh_ModAfterInit() {
    if (!g_isToolModProcessLauncher) {
        return;
    }

    WCHAR currentProcessPath[MAX_PATH];
    switch (GetModuleFileNameW(nullptr, currentProcessPath, ARRAYSIZE(currentProcessPath))) {
        case 0:
        case ARRAYSIZE(currentProcessPath):
            Wh_Log(L"GetModuleFileName failed");
            return;
    }

    WCHAR commandLine[MAX_PATH + 2 + (sizeof(L" -tool-mod \"" WH_MOD_ID "\"") / sizeof(WCHAR)) - 1];
    swprintf_s(commandLine, L"\"%s\" -tool-mod \"%s\"", currentProcessPath, WH_MOD_ID);

    HMODULE kernelModule = GetModuleHandleW(L"kernelbase.dll");
    if (!kernelModule) {
        kernelModule = GetModuleHandleW(L"kernel32.dll");
        if (!kernelModule) {
            Wh_Log(L"No kernelbase.dll/kernel32.dll");
            return;
        }
    }

    using CreateProcessInternalW_t = BOOL(WINAPI*)(
        HANDLE hUserToken,
        LPCWSTR lpApplicationName,
        LPWSTR lpCommandLine,
        LPSECURITY_ATTRIBUTES lpProcessAttributes,
        LPSECURITY_ATTRIBUTES lpThreadAttributes,
        WINBOOL bInheritHandles,
        DWORD dwCreationFlags,
        LPVOID lpEnvironment,
        LPCWSTR lpCurrentDirectory,
        LPSTARTUPINFOW lpStartupInfo,
        LPPROCESS_INFORMATION lpProcessInformation,
        PHANDLE hRestrictedUserToken
    );

    CreateProcessInternalW_t pCreateProcessInternalW =
        (CreateProcessInternalW_t)GetProcAddress(kernelModule, "CreateProcessInternalW");
    if (!pCreateProcessInternalW) {
        Wh_Log(L"No CreateProcessInternalW");
        return;
    }

    STARTUPINFOW si{
        .cb = sizeof(STARTUPINFOW),
        .dwFlags = STARTF_FORCEOFFFEEDBACK,
    };
    PROCESS_INFORMATION pi;

    if (!pCreateProcessInternalW(nullptr, currentProcessPath, commandLine, nullptr, nullptr,
                                  FALSE, NORMAL_PRIORITY_CLASS, nullptr, nullptr, &si, &pi, nullptr)) {
        Wh_Log(L"CreateProcess failed");
        return;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void Wh_ModSettingsChanged() {
    if (g_isRegularAppProcess) {
        UpdateSystemMenuIntegrationSetting();
        return;
    }
    if (g_isToolModProcessLauncher) return;
    WhTool_ModSettingsChanged();
}

void Wh_ModUninit() {
    if (g_isRegularAppProcess) {
        UninitSystemMenuIntegration();
        return;
    }
    if (g_isToolModProcessLauncher) return;
    WhTool_ModUninit();
    ExitProcess(0);
}

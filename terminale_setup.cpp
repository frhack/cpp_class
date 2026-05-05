// terminale_setup.cpp
//
// Funzioni tecniche per controllare Windows Terminal.
// Da non studiare: bastano i nomi e cosa fanno.
//
// USO: copia-incolla queste 4 funzioni nel tuo sorgente
// (insieme agli include che vedi qui sotto).
//
// Servono questi include in cima al file:
//
//     #include <iostream>
//     #include <windows.h>

// Trova la finestra di Windows Terminal e la porta in primo piano.
HWND focusTerminal() {
    HWND hwnd = FindWindowW(L"CASCADIA_HOSTING_WINDOW_CLASS", nullptr);
    if (!hwnd) {
        std::cerr << "Windows Terminal non trovato\n";
        return nullptr;
    }
    if (IsIconic(hwnd)) ShowWindow(hwnd, SW_RESTORE);
    SetForegroundWindow(hwnd);
    Sleep(150);
    return hwnd;
}

// Simula la pressione di un tasto (eventualmente insieme a CTRL).
bool sendKey(WORD vk, bool ctrl = false) {
    INPUT input[4] = {};
    int n = 0;
    auto addKey = [&](WORD key, DWORD flags = 0) {
        input[n].type = INPUT_KEYBOARD;
        input[n].ki.wVk = key;
        input[n].ki.dwFlags = flags;
        n++;
    };
    if (ctrl) addKey(VK_CONTROL);
    addKey(vk);
    addKey(vk, KEYEVENTF_KEYUP);
    if (ctrl) addKey(VK_CONTROL, KEYEVENTF_KEYUP);
    return SendInput(n, input, sizeof(INPUT)) == n;
}

// Preme CTRL + - per "times" volte (rimpicciolisce il carattere).
bool zoomOutTerminal(int times) {
    if (!focusTerminal()) return false;
    for (int i = 0; i < times; i++) {
        if (!sendKey(VK_OEM_MINUS, true)) return false;
        Sleep(50);
    }
    return true;
}

// Preme F11 (mette il terminale a tutto schermo).
bool fullscreenTerminal() {
    if (!focusTerminal()) return false;
    return sendKey(VK_F11);
}

#include <stdio.h>
#include <windows.h>


int main()
{
//keybd_event(VK_F11,0x38,0,0); //Appuie sur ALT
//keybd_event(VK_RETURN,0x1c,0,0); //Appuie ENTREE
//keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); // Relache ENTREE
//keybd_event(VK_F11,0x38,KEYEVENTF_KEYUP,0); //Relache ALT
keybd_event(VK_F11,0,0,0); //Appuie sur ALT

//Suite du code...
}

/*int main() {
    //system("mode con LINES=50 COLS=80");
    return 0;
} */
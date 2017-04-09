#include <jni.h>
#include <MsHook.h>

#define hook(a,b,c) MSHookFunction((void*)&a,(void*)&b,(void**)&c)

struct Item;
struct Player
{
	void ConsumeAmmo(Item const *,int,Item &);
};

static void (*_ConsumeAmmo)(Player *,Item const *,int,Item &);
static void ConsumeAmmo(Player *p,Item const *i,int a,Item & b)
{
	
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	hook(Player::ConsumeAmmo,ConsumeAmmo,_ConsumeAmmo);
	
	return JNI_VERSION_1_6;
}

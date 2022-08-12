#include "CTRPluginFramework.hpp"
#include "cheats.hpp"
#include "csvc.h"

namespace CTRPluginFramework
{
	static MenuEntry *AddArg(void *arg, MenuEntry *entry)
	{
		if (entry != nullptr)
			entry->SetArg(arg);
		return (entry);
	}
	
	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const Hotkey& hotkey)
	{
		if (entry != nullptr)
		{
			entry->Hotkeys += hotkey;
			entry->SetArg(new std::string(entry->Name()));
			entry->Name() += " " + hotkey.ToString();
			entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
				{
					std::string *name = reinterpret_cast<std::string*>(entry->GetArg());

					entry->Name() = *name + " " + entry->Hotkeys[0].ToString();
				});
		}
		return (entry);
	}
	
	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const std::vector<Hotkey>& hotkeys)
	{
		if (entry != nullptr)
		{
			for (const Hotkey& hotkey : hotkeys)
				entry->Hotkeys += hotkey;
		}
		return (entry);
	}
	
	static MenuEntry *EnabledEntry(MenuEntry *entry)
	{
		if (entry != nullptr) entry->Enable();
		return (entry);
	}
	
	PluginMenu *menu;
	
	void InitMenu()  //ここから上は弄らない！
	{	
		new MenuEntry("日本語の名前", NAME);
		
		MenuFolder *folder1 = new MenuFolder(Color::LimeGreen << "日本語の名前","説明");
		{
			MenuFolder *folder2 = new MenuFolder("日本語の名前");
			{
				*folder2 += new MenuEntry("日本語の名前", NAME);
		    }
			*folder1 += folder2;
			
			*folder1 += new MenuEntry("日本語の名前", NAME);
		}
		*menu += folder1;
	}

	int main(void)
	{
		menu = new PluginMenu(Color::Yellow << "左上に表示される文字(基本的には3gx名)", 1, 0, 0, "aboutに書くこと");
		menu->SynchronizeWithFrame(true);
		menu->ShowWelcomeMessage(false);
        OSD::Notify(Color::Yellow << "plgin ready!! の代わりの文字");
		InitMenu();
		menu->Run();
		delete menu;
		return 0;
	}
	
	
}





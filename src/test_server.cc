#include "MyConf.h"
#include "SpellcorrectServer.h"
#include "CacheManager.h"
#include <iostream>

int main(void)
{

	MyConf::getInstance()->init("./conf/my.conf");
	MyConf::getInstance()->show();

	CacheManager::initCache(wd::str2int(MyConf::getInstance()->getMap()["my_thread_num"]),
							MyConf::getInstance()->getMap()["my_cache"]);
	CacheManager::getCache(0).debug();

	wd::SpellcorrectServer server;
	server.start();

	return 0;
}

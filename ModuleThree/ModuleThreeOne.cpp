#include "ModuleThreeOne.h"
#include <iostream>
ModuleThreeOne::ModuleThreeOne() {
	totalPassengers = 0;
	totalMoney      = 0;
	inPassengers    = 0;
	outPassengers   = 0;
	salaryDriver    = 0;
	fuel            = 0;
	taxes           = 0;
	repair          = 0;
	profit          = 0;
	stop            = "";
}

void ModuleThreeOne::run() {

	stop = "Óëèöà ïðîãðàììèñòîâ";

	std::cout << "Ïðèáûâàåì íà îñòàíîâêó \"" << stop << "\". Â ñàëîíå ïàññàæèðîâ: " << totalPassengers << "\n";
	std::cout << "Ââåäèòå êîëè÷åñòâî âîøåäùèõ ïàññàæèðîâ: ";
	std::cin  >> inPassengers;

	std::cout << "Ââåäèòå êîëè÷åñòâî âûøåäøèõ ïàññàæèðîâ: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "Ñêîëüêî ïàññàæèðîâ âûøëî? " << outPassengers << "\n";
	std::cout << "Ñêîëüêî ïàññàæèðîâ çàøëî íà îñòàíîâêå? " << inPassengers << "\n";
	std::cout << "Îòïðàâëÿåìñÿ ñ îñòàíîâêè \"" << stop << "\". Â ñàëîíå ïàññàæèðîâ: " << totalPassengers << "\n";
	std::cout << "-----------Åäåì---------\n\n";

	stop = "Ïðîñïåêò àëãîðèòìîâ";

	std::cout << "Ïðèáûâàåì íà îñòàíîâêó \"" << stop << "\". Â ñàëîíå ïàññàæèðîâ: " << totalPassengers << "\n";
	std::cout << "Ââåäèòå êîëè÷åñòâî âîøåäùèõ ïàññàæèðîâ: ";
	std::cin  >> inPassengers;

	std::cout << "Ââåäèòå êîëè÷åñòâî âûøåäøèõ ïàññàæèðîâ: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "Ñêîëüêî ïàññàæèðîâ âûøëî? " << outPassengers << "\n";
	std::cout << "Ñêîëüêî ïàññàæèðîâ çàøëî íà îñòàíîâêå? " << inPassengers << "\n";
	std::cout << "Îòïðàâëÿåìñÿ ñ îñòàíîâêè \"" << stop << "\". Â ñàëîíå ïàññàæèðîâ: " << totalPassengers << "\n";
	std::cout << "-----------Åäåì---------\n\n";

	stop = "Óíèâåðñèòåò ÓëÃÓ";

	std::cout << "Ïðèáûâàåì íà îñòàíîâêó \"" << stop << "\". Â ñàëîíå ïàññàæèðîâ: " << totalPassengers << "\n";
	std::cout << "Ââåäèòå êîëè÷åñòâî âîøåäùèõ ïàññàæèðîâ: ";
	std::cin  >> inPassengers;

	std::cout << "Ââåäèòå êîëè÷åñòâî âûøåäøèõ ïàññàæèðîâ: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "Ñêîëüêî ïàññàæèðîâ âûøëî? " << outPassengers << "\n";
	std::cout << "Ñêîëüêî ïàññàæèðîâ çàøëî íà îñòàíîâêå? " << inPassengers << "\n";
	std::cout << "Îòïðàâëÿåìñÿ ñ îñòàíîâêè \"" << stop << "\". Â ñàëîíå ïàññàæèðîâ: " << totalPassengers << "\n";
	std::cout << "-----------Åäåì---------\n\n";

	stop = "Ïðîñïåêò Ãàÿ";

	std::cout << "Ïðèáûâàåì íà êîíå÷íóþ îñòàíîâêó \"" << stop << "\". Â ñàëîíå ïàññàæèðîâ: " << totalPassengers << "\n";

	//Çäåñü ÿ îïèðàëñÿ íà ãàðàíòèðîâàííûé âûõîä âñåõ ïàññàæèðîâ íà êîíå÷íîé îñòàíîâêå
	inPassengers     = 0;
	outPassengers    = totalPassengers;
	totalPassengers -= totalPassengers;

	std::cout << "Ñêîëüêî ïàññàæèðîâ âûøëî? " << outPassengers << "\n";
	std::cout << "Ñêîëüêî ïàññàæèðîâ çàøëî íà îñòàíîâêå? " << inPassengers << "\n";
	std::cout << "Â ñàëîíå ïàññàæèðîâ : " << totalPassengers << "\n";
	std::cout << "-----------Êîíå÷íàÿ---------\n\n";

	salaryDriver = totalMoney / 4;
	fuel         = totalMoney / 5;
	taxes        = totalMoney / 5;
	repair       = totalMoney / 5;
	profit       = totalMoney - (salaryDriver + fuel + taxes + repair);

	std::cout << "Âñåãî çàðàáîòàëè: "         << totalMoney << "\n";
	std::cout << "Çàðïëàòà âîäèòåëÿ: "        << salaryDriver << "\n";
	std::cout << "Ðàñõîäû íà òîïëèâî: "       << fuel << "\n";
	std::cout << "Íàëîãè: "                   << taxes << "\n";
	std::cout << "Ðàñõîäû íà ðåìîíò ìàøèíû: " << repair << "\n";
	std::cout << "Èòîãî äîõîä: "              << profit << "\n";
}

ModuleThreeOne::~ModuleThreeOne() {

}

//
// Created by eliza on 4/12/24.
//

#include "game.h"
#include <chrono>
#include <thread>

   

void play()
{
    int n;
    PlaySound(TEXT("first.wav"), nullptr, SND_ASYNC);
    std::cout << "Enter the number of phases: ";
    std::cin >> n;
     PlaySound(TEXT("second.wav"), nullptr, SND_ASYNC);
    std::cout << "Enter the phases: \n";
    Name_Index names(n);

   

    Graph g(n);     

    PlaySound(TEXT("would.wav"), nullptr, SND_SYNC);

    std::string t;
    std::cout << "y/n : ";
    std::cin >> t;

    if(t == "y")
        PlaySound(TEXT("sorry.wav"), nullptr, SND_SYNC);
    if(t == "n") {
        PlaySound(TEXT("tobe.wav"), nullptr,  SND_SYNC);
        return;
    }
    

    Kosaraju k(g);

    k.print_leaders(names);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    k.print_rest();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    LinearProcessChecker l(k);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    l.Kahn();
}
